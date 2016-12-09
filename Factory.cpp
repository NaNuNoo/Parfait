#include <cstdlib>

enum class PRODUCT_TYPE {
    PRODUCT_A = 1,
    PRODUCT_B,
};

class Product {
protected:
    Product() { /* ...... */ }
};

class ProductA : public Product {
    friend Product* Factory(PRODUCT_TYPE type);
private:
    ProductA(): Singleton() { /* ...... */ }
};

class ProductB : public Product {
    friend Product* Factory(PRODUCT_TYPE type);
private:
    ProductB() : Singleton() { /* ...... */ }
};

Product* Factory(PRODUCT_TYPE type) {
    swtich (type) {
    case PRODUCT_TYPE.PRODUCT_A:
        return new ProductA();
    case PRODUCT_TYPE.PRODUCT_B:
        return new ProductB();
    default:
        return nullptr;
    }
};
