#include <cstdlib>

class Template {
public:
    virtual void Method1() = 0;
    virtual void Method2() = 0;
    virtual void Method3() = 0;
    void Execute() {
        Method1();
        Method2();
        Method3();
    }
};

class Implement1 : public Template {
public:
    void Method1() override { /* ...... */ }
    void Method2() override { /* ...... */ }
    void Method3() override { /* ...... */ }
};

class Implement2 : public Template {
public:
    void Method1() override { /* ...... */ }
    void Method2() override { /* ...... */ }
    void Method3() override { /* ...... */ }
};
