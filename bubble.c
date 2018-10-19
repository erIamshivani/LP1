#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);

int main (int argc, char *argv[]) {

	
	int A[10];
	int N = 10;
	int i=0, j=0; 
	int first;

	printf("\n-----------Input array-------------\nEnter 10 integers:");
	for(i=0;i<N ;i++)
	{
		scanf("%d", &A[i] );
	}
	for(i=0;i<N ;i++)
	{
	printf("\n %d",A[i]);
	}
	for( i = 0; i < N; i++ )
	{
		first = i % 2; 
		#pragma omp parallel for default(none),shared(A,first,N)	//Creates parallel threads to swap consecutive elements
		for( j = first; j < N-1; j += 2 )
		{
			if( A[ j ] > A[ j+1 ] )
			{
				swap( &A[ j ], &A[ j+1 ] );
			}
		}
	}
	printf("\n===============Output===============\n");
	for(i=0;i<N;i++)
	{

		printf("\n %d",A[i]);
	}
}

void swap(int *num1, int *num2)
{

	int temp = *num1;
	*num1 =  *num2;
	*num2 = temp;
}



/*
OUTPUT:
[lenovo@localhost ~]$ gcc -fopenmp bubble.c
[lenovo@localhost ~]$ ./a.out

================Input array===============

 6
 9
 1
 3
 7
 34
 23
 87
 4
 45
===============Output===============

 1
 3
 4
 6
 7
 9
 23
 34
 45
 87

*/

