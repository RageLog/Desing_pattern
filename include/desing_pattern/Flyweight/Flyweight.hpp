#pragma once

#include <iostream>
#include <memory>
#include <unordered_map>
#include <string>

/**
 *
 * ? Shared_t type is common component of flyweght object.
 * * When you generate many same object, this is going to
 * * take up place on the memory. For example on game (this is popular example on internet),
 * * you want to generate some object such as tree of forest,bullet. This objects have
 * * some texture model and maybe audio and this mambers is same for each instance of this
 * * object. In this case, we can use flyweight pattern. Shared_t is contain this
 * * same mamber parameter. Indeed, Shared_t struct can be bulletModel  class
 * * and intData can be declare with Texture type.
 *
 **/
struct Shared_t  // ! suppose that, this is a 3d object(bullet) class for game
{
  std::string id;
  int intData;  // ! suppose that, this a texture class for bullet
  std::string strData;
  Shared_t(const int& intData, const std::string& strData) : intData(intData), strData(strData)
  {
    id = strData + std::to_string(intData);
  };
};

class Flyweight  // ! and suppose that, this can contain bullet model and its coordinate on the
                 // world.
{                // ! And this is generating each bullet model
 private:
  std::shared_ptr<Shared_t> m_key;

 public:
  Flyweight(const Shared_t& key);
  void doSomeThing() const;
  ~Flyweight();
};

/**
 *
 * This is manager for flyweight object.
 * If you generate first time shared_t
 * Factory
 *
 **/
class flyweightFactory
{
 public:
 private:
  std::unordered_map<std::string, std::shared_ptr<Flyweight>> m_Flyweights;
  std::string getKey(const Shared_t&);

 public:
  flyweightFactory(std::initializer_list<Shared_t> keys);
  ~flyweightFactory();
  Flyweight& getFlyweight(const Shared_t& key);
};

class flyProduct
{
 private:
  Flyweight& m_Fly;
  int someUniqueInt;
  std::string someUniqueString;

 public:
  flyProduct(Flyweight& Fly, const int& number, const std::string& name);
  void doSomeThing() const;
  ~flyProduct();
};
