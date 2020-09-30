#ifndef EIGS_H
#define EIGS_H

#include <string.h>
#include <stdio.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_eigen.h>

//put all output in char* out
void print_eigs(gsl_vector_complex *v, int n, int matid);
//find the eigenvalues of a square matrix
gsl_vector_complex* gsl_eigs(gsl_matrix *a, int size);
//get eigenvalues of a short** matrix by converting to gsl
gsl_vector_complex* eigs(short** m, int n);
#endif
