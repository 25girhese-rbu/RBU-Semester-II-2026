//que11: Student Management System in C using Structures.
#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    char course[50];
    float marks;
};

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct Student students[n];
    for(int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i+1);
        printf("Roll Number: ");
        scanf("%d", &students[i].roll);
        printf("Name: ");
        scanf(" %[^\n]", students[i].name);
        printf("Course: ");
        scanf(" %[^\n]", students[i].course);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }
    printf("\nStudent Records:\n");
    printf("Roll\tName\t\tCourse\t\tMarks\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%s\t\t%s\t\t%.2f\n", students[i].roll, students[i].name, students[i].course, students[i].marks);
    }
    return 0;
}