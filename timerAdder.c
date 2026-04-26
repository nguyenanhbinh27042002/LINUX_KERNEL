#include <stdio.h>


typedef struct TimerStr
{
	int hour;
	int min;
	int sec;
}Timer;

int main(void)
{
	Timer time;
	for(int i=0;;i++)
	{
		do
		{
			printf("Enter the timer :\n");
			scanf("%d %d %d",&time.hour,&time.min,&time.sec);
		} while (time.hour < 0 || time.hour > 24 || time.min < 0 || time.min > 59 || time.sec < 0 || time.sec > 59); break ;
	}
	int temp = time.hour*3600 + time.min*60 + time.sec;
	temp = (temp+1)%(24*3600);
	time.hour = temp/3600;
	time.min = (temp%3600)/60;
	time.sec = (temp%3600)%60;

	printf("Time at the clock :%02d %02d %02d\n",time.hour,time.min,time.sec);
	return 0;
}