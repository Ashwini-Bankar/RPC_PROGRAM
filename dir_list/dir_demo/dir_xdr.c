/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "dir.h"

bool_t
xdr_dirlist (XDR *xdrs, dirlist *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->name, 20,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}
