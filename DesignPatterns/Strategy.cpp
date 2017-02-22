#include <cstdlib>

class IStrategy {
public:
  virtual void Method() = 0;
};

class Strategy1 : public IStrategy {
public:
  void Method() override {
    /* ...... */
  }
};

class Strategy2 : public IStrategy {
public:
  void Method() override {
    /* ...... */
  }
};
