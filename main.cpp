#include<iostream>
#include"matrix_util.cpp"
#include"eigs.h"
/*
  Given a n, lambda and a p use Theorem 1.10 to
  find the
*/
short* get_col(short n, short lambda, short p);
/*
  Given an n and a p iterate over all the lambda
  values to generate a matrix
*/
//short** get_matrix(short n, short p);


short** get_matrix(short n, short p);

void input_diagonal(short** matrix, short d, short* vals, short n);
/*
  print n stars
*/
void print_stars(short n){
  for(int i=0; i<n; i++){std::cout<<"*";}
}

int main()
{
  short n=0;
  std::cout<<"> n = ";
  std::cin>>n;
  std::cout<<"\n\n";
  for(int p=1; p<2*n; p++)
  {
    std::cout<<"p = "<<p;
    std::cout<<"\n";
    print_stars(n*4);
    std::cout<<"\n";
    short** mat = get_matrix(n,p);
    print_matrix(2*n, mat);
    print_stars(n*4);
    std::cout<<"\n\n";
    // eigen_info* v = eigs(mat,2*n);
    // print_eigs(v, 2*n, p);
    // gsl_vector_complex_free(v->eval);
    // gsl_matrix_complex_free(v->evec);
    // delete v;
    delete_matrix(2*n, mat);
  }

  short p1=0;
  short p2=0;
  // while(true)
  // {
  //   std::cout<<"Enter first matrix: ";
  //   std::cin>>p1;
  //   std::cout<<"Enter second matrix: ";
  //   std::cin>>p2;
  //   short** mat1 = get_matrix(n,p1);
  //   short** mat2 = get_matrix(n,p2);
  //   short** mat1_times_mat2 = multiply_matrix(mat1, mat2, 2*n);
  //   short** mat1_times_mat2 = multiply_matrix(mat1, mat2, 2*n);
  //   std::cout<<"p = "<<p1;
  //   std::cout<<"\n";
  //   print_stars(n*4);
  //   std::cout<<"\n";
  //   print_matrix(2*n, mat1);
  //   print_stars(n*4);
  //   std::cout<<"\n\n";
  //   std::cout<<"p = "<<p2;
  //   std::cout<<"\n";
  //   print_stars(n*4);
  //   std::cout<<"\n";
  //   print_matrix(2*n, mat2);
  //   print_stars(n*4);
  //   std::cout<<"\n\n";
  //   std::cout<<"p1 * p2:";
  //   std::cout<<"\n";
  //   print_stars(n*4);
  //   std::cout<<"\n";
  //   print_matrix(2*n, mat1_times_mat2);
  //   print_stars(n*4);
  //   std::cout<<"\n\n";
  // }
  return 0;
}

/*
  Given an n and a p iterate over all the lambda
  values to generate a matrix
*/
// short** get_matrix(short n, short p)
// {
//   short** matrix = new short*[2*n];
//   short * col0  = new short[2*n];
//   for(int i=0; i<2*n; i++){col0[i]=0;}
//   col0[p] =1;
//   matrix[0]=col0;
//   for(int lambda = 1; lambda<2*n; lambda++)
//   {
//     matrix[lambda] = get_col(n, lambda, p);
//   }
//   transpose_matrix(2*n, matrix);
//   return matrix;
// }
short** get_matrix(short n, short p)
{
  short** matrix = new short*[2*n];
  for(int i=0; i<2*n; i++){matrix[i]=new short[2*n];}
  for(int i=0; i<2*n; i++)
  {
    for(int j=0; j<2*n; j++)
    {
      matrix[i][j]=0;
    }
  }
  if(1<=p && p<n)
  {
    short diag1[2*n-p];
    for(int i=0; i<n-p; i++){diag1[i]=1;}
    for(int i=n-p; i<n; i++){diag1[i]=2;}
    for(int i=n; i<2*n-p; i++){diag1[i]=1;}

    short diag2[2+p-1];
    for(int i=0; i<2+p-1; i++){diag2[i]=2;}//I will overwrite the ends
    diag2[0]=1;
    diag2[p]=1;
    input_diagonal(matrix, 2*n-p, diag1, 2*n);
    input_diagonal(matrix, 4*n-p-1, diag2, 2*n);
  }
  else if (n <= p && p < 2*n-1)
  {
    short diag1[2*n-p];
    for(int i=0; i<2*n-p; i++){diag1[i]=1;}

    //len diagonal = 2+p-n+2*n-p-1+p-n = p+1
    short diag2[p+1];
    diag2[0]=1;
    int spot =1;
    for(int i=spot; i<spot+p-n; i++){diag2[i]=2;}
    spot += p-n;
    for(int i=spot; i<spot + 2*n-p-1; i++){diag2[i]=1;}
    spot+= 2*n-p-1;
    for(int i =spot; i< spot+p-n; i++){diag2[i]=2; }
    spot+=p-n;
    for(int i=spot; i<p+1; i++){diag2[i]=1;}
  //  for(int i=p-n+1; i<2*n-p; i++){std::cout<<"test"<<std::endl; diag2[i]=1;}

    input_diagonal(matrix, 2*n-p, diag1, 2*n);
    input_diagonal(matrix, 4*n-p-1, diag2, 2*n);
  }
  else if (p == 2*n-1)
  {
    short diag1[1];
    diag1[0]=1;

    short diag2[2*n];
    for(int i=0; i<2*n; i++){diag2[i]=1;}//I will overwrite the ends
    diag2[0]=0;
    diag2[2*n-1]=0;

    input_diagonal(matrix, 1, diag1, 2*n);
    input_diagonal(matrix, 2*n, diag2, 2*n);
    input_diagonal(matrix, 4*n-1, diag1, 2*n);
  }
  return matrix;
}

void input_diagonal(short** matrix, short d, short* vals, short n)
{
  if(d<=n)//lower diagonal
  {
    //starting row
    int row = n-d;//d is at least 1;
    for(int col=0; col<d; col++)
    {
      matrix[row][col]=vals[col];
      row++;
    }
  }
  else
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
/*
  Given a n, lambda and a p use Theorem 1.10 to
  find the
*/
short* get_col(short n, short lambda, short p)
{
  short* col = new short[2*n];
  for(int i=0; i<2*n; i++){col[i]=0;}

  if(p<n)
  {
    if(lambda + p < 2*n-1)  // case 1
    {
      if(n-p<=lambda && lambda < n){col[lambda+p] = 2;}
      else {col[lambda+p]=1;}
    }
    else if(lambda + p == 2*n-1) // case 2
    {
      col[2*n-1]=1;
      col[0]=1;
    }
    else
    {
      if(lambda == 2*n-1){col[p]=1;}
      else{col[lambda+p-(2*n-1)] =2;}
    }
  }
  else
  {
    if(lambda+p<2*n-1){col[lambda+p]=1;}
    else if(lambda + p == 2*n-1)
    {
      col[2*n-1]=1;
      col[0]=1;
    }
    else if(4*n-2>lambda+p && lambda+p > 2*n-1)
    {
      if(3*n-1<=lambda+p && lambda + p <2*(n-1) +lambda)
      {
        col[lambda+p-(2*n-1)]=2;
      }
      else
      {
        col[lambda+p-(2*n-1)]=1;
      }
    }
    else if(lambda+p == 4*n-2)
    {
      col[0]=1;
    }
  }
  return col;
}
