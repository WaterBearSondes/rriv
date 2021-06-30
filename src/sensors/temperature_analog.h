#ifndef WATERBEAR_TEMPERATURE_ANALOG
#define WATERBEAR_TEMPERATURE_ANALOG

#include "sensor.h"

class TemperatureAnalog : public AnalogSensorDriver
{

  public: 
    // Constructor
    TemperatureAnalog();

    // Interface
    void stop();
    bool takeMeasurement();
    char * getDataString();
    const char * getCSVColumns();
    protocol_type getProtocol();

  private:
    char dataString[16];
    const char CSVColumns[100] = {"temp.mv, temp.c, temp.slope, temp.int"};
    int TempMV = -1;
    int TempC = -1;
    int TempCMult = 100;
    int CalB = 5;
    int CalBMult = 10;
    int CalM = 0.2;
    int CalMMult = 10;
};


typedef struct temperature_analog_type{
    // 10k ohm NTC 3950b thermistor
    common_config_sensor common;
    char calibrated; // 1 byte => bit mask
    char sensor_port; // 1 byte => add into bit mask (4bits)
    // generalize for a generic linear calibrated sensor...? (x,y)
    unsigned short m; // 2bytes, slope
    int b; // 4bytes, y-intercept
    unsigned int cal_timestamp; // 4byte epoch timestamp at calibration
    short int c1; // 2bytes for 2pt calibration
    short int v1; // 2bytes for 2pt calibration
    short int c2; // 2bytes for 2pt calibration
    short int v2; // 2bytes for 2pt calibration

    char padding[12];
}temperature_analog_sensor;



#endif