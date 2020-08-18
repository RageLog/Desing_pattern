#pragma once
#include <iostream>
#include <type_traits>
#include <utility>

class absComponent
{
 private:
 public:
  absComponent();
  virtual ~absComponent() = 0;
  virtual void doSomething() const = 0;
};

class concreteComponent_1 : public absComponent
{
 private:
 public:
  concreteComponent_1();
  ~concreteComponent_1();
  void doSomething() const override;
  void componentSpecificMethod();
};

class concreteComponent_2 : public absComponent
{
 private:
 public:
  concreteComponent_2();
  ~concreteComponent_2();
  void doSomething() const override;
  void componentSpecificMethod();
};

class absDecorator : public absComponent
{
 private:
 protected:
  const absComponent& m_comp;

 public:
  absDecorator(absComponent& cmp);
  virtual void genaralEnhancedFunc() const = 0;
  virtual ~absDecorator();
};

namespace dynmc
{
class concreteDecorator : public absDecorator
{
 private:
 public:
  concreteDecorator(absComponent& cmp);
  ~concreteDecorator();
  void doSomething() const override;
  void genaralEnhancedFunc() const override;
  void enhancedFunc() const;
};
}  // namespace dynmc

// ! thanks to Vishal Chovatiya for that
// ! I learned this approach from his blog
namespace sttc
{
template <class T>
class concreteDecorator : public T
{
 private:
 public:
  static_assert(std::is_base_of_v<absComponent, T>, "T have to based on absComponent");

  template <typename... ARGS>
  concreteDecorator(ARGS&&... arg);

  ~concreteDecorator();
  void doSomething() const override;
  void enhancedFunc() const;
};
template <class T>
template <typename... ARGS>
concreteDecorator<T>::concreteDecorator(ARGS&&... arg) : T(std::forward<ARGS>(arg)...)
{
}

template <class T>
concreteDecorator<T>::~concreteDecorator()
{
}

template <class T>
void concreteDecorator<T>::doSomething() const
{
  T::doSomething();
  std::cout << "and decorated with sttc decorator " << '\n';
}

template <class T>
void concreteDecorator<T>::enhancedFunc() const
{
  std::cout << "[sttc]doing enhancedFunc " << '\n';
}

}  // namespace sttc
