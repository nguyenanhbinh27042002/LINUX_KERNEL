#include <stdio.h>


typedef struct 
{
    char name[20];
    char author[20];
    float price;
}NameBooks;

int checkString(char *a, char *b)
{
    while(*a && *b)
    {
        if(*a != *b)
        {
            return 1;
        }
        *a++;
        *b++;
    }
    return (*a == '\0' && *b == '\0') ? 0 : 1;
}

int main(void)
{   
    int N;
    NameBooks nameBooks[20];
    printf("Enter the number books\n");
    scanf("%d",&N);
    printf("Enter the name, author and price\n");
    for(int i=0;i<N;i++)
    {
        scanf("%s %s %f",nameBooks[i].name,nameBooks[i].author,&nameBooks[i].price);
    }
    char search[50];
    int found = 0;
    printf("Enter the information books need check\n");
    scanf("%s",search);
    for(int i=0;i<N;i++)
    {
        if(checkString(nameBooks[i].name,search) == 0)
        {
            found = 1;
            printf("Found the books\n");
            printf("Name the books:%s, Author the books:%s, Price the books:%f\n",nameBooks[i].name,nameBooks[i].author,nameBooks[i].price);
            break;
        }
    }

    if(!found)
    {
        printf("Not found\n");
    }
    return 0;
}