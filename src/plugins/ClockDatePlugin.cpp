#include "plugins/ClockDatePlugin.h"

void ClockDatePlugin::setup()
{
  // loading screen
  Screen.setPixel(4, 7, 1);
  Screen.setPixel(5, 7, 1);
  Screen.setPixel(7, 7, 1);
  Screen.setPixel(8, 7, 1);
  Screen.setPixel(10, 7, 1);
  Screen.setPixel(11, 7, 1);

  previousMinutes = -1;
  previousHour = -1;
}

void ClockDatePlugin::loop()
{
  if (getLocalTime(&timeinfo))
  {
    if (previousHour != timeinfo.tm_hour || previousMinutes != timeinfo.tm_min)
    {
      Screen.clear();
      Screen.drawNumbers(0, 2, {(timeinfo.tm_hour - timeinfo.tm_hour % 10) / 10, timeinfo.tm_hour % 10});
      Screen.drawNumbers(8, 2, {(timeinfo.tm_min - timeinfo.tm_min % 10) / 10, timeinfo.tm_min % 10});

      Screen.drawNumbers(0, 8, {(timeinfo.tm_mday - timeinfo.tm_mday % 10) / 10, timeinfo.tm_mday % 10});
      int month = timeinfo.tm_mon +1;
      Screen.drawNumbers(8, 8, {(month - month % 10) / 10, month % 10});
    }

    previousMinutes = timeinfo.tm_min;
    previousHour = timeinfo.tm_hour;
  }
}

const char *ClockDatePlugin::getName() const
{
  return "Clock&Date";
}
