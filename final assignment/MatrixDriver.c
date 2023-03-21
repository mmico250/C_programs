#include <stdio.h>
#include <stdio.h>
#include <math.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */



void coFactor(int size, double matrix[size][size], double newMatrix[size-1][size-1], int row, int column)
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
	
	if(size == 1)
		return matrix[0][0];
	else if (size== 2)
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	else
	{
		double nextMatrix[size-1][size-1];
		for (int i =0;i<size;i++)
		{
			 coFactor(size, matrix[size][size],nextMatrix[size-1][size-1], 0, i);
			 result += m[0][i] * pow (-1, i) * determinant (n - 1, newMatrix); 
		}
	}
	
	return result;
}



int main(int argc, char** argv)
{
	int n = 0;
    printf ("Enter the number of rows =>\n"); 

     scanf ("%d", &n); 
     
     double a[n][n]; 
      printf ("Enter the numbers row by row and after each number hit return\n"); 
	for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
        	 scanf("%lf", a[i][j]);
		}  
    }
	
	for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
        	 printf("  %lf", a[i][j]);
		}  
        printf("\n");
    }
    printf("lf",determinant(n,a));
	return 0;
}
