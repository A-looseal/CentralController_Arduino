#line 1 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\src\\zoneb_config.h"
/* ZONE B CONSTANTS */

//AIR TEMPERATURE STUFF
#define ZONEB_AIR_SENSOR_TYPE DHT22                     //(the pin the water temperature sensor is currently connected to)
#define ZONEB_AIR_SENSOR_PIN 4                          //(the pin the water temperature sensor is currently connected to)

// TEMPERATURE
#define ZONEB_AIR_TEMPERATURE_MIN 24                    //(the maximum allowed temperature for oxygen to be enabled
#define ZONEB_AIR_TEMPERATURE_MAX 28                    //(the maximum allowed temperature for oxygen to be enabled
#define ZONEB_AIR_TEMPERATURE_CRITICAL_MIN 20           //(the maximum allowed temperature for oxygen to be enabled
#define ZONEB_AIR_TEMPERATURE_CRITICAL_MAX 30           //(the maximum allowed temperature for oxygen to be enabled

//HUMIDITY
#define ZONEB_AIR_HUMIDITY_MIN 50                       //(the maximum allowed temperature for oxygen to be enabled
#define ZONEB_AIR_HUMIDITY_MAX 90                       //(the maximum allowed temperature for oxygen to be enabled
#define ZONEB_AIR_HUMIDITY_CRITICAL_MIN 21              //(the maximum allowed temperature for oxygen to be enabled
#define ZONEB_AIR_HUMIDITY_CRITICAL_MAX 95              //(the maximum allowed temperature for oxygen to be enabled

// WATER TEMPERATURE STUFF
#define ZONEB_WATER_TEMPERATURE_SENSOR_TYPE DHT22       //(the pin the water temperature sensor is currently connected to)
#define ZONEB_WATER_TEMPERATURE_SENSOR_PIN 11                  //(the pin the water temperature sensor is currently connected to)
#define ZONEB_WATER_TEMPERATURE_MAX 29                  //(the maximum allowed temperature for oxygen to be enabled
#define ZONEB_WATER_TEMPERATURE_CRITICAL 30             //(the maximum allowed temperature for oxygen to be enabled