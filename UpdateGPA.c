#include <stdio.h>

typedef struct
{
    char id[20];
    char name[20];
    float gpa;
}Student;


void updateGPA(Student *s, float newGPA)
{
    s->gpa = newGPA;
}

int compare(char *a, char *b)
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
    return ( *a == '\0' && *b == '\0') ? 1 : 0;
}
int main(void)
{
    int n;
    char targetID[100];
    float newGPA;
    printf("Enter the number student\n");
    scanf("%d",&n);
    Student student[100];
    printf("Enter the information student : id , name and gpa\n");
    for(int i=0;i<n;i++)
    {
        scanf("%s %s %f",student[i].id,student[i].name,&student[i].gpa);
    }
    
    printf("Enter the target ID\n");
    scanf("%s",targetID);

    printf("Enter the new GPA\n");
    scanf("%f",&newGPA);
    for(int i=0;i<n;i++)
    {
        if(compare(student[i].id, targetID))
        {
            updateGPA(&student[i],newGPA);
        }
    }
    printf("The new GPA after update\n");
    for(int i=0;i<n;i++)
    {
        printf("%s %s %.2f\n",student[i].id,student[i].name,student[i].gpa);
    }
    return 0;
}