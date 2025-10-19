#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"

#define N_MAX 10000
unsigned int arr[N_MAX] = {0};
int *twosum(int *nums, int numsSize, int target, int *returnsSize)
{
    for(int i=0;i<numsSize;i++)
    {
        for(int j=i+1;j<numsSize;j++)
        {
            if(nums[j] == target - nums[i])
            {
                int *result = (int*)malloc(2*sizeof(int));
                result[0] = i;
                result[1] = j;
                *returnsSize = 2;
                return result;
            }
        }
    }
    *returnsSize = 0;
    return NULL;
}

int main(void)
{
    int numsSize;
    int target;
    int returnsSize;
    printf("Enter the value of numbersSize\n");
    scanf("%d",&numsSize);
   
    printf("Enter the target\n");
    scanf("%d",&target);
    printf("Enter the value of array\n");
    for(int i =0;i<numsSize;i++)
    {
        scanf("%d",&arr[i]);
    }
    int *result = twosum(arr,numsSize,target,&returnsSize);
    if(result != NULL) 
    {
        printf("Output : [%d %d]\n",result[0],result[1]);
        free(result);
    }
    else
    {
        printf("Not value \n");
    }
    return 0;
}