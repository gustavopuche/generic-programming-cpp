#include <iostream>
#include <vector>
#include <list>

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

template <typename Sequence, typename Value>
Value sum(const Sequence& s,Value v)
{
  for (auto x : s)
    v+=x;
  return v;
}

// Functor template example.
template <typename T>
class More_than
{
  const T val; // Value to compare againts.

public:
  More_than(const T& v) :val(v) {}
  bool operator()(const T &x) const { return x > val; } // Call operator.
};

// Function to call Functor predicate from a sequence.
template <typename Sequence, typename P>
int count_success(const Sequence &s, P pred)
{
  int count = 0;
  
  for (const auto& x : s)
  {
    if (pred(x))
    {
      count++;
      cout  << x << " is greater than... " << endl;
    }
    else
    {
      cout  << x  << " is NOT greater than... " << endl;
    }
  }
  
  return count;
}

////////////////////////////////////////////////////////////////////////////////
//
// MAIN FUNCTION
//
////////////////////////////////////////////////////////////////////////////////
int main()
{
  // Local buffer of integers allocated on the stack.
  Buffer<int,256> buf;

  cout  << "Number of elements in global buffer glob: " << glob.size()
                  << endl;
  cout  << "Number of elements in local buffer on the stack buf: " << buf.size() << endl;

  vector<int> vi{1, 2, 3, 4, 5, 6};
  list<double> ld{0.2, 0.7, 1.56, 2.43, 3.43, 3.56};

  auto x = sum(vi,0);
  auto d = sum(ld,0.0);

  cout  << "Sum of integer vector: " << x << endl;
  cout  << "Sum of double list: " << d << endl;

  More_than mti{57}; // Compare i to 57 using < (i>57).
  More_than mts{"Gustavo"s}; // Compare i to 57 using < (s>"Gustavo"s).

  int i_value = 67;
  
  if (mti(i_value))
    cout << i_value  << " greater than " << 57 << endl;
  else
    cout << i_value  << " is not greater than " << 57 << endl;

  string s = "Puche"s;

  if (mts(s))
    cout  << s  << " greater than "  << "Gustavo" << endl;
  else
    cout  << s  << " is not greater than "  << "Gustavo" << endl;

  vector<int> vi2{1, 6, 8, 58, 64, 33, 99, 78, 65, 44};

  count_success(vi2, mti);
  
  return 0;
}
