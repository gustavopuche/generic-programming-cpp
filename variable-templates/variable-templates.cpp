#include <iostream>
#include <vector>
#include <type_traits>

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

// Constant template.
template <class T> constexpr T viscosity = 0.4;

template <typename T1, typename T2>
constexpr bool Assignable = is_assignable<T1&,T2>::value; // is_assignable is a type trait.

template <typename T> void testing() {
  static_assert(Assignable<T&,double>,"can't assign a double");
  static_assert(Assignable<T&,string>,"can't assign a string");
}

int main()
{
  // Local buffer of integers allocated on the stack.
  Buffer<int,256> buf;

  cout << "Number of elements in global buffer glob: " << glob.size() << endl;
  cout << "Number of elements in local buffer on the stack buf: "<< buf.size() << endl;

  auto visc2 = 2*viscosity<double>;
  cout << "Viscosity = " << visc2 << endl;

  testing<long>(); // Fails at compile time can't assing a string. Change to string.
  
  return 0;
}
