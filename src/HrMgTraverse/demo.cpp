#include <iostream>
#include <string>
using namespace std;

struct Node {
  std::string name;
  struct Node *next;
};

class StuffTree {
  int n;
  struct Node *head;
  public:
    StuffTree(int n) {n = n;}
    void createTree() {
      // to do
    }

    void traverseTree() {

    }
};

class HR {
  public:
    void sendmsg(StuffTree proot) {}
};

class MG {
  public:
    void process(StuffTree proot) {}
};

int main(void) {
  return 0;
}
