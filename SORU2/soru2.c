/* #Newton Divided-Difference 
 * File       :   main.c
 * Author     : Gökçe Demir
 * Student ID : 141044067
 * 
 * Created on May 8, 2017, 2:22 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_SIZE 50
#define ZERO 0
#define ONE 1

char son[ARR_SIZE]="";

char* poli(double *x, double *y, double f);

int main(int argc, char** argv)
{
    char result[ARR_SIZE];
    
    double x[]={8.1, 8.3 , 8.6, 8.7};
    double y[]={16.94410 , 17.56492, 18.50515, 18.82091 };
    

    poli(x,y,8.4);
	printf("%s\n",son);
    
    return (EXIT_SUCCESS);
}

char* poli(double *x, double *y, double f)
{
    int sizeOfArr=4;
    int i=ZERO,j=ONE;
    double first=1.0, second=0;
    double result;
    double arr[ARR_SIZE];
    result=y[ZERO];

    
    while(sizeOfArr!=ONE)
    {    
        for (i=ZERO;i<sizeOfArr-ONE;i++)
        {
            arr[i] = ((y[i+ONE]-y[i])/(x[i+j]-x[i]));
            y[i]=arr[i];
        }
        first=1.0;
        for(i=ZERO;i<j;i++)
            first*=(f-x[i]);
        
        second+=(y[ZERO]*first);

        sizeOfArr--;
        j++;
    }
    result+=second;

	snprintf(son,ARR_SIZE,"f(%f)= %f",f,result);
    
    return son;
}


