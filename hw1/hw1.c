/* 
 * File:   hw1.c
 * Author: Gökçe DEMİR 
 * STUDENT ID: 141044067
 * 
 * Created on March 10, 2017, 11:55 PM
 */

/******************************************************************************/
/*			  ~ BISECTION METHOD IN C ~										  */
/* This program include implement the Bisection method. The program should    */
/* work from the command line. The program will have 4 inputs:                */
/*	start_of_the_root, end_of_the_root,stop criteria,epsilon value.           */
/*  The program include math library so that when you compile, should add     */
/* -lm parametre.                                                             */
/******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define ITER 100

void bisection(double a, double b, char *errorCheck, double epsilon);

double function(double x);

int main(int argc, char** argv)
{
    //usage kontrolu
    if(argc != 5)
	{
        fprintf(stderr, "Usage: %s startOf_root endOf_root error_Check epsilon\n",argv[0]);
		exit(1);	
	}
   //Control of epsilon value                     
   if(atof(argv[4])<0)
    {
        fprintf(stderr,"Epsilon value should have positive real number.\n");
        exit(1);
    }
	
	
    bisection(atof(argv[1]),atof(argv[2]), argv[3], atof(argv[4]));
    
    return 0;
}

void bisection(double a, double b, char *errorCheck, double epsilon)
{
    double p0= 0.0;
    int currentIter=1;
    double root=0.0;
    double meanValue=0;
    int num=0;
    int foundIter=0;
    float theoreticalNum=0.0;

	//Control of f(a)*f(b)<0 
	if(function(a)*function(b) > 0)
    {
        fprintf(stderr,"f(a) and f(b) should have opposite sign.!\n");
        exit(1);
    }	
    
    //calculate the theoretical required number of iterations
    theoreticalNum=log2((b-a)/epsilon); 
       
    if(strcmp(errorCheck,"DISTANCE_TO_ROOT") == 0)
    {  
        p0=a;
        meanValue=(a+b)/2;
        printf("iter%d:\tAbsolute Error:%f\tRelative Error:%f\n",currentIter,
                fabs(meanValue-p0),(fabsf(meanValue-p0)/meanValue));
        
        while(fabs(meanValue) > epsilon)
        {
            if(function(a)*function(meanValue)>0)
                a = meanValue;
            else 
                b=meanValue;
            
            p0=meanValue;
            meanValue=(a+b)/2;
            if(fabs(function(p0))< epsilon)
            {
                root=p0;
                foundIter=currentIter;
                break;
            }
            ++currentIter;
            printf("iter%d:\tAbsolute Error:%f\tRelative Error:%f\n",
            currentIter,fabs(meanValue-p0),(fabsf(meanValue-p0)/meanValue));           
            
            ++num;
            
            if(currentIter >= 100)
            {
                printf("Something is wrong!\n");
                break;
            }
        }
       printf("The root is %f found that %d. iteration,theoretically required"
        " number of iterations %.0f!\n", root,foundIter,ceilf(theoreticalNum));
    }
    else if(strcmp(errorCheck,"ABSOLUTE_ERROR") ==0 )
    {
        p0=a;
        meanValue=(a+b)/2;
        printf("iter%d:\tAbsolute Error:%f\tRelative Error:%f\n",currentIter,
                fabs(meanValue-p0),(fabsf(meanValue-p0)/meanValue));
        
        while(((fabs(meanValue-p0))) > epsilon)
        {
            if(function(a)*function(meanValue)>0)
                a = meanValue;
            else 
                b=meanValue;
            
            p0=meanValue;
            meanValue=(a+b)/2;
            ++currentIter;
            if(((fabs(meanValue-p0)))< epsilon)
            {
                root=p0;
                foundIter=currentIter;
            }
            printf("iter%d:\tAbsolute Error:%f\tRelative Error:%f\n",currentIter,
					fabs(meanValue-p0),(fabsf(meanValue-p0)/meanValue));            
            ++num;
            
            if(currentIter >= 100)
            {
                printf("Something is wrong!\n");
                break;
            }
        }
        printf("The root is %f found that %d. iteration,theoretically required"
        " number of iterations %.0f!\n", root,foundIter,ceilf(theoreticalNum));
    }
    else if(strcmp(errorCheck,"RELATIVE_ERROR")==0)
    {
        p0=a;
        meanValue=(a+b)/2;
        printf("iter%d:\tAbsolute Error:%f\tRelative Error:%f\n",currentIter,
					fabs(meanValue-p0),(fabsf(meanValue-p0)/meanValue));
        
        if(meanValue ==0)
        {
            printf("Something is wrong.\n");
            exit(1);
        }
        while(((fabs(meanValue-p0)/meanValue)) > epsilon)
        {
            if(function(a)*function(meanValue)>0)
                a = meanValue;
            else 
                b=meanValue;
            
            p0=meanValue;
            meanValue=(a+b)/2;
            ++currentIter;
            if((fabs(meanValue-p0)/meanValue)< epsilon)
            {
                root=p0;
                foundIter=currentIter;
            }
            printf("iter%d:\tAbsolute Error:%f\tRelative Error:%f\n",currentIter,
					fabs(meanValue-p0),(fabsf(meanValue-p0)/meanValue));
            ++num;
            
            if(currentIter >= 100)
            {
                printf("Something is wrong!\n");
                break;
            }
        }
        printf("The root is %f found that %d. iteration,theoretically required"
        " number of iterations %.0f!\n", root,foundIter,ceilf(theoreticalNum));
    }
    else
        fprintf(stderr,"Undefined stopping criteria!\n");
    
    
}
double function(double x)
{
	/*exercise 6 of section 2.1 using the relative_error stopping criterion
 		and a tolerance of 10E-5 */
    double func=0.0; 
	func= (3*x-exp(x));
	//func= 2*x+3*cos(x)-exp(x);
	//func= x*x-4*x+4-log(x);
	//func=x+1-2*sin(M_PI*x);
	return func;  // 
}



