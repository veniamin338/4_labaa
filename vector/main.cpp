#include <iostream>
//#include "VectorT.h"
#include "MatrixT.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
  TVector <int> a(5);
  TVector <double> b(8);
  TVector <double> c(b);
  TVector <double> c2(7);
  TMatrix <int> m1(5,9);
  b = b / c2;
  //cin >> a; 
  //m1.SetRazmer(9);
  //int* mas;
  //mas = 0;
  //int* mas2;
 // mas2 = new int[0];
  //m1.GetRazmer();
  m1[1][1] = 99;
  int aaa = m1[1][1];
  //std::cout << m1 << std::endl;
  //std::cout << m1.GetRazmer() << std::endl;
  std::cout << m1 << std::endl;
 
  
  return 0;
}