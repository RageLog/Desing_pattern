// Includes
#include <iostream>
#include <thread>
#if defined(PROJECT_VERSION_DEFINITIONED)
#include "ver.h"
#endif  // PROJECT_VERSION_DEFINITIONED
#include "Abstract_Factory/Abstract_Factory.hpp"
#include "Adapter/Adapter.hpp"
#include "Builder/Builder.hpp"
#include "Factory_method/Factory_method.hpp"
#include "Prototype/Prototype.hpp"
#include "Singleton/Singleton.hpp"
#include "Static_class/Static_class.hpp"

int main(/*int argc, char *argv[]*/)
{
#if defined(PROJECT_VERSION_DEFINITIONED)
  std::cout << "Project version is :" << ver << '\n';
#endif  // PROJECT_VERSION_DEFINITIONED
  ///////////////////////////////////////////////////////////////////////////////////////////////////////
  // ! creational design patterns
  ///////////////////////////////////////////////////////////////////////////////////////////////////////
  // ? factory method
  auto obj = Object::create(m_type::m_Class2);
  obj->doSomething();

  // ? abstarct factory
  absFactory::createFactory(absFactory::typeOfFactories::Factory_1)
      ->getAbsProduct_1()
      ->doSomeThing();
  absFactory::createFactory(absFactory::typeOfFactories::Factory_1)
      ->getAbsProduct_2()
      ->doSomeThing();
  absFactory::createFactory(absFactory::typeOfFactories::Factory_2)
      ->getAbsProduct_1()
      ->doSomeThing();
  absFactory::createFactory(absFactory::typeOfFactories::Factory_2)
      ->getAbsProduct_2()
      ->doSomeThing();

  // ? builder
  Director m_dir;
  auto m_product =
      m_dir.setBuilder(std::make_shared<concreteBuilder_1>()).fullFeaturedProduct().build();
  std::cout << "it is work :)" << m_product->doSomeThingWithPart() << '\n';

  // ? prototype method
  factoryPrototype fP;
  auto p1 = fP.createCloneOf(typeOfPrototype::prototype_1);
  auto p2 = fP.createCloneOf(typeOfPrototype::prototype_2);

  // ? singleton
  Singleton::getInstance()->setValue(10);
  std::cout << "singleton value" << Singleton::getInstance()->getValue() << '\n';
  ///////////////////////////////////////////////////////////////////////////////////////////////////////
  // ! structural design pattern
  ///////////////////////////////////////////////////////////////////////////////////////////////////////
  // ? adapter
  auto adapt_1 = adapter::adapter(std::make_shared<adapter::newIncompatibleClass>());
  auto adaptClient_1 = adapter::clientClass(adapt_1);
  auto adapt_2 = adapter::adapter(std::make_shared<adapter::oldClass>());
  auto adaptClient_2 = adapter::clientClass(adapt_2);

  return EXIT_SUCCESS;
}
