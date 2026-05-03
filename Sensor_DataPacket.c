#include <stdio.h>
#include <stdint.h>


typedef struct 
{
    uint8_t id;
    float temp;
    uint8_t percentPin;
}SensorData;


void logSensorData(SensorData Data)
{
    printf("Device:[%d], Temperature:[%.1f]^C, Percent pin[%d]%%\n",Data.id,Data.temp,Data.percentPin);
}
int main(void)
{
    printf("Enter the data sensor such as:id, temperature and percent charge\n");
    SensorData sensorData;
    scanf("%hhu %f %hhu",&sensorData.id,&sensorData.temp,&sensorData.percentPin);
    logSensorData(sensorData);
    return 0;
}