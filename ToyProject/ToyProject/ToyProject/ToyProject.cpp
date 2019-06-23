// ToyProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Animal 
{
public:
  void eat() { std::cout << "  eating  \n"; }
};

class Dog : public Animal 
{
public:
  void bark() { std::cout << "  barking  \n"; }
};

int main()
{
  auto dog = Dog();

  dog.eat();
  dog.bark();
}
