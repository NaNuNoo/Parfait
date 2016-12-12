#include <cstdlib>
#include <shared_ptr>
#include <vector>
using namespace std;

struct Request {
    int _field;
};

class AbstractHandler {
public:
    virtual bool Handle(Request request) = 0;
};

class Handler1 {
public:
    bool Handle(Request request) { /* ...... */ }
}

class Handler2 {
public:
    bool Handle(Request request) { /* ...... */ }
}

class HandlerManager {
private:
    vector<shared_ptr<AbstractHandler>> _handlers;
public:
    void AddHandler(shared_ptr<AbstractHandler> handler) {
        _handlers.push_back(handler);
    }
    bool Handle(Request request) {
        for (int index = 0; index < _handlers.length(); ++index) {
            bool result = _handlers[index].Handle(request);
            if (result) {
                return true;
            }
        }
        return false;
    }
};
