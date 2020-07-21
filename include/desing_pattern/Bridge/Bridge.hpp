#pragma once
#include <memory>
class impInterface
{
private:
public:
  virtual void someFunctionality() const = 0;
  impInterface();
  virtual ~impInterface() = 0;
};
// ! implemantation of each diffirent background 

// * This could be linux functionality or vulkan api functionality
class concrateImpl_1 : public impInterface
{
private:
public:
  concrateImpl_1();
  ~concrateImpl_1();
  void someFunctionality() const override;

};

// * This could be windows functionality or dx12 api functionality
class concrateImpl_2 : public impInterface
{
private:
public:
  concrateImpl_2();
  ~concrateImpl_2();
  void someFunctionality() const override;

};

// * abstraction of bridge abstraction part
class absInterface
{
private:
public:
  absInterface();
  virtual ~absInterface() = 0;
  virtual void abstructSomeFunctionality() const = 0;
};
// * abstraction part
// * In my opinion, prefer pimpl version but 
// * For more information about pimpl look at this link ->
// * http://www.vishalchovatiya.com/bridge-design-pattern-in-modern-cpp/
// ? This could be shape scriber class and you want to draw with diffirent API
class bridge : public absInterface
{
private:
protected:
/**
 * @param implementation and @param m_impl is
 * ? pointer to implementation (pimpl) structures.
 * ? This provide to you more abstraction for your library
 * ! If you want, you can impllementation into .h* file but
 * ! If you do that, you lose to opportunity of more abstruction and secure. 
 * ! However, If you do that,you will have flexibility of extendable implementation.
 * * I'm going to implement the bridge with clasic method.
 */
  // class implementation;  std::unique_ptr<implementation> m_impl;

  // * Classic method
  impInterface& m_impl;
public:
  bridge(impInterface& implementation);
  ~bridge();
  virtual void abstructSomeFunctionality() const override; // TODO default implementation if this is necessary do from here
                                                           // * This could be draw method or something else
};


// ! Bridge abstraction extantion
// * For exemple, if bridge is shape class, use case could be triangle

class useCase_1 : public bridge
{
private:
public:
  useCase_1(impInterface& implementation);
  ~useCase_1();
  void abstructSomeFunctionality() const override;
};

// * For exemple, if bridge is shape class, use case could be square
class useCase_2 : public bridge
{
private:
public:
  useCase_2(impInterface& implementation);
  ~useCase_2();
  void abstructSomeFunctionality() const override;
};








