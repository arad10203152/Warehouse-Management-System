// source/Warehouse.cpp
#include "../include/Warehouse.h"
#include "../include/PerishableProduct.h"
#include <fstream>
#include <iostream>

using namespace std;

Warehouse::Warehouse() {
    loadFromFile(); // Automatically load data when warehouse starts
}

Warehouse::~Warehouse() {
    // Clean up memory to avoid memory leaks (Destructor requirement)
    for (Product* p : products) {
        delete p;
    }
}

void Warehouse::addProduct(Product* p) {
    products.push_back(p);
    saveToFile(); // Save immediately when a product is added
}

void Warehouse::showInventory() const {
    if (products.empty()) {
        cout << "Warehouse is empty!\n";
        return;
    }
    for (Product* p : products) {
        p->display(); // Polymorphism: automatically calls the correct display()
        cout << "\n---------------------\n";
    }
}

void Warehouse::saveToFile() const {
    ofstream file(filePath);
    if (!file.is_open()) return;

    json j_list = json::array(); // Create a JSON array
    for (Product* p : products) {
        j_list.push_back(p->toJsonObject()); // Polymorphism: calls correct toJsonObject()
    }

    file << j_list.dump(4); // dump(4) makes the JSON look clean and readable (indented)
    file.close();
}

void Warehouse::loadFromFile() {
    ifstream file(filePath);
    if (!file.is_open()) return; // If file doesn't exist yet, just skip

    json j_list;
    file >> j_list;
    file.close();

    // Clear current vector memory before loading
    for (Product* p : products) delete p;
    products.clear();

    // Parse JSON back into real objects
    for (const auto& item : j_list) {
        int id = item["id"];
        string name = item["name"];
        double price = item["price"];
        int quantity = item["quantity"];
        string type = item["type"];

        if (type == "Perishable") {
            string date = item["expiry_date"];
            products.push_back(new PerishableProduct(id, name, price, quantity, date));
        } else {
            products.push_back(new Product(id, name, price, quantity));
        }
    }
}