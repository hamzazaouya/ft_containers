#include <iostream>
#include <memory>
#include <vector>
#include "vector/vector.tpp"

int main ()
{
  ft::vector<int> myvector;

  myvector.push_back(10);

  while (myvector.back() != 0)
  {
    myvector.push_back ( myvector.back() -1 );
  }

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size() ; i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

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
