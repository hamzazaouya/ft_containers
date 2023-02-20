#include <iostream>
#include <memory>
#include <vector>
#include "vector/vector.tpp"


int main(void)
{
  ft::vector<int> v1;
  std::vector<int> v2;
  ft::vector<int>::iterator iter1;
  std::vector<int>::iterator iter2;

  int arr[] = {110, 2, 3, 4, 5};
  for(int i = 0; i < 5; i++)
  {
    v1.push_back(arr[i]); 
    v2.push_back(arr[i]);
  }
  iter1 = v1.end();
  iter2 = v2.end();
  std::cout << v2.end() - v2.begin() << std::endl;
  std::cout << v1.end() - v1.begin() << std::endl;
  return (0);
}
