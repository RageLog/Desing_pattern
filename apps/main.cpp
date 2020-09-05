// Includes
#include <iostream>
#include <thread>
#if defined(PROJECT_VERSION_DEFINITIONED)
#include "ver.h"
#endif  // PROJECT_VERSION_DEFINITIONED
#include "Abstract_Factory/Abstract_Factory.hpp"
#include "Adapter/Adapter.hpp"
#include "Bridge/Bridge.hpp"
#include "Builder/Builder.hpp"
#include "Composite/Composite.hpp"
#include "Decorator/Decorator.hpp"
#include "Facade/Facade.hpp"
#include "Factory_method/Factory_method.hpp"
#include "Flyweight/Flyweight.hpp"
#include "Prototype/Prototype.hpp"
#include "Proxy/Proxy.hpp"
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
  std::cout << "creational design patterns:"
            << "\n\n\n";

  // ? factory method
  std::cout << '\n'
            << "factory method:"
            << "\n\n";

  auto obj = Object::create(m_type::m_Class2);
  obj->doSomething();

  // ? abstarct factory
  std::cout << '\n'
            << "abstarct method:"
            << "\n\n";

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
  std::cout << '\n'
            << "builder:"
            << "\n\n";

  Director m_dir;
  auto m_product =
      m_dir.setBuilder(std::make_shared<concreteBuilder_1>()).fullFeaturedProduct().build();
  std::cout << "it is work :)" << m_product->doSomeThingWithPart() << '\n';

  // ? prototype
  std::cout << '\n'
            << "prototype:"
            << "\n\n";

  factoryPrototype fP;
  auto p1 = fP.createCloneOf(typeOfPrototype::prototype_1);
  auto p2 = fP.createCloneOf(typeOfPrototype::prototype_2);

  // ? singleton
  std::cout << '\n'
            << "singleton:"
            << "\n\n";

  Singleton::getInstance()->setValue(10);
  std::cout << "singleton value" << Singleton::getInstance()->getValue() << '\n';
  ///////////////////////////////////////////////////////////////////////////////////////////////////////
  // ! structural design pattern
  ///////////////////////////////////////////////////////////////////////////////////////////////////////
  std::cout << "structural design pattern:"
            << "\n\n\n";

  // ? adapter
  std::cout << '\n'
            << "adapter:"
            << "\n\n";

  auto adapt_1 = adapter::adapter(std::make_shared<adapter::newIncompatibleClass>());
  auto adaptClient_1 = adapter::clientClass(adapt_1);
  auto adapt_2 = adapter::adapter(std::make_shared<adapter::oldClass>());
  auto adaptClient_2 = adapter::clientClass(adapt_2);

  // ? bridge
  std::cout << '\n'
            << "bridge:"
            << "\n\n";

  auto m_impl_1 = concrateImpl_1();
  auto m_impl_2 = concrateImpl_2();

  auto m_useCase_1_1 = useCase_1(m_impl_1);
  m_useCase_1_1.abstructSomeFunctionality();
  auto m_useCase_1_2 = useCase_1(m_impl_2);
  m_useCase_1_2.abstructSomeFunctionality();

  auto m_useCase_2_1 = useCase_2(m_impl_1);
  m_useCase_2_1.abstructSomeFunctionality();
  auto m_useCase_2_2 = useCase_2(m_impl_2);
  m_useCase_2_2.abstructSomeFunctionality();

  // ? composite
  std::cout << '\n'
            << "composite:"
            << "\n\n";

  composite c1;
  composite c2;
  c1.add(c2);
  c1.doSomeThing();
  /**
   * * don't do this
   * * this cause to infinite loop
  c2.add(c1);
  c2.doSomeThing();
  */

  /**
   * ! This is Vishal Chovatiya crtp implemantation
  composite c1,c2;
  groupOfComponent g1(1),g2(2);
  c1.connect_to(g1);
  g2.connect_to(c2);
  g1.connect_to(g2);
  c1.connect_to(c2);

  std::cout << "c1 :" << '\n' << c1 << '\n';
  std::cout << "c2 :" << '\n' << c2 << '\n';
  std::cout << "g1 :" << '\n' << g1 << '\n';
  std::cout << "g2 :" << '\n' << g2 << '\n';
  */

  // ? decorator
  std::cout << '\n'
            << "decorator:"
            << "\n\n";

  auto m_comp_1 = concreteComponent_1();

  // * dynamic
  auto d_dec = dynmc::concreteDecorator(m_comp_1);
  d_dec.doSomething();
  d_dec.genaralEnhancedFunc();
  d_dec.enhancedFunc();
  // ! d_dec.componentSpecificMethod(); <- You cannot access this method like this. Look to the
  // static method !!
  m_comp_1.componentSpecificMethod();
  std::cout << "\n\n";
  // * static
  auto s_dec = sttc::concreteDecorator<concreteComponent_2>();
  s_dec.doSomething();
  s_dec.enhancedFunc();
  s_dec.componentSpecificMethod();

  // auto s_dec_ = sttc::concreteDecorator<int>();// this is going to give an error to you.

  // ? facade
  std::cout << '\n'
            << "facade:"
            << "\n\n";

  // * You can implament set to system object method.
  overAllSystemFacade m_Facade;
  m_Facade.doHighLevelSomeThing();

  // ? flyweight
  std::cout << '\n'
            << "flyweight:"
            << "\n\n";

  auto sharedTest = Shared_t(10, "shareddata_test");
  auto factoryOfFly = flyweightFactory({{1, "insertedSharedData_1"}, {2, "insertedSharedData_2"}});

  auto flyP_test_1 = flyProduct(factoryOfFly.getFlyweight(sharedTest), 10, "test_1");
  auto flyP_test_2 = flyProduct(factoryOfFly.getFlyweight(sharedTest), 10, "test_2");
  auto flyP_1 = flyProduct(factoryOfFly.getFlyweight({1, "insertedSharedData_1"}), 1, "flyP_1");
  auto flyP_2 = flyProduct(factoryOfFly.getFlyweight({2, "insertedSharedData_2"}), 2, "flyP_2");

  flyP_test_1.doSomeThing();
  flyP_test_2.doSomeThing();
  flyP_1.doSomeThing();
  flyP_2.doSomeThing();

  // ? Proxy
  std::cout << '\n'
            << "Proxy:"
            << "\n\n";

  std::cout << "Virtual proxy" << '\n';
  auto m_prx = virtualProxy::Proxy();
  m_prx.doSomeThing();
  std::cout << "Property proxy" << '\n';
  auto m_porpertiesPrx = propertyProxy::someObject();
  std::cout << "property proxy object value 1 is " << m_porpertiesPrx.value_1 << '\n';
  std::cout << "property proxy object value 2 is " << m_porpertiesPrx.value_2 << '\n';
  m_porpertiesPrx.value_1 = 10;
  m_porpertiesPrx.value_2 = 20;
  std::cout << "property proxy object value 1 is " << m_porpertiesPrx.value_1 << '\n';
  std::cout << "property proxy object value 2 is " << m_porpertiesPrx.value_2 << '\n';
  return EXIT_SUCCESS;
}
