#include <cstdlib>
#include <vector>
#include <shared_ptr>

class IObserver {
public:
  virtual void OnUpdate() = 0;
}

class Observer : public IObserver {
public:
  void OnUpdate() override {
    /* ...... */
  }
}

class AbstractSubject {
private:
  std::vector<std::shared_ptr<IObserver>> _observerVec;
public:
  void AddObserver(std::shared_ptr<IObserver> observer) {
    _observerVec.push_back(observer);
  }
  void NotifyObserver() {
    for (auto& iter: _observerVec) {
      iter.OnUpdate();
    }
  }
}

class Subject : public AbstractSubject {
private:
  int _field = 0;
public:
  void SetField(int field) {
    _field = field;
    this->NotifyObserver();
  }
}
