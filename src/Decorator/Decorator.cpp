#include "Decorator/Decorator.hpp"

absComponent::absComponent()
{
}
absComponent::~absComponent()
{
}

concreteComponent_1::concreteComponent_1()
{
}
concreteComponent_1::~concreteComponent_1()
{
}
void concreteComponent_1::doSomething() const
{
  std::cout << "concreteComponent_1 doing something " << '\n';
}

void concreteComponent_1::componentSpecificMethod()
{
  std::cout << "componentSpecificMethod called" << '\n';
}

concreteComponent_2::concreteComponent_2()
{
}
concreteComponent_2::~concreteComponent_2()
{
}
void concreteComponent_2::doSomething() const
{
  std::cout << "concreteComponent_2 doing something " << '\n';
}
void concreteComponent_2::componentSpecificMethod()
{
  std::cout << "componentSpecificMethod called" << '\n';
}

absDecorator::absDecorator(absComponent& cmp) : m_comp(cmp)
{
}
absDecorator::~absDecorator()
{
}

namespace dynmc
{
concreteDecorator::concreteDecorator(absComponent& cmp) : absDecorator(cmp)
{
}
concreteDecorator::~concreteDecorator()
{
}

void concreteDecorator::doSomething() const
{
  this->m_comp.doSomething();
  std::cout << "and decorated with dynmc decorator " << '\n';
}

void concreteDecorator::genaralEnhancedFunc() const
{
  std::cout << "[dynmc]doing genaralEnhancedFunc " << '\n';
}

void concreteDecorator::enhancedFunc() const
{
  std::cout << "[dynmc]doing enhancedFunc " << '\n';
}
}  // namespace dynmc
