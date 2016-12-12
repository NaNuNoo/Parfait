#include <cstdlib>

class Prototype {
public:
    Prototype* Clone() {
        Prototype* newObj = new Prototype();
        // Copy filed from this to newObj
        return newObj;
    }
    static Prototype* Clone(Prototype* oldObj) {
        return oldObj.Clone();
    }
};
