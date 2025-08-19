#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // For std::setw, std::left, etc.
#include <vector>

const char* FILENAME = "students.dat";

// Structure to hold student data
struct Student {
    int roll;
    char name[50];
    float marks;
};

// Function prototypes
void addRecord();
void displayRecords();
void searchRecord();
void updateRecord();
void showMenu();

// Helper function to read all records from the file
std::vector<Student> readAllRecords() {
    std::vector<Student> records;
    std::ifstream inFile(FILENAME, std::ios::in | std::ios::binary);
    
    if (!inFile) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return records; // Return empty vector if file can't be read
    }
    
    Student s;
    while (inFile.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        records.push_back(s);
    }
    
    inFile.close();
    return records;
}

// Helper function to write all records to the file
void writeAllRecords(const std::vector<Student>& records) {
    std::ofstream outFile(FILENAME, std::ios::out | std::ios::binary);
    
    if (!outFile) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return;
    }
    
    for (const auto& s : records) {
        outFile.write(reinterpret_cast<const char*>(&s), sizeof(Student));
    }
    
    outFile.close();
}

int main() {
    int choice;
    do {
        showMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                updateRecord();
                break;
            case 5:
                std::cout << "Exiting program. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
        std::cout << std::endl;
    } while (choice != 5);

    return 0;
}

void showMenu() {
    std::cout << "--- Student Record Management ---\n";
    std::cout << "1. Add a new record\n";
    std::cout << "2. Display all records\n";
    std::cout << "3. Search for a student by roll number\n";
    std::cout << "4. Update marks of a student\n";
    std::cout << "5. Exit\n";
    std::cout << "---------------------------------\n";
}

void addRecord() {
    Student s;
    std::cout << "Enter Roll Number: ";
    std::cin >> s.roll;
    std::cout << "Enter Name: ";
    std::cin.ignore(); // Consume the newline character left by std::cin
    std::cin.getline(s.name, 50);
    std::cout << "Enter Marks: ";
    std::cin >> s.marks;

    std::vector<Student> records = readAllRecords();
    records.push_back(s);
    writeAllRecords(records);
    
    std::cout << "Record added successfully." << std::endl;
}

void displayRecords() {
    std::vector<Student> records = readAllRecords();
    
    if (records.empty()) {
        std::cout << "No records to display." << std::endl;
        return;
    }
    
    std::cout << "\n--- Student Records ---\n";
    std::cout << std::left << std::setw(10) << "Roll No."
              << std::setw(30) << "Name"
              << std::setw(10) << "Marks" << std::endl;
    std::cout << "--------------------------------------------------\n";

    for (const auto& s : records) {
        std::cout << std::left << std::setw(10) << s.roll
                  << std::setw(30) << s.name
                  << std::setw(10) << std::fixed << std::setprecision(2) << s.marks << std::endl;
    }
}

void searchRecord() {
    int rollNum;
    std::cout << "Enter Roll Number to search: ";
    std::cin >> rollNum;

    std::vector<Student> records = readAllRecords();
    bool found = false;

    for (const auto& s : records) {
        if (s.roll == rollNum) {
            std::cout << "\n--- Record Found ---\n";
            std::cout << "Roll Number: " << s.roll << std::endl;
            std::cout << "Name: " << s.name << std::endl;
            std::cout << "Marks: " << std::fixed << std::setprecision(2) << s.marks << std::endl;
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Student with Roll Number " << rollNum << " not found." << std::endl;
    }
}

void updateRecord() {
    int rollNum;
    std::cout << "Enter Roll Number to update marks: ";
    std::cin >> rollNum;

    std::vector<Student> records = readAllRecords();
    bool found = false;

    for (auto& s : records) {
        if (s.roll == rollNum) {
            std::cout << "Record Found. Current Marks: " << s.marks << std::endl;
            std::cout << "Enter new marks: ";
            std::cin >> s.marks;
            found = true;
            break;
        }
    }

    if (found) {
        writeAllRecords(records);
        std::cout << "Record updated successfully." << std::endl;
    } else {
        std::cout << "Student with Roll Number " << rollNum << " not found." << std::endl;
    }
}
