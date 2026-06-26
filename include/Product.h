
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include "json.hpp" 

/*
It is prohibited to use:
"using namespace std;"
in .h file 
bc it causes "Namespace Pollution"
در واقع در فایل های هدر نباید کتابخانه std رو به صورت Using Directive کنیم چون:
داری کل کلمات و توابع std رو به زور وارد تمام فایل‌های دیگه پروژه می‌کنی.
*/

// Using nlohmann's json shortcut
using json = nlohmann::json;

class Product {
protected:
    int id;
    std::string name;
    double price;
    int quantity;

public:
    // Constructor using member initializer list
    Product(int i, std::string n, double p, int q);

    // Virtual destructor for proper inheritance cleanup
    virtual ~Product();

    // Virtual function for polymorphism - to be overridden by child classes
    virtual void display() const;

    // These are getters (Encapsulation: providing safe read-only access)
    int getId() const;
    std::string getName() const;

    // Polymorphic function to convert object data to JSON format
    virtual json toJsonObject() const;
};

#endif