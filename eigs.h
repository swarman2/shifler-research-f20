#ifndef EIGS_H
#define EIGS_H

#include <string.h>
#include <stdio.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_eigen.h>

//put all output in char* out
void print_output(gsl_matrix *a, gsl_vector_complex *v, int n, int matid, char* out){
	sprintf(out, "%s===start of matrix===\n", out);
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			sprintf(out, "%s %g ", out, gsl_matrix_get(a, i, j));
		}
		sprintf(out, "%s\n", out);
	}
	sprintf(out, "%s===end of matrix===\n\n", out);

	sprintf(out, "%s~~~eigenvalues for %d x %d matrix #%d~~~\n", out, n, n, matid);
	for(i = 0; i < n; i++){
		sprintf(out, "%s%g + %gi\n", out, GSL_REAL(gsl_vector_complex_get(v, i)), GSL_IMAG(gsl_vector_complex_get(v, i)));
	}
	sprintf(out, "%s~~~end~~~\n\n", out);

	//printf("%s\n ^ has strlen %d\n", out, strlen(out));
}

//find the eigenvalues of a square matrix
void gsl_eigs(gsl_matrix *a, int size, int matrix_id, char* output){
	//hold the original matrix to write to file later
	gsl_matrix *a_copy;
	a_copy = gsl_matrix_calloc(size, size);
	gsl_matrix_memcpy(a_copy, a);

	//create workspace for computing eigenvalues
	gsl_eigen_nonsymm_workspace* w;
	w = gsl_eigen_nonsymm_alloc(size);
	gsl_eigen_nonsymm_params(0,0,w);

	//print_gsl_matrix(a, size, size);

	//create vector to hold the eigenvalues
	gsl_vector_complex *result;
	result = gsl_vector_complex_calloc(size);

	//calculate eigenvalues
	if(gsl_eigen_nonsymm(a, result, w) != 0){
		puts("error");
		exit(1);
	}

	//print eigenvalues
	//TODO: do something different with output
	//either return it or print it to a file
	
	print_output(a_copy, result, size, matrix_id, output);

	gsl_matrix_free(a_copy);
}

#endif
