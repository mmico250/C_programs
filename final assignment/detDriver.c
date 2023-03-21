#include <stdio.h>
#include <stdio.h>
#include <math.h>


/*********************************************************************

program:                  detDriver.c
purpose:                  recursively compute the determinant
date:                     5/12/2021
by:                       Mike Mico

**************************************************************************/


//method  to get the sub matrix
void coFactor(int size, double matrix[size][size], double newMatrix[size-1][size-1], int row, int column)
{
	//initialize variables
	int i=0;
	int j =0;
	int k= 0;
	int l= 0;
	
	//recopy the matrix into the new matrrix
	for ( i = 0; i < size; i++) 
    { 
        //if this is not the row we are covering
        if (i != row) 
        { 
            for ( j = 0; j < size; j++) 
            { 
            	//if this is not the column we are covering
                if (j != column) 
                { 
                    newMatrix[k][l] = matrix[i][j]; 
                    //iterate after assignment
                    l++; 
	            } 
            } 
            //iterate after assignment
			k++; 
			//reset l=0 to allow iteration from start again
            l=0; 
            } 
        } 
}

//method to calculate the determinant
double det(int size, double matrix[size][size])
{
	double result = 0;
	int i=0;
	//base case 1
	if(size == 1)
		return matrix[0][0];
	//base case 2
	else if (size== 2)
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	else
	{
		double nextMatrix[size-1][size-1];
		for ( i =0;i<size;i++)
		{
			 coFactor(size, matrix, nextMatrix, 0, i);
			 //recursively call det on the coFactor
			 result += matrix[0][i] * pow (-1, i) * det(size - 1, nextMatrix); 
		}
	}
	
	return result;
}



int main(int argc, char** argv)
{
	int n = 0;
	int i = 0;
	int j = 0;
    printf ("Enter the number of rows\n"); 

     scanf ("%d", &n); 
     
     double a[n][n]; 
     printf ("insert numbers  \n"); 
	for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
        	printf("insert at a[%d][%d] \n",i,j);
        	 scanf("%lf", &a[i][j]);
		}  
		printf ("next line  \n"); 
    }
	printf("printing your inputs \n");
	for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
        	 printf("%lf ", a[i][j]);
		}  
		printf("\n");
    }
    printf("%lf",det(n,a));
	return 0;
}
