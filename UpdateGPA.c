#include <stdio.h>


typedef struct Student
{
    char id[20];
    char name[20];
    float gpa;
}Student;

int compare(char *a,char *b)
{
    while(*a && *b)
    {
        if(*a != *b)
        {
            return 0;
        }
        *a++;
        *b++;
    }
    return (*a == '\0' && *b == '\0');
}
void updateGPA(Student *s, float newGPA)
{
    s->gpa = newGPA;
}
int main(void)
{
    Student student[100];
    int n;
    printf("Enter the number student\n");
    scanf("%d",&n);
    printf("Enter number student such as: id, name and gpa\n");
    for( int i=0;i<n;i++)
    {
        scanf("%s %s %f",student[i].id, student[i].name,&student[i].gpa);
    }
    float newGPA;
    char targetID[100];
    printf("Enter the new GPA\n");
    scanf("%f",&newGPA);
    printf("GPA after update\n");
    for(int i=0;i<n;i++)
    {
        if(compare(student[i].id, targetID) == 0)
        {
            updateGPA(&student[i],newGPA);
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%s %s %f\n",student[i].id,student[i].name,student[i].gpa);
    }
    return 0;
}