//que12: Hospital Management System in C using Structures.
#include <stdio.h>
#include <string.h>

#define MAX_PATIENTS 100

struct Patient {
    int id;
    char name[50];
    int age;
    char gender[10];
    char disease[50];
    char doctor[50];
    char admission_date[20];
};

struct Patient patients[MAX_PATIENTS];
int patient_count = 0;

void add_patient() {
    if (patient_count >= MAX_PATIENTS) {
        printf("Maximum patients reached.\n");
        return;
    }
    struct Patient p;
    printf("Enter Patient ID: ");
    scanf("%d", &p.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", p.name);
    printf("Enter Age: ");
    scanf("%d", &p.age);
    printf("Enter Gender: ");
    scanf(" %[^\n]", p.gender);
    printf("Enter Disease: ");
    scanf(" %[^\n]", p.disease);
    printf("Enter Doctor Assigned: ");
    scanf(" %[^\n]", p.doctor);
    printf("Enter Admission Date (DD/MM/YYYY): ");
    scanf(" %[^\n]", p.admission_date);
    patients[patient_count++] = p;
    printf("Patient added successfully.\n");
}

void update_patient() {
    int id;
    printf("Enter Patient ID to update: ");
    scanf("%d", &id);
    for(int i = 0; i < patient_count; i++) {
        if (patients[i].id == id) {
            printf("Enter new Name: ");
            scanf(" %[^\n]", patients[i].name);
            printf("Enter new Age: ");
            scanf("%d", &patients[i].age);
            printf("Enter new Gender: ");
            scanf(" %[^\n]", patients[i].gender);
            printf("Enter new Disease: ");
            scanf(" %[^\n]", patients[i].disease);
            printf("Enter new Doctor: ");
            scanf(" %[^\n]", patients[i].doctor);
            printf("Enter new Admission Date: ");
            scanf(" %[^\n]", patients[i].admission_date);
            printf("Patient updated successfully.\n");
            return;
        }
    }
    printf("Patient not found.\n");
}

void display_all() {
    if (patient_count == 0) {
        printf("No patients to display.\n");
        return;
    }
    printf("Patient Records:\n");
    printf("ID\tName\t\tAge\tGender\tDisease\t\tDoctor\t\tAdmission Date\n");
    for(int i = 0; i < patient_count; i++) {
        printf("%d\t%s\t\t%d\t%s\t%s\t\t%s\t\t%s\n", patients[i].id, patients[i].name, patients[i].age, patients[i].gender, patients[i].disease, patients[i].doctor, patients[i].admission_date);
    }
}

void display_patient() {
    int id;
    printf("Enter Patient ID to display: ");
    scanf("%d", &id);
    for(int i = 0; i < patient_count; i++) {
        if (patients[i].id == id) {
            printf("Patient Details:\n");
            printf("ID: %d\n", patients[i].id);
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Gender: %s\n", patients[i].gender);
            printf("Disease: %s\n", patients[i].disease);
            printf("Doctor: %s\n", patients[i].doctor);
            printf("Admission Date: %s\n", patients[i].admission_date);
            return;
        }
    }
    printf("Patient not found.\n");
}

int main() {
    int choice;
    while(1) {
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. Update Patient\n");
        printf("3. Display All Patients\n");
        printf("4. Display Specific Patient\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: add_patient(); break;
            case 2: update_patient(); break;
            case 3: display_all(); break;
            case 4: display_patient(); break;
            case 5: return 0;
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}