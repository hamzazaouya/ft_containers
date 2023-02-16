#include <iostream>
#include <memory>
#include <vector>
#include "vector/vector.tpp"

int main ()
{
  // constructors used in the same order as described above:
  // ft::vector<int> first;                                // empty vector of ints
  ft::vector<int> second;
  
  second.push_back(10);
  second.push_back(20);
  second.push_back(30); 
  second.push_back(50);                     // four ints with value 100

  ft::vector<int>::iterator iter_start = second.begin();
  ft::vector<int>::iterator iter_end;
  iter_end = second.end();

  std::cout << *iter_start << std::endl;
  iter_end--;
  std::cout << *iter_end << std::endl;
  // ft::vector<int> third (second.begin(),second.end());  // iterating through second
  // ft::vector<int> fourth (third);                       // a copy of third
  return 0;
}

// int main ()
// {
//   ft::vector<int> myvector;
//   int sum (0);

//   for (int i=1;i<=10;i++) myvector.push_back(i);

//   while (!myvector.empty())
//   {
//      sum += myvector.back();
//      myvector.pop_back();
//   }

//   std::cout << "total: " << sum << '\n';

//   return 0;
// }



// int main ()
// {
//   ft::vector<int>::size_type sz;

//   ft::vector<int> foo;
//   sz = foo.capacity();
//   std::cout << "making foo grow:\n";
//   for (int i=0; i<100; ++i) {
//     foo.push_back(i);
//     if (sz!=foo.capacity()) {
//       sz = foo.capacity();
//       std::cout << "capacity changed: " << sz << '\n';
//     }
//   }

//   std::vector<int> bar;
//   sz = bar.capacity();
//   bar.reserve(100);   // this is the only difference with foo above
//   std::cout << "making bar grow:\n";
//   for (int i=0; i<100; ++i) {
//     bar.push_back(i);
//     if (sz!=bar.capacity()) {
//       sz = bar.capacity();
//       std::cout << "capacity changed: " << sz << '\n';
//     }
//   }
//   return 0;
// }
