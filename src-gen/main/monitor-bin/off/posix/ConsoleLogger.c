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
void f_ConsoleLogger_do_log(struct ConsoleLogger_Instance *_instance, uint8_t* payload, uint8_t size);
// Declaration of functions:
// Definition of function do_log
void f_ConsoleLogger_do_log(struct ConsoleLogger_Instance *_instance, uint8_t* payload, uint8_t size) {
if( !(_instance->ConsoleLogger_QUIET_var)) {
uint8_t log_type = payload[0];
if(log_type == LOGTYPE_FUNCTION_CALLED) {
fprintf(stdout, "log: function_called  [");

} else {
if(log_type == LOGTYPE_PROPERTY_CHANGED) {
fprintf(stdout, "log: property_changed [");

} else {
if(log_type == LOGTYPE_MESSAGE_LOST) {
fprintf(stdout, "log: message_lost     [");

} else {
if(log_type == LOGTYPE_MESSAGE_SENT) {
fprintf(stdout, "log: message_sent     [");

} else {
if(log_type == LOGTYPE_MESSAGE_HANDLED) {
fprintf(stdout, "log: message_handled  [");

} else {
fprintf(stdout, "log: unknown          [");

}

}

}

}

}

}
uint8_t i = 0;
while(i < size) {
uint8_t v = payload[i];
if(_instance->Logger_HAS_SIGNED_BYTE_var) {
fprintf(stdout, "%i",(v & 0xFF));

} else {
fprintf(stdout, "%i",v);

}
if( !(_instance->ConsoleLogger_QUIET_var)) {
fprintf(stdout, ",");

}
i++;

}
if( !(_instance->ConsoleLogger_QUIET_var)) {
fprintf(stdout, "]");
fprintf(stdout, "\n");

} else {
fprintf(stdout, "");
fprintf(stdout, "\n");

}
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
case LOGGER_NULL_STARTUP_STATE:{
break;
}
case LOGGER_NULL_OFF_STATE:{
break;
}
case LOGGER_NULL_ON_STATE:{
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
case LOGGER_NULL_STARTUP_STATE:{
break;}
case LOGGER_NULL_OFF_STATE:{
break;}
case LOGGER_NULL_ON_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void ConsoleLogger_handle_log_log(struct ConsoleLogger_Instance *_instance, uint8_t* payload, uint8_t size) {
if(!(_instance->active)) return;
//Region null
uint8_t Logger_State_event_consumed = 0;
if (_instance->Logger_State == LOGGER_NULL_ON_STATE) {
if (Logger_State_event_consumed == 0 && 1) {
f_ConsoleLogger_do_log(_instance, payload, size);
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



