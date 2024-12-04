#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100  // Define a maximum number of students

struct record {
    char first_name[40];
    char last_name[40];
    char course[30];
    int sapid;
    char gender[10];
    char contact_number[15];
};

int main() {
    int students;

    // Ask for the number of students
    printf("Enter the number of Students (max %d): ", MAX_STUDENTS);
    scanf("%d", &students);
    getchar();  // Consume the newline left by scanf

    // Validate the number of students
    if (students > MAX_STUDENTS) {
        printf("Number of students exceeds the maximum allowed (%d).\n", MAX_STUDENTS);
        return 1;
    }

    // Declare a statically allocated array of struct records
    struct record arr[MAX_STUDENTS];

    // Collect information for each student
    for (int i = 0; i < students; i++) {
        printf("\nEntering record for student %d:\n", i + 1);

        // Read first name
        printf("Enter First Name: ");
        fgets(arr[i].first_name, sizeof(arr[i].first_name), stdin);
        arr[i].first_name[strcspn(arr[i].first_name, "\n")] = '\0'; 

        // Read last name
        printf("Enter Last Name: ");
        fgets(arr[i].last_name, sizeof(arr[i].last_name), stdin);
        arr[i].last_name[strcspn(arr[i].last_name, "\n")] = '\0'; 

        // Read course name
        printf("Enter Course: ");
        fgets(arr[i].course, sizeof(arr[i].course), stdin);
        arr[i].course[strcspn(arr[i].course, "\n")] = '\0';  

        // Read SAP ID
        printf("Enter SAPID: ");
        scanf("%d", &arr[i].sapid);
        getchar(); 

        // Read gender
        printf("Enter Gender: ");
        fgets(arr[i].gender, sizeof(arr[i].gender), stdin);
        arr[i].gender[strcspn(arr[i].gender, "\n")] = '\0'; 

        // Read contact number
        printf("Enter Contact Number: ");
        fgets(arr[i].contact_number, sizeof(arr[i].contact_number), stdin);
        arr[i].contact_number[strcspn(arr[i].contact_number, "\n")] = '\0'; 
    }

    // Display student records in a table format
    printf("\nSTUDENT RECORDS:\n");
    printf("----------------------------------------------------------------------------------------\n");
    printf("| %-15s | %-15s | %-15s | %-10s | %-5s | %-15s |\n", 
           "First Name", "Last Name", "Course", "Gender", "SAPID", "Contact Number");
    printf("----------------------------------------------------------------------------------------\n");

    for (int i = 0; i < students; i++) {
        printf("| %-15s | %-15s | %-15s | %-10s | %-5d | %-15s |\n", 
               arr[i].first_name, arr[i].last_name, arr[i].course, arr[i].gender, arr[i].sapid, arr[i].contact_number);
    }
    printf("----------------------------------------------------------------------------------------\n");

    return 0;
}
