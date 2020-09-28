#include<iostream>
#include"matrix_util.cpp"
/*
  Given a n, lambda and a p use Theorem 1.10 to
  find the
*/
short* get_col(short n, short lambda, short p);
/*
  Given an n and a p iterate over all the lambda
  values to generate a matrix
*/
short** get_matrix(short n, short p);

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
    delete_matrix(2*n, mat);
  }
  return 0;
}

/*
  Given an n and a p iterate over all the lambda
  values to generate a matrix
*/
short** get_matrix(short n, short p)
{
  short** matrix = new short*[2*n];
  short * col0  = new short[2*n];
  for(int i=0; i<2*n; i++){col0[i]=0;}
  col0[p] =1;
  matrix[0]=col0; 
  for(int lambda = 1; lambda<2*n; lambda++)
  {
    matrix[lambda] = get_col(n, lambda, p);
  }
  transpose_matrix(2*n, matrix);
  return matrix;
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
