#include "Builder/Builder.hpp"

Product::Product()
{
}

Product::~Product()
{
}

int Product::doSomeThingWithPart()
{
  return (part_1->getAnyMember() + part_2->getAnyMember() + part_3->getAnyMember() +
          part_4->getAnyMember());
}
productPart_1::productPart_1()
{
}
productPart_1::~productPart_1()
{
}
void productPart_1::setAnyMember(const int& value)
{
  this->any_member = value;
}
int productPart_1::getAnyMember() const
{
  return this->any_member;
}

productPart_2::productPart_2()
{
}
productPart_2::~productPart_2()
{
}
void productPart_2::setAnyMember(const int& value)
{
  this->any_member = value;
}
int productPart_2::getAnyMember() const
{
  return this->any_member;
}

productPart_3::productPart_3()
{
}
productPart_3::~productPart_3()
{
}
void productPart_3::setAnyMember(const int& value)
{
  this->any_member = value;
}
int productPart_3::getAnyMember() const
{
  return this->any_member;
}

productPart_4::productPart_4()
{
}
productPart_4::~productPart_4()
{
}
void productPart_4::setAnyMember(const int& value)
{
  this->any_member = value;
}
int productPart_4::getAnyMember() const
{
  return this->any_member;
}

absBuilder::absBuilder()
{
}
absBuilder::~absBuilder()
{
}

concreteBuilder_1::concreteBuilder_1() : m_product(std::make_unique<Product>())
{
}
concreteBuilder_1::~concreteBuilder_1()
{
}
absBuilder& concreteBuilder_1::producePart_1()
{
  this->m_product->part_1->setAnyMember(10);
  return *this;
}
absBuilder& concreteBuilder_1::producePart_2()
{
  this->m_product->part_2->setAnyMember(20);
  return *this;
}
absBuilder& concreteBuilder_1::producePart_3()
{
  this->m_product->part_3->setAnyMember(30);
  return *this;
}
absBuilder& concreteBuilder_1::producePart_4()
{
  this->m_product->part_4->setAnyMember(40);
  return *this;
}

std::shared_ptr<Product> concreteBuilder_1::build() const
{
  return this->m_product;
}

Director::Director()
{
}
Director::~Director()
{
}
Director& Director::setBuilder(const std::shared_ptr<absBuilder>& builder)
{
  this->m_builder = builder;
  return *this;
}

Director& Director::setBuilder(std::unique_ptr<absBuilder>&& builder)
{
  this->m_builder = std::move(builder);
  return *this;
}
Director& Director::fullFeaturedProduct()
{
  this->m_builder->producePart_1().producePart_2().producePart_3().producePart_4();
  return *this;
}
Director& Director::minFeaturedProduct()
{
  this->m_builder->producePart_1();
  return *this;
}

std::shared_ptr<Product> Director::build()
{
  return this->m_builder->build();
}

std::shared_ptr<absBuilder> Director::getBuilder() const
{
  return this->m_builder;
}
