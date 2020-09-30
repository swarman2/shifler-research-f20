#include"eigs.h"


//put all output in char* out
void print_eigs(eigen_info *v, int n, int matid){


	printf("~~~eigenvalues for %d x %d matrix p=%d~~~\n", n, n, matid);
	for(int i = 0; i < n; i++){
		printf("%g + %gi\n", GSL_REAL(gsl_vector_complex_get(v->eval, i)), GSL_IMAG(gsl_vector_complex_get(v->eval, i)));
	}
	printf("~~~end~~~\n\n");
	printf("~~~eigenvectors for %d x %d matrix p=%d~~~\n", n, n, matid);
	for(int i = 0; i < n; i++){
		for(int j=0; j<n; j++)
		{
			gsl_complex z = gsl_matrix_complex_get(v->evec, i,j);
			printf(     "(%.12e,%.12e)%s",
                  GSL_REAL(z),
                  GSL_IMAG(z),
                  (j < n - 1) ? " " : "\n");
		//	printf("%g + %gi\n", GSL_REAL(gsl_vector_complex_get(v, i)), GSL_IMAG(gsl_vector_complex_get(v, i)));
		}
	}
	printf("~~~end~~~\n\n");

	//printf("%s\n ^ has strlen %d\n", out, strlen(out));
}

//find the eigenvalues of a square matrix
eigen_info* gsl_eigs(gsl_matrix *a, int size){
	// //hold the original matrix to write to file later
	// gsl_matrix *a_copy;
	// a_copy = gsl_matrix_calloc(size, size);
	// gsl_matrix_memcpy(a_copy, a);
	//
	eigen_info *result = new eigen_info;
	//create workspace for computing eigenvalues
	gsl_eigen_nonsymmv_workspace* w;
	w = gsl_eigen_nonsymmv_alloc(size);
	//gsl_eigen_nonsymmv_params(0,0,w);

	//print_gsl_matrix(a, size, size);

	//create vector to hold the eigenvalues
	gsl_vector_complex *eval;
	eval = gsl_vector_complex_calloc(size);

	//create matrix to hold eigenvectors
	gsl_matrix_complex* evec;
	evec = gsl_matrix_complex_calloc(size, size);

	//calculate eigenvalues
	if(gsl_eigen_nonsymmv(a, eval, evec, w) != 0){
		puts("error");
		exit(1);
	}
	gsl_eigen_nonsymmv_free(w);
	result->eval = eval;
	result->evec = evec;
	//print eigenvalues
	//TODO: do something different with output
	//either return it or print it to a file
	return result;
	//print_output(a_copy, result, size, matrix_id, output);

	//gsl_matrix_free(a_copy);
}

//get eigenvalues of a short** matrix by converting to gsl
eigen_info* eigs(short** m, int n)
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
	eigen_info* v = gsl_eigs(m_copy, n);
	gsl_matrix_free(m_copy);
	return v;

}
