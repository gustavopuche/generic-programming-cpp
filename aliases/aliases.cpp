#include <iostream>
#include <vector>
#include <type_traits>

using namespace std;


// Constant template.
template <class T> constexpr T viscosity = 0.4;

template <typename T1, typename T2>
constexpr bool Assignable = is_assignable<T1&,T2>::value; // is_assignable is a type trait.

template <typename T> void testing() {
  static_assert(Assignable<T&,double>,"can't assign a double");
  static_assert(Assignable<T&,string>,"can't assign a string");
}

// Aliases
using my_long = unsigned long;

template <typename T> class Vector {
public:
  using value_type = T;
  // ...
};

template <typename C>
using Value_type = typename C::value_type; // The type of C's elements.

template <typename Container> void algo(Container &c) {
  Vector<Value_type<Container>> vec;
  // ...
}

template <typename Key, typename Value> class Map {
// ...
};

// Defining alias to a string map.
template <typename Value>
using String_map = Map<string,Value>;

int main()
{

  auto visc2 = 2*viscosity<double>;
  cout << "Viscosity = " << visc2 << endl;

  testing<string>(); // Change to string.

  String_map<int> m; // m is a Map<string, int>.
  
  return 0;
}
