/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "IDL.h"
#include<stdio.h>
#include<rpc/rpc.h>

float compute_3(char *host,float a, float b, char op)
{
	CLIENT *clnt;
	float  *result_1;
	values  add_3_arg;
	float  *result_2;
	values  sub_3_arg;

	if(op=='+')
	{
		add_3_arg.n1=a;
		add_3_arg.n2=b;
		add_3_arg.opt=op;

		clnt = clnt_create (host, COMPUTE, COMPUTE_VERS, "tcp");
		if (clnt == NULL) 
		{
			clnt_pcreateerror (host);
			exit (1);
		}


		result_1 = add_3(&add_3_arg, clnt);
		if (result_1 == (float *) NULL) 
		{
			clnt_perror (clnt, "call failed");
		}
		clnt_destroy (clnt);
		return (*result_1);       
	}

	else if(op=='-')
	{
		CLIENT *clnt;
		float  *result_1;
		values  add_3_arg;
		float  *result_2;
		values  sub_3_arg;

		sub_3_arg.n1=a;
		sub_3_arg.n2=b;
		sub_3_arg.opt=op;

		clnt = clnt_create (host, COMPUTE, COMPUTE_VERS, "tcp");
		if (clnt == NULL)
		{
			clnt_pcreateerror (host);
			exit (1);
		}


		result_2 = sub_3(&sub_3_arg, clnt);
		if (result_2 == (float *) NULL) 
		{
			clnt_perror (clnt, "call failed");
		}
		clnt_destroy (clnt);
		return(*result_2);

	}
}

int main (int argc, char *argv[])
{
	char *host;
	float no1,no2;
	char oper;

	if (argc < 2) 
	{
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	printf("Enter two no.s and operation(+,-)");
	scanf("%f%f",&no1,&no2);
	scanf("%s",&oper);

	host = argv[1];
	printf("\nAnswer = %f\n",compute_3(host,no1,no2,oper));

	exit (0);
}