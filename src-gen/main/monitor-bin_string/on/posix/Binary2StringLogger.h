/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing Binary2StringLogger
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef Binary2StringLogger_H_
#define Binary2StringLogger_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : Binary2StringLogger
 *****************************************************************************/

// Definition of the instance struct:
struct Binary2StringLogger_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_log;
// Variables for the current instance state
int Logger_State;
// Variables for the properties of the instance
bool Logger_ACTIVATE_ON_STARTUP_var;
bool Logger_HAS_SIGNED_BYTE_var;

};
// Declaration of prototypes outgoing messages :
void Logger_OnEntry(int state, struct Binary2StringLogger_Instance *_instance);
void Binary2StringLogger_handle_log_log_on(struct Binary2StringLogger_Instance *_instance);
void Binary2StringLogger_handle_log_log(struct Binary2StringLogger_Instance *_instance, uint8_t* payload, uint8_t size);
void Binary2StringLogger_handle_log_log_off(struct Binary2StringLogger_Instance *_instance);
// Declaration of callbacks for incoming messages:

// Definition of the states:
#define LOGGER_NULL_OFF_STATE 0
#define LOGGER_NULL_ON_STATE 1
#define LOGGER_STATE 2
#define LOGGER_NULL_STARTUP_STATE 3



#ifdef __cplusplus
}
#endif

#endif //Binary2StringLogger_H_
