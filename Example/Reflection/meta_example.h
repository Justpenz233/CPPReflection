#pragma once
#include <vector>
#include "Reflection/reflection/reflection.h"

    enum EAccessorFlag
    {
        // Include all propertys recursively from parent class
        Default,

        // Exclude all property from parent class
        ExculdeParent
    };

    MCLASS(Object)
    class Object : public std::enable_shared_from_this<Object>
    {
        REFLECTION_BODY_OBJECT(Object);
    protected:
        MPROPERTY()
        std::string ObjectName;
    public:
        typedef std::string Class;

        // Get immediate parent class
        std::vector<Class> GetBaseClassDirect();

        // Get all parent classes recursively
        std::vector<Class> GetBaseClassRecursive();

        std::vector<Reflection::FieldAccessor> GetAllPropertyAceessors(EAccessorFlag Flag = EAccessorFlag::Default);

        Reflection::ReflectionInstance GetMetaInfo();

        static Reflection::ReflectionInstance GetMetaInfo(const Class& ClassName, void* Instance);
    };

    MCLASS(BaseTest)
    class BaseTest : public Object
    {
        REFLECTION_BODY(BaseTest);

    public:
        MPROPERTY()
        int               m_int;
        MPROPERTY()
        std::vector<int*> m_int_vector;
        MFUNCTION()
        void test();
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
    private:
        MPROPERTY()
        int Private_test = 10;
    public:
        MPROPERTY()
        std::vector<Reflection::ReflectionPtr<BaseTest>> m_test_base_array;
    };

    void metaExample();
