/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing ConsoleLogger
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef ConsoleLogger_H_
#define ConsoleLogger_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : ConsoleLogger
 *****************************************************************************/

// Definition of the instance struct:
struct ConsoleLogger_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_log;
// Variables for the current instance state
int Logger_State;
// Variables for the properties of the instance
bool Logger_ACTIVATE_ON_STARTUP_var;

};
// Declaration of prototypes outgoing messages :
void Logger_OnEntry(int state, struct ConsoleLogger_Instance *_instance);
void ConsoleLogger_handle_log_log_off(struct ConsoleLogger_Instance *_instance);
void ConsoleLogger_handle_log_function_called(struct ConsoleLogger_Instance *_instance, char * inst, char * fn_name, char * ty, char * returns, char * params);
void ConsoleLogger_handle_log_message_sent(struct ConsoleLogger_Instance *_instance, char * inst, char * port_name, char * msg_name, char * params);
void ConsoleLogger_handle_log_log_on(struct ConsoleLogger_Instance *_instance);
void ConsoleLogger_handle_log_message_lost(struct ConsoleLogger_Instance *_instance, char * inst, char * port_name, char * msg_name, char * params);
void ConsoleLogger_handle_log_property_changed(struct ConsoleLogger_Instance *_instance, char * inst, char * prop_name, char * ty, char * old_value, char * new_value);
void ConsoleLogger_handle_log_message_handled(struct ConsoleLogger_Instance *_instance, char * inst, char * source, char * target, char * port_name, char * msg_name, char * params);
// Declaration of callbacks for incoming messages:

// Definition of the states:
#define LOGGER_NULL_ON_STATE 0
#define LOGGER_NULL_STARTUP_STATE 1
#define LOGGER_NULL_OFF_STATE 2
#define LOGGER_STATE 3



#ifdef __cplusplus
}
#endif

#endif //ConsoleLogger_H_
