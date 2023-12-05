#include "plugins/BinClockPlugin.h"

void BinClockPlugin::setup()
{
  // loading screen
  Screen.setPixel(4, 7, 1);
  Screen.setPixel(5, 7, 1);
  Screen.setPixel(7, 7, 1);
  Screen.setPixel(8, 7, 1);
  Screen.setPixel(10, 7, 1);
  Screen.setPixel(11, 7, 1);

  previousSeconds = -1;
}

void BinClockPlugin::loop()
{
  if (getLocalTime(&timeinfo))
  {
    if (previousSeconds != timeinfo.tm_sec)
    {
      int hour_decimal = (timeinfo.tm_hour - timeinfo.tm_hour % 10) / 10;
      int hour_one = timeinfo.tm_hour % 10;

      int minutes_decimal = (timeinfo.tm_min - timeinfo.tm_min % 10) / 10;
      int minutes_one = timeinfo.tm_min % 10;

      int seconds_decimal = (timeinfo.tm_sec - timeinfo.tm_sec % 10) / 10;
      int seconds_one = timeinfo.tm_sec % 10;

      Screen.clear();

      drawNumber(3, 2, hour_decimal);
      drawNumber(4, 2, hour_one);
      drawNumber(7, 2, minutes_decimal);
      drawNumber(8, 2, minutes_one);
      drawNumber(11, 2, seconds_decimal);
      drawNumber(12, 2, seconds_one);
      

      drawNumberHorizontally(5, 9, timeinfo.tm_hour);
      drawNumberHorizontally(5, 11, timeinfo.tm_min);
      drawNumberHorizontally(5, 13, timeinfo.tm_sec);
    }

    previousSeconds = timeinfo.tm_sec;
  }
}

void BinClockPlugin::drawNumber(int x, int y, int number) {
  for(int i=0; i<4; i++) {
    Screen.setPixel(x, y+i, 1, (number & (1<<(3-i)))?255:5);
  }
}

void BinClockPlugin::drawNumberHorizontally(int x, int y, int number) {
  for(int i=0; i<6; i++) {
    Screen.setPixel(x+i, y, 1, (number & (1<<(5-i)))?255:5);
  }
}

const char *BinClockPlugin::getName() const
{
  return "BinaryClock";
}
