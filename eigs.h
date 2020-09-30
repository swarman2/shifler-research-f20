#ifndef EIGS_H
#define EIGS_H

#include <string.h>
#include <stdio.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_eigen.h>

struct eigen_info{
	gsl_vector_complex *eval;
	gsl_matrix_complex *evec;
};

//put all output in char* out
void print_eigs(eigen_info *v, int n, int matid);
//find the eigenvalues of a square matrix
eigen_info* gsl_eigs(gsl_matrix *a, int size);
//get eigenvalues of a short** matrix by converting to gsl
eigen_info* eigs(short** m, int n);


#endif
