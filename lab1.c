#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student
{
    int rollNo;
    char name[50];
    float marks[5];
    float total;
    float average;
    char grade;
};

struct Student students[MAX];
int count = 0;

void addStudent()
{
    if (count >= MAX)
    {
        printf("\nStudent limit reached!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &students[count].rollNo);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", students[count].name);

    students[count].total = 0;

    for (int i = 0; i < 5; i++)
    {
        printf("Enter marks for Subject %d: ", i + 1);
        scanf("%f", &students[count].marks[i]);

        students[count].total += students[count].marks[i];
    }

    students[count].average = students[count].total / 5;

    if (students[count].average >= 90)
        students[count].grade = 'A';
    else if (students[count].average >= 80)
        students[count].grade = 'B';
    else if (students[count].average >= 70)
        students[count].grade = 'C';
    else if (students[count].average >= 60)
        students[count].grade = 'D';
    else
        students[count].grade = 'F';

    count++;

    printf("\nStudent added successfully!\n");
}

void displayStudents()
{
    if (count == 0)
    {
        printf("\nNo student records available!\n");
        return;
    }

    printf("\n========== STUDENT RECORDS ==========\n");

    for (int i = 0; i < count; i++)
    {
        printf("\nRoll Number: %d", students[i].rollNo);
        printf("\nName: %s", students[i].name);
        printf("\nTotal Marks: %.2f", students[i].total);
        printf("\nAverage: %.2f", students[i].average);
        printf("\nGrade: %c", students[i].grade);
        printf("\n-------------------------------------\n");
    }
}

void searchStudent()
{
    int roll, found = 0;

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++)
    {
        if (students[i].rollNo == roll)
        {
            printf("\nStudent Found!\n");
            printf("Name: %s\n", students[i].name);
            printf("Roll Number: %d\n", students[i].rollNo);
            printf("Average Marks: %.2f\n", students[i].average);
            printf("Grade: %c\n", students[i].grade);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nStudent not found!\n");
}

void calculateResult()
{
    if (count == 0)
    {
        printf("\nNo records available!\n");
        return;
    }

    float highest = students[0].average;
    float lowest = students[0].average;
    float totalAverage = 0;

    int topper = 0;
    int lowestStudent = 0;

    for (int i = 0; i < count; i++)
    {
        totalAverage += students[i].average;

        if (students[i].average > highest)
        {
            highest = students[i].average;
            topper = i;
        }

        if (students[i].average < lowest)
        {
            lowest = students[i].average;
            lowestStudent = i;
        }
    }

    printf("\n========== RESULT ANALYSIS ==========\n");

    printf("\nClass Average: %.2f",
           totalAverage / count);

    printf("\nTopper: %s", students[topper].name);
    printf("\nHighest Average: %.2f", highest);

    printf("\nLowest Scorer: %s",
           students[lowestStudent].name);

    printf("\nLowest Average: %.2f\n", lowest);
}

int main()
{
    int choice;

    do
    {
        printf("\n\n====================================");
        printf("\n       STUDENT MANAGEMENT SYSTEM");
        printf("\n====================================");

        printf("\n1. Add Student");
        printf("\n2. Display All Students");
        printf("\n3. Search Student");
        printf("\n4. Calculate Class Result");
        printf("\n5. Exit");

        printf("\n====================================");
        printf("\nEnter Your Choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                calculateResult();
                break;

            case 5:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid Choice! Try Again.\n");
        }

    } while (choice != 5);

    return 0;
}
