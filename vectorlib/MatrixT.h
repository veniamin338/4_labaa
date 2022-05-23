//#pragma once
#include "VectorT.h"

template <class M>
class TMatrix : public TVector<TVector<M>>
{
protected:
  int stl;
public:
  TMatrix(int a = 1,int b=1);
  ~TMatrix();

};


template<class M>
inline TMatrix<M>::TMatrix(int a, int b) //:TVector<TVector<M>>::TVector(a)// вопрос 1
{
  this->str = a;
  this->stl = b;
  this->transponir = 1;
  this->koordinat = new TVector<M>[b];
  for (int i = 0; i < b; i++)
  {
    this->koordinat[i] = TVector<M>(a);
  }
}

template<class M>
inline TMatrix<M>::~TMatrix()
{
  if (koordinat != 0)
  {
    for (int i = 0; i < (stl); i++)
    {
      this->koordinat[i].~TVector();
      
    }
    delete[] this->koordinat;
    this->koordinat = 0;
  }
  
}

