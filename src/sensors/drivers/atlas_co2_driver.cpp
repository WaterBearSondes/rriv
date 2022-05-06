#include "sensors/drivers/atlas_co2_driver.h"
#include "sensors/sensor_types.h"
#include "system/monitor.h" // for debug() and notify()
// #include "system/measurement_components.h" // if external adc is used

AtlasCO2Driver::AtlasCO2Driver()
{
  // debug("allocating driver template");
}

AtlasCO2Driver::~AtlasCO2Driver(){}

configuration_bytes_partition AtlasCO2Driver::getDriverSpecificConfigurationBytes()
{
  configuration_bytes_partition partition;
  memcpy(&partition, &configuration, sizeof(driver_config));
  return partition;
}

void AtlasCO2Driver::configureSpecificConfigurationsFromBytes(configuration_bytes_partition configurationPartition)
{
  memcpy(&configuration, &configurationPartition, sizeof(driver_config));
}

void AtlasCO2Driver::appendDriverSpecificConfigurationJSON(cJSON * json)
{
  // debug("appeding driver specific driver template json");
  
  //driver specific config, customize
  addCalibrationParametersToJSON(json);
}

void AtlasCO2Driver::setup()
{
  modularSensorDriver = new AtlasScientificCO2(wire,-1);
  // debug("setup AtlasCO2Driver");
}

void AtlasCO2Driver::stop()
{
  modularSensorDriver->sleep();
  // debug("stop/delete AtlasCO2Driver");
}

bool AtlasCO2Driver::takeMeasurement()
{
  // debug("taking measurement from driver template");
  //return true if measurement taken store in class value(s), false if not
  bool measurementTaken = modularSensorDriver->addSingleMeasurementResult();
  if(measurementTaken)
  {
    value = modularSensorDriver->sensorValues[1];
    modularSensorDriver->clearValues();
    measurementTaken = true;
  }
  return measurementTaken;
}

const char *AtlasCO2Driver::getDataString()
{
  // debug("configuring driver template dataString");
  // process data string for .csv
  sprintf(dataString, "%d,%d",value,0);
  return dataString;
}

const char *AtlasCO2Driver::getBaseColumnHeaders()
{
  // for debug column headers defined in the .h
  // debug("getting driver template base column headers");
  return baseColumnHeaders;
}

void AtlasCO2Driver::initCalibration()
{
  // debug("init driver template sensor calibration");
}

void AtlasCO2Driver::calibrationStep(char *step, int arg_cnt, char ** args)
{
  // for intermediary steps of calibration process
  // debug("driver template calibration steps");
}

void AtlasCO2Driver::addCalibrationParametersToJSON(cJSON *json)
{
  // follows structure of calibration parameters in .h
  // debug("add driver template calibration parameters to json");
  cJSON_AddNumberToObject(json, "calibration_time", configuration.cal_timestamp);
}

void AtlasCO2Driver::configureDriverFromJSON(cJSON *json)
{
  // debug("configuring driver template driver from json");
}

void AtlasCO2Driver::setDriverDefaults()
{
  // debug("setting driver template driver defaults");
  // set default values for driver struct specific values
  configuration.cal_timestamp = 0;
}