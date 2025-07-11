/**************************************************************************
**  SP_INS_NODE                                                          **
**                                                                       **
**    Adds a node to an existing defined dimension of a sparse matrix.   **
**                                                                       **
**  INPUT:                                                               **
**    sp -- The sparse matrix into which the node is to be inserted.     **
**    tuple -- The tuple used to define the location of the node.        **
**    node_val -- The value to be assigned to the node.                  **
**              this header element.                                     **
**  OUTPUT:                                                              **
**    SPARSE_MATRIX * -- A pointer to the modified sparse matrix         **
**                                                                       **
**  SIDE EFFECTS:                                                        **
**    The error_no field of the sparse matrix can be set to an error if  **
**  an error is encountered.  Whenever an error is encountered, this     **
**  value is set and a NULL pointer is returned.  Thus, if a NULL        **
**  pointer is returned from this function it is important to examine    **
**  the error_no of the associated sparse matrix.                        **
**    Header list elements are inserted as needed if they don't exist    **
**  so attempting to insert a node could result in header list element   **
**  insertions as well.                                                  **
**                                                                       **
**  NOTES:                                                               **
**                                                                       **
**************************************************************************/

#include "sparse.h"
#include <stdio.h>
#include <stdlib.h>

SPARSE_MATRIX *sp_ins_node(SPARSE_MATRIX *sp, SP_TUPLE *tuple, int node_val)
/* SPARSE_MATRIX *sp  The sparse matrix into which the node is to be
                        inserted */
/* SP_TUPLE *tuple    The tuple used to define the location of the node */
/* int node_val       The value to be inserted in the node */
{
    SPARSE_MATRIX *sp_res;
    SP_HDR_ELEMENT *header_pos, **new_hdr_stack;
    SP_NODE *new_node, *node_pos, *node_head, **node_stack, *prev_node, *next_node;
    int curr_dim, sub_dim, *curr_seq, node_seq, pos_found, next_sub_dim, back_to_top;

    /* If the sparse matrix is empty, then a node cannot be inserted */
    if (sp == (SPARSE_MATRIX *)NULL) {
        return ((SPARSE_MATRIX *)NULL);
    }

    sp->error_no = SP_NOERR;

    /* If the tuple is empty, then no node can be inserted */
    if (tuple == (SP_TUPLE *)NULL) {
        sp->error_no = SP_BADDIM;
        return (sp);
    }

    /* Make sure that the number of dimensions in the tuple matches the
       number of dimensions in the sparse matrix */
    if (sp->dimensions != tuple->dimensions) {
        sp->error_no = SP_BADDIM;
        return (sp);
    }

    /* Attempt to retrieve the node in case it already exists */
    new_node = sp_retrieve_node(sp, tuple);
    if (sp->error_no != SP_NOERR) {
        return (sp);
    }

    /* If the node exists, just update the value */
    if (new_node != (SP_NODE *)NULL) {
        new_node->value = node_val;
        return (sp);
    }

    /* Since the node doesn't exist, check to make sure all the headers exist
       and if they don't, then insert them.  In the process, build up the header
       list stack needed by the node */
    new_hdr_stack = (SP_HDR_ELEMENT **)malloc(sizeof(SP_HDR_ELEMENT *) * (sp->dimensions - 1));
    for (curr_dim = 0; curr_dim < sp->dimensions; curr_dim++) {
        /* Set the current sequence number to the sequence number in the tuple
           stack associated with the current dimension */
        curr_seq = (int *)(tuple->seq + (curr_dim));

        /* Insert the header element, if appropriate */
        sp_res = sp_ins_header_element(sp, curr_dim + 1, *curr_seq, (SP_HEADER_DATA *)NULL);
        if (sp->error_no != SP_NOERR) {
            free(new_hdr_stack);
            return (sp);
        }

        /* Retrieve a pointer to the header list element */
        header_pos = sp_hdr_list_element_get(sp, curr_dim + 1, *curr_seq);
        if ((header_pos == (SP_HDR_ELEMENT *)NULL) || (sp->error_no != SP_NOERR)) {
            free(new_hdr_stack);
            return (sp);
        }
        *(new_hdr_stack + (curr_dim)) = header_pos;
    }

    /* Create the node */
    new_node = (SP_NODE *)malloc(sizeof(SP_NODE));
    if (new_node == (SP_NODE *)NULL) {
        free(new_hdr_stack);
        sp->error_no = SP_MEMLOW;
        return (sp);
    }

    new_node->hdr_stack = new_hdr_stack;
    new_node->value = node_val;

    /* Create a dimension stack for the node */
    node_stack = (SP_NODE **)malloc(sizeof(SP_NODE *) * sp->dimensions * 2);
    if (node_stack == (SP_NODE **)NULL) {
        free(new_hdr_stack);
        free(new_node);
        return (sp);
    }

    new_node->dimension_stack = node_stack;

    /* initialize the node stack to be self referencing */
    for (curr_dim = 0; curr_dim < sp->dimensions; curr_dim++) {
        /* Handle the next pointer */
        *((SP_NODE **)(new_node->dimension_stack + (2 * curr_dim))) = new_node;

        /* Handle the previous pointer */
        *((SP_NODE **)(new_node->dimension_stack + (2 * curr_dim) + 1)) = new_node;
    }

    /* insert the node into the node lists associated with each header
       list element */
    for (curr_dim = 0; curr_dim < sp->dimensions; curr_dim++) {
        /* Get the header list element associated with this dimension */
        header_pos = *(SP_HDR_ELEMENT **)(new_node->hdr_stack + curr_dim);

        /* Get the list of nodes associated with this header list element */
        node_head = header_pos->first;

        /* The list of nodes is ordered by the dimension sequence numbers,
           left to right, so traverse the list starting with the first dimension
           of the tuple until the correct position in the list is found */
        node_pos = node_head;
        back_to_top = 0;
        pos_found = 0;

        /* If there were no other nodes in this list, then the position is
           automatically the first position */
        if (node_pos == (SP_NODE *)NULL) {
            pos_found = 1;
            header_pos->first = new_node;
            header_pos->last = new_node;
        }

        for (sub_dim = 0; (sub_dim < sp->dimensions) && (!pos_found) && (!back_to_top); sub_dim++) {
            /* skip the current dimension, because all nodes in the list match
               the current dimension by default */
            if (sub_dim != curr_dim) {
                /* Get the sequence number for the tuple in this dimension */
                curr_seq = (int *)(tuple->seq + (sub_dim));

                /* search for an entry which is equal to or greater than the
                   sequence number of the node */
                next_sub_dim = 0;
                do {
                    /* Get the sequence number for this node in this sub-dimension */
                    node_seq = ((SP_HDR_ELEMENT *)*((node_pos->hdr_stack) + (sub_dim)))->sequence;

                    /* If this sub dimension sequence number is larger than the tuple
                       sequence number, then the node should be inserted before the
                       current node */
                    if (node_seq > *curr_seq) {
                        pos_found = 1;
                    } else {
                        /* If the sub dimension sequence number is equal to the tuple
                           sequence number, then the next dimension needs to be checked */
                        if (node_seq == *curr_seq) {
                            next_sub_dim = 1;
                        }

                        else {
                            /* If the sub dimension sequence number is smaller than the tuple
                               sequence number, check the next node */
                            node_pos = sp_next_node(sp, curr_dim + 1, node_pos);
                            if (sp->error_no != SP_NOERR) {
                                free(new_hdr_stack);
                                free(new_node);
                                free(node_stack);
                                return (sp);
                            }
                            back_to_top = (node_pos == node_head);
                        }
                    }
                } while ((!back_to_top) && (!pos_found) && (!next_sub_dim));
            }
        }

        /* If a node has been found which is larger than the current node, set up
           the pointers */
        if (node_pos != (SP_NODE *)NULL) {
            /* At this point, node_pos points to the node which belongs after the
               current node.  Since this node belongs after the current node in the
               doubly linked list, set up the next pointer in the dimension stack */
            next_node = node_pos;
            *((SP_NODE **)(new_node->dimension_stack + (2 * curr_dim))) = next_node;

            /* The previous pointer is the previous pointer held by the old node */
            prev_node = sp_previous_node(sp, curr_dim + 1, node_pos);
            if ((sp->error_no != SP_NOERR) || (prev_node == (SP_NODE *)NULL)) {
                free(new_hdr_stack);
                free(new_node);
                free(node_stack);
                return (sp);
            }
            *((SP_NODE **)(new_node->dimension_stack + (2 * curr_dim) + 1)) = prev_node;

            /* Now insert the node into the existing link structure */
            *((SP_NODE **)(prev_node->dimension_stack + (2 * curr_dim))) = new_node;

            *((SP_NODE **)(next_node->dimension_stack + (2 * curr_dim) + 1)) = new_node;
        }

        /* Update the first and last pointers as appropriate */
        if (node_pos == node_head) {
            /* If the whole list has been checked, then node_pos should be the
               last node in the header link */
            if (back_to_top) {
                header_pos->last = new_node;
                header_pos->first = next_node;
            } else {
                /* If the new node is smaller than the header node, then the first node of
                   the header link should point to node_pos */
                header_pos->first = new_node;
                header_pos->last = prev_node;
            }
        }
    }

    return (sp);
}
