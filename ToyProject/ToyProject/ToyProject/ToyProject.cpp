// ToyProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
using namespace std;


class MyClass
{
public:
  int data = 0;
  
  void IncrementData() 
  {
    data++;
  }
};

int main()
{
  MyClass* ptr = new MyClass();
  ptr->IncrementData();

  //  We must do delete(ptr) to avoid memory leak 
  delete ptr;

  unique_ptr<MyClass> smartPtr = make_unique<MyClass>();
  smartPtr->IncrementData();

  // No need to delete smartPtr

  return 0;
}

[ capture ] (parameters) -> return type
{
  // logic goes here
}

