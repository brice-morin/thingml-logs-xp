/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing HeadlessDisplay
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "HeadlessDisplay.h"

/*****************************************************************************
 * Implementation for type : HeadlessDisplay
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void HeadlessDisplay_OnExit(int state, struct HeadlessDisplay_Instance *_instance);
//Prototypes: Message Sending
void HeadlessDisplay_send_display_displayReady(struct HeadlessDisplay_Instance *_instance);
//Prototypes: Function
void f_HeadlessDisplay_mock(struct HeadlessDisplay_Instance *_instance);
// Declaration of functions:
// Definition of function mock
void f_HeadlessDisplay_mock(struct HeadlessDisplay_Instance *_instance) {
}

// Sessions functionss:


// On Entry Actions:
void HeadlessDisplay_OnEntry(int state, struct HeadlessDisplay_Instance *_instance) {
switch(state) {
case HEADLESSDISPLAY_STATE:{
_instance->HeadlessDisplay_State = HEADLESSDISPLAY_NULL_INIT_STATE;
HeadlessDisplay_OnEntry(_instance->HeadlessDisplay_State, _instance);
break;
}
case HEADLESSDISPLAY_NULL_MOCK_STATE:{
break;
}
case HEADLESSDISPLAY_NULL_INIT_STATE:{
HeadlessDisplay_send_display_displayReady(_instance);
break;
}
default: break;
}
}

// On Exit Actions:
void HeadlessDisplay_OnExit(int state, struct HeadlessDisplay_Instance *_instance) {
switch(state) {
case HEADLESSDISPLAY_STATE:{
HeadlessDisplay_OnExit(_instance->HeadlessDisplay_State, _instance);
break;}
case HEADLESSDISPLAY_NULL_MOCK_STATE:{
break;}
case HEADLESSDISPLAY_NULL_INIT_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void HeadlessDisplay_handle_display_clear(struct HeadlessDisplay_Instance *_instance) {
if(!(_instance->active)) return;
//Region null
uint8_t HeadlessDisplay_State_event_consumed = 0;
if (_instance->HeadlessDisplay_State == HEADLESSDISPLAY_NULL_MOCK_STATE) {
if (HeadlessDisplay_State_event_consumed == 0 && 1) {
f_HeadlessDisplay_mock(_instance);
HeadlessDisplay_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
void HeadlessDisplay_handle_display_create(struct HeadlessDisplay_Instance *_instance, uint8_t xsize, uint8_t ysize) {
if(!(_instance->active)) return;
//Region null
uint8_t HeadlessDisplay_State_event_consumed = 0;
if (_instance->HeadlessDisplay_State == HEADLESSDISPLAY_NULL_MOCK_STATE) {
if (HeadlessDisplay_State_event_consumed == 0 && 1) {
f_HeadlessDisplay_mock(_instance);
HeadlessDisplay_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
void HeadlessDisplay_handle_display_update(struct HeadlessDisplay_Instance *_instance) {
if(!(_instance->active)) return;
//Region null
uint8_t HeadlessDisplay_State_event_consumed = 0;
if (_instance->HeadlessDisplay_State == HEADLESSDISPLAY_NULL_MOCK_STATE) {
if (HeadlessDisplay_State_event_consumed == 0 && 1) {
f_HeadlessDisplay_mock(_instance);
HeadlessDisplay_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
void HeadlessDisplay_handle_display_setBGColor(struct HeadlessDisplay_Instance *_instance, uint8_t r, uint8_t g, uint8_t b) {
if(!(_instance->active)) return;
//Region null
uint8_t HeadlessDisplay_State_event_consumed = 0;
if (_instance->HeadlessDisplay_State == HEADLESSDISPLAY_NULL_MOCK_STATE) {
if (HeadlessDisplay_State_event_consumed == 0 && 1) {
f_HeadlessDisplay_mock(_instance);
HeadlessDisplay_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
void HeadlessDisplay_handle_display_drawRect(struct HeadlessDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
if(!(_instance->active)) return;
//Region null
uint8_t HeadlessDisplay_State_event_consumed = 0;
if (_instance->HeadlessDisplay_State == HEADLESSDISPLAY_NULL_MOCK_STATE) {
if (HeadlessDisplay_State_event_consumed == 0 && 1) {
f_HeadlessDisplay_mock(_instance);
HeadlessDisplay_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
void HeadlessDisplay_handle_display_fillRect(struct HeadlessDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
if(!(_instance->active)) return;
//Region null
uint8_t HeadlessDisplay_State_event_consumed = 0;
if (_instance->HeadlessDisplay_State == HEADLESSDISPLAY_NULL_MOCK_STATE) {
if (HeadlessDisplay_State_event_consumed == 0 && 1) {
f_HeadlessDisplay_mock(_instance);
HeadlessDisplay_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
void HeadlessDisplay_handle_display_drawInteger(struct HeadlessDisplay_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale) {
if(!(_instance->active)) return;
//Region null
uint8_t HeadlessDisplay_State_event_consumed = 0;
if (_instance->HeadlessDisplay_State == HEADLESSDISPLAY_NULL_MOCK_STATE) {
if (HeadlessDisplay_State_event_consumed == 0 && 1) {
f_HeadlessDisplay_mock(_instance);
HeadlessDisplay_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
void HeadlessDisplay_handle_display_destroy(struct HeadlessDisplay_Instance *_instance) {
if(!(_instance->active)) return;
//Region null
uint8_t HeadlessDisplay_State_event_consumed = 0;
if (_instance->HeadlessDisplay_State == HEADLESSDISPLAY_NULL_MOCK_STATE) {
if (HeadlessDisplay_State_event_consumed == 0 && 1) {
f_HeadlessDisplay_mock(_instance);
HeadlessDisplay_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
void HeadlessDisplay_handle_display_setColor(struct HeadlessDisplay_Instance *_instance, uint8_t r, uint8_t g, uint8_t b) {
if(!(_instance->active)) return;
//Region null
uint8_t HeadlessDisplay_State_event_consumed = 0;
if (_instance->HeadlessDisplay_State == HEADLESSDISPLAY_NULL_MOCK_STATE) {
if (HeadlessDisplay_State_event_consumed == 0 && 1) {
f_HeadlessDisplay_mock(_instance);
HeadlessDisplay_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
void HeadlessDisplay_handle_display_drawThingML(struct HeadlessDisplay_Instance *_instance, uint8_t x, uint8_t y) {
if(!(_instance->active)) return;
//Region null
uint8_t HeadlessDisplay_State_event_consumed = 0;
if (_instance->HeadlessDisplay_State == HEADLESSDISPLAY_NULL_MOCK_STATE) {
if (HeadlessDisplay_State_event_consumed == 0 && 1) {
f_HeadlessDisplay_mock(_instance);
HeadlessDisplay_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
int HeadlessDisplay_handle_empty_event(struct HeadlessDisplay_Instance *_instance) {
 uint8_t empty_event_consumed = 0;
if(!(_instance->active)) return 0;
//Region null
if (_instance->HeadlessDisplay_State == HEADLESSDISPLAY_NULL_INIT_STATE) {
if (1) {
HeadlessDisplay_OnExit(HEADLESSDISPLAY_NULL_INIT_STATE, _instance);
_instance->HeadlessDisplay_State = HEADLESSDISPLAY_NULL_MOCK_STATE;
HeadlessDisplay_OnEntry(HEADLESSDISPLAY_NULL_MOCK_STATE, _instance);
return 1;
}
}
//begin dispatchEmptyToSession
//end dispatchEmptyToSession
return empty_event_consumed;
}

// Observers for outgoing messages:
void (*external_HeadlessDisplay_send_display_displayReady_listener)(struct HeadlessDisplay_Instance *)= 0x0;
void (*HeadlessDisplay_send_display_displayReady_listener)(struct HeadlessDisplay_Instance *)= 0x0;
void register_external_HeadlessDisplay_send_display_displayReady_listener(void (*_listener)(struct HeadlessDisplay_Instance *)){
external_HeadlessDisplay_send_display_displayReady_listener = _listener;
}
void register_HeadlessDisplay_send_display_displayReady_listener(void (*_listener)(struct HeadlessDisplay_Instance *)){
HeadlessDisplay_send_display_displayReady_listener = _listener;
}
void HeadlessDisplay_send_display_displayReady(struct HeadlessDisplay_Instance *_instance){
if (HeadlessDisplay_send_display_displayReady_listener != 0x0) HeadlessDisplay_send_display_displayReady_listener(_instance);
if (external_HeadlessDisplay_send_display_displayReady_listener != 0x0) external_HeadlessDisplay_send_display_displayReady_listener(_instance);
;
}



