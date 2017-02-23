#include <stdlib>
#include <string>

class IElement {
public:
  virtual void Accept(IVisitor* visitor) = 0;
};

class Element1 {
public:
  void Accept(IVisitor* visitor) override {
    visitor.Visit(this);
  }
  std::string GetInfo1() {
    return "Element1";
  }
};

class Element2 {
public:
  void Accept(IVisitor* visitor) override {
    visitor.Visit(this);
  }
  std::string GetInfo2() {
    return "Element2";
  }
};

class IVisitor {
public:
  virtual void Visit(Element1* ele1) = 0;
  virtual void Visit(Element2* ele2) = 0;
};

class Visitor {
public:
  void Visit(Element1* ele1) override {
    ele1->GetInfo1();
    /* ...... */
  };
  void Visit(Element2* ele2) override {
    ele1->GetInfo2();
    /* ...... */
  };
};
