#include <cstdlib>

class Product {
    friend class Builder;
private:
    int _field;
private:
    Product(int field) {
        _field = field;
    }
};

class Builder {
private:
    int _productField;
public:
    void SetField(int field) {
        _productField = field;
    }
    Product* NewProduct() {
        return new Product(field);
    }
};
