#include <iostream>
#include "Reflection/meta_example.h"
#include "Reflection/reflection/reflection_register.h"

int main()
{
    //IMPORTANT Call this method to register meta info in global scope
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

    std::cout << "All Property : " << std::endl;
    for (auto i : t->GetAllPropertyAceessors()) {
        std::cout << i.getFieldName() << " : " << i.getFieldTypeName() << " in Class : " << std::endl;
    }

}