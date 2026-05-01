#include <stdio.h>


typedef struct 
{
    char id[20];
    char name[20];
    float salary;
}Employee;


int main(void)
{
    Employee emp[100];
    Employee temp[100];
    int n;
    printf("Enter the number the employee\n");
    scanf("%d",&n);
    printf("Enter the id, name and salary for employee\n");
    for(int i=0;i<n;i++)
    {
        scanf("%s %s %f",emp[i].id,emp[i].name,&emp[i].salary);
    }

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(emp[j].salary < emp[j+1].salary)
            {
                temp[j].salary = emp[j].salary;
                emp[j].salary = emp[j+1].salary;
                emp[j+1].salary = temp[j].salary;
            }
        }
    }

    printf("The employee is sorted salary decrease\n");
    for(int i=0;i<n;i++)
    {
        printf("%s %s %.2f\n",emp[i].id,emp[i].name,emp[i].salary);
    }
    return 0;
}