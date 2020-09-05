#include "Proxy/Proxy.hpp"
namespace virtualProxy
{
absObject::absObject()
{
}
absObject::~absObject()
{
}

Object::Object()
{
}
Object::~Object()
{
}
void Object::doSomeThing()
{
  std::cout << "doing some thing in object\n";
}

Proxy::Proxy()
{
}
Proxy::~Proxy()
{
}
void Proxy::doSomeThing()
{
  if (!m_object)
    m_object = std::make_unique<Object>();
  doSomePrivateChecksAndLogOrOtherThings();
  m_object->doSomeThing();
  std::cout << "doing some thing in proxy\n";
}
void Proxy::doSomePrivateChecksAndLogOrOtherThings() const
{
  std::cout << "doing some private checks and log or other things\n";
}
}  // namespace virtualProxy
