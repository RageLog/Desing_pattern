// Includes
#include <functional>
#include <future>
#include <iostream>
#include <thread>
#if defined(PROJECT_VERSION_DEFINITIONED)
#include "ver.h"
#endif  // PROJECT_VERSION_DEFINITIONED
#include "YOUR_LIBRARY_1_NAME/lib1_1.hpp"
#include "YOUR_LIBRARY_1_NAME/lib1_2.hpp"
#include "YOUR_LIBRARY_2_NAME/lib2.hpp"

int main(/*int argc, char *argv[]*/)
{
#if defined(PROJECT_VERSION_DEFINITIONED)
  std::cout << "Project version is :" << ver << '\n';
#endif  // PROJECT_VERSION_DEFINITIONED

  std::thread t([]() {
    lib1_1 l_1;
    lib2  l_2;
  });
 
  if (t.joinable())
  {
    t.join();
  }
}
