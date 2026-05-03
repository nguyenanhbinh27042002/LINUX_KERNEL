#include <stdio.h>
#include <math.h>

typedef struct Point
{
    float x;
    float y;
}Point;

int main(void)
{
    Point ptr1;
    Point ptr2;
    printf("Enter the coordition of the point: such as x1, y1, x2, y2\n");
    scanf("%f %f %f %f",&ptr1.x,&ptr1.y,&ptr2.x,&ptr2.y);

    float distance = sqrt(pow(ptr1.x-ptr2.x,2) + pow(ptr1.y-ptr2.y,2));
    printf("%f %f %f %f\n",ptr1.x,ptr1.y,ptr2.x,ptr2.y);
    printf("Distance of 2 point: %.2f\n",distance);
    return 0;
}