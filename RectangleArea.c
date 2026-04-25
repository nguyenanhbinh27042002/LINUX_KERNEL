#include <stdio.h>


typedef struct RectangleStr
{
	int height;
	int width;
}Rectangle;


int main(void)
{
	Rectangle rec;
	printf("Enter rectangle \n");
	scanf("%d %d",&rec.height,&rec.width);
	float area = (float)(rec.height*rec.width);
	printf("Area : %lf\n",area);
	return 0;
}

