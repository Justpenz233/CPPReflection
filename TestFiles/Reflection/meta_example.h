#pragma once
#include <vector>
#include "Reflection/reflection/reflection.h"

namespace Piccolo
{
    REFLECTION_TYPE(Object)
    CLASS(Object)
    {
    public:
        MPROPERTY()
        std::string ObjectName;
    };
    

    REFLECTION_TYPE(BaseTest)
    CLASS(BaseTest : public Object)
    {
        REFLECTION_BODY(BaseTest);

    public:
        MPROPERTY()
        int               m_int;
        MPROPERTY()
        std::vector<int*> m_int_vector;
    };

    REFLECTION_TYPE(Test1)
    CLASS(Test1 : public BaseTest)
    {
        REFLECTION_BODY(Test1);

    public:
        MPROPERTY()
        char m_char;
    };

    REFLECTION_TYPE(Test2)
    CLASS(Test2 : public BaseTest)
    {
        REFLECTION_BODY(Test2);

    public:
        MPROPERTY()
        std::vector<Reflection::ReflectionPtr<BaseTest>> m_test_base_array;
    };

    void metaExample();
} // namespace Piccolo
