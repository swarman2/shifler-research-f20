#include<iostream>
#include"matrix_util.h"
#include"eigs.h"
#include "UI_util.h"
#include "matplotlibcpp.h"
#include <string>
#include <sstream>
namespace plt = matplotlibcpp;
short menu()
{
  char select =0;
  do
  {
    std::cout<<"-------- MENU --------\n";
    std::cout<<"1) Print matrices\n";
    std::cout<<"2) Check commutativity\n";
    std::cout<<"3) Print eigenvalues & eigenvectors\n";
    // std::cout<<"4) Graph eigenvalues\n";
    std::cout<<"4) Quit\n";
    std::cin>>select;
    if (48>(int)select || (int)select> 52)
      std::cout<<"Invalid input "<<(int)select-48<<"\n";
  }while(48>(int)select || (int)select> 52);
  return (short)select-48;
}

void comm_check()
{
  short p1=0;
  short p2=0;
  short n=0;
  std::cout<<"Enter n: ";
  std::cin>>n;
  std::cout<<"Enter first matrix: ";
  std::cin>>p1;
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
  std::cout<<"{";
  for(int p=1; p<2*n; p++)
  {
    short** mat = get_matrix(n,p);
    print_matrix(2*n, mat, p,true);
    if(p!=2*n-1)
      std::cout<<",";
    delete_matrix(2*n, mat);
  }
  std::cout<<"}\n";
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

// void plot_eigen_val()
// {
//   short n=0;
//   std::cout<<"> n = ";
//   std::cin>>n;
//
//   for(int p=1; p<2*n; p++)
//   {
//     // plt::figure();
//     std::vector<double> x;
//     std::vector<double> y;
//     short** mat = get_matrix(n,p);
//     eigen_info* v = eigs(mat,2*n);
//     for(int i = 0; i < 2*n; i++){
//       x.push_back(GSL_REAL(gsl_vector_complex_get(v->eval, i)));
//       y.push_back(GSL_IMAG(gsl_vector_complex_get(v->eval, i)));
//     }
//
//     gsl_vector_complex_free(v->eval);
//     gsl_matrix_complex_free(v->evec);
//     delete v;
//     delete_matrix(2*n, mat);
//     std::cout<<"test"<<std::endl;
//     // plt::xlabel("Real");
//     // plt::ylabel("Imag");
//     std::cout<<"test"<<std::endl;
//     std::ostringstream oss;
//     std::cout<<"test"<<std::endl;
//     oss << "Eigenvalues for n = " << n << " & p = " << p;
//     // std::string title = oss.str();
//     std::cout<<"test"<<std::endl;
//     char* title;
//     sprintf(title,"Eigenvalues for n = %d & p=%d",n,p);
//     // plt::title(title);
//     // plt::axis("on");
//     title = std::string("graphs/")+title;
//     std::string* file_name;
//     sprintf(file_name,"%s.png",title);
//     std::cout<<"file name = "<<title<<std::endl;
//     plt::plot(x,y, "r*");
//     // plt::save(title);
//     plt::close();
//   }
// }
