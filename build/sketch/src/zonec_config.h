#line 1 "C:\\Users\\butte\\OneDrive\\Documents\\Arduino\\Projects\\com.luhvCorp\\com.GrowTable.LuhvCorp\\CentralController_Arduino\\src\\zonec_config.h"
/* ZONE C CONSTANTS */

//AIR TEMPERATURE STUFF
#define ZONEC_AIR_SENSOR_TYPE DHT22                     //(the pin the water temperature sensor is currently connected to)
#define ZONEC_AIR_SENSOR_PIN 3                          //(the pin the water temperature sensor is currently connected to)

// TEMPERATURE
#define ZONEC_AIR_TEMPERATURE_MIN 15                    //(the maximum allowed temperature for oxygen to be enabled
#define ZONEC_AIR_TEMPERATURE_MAX 28                    //(the maximum allowed temperature for oxygen to be enabled
#define ZONEC_AIR_TEMPERATURE_CRITICAL_MIN 10           //(the maximum allowed temperature for oxygen to be enabled
#define ZONEC_AIR_TEMPERATURE_CRITICAL_MAX 30           //(the maximum allowed temperature for oxygen to be enabled

//HUMIDITY
#define ZONEC_AIR_HUMIDITY_MIN 30                       //(the maximum allowed temperature for oxygen to be enabled
#define ZONEC_AIR_HUMIDITY_MAX 100                      //(the maximum allowed temperature for oxygen to be enabled
#define ZONEC_AIR_HUMIDITY_CRITICAL_MIN 20              //(the maximum allowed temperature for oxygen to be enabled
#define ZONEC_AIR_HUMIDITY_CRITICAL_MAX 100             //(the maximum allowed temperature for oxygen to be enabled

// WATER TEMPERATURE STUFF
#define ZONEC_WATER_TEMPERATURE_SENSOR_TYPE DHT22       //(the pin the water temperature sensor is currently connected to)
#define ZONEC_WATER_TEMPERATURE_SENSOR_PIN 12                  //(the pin the water temperature sensor is currently connected to)
#define ZONEC_WATER_TEMPERATURE_MAX 26                  //(the maximum allowed temperature for oxygen to be enabled
#define ZONEC_WATER_TEMPERATURE_CRITICAL 30             //(the maximum allowed temperature for oxygen to be enabled
