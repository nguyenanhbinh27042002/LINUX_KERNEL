#include <stdio.h>

typedef struct 
{
    char idHouse[20];
    char nameStreet[20];
}Address;

typedef struct Person
{
    Address address;
    char id[20];
    char name[20];
    char work[20];
}Person;

int main(void)
{
    Person person[20];
    int n;
    printf("Enter the number person\n");
    scanf("%d",&n);
    printf("Information of the person\n");
    for(int i=0;i<n;i++)
    {
        scanf("%s %s %s %s %s",person[i].address.idHouse,person[i].address.nameStreet,person[i].id,person[i].name,person[i].work);
    }

    for(int i=0;i<n;i++)
    {
        printf("%s %s %s %s %s\n",person[i].address.idHouse,person[i].address.nameStreet,person[i].id,person[i].name,person[i].work);
    }
    return 0;
}