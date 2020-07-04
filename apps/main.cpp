// Includes
#include <iostream>
#include <thread>
#if defined(PROJECT_VERSION_DEFINITIONED)
#include "ver.h"
#endif  // PROJECT_VERSION_DEFINITIONED
#include "Singleton/Singleton.hpp"
#include "Static_class/Static_class.hpp"
int main(/*int argc, char *argv[]*/)
{
#if defined(PROJECT_VERSION_DEFINITIONED)
  std::cout << "Project version is :" << ver << '\n';
#endif  // PROJECT_VERSION_DEFINITIONED
  std::thread t1([&]() {
    for (int i = 0; i < 10; i++)
    {
      Singleton::getInstance()->setValue(i);
      std::cout << Singleton::getInstance()->getValue() << '\n';
    }
  });
  for (int i = 10; i < 20; i++)
  {
    Singleton::getInstance()->setValue(i);
    std::cout << Singleton::getInstance()->getValue() << '\n';
  }

  Static_class::doStuff();
  if (t1.joinable())
  {
    t1.join();
  }
}
