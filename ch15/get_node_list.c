/**************************************************************************
**  SP_GET_NODE_LIST                                                     **
**                                                                       **
**    Retrieves a pointer to the node list associated with the passed    **
**  dimension and header element sequence number.                        **
**                                                                       **
**  INPUT:                                                               **
**    sp -- The sparse matrix which contains the header list stack       **
**    dim -- The dimension of the header list being requested            **
**    seq -- The sequence number of the header element                   **
**                                                                       **
**  OUTPUT:                                                              **
**    SP_NODE -- A pointer to the node list                              **
**                                                                       **
**  SIDE EFFECTS:                                                        **
**    The error_no field of the sparse matrix can be set to an error if  **
**  an error is encountered.  Whenever an error is encountered, this     **
**  value is set and a NULL pointer is returned.  Thus, if a NULL        **
**  pointer is returned from this function it is important to examine    **
**  the error_no of the associated sparse matrix before assuming that    **
**  the node list is empty.                                              **
**                                                                       **
**  NOTES:                                                               **
**    It is possible for the node list associated with a dimension and   **
**  header element to be empty if no values are in the matrix.           **
**  Therefore, the error_no value should be checked in the associated    **
**  sparse matrix whenever a NULL pointer is returned.                   **
**                                                                       **
**************************************************************************/

#include "sparse.h"
#include <stdio.h>

SP_NODE *sp_get_node_list(SPARSE_MATRIX *sp, int dim, int seq)
/* SPARSE_MATRIX *sp The sparse matrix in which to find the header list */
/* int dim           The dimension number of the header list */
/*     seq           The sequence number of the header list element */
{
    SP_HDR_ELEMENT *header_element;

    /* If the sparse matrix passed is empty, then there are no nodes to
       be found */
    if (sp == (SPARSE_MATRIX *)NULL)
        return ((SP_NODE *)NULL);

    sp->error_no = SP_NOERR;

    /* Retrieve the header list element associated with the dimension and
       sequence*/
    header_element = sp_hdr_list_element_get(sp, dim, seq);
    if ((sp->error_no != SP_NOERR) || (header_element == (SP_HDR_ELEMENT *)NULL)) {
        return ((SP_NODE *)NULL);
    }

    return (header_element->first);
}
