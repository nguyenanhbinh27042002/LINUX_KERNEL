#include <stdio.h>

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
    return (*a == '\0' && *b == '\0') ? 1 : 0;
}

typedef struct
{
    char id[100];
    char name[100];
    float gpa;
}Student;

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
    printf("Enter the information such as;id, name and gpa\n");
    for(int i=0;i<n;i++)
    {
        scanf("%s %s %f",student[i].id,student[i].name,&student[i].gpa);
    }

    printf("Enter the id\n");
    char targetID[100];
    scanf("%s",targetID);
    float newGPA;
    printf("Enter the newGPA\n");
    scanf("%f",&newGPA);
    
    for(int i=0;i<n;i++)
    {
        if(compare(student[i].id,targetID))
        {
            updateGPA(&student[i],newGPA);
        }
    }
    printf("GPA after updated\n");
    for(int i=0;i<n;i++)
    {
        printf("%s %s %f\n",student[i].id,student[i].name,student[i].gpa);
    }
    return 0;
}