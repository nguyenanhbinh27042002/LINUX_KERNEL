#include <stdio.h>


typedef struct StudentStr
{
  char id[20];
  char nameStudent[20];
  float gpa;
}Student;

int main(void)
{
    int N; 
    Student student[20];
    printf("Enter the number\n");
    scanf("%d",&N);
    for(int i=0 ; i<N;i++)
    {
        printf("Enter the information student\n");
        scanf("%s %s %f",student[i].id, student[i].nameStudent,&student[i].gpa);
    }

    printf("Student list \n");
    for(int i=0;i<N;i++)
    {
        printf("%s %s %.2f\n",student[i].id,student[i].nameStudent,student[i].gpa);
    }
    return 0;
}