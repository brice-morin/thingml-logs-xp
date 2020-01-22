/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing ConsoleLogger
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "ConsoleLogger.h"

/*****************************************************************************
 * Implementation for type : ConsoleLogger
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void Logger_OnExit(int state, struct ConsoleLogger_Instance *_instance);
//Prototypes: Message Sending
//Prototypes: Function
void f_ConsoleLogger_log_function_called(struct ConsoleLogger_Instance *_instance, char * inst, char * fn_name, char * ty, char * returns, char * params);
void f_ConsoleLogger_log_property_changed(struct ConsoleLogger_Instance *_instance, char * inst, char * prop_name, char * ty, char * old_value, char * new_value);
void f_ConsoleLogger_log_message_lost(struct ConsoleLogger_Instance *_instance, char * inst, char * port_name, char * msg_name, char * params);
void f_ConsoleLogger_log_message_sent(struct ConsoleLogger_Instance *_instance, char * inst, char * port_name, char * msg_name, char * params);
void f_ConsoleLogger_log_message_handled(struct ConsoleLogger_Instance *_instance, char * inst, char * source, char * target, char * port_name, char * msg_name, char * params);
// Declaration of functions:
// Definition of function log_function_called
void f_ConsoleLogger_log_function_called(struct ConsoleLogger_Instance *_instance, char * inst, char * fn_name, char * ty, char * returns, char * params) {
fprintf(stdout, "function_called(");
fprintf(stdout, inst);
fprintf(stdout, ", ");
fprintf(stdout, fn_name);
fprintf(stdout, ", ");
fprintf(stdout, ty);
fprintf(stdout, ", ");
fprintf(stdout, returns);
fprintf(stdout, ", ");
fprintf(stdout, params);
fprintf(stdout, ")");
fprintf(stdout, "\n");
}
// Definition of function log_property_changed
void f_ConsoleLogger_log_property_changed(struct ConsoleLogger_Instance *_instance, char * inst, char * prop_name, char * ty, char * old_value, char * new_value) {
fprintf(stdout, "property_changed(");
fprintf(stdout, inst);
fprintf(stdout, ", ");
fprintf(stdout, prop_name);
fprintf(stdout, ", ");
fprintf(stdout, ty);
fprintf(stdout, ", ");
fprintf(stdout, old_value);
fprintf(stdout, ", ");
fprintf(stdout, new_value);
fprintf(stdout, ")");
fprintf(stdout, "\n");
}
// Definition of function log_message_lost
void f_ConsoleLogger_log_message_lost(struct ConsoleLogger_Instance *_instance, char * inst, char * port_name, char * msg_name, char * params) {
fprintf(stdout, "message_lost(");
fprintf(stdout, inst);
fprintf(stdout, ", ");
fprintf(stdout, port_name);
fprintf(stdout, ", ");
fprintf(stdout, msg_name);
fprintf(stdout, ", ");
fprintf(stdout, params);
fprintf(stdout, ")");
fprintf(stdout, "\n");
}
// Definition of function log_message_sent
void f_ConsoleLogger_log_message_sent(struct ConsoleLogger_Instance *_instance, char * inst, char * port_name, char * msg_name, char * params) {
fprintf(stdout, "message_sent(");
fprintf(stdout, inst);
fprintf(stdout, ", ");
fprintf(stdout, port_name);
fprintf(stdout, ", ");
fprintf(stdout, msg_name);
fprintf(stdout, ", ");
fprintf(stdout, params);
fprintf(stdout, ")");
fprintf(stdout, "\n");
}
// Definition of function log_message_handled
void f_ConsoleLogger_log_message_handled(struct ConsoleLogger_Instance *_instance, char * inst, char * source, char * target, char * port_name, char * msg_name, char * params) {
fprintf(stdout, "message_handled(");
fprintf(stdout, inst);
fprintf(stdout, ", ");
fprintf(stdout, source);
fprintf(stdout, ", ");
fprintf(stdout, target);
fprintf(stdout, ", ");
fprintf(stdout, port_name);
fprintf(stdout, ", ");
fprintf(stdout, msg_name);
fprintf(stdout, ", ");
fprintf(stdout, params);
fprintf(stdout, ")");
fprintf(stdout, "\n");
}

// Sessions functionss:


// On Entry Actions:
void Logger_OnEntry(int state, struct ConsoleLogger_Instance *_instance) {
switch(state) {
case LOGGER_STATE:{
_instance->Logger_State = LOGGER_NULL_STARTUP_STATE;
Logger_OnEntry(_instance->Logger_State, _instance);
break;
}
case LOGGER_NULL_ON_STATE:{
break;
}
case LOGGER_NULL_STARTUP_STATE:{
break;
}
case LOGGER_NULL_OFF_STATE:{
break;
}
default: break;
}
}

// On Exit Actions:
void Logger_OnExit(int state, struct ConsoleLogger_Instance *_instance) {
switch(state) {
case LOGGER_STATE:{
Logger_OnExit(_instance->Logger_State, _instance);
break;}
case LOGGER_NULL_ON_STATE:{
break;}
case LOGGER_NULL_STARTUP_STATE:{
break;}
case LOGGER_NULL_OFF_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void ConsoleLogger_handle_log_log_off(struct ConsoleLogger_Instance *_instance) {
if(!(_instance->active)) return;
//Region null
uint8_t Logger_State_event_consumed = 0;
if (_instance->Logger_State == LOGGER_NULL_ON_STATE) {
if (Logger_State_event_consumed == 0 && 1) {
Logger_OnExit(LOGGER_NULL_ON_STATE, _instance);
_instance->Logger_State = LOGGER_NULL_OFF_STATE;
Logger_OnEntry(LOGGER_NULL_OFF_STATE, _instance);
Logger_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
void ConsoleLogger_handle_log_function_called(struct ConsoleLogger_Instance *_instance, char * inst, char * fn_name, char * ty, char * returns, char * params) {
if(!(_instance->active)) return;
//Region null
uint8_t Logger_State_event_consumed = 0;
if (_instance->Logger_State == LOGGER_NULL_ON_STATE) {
if (Logger_State_event_consumed == 0 && 1) {
f_ConsoleLogger_log_function_called(_instance, inst, fn_name, ty, returns, params);
Logger_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
void ConsoleLogger_handle_log_message_sent(struct ConsoleLogger_Instance *_instance, char * inst, char * port_name, char * msg_name, char * params) {
if(!(_instance->active)) return;
//Region null
uint8_t Logger_State_event_consumed = 0;
if (_instance->Logger_State == LOGGER_NULL_ON_STATE) {
if (Logger_State_event_consumed == 0 && 1) {
f_ConsoleLogger_log_message_sent(_instance, inst, port_name, msg_name, params);
Logger_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
void ConsoleLogger_handle_log_log_on(struct ConsoleLogger_Instance *_instance) {
if(!(_instance->active)) return;
//Region null
uint8_t Logger_State_event_consumed = 0;
if (_instance->Logger_State == LOGGER_NULL_OFF_STATE) {
if (Logger_State_event_consumed == 0 && 1) {
Logger_OnExit(LOGGER_NULL_OFF_STATE, _instance);
_instance->Logger_State = LOGGER_NULL_ON_STATE;
Logger_OnEntry(LOGGER_NULL_ON_STATE, _instance);
Logger_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
void ConsoleLogger_handle_log_message_lost(struct ConsoleLogger_Instance *_instance, char * inst, char * port_name, char * msg_name, char * params) {
if(!(_instance->active)) return;
//Region null
uint8_t Logger_State_event_consumed = 0;
if (_instance->Logger_State == LOGGER_NULL_ON_STATE) {
if (Logger_State_event_consumed == 0 && 1) {
f_ConsoleLogger_log_message_lost(_instance, inst, port_name, msg_name, params);
Logger_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
void ConsoleLogger_handle_log_property_changed(struct ConsoleLogger_Instance *_instance, char * inst, char * prop_name, char * ty, char * old_value, char * new_value) {
if(!(_instance->active)) return;
//Region null
uint8_t Logger_State_event_consumed = 0;
if (_instance->Logger_State == LOGGER_NULL_ON_STATE) {
if (Logger_State_event_consumed == 0 && 1) {
f_ConsoleLogger_log_property_changed(_instance, inst, prop_name, ty, old_value, new_value);
Logger_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
void ConsoleLogger_handle_log_message_handled(struct ConsoleLogger_Instance *_instance, char * inst, char * source, char * target, char * port_name, char * msg_name, char * params) {
if(!(_instance->active)) return;
//Region null
uint8_t Logger_State_event_consumed = 0;
if (_instance->Logger_State == LOGGER_NULL_ON_STATE) {
if (Logger_State_event_consumed == 0 && 1) {
f_ConsoleLogger_log_message_handled(_instance, inst, source, target, port_name, msg_name, params);
Logger_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
int ConsoleLogger_handle_empty_event(struct ConsoleLogger_Instance *_instance) {
 uint8_t empty_event_consumed = 0;
if(!(_instance->active)) return 0;
//Region null
if (_instance->Logger_State == LOGGER_NULL_STARTUP_STATE) {
if (_instance->Logger_ACTIVATE_ON_STARTUP_var) {
Logger_OnExit(LOGGER_NULL_STARTUP_STATE, _instance);
_instance->Logger_State = LOGGER_NULL_ON_STATE;
Logger_OnEntry(LOGGER_NULL_ON_STATE, _instance);
return 1;
}
else if ( !(_instance->Logger_ACTIVATE_ON_STARTUP_var)) {
Logger_OnExit(LOGGER_NULL_STARTUP_STATE, _instance);
_instance->Logger_State = LOGGER_NULL_OFF_STATE;
Logger_OnEntry(LOGGER_NULL_OFF_STATE, _instance);
return 1;
}
}
//begin dispatchEmptyToSession
//end dispatchEmptyToSession
return empty_event_consumed;
}

// Observers for outgoing messages:



