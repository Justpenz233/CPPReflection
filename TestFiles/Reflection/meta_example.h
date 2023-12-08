#pragma once
#include <vector>
#include "Reflection/reflection/reflection.h"

namespace Piccolo
{
    MCLASS(Object)
    class Object
    {
    public:
        MPROPERTY()
        std::string ObjectName;
    };
    
    inline int R_TAG_BaseTest_MCLASS_1;

    MCLASS(BaseTest)
    class BaseTest : public Object
    {
        REFLECTION_BODY(BaseTest);

    public:
        MPROPERTY()
        int               m_int;
        MPROPERTY()
        std::vector<int*> m_int_vector;
    };

    MCLASS(Test1)
    class Test1 : public BaseTest
    {
        REFLECTION_BODY(Test1);

    public:
        MPROPERTY()
        char m_char;
    };

    MCLASS(Test2)
    class Test2 : public BaseTest
    {
        REFLECTION_BODY(Test2);

    public:
        MPROPERTY()
        std::vector<Reflection::ReflectionPtr<BaseTest>> m_test_base_array;
    };

    void metaExample();
} // namespace Piccolo
