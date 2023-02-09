#include <iostream>
#include <memory>
#include <vector>
#include "vector/vector.tpp"

int main(void)
{
	ft::vector<int>::iterator iter1, iter2;
	std::vector<int> v;
	// v.push_back(123);
	// v.push_back(2334);

	// iter1 = v.begin();
	// iter2 = v.begin();
	iter1 = iter2;
	*iter1 = 10;
	// std::cout << (iter1 == iter2) << std::endl;
	// std::cout << (iter1 != iter2) << std::endl;
}