#include <iostream>
#include <memory>
#include <vector>
#include "vector/vector.tpp"
typedef struct test
{
	int a;
	int b;
}	t_test;


template < Iter >
struct iterator_traits
{
	typedef Iter::value_type value_type;
	typedef Iter::reference reference;
	typedef Iter::pointer pointer;
}

template <T>
struct iterator_traits < T * >
{
	typedef Iter::value_type value_type;
	typedef Iter::reference reference;
	typedef Iter::pointer pointer;
}

template < const T * >
struct iterator_traits
{
	typedef T value_type;
	typedef const T * pointer;
	typedef const T & reference;
}


int main(void)
{
	ft::vector<int> v;
	ft::vector<int>::const_iterator iter = v.begin();
	iter = v.end();

	// int arr[10] = {1, 2, 3, 4};
	// const int *p = arr;
	// int *p1 = p;
	// std::cout << *p << std::endl;
	// p++;
	// std::cout << *p << std::endl;
	// *p = 10;
	// ft::vector<int>::iterator iter1, iter2;
	// ft::vector<int> v;
	// v.push_back(123);
	// v.push_back(2334);

	// iter1 = v.begin();
	// iter2 = v.begin();
	// 1 + iter1;
	// std::cout << (iter1 == iter2) << std::endl;
	// std::cout << (iter1 != iter2) << std::endl;
}
