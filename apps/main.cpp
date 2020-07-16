// Includes
#include <iostream>
#include <thread>
#if defined(PROJECT_VERSION_DEFINITIONED)
#include "ver.h"
#endif  // PROJECT_VERSION_DEFINITIONED
#include "Abstract_Factory/Abstract_Factory.hpp"
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
  auto obj = Object::create(m_type::m_Class2);
  obj->doSomething();
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
  Director m_dir;
  auto m_product =
      m_dir.setBuilder(std::make_shared<concreteBuilder_1>()).fullFeaturedProduct().build();
  std::cout << "it is work :)" << m_product->doSomeThingWithPart() << '\n';
  factoryPrototype fP;
  auto p1 = fP.createCloneOf(typeOfPrototype::prototype_1);
  auto p2 = fP.createCloneOf(typeOfPrototype::prototype_2);

  return EXIT_SUCCESS;
}
