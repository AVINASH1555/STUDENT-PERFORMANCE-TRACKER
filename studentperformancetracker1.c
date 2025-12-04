#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    int marks[5];
    int total;
    float percentage;
    char grade;
};

void calculate(struct Student *s) {
    s->total = 0;

    for (int i = 0; i < 5; i++) {
        s->total += s->marks[i];
    }

    s->percentage = s->total / 5.0;

    if (s->percentage >= 90) s->grade = 'A';
    else if (s->percentage >= 75) s->grade = 'B';
    else if (s->percentage >= 60) s->grade = 'C';
    else if (s->percentage >= 40) s->grade = 'D';
    else s->grade = 'F';
}

void addStudent(struct Student s[], int *n) {
    printf("\nEnter Roll Number: ");
    scanf("%d", &s[*n].roll);

    getchar();   // Clear input buffer before reading name
    printf("Enter Name: ");
    fgets(s[*n].name, sizeof(s[*n].name), stdin);
    s[*n].name[strcspn(s[*n].name, "\n")] = '\0';  // remove newline

    printf("Enter marks of 5 subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &s[*n].marks[i]);
    }

    calculate(&s[*n]);
    (*n)++;

    printf("\nStudent record added successfully!\n");
}

void displayAll(struct Student s[], int n) {
    if (n == 0) {
        printf("\nNo records available.\n");
        return;
    }

    printf("\n----- Student Performance Records -----\n");
    for (int i = 0; i < n; i++) {
        printf("\nRoll: %d\nName: %s\nTotal: %d\nPercentage: %.2f\nGrade: %c\n",
               s[i].roll, s[i].name, s[i].total, s[i].percentage, s[i].grade);
    }
}

void searchStudent(struct Student s[], int n) {
    int roll;
    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll);

    for (int i = 0; i < n; i++) {
        if (s[i].roll == roll) {
            printf("\nRecord Found:\n");
            printf("Roll: %d\nName: %s\nTotal: %d\nPercentage: %.2f\nGrade: %c\n",
                   s[i].roll, s[i].name, s[i].total, s[i].percentage, s[i].grade);
            return;
        }
    }
    printf("No student found with this roll number.\n");
}

int main() {
    struct Student s[100];
    int n = 0, choice;

    while (1) {
        printf("\n===== Student Performance Tracker =====\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(s, &n); break;
            case 2: displayAll(s, n); break;
            case 3: searchStudent(s, n); break;
            case 4: printf("Exiting...\n"); return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}
