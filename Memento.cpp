#include <cstdlib>
#include <vector>
using namespace std;

class Originator {
private:
    int _intState = 0;
    float _floatState = 0.0f;
public:
    void SetIntState(i) { _intState = i; }
    int GetIntState() { return _intState; }
    void SetFloatState(f) { _floatState = f; }
    int GetFloatState() { return _floatState; }
    Memento CreateMemento() {
        Memento memento;
        memento.intState = _intState;
        memento.floatState _floatState;
        return memento
    }
    void RestoreMemento(Memento memento) {
        _intState = memento.intState;
        _floatState = memento.floatState;
    }
};

class Memento {
public:
    int intState = 0;
    float floatState = 0.0f;
};

class Caretaker {
private:
    Memento _memento;
public:
    void SetMemento(memento) {
        _memento = memento;
    }
    Memento GetMemento() {
        return _memento;
    }
};
