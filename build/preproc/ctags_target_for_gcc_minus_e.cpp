# 1 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
# 2 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 2
# 3 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 2
# 4 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 2
# 5 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 2
# 6 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 2

# 8 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 2
# 9 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 2
# 10 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 2

# 12 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 2
# 13 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 2
# 14 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 2
# 15 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 2
# 16 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 2
# 17 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 2



/* EXHAUST FAN VARIABLES */
unsigned long exhaustFanTimer_previousMillis = 0; // will store last time LED was updated
bool canExhaustFlow = true; //(dynamically control whether the pump can be activated or not. Set by the clock)
bool exhaustFanState = false; //(the current state of the water pump)

/* INTAKE FAN VARIABLES */
unsigned long intakeFanTimer_previousMillis = 0; // will store last time LED was updated
bool canIntakeFlow = true; //(dynamically control whether the pump can be activated or not. Set by the clock)
bool intakeFanState = false; //(the current state of the water pump)

/* WIND FAN VARIABLES */
unsigned long windFanTimer_previousMillis = 0; // will store last time LED was updated
bool canWindFlow = true; //(dynamically control whether the pump can be activated or not. Set by the clock)
bool windFanState = false; //(the current state of the water pump)

/* SUN LIGHT VARIABLES */
unsigned long sunTimer_previousMillis = 0; // will store last time LED was updated
bool canSunShine = false; //(dynamically control whether the pump can be activated or not. Set by the clock)
bool sunLightState = false; //(the current state of the water pump)

/* WATER PUMP VARIABLES */
unsigned long waterTimer_previousMillis = 0; // will store last time LED was updated
bool canWaterFlow = false; //(dynamically control whether the pump can be activated or not. Set by the clock)
bool waterPumpState = false; //(the current state of the water pump)

/* OXYGEN PUMP VARIABLES*/
unsigned long oxygenTimer_previousMillis = 0; // will store last time LED was updated
bool canOxygenFlow = false; //(dynamically control whether the pump can be activated or not. Set by the clock)
bool oxygenPumpState = false; //(the current state of the water pump)

/* ZONE A VARIABLES*/
bool zoneA_isAirTemperatureHot = false;
bool zoneA_isAirTemperatureCritical = false;
bool zoneA_isAirHumidityHot = false;
bool zoneA_isAirHumidityCritical = false;
float zoneA_currentWaterTemperature;
bool zoneA_isWaterTemperatureHot = false;
bool zoneA_isWaterTemperatureCritical = false;
DHT ZONEA_AIR_THERMOMETER(5 /*(the pin the water temperature sensor is currently connected to)*/, DHT22 /*(the pin the water temperature sensor is currently connected to)*/);

/* ZONE B VARIABLES*/
bool zoneB_isAirTemperatureHot = false;
bool zoneB_isAirTemperatureCritical = false;
bool zoneB_isAirHumidityHot = false;
bool zoneB_isAirHumidityCritical = false;
float zoneB_currentWaterTemperature;
bool zoneB_isWaterTemperatureHot = false;
bool zoneB_isWaterTemperatureCritical = false;
DHT ZONEB_AIR_THERMOMETER(4 /*(the pin the water temperature sensor is currently connected to)*/, DHT22 /*(the pin the water temperature sensor is currently connected to)*/);

/* ZONE C VARIABLES*/
bool zoneC_isAirTemperatureHot = false;
bool zoneC_isAirTemperatureCritical = false;
bool zoneC_isAirHumidityHot = false;
bool zoneC_isAirHumidityCritical = false;
float zoneC_currentWaterTemperature;
bool zoneC_isWaterTemperatureHot = false;
bool zoneC_isWaterTemperatureCritical = false;
DHT ZONEC_AIR_THERMOMETER(3 /*(the pin the water temperature sensor is currently connected to)*/, DHT22 /*(the pin the water temperature sensor is currently connected to)*/);

/*REAL TIME CLOCK VARIABLES*/
int currentHour;
int currentMinute;
RTC_DS3231 OnBoardClock; // clock object
DateTime currentTime; // current time object

/* SYSTEM CLOCK VARIABLES */
unsigned long currentMillis;

// Setup a oneWire instance to communicate with any OneWire devices
OneWire zoneA_OneWire(0 /*(the pin the water temperature sensor is currently connected to)*/);
OneWire zoneB_OneWire(11 /*(the pin the water temperature sensor is currently connected to)*/);
OneWire zoneC_OneWire(12 /*(the pin the water temperature sensor is currently connected to)*/);

// Pass our oneWire reference to Dallas Temperature sensor
DallasTemperature zoneA_WaterSensor(&zoneA_OneWire);
DallasTemperature zoneB_WaterSensor(&zoneB_OneWire);
DallasTemperature zoneC_WaterSensor(&zoneC_OneWire);

// Program Start
void setup()
{

  Serial.begin(115200);
  delay(1000);
  Serial.println("Serial Connection Established.");


  zoneA_WaterSensor.begin();
  zoneB_WaterSensor.begin();
  zoneC_WaterSensor.begin();

  // search for connected clock. Dont continue if none is found
  if (!OnBoardClock.begin())
  {

    Serial.println("Couldn't find RTC");
    Serial.flush();

    while (1)
      delay(10);
  }

  // intake fan
  pinMode(13 /*(the pin the pump is currently connected to)*/, 0x1);
  digitalWrite(13 /*(the pin the pump is currently connected to)*/, 0x0);
  // echaust fan
  pinMode(13 /*(the pin the pump is currently connected to)*/, 0x1);
  digitalWrite(13 /*(the pin the pump is currently connected to)*/, 0x0);
  // windfans
  pinMode(13 /*(the pin the pump is currently connected to)*/, 0x1);
  digitalWrite(13 /*(the pin the pump is currently connected to)*/, 0x0);
  // water pump
  pinMode(13 /*(the pin the pump is currently connected to)*/, 0x1);
  digitalWrite(13 /*(the pin the pump is currently connected to)*/, 0x0);
  // oxygen pump
  pinMode(13 /*(the pin the pump is currently connected to)*/, 0x1);
  digitalWrite(13 /*(the pin the pump is currently connected to)*/, 0x0);

  ZONEA_AIR_THERMOMETER.begin();
  ZONEB_AIR_THERMOMETER.begin();
  ZONEC_AIR_THERMOMETER.begin();

  // uncomment the following line to set the date & time to the current date and time of uploading
  // OnBoardClock.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void loop()
{

  Serial.println('\n');
  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 151 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 151 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "#########################"
# 151 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 151 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));


  // get a reading of the current time
  currentMillis = millis();
  currentTime = OnBoardClock.now();
  currentHour = (currentTime.hour());
  currentMinute = (currentTime.minute());


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


  zoneA_WaterSensor.requestTemperatures();
  zoneB_WaterSensor.requestTemperatures();
  zoneC_WaterSensor.requestTemperatures();

  zoneA_currentWaterTemperature = zoneA_WaterSensor.getTempCByIndex(0);
  zoneB_currentWaterTemperature = zoneB_WaterSensor.getTempCByIndex(0);
  zoneC_currentWaterTemperature = zoneC_WaterSensor.getTempCByIndex(0);


  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 194 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 194 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "___ZONE A___"
# 194 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 194 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));


  Check_ZoneA_Air_Humidity();
  Check_ZoneA_Air_Temperature();
  Check_ZoneA_Water_Temperature();


  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 202 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 202 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "--------------------------"
# 202 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 202 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));


  Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 205 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 205 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              "Can Exhaust Fan flow value: "
# 205 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              ); &__c[0];}))
# 205 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              )));
  Serial.println(canExhaustFlow);
  CycleExhaustFan();


  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 210 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 210 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "--------------------------"
# 210 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 210 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));


  Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 213 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 213 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              "Can Intake Fan flow value: "
# 213 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              ); &__c[0];}))
# 213 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              )));
  Serial.println(canIntakeFlow);
  CycleIntakeFan();


  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 218 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 218 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "--------------------------"
# 218 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 218 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));


  Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 221 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 221 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              "Can Sun Light Shine value: "
# 221 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              ); &__c[0];}))
# 221 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              )));
  Serial.println(canSunShine);
  // handle sun light logic
  EnableSunLight();
  DisableSunLight();
  CycleSunLight();


  Serial.println('\n');



  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 233 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 233 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "___ZONE B___"
# 233 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 233 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));


  Check_ZoneB_Air_Humidity();
  Check_ZoneB_Air_Temperature();
  Check_ZoneB_Water_Temperature();


  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 241 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 241 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "--------------------------"
# 241 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 241 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));


  Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 244 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 244 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              "Can Wind Fan flow value: "
# 244 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              ); &__c[0];}))
# 244 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              )));
  Serial.println(canWindFlow);
  CycleAllWindFans();


  Serial.println('\n');



  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 253 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 253 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "___ZONE C___"
# 253 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 253 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));


  Check_ZoneC_Air_Humidity();
  Check_ZoneC_Air_Temperature();
  Check_ZoneC_Water_Temperature();


  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 261 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 261 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "--------------------------"
# 261 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 261 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));


  Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 264 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 264 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              "Can Water Pump Flow value: "
# 264 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              ); &__c[0];}))
# 264 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              )));
  Serial.println(canWaterFlow);
  // handle reservoir water pump logic
  EnableWater();
  DisableWater();
  CycleWaterPump();


  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 272 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 272 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "--------------------------"
# 272 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 272 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));


  Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 275 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 275 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              "Can Oxygen Pump Flow value: "
# 275 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              ); &__c[0];}))
# 275 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              )));
  Serial.println(canOxygenFlow);
  // handle reservoir oxygen pump logic
  EnableOxygen();
  DisableOxygen();
  CycleOxygenPump();


  Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 283 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 283 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "#########################"
# 283 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 283 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
  Serial.println('\n');

  delay(5000);
}

/* Setup Hardware function

Written by: aLooSeal

Version: v1.0



- uses a tiny bit of logic to set the GPIO pinmode

- requires device pin, and the desired pin Mode



OUTPUT DEVICE = 'o' | INPUT DEVICE = 'i'

*/
# 298 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
void SetupHardware(byte _devicePin, char _deviceMode)
{
  if (_deviceMode == 'o')
  {

    Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 303 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 303 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                  "Device setup initialized..."
# 303 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                  ); &__c[0];}))
# 303 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                  )));

    pinMode(_devicePin, 0x1);
    digitalWrite(_devicePin, 0);

    Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 308 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 308 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                  "Device setup complete."
# 308 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                  ); &__c[0];}))
# 308 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                  )));

  }
  else if (_deviceMode == 'i')
  {

    Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 314 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 314 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                  "Device setup initialized..."
# 314 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                  ); &__c[0];}))
# 314 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                  )));

    pinMode(_devicePin, 0x0);

    Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 318 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 318 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                  "Device setup initialized..."
# 318 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                  ); &__c[0];}))
# 318 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                  )));

  }
}

// ZONE A
// ZONE A ENVIRONMENT FEEDBACK
bool Check_ZoneA_Water_Temperature()
{
  Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 327 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 327 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              "ZONE A CURRENT WATER TEMPERATURE: "
# 327 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              ); &__c[0];}))
# 327 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              )));

  // if value is above critical threshold.
  if (zoneA_currentWaterTemperature >= 30 /*(the maximum allowed temperature for oxygen to be enabled*/)
  {
    // TODO: trigger critical alert (critical alert should stop all pumps.)
    zoneA_isWaterTemperatureCritical = true;
    zoneA_isWaterTemperatureHot = true;

    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 336 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 336 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "CRITICAL: "
# 336 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 336 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
    Serial.println(zoneA_currentWaterTemperature);

    return false;
  }
  // if temperature is above the max allowed
  else if (zoneA_currentWaterTemperature >= 28 /*(the maximum allowed temperature for oxygen to be enabled*/ && zoneA_currentWaterTemperature < 30 /*(the maximum allowed temperature for oxygen to be enabled*/)
  {
    zoneA_isWaterTemperatureCritical = false;
    zoneA_isWaterTemperatureHot = true;

    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 347 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 347 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "ELEVATED: "
# 347 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 347 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
    Serial.println(zoneA_currentWaterTemperature);

    return false;
  }
  else
  {
    zoneA_isWaterTemperatureCritical = false;
    zoneA_isWaterTemperatureHot = false;

    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 357 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 357 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "NORMAL: "
# 357 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 357 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
    Serial.println(zoneA_currentWaterTemperature);

    return true;
  }
}

bool Check_ZoneA_Air_Humidity()
{
  Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 366 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 366 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              "ZONE A CURRENT AIR HUMIDITY: "
# 366 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              ); &__c[0];}))
# 366 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              )));

  // if value is above critical threshold.
  if (ZONEA_AIR_THERMOMETER.readHumidity() >= 75 /*(the maximum allowed temperature for oxygen to be enabled*/)
  {
    // TODO: trigger critical alert (critical alert should stop all pumps.)
    zoneA_isAirHumidityCritical = true;
    zoneA_isAirHumidityHot = true;
    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 374 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 374 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "CRITICAL: "
# 374 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 374 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
    Serial.println(ZONEA_AIR_THERMOMETER.readHumidity());
    return false;
  }
  // if temperature is above the max allowed
  else if (ZONEC_AIR_THERMOMETER.readHumidity() >= 70 /*(the maximum allowed temperature for oxygen to be enabled*/ && ZONEA_AIR_THERMOMETER.readHumidity() < 75 /*(the maximum allowed temperature for oxygen to be enabled*/)
  {
    zoneA_isAirHumidityCritical = false;
    zoneA_isAirHumidityHot = true;
    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 383 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 383 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "ELEVATED: "
# 383 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 383 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
    Serial.println(ZONEA_AIR_THERMOMETER.readHumidity());
    // if value is max temp threshold, disable pump
    return false;
  }
  else
  {
    zoneA_isAirHumidityCritical = false;
    zoneA_isAirHumidityHot = false;
    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 392 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 392 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "NORMAL: "
# 392 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 392 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
    Serial.println(ZONEA_AIR_THERMOMETER.readHumidity());
    //  if value is below max temp threshold, enable pump
    return true;
  }
}

bool Check_ZoneA_Air_Temperature()
{
  Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 401 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 401 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              "ZONE A CURRENT AIR TEMPERATURE: "
# 401 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              ); &__c[0];}))
# 401 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              )));

  // if value is above critical threshold.
  if (ZONEA_AIR_THERMOMETER.readTemperature() >= 32 /*(the maximum allowed temperature for oxygen to be enabled*/)
  {
    // TODO: trigger critical alert (critical alert should stop all pumps.)
    zoneA_isAirTemperatureCritical = true;
    zoneA_isAirTemperatureHot = true;

    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 410 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 410 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "CRITICAL: "
# 410 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 410 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
    Serial.println(ZONEA_AIR_THERMOMETER.readTemperature());

    return false;
  }
  // if temperature is above the max allowed
  else if (ZONEC_AIR_THERMOMETER.readTemperature() >= 30 /*(the maximum allowed temperature for oxygen to be enabled*/ && ZONEA_AIR_THERMOMETER.readTemperature() < 32 /*(the maximum allowed temperature for oxygen to be enabled*/)
  {
    zoneA_isAirTemperatureCritical = false;
    zoneA_isAirTemperatureHot = true;

    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 421 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 421 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "ELEVATED: "
# 421 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 421 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
    Serial.println(ZONEA_AIR_THERMOMETER.readTemperature());

    return false;
  }
  else
  {
    zoneA_isAirTemperatureCritical = false;
    zoneA_isAirTemperatureHot = false;

    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 431 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 431 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "NORMAL: "
# 431 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 431 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
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

    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 445 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 445 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "attempting to enable sun light capability: "
# 445 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 445 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));

    // check if the current time is greater than the set on time, but in the same period.
    if (currentHour >= 7)
    {
      // if the hardare should be enabled, enable hardware capability
      canSunShine = true;

      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 453 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 453 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    "successfully enabled sun light!"
# 453 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    ); &__c[0];}))
# 453 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    )));

    }
    else
    {

      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 459 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 459 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    "not yet time to enable sun light."
# 459 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    ); &__c[0];}))
# 459 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    )));

    }
  }
}

void DisableSunLight()
{
  // if hardware is not currently enabled
  if (canSunShine == true)
  {

    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 471 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 471 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "attempting to disable sun light capability: "
# 471 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 471 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));

    // check if the current time is greater than the set on time, but in the same period.
    if (currentHour >= 18)
    {
      // if the hardare should be enabled, enable hardware capability
      canSunShine = false;

      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 479 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 479 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    "successfully disabled sun light!"
# 479 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    ); &__c[0];}))
# 479 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    )));

    }
    else
    {

      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 485 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 485 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    "not yet time to disable sun light."
# 485 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    ); &__c[0];}))
# 485 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    )));

    }
  }
}

void CycleSunLight()
{ // if hardware is currently enabled
  if (canSunShine == true)
  { // check if reservoir is overheating
    if (sunLightState == false && zoneA_isAirHumidityCritical == true || zoneA_isAirHumidityHot == true || zoneA_isAirTemperatureCritical == true || zoneA_isAirTemperatureHot == true)
    {
      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 497 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 497 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    "Attempting to cycle sun light On/Off"
# 497 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    ); &__c[0];}))
# 497 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    )));
      // TODO: use ()millis to run pump for x time, x time (relay, not pwm)
      if (sunLightState == false && currentMillis - sunTimer_previousMillis >= 1000 /*(the amount of time to run the pump for during a cycle. In seconds)*/)
      {
        // turn the pump on
        digitalWrite(13 /*(the pin the pump is currently connected to)*/, 0x1);
        // TODO: track current state of the pump
        sunLightState = true;
        // save the last time you blinked the LED
        sunTimer_previousMillis = currentMillis;
        Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 507 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                      (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 507 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                      "sun light is on."
# 507 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                      ); &__c[0];}))
# 507 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                      )));
      }

      // TODO: use ()millis to stop pump for x time (relay, not pwm)
      if (sunLightState == true && currentMillis - sunTimer_previousMillis >= 1000 /*(the amount of time to run the pump for during a cycle. In seconds)*/)
      {
        // turn the pump off
        digitalWrite(13 /*(the pin the pump is currently connected to)*/, 0x0);
        // TODO: track current state of the pump
        sunLightState = false;
        // save the last time you blinked the LED
        sunTimer_previousMillis = currentMillis;
        Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 519 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                      (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 519 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                      "sun light is off."
# 519 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                      ); &__c[0];}))
# 519 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                      )));
      }

      // TODO: only do off cycle logic if the off frequency is 0
    }
  }
  if (canSunShine == false)
  {
    digitalWrite(13 /*(the pin the pump is currently connected to)*/, 0x0);
  }
}

// ZONE A FAN CONTROL LOGIC
void CycleIntakeFan()
{ // if hardware is currently enabled
  if (canIntakeFlow == true)
  { // check if reservoir is overheating
    if (intakeFanState == false && zoneA_isAirHumidityCritical == true || zoneA_isAirHumidityHot == true || zoneA_isAirTemperatureCritical == true || zoneA_isAirTemperatureHot == true)
    {
      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 538 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 538 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    "Attempting to cycle intake fan On"
# 538 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    ); &__c[0];}))
# 538 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    )));

      // turn the pump on
      digitalWrite(13 /*(the pin the pump is currently connected to)*/, 0x1);
      intakeFanState = true;
      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 543 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 543 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    "Intake fan is on."
# 543 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    ); &__c[0];}))
# 543 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    )));
    }
  }
  else if (intakeFanState == true && zoneA_isAirHumidityCritical == false || zoneA_isAirHumidityHot == true || zoneA_isAirTemperatureCritical == true || zoneA_isAirTemperatureHot == true)
  {
    digitalWrite(13 /*(the pin the pump is currently connected to)*/, 0x0);
    // TODO: track current state of the pump
    intakeFanState = false;
    Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 551 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 551 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                  "Intake fan is off."
# 551 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                  ); &__c[0];}))
# 551 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                  )));
  }

  if (intakeFanState == true && canIntakeFlow == false)
  {
    digitalWrite(13 /*(the pin the pump is currently connected to)*/, 0x0);
    // TODO: track current state of the pump
    intakeFanState = false;
    Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 559 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 559 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                  "Intake fan is off."
# 559 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                  ); &__c[0];}))
# 559 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                  )));
  }
}

void CycleExhaustFan()
{ // if hardware is currently enabled
  if (canExhaustFlow == true)
  { // check if reservoir is overheating
    if (intakeFanState == false && zoneA_isAirHumidityCritical == true || zoneA_isAirHumidityHot == true || zoneA_isAirTemperatureCritical == true || zoneA_isAirTemperatureHot == true)
    {
      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 569 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 569 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    "Attempting to cycle exhaust fan On"
# 569 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    ); &__c[0];}))
# 569 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    )));

      // turn the pump on
      digitalWrite(13 /*(the pin the pump is currently connected to)*/, 0x1);
      // TODO: track current state of the pump
      exhaustFanState = true;
      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 575 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 575 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    "Exhaust fan is on."
# 575 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    ); &__c[0];}))
# 575 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    )));
    }
  }
  else if (intakeFanState == true && (zoneA_isAirHumidityCritical == false && zoneA_isAirHumidityHot == false) || (zoneA_isAirTemperatureCritical == false || zoneA_isAirTemperatureHot == false))
  {
    digitalWrite(13 /*(the pin the pump is currently connected to)*/, 0x0);
    // TODO: track current state of the pump
    exhaustFanState = false;
    Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 583 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 583 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                  "Exhaust fan is off."
# 583 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                  ); &__c[0];}))
# 583 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                  )));
  }

  if (intakeFanState == true && canIntakeFlow == false)
  {
    digitalWrite(13 /*(the pin the pump is currently connected to)*/, 0x0);
    // TODO: track current state of the pump
    exhaustFanState = false;
    Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 591 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 591 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                  "Exhaust fan is off."
# 591 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                  ); &__c[0];}))
# 591 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                  )));
  }
}

// ZONE B
// ZONE B ENVIRONMENT FEEDBACK
bool Check_ZoneB_Water_Temperature()
{
  Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 599 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 599 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              "ZONE B CURRENT WATER TEMPERATURE: "
# 599 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              ); &__c[0];}))
# 599 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              )));

  // if value is above critical threshold.
  if (zoneB_currentWaterTemperature >= 30 /*(the maximum allowed temperature for oxygen to be enabled*/)
  {
    // TODO: trigger critical alert (critical alert should stop all pumps.)
    zoneB_isWaterTemperatureCritical = true;
    zoneB_isWaterTemperatureHot = true;

    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 608 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 608 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "CRITICAL: "
# 608 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 608 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
    Serial.println(zoneB_currentWaterTemperature);

    return false;
  }
  // if temperature is above the max allowed
  else if (zoneB_currentWaterTemperature >= 29 /*(the maximum allowed temperature for oxygen to be enabled*/ && zoneB_currentWaterTemperature < 30 /*(the maximum allowed temperature for oxygen to be enabled*/)
  {
    zoneB_isWaterTemperatureCritical = false;
    zoneB_isWaterTemperatureHot = true;

    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 619 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 619 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "ELEVATED: "
# 619 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 619 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
    Serial.println(zoneB_currentWaterTemperature);

    return false;
  }
  else
  {
    zoneB_isWaterTemperatureCritical = false;
    zoneB_isWaterTemperatureHot = false;

    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 629 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 629 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "NORMAL: "
# 629 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 629 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
    Serial.println(zoneB_currentWaterTemperature);

    return true;
  }
}

bool Check_ZoneB_Air_Humidity()
{
  Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 638 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 638 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              "ZONE B CURRENT AIR HUMIDITY: "
# 638 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              ); &__c[0];}))
# 638 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              )));

  // if value is above critical threshold.
  if (ZONEB_AIR_THERMOMETER.readHumidity() >= 95 /*(the maximum allowed temperature for oxygen to be enabled*/)
  {
    // TODO: trigger critical alert (critical alert should stop all pumps.)
    zoneB_isAirHumidityCritical = true;
    zoneB_isAirHumidityHot = true;

    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 647 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 647 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "CRITICAL: "
# 647 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 647 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
    Serial.println(ZONEB_AIR_THERMOMETER.readHumidity());

    return false;
  }
  // if temperature is above the max allowed
  else if (ZONEB_AIR_THERMOMETER.readHumidity() >= 90 /*(the maximum allowed temperature for oxygen to be enabled*/ && ZONEB_AIR_THERMOMETER.readHumidity() < 95 /*(the maximum allowed temperature for oxygen to be enabled*/)
  {
    zoneB_isAirHumidityCritical = false;
    zoneB_isAirHumidityHot = true;

    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 658 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 658 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "ELEVATED: "
# 658 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 658 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
    Serial.println(ZONEB_AIR_THERMOMETER.readHumidity());

    return false;
  }
  else
  {
    zoneB_isAirHumidityCritical = false;
    zoneB_isAirHumidityHot = false;

    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 668 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 668 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "NORMAL: "
# 668 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 668 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
    Serial.println(ZONEB_AIR_THERMOMETER.readHumidity());

    return true;
  }
}

bool Check_ZoneB_Air_Temperature()
{
  Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 677 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 677 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              "ZONE B CURRENT AIR TEMPERATURE: "
# 677 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              ); &__c[0];}))
# 677 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              )));

  // if value is above critical threshold.
  if (ZONEB_AIR_THERMOMETER.readTemperature() >= 30 /*(the maximum allowed temperature for oxygen to be enabled*/)
  {
    // TODO: trigger critical alert (critical alert should stop all pumps.)
    zoneB_isAirTemperatureCritical = true;
    zoneB_isAirTemperatureHot = true;

    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 686 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 686 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "CRITICAL: "
# 686 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 686 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
    Serial.println(ZONEB_AIR_THERMOMETER.readTemperature());

    return false;
  }
  // if temperature is above the max allowed
  else if (ZONEB_AIR_THERMOMETER.readTemperature() >= 28 /*(the maximum allowed temperature for oxygen to be enabled*/ && ZONEB_AIR_THERMOMETER.readTemperature() < 30 /*(the maximum allowed temperature for oxygen to be enabled*/)
  {
    zoneB_isAirTemperatureCritical = false;
    zoneB_isAirTemperatureHot = true;

    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 697 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 697 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "ELEVATED: "
# 697 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 697 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
    Serial.println(ZONEB_AIR_THERMOMETER.readTemperature());

    return false;
  }
  // if temperature is below max (normal)
  else
  {
    zoneB_isAirTemperatureCritical = false;
    zoneB_isAirTemperatureHot = false;

    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 708 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 708 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "NORMAL: "
# 708 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 708 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
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
      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 722 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 722 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    "Attempting to cycle Wind fan."
# 722 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    ); &__c[0];}))
# 722 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    )));
      if (windFanState == false)
      {
        // turn the pump on
        digitalWrite(13 /*(the pin the pump is currently connected to)*/, 0x1);
        windFanState = true;
        Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 728 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                      (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 728 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                      "Wind fan is on."
# 728 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                      ); &__c[0];}))
# 728 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                      )));
      }
    }
  }
  else if (zoneB_isAirHumidityCritical == false || zoneB_isAirHumidityHot == true || zoneB_isAirTemperatureCritical == true || zoneB_isAirTemperatureHot == true)
  {
    Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 734 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 734 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                  "Attempting to cycle Wind fan."
# 734 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                  ); &__c[0];}))
# 734 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                  )));
    if (windFanState == true)
    {
      digitalWrite(13 /*(the pin the pump is currently connected to)*/, 0x0);
      // TODO: track current state of the pump
      windFanState = false;
      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 740 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 740 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    "Wind fan is off."
# 740 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    ); &__c[0];}))
# 740 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    )));
    }
  }

  if (windFanState == true && canWindFlow == false)
  {
    digitalWrite(13 /*(the pin the pump is currently connected to)*/, 0x0);
    // TODO: track current state of the pump
    windFanState = false;
    Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 749 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                  (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 749 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                  "Wind fan is off."
# 749 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                  ); &__c[0];}))
# 749 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                  )));
  }
}

// ZONE C
// ZONE C ENVIRONMENT FEEDBACK
bool Check_ZoneC_Water_Temperature()
{
  Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 757 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 757 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              "ZONE C CURRENT WATER TEMPERATURE: "
# 757 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              ); &__c[0];}))
# 757 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              )));

  // if value is above critical threshold.
  if (zoneC_currentWaterTemperature >= 30 /*(the maximum allowed temperature for oxygen to be enabled*/)
  {
    // TODO: trigger critical alert (critical alert should stop all pumps.)
    zoneC_isWaterTemperatureCritical = true;
    zoneC_isWaterTemperatureHot = true;

    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 766 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 766 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "CRITICAL: "
# 766 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 766 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
    Serial.println(zoneC_currentWaterTemperature);

    return false;
  }
  // if temperature is above the max allowed
  else if (zoneC_currentWaterTemperature >= 26 /*(the maximum allowed temperature for oxygen to be enabled*/ && zoneC_currentWaterTemperature < 30 /*(the maximum allowed temperature for oxygen to be enabled*/)
  {
    zoneC_isWaterTemperatureCritical = false;
    zoneC_isWaterTemperatureHot = true;

    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 777 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 777 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "ELEVATED: "
# 777 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 777 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
    Serial.println(zoneC_currentWaterTemperature);

    return false;
  }
  else
  {
    zoneC_isWaterTemperatureCritical = false;
    zoneC_isWaterTemperatureHot = false;

    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 787 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 787 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "NORMAL: "
# 787 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 787 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
    Serial.println(zoneC_currentWaterTemperature);

    return true;
  }
}

bool Check_ZoneC_Air_Humidity()
{
  Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 796 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 796 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              "ZONE C CURRENT AIR HUMIDITY: "
# 796 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              ); &__c[0];}))
# 796 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              )));

  // if value is above critical threshold.
  if (ZONEC_AIR_THERMOMETER.readHumidity() >= 100 /*(the maximum allowed temperature for oxygen to be enabled*/)
  {
    // TODO: trigger critical alert (critical alert should stop all pumps.)
    zoneC_isAirHumidityCritical = true;
    zoneC_isAirHumidityHot = true;

    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 805 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 805 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "CRITICAL: "
# 805 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 805 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
    Serial.println(ZONEC_AIR_THERMOMETER.readHumidity());

    return false;
  }
  // if temperature is above the max allowed
  else if (ZONEC_AIR_THERMOMETER.readTemperature() >= 100 /*(the maximum allowed temperature for oxygen to be enabled*/ && ZONEC_AIR_THERMOMETER.readTemperature() < 100 /*(the maximum allowed temperature for oxygen to be enabled*/)
  {
    zoneC_isAirHumidityCritical = false;
    zoneC_isAirHumidityHot = true;

    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 816 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 816 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "ELEVATED: "
# 816 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 816 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
    Serial.println(ZONEC_AIR_THERMOMETER.readHumidity());

    return false;
  }
  else
  {
    zoneC_isAirHumidityCritical = false;
    zoneC_isAirHumidityHot = false;

    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 826 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 826 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "NORMAL: "
# 826 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 826 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
    Serial.println(ZONEC_AIR_THERMOMETER.readHumidity());

    return true;
  }
}

bool Check_ZoneC_Air_Temperature()
{
  Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 835 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 835 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              "ZONE C CURRENT AIR TEMPERATURE: "
# 835 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
              ); &__c[0];}))
# 835 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
              )));

  // if value is above critical threshold.
  if (ZONEC_AIR_THERMOMETER.readTemperature() >= 30 /*(the maximum allowed temperature for oxygen to be enabled*/)
  {
    // TODO: trigger critical alert (critical alert should stop all pumps.)
    zoneC_isAirTemperatureCritical = true;
    zoneC_isAirTemperatureHot = true;

    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 844 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 844 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "CRITICAL: "
# 844 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 844 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
    Serial.println(ZONEC_AIR_THERMOMETER.readTemperature());

    return false;
  }
  // if temperature is above the max allowed
  else if (ZONEC_AIR_THERMOMETER.readTemperature() >= 28 /*(the maximum allowed temperature for oxygen to be enabled*/ && ZONEC_AIR_THERMOMETER.readTemperature() < 30 /*(the maximum allowed temperature for oxygen to be enabled*/)
  {
    zoneC_isAirTemperatureCritical = false;
    zoneC_isAirTemperatureHot = true;

    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 855 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 855 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "ELEVATED: "
# 855 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 855 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
    Serial.println(ZONEC_AIR_THERMOMETER.readTemperature());

    return false;
  }
  // if temperature is below max (normal)
  else
  {
    zoneC_isAirTemperatureCritical = false;
    zoneC_isAirTemperatureHot = false;

    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 866 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 866 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "NORMAL: "
# 866 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 866 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
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
    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 879 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 879 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "attempting to enable water capability: "
# 879 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 879 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
    // check if the current time is greater than the set on time, but in the same period.
    if (currentHour >= 7)
    {
      // if the hardare should be enabled, enable hardware capability
      canWaterFlow = true;

      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 886 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 886 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    "successfully enabled water!"
# 886 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    ); &__c[0];}))
# 886 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    )));

    }
    else
    {
      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 891 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 891 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    "not yet time to enable water."
# 891 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    ); &__c[0];}))
# 891 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    )));
    }
  }
}

void DisableWater()
{
  // if hardware is not currently enabled
  if (canWaterFlow == true)
  {
    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 901 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 901 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "attempting to disable water capability: "
# 901 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 901 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
    // check if the current time is greater than the set on time, but in the same period.
    if (currentHour >= 17)
    {
      // if the hardare should be enabled, enable hardware capability
      canWaterFlow = false;

      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 908 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 908 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    "successfully disabled water!"
# 908 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    ); &__c[0];}))
# 908 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    )));

    }
    else
    {
      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 913 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 913 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    "not yet time to disable water."
# 913 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    ); &__c[0];}))
# 913 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    )));
    }
  }
}

void CycleWaterPump()
{ // if hardware is currently enabled
  if (canWaterFlow == true)
  { // check if reservoir is overheating
    if (waterPumpState == false && zoneA_isAirHumidityCritical == true || zoneA_isAirHumidityHot == true || zoneA_isAirTemperatureCritical == true || zoneA_isAirTemperatureHot == true)
    {
      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 924 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 924 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    "Attempting to cycle Water Pump On/Off"
# 924 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    ); &__c[0];}))
# 924 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    )));
      // TODO: use ()millis to run pump for x time, x time (relay, not pwm)
      if (waterPumpState == false && currentMillis - waterTimer_previousMillis >= 60000 /*(the amount of time to run the pump for during a cycle. In seconds)*/)
      {
        // turn the pump on
        digitalWrite(13 /*(the pin the pump is currently connected to)*/, 0x1);
        // TODO: track current state of the pump
        waterPumpState = true;
        // save the last time you blinked the LED
        waterTimer_previousMillis = currentMillis;
        Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 934 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                      (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 934 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                      "Water pump is running."
# 934 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                      ); &__c[0];}))
# 934 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                      )));
      }

      // TODO: use ()millis to stop pump for x time (relay, not pwm)
      if (waterPumpState == true && currentMillis - waterTimer_previousMillis >= 60000 /*(the amount of time to run the pump for during a cycle. In seconds)*/)
      {
        // turn the pump off
        digitalWrite(13 /*(the pin the pump is currently connected to)*/, 0x0);
        // TODO: track current state of the pump
        waterPumpState = false;
        // save the last time you blinked the LED
        waterTimer_previousMillis = currentMillis;
        Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 946 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                      (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 946 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                      "Water pump not running."
# 946 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                      ); &__c[0];}))
# 946 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                      )));
      }

      // TODO: only do off cycle logic if the off frequency is 0
    }
  }
  if (canWaterFlow == false)
  {
    digitalWrite(13 /*(the pin the pump is currently connected to)*/, 0x0);
  }
}

// ZONE C OXYGEN CONTROL LOGIC
void EnableOxygen()
{
  // if hardware is not currently enabled
  if (canOxygenFlow == false)
  {
    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 964 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 964 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "attempting to enable oxygen capability: "
# 964 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 964 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
    // check if the current time is greater than the set on time, but in the same period.
    if (currentHour >= 19)
    {
      // if the hardare should be enabled, enable hardware capability
      canOxygenFlow = true;

      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 971 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 971 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    "successfully enabled oxygen!"
# 971 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    ); &__c[0];}))
# 971 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    )));

    }
    else
    {
      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 976 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 976 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    "not yet time to enable oxygen."
# 976 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    ); &__c[0];}))
# 976 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    )));
    }
  }
}

void DisableOxygen()
{
  // if hardware is not currently enabled
  if (canOxygenFlow == true)
  {
    Serial.print((reinterpret_cast<const __FlashStringHelper *>(
# 986 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 986 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                "attempting to disable oxygen capability: "
# 986 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                ); &__c[0];}))
# 986 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                )));
    // check if the current time is greater than the set on time, but in the same period.
    if (currentHour >= 23)
    {
      // if the hardare should be enabled, enable hardware capability
      canOxygenFlow = false;

      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 993 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 993 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    "successfully disabled oxygen!"
# 993 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    ); &__c[0];}))
# 993 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    )));

    }
    else
    {
      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 998 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 998 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    "not yet time to disable oxygen."
# 998 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    ); &__c[0];}))
# 998 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    )));
    }
  }
}

void CycleOxygenPump()
{ // if hardware is currently enabled
  if (canOxygenFlow == true)
  { // check if reservoir is overheating
    if (oxygenPumpState == false && zoneC_isAirHumidityCritical == true || zoneC_isAirHumidityHot == true || zoneC_isAirTemperatureCritical == true || zoneC_isAirTemperatureHot == true)
    {
      Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 1009 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 1009 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    "Attempting to cycle Oxygen Pump On/Off"
# 1009 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                    ); &__c[0];}))
# 1009 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                    )));
      // TODO: use ()millis to run pump for x time, x time (relay, not pwm)
      if (oxygenPumpState == false && currentMillis - oxygenTimer_previousMillis >= 1000 /*(the amount of time to run the pump for during a cycle. In seconds)*/)
      {
        // turn the pump on
        digitalWrite(13 /*(the pin the pump is currently connected to)*/, 0x1);
        // TODO: track current state of the pump
        oxygenPumpState = true;
        // save the last time you blinked the LED
        oxygenTimer_previousMillis = currentMillis;
        Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 1019 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                      (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 1019 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                      "Oxygen Pump is running."
# 1019 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                      ); &__c[0];}))
# 1019 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                      )));
      }

      // TODO: use ()millis to stop pump for x time (relay, not pwm)
      if (oxygenPumpState == true && currentMillis - oxygenTimer_previousMillis >= 1000 /*(the amount of time to run the pump for during a cycle. In seconds)*/)
      {
        // turn the pump off
        digitalWrite(13 /*(the pin the pump is currently connected to)*/, 0x0);
        // TODO: track current state of the pump
        oxygenPumpState = false;
        // save the last time you blinked the LED
        oxygenTimer_previousMillis = currentMillis;
        Serial.println((reinterpret_cast<const __FlashStringHelper *>(
# 1031 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                      (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 1031 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                      "Oxygen Pump not running."
# 1031 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino" 3
                      ); &__c[0];}))
# 1031 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\CentralController_Arduino.ino"
                      )));
      }

      // TODO: only do off cycle logic if the off frequency is 0
    }
  }
  if (canOxygenFlow == false)
  {
    digitalWrite(13 /*(the pin the pump is currently connected to)*/, 0x0);
  }
}
