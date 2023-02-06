#include <iostream>
#include <memory>
#include <vector>
#include "vector.tpp"

int main(void)
{
	int n  = 10;
    std::vector<int> v1(n, 20);
	std::vector<int> v2 = v1;
	std::vector<int> v3(154875, 30);
	std::vector<int> v4;
	v3 = v2;
	v4 = v3;
	// std::cout << "======= V1 ========" << std::endl;
	// for(int i = 0; i < n; i++)
	// 	std::cout << v1[i] << std::endl;
	// std::cout << "======= V2 ========" << std::endl;
	// for(int i = 0; i < n; i++)
	// 	std::cout << v2[i] << std::endl;
	// std::cout << "======= V4 ========" << std::endl;
	// for(int i = 0; i < n; i++)
	// 	std::cout << v4[i] << std::endl;
	std::cout << "======= V1 Size && Capacitry" << std::endl;
    std::cout << v1.size() << std::endl;
    std::cout << v1.capacity() << std::endl;
	std::cout << "======= V2 Size && Capacitry" << std::endl;
    std::cout << v2.size() << std::endl;
    std::cout << v2.capacity() << std::endl;
	std::cout << "======= V3 Size && Capacitry" << std::endl;
    std::cout << v3.size() << std::endl;
    std::cout << v3.capacity() << std::endl;
	std::cout << "======= V4 Size && Capacitry" << std::endl;
    std::cout << v4.size() << std::endl;
    std::cout << v4.capacity() << std::endl;
}