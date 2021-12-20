#ifndef WATERBEAR_FILESYSTEM
#define WATERBEAR_FILESYSTEM

// #include "Arduino.h"
#include "SdFat.h"
#include "DS3231.h"

class WaterBear_FileSystem
{

private:
  // File system object.
  SdFat sd;
  File logfile;
  int chipSelectPin;
  char filename[15];
  char deploymentIdentifier[29];

  void printCurrentDirListing();
  bool openFile(char * filename);


public:
  WaterBear_FileSystem(char * deploymentIdentifier, int chipSelectPin);
  void initializeSDCard();
  void writeLog(char** values, short fieldCount);
  void writeDebugMessage(const char* message);
  void setDeploymentIdentifier(char * deploymentIdentifier);
  void setNewDataFile(long unixtime);
  void dumpLoggedDataToStream(Stream * myStream, char * lastFileNameSent);
  void closeFileSystem(); // close filesystem when sleeping
  void reopenFileSystem(); // reopen filesystem after wakeup
};

#endif
