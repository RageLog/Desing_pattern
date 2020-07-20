#pragma once
//#include <functional>
#include <functional>
#include <memory>

namespace adapter
{
// ! target interface
class oldInterface
{
 private:
 public:
  oldInterface();
  virtual ~oldInterface() = 0;
  virtual void doSomething() const = 0;
};
// ! legacy class
class oldClass : public oldInterface
{
 private:
 public:
  oldClass();
  ~oldClass();
  void doSomething() const override;
};

// ! your new writed class, someone say "adeptee" to that
class newIncompatibleClass
{
 private:
 public:
  newIncompatibleClass();
  ~newIncompatibleClass();
  void doSomethingBetter() const;
};

// ! your adepter class. Adapt your new code to legacy code
class adapter : public oldInterface
{
 private:
  std::function<void()> m_request;

 public:
  adapter(const std::shared_ptr<oldClass>& m_old);
  adapter(const std::shared_ptr<newIncompatibleClass>& m_new);

  ~adapter();
  void doSomething() const override;
};

class clientClass
{
 private:
 public:
  clientClass(const oldInterface& useOld);
  ~clientClass();
};

};  // namespace adapter
