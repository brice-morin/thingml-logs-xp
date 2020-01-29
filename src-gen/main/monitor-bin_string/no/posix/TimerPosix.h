/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing TimerPosix
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef TimerPosix_H_
#define TimerPosix_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : TimerPosix
 *****************************************************************************/


// BEGIN: Code from the c_header annotation TimerPosix

#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define NB_SOFT_TIMERS 16

// END: Code from the c_header annotation TimerPosix

// Definition of the instance struct:
struct TimerPosix_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_timer;
// Variables for the current instance state
int TimerPosix_SoftTimer_State;
// Variables for the properties of the instance
uint16_t TimerPosix_NB_SOFT_TIMERS_var;
uint16_t TimerPosix_SOFT_TIMER_PERIOD_var;

};
// Declaration of prototypes outgoing messages :
void TimerPosix_SoftTimer_OnEntry(int state, struct TimerPosix_Instance *_instance);
void TimerPosix_handle_timer_timer_start(struct TimerPosix_Instance *_instance, uint8_t id, uint16_t time);
void TimerPosix_handle_timer_timer_cancel(struct TimerPosix_Instance *_instance, uint8_t id);
// Declaration of callbacks for incoming messages:
void register_TimerPosix_send_timer_timer_timeout_listener(void (*_listener)(struct TimerPosix_Instance *, uint8_t));
void register_external_TimerPosix_send_timer_timer_timeout_listener(void (*_listener)(struct TimerPosix_Instance *, uint8_t));

// Definition of the states:
#define TIMERPOSIX_SOFTTIMER_STATE 0
#define TIMERPOSIX_SOFTTIMER_DEFAULT_STATE 1



#ifdef __cplusplus
}
#endif

#endif //TimerPosix_H_
