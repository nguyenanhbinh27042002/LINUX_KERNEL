#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#define N_MAX   10000
unsigned  int arr[N_MAX] = {0};
int compare(const void *a, const void *b)
{
    return(*(int*)a - *(int*)b);
}
bool containsDuplicate(int *nums, int numsSize)
{
    qsort(nums,numsSize,sizeof(int),compare);
    for(int i=1;i<numsSize;i++)
    {
        if(nums[i] == nums[i-1])
        {
            return true;
        }
    }
    return false;
}

int main(void)
{
    int N;
    printf("Enter the value of N\n");
    scanf("%d",&N);
    printf("Value of array\n");
    for(int i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    bool result = containsDuplicate(arr,N);
    if(result)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    return 0;
}