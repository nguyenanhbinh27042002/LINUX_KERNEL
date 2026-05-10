#include <stdio.h>

typedef struct 
{
    unsigned int power :1;
    unsigned int mode : 3;
    unsigned int reverse : 4;
}SystemConfig;


int main(void)
{
    printf("Size of the struct System Configuration:%ld\n",sizeof(SystemConfig));

    return 0;
}