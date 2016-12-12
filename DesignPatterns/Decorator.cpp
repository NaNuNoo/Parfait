#include <cstdlib>
#include <shared_ptr>

class AbstractComponent {
public:
    virtual void Method() = 0;
};

class Component {
public:
    void Operate(int argumant) override { /* ...... */ }
};

class AbstractDecorator : public AbstractComponent {
private:
    shared_ptr<AbstractComponent> _component;
public:
    AbstractDecorator(shared_ptr<AbstractComponent> component) {
        _component = component;
    }
    void Operate(int argumant) override {
        _component->Operate(int argumant);
    }
};

class DecoratorBefore : public AbstractDecorator {
private:
    void Before(int argumant) { /* ...... */ }
public:
    AbstractDecorator(shared_ptr<AbstractComponent> component) :
        AbstractDecorator(component) {
    }
    void Operate(int argumant) override {
        Before(argumant);
        AbstractDecorator::Operate(argumant);
    }
};

class DecoratorAfter : public AbstractDecorator {
private:
    void After(int argumant) { /* ...... */ }
public:
    AbstractDecorator(shared_ptr<AbstractComponent> component) :
        AbstractDecorator(component) {
    }
    void Operate(int argumant) override {
        AbstractDecorator::Operate(argumant);
        After(argumant);
    }
};
