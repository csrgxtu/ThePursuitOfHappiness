#include <iostream>
using namespace std;

class Base {
  private:
    int n;
  public:
    Base(int n) {n = n;}
}

class Child: public Base {
  public:
    void print() {

    }
}
