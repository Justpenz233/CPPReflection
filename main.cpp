#include <iostream>
#include "Reflection/meta_example.h"
#include "Reflection/reflection/reflection_register.h"
#include "_generated/reflection/all_reflection.h"

MCLASS(B)
class B : public Piccolo::Object
{
    REFLECTION_BODY(B);
};

int main()
{
    Piccolo::Reflection::TypeMetaRegister::metaRegister();
    std::shared_ptr<B> b = std::make_shared<B>();
    std::shared_ptr<Piccolo::Object> t = b;
    std::cout << t->GetClassName() << std::endl;

    Piccolo::metaExample();
}