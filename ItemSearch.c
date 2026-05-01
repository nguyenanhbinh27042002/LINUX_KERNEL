#include <stdio.h>

typedef struct
{
    char id[20];
    int quantity;
    int price;
}ItemSearch;

int main(void)
{
    ItemSearch item[100];
    printf("Enter the number\n");
    int n;
    scanf("%d",&n);
    printf("Enter the id, quantity and price of items at the store\n");
    for(int i=0;i<n;i++)
    {
        scanf("%s %d %d",item[i].id,&item[i].quantity,&item[i].price);
    }
    float sum = 0;
    for(int i=0;i<n;i++)
    {
        sum += item[i].price*item[i].quantity;
    }
    printf("Total the quantity*price:%.2f\n",sum);
    return 0;
}