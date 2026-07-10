# 🏢 Warehouse Management System (C++)

A robust, object-oriented Warehouse Management System implemented in modern C++. This system demonstrates advanced software engineering principles including inheritance, polymorphism, and dynamic memory management, with seamless data persistence using JSON format.

---

## راهنمای سریع (Persian--> Summary)
این پروژه یک سیستم مدیریت انبار هوشمند و پیشرفته است که با زبان ++C شده. 

### ویژگی‌های کلیدی:
- **شالوده شیءگرایی (OOP):** پیاده‌سازی اصولی ارث‌بری، کپسوله‌سازی و چندریختی (Polymorphic Vectors).
- **پشتیبانی از انواع محصولات:** مدیریت کالاهای فیزیکی فاسدشدنی (دارای تاریخ انقضا) و کالاهای دیجیتال (دارای حجم فایل).
- **ذخیره‌سازی دیتابیس:** ذخیره و لود خودکار و آنی کل انبار در قالب فایل استاندارد `JSON`.
- **منوی تعاملی:** منوی ترمینالیِ کاربرپسند برای مدیریت موجودی، افزودن، حذف و نمایش محصولات.

---

## 🚀 Key Features (English --> Detailed)

- **Advanced Polymorphism:** Utilizes a unified `std::vector<Product*>` to store mixed product types dynamically at runtime.
- **Data Persistence:** Integrated with `nlohmann/json` library to serialize and deserialize the state of the warehouse into a `warehouse.json` database.
- **Extensible Architecture:** Designed with modern abstract-like interfaces, making it incredibly easy to add new product categories (e.g., Physical, Fragile, Subscribed products).
- **Memory Safety:** Implements structured cleanups to prevent memory leaks during dynamic object destruction on the Heap.

---

## 🛠️ Class Architecture & Design



The project architecture strictly follows clean OOP design patterns:

1. **`Product` (Base Class):** Holds core attributes common to all inventory items (`id`, `name`, `price`, `quantity`). It declares virtual methods for polymorphic behavior:
   - `virtual void display() const`
   - `virtual json toJsonObject() const`
2. **`PerishableProduct` (Derived Class):** Inherits from `Product` and adds a specific `expiryDate` attribute. Overrides display and serialization.
3. **`DigitalProduct` (Derived Class):** Inherits from `Product` and introduces `fileSize` (in MB) for digital-only inventory tracking.
4. **`Warehouse` (Manager Class):** Orchestrates the overall logic. It contains methods to `addProduct()`, `removeProduct()`, `saveToFile()`, and `loadFromFile()`.

---

## 📂 Project Structure

```text
WarehouseProject/
├── include/
│   ├── Product.h
│   ├── PerishableProduct.h
│   ├── DigitalProduct.h
│   ├── Warehouse.h
│   └── json.hpp (Header-only JSON library)
├── source/
│   ├── Product.cpp
│   ├── PerishableProduct.cpp
│   ├── DigitalProduct.cpp
│   ├── Warehouse.cpp
│   └── main.cpp
└── data/
    └── warehouse.json






    💻 Compilation & Installation
To compile and run this system on your local machine (Linux/macOS), use any modern standard compiler (g++ or clang++):
# Clone the repository
git clone [https://github.com/arad10203152/Warehouse-Management-System.git](https://github.com/arad10203152/Warehouse-Management-System.git)
cd Warehouse-Management-System

# Compile all source files
g++ -std=c++11 source/*.cpp -o warehouse_app

# Run the executable
./warehouse_app

🧑‍💻 Author
•	Arad - Linux Lover | Code Enthusiast | Securing Systems
•	GitHub: @arad10203152

---

### 📥 چطور آپلودش کنی؟
همان‌طور که یاد گرفتی، ترمینالت را باز کن، برو داخل پوشه پروژه و این سه خط دستور را بزن تا این ریدمی خوشگل مستقیم بنشیند روی گیت‌هابت:

```bash
git add README.md
git commit -m "Docs: Add comprehensive bilingual README"
git push





attention: this project was written by the help of Gemini 

