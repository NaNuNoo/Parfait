#include <cstdlib>
#include <shared_ptr>

class InnerClass1 {
public:
  void Method() { /* ...... */ }
}

class InnerClass2 {
public:
  void Method() { /* ...... */ }
}

class InnerClass3 {
public:
  void Method() { /* ...... */ }
}

class Facade {
private:
  std::shared_ptr<InnerClass1> _cls1;
  std::shared_ptr<InnerClass2> _cls2;
  std::shared_ptr<InnerClass3> _cls3;
public:
  Facade() {
    _cls1 = std::shared_ptr<InnerClass1>(new InnerClass1());
    _cls2 = std::shared_ptr<InnerClass1>(new InnerClass2());
    _cls3 = std::shared_ptr<InnerClass1>(new InnerClass3());
  }
  void Method1() {
    return _cls1->Method();
  }
  void Method2() {
    return _cls2->Method();
  }
  void Method3() {
    return _cls3->Method();
  }
};
