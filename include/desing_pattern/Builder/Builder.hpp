#pragma once

#include <memory>

class productPart_1  // whele
{
 private:
  int any_member;  // for example size of whele
 public:
  productPart_1();
  ~productPart_1();
  void setAnyMember(const int& value);
  int getAnyMember() const;
};

class productPart_2  // shape
{
 private:
  int any_member;

 public:
  productPart_2();
  ~productPart_2();
  void setAnyMember(const int& value);
  int getAnyMember() const;
};

class productPart_3  // color
{
 private:
  int any_member;

 public:
  productPart_3();
  ~productPart_3();
  void setAnyMember(const int& value);
  int getAnyMember() const;
};

class productPart_4  // modal
{
 private:
  int any_member;

 public:
  productPart_4();
  ~productPart_4();
  void setAnyMember(const int& value);
  int getAnyMember() const;
};

class Product;

class absBuilder
{
 private:
 public:
  absBuilder();
  virtual ~absBuilder() = 0;
  virtual absBuilder& producePart_1() = 0;
  virtual absBuilder& producePart_2() = 0;
  virtual absBuilder& producePart_3() = 0;
  virtual absBuilder& producePart_4() = 0;
  virtual std::shared_ptr<Product> build() const = 0;
};

class Product  // car-build-desk-udp socket
{
 private:
  friend class concreteBuilder_1;
  std::unique_ptr<productPart_1> part_1 = std::make_unique<productPart_1>();
  std::unique_ptr<productPart_2> part_2 = std::make_unique<productPart_2>();
  std::unique_ptr<productPart_3> part_3 = std::make_unique<productPart_3>();
  std::unique_ptr<productPart_4> part_4 = std::make_unique<productPart_4>();

 public:
  Product();
  ~Product();
  int doSomeThingWithPart();
};

class concreteBuilder_1 : public absBuilder  // jeepBuilder for car
{
 private:
  std::shared_ptr<Product> m_product;

 public:
  concreteBuilder_1();
  ~concreteBuilder_1();
  absBuilder& producePart_1() override;
  absBuilder& producePart_2() override;
  absBuilder& producePart_3() override;
  absBuilder& producePart_4() override;
  std::shared_ptr<Product> build() const override;
};

class Director
{
 private:
  std::shared_ptr<absBuilder> m_builder;

 public:
  Director& setBuilder(const std::shared_ptr<absBuilder>& builder);
  Director& setBuilder(std::unique_ptr<absBuilder>&& builder);
  Director& fullFeaturedProduct();
  Director& minFeaturedProduct();
  std::shared_ptr<Product> build();
  std::shared_ptr<absBuilder> getBuilder() const;
  Director();
  ~Director();
};
