
// write a program where a function updates the salary of an employee using pointer
// to store structure
#include <stdio.h>
#include <string.h>

// Define the structure for an employee
struct Employee {
    char name[50];
    int id;
    float salary;
};

// Function to update the salary using a pointer to the structure
void updateSalary(struct Employee *emp, float newSalary) {
    if (emp != NULL) {
        emp->salary = newSalary;
    }
}

int main() {
    // Create an instance of the Employee structure
    struct Employee emp1;

    // Initialize the employee's details
    strcpy(emp1.name, "Bhusan kumar");
    emp1.id = 101;
    emp1.salary = 50000.0f;

    // Print the initial salary
    printf("Employee Name: %s\n", emp1.name);
    printf("Employee ID: %d\n", emp1.id);
    printf("Initial Salary: %.2f\n", emp1.salary);

    // New salary to be updated
    float newSalary = 60000.0f;
    printf("\nUpdating salary to %.2f...\n\n", newSalary);

    // Call the function to update the salary
    // We pass the address of the structure variable
    updateSalary(&emp1, newSalary);

    // Print the updated salary
    printf("Updated Details:\n");
    printf("Employee Name: %s\n", emp1.name);
    printf("Employee ID: %d\n", emp1.id);
    printf("Updated Salary: %.2f\n", emp1.salary);

    return 0;
}
/*
Employee Name: Bhusan Kumar
Employee ID: 101
Initial Salary: 50000.00

Updating salary to 60000.00...

Updated Details:
Employee Name: Bhusan kumar
Employee ID: 101
Updated Salary: 60000.00

*/
