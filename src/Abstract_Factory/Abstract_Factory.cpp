#include "Abstract_Factory/Abstract_Factory.hpp"

#include <iostream>
AbsProduct_1::AbsProduct_1()
{
}
AbsProduct_1::~AbsProduct_1()
{
}

AbsProduct_2::AbsProduct_2()
{
}
AbsProduct_2::~AbsProduct_2()
{
}

conProduct_1_1::conProduct_1_1()
{
}
conProduct_1_1::~conProduct_1_1()
{
}

conProduct_1_2::conProduct_1_2()
{
}
conProduct_1_2::~conProduct_1_2()
{
}

conProduct_2_1::conProduct_2_1()
{
}
conProduct_2_1::~conProduct_2_1()
{
}

conProduct_2_2::conProduct_2_2()
{
}
conProduct_2_2::~conProduct_2_2()
{
}

absFactory::absFactory()
{
}
absFactory::~absFactory()
{
}

conFactory_1::conFactory_1()
{
}
conFactory_1::~conFactory_1()
{
}

conFactory_2::conFactory_2()
{
}
conFactory_2::~conFactory_2()
{
}

void conProduct_1_1::doSomeThing()
{
  std::cout << "I'm product 1 - 1" << '\n';
}

void conProduct_1_2::doSomeThing()
{
  std::cout << "I'm product 1 - 2" << '\n';
}

void conProduct_2_1::doSomeThing()
{
  std::cout << "I'm product 2 - 1" << '\n';
}

void conProduct_2_2::doSomeThing()
{
  std::cout << "I'm product 2 - 2" << '\n';
}

std::unique_ptr<absFactory> absFactory::createFactory(const typeOfFactories& t)
{
  switch (t)
  {
    case typeOfFactories::Factory_1:
      return std::make_unique<conFactory_1>();
    case typeOfFactories::Factory_2:
      return std::make_unique<conFactory_2>();
    default:
      return nullptr;
  }
}

std::unique_ptr<AbsProduct_1> conFactory_1::getAbsProduct_1()
{
  return std::make_unique<conProduct_1_1>();
}

std::unique_ptr<AbsProduct_2> conFactory_1::getAbsProduct_2()
{
  return std::make_unique<conProduct_2_1>();
}

std::unique_ptr<AbsProduct_1> conFactory_2::getAbsProduct_1()
{
  return std::make_unique<conProduct_1_2>();
}

std::unique_ptr<AbsProduct_2> conFactory_2::getAbsProduct_2()
{
  return std::make_unique<conProduct_2_2>();
}
