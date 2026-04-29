#include <stdio.h>

typedef struct NameBooksStr
{
    char name[20];
    char author[20];
    float price;
}nameBooks;

int checkChar(char *a , char *b)
{
    while(*a && *b)
    {
        if( *a != *b)
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
    nameBooks nameBooks[200];
    int N;
    printf("Enter the number the books\n");
    scanf("%d",&N);
    printf("Enter the name, poet and price\n");
    for(int i=0;i<N;i++)
    {
        scanf("%s %s %f",nameBooks[i].name,nameBooks[i].author,&nameBooks[i].price);
    }
    char search[20];
    printf("Enter the string name for the books\n");
    scanf("%s",search);
    int flag = 0;
    for(int i=0;i<N;i++)
    {
        if(checkChar(nameBooks[i].name,search) == 0) // check the name is mapped name enter
        {
            flag = 1;
            printf("Found the name books\n");
            printf("Name the books:%s, Author the books:%s, The price:%.2f\n",nameBooks[i].name, nameBooks[i].author,nameBooks[i].price);
            break;
        }
    }
    if(!flag)
    {
        printf("Not found the books\n");
    }
    return 0;
}