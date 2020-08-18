#include "Bridge/Bridge.hpp"

#include <iostream>
/*class abstructionInterface::implementation : public imlemantationInterface
{
private:
public:
  implementation()
  {

  }
  ~implementation()
  {

  }
};
*/

impInterface::impInterface()
{
}
impInterface::~impInterface()
{
}

concrateImpl_1::concrateImpl_1()
{
}
concrateImpl_1::~concrateImpl_1()
{
}
void concrateImpl_1::someFunctionality() const
{
  std::cout << "concrateImpl_1" << '\n';
}

concrateImpl_2::concrateImpl_2()
{
}
concrateImpl_2::~concrateImpl_2()
{
}
void concrateImpl_2::someFunctionality() const
{
  std::cout << "concrateImpl_2" << '\n';
}

absInterface::absInterface()
{
}
absInterface::~absInterface()
{
}

bridge::bridge(impInterface& implementation)  //:m_impl(std::make_unique<implementation>())
    : m_impl(implementation)
{
}
bridge::~bridge()
{
}
void bridge::abstructSomeFunctionality() const
{
}

useCase_1::useCase_1(impInterface& implementation) : bridge(implementation)
{
}
useCase_1::~useCase_1()
{
}

void useCase_1::abstructSomeFunctionality() const
{
  std::cout << "useCase_1 fullfilled with ";
  m_impl.someFunctionality();
}

useCase_2::useCase_2(impInterface& implementation) : bridge(implementation)
{
}
useCase_2::~useCase_2()
{
}

void useCase_2::abstructSomeFunctionality() const
{
  std::cout << "useCase_2 fullfilled with ";
  m_impl.someFunctionality();
}