/**************************************************************************
**  HDR_LIST_ELEMENT_GET                                                 **
**                                                                       **
**    Retrieves a header list element.                                   **
**                                                                       **
**  INPUT:                                                               **
**    sp -- The sparse matrix which contains the header list stack       **
**    dim -- The dimension of the header list being requested            **
**    seq -- The sequence number of the header element                   **
**                                                                       **
**  OUTPUT:                                                              **
**    SP_HDR_ELEMENT * -- A pointer to the header element                **
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
**    It is possible for the header element associated with a dimension  **
**  sequence to be empty if no header element is in the matrix.          **
**  Therefore, the error_no value should be checked in the associated    **
**  sparse matrix whenever a NULL pointer is returned.                   **
**                                                                       **
**************************************************************************/

#include "sparse.h"
#include <stdio.h>

SP_HDR_ELEMENT *sp_hdr_list_element_get(SPARSE_MATRIX *sp, int dim, int seq)
/* SPARSE_MATRIX *sp  The sparse matrix in which to find the header list
                        element */
/* int dim            The dimension number of the header list element*/
/*     seq            The sequence number of the header list element */
{
    SP_HDR_ELEMENT *header_list, *header_element;

    /* If the sparse matrix passed is empty, then there are no nodes to be
       found */
    if (sp == (SPARSE_MATRIX *)NULL)
        return ((SP_HDR_ELEMENT *)NULL);

    sp->error_no = SP_NOERR;

    /* Retrieve the header list associated with the dimension */
    header_list = sp_get_header_list(sp, dim);
    if ((sp->error_no != SP_NOERR) || (header_list == (SP_HDR_ELEMENT *)NULL)) {
        return ((SP_HDR_ELEMENT *)NULL);
    }

    /* Make sure that the sequence number specified is within range */
    if ((seq < sp_get_range_min(sp, dim)) || (sp->error_no != SP_NOERR)) {
        sp->error_no = SP_DLOW;
        return ((SP_HDR_ELEMENT *)NULL);
    }

    /* Make sure that the sequence number specified is within range */
    if ((seq > sp_get_range_max(sp, dim)) || (sp->error_no != SP_NOERR)) {
        sp->error_no = SP_DHIGH;
        return ((SP_HDR_ELEMENT *)NULL);
    }

    /* Search the header list for the requested sequence */
    header_element = header_list;
    while ((header_element->next->sequence <= seq) && (header_element->next != header_list)) {
        header_element = header_element->next;
    }

    /* If the header_element is not the same sequence number as passed in,
       then the sequence number is not in the list */
    if (header_element->sequence != seq) {
        return ((SP_HDR_ELEMENT *)NULL);
    } else {
        return (header_element);
    }
}
