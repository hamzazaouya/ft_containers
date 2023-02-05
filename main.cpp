#include <iostream>
#include <memory>
#include <vector>
#include "vector.tpp"

int main(void)
{
    ft::vector<int> v1, v2;
    std::vector<int> vctor(10, 20, 30);

    std::cout << vctor[0] << std::endl;
    std::cout << v1.size() << std::endl;
    std::cout << v1.capacity() << std::endl;
    v1 = v2;
    std::cout << v2.size() << std::endl;
    std::cout << v2.capacity() << std::endl;
}