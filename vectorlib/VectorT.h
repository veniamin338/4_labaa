#pragma one
#include <iostream>

template<class T>
class TVector
{
protected:
  int str;
  T* koordinat;
  bool transponir = 0;
  
public:
  void SetRazmer(int a);
  //void SetKoordinat(T a);
  int GetRazmer();
  T GetKooordinat(int a);
  bool GetTransponir();
  TVector(int p = 1);
  TVector(const TVector<T>& p);
  ~TVector();
  void Transponir();
  TVector<T> operator + (const TVector<T>& p);
  TVector<T> operator - (const TVector<T>& p);
  TVector<T> operator = (const TVector<T>& p);
  TVector<T> operator * (const TVector<T>& p);
  TVector<T> operator / (const TVector<T>& p);
  bool operator == (const TVector<T>& p);
  T& operator [] (int a);
 
  //friend std::istream& operator>>(std::istream& istr_,TVector<T>& p);
  //std::ostream& operator<< (std::ostream& ostr_, const TVector<T>& p);
   
};


template<class T>
inline void TVector<T>::SetRazmer(int a)
{
  str = a;
}

template<class T>
inline int TVector<T>::GetRazmer()
{
  return this->str;
}

template<class T>
inline T TVector<T>::GetKooordinat(int a)
{
  return koordinat[a];
}

template<class T>
inline bool TVector<T>::GetTransponir()
{
  return transponir;
}

template<class T>
inline TVector<T>::TVector(int a)
{
  if (a >= 0)
  {
    str = a;
    koordinat = new T [a];
   
  }
  
}

template<class T>
inline TVector<T>::TVector(const TVector<T>& p)
{
  str = p.str;
  koordinat = new T [p.str];
  for (int i = 0; i < p.str; i++)
  {
    koordinat[i] = p.koordinat[i];
  }

}

template<class T>
inline TVector<T>::~TVector()
{
  if(koordinat != 0)
    delete[] koordinat;
  str = 0;
  koordinat = 0;
}

template<class T>
inline void TVector<T>::Transponir()
{
  transponir = true;
}

template<class T>
inline TVector<T> TVector<T>::operator+(const TVector<T>& p)
{
  if (str == p.str)
  {
    for (int i = 0; i < str; i++)
    {
      koordinat[i] = koordinat[i] + p.koordinat[i];
    }
  }
  else
    std::cout << "razmeri prostranstv ne sovpadayt" << std::endl;
  return (*this);
}

template<class T>
inline TVector<T> TVector<T>::operator-(const TVector<T>& p)
{
  if (str == p.str)
  {
    for (int i = 0; i < str; i++)
    {
      koordinat[i] = koordinat[i] - p.koordinat[i];
    }
  }
  else 
    std::cout << "razmeri prostranstv ne sovpadayt" << std::endl;
  return (*this);
}

template<class T>
inline TVector<T> TVector<T>::operator=(const TVector<T>& p)
{
  str = p.str;
  delete[] koordinat;
  koordinat = new T[str];
  for (int i = 0; i < str; i++)
  {
    koordinat[i] = p.koordinat[i];
  }
  return (*this);
}

template<class T>
inline TVector<T> TVector<T>::operator*(const TVector<T>& p)
{

  if (str == p.str)
  {
    for (int i = 0; i < str; i++)
    {
      koordinat[i] = koordinat[i] * p.koordinat[i];
    }
  }
  else
    std::cout << "razmeri prostranstv ne sovpadayt" << std::endl;
  return (*this);
}

template<class T>
inline TVector<T> TVector<T>::operator/(const TVector<T>& p)
{
  if (str == p.str)
  {
    for (int i = 0; i < str; i++)
    {
      koordinat[i] = koordinat[i] / p.koordinat[i];
    } 
    
  }
  else 
  {
    std::cout << "razmeri prostranstv ne sovpadayt" << std::endl;
  }
  return (*this);
 
}

template<class T>
inline bool TVector<T>::operator==(const TVector<T>& p)
{
  bool f = 1;
  if (str == p.str)
  {
    for (int i = 0; i < str; i++)
      if (koordinat[i] != p.koordinat[i])
        f = 0;
  }
  else
    f = 0;
  return f;
}

template<class T>
inline T& TVector<T>::operator[](int a)
{
  if (a < str)
  {
    return koordinat[a];
  }
  else
    std::cout << "razmer prostranstva < zaprashivaemogo" << std::endl;
}






template<class T>
std::ostream& operator<< (std::ostream& ostr_, TVector<T>& p)
{
  for (int i = 0; i < p.GetRazmer(); i++)
  {
    ostr_ << p[i] << "\t";
  }
  return ostr_;
}


template<class T>
 std::istream& operator >> (std::istream& istr_, TVector<T>& p)
{
  std::cout << "vvedite razmer prostranstva:  " ;
  int b = 0;
  std::cin >> b;
  p.SetRazmer(b);
  std::cout << "vvodite koordinata vectora"<< std::endl;
  for (int i = 0; i < p.GetRazmer(); i++)
  {
    T a;
    std::cin >> a;
    p[i] = a;

  }
  return istr_;

}



