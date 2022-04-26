#include <iostream>

using namespace std;

template <typename T, int N>
struct Buffer
{
  using value_type = T;
  constexpr int size() 
  {
    return N;
  }
  T elements[N];
  // ...
};

// Global buffer of characters statically allocated.
Buffer<char, 1024> glob;

int main()
{
  // Local buffer of integers allocated on the stack.
  Buffer<int,256> buf;

  cout << "Number of elements in global buffer glob: " << glob.size() << endl;
  cout << "Number of elements in local buffer on the stack buf: "<< buf.size() << endl;

  return 0;
}
