#include <stdio.h>


typedef struct __attribute__((packed))
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