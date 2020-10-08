#include<iostream>
#include"matrix_util.h"
#include"eigs.h"
#include "UI_util.h"



int main()
{
  short select=0;
  do
  {
    select = menu();
    switch(select)
    {
      case 1:print_matrices();
      break;
      case 2:comm_check();
      break;
      case 3: print_eigen_info();
      break;
    }

  }while(select!=4);
  return 0;
}
