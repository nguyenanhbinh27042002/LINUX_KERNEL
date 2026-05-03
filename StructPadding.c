#include <stdio.h>

#pragma pack(1)
typedef struct 
{
    char a;
    int b;
    char c;
}Padding;

int main(void)
{
    printf("Padding of struct :%ld\n",sizeof(Padding));
    return 0;
}