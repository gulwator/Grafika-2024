#ifndef MATRIX_H
#define MATRIX_H

/**
 * Initializes all elements of the matrix to zero.
 */
void init_zero_matrix(float matrix[3][3]);

/**
 * Print the elements of the matrix.
 */
void print_matrix(const float matrix[3][3]);

/**
 * Add matrices.
 */
void add_matrices(const float a[3][3], const float b[3][3], float c[3][3]);

/**
* Initializes identity matrix
*/
void init_identity_matix(float matrix[3][3]);

/**
 * Multiply matrix by scalar
*/
void scalar_matrix(const float matrix[3][3],float scalared_matrix[3][3] ,const float scalar);

/**
 * Multiply Matrices
*/
void multiply_matrices(const float matrix_a[3][3], const float matrix_b[3][3],float matrix_multipled[3][3]);

#endif // MATRIX_H

