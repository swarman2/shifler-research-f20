/*
  Utitlity function to print an n x n matrix, mat
*/
void print_matrix(short n, short** mat);


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


void print_matrix(short n, short** mat)
{
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
    {
      std::cout<<mat[i][j]<<" ";
    }
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
