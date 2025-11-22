#include <stdio.h>
#include <string.h>


int main(void)
{
    char A[1000];
    fgets(A,sizeof(A),stdin);
    A[strcspn(A,"\n")] = '\0';
    int count = 0;
    int flag = 0;
    for(int i = strlen(A) -1; i>=0;i--)
    {
        if(A[i] == ' ')
        {
            if(flag)
            {
                break;
            }
        }
        else
        {
            flag = 1;
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}