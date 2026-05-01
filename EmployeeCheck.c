#include <stdio.h>

typedef struct Employee
{
    char id[20];
    char name[20];
    int salary;
}Employee;

int main(void)
{
    Employee emp[100];
    Employee temp;
    int n;
    printf("Enter the number employee\n");
    scanf("%d",&n);
    printf("Enter the information employee: id, name , salary\n");
    for(int i=0;i<n;i++)
    {
        scanf("%s %s %d",emp[i].id,emp[i].name,&emp[i].salary);
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(emp[j].salary < emp[j+1].salary)
            {
                temp = emp[j];
                emp[j] = emp[j+1];
                emp[j+1] = temp;
            }   
        }
    }

    printf("The employee is sorted \n");
    for(int i=0;i<n;i++)
    {
        printf("%s %d\n",emp[i].name,emp[i].salary);
    }
    return 0;
}