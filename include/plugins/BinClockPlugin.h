#pragma once

#include "PluginManager.h"

class BinClockPlugin : public Plugin
{
private:
  void drawNumber(int x, int y, int number);
  void drawNumberHorizontally(int x, int y, int number);

  struct tm timeinfo;

  int previousSeconds;

public:
  void setup() override;
  void loop() override;
  const char *getName() const override;
};