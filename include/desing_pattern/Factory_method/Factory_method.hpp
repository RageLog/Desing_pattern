#pragma once
#include <cstddef>
#include <memory>
#include <type_traits>

enum class m_type : std::underlying_type_t<std::byte>
{
    m_Class1 = 0x00,
    m_Class2 = 0x01
};


class Object
{
private:
    /* data */
public:
    Object(/* args */);
    virtual ~Object() = 0;
    // ! pure virtual function
    virtual void doSomething() = 0;
    std::shared_ptr<Object> create(m_type t);

};

class Class_1 : public Object
{
private:
public:
    virtual void doSomething() override;

};

class Class_2 : public Object
{
private:
public:
    virtual void doSomething() override;

};

