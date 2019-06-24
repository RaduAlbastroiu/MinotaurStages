// PublicProtectedPrivate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class A
{
public:

  void PrintFromA()
  {
    std::cout << Pub << "\n";
    std::cout << Prot << "\n";
    std::cout << Prv << "\n";
  };

  int Pub = 0;

protected:
  int Prot = 1;

private:
  int Prv = 2;
};

class B : public A
{
public:
  
  void PrintFromB()
  {
    std::cout << Pub << "\n";
    // std::cout << Prot << "\n";
    // std::cout << Prv << "\n";
  };
};

int main()
{
  A a = A();
  B b = B();

  a.PrintFromA();
  b.PrintFromA();
  b.PrintFromB();

  // std::cout << b.Pub << "\n";
  // std::cout << b.Prot << "\n";
  // std::cout << b.Prv << "\n";
}
