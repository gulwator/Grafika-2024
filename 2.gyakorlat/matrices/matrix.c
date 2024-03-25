#include "matrix.h"

#include <stdio.h>

void init_zero_matrix(float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            matrix[i][j] = 0.0;
        }
    }
}

void print_matrix(const float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            printf("%4.4f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(const float a[3][3], const float b[3][3], float c[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void init_identity_matrix(float matrix[3][3])
{
    int i;
    int j;
    for (i =0; i<3; ++i){
        for(j=0; j< 3;++j){
            if(i==j){
            matrix[i][j] = 1;
            }
        }
    }
}

void scalar_matrix(const float matrix[3][3],float scalared_matrix[3][3] ,const float scalar)
{
    int i;
    int j;
    for ( i = 0; i < 3; ++i)
    {
        for ( j = 0; j < 3; ++j)
        {
            scalared_matrix[i][j]=scalar*matrix[i][j];
        }   
    }
}

void multiply_matrices(const float matrix_a[3][3], const float matrix_b[3][3],float matrix_multipled[3][3])
{
    int i;
    int j;  
    for ( i = 0; i < 3; ++i)
    {
        for ( j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                matrix_multipled[i][j]+=matrix_a[i][k]*matrix_b[k][j];
            }
            
        }
        
    }
    
}

