/*
Write a c program to store details of 3 books using an array of structures and pointer.

*/
#include <stdio.h>

// Define the structure for a book
struct Book {
    char title[100];
    char author[100];
    float price;
};

int main() {
    // Declare an array of 3 Book structures
    struct Book books[3];

    // Declare a pointer of type 'struct Book' and point it to the start of the array
    struct Book *ptr = books;

    // --- Input Section ---
    printf("--- Enter Details for 3 Books ---\n");
    for (int i = 0; i < 3; i++) {
        printf("\nEnter details for Book %d:\n", i + 1);

        // Use the pointer to access the current structure element
        // (ptr + i) points to the i-th element of the array.
        // We use the -> operator to access members via the pointer.

        printf("  Title: ");
        // Read a string that can include spaces. The " %[^\n]" format specifier
        // consumes any leading whitespace and then reads until a newline is found.
        scanf(" %[^\n]%*c", (ptr + i)->title);

        printf("  Author: ");
        scanf(" %[^\n]%*c", (ptr + i)->author);

        printf("  Price: ");
        scanf("%f", &(ptr + i)->price);
    }

    // --- Output Section ---
    printf("\n\n--- Displaying Book Details ---\n");
    for (int i = 0; i < 3; i++) {
        printf("\nDetails of Book %d:\n", i + 1);

        // Use the pointer to access and print the details
        printf("  Title: %s\n", (ptr + i)->title);
        printf("  Author: %s\n", (ptr + i)->author);
        printf("  Price: %.2f\n", (ptr + i)->price);
    }

    return 0;
}

/*
--- Enter Details for 3 Books ---

Enter details for Book 1:
  Title: ATOMIC HABITS
  Author: JHON ALLIE
  Price: 999

Enter details for Book 2:
  Title: THINK AND GROW RICH
  Author: NEPOLEAN HILL
  Price: 400

Enter details for Book 3:
  Title: PSYCHOLOGY OF MONEY 
  Author: CRISTOPHER NOLAN
  Price: 699  


--- Displaying Book Details ---

Details of Book 1:
  Title: ATOMIC HABITS
  Author: JHON ALLIE
  Price: 999.00

Details of Book 2:
  Title: THINK AND GROW RICH
  Author: NEPOLEAN HILL
  Price: 400.00

Details of Book 3:
  Title: PSYCHOLOGY OF MONEY 
  Author: CRISTOPHER NOLAN
  Price: 699.00

*/
