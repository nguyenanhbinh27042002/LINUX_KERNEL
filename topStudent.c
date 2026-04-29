#include <stdio.h>

typedef struct topStudent
{
    char id[20];
    char namStudent[20];
    float gpa;
}topStudent;

int main(void)
{
    topStudent student[20];
    float maxValue ; 

    int N;
    printf("Enter the number value student\n");
    scanf("%d",&N);
    printf("Enter the information student\n");
    for(int i=0;i<N;i++)
    {
        scanf("%s %s %f",student[i].id,student[i].namStudent,&student[i].gpa);
    }
    maxValue = student[0].gpa;
    for(int i=0;i<N;i++)
    {
        maxValue = (maxValue > student[i].gpa) ? maxValue : student[i].gpa;
    }
    printf("The student is maxvalue :%f\n",maxValue);
    return 0;
}