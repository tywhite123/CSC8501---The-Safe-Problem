//#include "Vec.h"

#pragma once
#include <cstdarg>

template <typename T, int N>

class Vec
{
public:
	Vec(T t, ...);
	~Vec();

	T getAt(int i) { return store[i]; }



private:
	T store[N];
};




//template <typename T, int N>
//Vec<T,N>::Vec()
//{
//}

//Constructor that uses variadic arguments which means that it can take in a 
//variable amount of arguments, this is useful because it means that this vector
//class can work for both the 4 dials per lock and 5 locks per safe

template<typename T, int N>
Vec<T, N>::Vec(T t, ...)
{
	//store[0] = t;
	va_list va;
	va_start(va, N);
	for(int i = 0; i < N; ++i)
	{
		store[i] = va_arg(va, Dial);
	}
	va_end(va);
}

template <typename T, int N>
Vec<T,N>::~Vec()
{
}
