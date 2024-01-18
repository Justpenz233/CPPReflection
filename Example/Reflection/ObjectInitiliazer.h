//
// Created by MarvelLi on 2024/1/18.
//

#pragma once
#include <type_traits>

class MObjectInitiliazer
{
    // ....
public:
    static MObjectInitiliazer& Get();
};


template<class T, bool>
class _ObjectDefaultConstructor
{
public:
    static T* _InternalConstructor(const MObjectInitiliazer& Initiliazer)
    {
        return new T();
    }
};

template<class T>
class _ObjectDefaultConstructor<T, false>
{
public:
    static T* _InternalConstructor(const MObjectInitiliazer& Initiliazer)
    {
        return new T(Initiliazer);
    }
};