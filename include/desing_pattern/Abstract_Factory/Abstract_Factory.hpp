#pragma once
#include <cstddef>
#include <memory>
#include <type_traits>

class AbsProduct_1  // model
{
 private:
 public:
  AbsProduct_1();
  virtual ~AbsProduct_1() = 0;
  virtual void doSomeThing() = 0;
};

class AbsProduct_2  // color
{
 private:
 public:
  AbsProduct_2();
  virtual ~AbsProduct_2() = 0;
  virtual void doSomeThing() = 0;
};

class conProduct_1_1 : public AbsProduct_1  // square
{
 private:
 public:
  conProduct_1_1();
  ~conProduct_1_1();
  void doSomeThing() override;
};

class conProduct_1_2 : public AbsProduct_1  // circle
{
 private:
 public:
  conProduct_1_2();
  void doSomeThing() override;
  ~conProduct_1_2();
};

class conProduct_2_1 : public AbsProduct_2  // red
{
 private:
 public:
  conProduct_2_1();
  void doSomeThing() override;
  ~conProduct_2_1();
};

class conProduct_2_2 : public AbsProduct_2  // blue
{
 private:
 public:
  conProduct_2_2();
  void doSomeThing() override;
  ~conProduct_2_2();
};

class absFactory  // clothing factory (main factory)
{
 private:
 public:
  enum class typeOfFactories : std::underlying_type_t<std::byte>  // clothingFactories
  {
    Factory_1 = 0x00,  // clothes factory
    Factory_2 = 0x01   // shoues  factory
  };
  absFactory();
  static std::shared_ptr<absFactory> createFactory(const typeOfFactories& t);
  virtual std::shared_ptr<AbsProduct_1> getAbsProduct_1() = 0;
  virtual std::shared_ptr<AbsProduct_2> getAbsProduct_2() = 0;
  virtual ~absFactory() = 0;
};

class conFactory_1 : public absFactory  // cloth
{
 private:
 public:
  std::shared_ptr<AbsProduct_1> getAbsProduct_1() override;
  std::shared_ptr<AbsProduct_2> getAbsProduct_2() override;
  conFactory_1();
  ~conFactory_1();
};

class conFactory_2 : public absFactory  // shou
{
 private:
 public:
  std::shared_ptr<AbsProduct_1> getAbsProduct_1() override;
  std::shared_ptr<AbsProduct_2> getAbsProduct_2() override;
  conFactory_2();
  ~conFactory_2();
};
