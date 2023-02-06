#include <iostream>
#include <memory>
#include <vector>
// #include "vector.tpp"

int main(void)
{
    std::allocator<int> myAllocator;
    int *arr = myAllocator.allocate(5);

    myAllocator.construct(arr, 20);
    std::cout << arr[3] << std::endl;
    std::cout << arr[0] << std::endl;

    myAllocator.deallocate(arr, 5);
    myAllocator.destroy(arr);
}

// int main(void)
// {
//     ft::vector<int> v1, v2;
//     std::vector<int> vctor(10, 20);

//     std::cout << vctor.size() << std::endl;
//     std::cout << v1.size() << std::endl;
//     std::cout << v1.capacity() << std::endl;
//     v2 = v1;
//     v2 = v2;
//     std::cout << v2.size() << std::endl;
//     std::cout << v2.capacity() << std::endl;
// }