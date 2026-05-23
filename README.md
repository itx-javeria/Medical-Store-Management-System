# 🏥 Medical Store Management System

**A comprehensive terminal-based pharmacy management system with integrated clinic functionality**

[![C++](https://img.shields.io/badge/C++-11-blue.svg)](https://isocpp.org/)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey.svg)](https://github.com)

> **Academic Project** — Object-Oriented Programming Course (2nd Semester)  
> Developed by: **Javeria Hussain** | Student ID: F2025-0990

---

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [OOP Concepts](#oop-concepts)
- [System Architecture](#system-architecture)
- [Installation](#installation)
- [Usage](#usage)
- [File Structure](#file-structure)
- [Contributing](#contributing)
- [License](#license)

---

## 🎯 Overview

The **Medical Store Management System** is a robust C++ application designed to streamline pharmacy operations and clinic appointment management. Built with object-oriented principles, it provides separate interfaces for administrators and customers with comprehensive inventory tracking, sales processing, and persistent data storage.

### Problem Statement

Manual pharmacy management faces critical challenges:
- ❌ Unreliable stock tracking
- ❌ Error-prone sales records
- ❌ Slow revenue calculations
- ❌ Scheduling conflicts in appointments
- ❌ Vulnerable paper-based records

This system automates these operations with accuracy, efficiency, and data persistence.

---

## ✨ Features

### 👨‍💼 Admin Functions
- ➕ **Add Medicines** — Insert new inventory with automatic validation
- 📊 **View Stock** — Complete inventory overview with sales statistics
- 💰 **Revenue Tracking** — Real-time earnings and units sold
- 📅 **Appointment Management** — View all booked patient appointments

### 👥 Customer Functions
- 🔍 **Search & Buy** — Case-insensitive medicine search with stock updates
- 📝 **Book Appointments** — Schedule doctor visits with time validation

### 🛡️ System Features
- 💾 **File Persistence** — All data saved to `medicines.txt` in pipe-delimited format
- ✅ **Input Validation** — Robust protection against invalid inputs
- 🎨 **Color-Coded UI** — ANSI terminal colors for better readability
- 🔐 **Role-Based Access** — Admin password protection (default: `admin123`)
- 📈 **Dynamic Memory** — Arrays grow automatically when capacity reached

---

## 🧩 OOP Concepts

This project demonstrates **12 core object-oriented programming concepts**:

| Concept | Implementation |
|---------|----------------|
| **Classes & Objects** | 7 classes modeling real-world entities |
| **Encapsulation** | Private data members with public getters/setters |
| **Inheritance** | `Patient`, `Doctor`, `Admin` extend `Person` base class |
| **Abstraction** | `Person` is an abstract class |
| **Pure Virtual Function** | `virtual void display() = 0` in `Person` |
| **Function Overriding** | Each child class overrides `display()` |
| **Function Overloading** | Multiple constructors with different parameters |
| **Association** | `Appointment` links `Patient` and `Doctor` |
| **File Handling** | `saveToFile()` and `loadFromFile()` methods |
| **Dynamic Arrays** | `new`/`delete[]` with automatic growth |
| **Static Keyword** | `totalMedicinesSold` shared across all `Medicine` objects |
| **Exception Handling** | `try-catch` blocks for file corruption handling |
| **this Pointer** | Used in all constructors and setters |

---

## 🏗️ System Architecture

```
Person (Abstract Base Class)
├── Patient (inherits name, contactNo + adds age)
├── Doctor (inherits name, contactNo + adds specialization)
└── Admin (inherits name, contactNo + adds password)

Medicine (Standalone)
└── Static member: totalMedicinesSold

Appointment (Association)
└── Links Patient + Doctor

MedicalStore (Controller)
└── Manages arrays, file I/O, menus
```

### Class Overview

| Class | Type | Purpose |
|-------|------|---------|
| `Person` | Abstract Base | Parent class with pure virtual `display()` |
| `Patient` | Child | Patient data with age |
| `Doctor` | Child | Doctor with specialization |
| `Admin` | Child | Admin with password authentication |
| `Medicine` | Standalone | Medicine inventory with static sales counter |
| `Appointment` | Association | Links patient to doctor for appointments |
| `MedicalStore` | Controller | Main system managing all operations |

---

## 🚀 Installation

### Prerequisites

- **C++ Compiler**: GCC 7.0+ or any C++11 compatible compiler
- **Operating System**: Windows 10+, Linux, or macOS
- **Terminal**: Command Prompt, PowerShell, or UNIX terminal with ANSI color support

### Compilation

```bash
# Clone the repository
git clone https://github.com/itx-javeria/Medical-Store-Management-System.git
cd Medical-Store-Management

# Compile
g++ medical_store.cpp -o medical_store

# For C++11 compliance (if needed)
g++ -std=c++11 medical_store.cpp -o medical_store
```

---

## 💻 Usage

### Running the Program

**Windows:**
```cmd
medical_store.exe
```

**Linux/macOS:**
```bash
./medical_store
```

### Admin Access
1. Select option `1` from main menu
2. Enter password: `admin123`
3. Access admin functions

### Customer Access
1. Select option `2` from main menu (no password required)
2. Search for medicines or book appointments

### Example Workflow

```
MEDICAL STORE MANAGEMENT SYSTEM
================================
1. Login as Admin (Store Owner)
2. Continue as Customer
3. Exit Program

Enter your choice: 2

CUSTOMER MENU
=============
1. Search and Buy Medicine
2. Book Doctor Appointment
3. Back to Main Menu

Enter Medicine Name: PANADOL
[Medicine found - shows details]
Enter Quantity to Buy: 5
Purchase Successful! Total Bill: Rs. 77.5
```

---

## 📁 File Structure

```
Medical-Store-Mmanagement/
├── medical_store.cpp          # Main source code
├── medicines.txt              # Data persistence file (auto-generated)
├── README.md                  # This file
├── LICENSE                    # MIT License
└── documentation/
    └── Medical_Store_Project_Documentation.docx
```

### medicines.txt Format

```
3
PANADOL|15.5|98
BRUFEN|25.0|47
DISPRIN|10.0|200
```

- **Line 1**: Total medicine count
- **Remaining lines**: `NAME|PRICE|QUANTITY` format

---

## 🤝 Contributing

Contributions are welcome! Please follow these steps:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

### Coding Standards

- Follow existing code style
- Add comments for complex logic
- Update documentation for new features
- Test thoroughly before submitting

---

## 🐛 Known Issues

- ANSI colors may not display on older Windows terminals (use Windows 10+ or Windows Terminal)
- File path must not contain special characters
- Maximum 100 medicines supported (can be increased by changing `MAX_MEDICINES` constant)

---

## 🔮 Future Enhancements

- [ ] Database integration (MySQL/SQLite)
- [ ] Graphical User Interface (Qt/GTK)
- [ ] Multi-doctor support
- [ ] Inventory alerts for low stock
- [ ] Sales reporting with date filters
- [ ] Prescription management
- [ ] Barcode scanning support

---

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

```
MIT License

Copyright (c) 2026 Javeria Hussain

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

---

## 👤 Author

**Javeria Hussain**
- Student ID: F2025-0990
- Course: Object-Oriented Programming (2nd Semester)
- Institution: Beaconhouse National University

---

## 🙏 Acknowledgments

- Course instructor for guidance on OOP principles
- Beaconhouse National University for academic support
- Open-source community for C++ resources

---

<div align="center">

**⭐ Star this repository if you found it helpful!**

Made with ❤️ for learning OOP concepts

</div>
