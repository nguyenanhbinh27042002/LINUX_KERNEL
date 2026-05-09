/*
Array elements before processing: 1 2 3 4 5 6 
Square of the array elements after processing: 1 4 9 16 25 36 
*/

#include <stdio.h>

#define Max  1000

void process(int *arr, int size, int (*callback)(int))
{
    for(int i=0;i<size;i++)
    {
        arr[i] = callback(arr[i]);
    }
}

int square(int n)
{
    return n*n;
}

int main(void)
{
    int n;
    printf("Enter the value number\n");
    scanf("%d",&n);
    int arr[Max];
    printf("Enter the value of array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    process(arr,n,square);

    printf("Array is resulted\n");
    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    return 0;
}
