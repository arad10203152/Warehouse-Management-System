// include/Warehouse.h
#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <vector>
#include "Product.h"

class Warehouse {
private:
    std::vector<Product*> products; // Using pointers for Polymorphism to work!
    const std::string filePath = "data/inventory.json";

public:
    Warehouse();
    ~Warehouse();

    void addProduct(Product* p);
    void showInventory() const;
    
    // File I/O operations using JSON
    void saveToFile() const;
    void loadFromFile();
};

#endif