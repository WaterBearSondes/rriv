#ifndef WATERBEAR_ATLAS_EC
#define WATERBEAR_ATLAS_EC

#include "sensor.h"

class AtlasEC : public I2CSensorDriver
{

  public: 
    // Constructor
    AtlasEC();

    // Interface
    void setup();
    void stop();
    bool takeMeasurement();
    char * getDataString();
    char * getCSVColumns();
    protocol_type getProtocol();

  private:
    char csvColumnHeaders[100] = "ec";

    char dataString[16];
};


// #include <Wire_slave.h> // Communicate with I2C/TWI devices
// #include <EC_OEM.h>

// void setupEC_OEM(TwoWire * wire);
// void hibernateEC_OEM();
// void clearECCalibrationData();
// void setECDryPointCalibration();
// void setECLowPointCalibration(float lowPoint);
// void setECHighPointCalibration(float highPoint);
// bool readECDataIfAvailable(float * value);

#endif