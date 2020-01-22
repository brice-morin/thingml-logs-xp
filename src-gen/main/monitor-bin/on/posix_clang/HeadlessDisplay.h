/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing HeadlessDisplay
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef HeadlessDisplay_H_
#define HeadlessDisplay_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : HeadlessDisplay
 *****************************************************************************/

// Definition of the instance struct:
struct HeadlessDisplay_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_display;
// Variables for the current instance state
int HeadlessDisplay_State;
// Variables for the properties of the instance

};
// Declaration of prototypes outgoing messages :
void HeadlessDisplay_OnEntry(int state, struct HeadlessDisplay_Instance *_instance);
void HeadlessDisplay_handle_display_clear(struct HeadlessDisplay_Instance *_instance);
void HeadlessDisplay_handle_display_drawThingML(struct HeadlessDisplay_Instance *_instance, uint8_t x, uint8_t y);
void HeadlessDisplay_handle_display_destroy(struct HeadlessDisplay_Instance *_instance);
void HeadlessDisplay_handle_display_fillRect(struct HeadlessDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void HeadlessDisplay_handle_display_drawInteger(struct HeadlessDisplay_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale);
void HeadlessDisplay_handle_display_update(struct HeadlessDisplay_Instance *_instance);
void HeadlessDisplay_handle_display_setBGColor(struct HeadlessDisplay_Instance *_instance, uint8_t r, uint8_t g, uint8_t b);
void HeadlessDisplay_handle_display_setColor(struct HeadlessDisplay_Instance *_instance, uint8_t r, uint8_t g, uint8_t b);
void HeadlessDisplay_handle_display_drawRect(struct HeadlessDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void HeadlessDisplay_handle_display_create(struct HeadlessDisplay_Instance *_instance, uint8_t xsize, uint8_t ysize);
// Declaration of callbacks for incoming messages:
void register_HeadlessDisplay_send_display_displayReady_listener(void (*_listener)(struct HeadlessDisplay_Instance *));
void register_external_HeadlessDisplay_send_display_displayReady_listener(void (*_listener)(struct HeadlessDisplay_Instance *));

// Definition of the states:
#define HEADLESSDISPLAY_NULL_MOCK_STATE 0
#define HEADLESSDISPLAY_NULL_INIT_STATE 1
#define HEADLESSDISPLAY_STATE 2



#ifdef __cplusplus
}
#endif

#endif //HeadlessDisplay_H_
