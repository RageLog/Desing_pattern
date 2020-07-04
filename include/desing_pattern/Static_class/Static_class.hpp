
#pragma once
#include <atomic>
#include <memory>
#include <mutex>

class Static_class
{
 private:
  /* data */
 public:
  Static_class(/* args */) = delete;
  ~Static_class() = delete;
  static void doStuff();
};
