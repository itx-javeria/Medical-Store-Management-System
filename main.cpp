#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

//   color codes for displaying differenct colors in terminal
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"         
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define MAGENTA "\033[35m"
#define BOLD "\033[1m"
#define WHITE "\033[37m"

// set maximum number of appointments by using const keyword
const int MAX_APPOINTMENTS = 50;

/* a function that will keep asking until the user enters a valid integer ,
 used this at taking valid input from users
*/
int getIntInput()
{
    int value;
    cin >> value;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << RED << "  Invalid input! Please enter a number: " << RESET;
        cin >> value;
    }

    return value;
}

class Person
{
protected:
    string name;
    string contactNo;

public:
    Person();
    Person(string name, string contactNo);

    void setName(string name);
    void setContactNo(string contactNo);
    string getName();
    string getContactNo();

    virtual void display() = 0;
};

Person::Person()
{
    this->name = "";
    this->contactNo = "";
}

Person::Person(string name, string contactNo)
{
    this->name = name;
    this->contactNo = contactNo;
}

void Person::setName(string name)
{
    this->name = name;
}

void Person::setContactNo(string contactNo)
{
    this->contactNo = contactNo;
}

string Person::getName()
{
    return this->name;
}

string Person::getContactNo()
{
    return this->contactNo;
}

class Patient : public Person
{
private:
    int age;

public:
    Patient();
    Patient(string name, string contactNo, int age);

    void setAge(int age);
    int getAge();

    void display() override;
};

Patient::Patient() : Person()
{
    this->age = 0;
}

Patient::Patient(string name, string contactNo, int age) : Person(name, contactNo)
{
    this->age = age;
}

void Patient::setAge(int age)
{
    this->age = age;
}

int Patient::getAge()
{
    return this->age;
}

void Patient::display()
{
    cout << "  Patient Name : " << this->name << endl;
    cout << "  Contact No.  : " << this->contactNo << endl;
    cout << "  Age          : " << this->age << endl;
}

class Doctor : public Person
{
private:
    string specialization;

public:
    Doctor();
    Doctor(string name, string contactNo, string specialization);

    void setSpecialization(string specialization);
    string getSpecialization();

    void display() override;
};

Doctor::Doctor() : Person()
{
    this->name = "Dr.Javeria Hussain";
    this->specialization = "General Physician";
    this->contactNo = "0300-1234567";
}

Doctor::Doctor(string name, string contactNo, string specialization) : Person(name, contactNo)
{
    this->specialization = specialization;
}

void Doctor::setSpecialization(string specialization)
{
    this->specialization = specialization;
}

string Doctor::getSpecialization()
{
    return this->specialization;
}

void Doctor::display()
{
    cout << "  Doctor Name  : " << this->name << endl;
    cout << "  Field        : " << this->specialization << endl;
}

class Admin : public Person
{
private:
    string password;

public:
    Admin();
    Admin(string name, string contactNo, string password);

    bool checkPassword(string inputPassword);

    void display();
};

Admin::Admin() : Person()
{
    this->name = "Store Owner";
    this->contactNo = "N/A";
    this->password = "admin123";
}

Admin::Admin(string name, string contactNo, string password) : Person(name, contactNo)
{
    this->password = password;
}

bool Admin::checkPassword(string inputPassword)
{
    return (this->password == inputPassword);
}

void Admin::display()
{
    cout << "  Admin Name   : " << this->name << endl;
    cout << "  Contact No.  : " << this->contactNo << endl;
}

class Medicine
{
private:
    string medicineName;
    double price;
    int quantity;

    static int totalMedicinesSold;

public:
    Medicine();
    Medicine(string medicineName, double price, int quantity);

    void setMedicineName(string medicineName);
    void setMedicinePrice(double price);
    void setMedicineQuantity(int quantity);
    string getMedicineName();
    double getMedicinePrice();
    int getMedicineQuantity();

    void reduceQuantity(int amount);
    void displayMedicine();

    static int getTotalMedicinesSold();
};

int Medicine::totalMedicinesSold = 0;

Medicine::Medicine()
{
    this->medicineName = "";
    this->price = 0.0;
    this->quantity = 0;
}

Medicine::Medicine(string medicineName, double price, int quantity)
{
    this->medicineName = medicineName;
    this->price = price;
    this->quantity = quantity;
}

void Medicine::setMedicineName(string medicineName)
{
    this->medicineName = medicineName;
}

void Medicine::setMedicinePrice(double price)
{
    this->price = price;
}

void Medicine::setMedicineQuantity(int quantity)
{
    this->quantity = quantity;
}

string Medicine::getMedicineName()
{
    return this->medicineName;
}

double Medicine::getMedicinePrice()
{
    return this->price;
}

int Medicine::getMedicineQuantity()
{
    return this->quantity;
}

void Medicine::reduceQuantity(int amount)
{
    this->quantity = this->quantity - amount;
    Medicine::totalMedicinesSold = Medicine::totalMedicinesSold + amount;
}

void Medicine::displayMedicine()
{
    cout << "  MedicineName : " << this->medicineName << endl;
    cout << "  Price        : Rs./ " << this->price << endl;
    cout << "  In Stock     : " << this->quantity << " units" << endl;
}

int Medicine::getTotalMedicinesSold()
{
    return Medicine::totalMedicinesSold;
}

class Appointment
{
private:
    Patient patient;
    Doctor doctor;
    string appointmentTime;

public:
    Appointment();

    void setAppointment(string patientName, string contactNo, int age, string time);
    void displayAppointment();
};

Appointment::Appointment()
{
    this->appointmentTime = "";
}

void Appointment::setAppointment(string patientName, string contactNo, int age, string time)
{
    this->patient.setName(patientName);
    this->patient.setContactNo(contactNo);
    this->patient.setAge(age);
    this->appointmentTime = time;
}

void Appointment::displayAppointment()
{
    cout << "  Patient Name : " << this->patient.getName() << endl;
    cout << "  Contact No.  : " << this->patient.getContactNo() << endl;
    cout << "  Age          : " << this->patient.getAge() << endl;
    cout << "  Time Booked  : " << this->appointmentTime << endl;
    this->doctor.display();
}

class MedicalStore
{
private:
    Medicine *medicinesArray;
    Appointment *appointmentsArray;

    int medicineCount;
    int medicineCapacity;

    int appointmentCount;
    int appointmentCapacity;

    double totalRevenue;
    string fileName;

    Admin admin;

    void growMedicinesArray();

    string toUpper(string str);

    // created a function for getting valid time form user in 24 hrs format
    bool isValidTime(string time);

public:
    MedicalStore();
    ~MedicalStore();

    void saveToFile();
    void loadFromFile();

    void addMedicine();
    void viewAllStock();
    void viewTotalRevenue();
    void viewAppointments();

    void searchAndBuyMedicine();
    void bookAppointment();

    void adminMenu();
    void customerMenu();
    void mainMenu();
};

MedicalStore::MedicalStore()
{
    this->medicineCapacity = 10;
    this->appointmentCapacity = 10;

    this->medicinesArray = new Medicine[this->medicineCapacity];
    this->appointmentsArray = new Appointment[this->appointmentCapacity];

    this->medicineCount = 0;
    this->appointmentCount = 0;
    this->totalRevenue = 0.0;
    this->fileName = "medicines.txt";

    loadFromFile();
}

MedicalStore::~MedicalStore()
{
    saveToFile();
    delete[] this->medicinesArray;
    delete[] this->appointmentsArray;
}

void MedicalStore::growMedicinesArray()
{
    int newCapacity = this->medicineCapacity * 2;
    Medicine *newArray = new Medicine[newCapacity];

    for (int i = 0; i < this->medicineCount; i++)
    {
        newArray[i] = this->medicinesArray[i];
    }

    delete[] this->medicinesArray;
    this->medicinesArray = newArray;
    this->medicineCapacity = newCapacity;
}

// function for converting string to upper case
string MedicalStore::toUpper(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = toupper(str[i]);
    }
    return str;
}

bool MedicalStore::isValidTime(string time)
{
    if (time.length() != 5)
    {
        return false;
    }

    if (time[2] != ':')
    {
        return false;
    }

    if (!isdigit(time[0]) || !isdigit(time[1]) ||
        !isdigit(time[3]) || !isdigit(time[4]))
    {
        return false;
    }

    // Subtract '0' converts a digit character to its integer value
    int hours = (time[0] - '0') * 10 + (time[1] - '0');
    int minutes = (time[3] - '0') * 10 + (time[4] - '0');

    if (hours < 0 || hours > 23)
    {
        return false;
    }
    if (minutes < 0 || minutes > 59)
    {
        return false;
    }

    return true;
}

void MedicalStore::saveToFile()
{
    ofstream outFile;
    outFile.open(this->fileName);

    if (outFile.is_open())
    {
        outFile << this->medicineCount << endl;

        for (int i = 0; i < this->medicineCount; i++)
        {
            outFile << this->medicinesArray[i].getMedicineName() << "|" << this->medicinesArray[i].getMedicinePrice() << "|" << this->medicinesArray[i].getMedicineQuantity() << endl;
        }

        outFile.close();
    }
}

void MedicalStore::loadFromFile()
{
    ifstream inFile;
    inFile.open(this->fileName);

    if (inFile.is_open())
    {
        inFile >> this->medicineCount;
        inFile.ignore();

        while (this->medicineCount > this->medicineCapacity)
        {
            growMedicinesArray();
        }

        for (int i = 0; i < this->medicineCount; i++)
        {
            string line;
            getline(inFile, line);

            try
            {
                // used predefined find functions for finding position of  '|'
                int firstBar = line.find('|');
                int secondBar = line.find('|', firstBar + 1);

                // used substr function to divide and assign whole string into respective variables
                string name = line.substr(0, firstBar);
                string priceStr = line.substr(firstBar + 1, secondBar - firstBar - 1);
                string qtyStr = line.substr(secondBar + 1);

                // these two lines can throw exceptions  that's why they are inside try block
                double price = stod(priceStr); // throws if priceStr is not a number
                int quantity = stoi(qtyStr);   // throws if qtyStr is not a number

                this->medicinesArray[i].setMedicineName(name);
                this->medicinesArray[i].setMedicinePrice(price);
                this->medicinesArray[i].setMedicineQuantity(quantity);
            }
            catch (exception &e)
            {
                // 'e.what()' gives the error message from the exception
                cout << RED << "  WARNING: Corrupted data skipped in file. (" << e.what() << ")" << RESET << endl;
                this->medicineCount--; // one less medicine loaded since this one failed
            }
        }

        inFile.close();
        cout << GREEN << "  [Data loaded from file successfully!]" << RESET << endl;
    }
    else
    {
        cout << YELLOW << "  [No saved data found. Starting fresh.]" << RESET << endl;
    }
}

void MedicalStore::addMedicine()
{
    if (this->medicineCount >= this->medicineCapacity)
    {
        growMedicinesArray();
    }

    cout << CYAN << "\n::::::::::ADD NEW MEDICINE::::::::::" << RESET << endl;

    string name;
    double price;
    int quantity;

    cout << "  Enter Medicine Name     : ";
    cin.ignore();
    getline(cin, name);

    // Convert to uppercase before storing so all names are uniform
    name = toUpper(name);

    cout << "  Enter Price (Rs.)       : ";
    cin >> price;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << RED << "  Invalid input! Please enter a number: " << RESET;
        cin >> price;
    }

    cout << "  Enter Quantity in Stock : ";
    quantity = getIntInput();

    if (price < 0 || quantity < 0)
    {
        cout << RED << "  ERROR: Price and quantity cannot be negative!" << RESET << endl;
        return;
    }

    this->medicinesArray[this->medicineCount].setMedicineName(name);
    this->medicinesArray[this->medicineCount].setMedicinePrice(price);
    this->medicinesArray[this->medicineCount].setMedicineQuantity(quantity);

    this->medicineCount++;

    cout << GREEN << "  Medicine added successfully!" << RESET << endl;

    saveToFile();
}

void MedicalStore::viewAllStock()
{
    cout << CYAN << "\n::::::::::ALL MEDICINES IN STOCK::::::::::" << RESET << endl;

    if (this->medicineCount == 0)
    {
        cout << YELLOW << "  No medicines in the store yet." << RESET << endl;
        return;
    }

    for (int i = 0; i < this->medicineCount; i++)
    {
        cout << MAGENTA << "\n  Medicine #" << (i + 1) << ":" << RESET << endl;
        this->medicinesArray[i].displayMedicine();
        cout << "  ----------------------------" << endl;
    }

    cout << YELLOW << "  [Total Units Sold So Far: "
         << Medicine::getTotalMedicinesSold() << "]" << RESET << endl;
}

void MedicalStore::viewTotalRevenue()
{
    cout << CYAN << "\n::::::::::TOTAL REVENUE::::::::::" << RESET << endl;
    cout << GREEN << "  Total Earnings : Rs./ " << this->totalRevenue << RESET << endl;
    cout << GREEN << "  Total Units Sold : " << Medicine::getTotalMedicinesSold() << RESET << endl;
}

void MedicalStore::viewAppointments()
{
    cout << CYAN << "\n::::::::::ALL APPOINTMENTS::::::::::" << RESET << endl;

    if (this->appointmentCount == 0)
    {
        cout << YELLOW << "  No appointments booked yet." << RESET << endl;
        return;
    }

    for (int i = 0; i < this->appointmentCount; i++)
    {
        cout << MAGENTA << "\n  Appointment #" << (i + 1) << ":" << RESET << endl;
        this->appointmentsArray[i].displayAppointment();
        cout << "  ----------------------------" << endl;
    }
}

void MedicalStore::searchAndBuyMedicine()
{
    cout << CYAN << "\n::::::::::BUY MEDICINE::::::::::" << RESET << endl;

    if (this->medicineCount == 0)
    {
        cout << YELLOW << "  No medicines available in the store." << RESET << endl;
        return;
    }

    cout << "  Enter Medicine Name (IN CAPITALS) : ";
    string searchName;
    cin.ignore();
    getline(cin, searchName);

    searchName = toUpper(searchName);

    // initialized index variable with -1 if not matched with index then same -1 will remain and used in condition
    int foundIndex = -1;
    for (int i = 0; i < this->medicineCount; i++)
    {
        if (this->medicinesArray[i].getMedicineName() == searchName)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1)
    {
        cout << RED << "  Medicine '" << searchName << "' not found in store." << RESET << endl;
        return;
    }

    cout << GREEN << "\n  Medicine Found:" << RESET << endl;
    this->medicinesArray[foundIndex].displayMedicine();

    if (this->medicinesArray[foundIndex].getMedicineQuantity() == 0)
    {
        cout << RED << "  Sorry, this medicine is OUT OF STOCK." << RESET << endl;
        return;
    }

    cout << "  Enter Quantity to Buy : ";
    int qty = getIntInput();

    if (qty <= 0)
    {
        cout << RED << "  ERROR: Quantity must be greater than zero!" << RESET << endl;
        return;
    }

    if (qty > this->medicinesArray[foundIndex].getMedicineQuantity())
    {
        cout << RED << "  ERROR: Not enough stock! Available: "
             << this->medicinesArray[foundIndex].getMedicineQuantity() << " units" << RESET << endl;
        return;
    }

    double cost = qty * this->medicinesArray[foundIndex].getMedicinePrice();

    this->medicinesArray[foundIndex].reduceQuantity(qty);
    this->totalRevenue = this->totalRevenue + cost;

    cout << GREEN << "\n::::::::::Purchase Successful!::::::::::" << RESET << endl;
    cout << "  Medicine  : " << this->medicinesArray[foundIndex].getMedicineName() << endl;
    cout << "  Quantity  : " << qty << " units" << endl;
    cout << "  Total Bill: Rs. " << cost << endl;

    saveToFile();
}

void MedicalStore::bookAppointment()
{
    cout << CYAN << "\n::::::::::BOOK DOCTOR APPOINTMENT::::::::::" << RESET << endl;

    if (this->appointmentCount >= this->appointmentCapacity)
    {
        cout << RED << "  ERROR: Appointment slots are full!" << RESET << endl;
        return;
    }

    string patientName;
    string contactNo;
    string time;
    int age;

    cin.ignore();

    cout << "  Enter Your Name       : ";
    getline(cin, patientName);

    cout << "  Enter Contact Number  : ";
    getline(cin, contactNo);

    cout << "  Enter Your Age        : ";
    age = getIntInput();

    // this do while loop will Keep asking until user enters a valid 24 hrr time
    do
    {
        cout << "  Enter Preferred Time (24-hr format HH:MM, e.g. 14:30) : ";
        getline(cin, time);

        if (!isValidTime(time))
        {
            cout << RED << "  ERROR: Invalid time! Use HH:MM format (00:00 to 23:59)." << RESET << endl;
        }

    } while (!isValidTime(time));

    this->appointmentsArray[this->appointmentCount].setAppointment(patientName, contactNo, age, time);
    this->appointmentCount++;

    cout << GREEN << "\n  Appointment Booked Successfully!" << RESET << endl;
    cout << "  Doctor: Dr.Javeria Hussain (General Physician)" << endl;
    cout << "  Time  : " << time << endl;
}

void MedicalStore::adminMenu()
{
    int choice;

    do
    {
        cout << BOLD << CYAN;
        cout << "\n========================================" << endl;
        cout << "          ADMIN MENU (Store Owner)     " << endl;
        cout << "========================================" << RESET << endl;
        cout << "  1. Add New Medicine" << endl;
        cout << "  2. View All Stock" << endl;
        cout << "  3. View Total Revenue" << endl;
        cout << "  4. View All Appointments" << endl;
        cout << "  5. Back to Main Menu" << endl;
        cout << BOLD << CYAN;
        cout << "========================================" << RESET << endl;
        cout << "  Enter your choice: ";
        choice = getIntInput();

        if (choice == 1)
        {
            addMedicine();
        }
        else if (choice == 2)
        {
            viewAllStock();
        }
        else if (choice == 3)
        {
            viewTotalRevenue();
        }
        else if (choice == 4)
        {
            viewAppointments();
        }
        else if (choice == 5)
        {
            cout << YELLOW << "  Going back to Main Menu..." << RESET << endl;
        }
        else
        {
            cout << RED << "  Invalid choice! Please enter 1 to 5." << RESET << endl;
        }

    } while (choice != 5);
}

void MedicalStore::customerMenu()
{
    int choice;

    do
    {
        cout << BOLD << GREEN;
        cout << "\n========================================" << endl;
        cout << "           CUSTOMER MENU               " << endl;
        cout << "========================================" << RESET << endl;
        cout << "  1. Search and Buy Medicine" << endl;
        cout << "  2. Book Doctor Appointment" << endl;
        cout << "  3. Back to Main Menu" << endl;
        cout << BOLD << GREEN;
        cout << "========================================" << RESET << endl;
        cout << "  Enter your choice: ";
        choice = getIntInput();

        if (choice == 1)
        {
            searchAndBuyMedicine();
        }
        else if (choice == 2)
        {
            bookAppointment();
        }
        else if (choice == 3)
        {
            cout << YELLOW << "  Going back to Main Menu..." << RESET << endl;
        }
        else
        {
            cout << RED << "  Invalid choice! Please enter 1 to 3." << RESET << endl;
        }

    } while (choice != 3);
}

void MedicalStore::mainMenu()
{
    int choice;

    do
    {
        cout << BOLD << MAGENTA;
        cout << "\n========================================" << endl;
        cout << "    MEDICAL STORE MANAGEMENT SYSTEM    " << endl;
        cout << "========================================" << RESET << endl;
        cout << "  1. Login as Admin (Store Owner)" << endl;
        cout << "  2. Continue as Customer" << endl;
        cout << "  3. Exit Program" << endl;
        cout << BOLD << MAGENTA;
        cout << "========================================" << RESET << endl;
        cout << "  Enter your choice: ";
        choice = getIntInput();

        if (choice == 1)
        {
            string password;
            cout << "\n  Enter Admin Password: ";
            cin >> password;

            if (this->admin.checkPassword(password))
            {
                cout << GREEN << "  Access Granted! Welcome, Admin." << RESET << endl;
                adminMenu();
            }
            else
            {
                cout << RED << "  ERROR: Incorrect password!" << RESET << endl;
            }
        }
        else if (choice == 2)
        {
            cout << GREEN << "::::::::::Welcome, Customer!::::::::::" << RESET << endl;
            customerMenu();
        }
        else if (choice == 3)
        {
            cout << YELLOW << "\n  Saving data and exiting..." << RESET << endl;
            cout << GREEN << "  Thank you for using Medical Store System!" << RESET << endl;
        }
        else
        {
            cout << RED << "  Invalid choice! Please enter 1, 2, or 3." << RESET << endl;
        }

    } while (choice != 3);
}

int main()
{
    cout << BOLD << MAGENTA;
    cout << "========================================" << endl;
    cout << "   WELCOME TO MEDICAL STORE SYSTEM     " << endl;
    cout << "   Initializing system...               " << endl;
    cout << "========================================" << RESET << endl;

    MedicalStore store;

    store.mainMenu();

    return 0;
}