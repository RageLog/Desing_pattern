#include "Composite/Composite.hpp"

composite::composite()
{
  static size_t id = 1;
  this->id = id++;
  std::cout << "Composite " << this->id << " is created." << '\n';
}
composite::~composite()
{
}

void composite::doSomeThing(void)
{
  std::cout << "My ID is " << this->id << ". And I'm doing something" << '\n';
  for (auto&& i : this->children)
  {
    i->doSomeThing();
  }
}
void composite::add(component& cmpnnt)
{
  this->children.push_back(&cmpnnt);
  cmpnnt.setParent(std::make_shared<component>(*this));
}

void composite::remove(component& cmpnnt)
{
  this->children.remove(&cmpnnt);
  cmpnnt.setParent(std::move(nullptr));
}
composite* composite::begin()
{
  return this;
}
composite* composite::end()
{
  return this + 1;
}
/**
 * ! This is Vishal Chovatiya crtp implemantation
composite* composite::begin()
{
    return this;
}
composite* composite::end()
{
    return this+1;
}

groupOfComponent::groupOfComponent(size_t count)
{
    while (count-- > 0)
    {
        emplace_back(composite{});
    }
}
composite::composite()
{
    static size_t id =1;
    this->id = id++;
    std::cout << this->id << ". component created! " << '\n';
}
*/