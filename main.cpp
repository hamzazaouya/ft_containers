#include <iostream>
#include <memory>
#include <vector>
#include "vector/vector.tpp"


int main(void)
{
  ft::vector<int>::iterator begin;
  ft::vector<int>::iterator end;
  int arr[5] = {10, 20, 30};
  ft::vector<int> v1(2,100);
  ft::vector<int> v2(v1.begin(), v1.end());
  ft::vector<int> v3(arr, arr + 3);
  return (0);
}
