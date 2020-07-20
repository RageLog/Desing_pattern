#include "Adapter/Adapter.hpp"

#include <iostream>

namespace adapter
{
clientClass::clientClass(const oldInterface& useOld)
{
  std::cout << "call knowed code" << '\n';
  useOld.doSomething();
}

clientClass::~clientClass()
{
}

adapter::adapter(const std::shared_ptr<oldClass>& m_old)
{
  m_request = [&m_old]() { m_old->doSomething(); };
}
adapter::adapter(const std::shared_ptr<newIncompatibleClass>& m_new)
{
  m_request = [&m_new]() { m_new->doSomethingBetter(); };
}
adapter::~adapter()
{
}

void adapter::doSomething() const
{
  m_request();
}

newIncompatibleClass::newIncompatibleClass()
{
}
newIncompatibleClass::~newIncompatibleClass()
{
}

void newIncompatibleClass::doSomethingBetter() const
{
  std::cout << "fullfiled better new code" << '\n';
}

oldClass::oldClass()
{
}
oldClass::~oldClass()
{
}

void oldClass::doSomething() const
{
  std::cout << "fullfiled old code" << '\n';
}

oldInterface::oldInterface()
{
}
oldInterface::~oldInterface()
{
}

}  // namespace adapter
