#include <cstdlib>
#include <shared_ptr>
using namespace std;

class Receiver1 {
public:
    void Task1() { /* ...... */ }
};

class Receiver2 {
public:
    void Task2() { /* ...... */ }
};

class AbstractCommand {
public:
    virtual void Execute() = 0;
};

class Command1 : public AbstractCommand {
private:
    shared_ptr<Receiver1> _receiver1;
public:
    Command1(shared_ptr<Receiver1> receiver1) {
        _receiver1 = receiver1;
    }
    void Execute() override {
        _receiver1->Task1();
    }
};

class Command2 : public AbstractCommand {
private:
    shared_ptr<Receiver2> _receiver2;
public:
    Command2(shared_ptr<Receiver2> receiver2) {
        _receiver2 = receiver2;
    }
    void Execute() override {
        _receiver2->Task2();
    }
};
