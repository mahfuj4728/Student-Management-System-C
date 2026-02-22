/*
--------------------------------------------------------
Project Title : Student Management System
Course        : Programming and Problem Solving Lab
Semester      : Fall 2022
Author        : Md Mahfuj Hossain
--------------------------------------------------------
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int id;
    char name[50];
    float cgpa;
};

struct Student students[MAX];
int totalStudents = 0;

void addStudent();
void viewStudents();
void searchStudent();
void deleteStudent();

int main() {

    int choice;

    while (1) {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addStudent();
                break;

            case 2:
                viewStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

void addStudent() {

    if (totalStudents >= MAX) {
        printf("Student list is full!\n");
        return;
    }

    printf("\nEnter Student ID: ");
    scanf("%d", &students[totalStudents].id);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", students[totalStudents].name);

    printf("Enter CGPA: ");
    scanf("%f", &students[totalStudents].cgpa);

    totalStudents++;

    printf("Student added successfully!\n");
}

void viewStudents() {

    int i;

    if (totalStudents == 0) {
        printf("No students found!\n");
        return;
    }

    printf("\n----- Student List -----\n");

    for (i = 0; i < totalStudents; i++) {

        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("CGPA: %.2f\n", students[i].cgpa);
        printf("------------------------\n");
    }
}

void searchStudent() {

    int searchId;
    int found = 0;
    int i;

    printf("\nEnter Student ID to search: ");
    scanf("%d", &searchId);

    for (i = 0; i < totalStudents; i++) {

        if (students[i].id == searchId) {

            printf("\nStudent Found!\n");
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("CGPA: %.2f\n", students[i].cgpa);

            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Student not found!\n");
    }
}

void deleteStudent() {

    int deleteId;
    int found = 0;
    int i, j;

    printf("\nEnter Student ID to delete: ");
    scanf("%d", &deleteId);

    for (i = 0; i < totalStudents; i++) {

        if (students[i].id == deleteId) {

            for (j = i; j < totalStudents - 1; j++) {
                students[j] = students[j + 1];
            }

            totalStudents--;
            found = 1;
            printf("Student deleted successfully!\n");
            break;
        }
    }

    if (found == 0) {
        printf("Student not found!\n");
    }
}