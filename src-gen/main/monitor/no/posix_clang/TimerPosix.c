/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing TimerPosix
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "TimerPosix.h"

/*****************************************************************************
 * Implementation for type : TimerPosix
 *****************************************************************************/


// BEGIN: Code from the c_global annotation TimerPosix
uint32_t Timer_timeouts[NB_SOFT_TIMERS];
uint8_t  Timer_wraps[NB_SOFT_TIMERS];
uint32_t Timer_prev;
pthread_mutex_t Timer_mut;
// END: Code from the c_global annotation TimerPosix

// Declaration of prototypes:
//Prototypes: State Machine
void TimerPosix_SoftTimer_OnExit(int state, struct TimerPosix_Instance *_instance);
//Prototypes: Message Sending
void TimerPosix_send_timer_timer_timeout(struct TimerPosix_Instance *_instance, uint8_t id);
//Prototypes: Function
uint32_t f_TimerPosix_time_ms(struct TimerPosix_Instance *_instance);
void f_TimerPosix_sleep_ms(struct TimerPosix_Instance *_instance, uint16_t timeout_ms);
void f_TimerPosix_initialize(struct TimerPosix_Instance *_instance);
void f_TimerPosix_start_soft_timer_process(struct TimerPosix_Instance *_instance);
void f_TimerPosix_startTimer(struct TimerPosix_Instance *_instance, uint8_t id, uint16_t delay);
void f_TimerPosix_cancel(struct TimerPosix_Instance *_instance, uint8_t id);
// Declaration of functions:
// Definition of function time_ms
uint32_t f_TimerPosix_time_ms(struct TimerPosix_Instance *_instance) {
struct timespec current;
		int res;
		uint32_t millis = 0;
		
		res = clock_gettime(CLOCK_MONOTONIC, &current);
		if (res != 0) {
			  perror("[ERROR]: Could not get current time : ");
		 } else {
			  millis  =  current.tv_sec * 1000;
			  millis += current.tv_nsec / 1000000;
		}
return millis;
}
// Definition of function sleep_ms
void f_TimerPosix_sleep_ms(struct TimerPosix_Instance *_instance, uint16_t timeout_ms) {
struct timeval tv;
        tv.tv_sec = timeout_ms/1000;
        tv.tv_usec = (timeout_ms%1000) * 1000;
        select(0, NULL, NULL, NULL, &tv);
}
// Definition of function initialize
void f_TimerPosix_initialize(struct TimerPosix_Instance *_instance) {
pthread_mutex_init(&Timer_mut, NULL);
	    uint8_t i;
	    for (i = 0; i < _instance->TimerPosix_NB_SOFT_TIMERS_var; i++) {
	        Timer_timeouts[i] = 0;
	        Timer_wraps[i] = 0;
	    }
f_TimerPosix_start_soft_timer_process(_instance);
}
// Fork a thread to execute the function f_TimerPosix_start_soft_timer_process

// Struct for the parameters of the function  f_TimerPosix_start_soft_timer_process
struct f_TimerPosix_start_soft_timer_process_struct {
  struct TimerPosix_Instance *_instance;

  pthread_mutex_t *lock;
  pthread_cond_t *cv;
};

// Definition of function start_receiver_process (executed in a separate thread)
void f_TimerPosix_start_soft_timer_process_run(struct TimerPosix_Instance *_instance)
{
  Timer_prev = f_TimerPosix_time_ms(_instance);
while(1) {
f_TimerPosix_sleep_ms(_instance, _instance->TimerPosix_SOFT_TIMER_PERIOD_var);
pthread_mutex_lock(&Timer_mut);
	        uint32_t current = f_TimerPosix_time_ms(_instance);
	        uint8_t i;
	        for (i = 0; i < _instance->TimerPosix_NB_SOFT_TIMERS_var; i++) {
	            if (Timer_timeouts[i] > 0) {
	                if (current >= Timer_prev) {
	                    // Normal time progression
	                    if (current > Timer_timeouts[i] && Timer_wraps[i] == 0) {
TimerPosix_send_timer_timer_timeout(_instance, i);
Timer_timeouts[i] = 0;
	                        Timer_wraps[i] = 0;
	                    }
	                } else {
	                    // A wraparound has occurred
	                    if (Timer_wraps[i] == 0) {
TimerPosix_send_timer_timer_timeout(_instance, i);
Timer_timeouts[i] = 0;
	                    } else {
	                        Timer_wraps[i] = 0;
	                        if (current > Timer_timeouts[i]) {
TimerPosix_send_timer_timer_timeout(_instance, i);
Timer_timeouts[i] = 0;
	                        }
	                    }
	                }
	            }
	        }
	        Timer_prev = current;
	        pthread_mutex_unlock(&Timer_mut);

}

}


void f_TimerPosix_start_soft_timer_process_proc(void * p)
{
  // Get parameters from the main thread
  struct f_TimerPosix_start_soft_timer_process_struct params = *((struct f_TimerPosix_start_soft_timer_process_struct *) p);
  
  // Unblock the main thread
  pthread_mutex_lock(params.lock);
  pthread_cond_signal(params.cv);
  pthread_mutex_unlock(params.lock);
  
  // Run the function
  //f_TimerPosix_start_soft_timer_process_run(params._instance, params.esums_device);
  f_TimerPosix_start_soft_timer_process_run(params._instance);
}

// Operation called by the runtime and forking a new thread
void f_TimerPosix_start_soft_timer_process(struct TimerPosix_Instance *_instance)
{
  // Store parameters
  struct f_TimerPosix_start_soft_timer_process_struct params;
  pthread_mutex_t lock;
  pthread_cond_t cv;
  params.lock = &lock;
  params.cv = &cv;
  params._instance = _instance;

  pthread_mutex_init(params.lock, NULL);
  pthread_cond_init(params.cv, NULL);
  //Start the new thread
  pthread_mutex_lock(params.lock);
  pthread_t thread; 
  pthread_create( &thread, NULL, f_TimerPosix_start_soft_timer_process_proc, (void*) &params);
  // Wait until it has started and read its parameters
  pthread_cond_wait(params.cv, params.lock);
  // Realease mutex
  pthread_mutex_unlock(params.lock);
}// Definition of function startTimer
void f_TimerPosix_startTimer(struct TimerPosix_Instance *_instance, uint8_t id, uint16_t delay) {

    	if (id < NB_SOFT_TIMERS) {
	        uint32_t current = f_TimerPosix_time_ms(_instance);
	        uint32_t timeout = current + delay;
	        if (timeout == 0) timeout = 1;
	
	        pthread_mutex_lock(&Timer_mut);
	        Timer_timeouts[id] = timeout;
	        Timer_wraps[id] = (timeout > current) ? 0 : 1;
	        pthread_mutex_unlock(&Timer_mut);
	    }
    
}
// Definition of function cancel
void f_TimerPosix_cancel(struct TimerPosix_Instance *_instance, uint8_t id) {

        if (id < NB_SOFT_TIMERS) {
	        pthread_mutex_lock(&Timer_mut);
	        Timer_timeouts[id] = 0;
	        Timer_wraps[id] = 0;
	        pthread_mutex_unlock(&Timer_mut);
	    }
      
}

// Sessions functionss:


// On Entry Actions:
void TimerPosix_SoftTimer_OnEntry(int state, struct TimerPosix_Instance *_instance) {
switch(state) {
case TIMERPOSIX_SOFTTIMER_STATE:{
_instance->TimerPosix_SoftTimer_State = TIMERPOSIX_SOFTTIMER_DEFAULT_STATE;
f_TimerPosix_start_soft_timer_process(_instance);
TimerPosix_SoftTimer_OnEntry(_instance->TimerPosix_SoftTimer_State, _instance);
break;
}
case TIMERPOSIX_SOFTTIMER_DEFAULT_STATE:{
break;
}
default: break;
}
}

// On Exit Actions:
void TimerPosix_SoftTimer_OnExit(int state, struct TimerPosix_Instance *_instance) {
switch(state) {
case TIMERPOSIX_SOFTTIMER_STATE:{
TimerPosix_SoftTimer_OnExit(_instance->TimerPosix_SoftTimer_State, _instance);
break;}
case TIMERPOSIX_SOFTTIMER_DEFAULT_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void TimerPosix_handle_timer_timer_cancel(struct TimerPosix_Instance *_instance, uint8_t id) {
if(!(_instance->active)) return;
//Region SoftTimer
uint8_t TimerPosix_SoftTimer_State_event_consumed = 0;
if (_instance->TimerPosix_SoftTimer_State == TIMERPOSIX_SOFTTIMER_DEFAULT_STATE) {
if (TimerPosix_SoftTimer_State_event_consumed == 0 && 1) {
f_TimerPosix_cancel(_instance, id);
TimerPosix_SoftTimer_State_event_consumed = 1;
}
}
//End Region SoftTimer
//End dsregion SoftTimer
//Session list: 
}
void TimerPosix_handle_timer_timer_start(struct TimerPosix_Instance *_instance, uint8_t id, uint16_t time) {
if(!(_instance->active)) return;
//Region SoftTimer
uint8_t TimerPosix_SoftTimer_State_event_consumed = 0;
if (_instance->TimerPosix_SoftTimer_State == TIMERPOSIX_SOFTTIMER_DEFAULT_STATE) {
if (TimerPosix_SoftTimer_State_event_consumed == 0 && time > 0) {
f_TimerPosix_startTimer(_instance, id, time);
TimerPosix_SoftTimer_State_event_consumed = 1;
}
else if (TimerPosix_SoftTimer_State_event_consumed == 0 && time == 0) {
TimerPosix_send_timer_timer_timeout(_instance, id);
TimerPosix_SoftTimer_State_event_consumed = 1;
}
}
//End Region SoftTimer
//End dsregion SoftTimer
//Session list: 
}

// Observers for outgoing messages:
void (*external_TimerPosix_send_timer_timer_timeout_listener)(struct TimerPosix_Instance *, uint8_t)= 0x0;
void (*TimerPosix_send_timer_timer_timeout_listener)(struct TimerPosix_Instance *, uint8_t)= 0x0;
void register_external_TimerPosix_send_timer_timer_timeout_listener(void (*_listener)(struct TimerPosix_Instance *, uint8_t)){
external_TimerPosix_send_timer_timer_timeout_listener = _listener;
}
void register_TimerPosix_send_timer_timer_timeout_listener(void (*_listener)(struct TimerPosix_Instance *, uint8_t)){
TimerPosix_send_timer_timer_timeout_listener = _listener;
}
void TimerPosix_send_timer_timer_timeout(struct TimerPosix_Instance *_instance, uint8_t id){
if (TimerPosix_send_timer_timer_timeout_listener != 0x0) TimerPosix_send_timer_timer_timeout_listener(_instance, id);
if (external_TimerPosix_send_timer_timer_timeout_listener != 0x0) external_TimerPosix_send_timer_timer_timeout_listener(_instance, id);
;
}



