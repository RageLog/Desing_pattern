#include "Factory_method/Factory_method.hpp"

#include <iostream>
Object::Object()
{
}
Object::~Object()
{
}
std::unique_ptr<Object> Object::create(const m_type& t)
{
  switch (t)
  {
    case m_type::m_Class1:
      return std::make_unique<Class_1>();
    case m_type::m_Class2:
      return std::make_unique<Class_2>();
    default:
      return nullptr;
  }
}

Class_1::Class_1()
{
}

void Class_1::doSomething()
{
  std::cout << "Class 1 doSomething" << '\n';
}

Class_2::Class_2()
{
}
void Class_2::doSomething()
{
  std::cout << "Class 2 doSomething" << '\n';
}
