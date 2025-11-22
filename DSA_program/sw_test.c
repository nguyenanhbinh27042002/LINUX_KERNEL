#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N_MAX           10000
int main(void)
{
    int T;
    printf("Enter the test case:\n");
    scanf("%d",&T);
    for(int test_case = 1;test_case <=T;test_case++)
    {
        char *str = (char*)malloc(sizeof(char)*N_MAX);
        printf("Enter string :\n");
        scanf("%s",str);
        int n =strlen(str);
        int count = 0;
        int total = 0;
        for(int i=0;i<n;i++)
        {
            if(str[i] == '(')
            {
                count++;
            }
            else if (str[i] == ')' && i>0)
            {
                count--;
                if(str[i-1] == '(')
                {
                    total +=count;
                }
                else if (str[i-1] == ')')
                {
                    total +=1;
                }
            }
        }
        printf("#%d %d\n",test_case,total);
        free(str);
    }
    return 0;
}