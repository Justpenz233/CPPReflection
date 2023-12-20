# Yet another CPP reflection lib
## Reference
- [Piccolo Engine](https://github.com/BoomingTech/Piccolo/tree/main/engine/source/meta_parser)
- [CPP Reflection](https://github.com/AustinBrunkHorst/CPP-Reflection)

## Usage
```CPP
MCLASS(BaseTest)
class BaseTest : public Object
{
    REFLECTION_BODY(BaseTest);

 public:
        MPROPERTY()
        int m_int;
        
        MPROPERTY()
        std::vector<int*> m_int_vector;
        
        MFUNCTION()
        void test();
    };
```
If you are familiar with Unreal Engine, you will find that the usage of this lib is very similar to Unreal Engine's reflection system. You can use MCLASS, MPROPERTY, MFUNCTION to declare a class, property, function. And you can use REFLECTION_BODY to implement the reflection system.  

## How did it work

We use libclang, a C++ parser, to parse the source code and generate template code to register the class, property, function.  
About the tag MCLASS, is a tricky implementation by string processing.

## TODO
- [ ] Doc for easy tag extension and implementation
- [ ] A base object class 


## install
Support all platforms including MSVC.  
Register your target with the following cmake function:
```cmake
PreCompile(Target1 Target2 ...)
```
