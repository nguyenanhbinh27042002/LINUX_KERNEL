#include <stdio.h>


typedef struct Timer_Str
{
	int hour;
	int min;
	int sec;
}Timer;

int main(void)
{
	Timer time;
	printf("Enter the Timer adder\n");
	scanf("%d %d %d",&time.hour,&time.min,&time.sec);


	return 0;
}
