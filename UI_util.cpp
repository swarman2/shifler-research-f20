#include<iostream>
#include"matrix_util.h"
#include"eigs.h"
#include "UI_util.h"

short menu()
{
  char select =0;
  do
  {
    std::cout<<"-------- MENU --------\n";
    std::cout<<"1) Print matrices\n";
    std::cout<<"2) Check commutativity\n";
    std::cout<<"3) Print eigenvalues & eigenvectors\n";
    std::cout<<"4) Quit\n";
    std::cin>>select;
    if (48>(int)select && (int)select< 52)
      std::cout<<"Invalid input "<<(int)select<<"\n";
  }while(48>(int)select && (int)select< 52);
  return (short)select-48;
}

void comm_check()
{
  short p1=0;
  short p2=0;
  short n=0;
  std::cout<<"Enter n: ";
  std::cin>>n;
  std::cout<<"Enter second matrix: ";
  std::cin>>p2;
  short** mat1 = get_matrix(n,p1);
  short** mat2 = get_matrix(n,p2);
  check_mult_commut(mat1, mat2, n, p1, p2);
  delete_matrix(2*n, mat1);
  delete_matrix(2*n, mat2);
}

void print_matrices()
{
  short n=0;
  std::cout<<"> n = ";
  std::cin>>n;
  std::cout<<"\n\n";
  for(int p=1; p<2*n; p++)
  {
    short** mat = get_matrix(n,p);
    print_matrix(2*n, mat, p);
    delete_matrix(2*n, mat);
  }
}

void print_eigen_info()
{
  short n=0;
  std::cout<<"> n = ";
  std::cin>>n;
  std::cout<<"\n\n";
  for(int p=1; p<2*n; p++)
  {
    short** mat = get_matrix(n,p);
    eigen_info* v = eigs(mat,2*n);
    print_eigs(v, 2*n, p);
    gsl_vector_complex_free(v->eval);
    gsl_matrix_complex_free(v->evec);
    delete v;
    delete_matrix(2*n, mat);
  }
}
