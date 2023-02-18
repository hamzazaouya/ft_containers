#include <iostream>
#include <vector>


 void func(int i, int *  = 0)
{
    std::cout << i << std::endl;
}
int main(void)
{
    int a  = 13;
    func(10, &a);
}