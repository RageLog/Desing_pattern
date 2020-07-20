#pragma once
#include <atomic>
#include <memory>
#include <mutex>

class Singleton
{

 private:
  Singleton() = default;
  ~Singleton() = default;
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;

  static std::atomic<Singleton*> m_instance;
  static std::mutex m_mutex;

  int val;

 protected:
 public:
  static Singleton* getInstance();

  void setValue(const int& _val);
  const int& getValue();
};
