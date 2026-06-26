// include/PerishableProduct.h
#ifndef PERISHABLE_PRODUCT_H
#define PERISHABLE_PRODUCT_H

#include "Product.h"

class PerishableProduct : public Product {
private:
    std::string expiryDate;

public:
    PerishableProduct(int i, std::string n, double p, int q, std::string date);
    ~PerishableProduct() override;

    void display() const override;
    json toJsonObject() const override;
};

#endif