#line 1 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\src\\zonea_config.h"
/* ZONE A CONSTANTS */

//AIR TEMPERATURE STUFF
#define ZONEA_AIR_SENSOR_TYPE DHT22                     //(the pin the water temperature sensor is currently connected to)
#define ZONEA_AIR_SENSOR_PIN 5                         //(the pin the water temperature sensor is currently connected to)

// TEMPERATURE
#define ZONEA_AIR_TEMPERATURE_MIN 24                    //(the maximum allowed temperature for oxygen to be enabled
#define ZONEA_AIR_TEMPERATURE_MAX 30                    //(the maximum allowed temperature for oxygen to be enabled
#define ZONEA_AIR_TEMPERATURE_CRITICAL_MIN 20          //(the maximum allowed temperature for oxygen to be enabled
#define ZONEA_AIR_TEMPERATURE_CRITICAL_MAX 32           //(the maximum allowed temperature for oxygen to be enabled

//HUMIDITY
#define ZONEA_AIR_HUMIDITY_MIN 30                       //(the maximum allowed temperature for oxygen to be enabled
#define ZONEA_AIR_HUMIDITY_MAX 70                       //(the maximum allowed temperature for oxygen to be enabled
#define ZONEA_AIR_HUMIDITY_CRITICAL_MIN 25              //(the maximum allowed temperature for oxygen to be enabled
#define ZONEA_AIR_HUMIDITY_CRITICAL_MAX 75              //(the maximum allowed temperature for oxygen to be enabled

// WATER TEMPERATURE STUFF
#define ZONEA_WATER_TEMPERATURE_SENSOR_TYPE DHT22       //(the pin the water temperature sensor is currently connected to)
#define ZONEA_WATER_TEMPERATURE_SENSOR_PIN 0                 //(the pin the water temperature sensor is currently connected to)
#define ZONEA_WATER_TEMPERATURE_MAX 28                  //(the maximum allowed temperature for oxygen to be enabled
#define ZONEA_WATER_TEMPERATURE_CRITICAL 30             //(the maximum allowed temperature for oxygen to be enabled