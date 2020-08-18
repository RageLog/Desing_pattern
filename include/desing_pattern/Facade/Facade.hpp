#pragma once
#include <iostream>

class system_1
{
private:
  
public:
  system_1();
  ~system_1();
  void doComplexSomeThing() const;
};

class system_2
{
private:
  
public:
  system_2();
  ~system_2();
  void doComplexSomeThing() const;
};

class overAllSystemFacade
{
private:
protected:
  system_1 s_1;
  system_2 s_2;
public:
  void doHighLevelSomeThing() const;
  overAllSystemFacade();
  ~overAllSystemFacade();
};




