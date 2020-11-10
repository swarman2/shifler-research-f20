#include<iostream>
#include "matrix_util.h"

short** multiply_matrix(short** mat1, short** mat2, int n)
{
  short** new_mat = new short*[n];
  for(int i=0; i<n; i++)
  {
    new_mat[i] = new short [n];
  }
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
    {
      new_mat[i][j]=0;
    }
  }
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
    {
      for(int k=0; k<n; k++)
      {
        new_mat[i][j]+= mat1[i][k] * mat2[k][j];
      }
    }
  }
  return new_mat;
}


void print_matrix(short n, short** mat, int id, bool mathematica)
{

  if(mathematica)
  {
    std::cout<<"{";
    for(int i=0; i<n; i++)
    {
      std::cout<<"{";
      for(int j=0; j<n; j++)
      {
        std::cout<<mat[i][j];
        if(j!=n-1)
          std::cout<<",";
      }
      std::cout<<"}";
      if(i!=n-1)
        std::cout<<",";
      std::cout<<"\n";
    }
    std::cout<<"}";
  }
  else
  {
    if(id!=0)
      std::cout<<"p = "<<id;
    std::cout<<"\n";
    print_stars(n*4);
    std::cout<<"\n";
    for(int i=0; i<n; i++)
    {
      for(int j=0; j<n; j++)
      {
        std::cout<<mat[i][j]<<" ";
      }
      std::cout<<"\n";
    }
    print_stars(n*4);
    std::cout<<"\n";
  }

}

void delete_matrix(short n, short** mat)
{
  for(int i=0; i<n; i++)
  {
    delete [] mat[i];
  }
  delete [] mat;
}

void transpose_matrix(short n, short** matrix)
{
  //transpose the matrix
  for(int i=0; i<n; i++)
  {
    //iterate over bottom diagonal
    for (int j=0; j<i; j++)
    {
      swap(matrix[j][i], matrix[i][j]);
    }
  }
}

void swap(short& a, short& b)
{
  short tmp = a;
  a=b;
  b=tmp;
}

void check_mult_commut(short** mat1, short** mat2, int n, int p1, int p2)
{

    short** mat1_times_mat2 = multiply_matrix(mat1, mat2, 2*n);
    short** mat2_times_mat1 = multiply_matrix(mat2, mat1, 2*n);
    print_matrix(2*n, mat1, p1);
    print_matrix(2*n, mat2, p2);

    std::cout<<"p1 * p2:";
    print_matrix(2*n, mat1_times_mat2);
    std::cout<<"p2 * p1:";
    print_matrix(2*n, mat2_times_mat1);
    delete_matrix(2*n, mat1_times_mat2);
    delete_matrix(2*n, mat2_times_mat1);
}

/*
  print n stars
*/
void print_stars(short n){
  for(int i=0; i<n; i++){std::cout<<"*";}
}



/*
 The function get_matrix generates a matrix given an 'n' and a 'p'
 using Thereom 5.1
*/
short** get_matrix(short n, short p)
{
  //allocate space for the matrix
  short** matrix = new short*[2*n];
  for(int i=0; i<2*n; i++){matrix[i]=new short[2*n];}

  //initalize all entries of the matrix to 0
  for(int i=0; i<2*n; i++)
  {
    for(int j=0; j<2*n; j++)
    {
      matrix[i][j]=0;
    }
  }

  //Begin Thereom 5.1
  if(1<=p && p<n) // case 1
  {
    short diag1[2*n-p]; // allocate array to hold diagonal 2n-p

    for(int i=0; i<n-p; i++){diag1[i]=1;} // fill first n-p spots with 1
    for(int i=n-p; i<n; i++){diag1[i]=2;} // fill p spots with 2
    for(int i=n; i<2*n-p; i++){diag1[i]=1;} // fill last n-p spots with 1

    short diag2[2+p-1]; // allocate array to hold diagional 2n-p-1
    for(int i=0; i<2+p-1; i++){diag2[i]=2;}// fill the entire array with 2s
    diag2[0]=1; // set the first spot to 1
    diag2[p]=1; // set the last spot to 1

    //insert the diagonals
    input_diagonal(matrix, 2*n-p, diag1, 2*n);
    input_diagonal(matrix, 4*n-p-1, diag2, 2*n);
  }
  else if (n <= p && p < 2*n-1) // case 2
  {
    short diag1[2*n-p]; // allocate array to hold diagonal 2n-p
    for(int i=0; i<2*n-p; i++){diag1[i]=1;} // fill diagonal with 1s

    short diag2[p+1]; // allocate array to hold diagonal 4n-p-1
    diag2[0]=1; //fill first spot with 1
    int spot =1;
    for(int i=spot; i<spot+p-n; i++){diag2[i]=2;} // fill p-n spots with 2
    spot += p-n;
    for(int i=spot; i<spot + 2*n-p-1; i++){diag2[i]=1;} // fill 2n-p-1 spots with 1
    spot+= 2*n-p-1;
    for(int i =spot; i< spot+p-n; i++){diag2[i]=2; } // fill p-n spots with 2
    spot+=p-n;
    for(int i=spot; i<p+1; i++){diag2[i]=1;} // fill last spot with 1

    // insert the diagonals
    input_diagonal(matrix, 2*n-p, diag1, 2*n);
    input_diagonal(matrix, 4*n-p-1, diag2, 2*n);
  }
  else if (p == 2*n-1) // case 3
  {
    short diag1[1]; // allocate array to hold diagonal 1
    diag1[0]=1; // fill array with 1

    short diag2[2*n]; // allocate array to hold diagonal 2n
    for(int i=0; i<2*n; i++){diag2[i]=1;} // fill array with 0
    diag2[0]=0; // fill first spot with 0
    diag2[2*n-1]=0; // fill last spot with 0

    //input the diagonals (note diagonal 4n-1 = diagonal 1)
    input_diagonal(matrix, 1, diag1, 2*n);
    input_diagonal(matrix, 2*n, diag2, 2*n);
    input_diagonal(matrix, 4*n-1, diag1, 2*n);
  }
  return matrix;
}

void input_diagonal(short** matrix, short d, short* vals, short n)
{
  if(d<=n) // lower diagonal
  {
    //starting row
    int row = n-d;//d is at least 1;
    for(int col=0; col<d; col++)
    {
      matrix[row][col]=vals[col];
      row++;
    }
  }
  else // upper diagonal
  {
    //starting col
    int starting_col = d-n;
    int col = starting_col;
    for(int row=0; row<2*n-d; row++)
    {
      matrix[row][col]=vals[row];
      col++;
    }
  }
}
