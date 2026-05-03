#include <stdio.h>
#include <stdint.h>

typedef struct
{
    uint8_t id;
    float temp;
    uint8_t pinStatus;
}SensorData;

void logSensorData(SensorData packet)
{
    printf("Device [%d] Temp[%.f]C , Battery: [%d]per\n",packet.id,packet.temp,packet.pinStatus);
}
int main(void)
{
    SensorData sensorData;
    printf("Enter the data of the sensor\n");
    scanf("%hhu %f %hhu",&sensorData.id,&sensorData.temp,&sensorData.pinStatus);
    logSensorData(sensorData);

    return 0;
}