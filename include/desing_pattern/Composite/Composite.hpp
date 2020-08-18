#pragma once
#include <iostream>
#include <list>
#include <memory>
#include <vector>

template <typename derivate>
class component
{
 private:
 protected:
  std::shared_ptr<component> prnt;

 public:
  void setParent(std::shared_ptr<component>& parent);
  void setParent(std::shared_ptr<component>&& parent);
  std::shared_ptr<component> getParent(void) const
  {
    return this->parent;
  }
  void add(component& component)
  {
    static_cast<derivate*>(this)->add(component);
  }
  void remove(component& component)
  {
    static_cast<derivate*>(this)->remove(component);
  }
  void doSomeThing(void)
  {
    static_cast<derivate*>(this)->doSomeThing();
  }
};
template <typename derivate>
void component<derivate>::setParent(std::shared_ptr<component>& parent)
{
  this->prnt = parent;
}

template <typename derivate>
void component<derivate>::setParent(std::shared_ptr<component>&& parent)
{
  this->prnt = std::move(parent);
}

class composite : public component<composite>
{
 private:
 protected:
  std::list<component*> children;

 public:
  size_t id;
  composite();
  ~composite();
  void add(component& cmpnnt);
  void remove(component& cmpnnt);
  void doSomeThing(void);
  composite* begin();
  composite* end();
};

/**
 * ! This is Vishal Chovatiya crtp implemantation
template <typename Self>
class component
{
private:
    std::shared_ptr<Self> parrent;
public:
    template<typename T>
    void connect_to(T& other);
};

class composite :public component<composite>
{
private:
public:
    size_t id;
    composite();
    std::vector<std::shared_ptr<composite>> in,out;
    composite* begin();
    composite* end();
};

class groupOfComponent :public std::vector<composite>,public component<groupOfComponent>
{
private:
public:
    groupOfComponent(size_t count);
};

// * templates
template<typename Self>
template<typename T>
void component<Self>::connect_to(T& other)
{
   for (composite& from : *static_cast<Self *>(this))
   {
       for (composite& to : other)
       {
            from.out.push_back(std::make_shared<composite>(to));
            to.in.push_back(std::make_shared<composite>(from));
       }

   }

}


template <typename Self>
std::ostream &operator<<(std::ostream &os, component<Self> &object) {
    for (composite &obj : *static_cast<Self *>(&object)) {
        for (auto &&n : obj.in)
            os << n->id << "\t-->\t[" << obj.id << "]" << '\n';
        for (auto &&n : obj.out)
            os << "[" << obj.id << "]\t-->\t" << n->id << '\n';
    }
    return os;
}
*/