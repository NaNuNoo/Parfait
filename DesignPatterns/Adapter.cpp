#include <cstdlib>
#include <string>

class ITarget {
public:
  virtual int MethodInt() = 0;
  virtual float MethodFloat() = 0;
};

class Target : public ITarget {
private:
  int _int = 0;
  float _float = 0.0f;
public:
  int MethodInt() override {
    return _int;
  }
  float MethodFloat() override {
    return _float;
  }
};

class Adaptee {
private:
  std::string _intStr = "0";
  std::string _floatStr = "0.0";
public:
  const std::string& MethodIntStr() {
    return _int;
  }
  const std::string& MethodFloatStr() {
    return _float;
  }
}

class Adapter : public ITarget, public Adaptee {
public:
  int MethodInt() override {
    return std::stoi(this->MethodIntStr());
  }
  float MethodFloat() override {
    return std::stof(this->MethodFloatStr());
  }
}
