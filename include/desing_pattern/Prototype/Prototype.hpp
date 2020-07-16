#pragma once
#include <type_traits>
#include <cstddef>
#include <memory>
#include <map>
#include <functional>


enum class typeOfPrototype : std::underlying_type_t<std::byte>
{
    prototype_1 = 0x00,
    prototype_2 = 0x01
};

// this functur is for fix to enum class bug of std::unordered_map 
struct EnumClassHash
{
    template <typename T>
    std::size_t operator()(T t) const
    {
        return static_cast<std::size_t>(t);
    }
};

class absPrototype
{
private:
    
public:
    absPrototype();
    virtual ~absPrototype() = 0;
    virtual std::unique_ptr<absPrototype> create() =0;
    virtual std::unique_ptr<absPrototype> clone() =0;
};


class concretePrototype_1 : public absPrototype
{
private:
    
public:
    concretePrototype_1();
    ~concretePrototype_1();
    std::unique_ptr<absPrototype> create() override;
    std::unique_ptr<absPrototype> clone() override;
};

class concretePrototype_2 : public absPrototype
{
private:
    
public:
    concretePrototype_2();
    ~concretePrototype_2();
    std::unique_ptr<absPrototype> create() override;
    std::unique_ptr<absPrototype> clone() override;
};

class factoryPrototype
{
private:
    std::unordered_map<typeOfPrototype, std::unique_ptr<absPrototype>, EnumClassHash> prototypes_;
public:
    factoryPrototype();
    ~factoryPrototype();
    std::unique_ptr<absPrototype> createCloneOf(typeOfPrototype t);
};





