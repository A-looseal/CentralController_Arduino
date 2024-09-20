#include <Arduino.h>
#line 1 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
#include <arduino.h>
#include <RTClib.h>
#include <DHT.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#include "src/zonea_config.h"
#include "src/zoneb_config.h"
#include "src/zonec_config.h"

#include "src/intakeFan_config.h"
#include "src/exhaustFan_config.h"
#include "src/windFan_config.h"
#include "src/sunLight_config.h"
#include "src/waterPump_config.h"
#include "src/oxygenPump_config.h"

#define ENABLE_SERIAL_OUTPUT

/* EXHAUST FAN VARIABLES */
unsigned long exhaustFanTimer_previousMillis = 0; // will store last time LED was updated
bool canExhaustFlow = true;                       //(dynamically control whether the pump can be activated or not. Set by the clock)
bool exhaustFanState = false;                     //(the current state of the water pump)

/* INTAKE FAN VARIABLES */
unsigned long intakeFanTimer_previousMillis = 0; // will store last time LED was updated
bool canIntakeFlow = true;                       //(dynamically control whether the pump can be activated or not. Set by the clock)
bool intakeFanState = false;                     //(the current state of the water pump)

/* WIND FAN VARIABLES */
unsigned long windFanTimer_previousMillis = 0; // will store last time LED was updated
bool canWindFlow = true;                       //(dynamically control whether the pump can be activated or not. Set by the clock)
bool windFanState = false;                     //(the current state of the water pump)

/* SUN LIGHT VARIABLES */
unsigned long sunTimer_previousMillis = 0; // will store last time LED was updated
bool canSunShine = false;                  //(dynamically control whether the pump can be activated or not. Set by the clock)
bool sunLightState = false;                //(the current state of the water pump)

/* WATER PUMP VARIABLES */
unsigned long waterTimer_previousMillis = 0; // will store last time LED was updated
bool canWaterFlow = false;                   //(dynamically control whether the pump can be activated or not. Set by the clock)
bool waterPumpState = false;                 //(the current state of the water pump)

/* OXYGEN PUMP VARIABLES*/
unsigned long oxygenTimer_previousMillis = 0; // will store last time LED was updated
bool canOxygenFlow = false;                   //(dynamically control whether the pump can be activated or not. Set by the clock)
bool oxygenPumpState = false;                 //(the current state of the water pump)

/* ZONE A VARIABLES*/
bool zoneA_isAirTemperatureHot = false;
bool zoneA_isAirTemperatureCritical = false;
bool zoneA_isAirHumidityHot = false;
bool zoneA_isAirHumidityCritical = false;
float zoneA_currentWaterTemperature;
bool zoneA_isWaterTemperatureHot = false;
bool zoneA_isWaterTemperatureCritical = false;
DHT ZONEA_AIR_THERMOMETER(ZONEA_AIR_SENSOR_PIN, ZONEA_AIR_SENSOR_TYPE);

/* ZONE B VARIABLES*/
bool zoneB_isAirTemperatureHot = false;
bool zoneB_isAirTemperatureCritical = false;
bool zoneB_isAirHumidityHot = false;
bool zoneB_isAirHumidityCritical = false;
float zoneB_currentWaterTemperature;
bool zoneB_isWaterTemperatureHot = false;
bool zoneB_isWaterTemperatureCritical = false;
DHT ZONEB_AIR_THERMOMETER(ZONEB_AIR_SENSOR_PIN, ZONEB_AIR_SENSOR_TYPE);

/* ZONE C VARIABLES*/
bool zoneC_isAirTemperatureHot = false;
bool zoneC_isAirTemperatureCritical = false;
bool zoneC_isAirHumidityHot = false;
bool zoneC_isAirHumidityCritical = false;
float zoneC_currentWaterTemperature;
bool zoneC_isWaterTemperatureHot = false;
bool zoneC_isWaterTemperatureCritical = false;
DHT ZONEC_AIR_THERMOMETER(ZONEC_AIR_SENSOR_PIN, ZONEC_AIR_SENSOR_TYPE);

/*REAL TIME CLOCK VARIABLES*/
int currentHour;
int currentMinute;
RTC_DS3231 OnBoardClock; // clock object
DateTime currentTime;    // current time object

/* SYSTEM CLOCK VARIABLES */
unsigned long currentMillis;

// Setup a oneWire instance to communicate with any OneWire devices
OneWire zoneA_OneWire(ZONEA_WATER_TEMPERATURE_SENSOR_PIN);
OneWire zoneB_OneWire(ZONEB_WATER_TEMPERATURE_SENSOR_PIN);
OneWire zoneC_OneWire(ZONEC_WATER_TEMPERATURE_SENSOR_PIN);

// Pass our oneWire reference to Dallas Temperature sensor
DallasTemperature zoneA_WaterSensor(&zoneA_OneWire);
DallasTemperature zoneB_WaterSensor(&zoneB_OneWire);
DallasTemperature zoneC_WaterSensor(&zoneC_OneWire);

// Program Start
#line 100 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
void setup();
#line 147 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
void loop();
#line 298 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
void SetupHardware(byte _devicePin, char _deviceMode);
#line 325 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
bool Check_ZoneA_Water_Temperature();
#line 364 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
bool Check_ZoneA_Air_Humidity();
#line 399 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
bool Check_ZoneA_Air_Temperature();
#line 439 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
void EnableSunLight();
#line 465 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
void DisableSunLight();
#line 491 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
void CycleSunLight();
#line 532 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
void CycleIntakeFan();
#line 563 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
void CycleExhaustFan();
#line 597 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
bool Check_ZoneB_Water_Temperature();
#line 636 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
bool Check_ZoneB_Air_Humidity();
#line 675 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
bool Check_ZoneB_Air_Temperature();
#line 716 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
void CycleAllWindFans();
#line 755 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
bool Check_ZoneC_Water_Temperature();
#line 794 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
bool Check_ZoneC_Air_Humidity();
#line 833 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
bool Check_ZoneC_Air_Temperature();
#line 874 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
void EnableWater();
#line 896 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
void DisableWater();
#line 918 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
void CycleWaterPump();
#line 959 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
void EnableOxygen();
#line 981 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
void DisableOxygen();
#line 1003 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
void CycleOxygenPump();
#line 100 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
void setup()
{
#ifdef ENABLE_SERIAL_OUTPUT
  Serial.begin(115200);
  delay(1000);
  Serial.println("Serial Connection Established.");
#endif

  zoneA_WaterSensor.begin();
  zoneB_WaterSensor.begin();
  zoneC_WaterSensor.begin();

  // search for connected clock. Dont continue if none is found
  if (!OnBoardClock.begin())
  {
#ifdef ENABLE_SERIAL_OUTPUT
    Serial.println("Couldn't find RTC");
    Serial.flush();
#endif
    while (1)
      delay(10);
  }

  // intake fan
  pinMode(INTAKEFAN_PIN, OUTPUT);
  digitalWrite(INTAKEFAN_PIN, LOW);
  // echaust fan
  pinMode(EXHAUSTFAN_PIN, OUTPUT);
  digitalWrite(EXHAUSTFAN_PIN, LOW);
  // windfans
  pinMode(WINDFAN_1_PIN, OUTPUT);
  digitalWrite(WINDFAN_1_PIN, LOW);
  // water pump
  pinMode(WATERPUMP_PIN, OUTPUT);
  digitalWrite(WATERPUMP_PIN, LOW);
  // oxygen pump
  pinMode(OXYGENPUMP_PIN, OUTPUT);
  digitalWrite(OXYGENPUMP_PIN, LOW);

  ZONEA_AIR_THERMOMETER.begin();
  ZONEB_AIR_THERMOMETER.begin();
  ZONEC_AIR_THERMOMETER.begin();

  // uncomment the following line to set the date & time to the current date and time of uploading
  // OnBoardClock.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void loop()
{
#ifdef ENABLE_SERIAL_OUTPUT
  Serial.println('\n');
  Serial.println(F("#########################"));
#endif

  // get a reading of the current time
  currentMillis = millis();
  currentTime = OnBoardClock.now();
  currentHour = (currentTime.hour());
  currentMinute = (currentTime.minute());

#ifdef ENABLE_SERIAL_OUTPUT
  Serial.print("current hour: ");
  Serial.println(currentHour);
  Serial.print("current minute: ");
  Serial.println(currentMinute);

  Serial.println('\n');
  // Serial.println(F("--------------------------"));

  // Serial.print(F("ZONE B Humidity Level: "));
  // Serial.println(ZONEB_AIR_THERMOMETER.readHumidity());
  // Serial.print(F("ZONE B Water Temperature: "));
  // Serial.println(sensors.getTempCByIndex(1));

  // Serial.println(F("--------------------------"));
  // Serial.print(F("ZONE C Air Temperature: "));
  // Serial.println(ZONEC_AIR_THERMOMETER.readTemperature());
  // Serial.print(F("ZONE C Humidity Level: "));
  // Serial.println(ZONEC_AIR_THERMOMETER.readHumidity());
  // Serial.print(F("ZONE C Water Temperature: "));
  // Serial.println(sensors.getTempCByIndex(2));

  Serial.println('\n');
#endif

  zoneA_WaterSensor.requestTemperatures();
  zoneB_WaterSensor.requestTemperatures();
  zoneC_WaterSensor.requestTemperatures();

  zoneA_currentWaterTemperature = zoneA_WaterSensor.getTempCByIndex(0);
  zoneB_currentWaterTemperature = zoneB_WaterSensor.getTempCByIndex(0);
  zoneC_currentWaterTemperature = zoneC_WaterSensor.getTempCByIndex(0);

#ifdef ENABLE_SERIAL_OUTPUT
  Serial.println(F("___ZONE A___"));
#endif

  Check_ZoneA_Air_Humidity();
  Check_ZoneA_Air_Temperature();
  Check_ZoneA_Water_Temperature();

#ifdef ENABLE_SERIAL_OUTPUT
  Serial.println(F("--------------------------"));
#endif

  Serial.print(F("Can Exhaust Fan flow value: "));
  Serial.println(canExhaustFlow);
  CycleExhaustFan();

#ifdef ENABLE_SERIAL_OUTPUT
  Serial.println(F("--------------------------"));
#endif

  Serial.print(F("Can Intake Fan flow value: "));
  Serial.println(canIntakeFlow);
  CycleIntakeFan();

#ifdef ENABLE_SERIAL_OUTPUT
  Serial.println(F("--------------------------"));
#endif

  Serial.print(F("Can Sun Light Shine value: "));
  Serial.println(canSunShine);
  // handle sun light logic
  EnableSunLight();
  DisableSunLight();
  CycleSunLight();

#ifdef ENABLE_SERIAL_OUTPUT
  Serial.println('\n');
#endif

#ifdef ENABLE_SERIAL_OUTPUT
  Serial.println(F("___ZONE B___"));
#endif

  Check_ZoneB_Air_Humidity();
  Check_ZoneB_Air_Temperature();
  Check_ZoneB_Water_Temperature();

#ifdef ENABLE_SERIAL_OUTPUT
  Serial.println(F("--------------------------"));
#endif

  Serial.print(F("Can Wind Fan flow value: "));
  Serial.println(canWindFlow);
  CycleAllWindFans();

#ifdef ENABLE_SERIAL_OUTPUT
  Serial.println('\n');
#endif

#ifdef ENABLE_SERIAL_OUTPUT
  Serial.println(F("___ZONE C___"));
#endif

  Check_ZoneC_Air_Humidity();
  Check_ZoneC_Air_Temperature();
  Check_ZoneC_Water_Temperature();

#ifdef ENABLE_SERIAL_OUTPUT
  Serial.println(F("--------------------------"));
#endif

  Serial.print(F("Can Water Pump Flow value: "));
  Serial.println(canWaterFlow);
  // handle reservoir water pump logic
  EnableWater();
  DisableWater();
  CycleWaterPump();

#ifdef ENABLE_SERIAL_OUTPUT
  Serial.println(F("--------------------------"));
#endif

  Serial.print(F("Can Oxygen Pump Flow value: "));
  Serial.println(canOxygenFlow);
  // handle reservoir oxygen pump logic
  EnableOxygen();
  DisableOxygen();
  CycleOxygenPump();

#ifdef ENABLE_SERIAL_OUTPUT
  Serial.println(F("#########################"));
  Serial.println('\n');
#endif
  delay(5000);
}

/* Setup Hardware function
Written by: aLooSeal
Version: v1.0

- uses a tiny bit of logic to set the GPIO pinmode
- requires device pin, and the desired pin Mode

OUTPUT DEVICE = 'o' | INPUT DEVICE = 'i'
*/
void SetupHardware(byte _devicePin, char _deviceMode)
{
  if (_deviceMode == 'o')
  {
#ifdef ENABLE_SERIAL_OUTPUT
    Serial.println(F("Device setup initialized..."));
#endif
    pinMode(_devicePin, OUTPUT);
    digitalWrite(_devicePin, 0);
#ifdef ENABLE_SERIAL_OUTPUT
    Serial.println(F("Device setup complete."));
#endif
  }
  else if (_deviceMode == 'i')
  {
#ifdef ENABLE_SERIAL_OUTPUT
    Serial.println(F("Device setup initialized..."));
#endif
    pinMode(_devicePin, INPUT);
#ifdef ENABLE_SERIAL_OUTPUT
    Serial.println(F("Device setup initialized..."));
#endif
  }
}

// ZONE A
// ZONE A ENVIRONMENT FEEDBACK
bool Check_ZoneA_Water_Temperature()
{
  Serial.print(F("ZONE A CURRENT WATER TEMPERATURE: "));

  // if value is above critical threshold.
  if (zoneA_currentWaterTemperature >= ZONEA_WATER_TEMPERATURE_CRITICAL)
  {
    // TODO: trigger critical alert (critical alert should stop all pumps.)
    zoneA_isWaterTemperatureCritical = true;
    zoneA_isWaterTemperatureHot = true;

    Serial.print(F("CRITICAL: "));
    Serial.println(zoneA_currentWaterTemperature);

    return false;
  }
  // if temperature is above the max allowed
  else if (zoneA_currentWaterTemperature >= ZONEA_WATER_TEMPERATURE_MAX && zoneA_currentWaterTemperature < ZONEA_WATER_TEMPERATURE_CRITICAL)
  {
    zoneA_isWaterTemperatureCritical = false;
    zoneA_isWaterTemperatureHot = true;

    Serial.print(F("ELEVATED: "));
    Serial.println(zoneA_currentWaterTemperature);

    return false;
  }
  else
  {
    zoneA_isWaterTemperatureCritical = false;
    zoneA_isWaterTemperatureHot = false;

    Serial.print(F("NORMAL: "));
    Serial.println(zoneA_currentWaterTemperature);

    return true;
  }
}

bool Check_ZoneA_Air_Humidity()
{
  Serial.print(F("ZONE A CURRENT AIR HUMIDITY: "));

  // if value is above critical threshold.
  if (ZONEA_AIR_THERMOMETER.readHumidity() >= ZONEA_AIR_HUMIDITY_CRITICAL_MAX)
  {
    // TODO: trigger critical alert (critical alert should stop all pumps.)
    zoneA_isAirHumidityCritical = true;
    zoneA_isAirHumidityHot = true;
    Serial.print(F("CRITICAL: "));
    Serial.println(ZONEA_AIR_THERMOMETER.readHumidity());
    return false;
  }
  // if temperature is above the max allowed
  else if (ZONEC_AIR_THERMOMETER.readHumidity() >= ZONEA_AIR_HUMIDITY_MAX && ZONEA_AIR_THERMOMETER.readHumidity() < ZONEA_AIR_HUMIDITY_CRITICAL_MAX)
  {
    zoneA_isAirHumidityCritical = false;
    zoneA_isAirHumidityHot = true;
    Serial.print(F("ELEVATED: "));
    Serial.println(ZONEA_AIR_THERMOMETER.readHumidity());
    // if value is max temp threshold, disable pump
    return false;
  }
  else
  {
    zoneA_isAirHumidityCritical = false;
    zoneA_isAirHumidityHot = false;
    Serial.print(F("NORMAL: "));
    Serial.println(ZONEA_AIR_THERMOMETER.readHumidity());
    //  if value is below max temp threshold, enable pump
    return true;
  }
}

bool Check_ZoneA_Air_Temperature()
{
  Serial.print(F("ZONE A CURRENT AIR TEMPERATURE: "));

  // if value is above critical threshold.
  if (ZONEA_AIR_THERMOMETER.readTemperature() >= ZONEA_AIR_TEMPERATURE_CRITICAL_MAX)
  {
    // TODO: trigger critical alert (critical alert should stop all pumps.)
    zoneA_isAirTemperatureCritical = true;
    zoneA_isAirTemperatureHot = true;

    Serial.print(F("CRITICAL: "));
    Serial.println(ZONEA_AIR_THERMOMETER.readTemperature());

    return false;
  }
  // if temperature is above the max allowed
  else if (ZONEC_AIR_THERMOMETER.readTemperature() >= ZONEA_AIR_TEMPERATURE_MAX && ZONEA_AIR_THERMOMETER.readTemperature() < ZONEA_AIR_TEMPERATURE_CRITICAL_MAX)
  {
    zoneA_isAirTemperatureCritical = false;
    zoneA_isAirTemperatureHot = true;

    Serial.print(F("ELEVATED: "));
    Serial.println(ZONEA_AIR_THERMOMETER.readTemperature());

    return false;
  }
  else
  {
    zoneA_isAirTemperatureCritical = false;
    zoneA_isAirTemperatureHot = false;

    Serial.print(F("NORMAL: "));
    Serial.println(ZONEA_AIR_THERMOMETER.readTemperature());

    return true;
  }
}

// ZONE A SUN LIGHT CONTROL LOGIC
void EnableSunLight()
{
  // if hardware is not currently enabled
  if (canSunShine == false)
  {
#ifdef ENABLE_SERIAL_OUTPUT
    Serial.print(F("attempting to enable sun light capability: "));
#endif
    // check if the current time is greater than the set on time, but in the same period.
    if (currentHour >= SUNLIGHT_TIME_TURN_ON_HOUR)
    {
      // if the hardare should be enabled, enable hardware capability
      canSunShine = true;
#ifdef ENABLE_SERIAL_OUTPUT
      Serial.println(F("successfully enabled sun light!"));
#endif
    }
    else
    {
#ifdef ENABLE_SERIAL_OUTPUT
      Serial.println(F("not yet time to enable sun light."));
#endif
    }
  }
}

void DisableSunLight()
{
  // if hardware is not currently enabled
  if (canSunShine == true)
  {
#ifdef ENABLE_SERIAL_OUTPUT
    Serial.print(F("attempting to disable sun light capability: "));
#endif
    // check if the current time is greater than the set on time, but in the same period.
    if (currentHour >= SUNLIGHT_TIME_TURN_OFF_HOUR)
    {
      // if the hardare should be enabled, enable hardware capability
      canSunShine = false;
#ifdef ENABLE_SERIAL_OUTPUT
      Serial.println(F("successfully disabled sun light!"));
#endif
    }
    else
    {
#ifdef ENABLE_SERIAL_OUTPUT
      Serial.println(F("not yet time to disable sun light."));
#endif
    }
  }
}

void CycleSunLight()
{ // if hardware is currently enabled
  if (canSunShine == true)
  { // check if reservoir is overheating
    if (sunLightState == false && zoneA_isAirHumidityCritical == true || zoneA_isAirHumidityHot == true || zoneA_isAirTemperatureCritical == true || zoneA_isAirTemperatureHot == true)
    {
      Serial.println(F("Attempting to cycle sun light On/Off"));
      // TODO: use ()millis to run pump for x time, x time (relay, not pwm)
      if (sunLightState == false && currentMillis - sunTimer_previousMillis >= SUNLIGHT_FREQUENCY_ON)
      {
        // turn the pump on
        digitalWrite(SUNLIGHT_PIN, HIGH);
        // TODO: track current state of the pump
        sunLightState = true;
        // save the last time you blinked the LED
        sunTimer_previousMillis = currentMillis;
        Serial.println(F("sun light is on."));
      }

      // TODO: use ()millis to stop pump for x time (relay, not pwm)
      if (sunLightState == true && currentMillis - sunTimer_previousMillis >= SUNLIGHT_FREQUENCY_OFF)
      {
        // turn the pump off
        digitalWrite(SUNLIGHT_PIN, LOW);
        // TODO: track current state of the pump
        sunLightState = false;
        // save the last time you blinked the LED
        sunTimer_previousMillis = currentMillis;
        Serial.println(F("sun light is off."));
      }

      // TODO: only do off cycle logic if the off frequency is 0
    }
  }
  if (canSunShine == false)
  {
    digitalWrite(SUNLIGHT_PIN, LOW);
  }
}

// ZONE A FAN CONTROL LOGIC
void CycleIntakeFan()
{ // if hardware is currently enabled
  if (canIntakeFlow == true)
  { // check if reservoir is overheating
    if (intakeFanState == false && zoneA_isAirHumidityCritical == true || zoneA_isAirHumidityHot == true || zoneA_isAirTemperatureCritical == true || zoneA_isAirTemperatureHot == true)
    {
      Serial.println(F("Attempting to cycle intake fan On"));

      // turn the pump on
      digitalWrite(INTAKEFAN_PIN, HIGH);
      intakeFanState = true;
      Serial.println(F("Intake fan is on."));
    }
  }
  else if (intakeFanState == true && zoneA_isAirHumidityCritical == false || zoneA_isAirHumidityHot == true || zoneA_isAirTemperatureCritical == true || zoneA_isAirTemperatureHot == true)
  {
    digitalWrite(INTAKEFAN_PIN, LOW);
    // TODO: track current state of the pump
    intakeFanState = false;
    Serial.println(F("Intake fan is off."));
  }

  if (intakeFanState == true && canIntakeFlow == false)
  {
    digitalWrite(INTAKEFAN_PIN, LOW);
    // TODO: track current state of the pump
    intakeFanState = false;
    Serial.println(F("Intake fan is off."));
  }
}

void CycleExhaustFan()
{ // if hardware is currently enabled
  if (canExhaustFlow == true)
  { // check if reservoir is overheating
    if (intakeFanState == false && zoneA_isAirHumidityCritical == true || zoneA_isAirHumidityHot == true || zoneA_isAirTemperatureCritical == true || zoneA_isAirTemperatureHot == true)
    {
      Serial.println(F("Attempting to cycle exhaust fan On"));

      // turn the pump on
      digitalWrite(EXHAUSTFAN_PIN, HIGH);
      // TODO: track current state of the pump
      exhaustFanState = true;
      Serial.println(F("Exhaust fan is on."));
    }
  }
  else if (intakeFanState == true && (zoneA_isAirHumidityCritical == false && zoneA_isAirHumidityHot == false) || (zoneA_isAirTemperatureCritical == false || zoneA_isAirTemperatureHot == false))
  {
    digitalWrite(EXHAUSTFAN_PIN, LOW);
    // TODO: track current state of the pump
    exhaustFanState = false;
    Serial.println(F("Exhaust fan is off."));
  }

  if (intakeFanState == true && canIntakeFlow == false)
  {
    digitalWrite(EXHAUSTFAN_PIN, LOW);
    // TODO: track current state of the pump
    exhaustFanState = false;
    Serial.println(F("Exhaust fan is off."));
  }
}

// ZONE B
// ZONE B ENVIRONMENT FEEDBACK
bool Check_ZoneB_Water_Temperature()
{
  Serial.print(F("ZONE B CURRENT WATER TEMPERATURE: "));

  // if value is above critical threshold.
  if (zoneB_currentWaterTemperature >= ZONEB_WATER_TEMPERATURE_CRITICAL)
  {
    // TODO: trigger critical alert (critical alert should stop all pumps.)
    zoneB_isWaterTemperatureCritical = true;
    zoneB_isWaterTemperatureHot = true;

    Serial.print(F("CRITICAL: "));
    Serial.println(zoneB_currentWaterTemperature);

    return false;
  }
  // if temperature is above the max allowed
  else if (zoneB_currentWaterTemperature >= ZONEB_WATER_TEMPERATURE_MAX && zoneB_currentWaterTemperature < ZONEB_WATER_TEMPERATURE_CRITICAL)
  {
    zoneB_isWaterTemperatureCritical = false;
    zoneB_isWaterTemperatureHot = true;

    Serial.print(F("ELEVATED: "));
    Serial.println(zoneB_currentWaterTemperature);

    return false;
  }
  else
  {
    zoneB_isWaterTemperatureCritical = false;
    zoneB_isWaterTemperatureHot = false;

    Serial.print(F("NORMAL: "));
    Serial.println(zoneB_currentWaterTemperature);

    return true;
  }
}

bool Check_ZoneB_Air_Humidity()
{
  Serial.print(F("ZONE B CURRENT AIR HUMIDITY: "));

  // if value is above critical threshold.
  if (ZONEB_AIR_THERMOMETER.readHumidity() >= ZONEB_AIR_HUMIDITY_CRITICAL_MAX)
  {
    // TODO: trigger critical alert (critical alert should stop all pumps.)
    zoneB_isAirHumidityCritical = true;
    zoneB_isAirHumidityHot = true;

    Serial.print(F("CRITICAL: "));
    Serial.println(ZONEB_AIR_THERMOMETER.readHumidity());

    return false;
  }
  // if temperature is above the max allowed
  else if (ZONEB_AIR_THERMOMETER.readHumidity() >= ZONEB_AIR_HUMIDITY_MAX && ZONEB_AIR_THERMOMETER.readHumidity() < ZONEB_AIR_HUMIDITY_CRITICAL_MAX)
  {
    zoneB_isAirHumidityCritical = false;
    zoneB_isAirHumidityHot = true;

    Serial.print(F("ELEVATED: "));
    Serial.println(ZONEB_AIR_THERMOMETER.readHumidity());

    return false;
  }
  else
  {
    zoneB_isAirHumidityCritical = false;
    zoneB_isAirHumidityHot = false;

    Serial.print(F("NORMAL: "));
    Serial.println(ZONEB_AIR_THERMOMETER.readHumidity());

    return true;
  }
}

bool Check_ZoneB_Air_Temperature()
{
  Serial.print(F("ZONE B CURRENT AIR TEMPERATURE: "));

  // if value is above critical threshold.
  if (ZONEB_AIR_THERMOMETER.readTemperature() >= ZONEB_AIR_TEMPERATURE_CRITICAL_MAX)
  {
    // TODO: trigger critical alert (critical alert should stop all pumps.)
    zoneB_isAirTemperatureCritical = true;
    zoneB_isAirTemperatureHot = true;

    Serial.print(F("CRITICAL: "));
    Serial.println(ZONEB_AIR_THERMOMETER.readTemperature());

    return false;
  }
  // if temperature is above the max allowed
  else if (ZONEB_AIR_THERMOMETER.readTemperature() >= ZONEB_AIR_TEMPERATURE_MAX && ZONEB_AIR_THERMOMETER.readTemperature() < ZONEB_AIR_TEMPERATURE_CRITICAL_MAX)
  {
    zoneB_isAirTemperatureCritical = false;
    zoneB_isAirTemperatureHot = true;

    Serial.print(F("ELEVATED: "));
    Serial.println(ZONEB_AIR_THERMOMETER.readTemperature());

    return false;
  }
  // if temperature is below max (normal)
  else
  {
    zoneB_isAirTemperatureCritical = false;
    zoneB_isAirTemperatureHot = false;

    Serial.print(F("NORMAL: "));
    Serial.println(ZONEB_AIR_THERMOMETER.readTemperature());

    return true;
  }
}

// ZONE B WIND CONTROL LOGIC
void CycleAllWindFans()
{ // if hardware is currently enabled
  if (canWindFlow == true)
  { // check if reservoir is overheating
    if (zoneB_isAirHumidityCritical == true || zoneB_isAirHumidityHot == true || zoneB_isAirTemperatureCritical == true || zoneB_isAirTemperatureHot == true)
    {
      Serial.println(F("Attempting to cycle Wind fan."));
      if (windFanState == false)
      {
        // turn the pump on
        digitalWrite(WINDFAN_1_PIN, HIGH);
        windFanState = true;
        Serial.println(F("Wind fan is on."));
      }
    }
  }
  else if (zoneB_isAirHumidityCritical == false || zoneB_isAirHumidityHot == true || zoneB_isAirTemperatureCritical == true || zoneB_isAirTemperatureHot == true)
  {
    Serial.println(F("Attempting to cycle Wind fan."));
    if (windFanState == true)
    {
      digitalWrite(WINDFAN_1_PIN, LOW);
      // TODO: track current state of the pump
      windFanState = false;
      Serial.println(F("Wind fan is off."));
    }
  }

  if (windFanState == true && canWindFlow == false)
  {
    digitalWrite(WINDFAN_1_PIN, LOW);
    // TODO: track current state of the pump
    windFanState = false;
    Serial.println(F("Wind fan is off."));
  }
}

// ZONE C
// ZONE C ENVIRONMENT FEEDBACK
bool Check_ZoneC_Water_Temperature()
{
  Serial.print(F("ZONE C CURRENT WATER TEMPERATURE: "));

  // if value is above critical threshold.
  if (zoneC_currentWaterTemperature >= ZONEC_WATER_TEMPERATURE_CRITICAL)
  {
    // TODO: trigger critical alert (critical alert should stop all pumps.)
    zoneC_isWaterTemperatureCritical = true;
    zoneC_isWaterTemperatureHot = true;

    Serial.print(F("CRITICAL: "));
    Serial.println(zoneC_currentWaterTemperature);

    return false;
  }
  // if temperature is above the max allowed
  else if (zoneC_currentWaterTemperature >= ZONEC_WATER_TEMPERATURE_MAX && zoneC_currentWaterTemperature < ZONEC_WATER_TEMPERATURE_CRITICAL)
  {
    zoneC_isWaterTemperatureCritical = false;
    zoneC_isWaterTemperatureHot = true;

    Serial.print(F("ELEVATED: "));
    Serial.println(zoneC_currentWaterTemperature);

    return false;
  }
  else
  {
    zoneC_isWaterTemperatureCritical = false;
    zoneC_isWaterTemperatureHot = false;

    Serial.print(F("NORMAL: "));
    Serial.println(zoneC_currentWaterTemperature);

    return true;
  }
}

bool Check_ZoneC_Air_Humidity()
{
  Serial.print(F("ZONE C CURRENT AIR HUMIDITY: "));

  // if value is above critical threshold.
  if (ZONEC_AIR_THERMOMETER.readHumidity() >= ZONEC_AIR_HUMIDITY_CRITICAL_MAX)
  {
    // TODO: trigger critical alert (critical alert should stop all pumps.)
    zoneC_isAirHumidityCritical = true;
    zoneC_isAirHumidityHot = true;

    Serial.print(F("CRITICAL: "));
    Serial.println(ZONEC_AIR_THERMOMETER.readHumidity());

    return false;
  }
  // if temperature is above the max allowed
  else if (ZONEC_AIR_THERMOMETER.readTemperature() >= ZONEC_AIR_HUMIDITY_MAX && ZONEC_AIR_THERMOMETER.readTemperature() < ZONEC_AIR_HUMIDITY_CRITICAL_MAX)
  {
    zoneC_isAirHumidityCritical = false;
    zoneC_isAirHumidityHot = true;

    Serial.print(F("ELEVATED: "));
    Serial.println(ZONEC_AIR_THERMOMETER.readHumidity());

    return false;
  }
  else
  {
    zoneC_isAirHumidityCritical = false;
    zoneC_isAirHumidityHot = false;

    Serial.print(F("NORMAL: "));
    Serial.println(ZONEC_AIR_THERMOMETER.readHumidity());

    return true;
  }
}

bool Check_ZoneC_Air_Temperature()
{
  Serial.print(F("ZONE C CURRENT AIR TEMPERATURE: "));

  // if value is above critical threshold.
  if (ZONEC_AIR_THERMOMETER.readTemperature() >= ZONEC_AIR_TEMPERATURE_CRITICAL_MAX)
  {
    // TODO: trigger critical alert (critical alert should stop all pumps.)
    zoneC_isAirTemperatureCritical = true;
    zoneC_isAirTemperatureHot = true;

    Serial.print(F("CRITICAL: "));
    Serial.println(ZONEC_AIR_THERMOMETER.readTemperature());

    return false;
  }
  // if temperature is above the max allowed
  else if (ZONEC_AIR_THERMOMETER.readTemperature() >= ZONEC_AIR_TEMPERATURE_MAX && ZONEC_AIR_THERMOMETER.readTemperature() < ZONEC_AIR_TEMPERATURE_CRITICAL_MAX)
  {
    zoneC_isAirTemperatureCritical = false;
    zoneC_isAirTemperatureHot = true;

    Serial.print(F("ELEVATED: "));
    Serial.println(ZONEC_AIR_THERMOMETER.readTemperature());

    return false;
  }
  // if temperature is below max (normal)
  else
  {
    zoneC_isAirTemperatureCritical = false;
    zoneC_isAirTemperatureHot = false;

    Serial.print(F("NORMAL: "));
    Serial.println(ZONEC_AIR_THERMOMETER.readTemperature());

    return true;
  }
}

// ZONE C WATER CONTROL LOGIC
void EnableWater()
{
  // if hardware is not currently enabled
  if (canWaterFlow == false)
  {
    Serial.print(F("attempting to enable water capability: "));
    // check if the current time is greater than the set on time, but in the same period.
    if (currentHour >= WATERPUMP_TIME_TURN_ON_HOUR)
    {
      // if the hardare should be enabled, enable hardware capability
      canWaterFlow = true;
#ifdef ENABLE_SERIAL_OUTPUT
      Serial.println(F("successfully enabled water!"));
#endif
    }
    else
    {
      Serial.println(F("not yet time to enable water."));
    }
  }
}

void DisableWater()
{
  // if hardware is not currently enabled
  if (canWaterFlow == true)
  {
    Serial.print(F("attempting to disable water capability: "));
    // check if the current time is greater than the set on time, but in the same period.
    if (currentHour >= WATERPUMP_TIME_TURN_OFF_HOUR)
    {
      // if the hardare should be enabled, enable hardware capability
      canWaterFlow = false;
#ifdef ENABLE_SERIAL_OUTPUT
      Serial.println(F("successfully disabled water!"));
#endif
    }
    else
    {
      Serial.println(F("not yet time to disable water."));
    }
  }
}

void CycleWaterPump()
{ // if hardware is currently enabled
  if (canWaterFlow == true)
  { // check if reservoir is overheating
    if (waterPumpState == false && zoneA_isAirHumidityCritical == true || zoneA_isAirHumidityHot == true || zoneA_isAirTemperatureCritical == true || zoneA_isAirTemperatureHot == true)
    {
      Serial.println(F("Attempting to cycle Water Pump On/Off"));
      // TODO: use ()millis to run pump for x time, x time (relay, not pwm)
      if (waterPumpState == false && currentMillis - waterTimer_previousMillis >= WATERPUMP_FREQUENCY_OFF)
      {
        // turn the pump on
        digitalWrite(WATERPUMP_PIN, HIGH);
        // TODO: track current state of the pump
        waterPumpState = true;
        // save the last time you blinked the LED
        waterTimer_previousMillis = currentMillis;
        Serial.println(F("Water pump is running."));
      }

      // TODO: use ()millis to stop pump for x time (relay, not pwm)
      if (waterPumpState == true && currentMillis - waterTimer_previousMillis >= WATERPUMP_FREQUENCY_ON)
      {
        // turn the pump off
        digitalWrite(WATERPUMP_PIN, LOW);
        // TODO: track current state of the pump
        waterPumpState = false;
        // save the last time you blinked the LED
        waterTimer_previousMillis = currentMillis;
        Serial.println(F("Water pump not running."));
      }

      // TODO: only do off cycle logic if the off frequency is 0
    }
  }
  if (canWaterFlow == false)
  {
    digitalWrite(WATERPUMP_PIN, LOW);
  }
}

// ZONE C OXYGEN CONTROL LOGIC
void EnableOxygen()
{
  // if hardware is not currently enabled
  if (canOxygenFlow == false)
  {
    Serial.print(F("attempting to enable oxygen capability: "));
    // check if the current time is greater than the set on time, but in the same period.
    if (currentHour >= OXYGENPUMP_TIME_TURN_ON_HOUR)
    {
      // if the hardare should be enabled, enable hardware capability
      canOxygenFlow = true;
#ifdef ENABLE_SERIAL_OUTPUT
      Serial.println(F("successfully enabled oxygen!"));
#endif
    }
    else
    {
      Serial.println(F("not yet time to enable oxygen."));
    }
  }
}

void DisableOxygen()
{
  // if hardware is not currently enabled
  if (canOxygenFlow == true)
  {
    Serial.print(F("attempting to disable oxygen capability: "));
    // check if the current time is greater than the set on time, but in the same period.
    if (currentHour >= OXYGENPUMP_TIME_TURN_OFF_HOUR)
    {
      // if the hardare should be enabled, enable hardware capability
      canOxygenFlow = false;
#ifdef ENABLE_SERIAL_OUTPUT
      Serial.println(F("successfully disabled oxygen!"));
#endif
    }
    else
    {
      Serial.println(F("not yet time to disable oxygen."));
    }
  }
}

void CycleOxygenPump()
{ // if hardware is currently enabled
  if (canOxygenFlow == true)
  { // check if reservoir is overheating
    if (oxygenPumpState == false && zoneC_isAirHumidityCritical == true || zoneC_isAirHumidityHot == true || zoneC_isAirTemperatureCritical == true || zoneC_isAirTemperatureHot == true)
    {
      Serial.println(F("Attempting to cycle Oxygen Pump On/Off"));
      // TODO: use ()millis to run pump for x time, x time (relay, not pwm)
      if (oxygenPumpState == false && currentMillis - oxygenTimer_previousMillis >= OXYGENPUMP_FREQUENCY_OFF)
      {
        // turn the pump on
        digitalWrite(OXYGENPUMP_PIN, HIGH);
        // TODO: track current state of the pump
        oxygenPumpState = true;
        // save the last time you blinked the LED
        oxygenTimer_previousMillis = currentMillis;
        Serial.println(F("Oxygen Pump is running."));
      }

      // TODO: use ()millis to stop pump for x time (relay, not pwm)
      if (oxygenPumpState == true && currentMillis - oxygenTimer_previousMillis >= OXYGENPUMP_FREQUENCY_ON)
      {
        // turn the pump off
        digitalWrite(OXYGENPUMP_PIN, LOW);
        // TODO: track current state of the pump
        oxygenPumpState = false;
        // save the last time you blinked the LED
        oxygenTimer_previousMillis = currentMillis;
        Serial.println(F("Oxygen Pump not running."));
      }

      // TODO: only do off cycle logic if the off frequency is 0
    }
  }
  if (canOxygenFlow == false)
  {
    digitalWrite(OXYGENPUMP_PIN, LOW);
  }
}

