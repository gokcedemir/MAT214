/* 
 * File:   main.cpp
 * Author: Gökçe Demir
 * Student ID: 141044067
 * 
 * Numerical Analysis Homework 3- Part 3 
 * This program is calculate the least squares polynomial .
 * Created on May 15, 2017, 2:47 PM
 */

#include <cstdlib>
#include <cmath>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

#define SIZE 25

using namespace std;

string leastSquarePoly(double corArr[][2], int m);

int main(int argc, char** argv) 
{
	int m=2;  //degree of polynomial
    string rv;
    double coordinate[5][2] = {
                                {0, 1.000 } ,{ 0.25 , 1.2840 },{0.50,1.6487},
                                {0.75, 2.1170 }, {1.00, 2.7183}
							 };
   

    rv=leastSquarePoly(coordinate,m);
    
    cout<<rv<<endl;
    
    return 0;
}

string leastSquarePoly(double corArr[][2], int m)
{
    int i=0;
    int j;
    double x[SIZE][SIZE];
    int value=5; //num of points
    int k=0;
    int count;
    double result;
    double resultArr[SIZE];
    double total;
    int a;
    string ss;

    while(k<=m)
    {
        count=k;
        //m=2 --> degree of polynomial
        for (i = 0; i <=m; i++)
        {
            for (j = 0; j < value; j++)
                x[k][i]+= pow(corArr[j][0],count);
            count++;
        }
        
        for( int b=0; b< value; b++)
        {
            x[k][i]+=corArr[b][1]*(pow(corArr[b][0],k));
        }
   
        k++;
    }

    for (i=0; i <=m; i++)
    {
        for (j = 0; j <=m; j++)
        {
            if(j>i)
            {
                result=x[j][i]/x[i][i];
                for(a=0; a<=m+1; a++)
                    x[j][a]=x[j][a]-result*x[i][a];
            }
        }
    }
    resultArr[m]=x[m][m+1]/x[m][m];
    for (i=m-1; i>=0; i--) 
    {
        total=0;
        for (j=i+1; j <=m ; j++)       
            total+=x[i][j]*resultArr[j];       
        resultArr[i]=(x[i][m+1]-total)/x[i][i];
    }
    for(i=0; i<=m; i++)
    {
        if(i==0)
            ss="P(x)=" + to_string(resultArr[i]);
        else 
            ss += "+" + to_string(resultArr[i]) + "x^" + to_string(i);
    }
       
    return ss;
}


