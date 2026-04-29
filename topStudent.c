#include <stdio.h>

typedef struct topStudent
{
    char id[20];
    char nameStudent[20];
    float gpa;
}topStudent;


int main(void)
{
    int N;
    printf("Enter the number of student\n");
    scanf("%d",&N);
    topStudent student[200];
    printf("Enter the information student such as: id, name , gpa\n");
    for(int i=0;i<N;i++)
    {
        scanf("%s %s %f",student[i].id,student[i].nameStudent,&student[i].gpa);
    }
    float maxValue = student[0].gpa;
    for(int i=0;i<N;i++)
    {
        maxValue = (maxValue > student[i].gpa) ? maxValue : student[i].gpa;
    }
    printf("Max gpa top student :%.2f\n",maxValue);
    return 0;
}