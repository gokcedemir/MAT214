/* 
 * File:   main.c
 * Author: Gökçe Demir
 * Student ID: 141044067
 * Numerical Analysis part-1
 * Created on May 6, 2017, 7:19 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROW_COL 10
#define ZERO 0
#define ONE 1

int *interpolation(int *matrix,int z, int s);

int main(int argc, char** argv)
{
    int z;   //integer zooming factor z > 1
    int s;  // interpolation strategy s
    int matrix[ROW_COL*ROW_COL]={
                        13,5,16,29,5,96,23,3,96,30,
                        1,2,3,4,5,64,7,8,4,30,
                        8,9,7,2,44,23,29,18,1,6,
                        54,12,10,13,14,17,19,25,89,4,
                        1,2,3,4,5,6,7,8,9,10,
                        5,4,6,3,2,2,1,20,8,7,
                        6,3,2,1,4,5,9,88,74,5,
                        13,5,17,36,38,37,52,12,6,4,
                        10,9,8,7,6,5,4,3,2,1,
                        12,13,14,15,16,17,18,19,14,12,
                    };
        
    z=3;
    s=0;  //s =0 için nearest neighbor interpolation yapıyor
    interpolation(matrix,z,s);  
    
    return (EXIT_SUCCESS);
}

int *interpolation(int *matrix,int z, int s)
{
    int w1= ROW_COL;
    int w2= z*ROW_COL;
    int *newMatrix;
    newMatrix=(int *)malloc((w2*w2) * sizeof(int));
    int j;
    int i;
    double x= w1/(double)w2;
    double px,py;

    if(z<1)
    {
        printf("z must be greater than one!\n");
        exit(ZERO);
    }

	    printf("============ Original Matrix ===========\n");
		for(i=0; i< w1*w1; i++)
		{
			printf("%3d ",matrix[i]);
			if((i+1)%w1==0)
				printf("\n");
			
		}
	printf("============== Nearest Neighbor Interpolation ================\n");
    if(s==0)  // s equals zero for nearest neighbor interpolation 
	{
		for (i = 0; i < w2; i++)
		{
		    for (j = 0; j < w2; j++)
		    {
		        px=floorf(j*x);
		        py=floorf(i*x);
		        newMatrix[(i*w2) +j] =matrix[(int)((py*w1)+px)];		        
		    }

		}
		for(i=0; i< w2*w2; i++)
		{
			printf("%3d ",newMatrix[i]);
			if((i+1)%w2==0)
				printf("\n");
		}
		printf("===========================================================\n");
	}
	
    return newMatrix;
}

