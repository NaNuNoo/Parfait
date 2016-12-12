#include <cstdlib>

class AbstractMediator;

class AbstractColleague {
protected:
    AbstractMediator _mediator;
public:
    void AbstractColleague(AbstractMediator* mediator) {
        _mediator = mediator;
    }
};

class Colleague1 : public AbstractColleague {
public:
    Colleague1(AbstractMediator* mediator) :
        AbstractColleague(mediator) {
        _mediator.SetColleague1(this);
    }
    void SimpleTaskA() { /* ...... */}
    void SimpleTaskB() { /* ...... */}
    void ComplexTaskA() {
        _mediator.ComplexTaskA();
    }
};

class Colleague2 : public AbstractColleague {
public:
    Colleague2(AbstractMediator* mediator) :
        AbstractColleague(mediator) {
        _mediator.SetColleague2(this);
    }
    void SimpleTaskA() { /* ...... */}
    void SimpleTaskB() { /* ...... */}
    void ComplexTaskB() {
        _mediator.ComplexTaskB();
    }
};

class AbstractMediator {
protected:
    Colleague1* _colleague1 = nullptr;
    Colleague2* _colleague2 = nullptr;
public:
    void SetColleague1(Colleague1* colleague1) {
        _colleague1 = colleague1;
    }
    void SetColleague2(Colleague2* colleague2) {
        _colleague2 = colleague2;
    }
    virtual void ComplexTaskA() = 0;
    virtual void ComplexTaskB() = 0;
};

class Mediator : public AbstractMediator {
public:
    void ComplexTaskA() override {
        _colleague1.SimpleTaskA();
        _colleague2.SimpleTaskA();
    }
    void ComplexTaskB() override {
        _colleague1.SimpleTaskB();
        _colleague2.SimpleTaskB();
    }
};
