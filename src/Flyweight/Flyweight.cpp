#include "Flyweight/Flyweight.hpp"

Flyweight::Flyweight(const Shared_t& key) : m_key(std::make_shared<Shared_t>(key))
{
}
Flyweight::~Flyweight()
{
}
void Flyweight::doSomeThing() const
{
  std::cout << "Flyweight doing SomeThing\n";
  std::cout << "and its member is:\n";
  std::cout << m_key->intData << " (int member) "
            << " and " << m_key->strData << " (string member) \n";
}

flyweightFactory::flyweightFactory(std::initializer_list<Shared_t> keys)
{
  for (auto&& i : keys)
  {
    this->m_Flyweights[i.id] = std::make_shared<Flyweight>(i);
  }
}
std::string flyweightFactory::getKey(const Shared_t& key)
{
  return key.id;
}

flyweightFactory::~flyweightFactory()
{
}
Flyweight& flyweightFactory::getFlyweight(const Shared_t& key)
{
  std::cout << "getFlyweight \n";
  if (m_Flyweights.count(key.id) != 0)
  {
    std::cout << "Key is found " << key.intData << " (int member) "
              << " and " << key.strData << " (string member) \n\n";
    return *m_Flyweights[key.id];
  }
  m_Flyweights[key.id] = std::make_shared<Flyweight>(key);
  std::cout << "New Flyweigts generated with: " << key.intData << " (int member) "
            << " and " << key.strData << " (string member) \n\n";
  return *m_Flyweights[key.id];
}

flyProduct::flyProduct(Flyweight& fly, const int& number, const std::string& name)
    : m_Fly(fly), someUniqueInt(number), someUniqueString(name)
{
}
flyProduct::~flyProduct()
{
}
void flyProduct::doSomeThing() const
{
  m_Fly.doSomeThing();
  std::cout << "flyProduct doing SomeThing\n";
  std::cout << "and its unique member is:\n";
  std::cout << someUniqueInt << " (int member) "
            << " and " << someUniqueString << " (string member) \n\n";
}