#include "Singleton/Singleton.hpp"

#include <iostream>

std::atomic<Singleton*> Singleton::m_instance;
std::mutex Singleton::m_mutex;

Singleton* Singleton::getInstance()
{
  Singleton* instance = m_instance.load(std::memory_order_acquire);
  if (!instance)
  {
    std::lock_guard<std::mutex> m_Lock(m_mutex);
    instance = m_instance.load(std::memory_order_relaxed);
    if (!instance)
    {
      instance = new Singleton();
      m_instance.store(instance, std::memory_order_release);
    }
  }
  return instance;
}

void Singleton::setValue(int& _val)
{
  std::lock_guard<std::mutex> m_Lock(m_mutex);
  this->val = _val;
}
const int& Singleton::getValue()
{
  std::lock_guard<std::mutex> m_Lock(m_mutex);
  return this->val;
}
