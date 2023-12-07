#pragma once
#include <vector>
#include "Reflection/reflection/reflection.h"

namespace Piccolo
{
    REFLECTION_TYPE(BaseTest)
    CLASS(BaseTest, Fields)
    {
        REFLECTION_BODY(BaseTest);

    public:
        META(Enable)
        int               m_int;
        META(Enable)
        std::vector<int*> m_int_vector;
    };

    REFLECTION_TYPE(Test1)
    CLASS(Test1 : public BaseTest, WhiteListFields)
    {
        REFLECTION_BODY(Test1);

    public:
        META(Enable)
        char m_char;
    };

    REFLECTION_TYPE(Test2)
    CLASS(Test2 : public BaseTest, , Fields)
    {
        REFLECTION_BODY(Test2);

    public:
        META(Enable)
        std::vector<Reflection::ReflectionPtr<BaseTest>> m_test_base_array;
    };

    void metaExample();
} // namespace Piccolo
