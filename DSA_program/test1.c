#include <stdio.h>

int main(void)
{
    int A[1000],B[1000],C[1000];

    int m,n,t;
    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
        //printf("%d ",A[i]);
    }
    //printf("\n");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&B[i]);
        //printf("%d ",B[i]);
    }
    //printf("\n");

    t = (n > m) ? n:m;

    for(int i=0;i<t;i++)
    {
        C[i] = A[i] + B[i];
        printf("%d ",C[i]);
    }
    return 0;
}