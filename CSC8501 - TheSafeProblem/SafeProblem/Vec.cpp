//#include "Vec.h"

#pragma once

template <typename T, int N>

class Vec
{
public:
	Vec(T t, ...);
	~Vec();



private:
	T store[N];
};




//template <typename T, int N>
//Vec<T,N>::Vec()
//{
//}

template<typename T, int N>
Vec<T, N>::Vec(T t, ...)
{
}

template <typename T, int N>
Vec<T,N>::~Vec()
{
}
