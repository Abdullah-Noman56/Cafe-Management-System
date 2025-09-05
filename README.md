# Cafe Management System

A comprehensive C++ Object-Oriented Programming project for managing a university cafe system with role-based access control for administrators, employees, and students.

## 📋 Project Overview

This system provides a complete cafe management solution with:

* Inventory management and stock tracking
* Order processing and transaction handling
* User authentication and role-based access
* Employee performance tracking
* Customer complaint system
* Notification system for promotions and updates

## 🏗️ System Architecture

The project follows OOP principles with inheritance and polymorphism:

```
Login (Base Class)
├── Admin (Derived Class)
├── Employee (Derived Class)
└── Student (Derived Class)
```

Additional supporting classes:

* `Order` - Handles order processing
* `Stock` - Manages inventory
* `Credentials` - Handles user authentication

## 👥 User Roles & Features

### 1. Administrator

* View and manage stock details
* Add/remove items and update prices
* Monitor low stock items with threshold alerts
* Manage employee and student credentials
* Post notifications and promotions
* View orders and complaints
* Track best-performing employees

### 2. Employee

* Search menu items
* View online orders
* Process transactions for students/staff
* Take orders directly
* Sales performance tracking

### 3. Student

* Search menu items
* Place orders (immediate and scheduled)
* Submit complaints
* View notifications and promotions

## 📁 File Structure

```
cafe-management-system/
├── main.cpp          # Main application entry point
├── Admin.h/cpp       # Administrator class implementation
├── Employee.h/cpp    # Employee class implementation
├── Student.h/cpp     # Student class implementation
├── login.h/cpp       # Base login class
├── order.h/cpp       # Order management
├── stock.h/cpp       # Inventory management
├── Crediental.h/cpp  # Credentials management
├── project.h         # Common includes and definitions
├── Data Files/
│   ├── menu.txt      # Menu items with prices and quantities
│   ├── Employee.txt  # Employee credentials
│   ├── student.txt   # Student credentials
│   ├── Orders.txt    # Order records
│   ├── Sales.txt     # Employee sales performance
│   ├── Complaints.txt # Customer complaints
│   └── Notification.txt # System notifications
```

## 🚀 Getting Started

### Prerequisites

* C++ compiler (g++ recommended)
* Linux/macOS/Windows with terminal support

### Compilation

```bash
g++ -o Cafe_Management-System *.cpp 
```

### Execution

```bash
./Cafe-Management-System
```

## 🎯 GitHub Repository Setup

Create a new GitHub repository with the name: **`cafe-management-system`**

### Repository Structure

```
cafe-management-system/
├── src/
│   ├── *.cpp
│   └── *.h
├── data/           # Data files (should be created on first run)
├── README.md
├── LICENSE
└── Makefile
```

### Suggested .gitignore

```
*.o
cafe_management-system
data/*.txt
.DS_Store
*.out
```

## 🔧 Key Features Implementation

* **Role-based Authentication**: Different access levels for admin, employees, and students
* **File-based Data Storage**: All data persists in text files
* **Inventory Management**: Track stock levels with color-coded low stock alerts
* **Sales Tracking**: Monitor employee performance
* **Scheduled Orders**: Allow students to schedule orders for specific times
* **Complaint System**: Record and view customer feedback

## 💡 Future Enhancements

* Database integration for better data management
* GUI implementation using Qt or similar framework
* Online ordering system with web interface
* Payment gateway integration
* Advanced reporting and analytics
* Mobile application for students

## 📝 License

This project is created for educational purposes as part of OOP coursework at FAST(NUCES) University Islamabad Univeristy in 2024 spring.

---

**Note**: This system uses text files for data storage. Ensure proper file permissions and consider implementing database storage for production use.
