#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#define MAXVAL 10000 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double size = 4;


void makeSubMatrix(int size, double matrix[size][size], double newMatrix[size-1][size-1], int row, int column)
{
	int k= 0;
	int l= 0;
	
	
	for (int i = 0; i < size; i++) 
    { 
        if (i != row) 
        { 
            for (int j = 0; j < size; j++) 
            { 
                if (j != column) 
                { 
                    newMatrix[k][l] = matrix[i][j]; 
                    l++; 
	            } 
            } 
			k++; 

            l=0; 
            } 
        } 
}

double determinant(int size, double matrix[][])
{
	double result = 0;
	
	if(n == 1)
		return matrix[0][0];
	else if (n== 2)
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	else
	{
		double nextMatrix[size-1][size-1];
		for (int i =0;i<size;i++)
		{
			 makeSubMatrix(size, matrix[size][size],nextMatrix[size-1][size-1], 0, i);
			 result += m[0][i] * pow (-1, i) * determinant (n - 1, newMatrix); 
		}
	}
	
	return result;
}



int main(int argc, char** argv)
{
	double a[row][column]; 
	for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf("  %d", mat[i][j]);
        printf("n");
    }
	return 0;
}