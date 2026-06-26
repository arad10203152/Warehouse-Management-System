// source/Product.cpp
#include "../include/Product.h"
#include <iostream>

using namespace std; // Here we can use it safely!

// Constructor implementation using member initializer list
Product::Product(int i, string n, double p, int q) 
    : id(i), name(n), price(p), quantity(q) {}

// Destructor implementation
Product::~Product() {}

// Display function implementation
void Product::display() const {
    cout << "ID: " << id << " | Name: " << name 
         << " | Price: $" << price << " | Qty: " << quantity;
}

// Getters implementation
int Product::getId() const { return id; }
string Product::getName() const { return name; }

// JSON conversion implementation
json Product::toJsonObject() const {
    json j;
    j["id"] = id;
    j["name"] = name;
    j["price"] = price;
    j["quantity"] = quantity;
    j["type"] = "Normal"; // To identify the product type later
    return j;
}