#include <iostream>
#include "Prototype/Prototype.hpp"


absPrototype::absPrototype()
{
    std::cout << "absPrototype created" << '\n';
}

absPrototype::~absPrototype()
{
}


concretePrototype_1::concretePrototype_1(){std::cout << "concretePrototype_1 created" << '\n';}
concretePrototype_1::~concretePrototype_1(){}

std::unique_ptr<absPrototype> concretePrototype_1::create() 
{
    std::cout << "concretePrototype_1 created" << '\n';
    return std::make_unique<concretePrototype_1>();
}

std::unique_ptr<absPrototype> concretePrototype_1::clone() 
{
    std::cout << "concretePrototype_1 cloned" << '\n';
    return std::make_unique<concretePrototype_1>(*this);
}

concretePrototype_2::concretePrototype_2(){std::cout << "concretePrototype_2 created" << '\n';}
concretePrototype_2::~concretePrototype_2(){}

std::unique_ptr<absPrototype> concretePrototype_2::create() 
{
    std::cout << "concretePrototype_2 created" << '\n';
    return std::make_unique<concretePrototype_2>();
}

std::unique_ptr<absPrototype> concretePrototype_2::clone() 
{
    std::cout << "concretePrototype_2 cloned" << '\n';
    return std::make_unique<concretePrototype_2>(*this);
}

factoryPrototype::factoryPrototype()
{
    prototypes_[typeOfPrototype::prototype_1] = std::make_unique<concretePrototype_1>();
    prototypes_[typeOfPrototype::prototype_2] = std::make_unique<concretePrototype_2>();

}

factoryPrototype::~factoryPrototype()
{
}

std::unique_ptr<absPrototype> factoryPrototype::createCloneOf(typeOfPrototype t) 
{
    return prototypes_[t]->clone();
}