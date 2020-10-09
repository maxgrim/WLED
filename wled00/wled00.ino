/*
 * WLED Arduino IDE compatibility file.
 * 
 * Where has everything gone?
 * 
 * In April 2020, the project's structure underwent a major change. 
 * Global variables are now found in file "wled.h"
 * Global function declarations are found in "fcn_declare.h"
 * 
 * Usermod compatibility: Existing wled06_usermod.ino mods should continue to work. Delete usermod.cpp.
 * New usermods should use usermod.cpp instead.
 */
#include "wled.h"
#include <Badge.h>

bool badgeMode = false;

void setup() {
  if(badgeSetup()) {
    badgeMode = true;
  } else {
    WLED::instance().setup();
  }
}

void loop() {
  if(badgeMode) {
    badgeLoop();
  } else {
    WLED::instance().loop();
  }
}
