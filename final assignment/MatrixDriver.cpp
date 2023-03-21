#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#define MAXVAL 10000 

   
/********************************
 A structure for a Matrix
*********************************/
    struct Matrix 

    { 

        double a[MAXVAL][MAXVAL]; 

    }; 
    
    

 /**********************************************************
   This calculates the determinant of the smaller matrices
 ***********************************************************/
void subMatrix(int n,double M[n-1][n-1], double m[n][n], int I, int J) 

    { 
        int i, a = 0, b = 0; 
        int j; 
        for (i = 0; i < n; i++) 
        { 
            if (i != I) 
            { 
                for (j = 0; j < n; j++) 
                { 
                    if (J != j) 
                    { 
                       M[a][b] = m[i][j]; 
                       b++; 
	               } 

                } 
                a++; 

                b=0; 
            } 
        } 
    } 

 

 /***************************************
   This function calculates the determinant
 ****************************************/

double determinant (int n, double m[n][n]) 
{ 
	int i;
    double det = 0; 

      /*************************
       If it is a 1x1 Matrix
      **************************/

      if (n == 1) 

        { 

          return m[0][0]; 

        } 
        /****************************
          If it is a 2x2 matrix
        *****************************/

      if (n == 2) 

        { 
          det = m[0][0] * m[1][1] - m[0][1] * m[1][0]; 
        } 
      else 
        { 

          double M[n - 1][n - 1]; 

          for (i = 0; i < n; i++) 

        	{ 

          		subMatrix (n, M, m, 0, i); 
				det += m[0][i] * pow (-1, i) * determinant (n - 1, M); 

        	}	 

        } 
      return det; 

    } 

 

int main () 

{ 

    int n, k= 0; 
    int i,j;

 

      printf ("Enter the number of rows =>\n"); 

      scanf ("%d", &n); 

      double Matrix[n][n]; 

      printf ("Enter the numbers row by row and after each number hit return\n"); 

     /**************************
      Puting User data in Matrix
     ***************************/
      for ( i = 0; i < n; i++) 

        { 

          for ( j = 0; j < n; j++) 

        { 

          scanf ("%lf", &Matrix[i][j]); 

        } 

        } 

 

      /****************************************
       Prints out the Determinant
      *****************************************/

      printf ("The determinant of this Matrix is => %lf\n", determinant (n, Matrix)); 

 

      return 0; 

} 

 
