//#include "Vec.h"

#pragma once
#include <cstdarg>
#include <vector>

using namespace std;

template <typename T, int N>

class Vec
{
public:
	Vec();
	Vec(T t, ...);
	~Vec();

	T getAt(int i) { return store[i]; }
	T* getStore() { return &store; }



	void insert(T t);
	int size() { return store.size(); }
	void resize(int n);


private:
	//T store[N];
	vector<T> store;
	int i = 0;
};




template <typename T, int N>
Vec<T,N>::Vec()
{

	store.resize(N);
	i = 0;
}

//Constructor that uses variadic arguments which means that it can take in a 
//variable amount of arguments, this is useful because it means that this vector
//class can work for both the 4 dials per lock and 5 locks per safe

template<typename T, int N>
Vec<T, N>::Vec(T t, ...)
{
	it = 4;
	//store[0] = t;
	va_list va;
	va_start(va, it);
	for(int i = 0; i < it; ++i)
	{
		store[i] = va_arg(va, Dial);
	}
	va_end(va);
}

template <typename T, int N>
Vec<T,N>::~Vec()
{
}



template<typename T, int N>
void Vec<T, N>::insert(T t)
{
	if (i <= N) {
		store[i] = t;
		++i;
	}
}

template<typename T, int N>
void Vec<T, N>::resize(int n)
{
	store.resize(n);
}






