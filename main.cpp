#include <iostream>
#include "Reflection/meta_example.h"
#include "Reflection/reflection/reflection_register.h"
#include "_generated/reflection/all_reflection.h"


int main()
{
    Piccolo::metaExample(); // Register meta info

    Piccolo::Reflection::TypeMetaRegister::metaRegister();
    std::shared_ptr<Piccolo::Test2> b = std::make_shared<Piccolo::Test2>();
    std::shared_ptr<Piccolo::Object> t = b;
    std::cout << "Class Name : ";
    std::cout << t->GetClassName() << std::endl;

    std::cout << "Base Class Direct : " << std::endl;
    for(auto i : t->GetBaseClassDirect()) {
        std::cout << i << std::endl;
    }
    std::cout << "--------------------" << std::endl;

    std::cout << "Base Class Recursive : " << std::endl;
    for (auto i : t->GetBaseClassRecursive()) {
        std::cout << i << std::endl;
    }
    std::cout << "--------------------" << std::endl;

}