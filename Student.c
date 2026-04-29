#include <stdio.h>


typedef struct Student_str
{
    char id[20]; 
    char nameStudent[20];
    float gpa;
}Student;

int main(void)
{
    Student student[20];
    int N;
    printf("Enter the number student \n");
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        printf("Enter the string value id, name student , gpa\n");
        scanf("%s %s %f",student[i].id, student[i].nameStudent, &student[i].gpa);

    }
    printf("\nStudent list\n");
    for(int i=0;i<N;i++)
    {
        printf("%s %s %f\n",student[i].id,student[i].nameStudent,student[i].gpa);
    }
    
    return 0;
}