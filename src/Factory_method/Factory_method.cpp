#include "Factory_method/Factory_method.hpp"

std::shared_ptr<Object> Object::create(m_type t)
{
  switch (t)
  {
    case m_type::m_Class1:
      return std::make_shared<Class_1>();
    case m_type::m_Class2:
      return std::make_shared<Class_2>();
    default:
      return nullptr;
  }
}
