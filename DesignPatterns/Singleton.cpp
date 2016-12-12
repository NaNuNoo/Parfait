#include <cstdlib>

class Singleton {
private:
    Singleton() = delete;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
private:
    static Singleton* instance = nullptr;
public:
    static Singleton* Instance() {
        if (nullptr == instance) {
            instance = new Singleton();
        }
        return instance;
    }
};
