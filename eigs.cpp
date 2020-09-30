#include"eigs.h"

//put all output in char* out
void print_eigs(gsl_vector_complex *v, int n, int matid){


	printf("~~~eigenvalues for %d x %d matrix p=%d~~~\n", n, n, matid);
	for(int i = 0; i < n; i++){
		printf("%g + %gi\n", GSL_REAL(gsl_vector_complex_get(v, i)), GSL_IMAG(gsl_vector_complex_get(v, i)));
	}
	printf("~~~end~~~\n\n");

	//printf("%s\n ^ has strlen %d\n", out, strlen(out));
}

//find the eigenvalues of a square matrix
gsl_vector_complex* gsl_eigs(gsl_matrix *a, int size){
	// //hold the original matrix to write to file later
	// gsl_matrix *a_copy;
	// a_copy = gsl_matrix_calloc(size, size);
	// gsl_matrix_memcpy(a_copy, a);
	//
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
	gsl_eigen_nonsymm_free(w);

	//print eigenvalues
	//TODO: do something different with output
	//either return it or print it to a file
	return result;
	//print_output(a_copy, result, size, matrix_id, output);

	//gsl_matrix_free(a_copy);
}

//get eigenvalues of a short** matrix by converting to gsl
gsl_vector_complex* eigs(short** m, int n)
{
	//hold the original matrix to write to file later
	gsl_matrix *m_copy;
	m_copy = gsl_matrix_calloc(n,n);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			gsl_matrix_set(m_copy,i,j,m[i][j]);
		}
	}
	gsl_vector_complex* v = gsl_eigs(m_copy, n);
	gsl_matrix_free(m_copy);
	return v;

}
