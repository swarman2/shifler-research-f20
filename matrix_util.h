#ifndef MATRIX_UTIL
#define MATRIX_UTIL

/*
  Utitlity function to print an n x n matrix, mat
*/
void print_matrix(short n, short** mat, int id=0, bool mathematica =false);


/*
  Utility function to delete an nxn matrix
*/
void delete_matrix(short n, short** mat);

/*
  Utility function to transpose an nxn matrix
*/
void transpose_matrix(short n, short** matrix);

/*
  Utility function to swap two shorts.
*/
void swap(short& a, short& b);

/*
  Utility function to multiply two nxn matricies
*/
short** multiply_matrix(short** mat1, short** mat2, int n);

/*
  Utility function to check the commutativity of two matricies
*/
void check_mult_commut(short** mat1, short** mat2, int n, int p1, int p2);

/*
  print n stars
*/
void print_stars(short n);

/*******************************

  Generate matrix functions (based on the thm proposed by Ryan Shifler Ph.D.)

*******************/
short** get_matrix(short n, short p);
void input_diagonal(short** matrix, short d, short* vals, short n);

#endif
