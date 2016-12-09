#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    virtual void Method_1() = 0;
    virtual void Method_2() = 0;
};

class Leaf : public Node {
public:
    Leaf() { /* ...... */ }
    void Method_1() override { /* ...... */ }
    void Method_2() override { /* ...... */ }
};

class Branch : public Node {
private:
    vector<Node*> _children = new vector<Node*>();
public:
    Branch() { /* ...... */ }
    void Method_1() override { /* ...... */ }
    void Method_2() override { /* ...... */ }
    void Insert(Node* node) {
        _children.push_back(node);
    }
    void Remove(Node* node) {
        std::remove(_children.begin(), _children.end(), node);
    }
    const vector<Node*>& Children() {
        return _children;
    }
};
