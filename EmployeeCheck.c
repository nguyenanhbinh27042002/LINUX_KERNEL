#include <stdio.h>

typedef struct Employee
{
    char id[20];
    char name[20];
    int salary;
}Employee;

int main(void)
{
    Employee Employee[100];
    int n;
    printf("Enter the number employee\n");
    scanf("%d",&n);
    printf("Enter the information employee: id, name , salary\n");
    for(int i=0;i<n;i++)
    {
        scanf("%s %s %d",Employee[i].id,Employee[i].name,&Employee[i].salary);
    }
    float maxValue = Employee[0].salary;
    for(int i=1;i<n;i++)
    {
        maxValue = (maxValue > Employee[i].salary) ? maxValue : Employee[i].salary;
        printf("Employee id, name and salary decrease:%s %s %.2f\n",Employee[i].id,Employee[i].name,maxValue);
    }

    return 0;
}