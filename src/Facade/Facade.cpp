#include "Facade/Facade.hpp"

system_1::system_1()
{
}
system_1::~system_1()
{
}
void system_1::doComplexSomeThing() const
{
  std::cout << "system_1 doing something" << '\n';
}

system_2::system_2()
{
}
system_2::~system_2()
{
}
void system_2::doComplexSomeThing() const
{
  std::cout << "system_2 doing something" << '\n';
}

overAllSystemFacade::overAllSystemFacade()
{
}
overAllSystemFacade::~overAllSystemFacade()
{
}

void overAllSystemFacade::doHighLevelSomeThing() const
{
  this->s_1.doComplexSomeThing();
  this->s_2.doComplexSomeThing();
  std::cout << "system_1 and system_2 doing some high level thing" << '\n';
}