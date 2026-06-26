// source/PerishableProduct.cpp
#include "../include/PerishableProduct.h"
#include <iostream>

using namespace std;

PerishableProduct::PerishableProduct(int i, string n, double p, int q, string date)
    : Product(i, n, p, q), expiryDate(date) {}

PerishableProduct::~PerishableProduct() {}

void PerishableProduct::display() const {
    Product::display(); 
    cout << " | Expiry Date: " << expiryDate;
}

json PerishableProduct::toJsonObject() const {
    json j = Product::toJsonObject(); 
    j["expiry_date"] = expiryDate;    
    j["type"] = "Perishable";         
    return j;
}