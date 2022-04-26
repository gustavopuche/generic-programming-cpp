#include <iostream>

using namespace std;

template<typename T>
class Printer
{
public:
  string name;
  T      elem;
  
  Printer(string name, T elem) : name(name), elem(elem) {}
  
  void operator()()
  {
    cout << name << " is printing elem "<< elem << endl;

  }
};

int main()
{
  Printer printer1{"Integer Printer",5};
  Printer printer2("String Printer","Hola, ¿cómo estás?");

  printer1();
  printer2();

  return 0;
}
