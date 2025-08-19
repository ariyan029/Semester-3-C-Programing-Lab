/*
Write a c program to store and display information about a list of courses  
where each course has a subject name and corresponding marks. The number of 
courses should be taken as input from the user . Dynamically allocate memeory 
for storing the records usnig malloc. Accept subject name and marks for each record
from the user. Display the stored information.Finally, release the allocated 
memeory using free.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char subject[100];
    int marks;
} Course;

int main() {
    int n;
    printf("Enter the number of courses: ");
    scanf("%d", &n);

    Course *courses = (Course *)malloc(n * sizeof(Course));
    if (courses == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter subject name for course %d: ", i + 1);
        scanf(" %[^\n]", courses[i].subject);
        printf("Enter marks for course %d: ", i + 1);
        scanf("%d", &courses[i].marks);
    }

    printf("\nStored Course Information:\n");
    for (int i = 0; i < n; i++) {
        printf("Course %d: Subject: %s, Marks: %d\n", i + 1, courses[i].subject, courses[i].marks);
    }

    free(courses);
    return 0;
}
/*
Enter the number of courses: 4
Enter subject name for course 1: physics
Enter marks for course 1: 45  
Enter subject name for course 2: math
Enter marks for course 2: 100
Enter subject name for course 3: chemistry
Enter marks for course 3: 76
Enter subject name for course 4: biology
Enter marks for course 4: 98

Stored Course Information:
Course 1: Subject: physics, Marks: 45
Course 2: Subject: math, Marks: 100
Course 3: Subject: chemistry, Marks: 76
Course 4: Subject: biology, Marks: 98

*/