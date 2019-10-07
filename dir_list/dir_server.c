/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "dir.h"
#include<stdio.h>
#include<rpc/rpc.h>
#include<dirent.h>
int *print_dir_2_svc(dir_list *argp, struct svc_req *rqstp)
{
	static int  result;

	DIR* dirp;
	struct dirent* direntp;

	dirp = opendir(argp->dir_name);
	if( dirp == NULL )
	{
		printf("Can't open %s directory",argp->dir_name );
	}
	else
	{
	
		for(;;)
                {
                        direntp = readdir( dirp );
                        if( direntp == NULL ) break;

                        printf( "%s\n", direntp->d_name );
                }

                closedir( dirp );

	}



	return &result;
}
