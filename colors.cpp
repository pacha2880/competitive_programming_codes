#include <iostream>
using namespace std;

namespace Color {
enum Code {
  FG_RED     = 31,
  FG_GREEN   = 32,
  FG_YELLOW  = 33,
  FG_BLUE    = 34,
  FG_DEFAULT = 39
};
class ColorDebugger {
  Code code;
 public:
  ColorDebugger(Code pCode) : code(pCode) {}
  template <class T>
  ColorDebugger& operator<<(const T &other) {
    cout << "\033[" << code << "m" << other << "\033[" << FG_DEFAULT << "m";
    return *this;
  }
  ColorDebugger& operator<<(ostream&(*pManip)(ostream&)){
    (*pManip)(cout);
    return *this;
  }
};
}

using namespace Color;
ColorDebugger ycout(FG_YELLOW);
ColorDebugger rcout(FG_RED);
ColorDebugger bcout(FG_BLUE);
ColorDebugger gcout(FG_GREEN);

int main(){
  ycout << "Hello, I'm a cookie monster!" << endl;
  rcout << "Yes, I'm a cookie cookie cute monster" << endl;
  bcout << "What am I doing" << endl;
  gcout << "how to be as good as {name} orzzzzz" << endl;
  cout << "Hooray" << endl;
}