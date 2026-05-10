#include <stdio.h>
#include <stdint.h>


typedef struct 
{
    uint8_t id;
    char data[50];
}Message;

void messageFilter(Message msg[], int size)
{
    for(int i=0;i<size;i++)
    {
        if(msg[i].id == 0xFF)
        {
            printf("Warning the error message: %s\n",msg[i].data);
        }
    }
}


int main(void)
{
    Message msg[50] = {
        {0x01, "Normal mode"},
        {0x02, "Toggle mode"},
        {0x03, "Interrupt mode"},
        {0xFF, "Error mode"},
    };
    int size = sizeof(msg)/sizeof(msg[0]);
    messageFilter(msg,size);

    return 0;
}