#include <stdio.h>
#include <math.h>

typedef struct PointStr
{
    float x;
    float y;
}Point;

int main(void)
{
    Point ptr;
    printf("Enter the pointer \n");
    scanf("%f %f",&ptr.x, &ptr.y);
    float distance = sqrt(pow(ptr.x,2) + pow(ptr.y,2));
    printf("Distance %f\n", distance);
    return 0;
}