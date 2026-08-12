#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Employee {
    int id;
    char name[50];
    char designation[30];
    int experience;
    int age;
    struct Employee* next;
} Employee;

Employee* hashTable[TABLE_SIZE];

int hashFunction(int id) {
    return id % TABLE_SIZE;
}

Employee* createEmployee(int id, char* name, char* designation, int experience, int age) {
    Employee* newEmp = (Employee*)malloc(sizeof(Employee));
    newEmp->id = id;
    strcpy(newEmp->name, name);
    strcpy(newEmp->designation, designation);
    newEmp->experience = experience;
    newEmp->age = age;
    newEmp->next = NULL;
    return newEmp;
}

void insertEmployee(int id, char* name, char* designation, int experience, int age) {
    int index = hashFunction(id);
    Employee* newEmp = createEmployee(id, name, designation, experience, age);

    if (hashTable[index] == NULL) {
        hashTable[index] = newEmp;
    } else {
        Employee* temp = hashTable[index];
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newEmp;
    }

    printf("Employee inserted successfully.\n");
}

Employee* searchEmployee(int id) {
    int index = hashFunction(id);
    Employee* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->id == id)
            return temp;
        temp = temp->next;
    }

    return NULL;
}

void deleteEmployee(int id) {
    int index = hashFunction(id);
    Employee* temp = hashTable[index];
    Employee* prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Employee not found.\n");
        return;
    }

    if (prev == NULL)
        hashTable[index] = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Employee deleted successfully.\n");
}

void displayEmployees() {
    printf("\n--- All Employees ---\n");

    for (int i = 0; i < TABLE_SIZE; i++) {
        Employee* temp = hashTable[i];

        if (temp == NULL)
            continue;

        printf("Index %d:\n", i);

        while (temp != NULL) {
            printf("ID: %d, Name: %s, Designation: %s, Experience: %d, Age: %d\n",
                   temp->id, temp->name, temp->designation,
                   temp->experience, temp->age);
            temp = temp->next;
        }
    }
}

void menu() {
    int choice, id, experience, age;
    char name[50], designation[30];
    Employee* emp;

    while (1) {
        printf("\nEmployee Management System\n");
        printf("1. Insert Employee\n");
        printf("2. Search Employee\n");
        printf("3. Delete Employee\n");
        printf("4. Display All Employees\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);

                printf("Enter Name: ");
                scanf(" %[^\n]%*c", name);

                printf("Enter Designation: ");
                scanf(" %[^\n]%*c", designation);

                printf("Enter Experience (years): ");
                scanf("%d", &experience);

                printf("Enter Age: ");
                scanf("%d", &age);

                insertEmployee(id, name, designation, experience, age);
                break;

            case 2:
                printf("Enter ID to search: ");
                scanf("%d", &id);

                emp = searchEmployee(id);

                if (emp != NULL) {
                    printf("Employee found:\n");
                    printf("ID: %d, Name: %s, Designation: %s, Experience: %d, Age: %d\n",
                           emp->id, emp->name, emp->designation,
                           emp->experience, emp->age);
                } else {
                    printf("Employee not found.\n");
                }
                break;

            case 3:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteEmployee(id);
                break;

            case 4:
                displayEmployees();
                break;

            case 5:
                printf("Exiting program.\n");
                return;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

int main() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = NULL;

    menu();
    return 0;
}