#include <stdint.h>
#include <Arduino.h>
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
void ConsoleLogger_handle_log_log_on(struct ConsoleLogger_Instance *_instance);
void ConsoleLogger_handle_log_property_changed(struct ConsoleLogger_Instance *_instance, String inst, String prop_name, String ty, String old_value, String new_value);
void ConsoleLogger_handle_log_message_handled(struct ConsoleLogger_Instance *_instance, String inst, String source, String target, String port_name, String msg_name, String params);
void ConsoleLogger_handle_log_function_called(struct ConsoleLogger_Instance *_instance, String inst, String fn_name, String ty, String returns, String params);
void ConsoleLogger_handle_log_message_sent(struct ConsoleLogger_Instance *_instance, String inst, String port_name, String msg_name, String params);
void ConsoleLogger_handle_log_log_off(struct ConsoleLogger_Instance *_instance);
void ConsoleLogger_handle_log_message_lost(struct ConsoleLogger_Instance *_instance, String inst, String port_name, String msg_name, String params);
// Declaration of callbacks for incoming messages:

// Definition of the states:
#define LOGGER_STATE 0
#define LOGGER_NULL_STARTUP_STATE 1
#define LOGGER_NULL_OFF_STATE 2
#define LOGGER_NULL_ON_STATE 3


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
void HeadlessDisplay_handle_display_update(struct HeadlessDisplay_Instance *_instance);
void HeadlessDisplay_handle_display_fillRect(struct HeadlessDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void HeadlessDisplay_handle_display_setColor(struct HeadlessDisplay_Instance *_instance, uint8_t r, uint8_t g, uint8_t b);
void HeadlessDisplay_handle_display_drawInteger(struct HeadlessDisplay_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale);
void HeadlessDisplay_handle_display_create(struct HeadlessDisplay_Instance *_instance, uint8_t xsize, uint8_t ysize);
void HeadlessDisplay_handle_display_destroy(struct HeadlessDisplay_Instance *_instance);
void HeadlessDisplay_handle_display_drawRect(struct HeadlessDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void HeadlessDisplay_handle_display_clear(struct HeadlessDisplay_Instance *_instance);
void HeadlessDisplay_handle_display_setBGColor(struct HeadlessDisplay_Instance *_instance, uint8_t r, uint8_t g, uint8_t b);
void HeadlessDisplay_handle_display_drawThingML(struct HeadlessDisplay_Instance *_instance, uint8_t x, uint8_t y);
// Declaration of callbacks for incoming messages:
void register_HeadlessDisplay_send_display_displayReady_listener(void (*_listener)(struct HeadlessDisplay_Instance *));
void register_external_HeadlessDisplay_send_display_displayReady_listener(void (*_listener)(struct HeadlessDisplay_Instance *));

// Definition of the states:
#define HEADLESSDISPLAY_NULL_MOCK_STATE 0
#define HEADLESSDISPLAY_STATE 1
#define HEADLESSDISPLAY_NULL_INIT_STATE 2


/*****************************************************************************
 * Headers for type : BasicIAController
 *****************************************************************************/

// Definition of the instance struct:
struct BasicIAController_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_controls;
uint16_t id_game;
// Variables for the current instance state
int BasicIAController_SC_State;
// Variables for the properties of the instance
int16_t BasicIAController_ctrlx_var;

};
// Declaration of prototypes outgoing messages :
void BasicIAController_SC_OnEntry(int state, struct BasicIAController_Instance *_instance);
void BasicIAController_handle_game_updateIA(struct BasicIAController_Instance *_instance, int16_t ballx, int16_t bally, int16_t padx, int16_t pady);
// Declaration of callbacks for incoming messages:
void register_BasicIAController_send_controls_position_listener(void (*_listener)(struct BasicIAController_Instance *, int16_t, int16_t));
void register_external_BasicIAController_send_controls_position_listener(void (*_listener)(struct BasicIAController_Instance *, int16_t, int16_t));

// Definition of the states:
#define BASICIACONTROLLER_SC_STATE 0
#define BASICIACONTROLLER_SC_FOLLOWING_STATE 1


/* Adds and instance to the runtime and returns its id */
uint16_t add_instance(void * instance_struct);
/* Returns the instance with id */
void * instance_by_id(uint16_t id);

/* Returns the number of byte currently in the fifo */
int fifo_byte_length();
/* Returns the number of bytes currently available in the fifo */
int fifo_byte_available();
/* Returns true if the fifo is empty */
int fifo_empty();
/* Return true if the fifo is full */
int fifo_full();
/* Enqueue 1 byte in the fifo if there is space
   returns 1 for sucess and 0 if the fifo was full */
int fifo_enqueue(byte b);
/* Enqueue 1 byte in the fifo without checking for available space
   The caller should have checked that there is enough space */
int _fifo_enqueue(byte b);
/* Dequeue 1 byte in the fifo.
   The caller should check that the fifo is not empty */
byte fifo_dequeue();
/*****************************************************************************
 * Headers for type : TimerArduino
 *****************************************************************************/


// BEGIN: Code from the c_header annotation TimerArduino
#define NB_SOFT_TIMERS 32

// END: Code from the c_header annotation TimerArduino

// Definition of the instance struct:
struct TimerArduino_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_timer;
// Variables for the current instance state
int TimerArduino_SoftTimer_State;
// Variables for the properties of the instance
uint16_t TimerArduino_NB_SOFT_TIMERS_var;

};
// Declaration of prototypes outgoing messages :
void TimerArduino_SoftTimer_OnEntry(int state, struct TimerArduino_Instance *_instance);
void TimerArduino_handle_timer_timer_cancel(struct TimerArduino_Instance *_instance, uint8_t id);
void TimerArduino_handle_timer_timer_start(struct TimerArduino_Instance *_instance, uint8_t id, uint16_t time);
// Declaration of callbacks for incoming messages:
void register_TimerArduino_send_timer_timer_timeout_listener(void (*_listener)(struct TimerArduino_Instance *, uint8_t));
void register_external_TimerArduino_send_timer_timer_timeout_listener(void (*_listener)(struct TimerArduino_Instance *, uint8_t));

// Definition of the states:
#define TIMERARDUINO_SOFTTIMER_DEFAULT_STATE 0
#define TIMERARDUINO_SOFTTIMER_STATE 1


/*****************************************************************************
 * Headers for type : BreakoutGameArduino
 *****************************************************************************/

// Definition of the instance struct:
struct BreakoutGameArduino_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_log;
uint16_t id_clock;
uint16_t id_display;
uint16_t id_controller;
uint16_t id_ia;
uint16_t id_game;
uint16_t id_req_game;
uint16_t id_pro_game;
// Variables for the current instance state
int BreakoutGame_SC_State;
// Variables for the properties of the instance
uint16_t BreakoutGame_period_var;
uint8_t BreakoutGame_counter_var;
uint32_t BreakoutGame_stopTime_var;
int16_t BreakoutGame_prevPY_var;
int16_t BreakoutGame_dy_var;
int16_t BreakoutGame_by_var;
uint32_t BreakoutGame_startTime_var;
uint8_t BreakoutGame_level_var;
int16_t BreakoutGame_TOP_var;
int16_t BreakoutGame_padlen_var;
uint8_t * BreakoutGame_fgcolor_var;
uint16_t BreakoutGame_fgcolor_var_size;
int16_t BreakoutGame_prevBX_var;
uint8_t BreakoutGame_YDISPSIZE_var;
int16_t BreakoutGame_padx_var;
uint32_t BreakoutGameArduino_RAM_SIZE_var;
int16_t BreakoutGame_br_var;
int16_t BreakoutGame_bx_var;
int16_t BreakoutGame_YMAX_var;
int16_t BreakoutGame_pady_var;
int16_t BreakoutGame_RIGHT_var;
uint8_t BreakoutGame_BRICK_HEIGHT_var;
uint8_t * BreakoutGame_bgcolor_var;
uint16_t BreakoutGame_bgcolor_var_size;
int16_t BreakoutGame_prevPX_var;
uint32_t BreakoutGame_lastTimestamp_var;
int16_t BreakoutGame_dx_var;
int16_t BreakoutGame_LEFT_var;
int16_t BreakoutGame_XMAX_var;
uint8_t BreakoutGame_XDISPSIZE_var;
uint8_t BreakoutGame_lives_var;
uint8_t BreakoutGame_SC_LAUNCH_countdown_var;
bool BreakoutGame_QUIET_var;
int16_t BreakoutGame_score_var;
int16_t BreakoutGame_BOTTOM_var;
uint8_t * BreakoutGame_bricks_var;
uint16_t BreakoutGame_bricks_var_size;
int16_t BreakoutGame_prevBY_var;
uint8_t BreakoutGame_BRICK_ROWS_var;
int16_t BreakoutGame_SCALE_var;
String WithLog_DEBUG_ID_var;

};
// Declaration of prototypes outgoing messages :
void BreakoutGame_SC_OnEntry(int state, struct BreakoutGameArduino_Instance *_instance);
void BreakoutGameArduino_handle_controller_position(struct BreakoutGameArduino_Instance *_instance, int16_t x, int16_t y);
void BreakoutGameArduino_handle_pro_game_lostBall(struct BreakoutGameArduino_Instance *_instance);
void BreakoutGameArduino_handle_pro_game_nextLevel(struct BreakoutGameArduino_Instance *_instance);
void BreakoutGameArduino_handle_game_lostBall(struct BreakoutGameArduino_Instance *_instance);
void BreakoutGameArduino_handle_game_nextLevel(struct BreakoutGameArduino_Instance *_instance);
void BreakoutGameArduino_handle_clock_timer_timeout(struct BreakoutGameArduino_Instance *_instance, uint8_t id);
void BreakoutGameArduino_handle_display_displayReady(struct BreakoutGameArduino_Instance *_instance);
// Declaration of callbacks for incoming messages:
void register_BreakoutGameArduino_send_log_function_called_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String, String));
void register_external_BreakoutGameArduino_send_log_function_called_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String, String));
void register_BreakoutGameArduino_send_log_property_changed_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String, String));
void register_external_BreakoutGameArduino_send_log_property_changed_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String, String));
void register_BreakoutGameArduino_send_log_message_lost_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String));
void register_external_BreakoutGameArduino_send_log_message_lost_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String));
void register_BreakoutGameArduino_send_log_message_handled_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String, String, String));
void register_external_BreakoutGameArduino_send_log_message_handled_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String, String, String));
void register_BreakoutGameArduino_send_log_message_sent_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String));
void register_external_BreakoutGameArduino_send_log_message_sent_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String));
void register_BreakoutGameArduino_send_clock_timer_start_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint16_t));
void register_external_BreakoutGameArduino_send_clock_timer_start_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint16_t));
void register_BreakoutGameArduino_send_clock_timer_cancel_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t));
void register_external_BreakoutGameArduino_send_clock_timer_cancel_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t));
void register_BreakoutGameArduino_send_display_create_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t));
void register_external_BreakoutGameArduino_send_display_create_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t));
void register_BreakoutGameArduino_send_display_fillRect_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t, uint8_t));
void register_external_BreakoutGameArduino_send_display_fillRect_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t, uint8_t));
void register_BreakoutGameArduino_send_display_drawRect_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t, uint8_t));
void register_external_BreakoutGameArduino_send_display_drawRect_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t, uint8_t));
void register_BreakoutGameArduino_send_display_clear_listener(void (*_listener)(struct BreakoutGameArduino_Instance *));
void register_external_BreakoutGameArduino_send_display_clear_listener(void (*_listener)(struct BreakoutGameArduino_Instance *));
void register_BreakoutGameArduino_send_display_setColor_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t));
void register_external_BreakoutGameArduino_send_display_setColor_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t));
void register_BreakoutGameArduino_send_display_setBGColor_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t));
void register_external_BreakoutGameArduino_send_display_setBGColor_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t));
void register_BreakoutGameArduino_send_display_drawInteger_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, int16_t, uint8_t, uint8_t));
void register_external_BreakoutGameArduino_send_display_drawInteger_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, int16_t, uint8_t, uint8_t));
void register_BreakoutGameArduino_send_display_update_listener(void (*_listener)(struct BreakoutGameArduino_Instance *));
void register_external_BreakoutGameArduino_send_display_update_listener(void (*_listener)(struct BreakoutGameArduino_Instance *));
void register_BreakoutGameArduino_send_display_drawThingML_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t));
void register_external_BreakoutGameArduino_send_display_drawThingML_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t));
void register_BreakoutGameArduino_send_ia_updateIA_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, int16_t, int16_t, int16_t, int16_t));
void register_external_BreakoutGameArduino_send_ia_updateIA_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, int16_t, int16_t, int16_t, int16_t));
void register_BreakoutGameArduino_send_game_lostBall_listener(void (*_listener)(struct BreakoutGameArduino_Instance *));
void register_external_BreakoutGameArduino_send_game_lostBall_listener(void (*_listener)(struct BreakoutGameArduino_Instance *));
void register_BreakoutGameArduino_send_game_nextLevel_listener(void (*_listener)(struct BreakoutGameArduino_Instance *));
void register_external_BreakoutGameArduino_send_game_nextLevel_listener(void (*_listener)(struct BreakoutGameArduino_Instance *));
void register_BreakoutGameArduino_send_req_game_lostBall_listener(void (*_listener)(struct BreakoutGameArduino_Instance *));
void register_external_BreakoutGameArduino_send_req_game_lostBall_listener(void (*_listener)(struct BreakoutGameArduino_Instance *));
void register_BreakoutGameArduino_send_req_game_nextLevel_listener(void (*_listener)(struct BreakoutGameArduino_Instance *));
void register_external_BreakoutGameArduino_send_req_game_nextLevel_listener(void (*_listener)(struct BreakoutGameArduino_Instance *));

// Definition of the states:
#define BREAKOUTGAME_SC_LOSTBALL_STATE 0
#define BREAKOUTGAME_SC_NEXTLEVEL_STATE 1
#define BREAKOUTGAME_SC_STATE 2
#define BREAKOUTGAME_SC_PLAY_STATE 3
#define BREAKOUTGAME_SC_INIT_STATE 4
#define BREAKOUTGAME_SC_LAUNCH_STATE 5
#define BREAKOUTGAME_SC_GAMEOVER_STATE 6


// Definition of Enumeration  DigitalState
#define DIGITALSTATE_LOW 0
#define DIGITALSTATE_HIGH 1


/*****************************************************************************
 * Implementation for type : BreakoutGameArduino
 *****************************************************************************/


// BEGIN: Code from the c_global annotation BreakoutGameArduino
extern "C" char* sbrk(int incr);
// END: Code from the c_global annotation BreakoutGameArduino

// Declaration of prototypes:
//Prototypes: State Machine
void BreakoutGame_SC_OnExit(int state, struct BreakoutGameArduino_Instance *_instance);
//Prototypes: Message Sending
void BreakoutGameArduino_send_log_function_called(struct BreakoutGameArduino_Instance *_instance, String inst, String fn_name, String ty, String returns, String params);
void BreakoutGameArduino_send_log_property_changed(struct BreakoutGameArduino_Instance *_instance, String inst, String prop_name, String ty, String old_value, String new_value);
void BreakoutGameArduino_send_log_message_lost(struct BreakoutGameArduino_Instance *_instance, String inst, String port_name, String msg_name, String params);
void BreakoutGameArduino_send_log_message_handled(struct BreakoutGameArduino_Instance *_instance, String inst, String source, String target, String port_name, String msg_name, String params);
void BreakoutGameArduino_send_log_message_sent(struct BreakoutGameArduino_Instance *_instance, String inst, String port_name, String msg_name, String params);
void BreakoutGameArduino_send_clock_timer_start(struct BreakoutGameArduino_Instance *_instance, uint8_t id, uint16_t time);
void BreakoutGameArduino_send_clock_timer_cancel(struct BreakoutGameArduino_Instance *_instance, uint8_t id);
void BreakoutGameArduino_send_display_create(struct BreakoutGameArduino_Instance *_instance, uint8_t xsize, uint8_t ysize);
void BreakoutGameArduino_send_display_fillRect(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void BreakoutGameArduino_send_display_drawRect(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void BreakoutGameArduino_send_display_clear(struct BreakoutGameArduino_Instance *_instance);
void BreakoutGameArduino_send_display_setColor(struct BreakoutGameArduino_Instance *_instance, uint8_t r, uint8_t g, uint8_t b);
void BreakoutGameArduino_send_display_setBGColor(struct BreakoutGameArduino_Instance *_instance, uint8_t r, uint8_t g, uint8_t b);
void BreakoutGameArduino_send_display_drawInteger(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale);
void BreakoutGameArduino_send_display_update(struct BreakoutGameArduino_Instance *_instance);
void BreakoutGameArduino_send_display_drawThingML(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y);
void BreakoutGameArduino_send_ia_updateIA(struct BreakoutGameArduino_Instance *_instance, int16_t ballx, int16_t bally, int16_t padx, int16_t pady);
void BreakoutGameArduino_send_game_lostBall(struct BreakoutGameArduino_Instance *_instance);
void BreakoutGameArduino_send_game_nextLevel(struct BreakoutGameArduino_Instance *_instance);
void BreakoutGameArduino_send_req_game_lostBall(struct BreakoutGameArduino_Instance *_instance);
void BreakoutGameArduino_send_req_game_nextLevel(struct BreakoutGameArduino_Instance *_instance);
//Prototypes: Function
void f_BreakoutGameArduino_log(struct BreakoutGameArduino_Instance *_instance, bool logMem);
void f_BreakoutGameArduino_initColors(struct BreakoutGameArduino_Instance *_instance);
void f_BreakoutGameArduino_resetBall(struct BreakoutGameArduino_Instance *_instance);
void f_BreakoutGameArduino_eraseBall(struct BreakoutGameArduino_Instance *_instance);
void f_BreakoutGameArduino_drawBall(struct BreakoutGameArduino_Instance *_instance);
void f_BreakoutGameArduino_erasePad(struct BreakoutGameArduino_Instance *_instance);
void f_BreakoutGameArduino_drawPad(struct BreakoutGameArduino_Instance *_instance);
void f_BreakoutGameArduino_drawCountDown(struct BreakoutGameArduino_Instance *_instance, int16_t c);
void f_BreakoutGameArduino_drawWalls(struct BreakoutGameArduino_Instance *_instance);
bool f_BreakoutGameArduino_bitIsSet(struct BreakoutGameArduino_Instance *_instance, uint8_t variable, uint8_t bit);
void f_BreakoutGameArduino_createBricks(struct BreakoutGameArduino_Instance *_instance);
uint8_t f_BreakoutGameArduino_bricksLeft(struct BreakoutGameArduino_Instance *_instance);
void f_BreakoutGameArduino_drawBrick(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y);
void f_BreakoutGameArduino_removeBrick(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y);
bool f_BreakoutGameArduino_collideBrick(struct BreakoutGameArduino_Instance *_instance, int16_t xpos, int16_t ypos);
void f_BreakoutGameArduino_drawLevel(struct BreakoutGameArduino_Instance *_instance);
void f_BreakoutGameArduino_incrementScore(struct BreakoutGameArduino_Instance *_instance, int8_t diff);
void f_BreakoutGameArduino_drawScore(struct BreakoutGameArduino_Instance *_instance);
void f_BreakoutGameArduino_drawLives(struct BreakoutGameArduino_Instance *_instance);
void f_BreakoutGameArduino_quit(struct BreakoutGameArduino_Instance *_instance);
uint32_t f_BreakoutGameArduino_timestamp(struct BreakoutGameArduino_Instance *_instance);
uint32_t f_BreakoutGameArduino_usedMemory(struct BreakoutGameArduino_Instance *_instance);
uint8_t f_BreakoutGameArduino_unsetBit(struct BreakoutGameArduino_Instance *_instance, uint8_t variable, uint8_t bit);
// Declaration of functions:
// Definition of function log
void f_BreakoutGameArduino_log(struct BreakoutGameArduino_Instance *_instance, bool logMem) {
if(_instance->BreakoutGame_counter_var == 0 || logMem) {
uint32_t ts;
if(_instance->BreakoutGame_lastTimestamp_var == 0) {
ts = 0;
_instance->BreakoutGame_lastTimestamp_var = f_BreakoutGameArduino_timestamp(_instance);

} else {
uint32_t t = f_BreakoutGameArduino_timestamp(_instance);
ts = t - _instance->BreakoutGame_lastTimestamp_var;
_instance->BreakoutGame_lastTimestamp_var = t;

}
if( !(_instance->BreakoutGame_QUIET_var)) {
Serial.print("ts:");
Serial.print(ts);
Serial.print(",lives:");
Serial.print(_instance->BreakoutGame_lives_var);
Serial.print(",score:");
Serial.print(_instance->BreakoutGame_score_var);
Serial.print(",level:");
Serial.print(_instance->BreakoutGame_level_var);
Serial.print(",bx:");
Serial.print(_instance->BreakoutGame_bx_var);
Serial.print(",by:");
Serial.print(_instance->BreakoutGame_by_var);
Serial.print(",padx:");
Serial.print(_instance->BreakoutGame_padx_var);
Serial.print("\n");
Serial.print("#usedMem:");
Serial.print(f_BreakoutGameArduino_usedMemory(_instance));
Serial.print("\n");

}

}
_instance->BreakoutGame_counter_var++;
if(_instance->BreakoutGame_counter_var == 33) {
_instance->BreakoutGame_counter_var = 0;

}
}
// Definition of function initColors
void f_BreakoutGameArduino_initColors(struct BreakoutGameArduino_Instance *_instance) {
BreakoutGameArduino_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "initColors", "void_", "", "");
_instance->BreakoutGame_bgcolor_var[0] = 53;
_instance->BreakoutGame_bgcolor_var[1] = 40;
_instance->BreakoutGame_bgcolor_var[2] = 120;
_instance->BreakoutGame_fgcolor_var[0] = 107;
_instance->BreakoutGame_fgcolor_var[1] = 94;
_instance->BreakoutGame_fgcolor_var[2] = 174;
uint8_t r_0 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_1 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_2 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGameArduino_send_display_setBGColor(_instance, r_0, g_1, b_2);
String params_3 = "" + ("r=" + (String(r_0) + ",")) + ("g=" + (String(g_1) + ",")) + ("b=" + (String(b_2) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setBGColor", params_3);
uint8_t r_4 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_5 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_6 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_4, g_5, b_6);
String params_7 = "" + ("r=" + (String(r_4) + ",")) + ("g=" + (String(g_5) + ",")) + ("b=" + (String(b_6) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_7);
}
// Definition of function resetBall
void f_BreakoutGameArduino_resetBall(struct BreakoutGameArduino_Instance *_instance) {
BreakoutGameArduino_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "resetBall", "void_", "", "");
String old_bx_16 = "" + String(_instance->BreakoutGame_bx_var);
_instance->BreakoutGame_bx_var = _instance->BreakoutGame_padx_var - _instance->BreakoutGame_br_var / _instance->BreakoutGame_SCALE_var;
String new_bx_16 = "" + String(_instance->BreakoutGame_bx_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "bx", "Int16", old_bx_16, new_bx_16);
String old_by_12 = "" + String(_instance->BreakoutGame_by_var);
_instance->BreakoutGame_by_var = _instance->BreakoutGame_pady_var - _instance->BreakoutGame_br_var / _instance->BreakoutGame_SCALE_var;
String new_by_12 = "" + String(_instance->BreakoutGame_by_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "by", "Int16", old_by_12, new_by_12);
String old_dx_20 = "" + String(_instance->BreakoutGame_dx_var);
_instance->BreakoutGame_dx_var = (_instance->BreakoutGame_padx_var + _instance->BreakoutGame_prevBX_var + _instance->BreakoutGame_prevBY_var) % 300 - 150;
String new_dx_20 = "" + String(_instance->BreakoutGame_dx_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "dx", "Int16", old_dx_20, new_dx_20);
if(_instance->BreakoutGame_dy_var > 0) {
String old_dy_2 = "" + String(_instance->BreakoutGame_dy_var);
_instance->BreakoutGame_dy_var =  -_instance->BreakoutGame_dy_var;
String new_dy_2 = "" + String(_instance->BreakoutGame_dy_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "dy", "Int16", old_dy_2, new_dy_2);

}
String old_prevBX_9 = "" + String(_instance->BreakoutGame_prevBX_var);
_instance->BreakoutGame_prevBX_var =  -1;
String new_prevBX_9 = "" + String(_instance->BreakoutGame_prevBX_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "prevBX", "Int16", old_prevBX_9, new_prevBX_9);
String old_prevBY_25 = "" + String(_instance->BreakoutGame_prevBY_var);
_instance->BreakoutGame_prevBY_var =  -1;
String new_prevBY_25 = "" + String(_instance->BreakoutGame_prevBY_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "prevBY", "Int16", old_prevBY_25, new_prevBY_25);
}
// Definition of function eraseBall
void f_BreakoutGameArduino_eraseBall(struct BreakoutGameArduino_Instance *_instance) {
BreakoutGameArduino_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "eraseBall", "void_", "", "");
int16_t bs = (_instance->BreakoutGame_br_var * 2) / _instance->BreakoutGame_SCALE_var;
if(_instance->BreakoutGame_prevBX_var > 0) {
uint8_t r_8 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_9 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_10 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_8, g_9, b_10);
String params_11 = "" + ("r=" + (String(r_8) + ",")) + ("g=" + (String(g_9) + ",")) + ("b=" + (String(b_10) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_11);
uint8_t x_12 = _instance->BreakoutGame_prevBX_var;
uint8_t y_13 = _instance->BreakoutGame_prevBY_var;
uint8_t width_14 = bs;
uint8_t height_15 = bs;
BreakoutGameArduino_send_display_fillRect(_instance, x_12, y_13, width_14, height_15);
String params_16 = "" + ("x=" + (String(x_12) + ",")) + ("y=" + (String(y_13) + ",")) + ("width=" + (String(width_14) + ",")) + ("height=" + (String(height_15) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_16);

}
String old_prevBX_10 = "" + String(_instance->BreakoutGame_prevBX_var);
_instance->BreakoutGame_prevBX_var =  -1;
String new_prevBX_10 = "" + String(_instance->BreakoutGame_prevBX_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "prevBX", "Int16", old_prevBX_10, new_prevBX_10);
String old_prevBY_26 = "" + String(_instance->BreakoutGame_prevBY_var);
_instance->BreakoutGame_prevBY_var =  -1;
String new_prevBY_26 = "" + String(_instance->BreakoutGame_prevBY_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "prevBY", "Int16", old_prevBY_26, new_prevBY_26);
}
// Definition of function drawBall
void f_BreakoutGameArduino_drawBall(struct BreakoutGameArduino_Instance *_instance) {
BreakoutGameArduino_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "drawBall", "void_", "", "");
int16_t bs = (_instance->BreakoutGame_br_var * 2) / _instance->BreakoutGame_SCALE_var;
f_BreakoutGameArduino_eraseBall(_instance);
String old_prevBX_11 = "" + String(_instance->BreakoutGame_prevBX_var);
_instance->BreakoutGame_prevBX_var = (_instance->BreakoutGame_bx_var - _instance->BreakoutGame_br_var) / _instance->BreakoutGame_SCALE_var;
String new_prevBX_11 = "" + String(_instance->BreakoutGame_prevBX_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "prevBX", "Int16", old_prevBX_11, new_prevBX_11);
String old_prevBY_27 = "" + String(_instance->BreakoutGame_prevBY_var);
_instance->BreakoutGame_prevBY_var = (_instance->BreakoutGame_by_var - _instance->BreakoutGame_br_var) / _instance->BreakoutGame_SCALE_var;
String new_prevBY_27 = "" + String(_instance->BreakoutGame_prevBY_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "prevBY", "Int16", old_prevBY_27, new_prevBY_27);
uint8_t r_17 = 183;
uint8_t g_18 = 199;
uint8_t b_19 = 111;
BreakoutGameArduino_send_display_setColor(_instance, r_17, g_18, b_19);
String params_20 = "" + ("r=" + (String(r_17) + ",")) + ("g=" + (String(g_18) + ",")) + ("b=" + (String(b_19) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_20);
uint8_t x_21 = _instance->BreakoutGame_prevBX_var;
uint8_t y_22 = _instance->BreakoutGame_prevBY_var;
uint8_t width_23 = bs;
uint8_t height_24 = bs;
BreakoutGameArduino_send_display_fillRect(_instance, x_21, y_22, width_23, height_24);
String params_25 = "" + ("x=" + (String(x_21) + ",")) + ("y=" + (String(y_22) + ",")) + ("width=" + (String(width_23) + ",")) + ("height=" + (String(height_24) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_25);
}
// Definition of function erasePad
void f_BreakoutGameArduino_erasePad(struct BreakoutGameArduino_Instance *_instance) {
BreakoutGameArduino_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "erasePad", "void_", "", "");
int16_t ps = _instance->BreakoutGame_padlen_var / _instance->BreakoutGame_SCALE_var;
if(_instance->BreakoutGame_prevPX_var > 0) {
uint8_t r_26 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_27 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_28 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_26, g_27, b_28);
String params_29 = "" + ("r=" + (String(r_26) + ",")) + ("g=" + (String(g_27) + ",")) + ("b=" + (String(b_28) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_29);
uint8_t x_30 = _instance->BreakoutGame_prevPX_var;
uint8_t y_31 = _instance->BreakoutGame_prevPY_var;
uint8_t width_32 = ps;
uint8_t height_33 = 4;
BreakoutGameArduino_send_display_fillRect(_instance, x_30, y_31, width_32, height_33);
String params_34 = "" + ("x=" + (String(x_30) + ",")) + ("y=" + (String(y_31) + ",")) + ("width=" + (String(width_32) + ",")) + ("height=" + (String(height_33) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_34);

}
}
// Definition of function drawPad
void f_BreakoutGameArduino_drawPad(struct BreakoutGameArduino_Instance *_instance) {
BreakoutGameArduino_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "drawPad", "void_", "", "");
int16_t ps = _instance->BreakoutGame_padlen_var / _instance->BreakoutGame_SCALE_var;
f_BreakoutGameArduino_erasePad(_instance);
String old_prevPX_7 = "" + String(_instance->BreakoutGame_prevPX_var);
_instance->BreakoutGame_prevPX_var = (_instance->BreakoutGame_padx_var - (_instance->BreakoutGame_padlen_var / 2)) / _instance->BreakoutGame_SCALE_var;
String new_prevPX_7 = "" + String(_instance->BreakoutGame_prevPX_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "prevPX", "Int16", old_prevPX_7, new_prevPX_7);
String old_prevPY_8 = "" + String(_instance->BreakoutGame_prevPY_var);
_instance->BreakoutGame_prevPY_var = _instance->BreakoutGame_pady_var / _instance->BreakoutGame_SCALE_var;
String new_prevPY_8 = "" + String(_instance->BreakoutGame_prevPY_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "prevPY", "Int16", old_prevPY_8, new_prevPY_8);
uint8_t r_35 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_36 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_37 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_35, g_36, b_37);
String params_38 = "" + ("r=" + (String(r_35) + ",")) + ("g=" + (String(g_36) + ",")) + ("b=" + (String(b_37) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_38);
uint8_t x_39 = _instance->BreakoutGame_prevPX_var;
uint8_t y_40 = _instance->BreakoutGame_prevPY_var;
uint8_t width_41 = ps;
uint8_t height_42 = 4;
BreakoutGameArduino_send_display_fillRect(_instance, x_39, y_40, width_41, height_42);
String params_43 = "" + ("x=" + (String(x_39) + ",")) + ("y=" + (String(y_40) + ",")) + ("width=" + (String(width_41) + ",")) + ("height=" + (String(height_42) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_43);
}
// Definition of function drawCountDown
void f_BreakoutGameArduino_drawCountDown(struct BreakoutGameArduino_Instance *_instance, int16_t c) {
String params = "" + ("c=" + (String(c) + ","));
BreakoutGameArduino_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "drawCountDown", "void_", "", params);
uint8_t r_44 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_45 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_46 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_44, g_45, b_46);
String params_47 = "" + ("r=" + (String(r_44) + ",")) + ("g=" + (String(g_45) + ",")) + ("b=" + (String(b_46) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_47);
if(c > 0) {
uint8_t r_48 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_49 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_50 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_48, g_49, b_50);
String params_51 = "" + ("r=" + (String(r_48) + ",")) + ("g=" + (String(g_49) + ",")) + ("b=" + (String(b_50) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_51);
uint8_t r_52 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_53 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_54 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGameArduino_send_display_setBGColor(_instance, r_52, g_53, b_54);
String params_55 = "" + ("r=" + (String(r_52) + ",")) + ("g=" + (String(g_53) + ",")) + ("b=" + (String(b_54) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setBGColor", params_55);
uint8_t x_56 = 80 - 6;
uint8_t y_57 = 90;
int16_t v_58 = c;
uint8_t digits_59 = 1;
uint8_t scale_60 = 4;
BreakoutGameArduino_send_display_drawInteger(_instance, x_56, y_57, v_58, digits_59, scale_60);
String params_61 = "" + ("x=" + (String(x_56) + ",")) + ("y=" + (String(y_57) + ",")) + ("v=" + (String(v_58) + ",")) + ("digits=" + (String(digits_59) + ",")) + ("scale=" + (String(scale_60) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "drawInteger", params_61);

} else {
uint8_t r_62 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_63 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_64 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_62, g_63, b_64);
String params_65 = "" + ("r=" + (String(r_62) + ",")) + ("g=" + (String(g_63) + ",")) + ("b=" + (String(b_64) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_65);
uint8_t x_66 = 80 - 6;
uint8_t y_67 = 90;
uint8_t width_68 = 12;
uint8_t height_69 = 20;
BreakoutGameArduino_send_display_fillRect(_instance, x_66, y_67, width_68, height_69);
String params_70 = "" + ("x=" + (String(x_66) + ",")) + ("y=" + (String(y_67) + ",")) + ("width=" + (String(width_68) + ",")) + ("height=" + (String(height_69) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_70);

}
}
// Definition of function drawWalls
void f_BreakoutGameArduino_drawWalls(struct BreakoutGameArduino_Instance *_instance) {
BreakoutGameArduino_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "drawWalls", "void_", "", "");
uint8_t r_71 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_72 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_73 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_71, g_72, b_73);
String params_74 = "" + ("r=" + (String(r_71) + ",")) + ("g=" + (String(g_72) + ",")) + ("b=" + (String(b_73) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_74);
uint8_t left = (_instance->BreakoutGame_LEFT_var / _instance->BreakoutGame_SCALE_var);
uint8_t right = (_instance->BreakoutGame_RIGHT_var / _instance->BreakoutGame_SCALE_var);
uint8_t top = (_instance->BreakoutGame_TOP_var / _instance->BreakoutGame_SCALE_var);
uint8_t bottom = (_instance->BreakoutGame_BOTTOM_var / _instance->BreakoutGame_SCALE_var);
uint8_t xcenter = ((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / _instance->BreakoutGame_SCALE_var);
uint8_t ycenter = ((_instance->BreakoutGame_BOTTOM_var - _instance->BreakoutGame_TOP_var) / _instance->BreakoutGame_SCALE_var);
uint8_t x_75 = left - 1;
uint8_t y_76 = top - 1;
uint8_t width_77 = xcenter + 1;
uint8_t height_78 = 1;
BreakoutGameArduino_send_display_fillRect(_instance, x_75, y_76, width_77, height_78);
String params_79 = "" + ("x=" + (String(x_75) + ",")) + ("y=" + (String(y_76) + ",")) + ("width=" + (String(width_77) + ",")) + ("height=" + (String(height_78) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_79);
uint8_t x_80 = left - 1;
uint8_t y_81 = bottom;
uint8_t width_82 = xcenter + 1;
uint8_t height_83 = 1;
BreakoutGameArduino_send_display_fillRect(_instance, x_80, y_81, width_82, height_83);
String params_84 = "" + ("x=" + (String(x_80) + ",")) + ("y=" + (String(y_81) + ",")) + ("width=" + (String(width_82) + ",")) + ("height=" + (String(height_83) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_84);
uint8_t x_85 = left - 1;
uint8_t y_86 = top;
uint8_t width_87 = 1;
uint8_t height_88 = ycenter;
BreakoutGameArduino_send_display_fillRect(_instance, x_85, y_86, width_87, height_88);
String params_89 = "" + ("x=" + (String(x_85) + ",")) + ("y=" + (String(y_86) + ",")) + ("width=" + (String(width_87) + ",")) + ("height=" + (String(height_88) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_89);
uint8_t x_90 = right;
uint8_t y_91 = top;
uint8_t width_92 = 1;
uint8_t height_93 = ycenter;
BreakoutGameArduino_send_display_fillRect(_instance, x_90, y_91, width_92, height_93);
String params_94 = "" + ("x=" + (String(x_90) + ",")) + ("y=" + (String(y_91) + ",")) + ("width=" + (String(width_92) + ",")) + ("height=" + (String(height_93) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_94);
}
// Definition of function bitIsSet
bool f_BreakoutGameArduino_bitIsSet(struct BreakoutGameArduino_Instance *_instance, uint8_t variable, uint8_t bit) {
bool return_0 = (((1 << bit) & variable) != 0);
String return_as_string0 = "" + (String(return_0));
String params = "" + ("variable=" + (String(variable) + ",")) + ("bit=" + (String(bit) + ","));
BreakoutGameArduino_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "bitIsSet", "Boolean", return_as_string0, params);
return return_0;
}
// Definition of function createBricks
void f_BreakoutGameArduino_createBricks(struct BreakoutGameArduino_Instance *_instance) {
BreakoutGameArduino_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "createBricks", "void_", "", "");
uint8_t y = 0;
while(y < _instance->BreakoutGame_BRICK_ROWS_var) {
_instance->BreakoutGame_bricks_var[y] = 0xFF;
uint8_t x = 0;
while(x < 8) {
if(f_BreakoutGameArduino_bitIsSet(_instance, _instance->BreakoutGame_bricks_var[y], x)) {
f_BreakoutGameArduino_drawBrick(_instance, x, y);

}
x = x + 1;

}
y = y + 1;

}
}
// Definition of function bricksLeft
uint8_t f_BreakoutGameArduino_bricksLeft(struct BreakoutGameArduino_Instance *_instance) {
uint8_t result = 0;
uint8_t y = 0;
while(y < _instance->BreakoutGame_BRICK_ROWS_var) {
uint8_t x = 0;
while(x < 8) {
if(f_BreakoutGameArduino_bitIsSet(_instance, _instance->BreakoutGame_bricks_var[y], x)) {
result = result + 1;

}
x = x + 1;

}
y = y + 1;

}
uint8_t return_3 = result;
String return_as_string3 = "" + (String(return_3));
BreakoutGameArduino_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "bricksLeft", "UInt8", return_as_string3, "");
return return_3;
}
// Definition of function drawBrick
void f_BreakoutGameArduino_drawBrick(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y) {
String params = "" + ("x=" + (String(x) + ",")) + ("y=" + (String(y) + ","));
BreakoutGameArduino_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "drawBrick", "void_", "", params);
uint8_t bx = ((_instance->BreakoutGame_LEFT_var + ((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 8) * x) / _instance->BreakoutGame_SCALE_var + 1);
uint8_t by = ((_instance->BreakoutGame_TOP_var + 20 * _instance->BreakoutGame_SCALE_var + _instance->BreakoutGame_BRICK_HEIGHT_var * y * _instance->BreakoutGame_SCALE_var) / _instance->BreakoutGame_SCALE_var + 1);
uint8_t w = (((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 8) / _instance->BreakoutGame_SCALE_var - 2);
uint8_t h = (_instance->BreakoutGame_BRICK_HEIGHT_var - 2);
uint8_t r_95 = 155;
uint8_t g_96 = 103;
uint8_t b_97 = 89;
BreakoutGameArduino_send_display_setColor(_instance, r_95, g_96, b_97);
String params_98 = "" + ("r=" + (String(r_95) + ",")) + ("g=" + (String(g_96) + ",")) + ("b=" + (String(b_97) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_98);
uint8_t x_99 = bx;
uint8_t y_100 = by;
uint8_t width_101 = w;
uint8_t height_102 = h;
BreakoutGameArduino_send_display_fillRect(_instance, x_99, y_100, width_101, height_102);
String params_103 = "" + ("x=" + (String(x_99) + ",")) + ("y=" + (String(y_100) + ",")) + ("width=" + (String(width_101) + ",")) + ("height=" + (String(height_102) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_103);
uint8_t r_104 = 100;
uint8_t g_105 = 56;
uint8_t b_106 = 43;
BreakoutGameArduino_send_display_setColor(_instance, r_104, g_105, b_106);
String params_107 = "" + ("r=" + (String(r_104) + ",")) + ("g=" + (String(g_105) + ",")) + ("b=" + (String(b_106) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_107);
uint8_t x_108 = bx;
uint8_t y_109 = by;
uint8_t width_110 = w;
uint8_t height_111 = h;
BreakoutGameArduino_send_display_drawRect(_instance, x_108, y_109, width_110, height_111);
String params_112 = "" + ("x=" + (String(x_108) + ",")) + ("y=" + (String(y_109) + ",")) + ("width=" + (String(width_110) + ",")) + ("height=" + (String(height_111) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "drawRect", params_112);
}
// Definition of function removeBrick
void f_BreakoutGameArduino_removeBrick(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y) {
String params = "" + ("x=" + (String(x) + ",")) + ("y=" + (String(y) + ","));
BreakoutGameArduino_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "removeBrick", "void_", "", params);
uint8_t bx = ((_instance->BreakoutGame_LEFT_var + ((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 8) * x) / _instance->BreakoutGame_SCALE_var + 1);
uint8_t by = ((_instance->BreakoutGame_TOP_var + 20 * _instance->BreakoutGame_SCALE_var + _instance->BreakoutGame_BRICK_HEIGHT_var * y * _instance->BreakoutGame_SCALE_var) / _instance->BreakoutGame_SCALE_var + 1);
uint8_t r_113 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_114 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_115 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_113, g_114, b_115);
String params_116 = "" + ("r=" + (String(r_113) + ",")) + ("g=" + (String(g_114) + ",")) + ("b=" + (String(b_115) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_116);
uint8_t x_117 = bx;
uint8_t y_118 = by;
uint8_t width_119 = (((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 8) / _instance->BreakoutGame_SCALE_var - 2);
uint8_t height_120 = _instance->BreakoutGame_BRICK_HEIGHT_var - 2;
BreakoutGameArduino_send_display_fillRect(_instance, x_117, y_118, width_119, height_120);
String params_121 = "" + ("x=" + (String(x_117) + ",")) + ("y=" + (String(y_118) + ",")) + ("width=" + (String(width_119) + ",")) + ("height=" + (String(height_120) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_121);
_instance->BreakoutGame_bricks_var[y] = f_BreakoutGameArduino_unsetBit(_instance, _instance->BreakoutGame_bricks_var[y], x);
}
// Definition of function collideBrick
bool f_BreakoutGameArduino_collideBrick(struct BreakoutGameArduino_Instance *_instance, int16_t xpos, int16_t ypos) {
int16_t bry = (ypos - _instance->BreakoutGame_TOP_var - 20 * _instance->BreakoutGame_SCALE_var) / (_instance->BreakoutGame_BRICK_HEIGHT_var * _instance->BreakoutGame_SCALE_var);
bool result = 0;
if(bry >= 0 && bry < _instance->BreakoutGame_BRICK_ROWS_var) {
int16_t brx = (xpos - _instance->BreakoutGame_LEFT_var) / ((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 8);
if(f_BreakoutGameArduino_bitIsSet(_instance, _instance->BreakoutGame_bricks_var[bry], brx)) {
f_BreakoutGameArduino_removeBrick(_instance, brx, bry);
result = 1;

}

}
bool return_3 = result;
String return_as_string3 = "" + (String(return_3));
String params = "" + ("xpos=" + (String(xpos) + ",")) + ("ypos=" + (String(ypos) + ","));
BreakoutGameArduino_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "collideBrick", "Boolean", return_as_string3, params);
return return_3;
}
// Definition of function drawLevel
void f_BreakoutGameArduino_drawLevel(struct BreakoutGameArduino_Instance *_instance) {
BreakoutGameArduino_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "drawLevel", "void_", "", "");
uint8_t r_122 = 158;
uint8_t g_123 = 209;
uint8_t b_124 = 130;
BreakoutGameArduino_send_display_setColor(_instance, r_122, g_123, b_124);
String params_125 = "" + ("r=" + (String(r_122) + ",")) + ("g=" + (String(g_123) + ",")) + ("b=" + (String(b_124) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_125);
uint8_t r_126 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_127 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_128 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setBGColor(_instance, r_126, g_127, b_128);
String params_129 = "" + ("r=" + (String(r_126) + ",")) + ("g=" + (String(g_127) + ",")) + ("b=" + (String(b_128) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setBGColor", params_129);
uint8_t r_130 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_131 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_132 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_130, g_131, b_132);
String params_133 = "" + ("r=" + (String(r_130) + ",")) + ("g=" + (String(g_131) + ",")) + ("b=" + (String(b_132) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_133);
uint8_t x_134 = 6;
uint8_t y_135 = 2;
int16_t v_136 = _instance->BreakoutGame_level_var;
uint8_t digits_137 = 2;
uint8_t scale_138 = 2;
BreakoutGameArduino_send_display_drawInteger(_instance, x_134, y_135, v_136, digits_137, scale_138);
String params_139 = "" + ("x=" + (String(x_134) + ",")) + ("y=" + (String(y_135) + ",")) + ("v=" + (String(v_136) + ",")) + ("digits=" + (String(digits_137) + ",")) + ("scale=" + (String(scale_138) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "drawInteger", params_139);
}
// Definition of function incrementScore
void f_BreakoutGameArduino_incrementScore(struct BreakoutGameArduino_Instance *_instance, int8_t diff) {
String params = "" + ("diff=" + (String(diff) + ","));
BreakoutGameArduino_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "incrementScore", "void_", "", params);
String old_score_30 = "" + String(_instance->BreakoutGame_score_var);
_instance->BreakoutGame_score_var = _instance->BreakoutGame_score_var + diff;
String new_score_30 = "" + String(_instance->BreakoutGame_score_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "score", "Int16", old_score_30, new_score_30);
if(_instance->BreakoutGame_score_var < 0) {
String old_score_31 = "" + String(_instance->BreakoutGame_score_var);
_instance->BreakoutGame_score_var = 0;
String new_score_31 = "" + String(_instance->BreakoutGame_score_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "score", "Int16", old_score_31, new_score_31);

}
f_BreakoutGameArduino_drawScore(_instance);
}
// Definition of function drawScore
void f_BreakoutGameArduino_drawScore(struct BreakoutGameArduino_Instance *_instance) {
BreakoutGameArduino_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "drawScore", "void_", "", "");
uint8_t r_140 = 158;
uint8_t g_141 = 209;
uint8_t b_142 = 130;
BreakoutGameArduino_send_display_setColor(_instance, r_140, g_141, b_142);
String params_143 = "" + ("r=" + (String(r_140) + ",")) + ("g=" + (String(g_141) + ",")) + ("b=" + (String(b_142) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_143);
uint8_t r_144 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_145 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_146 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setBGColor(_instance, r_144, g_145, b_146);
String params_147 = "" + ("r=" + (String(r_144) + ",")) + ("g=" + (String(g_145) + ",")) + ("b=" + (String(b_146) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setBGColor", params_147);
uint8_t x_148 = 58;
uint8_t y_149 = 2;
int16_t v_150 = _instance->BreakoutGame_score_var;
uint8_t digits_151 = 5;
uint8_t scale_152 = 2;
BreakoutGameArduino_send_display_drawInteger(_instance, x_148, y_149, v_150, digits_151, scale_152);
String params_153 = "" + ("x=" + (String(x_148) + ",")) + ("y=" + (String(y_149) + ",")) + ("v=" + (String(v_150) + ",")) + ("digits=" + (String(digits_151) + ",")) + ("scale=" + (String(scale_152) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "drawInteger", params_153);
}
// Definition of function drawLives
void f_BreakoutGameArduino_drawLives(struct BreakoutGameArduino_Instance *_instance) {
BreakoutGameArduino_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "drawLives", "void_", "", "");
uint8_t r_154 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_155 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_156 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_154, g_155, b_156);
String params_157 = "" + ("r=" + (String(r_154) + ",")) + ("g=" + (String(g_155) + ",")) + ("b=" + (String(b_156) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_157);
uint8_t x_158 = 124;
uint8_t y_159 = 4;
uint8_t width_160 = 24 + 6;
uint8_t height_161 = 6;
BreakoutGameArduino_send_display_fillRect(_instance, x_158, y_159, width_160, height_161);
String params_162 = "" + ("x=" + (String(x_158) + ",")) + ("y=" + (String(y_159) + ",")) + ("width=" + (String(width_160) + ",")) + ("height=" + (String(height_161) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_162);
uint8_t r_163 = 183;
uint8_t g_164 = 199;
uint8_t b_165 = 111;
BreakoutGameArduino_send_display_setColor(_instance, r_163, g_164, b_165);
String params_166 = "" + ("r=" + (String(r_163) + ",")) + ("g=" + (String(g_164) + ",")) + ("b=" + (String(b_165) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_166);
uint8_t i = 0;
while(i < _instance->BreakoutGame_lives_var) {
uint8_t x_167 = 124 + (2 - i) * 12;
uint8_t y_168 = 4;
uint8_t width_169 = 6;
uint8_t height_170 = 6;
BreakoutGameArduino_send_display_fillRect(_instance, x_167, y_168, width_169, height_170);
String params_171 = "" + ("x=" + (String(x_167) + ",")) + ("y=" + (String(y_168) + ",")) + ("width=" + (String(width_169) + ",")) + ("height=" + (String(height_170) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_171);
i = i + 1;

}
}
// Definition of function quit
void f_BreakoutGameArduino_quit(struct BreakoutGameArduino_Instance *_instance) {
Serial.print(">done in ");
Serial.print(_instance->BreakoutGame_stopTime_var - _instance->BreakoutGame_startTime_var);
Serial.print("ms!");
Serial.print("\n");
Serial.print(">lives:");
Serial.print(_instance->BreakoutGame_lives_var);
Serial.print(",score:");
Serial.print(_instance->BreakoutGame_score_var);
Serial.print(",level:");
Serial.print(_instance->BreakoutGame_level_var);
Serial.print(",bx:");
Serial.print(_instance->BreakoutGame_bx_var);
Serial.print(",by:");
Serial.print(_instance->BreakoutGame_by_var);
Serial.print(",padx:");
Serial.print(_instance->BreakoutGame_padx_var);
Serial.print("\n");
Serial.print(">usedMem:");
Serial.print(f_BreakoutGameArduino_usedMemory(_instance));
Serial.print("\n");
}
// Definition of function timestamp
uint32_t f_BreakoutGameArduino_timestamp(struct BreakoutGameArduino_Instance *_instance) {
return millis();
}
// Definition of function usedMemory
uint32_t f_BreakoutGameArduino_usedMemory(struct BreakoutGameArduino_Instance *_instance) {
char top;
return _instance->BreakoutGameArduino_RAM_SIZE_var - (&top - reinterpret_cast<char*>(sbrk(0)));
}
// Definition of function unsetBit
uint8_t f_BreakoutGameArduino_unsetBit(struct BreakoutGameArduino_Instance *_instance, uint8_t variable, uint8_t bit) {
return (variable & ~(1 << bit));
}

// Sessions functionss:


// On Entry Actions:
void BreakoutGame_SC_OnEntry(int state, struct BreakoutGameArduino_Instance *_instance) {
switch(state) {
case BREAKOUTGAME_SC_STATE:{
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_INIT_STATE;
BreakoutGame_SC_OnEntry(_instance->BreakoutGame_SC_State, _instance);
break;
}
case BREAKOUTGAME_SC_LOSTBALL_STATE:{
uint8_t id_218 = 0;
uint16_t time_219 = _instance->BreakoutGame_period_var;
BreakoutGameArduino_send_clock_timer_start(_instance, id_218, time_219);
String params_220 = "" + ("id=" + (String(id_218) + ",")) + ("time=" + (String(time_219) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "clock", "timer_start", params_220);
String old_lives_1 = "" + String(_instance->BreakoutGame_lives_var);
_instance->BreakoutGame_lives_var = _instance->BreakoutGame_lives_var - 1;
String new_lives_1 = "" + String(_instance->BreakoutGame_lives_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "lives", "UInt8", old_lives_1, new_lives_1);
f_BreakoutGameArduino_eraseBall(_instance);
f_BreakoutGameArduino_erasePad(_instance);
f_BreakoutGameArduino_drawLives(_instance);
BreakoutGameArduino_send_display_update(_instance);
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "update", "");
f_BreakoutGameArduino_log(_instance, 1);
break;
}
case BREAKOUTGAME_SC_NEXTLEVEL_STATE:{
uint8_t id_221 = 0;
uint16_t time_222 = _instance->BreakoutGame_period_var;
BreakoutGameArduino_send_clock_timer_start(_instance, id_221, time_222);
String params_223 = "" + ("id=" + (String(id_221) + ",")) + ("time=" + (String(time_222) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "clock", "timer_start", params_223);
String old_level_32 = "" + String(_instance->BreakoutGame_level_var);
_instance->BreakoutGame_level_var = _instance->BreakoutGame_level_var + 1;
String new_level_32 = "" + String(_instance->BreakoutGame_level_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "level", "UInt8", old_level_32, new_level_32);
f_BreakoutGameArduino_drawLevel(_instance);
f_BreakoutGameArduino_eraseBall(_instance);
f_BreakoutGameArduino_erasePad(_instance);
if((_instance->BreakoutGame_level_var % 2) == 0 && _instance->BreakoutGame_padlen_var > 5 * _instance->BreakoutGame_SCALE_var) {
String old_padlen_24 = "" + String(_instance->BreakoutGame_padlen_var);
_instance->BreakoutGame_padlen_var = _instance->BreakoutGame_padlen_var - (4 * _instance->BreakoutGame_SCALE_var);
String new_padlen_24 = "" + String(_instance->BreakoutGame_padlen_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "padlen", "Int16", old_padlen_24, new_padlen_24);

}
if((_instance->BreakoutGame_level_var % 2) == 1) {
String old_dy_6 = "" + String(_instance->BreakoutGame_dy_var);
_instance->BreakoutGame_dy_var = (_instance->BreakoutGame_dy_var * 3) / 2;
String new_dy_6 = "" + String(_instance->BreakoutGame_dy_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "dy", "Int16", old_dy_6, new_dy_6);

}
f_BreakoutGameArduino_drawLives(_instance);
f_BreakoutGameArduino_createBricks(_instance);
BreakoutGameArduino_send_display_update(_instance);
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "update", "");
break;
}
case BREAKOUTGAME_SC_PLAY_STATE:{
uint8_t id_199 = 0;
uint16_t time_200 = _instance->BreakoutGame_period_var;
BreakoutGameArduino_send_clock_timer_start(_instance, id_199, time_200);
String params_201 = "" + ("id=" + (String(id_199) + ",")) + ("time=" + (String(time_200) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "clock", "timer_start", params_201);
break;
}
case BREAKOUTGAME_SC_INIT_STATE:{
_instance->BreakoutGame_startTime_var = f_BreakoutGameArduino_timestamp(_instance);
uint8_t xsize_172 = _instance->BreakoutGame_XDISPSIZE_var;
uint8_t ysize_173 = _instance->BreakoutGame_YDISPSIZE_var;
BreakoutGameArduino_send_display_create(_instance, xsize_172, ysize_173);
String params_174 = "" + ("xsize=" + (String(xsize_172) + ",")) + ("ysize=" + (String(ysize_173) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "create", params_174);
break;
}
case BREAKOUTGAME_SC_LAUNCH_STATE:{
uint8_t id_193 = 0;
uint16_t time_194 = _instance->BreakoutGame_period_var;
BreakoutGameArduino_send_clock_timer_start(_instance, id_193, time_194);
String params_195 = "" + ("id=" + (String(id_193) + ",")) + ("time=" + (String(time_194) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "clock", "timer_start", params_195);
String old_countdown_28 = "" + String(_instance->BreakoutGame_SC_LAUNCH_countdown_var);
_instance->BreakoutGame_SC_LAUNCH_countdown_var = 3;
String new_countdown_28 = "" + String(_instance->BreakoutGame_SC_LAUNCH_countdown_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "countdown", "UInt8", old_countdown_28, new_countdown_28);
f_BreakoutGameArduino_drawScore(_instance);
f_BreakoutGameArduino_drawLives(_instance);
BreakoutGameArduino_send_display_update(_instance);
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "update", "");
break;
}
case BREAKOUTGAME_SC_GAMEOVER_STATE:{
f_BreakoutGameArduino_eraseBall(_instance);
f_BreakoutGameArduino_erasePad(_instance);
uint8_t r_224 = 255;
uint8_t g_225 = 255;
uint8_t b_226 = 255;
BreakoutGameArduino_send_display_setColor(_instance, r_224, g_225, b_226);
String params_227 = "" + ("r=" + (String(r_224) + ",")) + ("g=" + (String(g_225) + ",")) + ("b=" + (String(b_226) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_227);
uint8_t x_228 = 8;
uint8_t y_229 = 30;
uint8_t width_230 = 142;
uint8_t height_231 = 76;
BreakoutGameArduino_send_display_fillRect(_instance, x_228, y_229, width_230, height_231);
String params_232 = "" + ("x=" + (String(x_228) + ",")) + ("y=" + (String(y_229) + ",")) + ("width=" + (String(width_230) + ",")) + ("height=" + (String(height_231) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_232);
uint8_t r_233 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_234 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_235 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_233, g_234, b_235);
String params_236 = "" + ("r=" + (String(r_233) + ",")) + ("g=" + (String(g_234) + ",")) + ("b=" + (String(b_235) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_236);
uint8_t x_237 = 9;
uint8_t y_238 = 31;
uint8_t width_239 = 140;
uint8_t height_240 = 50;
BreakoutGameArduino_send_display_fillRect(_instance, x_237, y_238, width_239, height_240);
String params_241 = "" + ("x=" + (String(x_237) + ",")) + ("y=" + (String(y_238) + ",")) + ("width=" + (String(width_239) + ",")) + ("height=" + (String(height_240) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_241);
uint8_t r_242 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_243 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_244 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setBGColor(_instance, r_242, g_243, b_244);
String params_245 = "" + ("r=" + (String(r_242) + ",")) + ("g=" + (String(g_243) + ",")) + ("b=" + (String(b_244) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setBGColor", params_245);
uint8_t r_246 = 158;
uint8_t g_247 = 209;
uint8_t b_248 = 130;
BreakoutGameArduino_send_display_setColor(_instance, r_246, g_247, b_248);
String params_249 = "" + ("r=" + (String(r_246) + ",")) + ("g=" + (String(g_247) + ",")) + ("b=" + (String(b_248) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_249);
uint8_t x_250 = 23;
uint8_t y_251 = 40;
int16_t v_252 = _instance->BreakoutGame_score_var;
uint8_t digits_253 = 5;
uint8_t scale_254 = 6;
BreakoutGameArduino_send_display_drawInteger(_instance, x_250, y_251, v_252, digits_253, scale_254);
String params_255 = "" + ("x=" + (String(x_250) + ",")) + ("y=" + (String(y_251) + ",")) + ("v=" + (String(v_252) + ",")) + ("digits=" + (String(digits_253) + ",")) + ("scale=" + (String(scale_254) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "drawInteger", params_255);
uint8_t x_256 = 26;
uint8_t y_257 = 87;
BreakoutGameArduino_send_display_drawThingML(_instance, x_256, y_257);
String params_258 = "" + ("x=" + (String(x_256) + ",")) + ("y=" + (String(y_257) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "drawThingML", params_258);
BreakoutGameArduino_send_display_update(_instance);
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "update", "");
f_BreakoutGameArduino_log(_instance, 1);
_instance->BreakoutGame_stopTime_var = f_BreakoutGameArduino_timestamp(_instance);
f_BreakoutGameArduino_quit(_instance);
_instance->active = false;
break;
}
default: break;
}
}

// On Exit Actions:
void BreakoutGame_SC_OnExit(int state, struct BreakoutGameArduino_Instance *_instance) {
switch(state) {
case BREAKOUTGAME_SC_STATE:{
BreakoutGame_SC_OnExit(_instance->BreakoutGame_SC_State, _instance);
break;}
case BREAKOUTGAME_SC_LOSTBALL_STATE:{
break;}
case BREAKOUTGAME_SC_NEXTLEVEL_STATE:{
break;}
case BREAKOUTGAME_SC_PLAY_STATE:{
break;}
case BREAKOUTGAME_SC_INIT_STATE:{
break;}
case BREAKOUTGAME_SC_LAUNCH_STATE:{
break;}
case BREAKOUTGAME_SC_GAMEOVER_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void BreakoutGameArduino_handle_controller_position(struct BreakoutGameArduino_Instance *_instance, int16_t x, int16_t y) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
String params = "" + ("x=" + (String(x) + ",")) + ("y=" + (String(y) + ","));
BreakoutGameArduino_send_log_message_handled(_instance, _instance->WithLog_DEBUG_ID_var, "SC", "_", "controller", "position", params);
int32_t center = (_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var - _instance->BreakoutGame_padlen_var);
center = x * center;
center = center / 200;
String old_padx_0 = "" + String(_instance->BreakoutGame_padx_var);
_instance->BreakoutGame_padx_var = (_instance->BreakoutGame_LEFT_var + center + (_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 2);
String new_padx_0 = "" + String(_instance->BreakoutGame_padx_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "padx", "Int16", old_padx_0, new_padx_0);
BreakoutGame_SC_State_event_consumed = 1;
}
}
void BreakoutGameArduino_handle_pro_game_lostBall(struct BreakoutGameArduino_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_PLAY_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && 1) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_PLAY_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_LOSTBALL_STATE;
BreakoutGameArduino_send_log_message_handled(_instance, _instance->WithLog_DEBUG_ID_var, "SC.PLAY", "SC.LOSTBALL", "pro_game", "lostBall", "_");
uint8_t id_214 = 0;
BreakoutGameArduino_send_clock_timer_cancel(_instance, id_214);
String params_215 = "" + ("id=" + (String(id_214) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "clock", "timer_cancel", params_215);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_LOSTBALL_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
BreakoutGameArduino_send_log_message_lost(_instance, _instance->WithLog_DEBUG_ID_var, "pro_game", "lostBall", "");
BreakoutGame_SC_State_event_consumed = 1;
}
}
void BreakoutGameArduino_handle_pro_game_nextLevel(struct BreakoutGameArduino_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_PLAY_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && 1) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_PLAY_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_NEXTLEVEL_STATE;
BreakoutGameArduino_send_log_message_handled(_instance, _instance->WithLog_DEBUG_ID_var, "SC.PLAY", "SC.NEXTLEVEL", "pro_game", "nextLevel", "_");
uint8_t id_216 = 0;
BreakoutGameArduino_send_clock_timer_cancel(_instance, id_216);
String params_217 = "" + ("id=" + (String(id_216) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "clock", "timer_cancel", params_217);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_NEXTLEVEL_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
BreakoutGameArduino_send_log_message_lost(_instance, _instance->WithLog_DEBUG_ID_var, "pro_game", "nextLevel", "");
BreakoutGame_SC_State_event_consumed = 1;
}
}
void BreakoutGameArduino_handle_game_lostBall(struct BreakoutGameArduino_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_PLAY_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && 1) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_PLAY_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_LOSTBALL_STATE;
BreakoutGameArduino_send_log_message_handled(_instance, _instance->WithLog_DEBUG_ID_var, "SC.PLAY", "SC.LOSTBALL", "game", "lostBall", "_");
uint8_t id_210 = 0;
BreakoutGameArduino_send_clock_timer_cancel(_instance, id_210);
String params_211 = "" + ("id=" + (String(id_210) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "clock", "timer_cancel", params_211);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_LOSTBALL_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
BreakoutGameArduino_send_log_message_lost(_instance, _instance->WithLog_DEBUG_ID_var, "game", "lostBall", "");
BreakoutGame_SC_State_event_consumed = 1;
}
}
void BreakoutGameArduino_handle_game_nextLevel(struct BreakoutGameArduino_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_PLAY_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && 1) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_PLAY_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_NEXTLEVEL_STATE;
BreakoutGameArduino_send_log_message_handled(_instance, _instance->WithLog_DEBUG_ID_var, "SC.PLAY", "SC.NEXTLEVEL", "game", "nextLevel", "_");
uint8_t id_212 = 0;
BreakoutGameArduino_send_clock_timer_cancel(_instance, id_212);
String params_213 = "" + ("id=" + (String(id_212) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "clock", "timer_cancel", params_213);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_NEXTLEVEL_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
BreakoutGameArduino_send_log_message_lost(_instance, _instance->WithLog_DEBUG_ID_var, "game", "nextLevel", "");
BreakoutGame_SC_State_event_consumed = 1;
}
}
void BreakoutGameArduino_handle_clock_timer_timeout(struct BreakoutGameArduino_Instance *_instance, uint8_t id) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_LAUNCH_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && id == 0 && _instance->BreakoutGame_SC_LAUNCH_countdown_var == 0) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_LAUNCH_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_PLAY_STATE;
String params = "" + ("id=" + (String(id) + ","));
BreakoutGameArduino_send_log_message_handled(_instance, _instance->WithLog_DEBUG_ID_var, "SC.LAUNCH", "SC.PLAY", "clock", "timer_timeout", params);
f_BreakoutGameArduino_drawCountDown(_instance, 0);
f_BreakoutGameArduino_resetBall(_instance);
BreakoutGameArduino_send_display_update(_instance);
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "update", "");
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_PLAY_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
else if (BreakoutGame_SC_State_event_consumed == 0 && id == 0 && _instance->BreakoutGame_SC_LAUNCH_countdown_var > 0) {
String params = "" + ("id=" + (String(id) + ","));
BreakoutGameArduino_send_log_message_handled(_instance, _instance->WithLog_DEBUG_ID_var, "SC.LAUNCH", "_", "clock", "timer_timeout", params);
uint8_t id_196 = 0;
uint16_t time_197 = _instance->BreakoutGame_period_var;
BreakoutGameArduino_send_clock_timer_start(_instance, id_196, time_197);
String params_198 = "" + ("id=" + (String(id_196) + ",")) + ("time=" + (String(time_197) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "clock", "timer_start", params_198);
f_BreakoutGameArduino_drawPad(_instance);
if((_instance->BreakoutGame_SC_LAUNCH_countdown_var % 30) == 0) {
f_BreakoutGameArduino_drawCountDown(_instance, _instance->BreakoutGame_SC_LAUNCH_countdown_var / 30);

}
String old_countdown_29 = "" + String(_instance->BreakoutGame_SC_LAUNCH_countdown_var);
_instance->BreakoutGame_SC_LAUNCH_countdown_var = _instance->BreakoutGame_SC_LAUNCH_countdown_var - 1;
String new_countdown_29 = "" + String(_instance->BreakoutGame_SC_LAUNCH_countdown_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "countdown", "UInt8", old_countdown_29, new_countdown_29);
BreakoutGameArduino_send_display_update(_instance);
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "update", "");
BreakoutGame_SC_State_event_consumed = 1;
}
}
else if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_PLAY_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && id == 0) {
String params = "" + ("id=" + (String(id) + ","));
BreakoutGameArduino_send_log_message_handled(_instance, _instance->WithLog_DEBUG_ID_var, "SC.PLAY", "_", "clock", "timer_timeout", params);
String old_bx_17 = "" + String(_instance->BreakoutGame_bx_var);
_instance->BreakoutGame_bx_var = _instance->BreakoutGame_bx_var + _instance->BreakoutGame_dx_var;
String new_bx_17 = "" + String(_instance->BreakoutGame_bx_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "bx", "Int16", old_bx_17, new_bx_17);
String old_by_13 = "" + String(_instance->BreakoutGame_by_var);
_instance->BreakoutGame_by_var = _instance->BreakoutGame_by_var + _instance->BreakoutGame_dy_var;
String new_by_13 = "" + String(_instance->BreakoutGame_by_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "by", "Int16", old_by_13, new_by_13);
int16_t wl = _instance->BreakoutGame_LEFT_var + _instance->BreakoutGame_br_var;
int16_t wr = _instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_br_var;
int16_t wt = _instance->BreakoutGame_TOP_var + _instance->BreakoutGame_br_var;
int16_t wb = _instance->BreakoutGame_BOTTOM_var - _instance->BreakoutGame_br_var;
if(_instance->BreakoutGame_bx_var < wl) {
String old_dx_21 = "" + String(_instance->BreakoutGame_dx_var);
_instance->BreakoutGame_dx_var =  -_instance->BreakoutGame_dx_var;
String new_dx_21 = "" + String(_instance->BreakoutGame_dx_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "dx", "Int16", old_dx_21, new_dx_21);
String old_bx_18 = "" + String(_instance->BreakoutGame_bx_var);
_instance->BreakoutGame_bx_var = 2 * wl - _instance->BreakoutGame_bx_var;
String new_bx_18 = "" + String(_instance->BreakoutGame_bx_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "bx", "Int16", old_bx_18, new_bx_18);
f_BreakoutGameArduino_incrementScore(_instance,  -1);

} else {
if(_instance->BreakoutGame_bx_var > wr) {
String old_dx_22 = "" + String(_instance->BreakoutGame_dx_var);
_instance->BreakoutGame_dx_var =  -_instance->BreakoutGame_dx_var;
String new_dx_22 = "" + String(_instance->BreakoutGame_dx_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "dx", "Int16", old_dx_22, new_dx_22);
String old_bx_19 = "" + String(_instance->BreakoutGame_bx_var);
_instance->BreakoutGame_bx_var = 2 * wr - _instance->BreakoutGame_bx_var;
String new_bx_19 = "" + String(_instance->BreakoutGame_bx_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "bx", "Int16", old_bx_19, new_bx_19);
f_BreakoutGameArduino_incrementScore(_instance,  -1);

}

}
if(_instance->BreakoutGame_by_var < wt) {
String old_dy_3 = "" + String(_instance->BreakoutGame_dy_var);
_instance->BreakoutGame_dy_var =  -_instance->BreakoutGame_dy_var;
String new_dy_3 = "" + String(_instance->BreakoutGame_dy_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "dy", "Int16", old_dy_3, new_dy_3);
String old_by_14 = "" + String(_instance->BreakoutGame_by_var);
_instance->BreakoutGame_by_var = 2 * wt - _instance->BreakoutGame_by_var;
String new_by_14 = "" + String(_instance->BreakoutGame_by_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "by", "Int16", old_by_14, new_by_14);
f_BreakoutGameArduino_incrementScore(_instance,  -1);

} else {
if(_instance->BreakoutGame_by_var > wb) {
BreakoutGameArduino_send_game_lostBall(_instance);
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "game", "lostBall", "");
BreakoutGameArduino_send_req_game_lostBall(_instance);
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "req_game", "lostBall", "");

}

}
if(_instance->BreakoutGame_dy_var > 0) {
if(_instance->BreakoutGame_by_var > _instance->BreakoutGame_pady_var - _instance->BreakoutGame_br_var && _instance->BreakoutGame_by_var < _instance->BreakoutGame_pady_var + _instance->BreakoutGame_br_var) {
if(_instance->BreakoutGame_bx_var > _instance->BreakoutGame_padx_var - _instance->BreakoutGame_padlen_var / 2 && _instance->BreakoutGame_bx_var < _instance->BreakoutGame_padx_var + _instance->BreakoutGame_padlen_var / 2) {
String old_dy_4 = "" + String(_instance->BreakoutGame_dy_var);
_instance->BreakoutGame_dy_var =  -_instance->BreakoutGame_dy_var;
String new_dy_4 = "" + String(_instance->BreakoutGame_dy_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "dy", "Int16", old_dy_4, new_dy_4);
String old_by_15 = "" + String(_instance->BreakoutGame_by_var);
_instance->BreakoutGame_by_var = 2 * (_instance->BreakoutGame_pady_var - _instance->BreakoutGame_br_var) - _instance->BreakoutGame_by_var;
String new_by_15 = "" + String(_instance->BreakoutGame_by_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "by", "Int16", old_by_15, new_by_15);
String old_dx_23 = "" + String(_instance->BreakoutGame_dx_var);
_instance->BreakoutGame_dx_var = _instance->BreakoutGame_dx_var / 4 + (_instance->BreakoutGame_bx_var - _instance->BreakoutGame_padx_var) / 4;
String new_dx_23 = "" + String(_instance->BreakoutGame_dx_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "dx", "Int16", old_dx_23, new_dx_23);

}

}

}
bool collision = f_BreakoutGameArduino_collideBrick(_instance, _instance->BreakoutGame_bx_var - _instance->BreakoutGame_br_var, _instance->BreakoutGame_by_var - _instance->BreakoutGame_br_var) || f_BreakoutGameArduino_collideBrick(_instance, _instance->BreakoutGame_bx_var + _instance->BreakoutGame_br_var, _instance->BreakoutGame_by_var - _instance->BreakoutGame_br_var) || f_BreakoutGameArduino_collideBrick(_instance, _instance->BreakoutGame_bx_var + _instance->BreakoutGame_br_var, _instance->BreakoutGame_by_var + _instance->BreakoutGame_br_var) || f_BreakoutGameArduino_collideBrick(_instance, _instance->BreakoutGame_bx_var - _instance->BreakoutGame_br_var, _instance->BreakoutGame_by_var + _instance->BreakoutGame_br_var);
if(collision) {
String old_dy_5 = "" + String(_instance->BreakoutGame_dy_var);
_instance->BreakoutGame_dy_var =  -_instance->BreakoutGame_dy_var;
String new_dy_5 = "" + String(_instance->BreakoutGame_dy_var);
BreakoutGameArduino_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "dy", "Int16", old_dy_5, new_dy_5);
f_BreakoutGameArduino_incrementScore(_instance, 10);
if(f_BreakoutGameArduino_bricksLeft(_instance) == 0) {
BreakoutGameArduino_send_game_nextLevel(_instance);
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "game", "nextLevel", "");
BreakoutGameArduino_send_req_game_nextLevel(_instance);
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "req_game", "nextLevel", "");

}

}
f_BreakoutGameArduino_drawBall(_instance);
f_BreakoutGameArduino_drawPad(_instance);
int16_t ballx_202 = _instance->BreakoutGame_bx_var;
int16_t bally_203 = _instance->BreakoutGame_by_var;
int16_t padx_204 = _instance->BreakoutGame_padx_var;
int16_t pady_205 = _instance->BreakoutGame_pady_var;
BreakoutGameArduino_send_ia_updateIA(_instance, ballx_202, bally_203, padx_204, pady_205);
String params_206 = "" + ("ballx=" + (String(ballx_202) + ",")) + ("bally=" + (String(bally_203) + ",")) + ("padx=" + (String(padx_204) + ",")) + ("pady=" + (String(pady_205) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "ia", "updateIA", params_206);
BreakoutGameArduino_send_display_update(_instance);
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "update", "");
f_BreakoutGameArduino_log(_instance, 0);
uint8_t id_207 = 0;
uint16_t time_208 = _instance->BreakoutGame_period_var;
BreakoutGameArduino_send_clock_timer_start(_instance, id_207, time_208);
String params_209 = "" + ("id=" + (String(id_207) + ",")) + ("time=" + (String(time_208) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "clock", "timer_start", params_209);
BreakoutGame_SC_State_event_consumed = 1;
}
}
else if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_LOSTBALL_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && id == 0 && _instance->BreakoutGame_lives_var > 0) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_LOSTBALL_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_LAUNCH_STATE;
String params = "" + ("id=" + (String(id) + ","));
BreakoutGameArduino_send_log_message_handled(_instance, _instance->WithLog_DEBUG_ID_var, "SC.LOSTBALL", "SC.LAUNCH", "clock", "timer_timeout", params);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_LAUNCH_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
else if (BreakoutGame_SC_State_event_consumed == 0 && id == 0 && _instance->BreakoutGame_lives_var == 0) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_LOSTBALL_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_GAMEOVER_STATE;
String params = "" + ("id=" + (String(id) + ","));
BreakoutGameArduino_send_log_message_handled(_instance, _instance->WithLog_DEBUG_ID_var, "SC.LOSTBALL", "SC.GAMEOVER", "clock", "timer_timeout", params);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_GAMEOVER_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
else if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_NEXTLEVEL_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && id == 0) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_NEXTLEVEL_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_LAUNCH_STATE;
String params = "" + ("id=" + (String(id) + ","));
BreakoutGameArduino_send_log_message_handled(_instance, _instance->WithLog_DEBUG_ID_var, "SC.NEXTLEVEL", "SC.LAUNCH", "clock", "timer_timeout", params);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_LAUNCH_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
String params = "" + ("id=" + (String(id) + ","));
BreakoutGameArduino_send_log_message_lost(_instance, _instance->WithLog_DEBUG_ID_var, "clock", "timer_timeout", params);
BreakoutGame_SC_State_event_consumed = 1;
}
}
void BreakoutGameArduino_handle_display_displayReady(struct BreakoutGameArduino_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_INIT_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && 1) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_INIT_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_LAUNCH_STATE;
BreakoutGameArduino_send_log_message_handled(_instance, _instance->WithLog_DEBUG_ID_var, "SC.INIT", "SC.LAUNCH", "display", "displayReady", "_");
BreakoutGameArduino_send_display_clear(_instance);
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "clear", "");
f_BreakoutGameArduino_initColors(_instance);
uint8_t r_175 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_176 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_177 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_175, g_176, b_177);
String params_178 = "" + ("r=" + (String(r_175) + ",")) + ("g=" + (String(g_176) + ",")) + ("b=" + (String(b_177) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_178);
uint8_t x_179 = 0;
uint8_t y_180 = 0;
uint8_t width_181 = _instance->BreakoutGame_XDISPSIZE_var;
uint8_t height_182 = _instance->BreakoutGame_YDISPSIZE_var;
BreakoutGameArduino_send_display_fillRect(_instance, x_179, y_180, width_181, height_182);
String params_183 = "" + ("x=" + (String(x_179) + ",")) + ("y=" + (String(y_180) + ",")) + ("width=" + (String(width_181) + ",")) + ("height=" + (String(height_182) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_183);
uint8_t r_184 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_185 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_186 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_184, g_185, b_186);
String params_187 = "" + ("r=" + (String(r_184) + ",")) + ("g=" + (String(g_185) + ",")) + ("b=" + (String(b_186) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_187);
uint8_t x_188 = 0;
uint8_t y_189 = 0;
uint8_t width_190 = _instance->BreakoutGame_XDISPSIZE_var;
uint8_t height_191 = 14;
BreakoutGameArduino_send_display_fillRect(_instance, x_188, y_189, width_190, height_191);
String params_192 = "" + ("x=" + (String(x_188) + ",")) + ("y=" + (String(y_189) + ",")) + ("width=" + (String(width_190) + ",")) + ("height=" + (String(height_191) + ","));
BreakoutGameArduino_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_192);
f_BreakoutGameArduino_drawWalls(_instance);
f_BreakoutGameArduino_createBricks(_instance);
f_BreakoutGameArduino_drawLevel(_instance);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_LAUNCH_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
BreakoutGameArduino_send_log_message_lost(_instance, _instance->WithLog_DEBUG_ID_var, "display", "displayReady", "");
BreakoutGame_SC_State_event_consumed = 1;
}
}

// Observers for outgoing messages:
void (*external_BreakoutGameArduino_send_log_function_called_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String, String)= 0x0;
void (*BreakoutGameArduino_send_log_function_called_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String, String)= 0x0;
void register_external_BreakoutGameArduino_send_log_function_called_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String, String)){
external_BreakoutGameArduino_send_log_function_called_listener = _listener;
}
void register_BreakoutGameArduino_send_log_function_called_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String, String)){
BreakoutGameArduino_send_log_function_called_listener = _listener;
}
void BreakoutGameArduino_send_log_function_called(struct BreakoutGameArduino_Instance *_instance, String inst, String fn_name, String ty, String returns, String params){
if (BreakoutGameArduino_send_log_function_called_listener != 0x0) BreakoutGameArduino_send_log_function_called_listener(_instance, inst, fn_name, ty, returns, params);
if (external_BreakoutGameArduino_send_log_function_called_listener != 0x0) external_BreakoutGameArduino_send_log_function_called_listener(_instance, inst, fn_name, ty, returns, params);
;
}
void (*external_BreakoutGameArduino_send_log_property_changed_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String, String)= 0x0;
void (*BreakoutGameArduino_send_log_property_changed_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String, String)= 0x0;
void register_external_BreakoutGameArduino_send_log_property_changed_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String, String)){
external_BreakoutGameArduino_send_log_property_changed_listener = _listener;
}
void register_BreakoutGameArduino_send_log_property_changed_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String, String)){
BreakoutGameArduino_send_log_property_changed_listener = _listener;
}
void BreakoutGameArduino_send_log_property_changed(struct BreakoutGameArduino_Instance *_instance, String inst, String prop_name, String ty, String old_value, String new_value){
if (BreakoutGameArduino_send_log_property_changed_listener != 0x0) BreakoutGameArduino_send_log_property_changed_listener(_instance, inst, prop_name, ty, old_value, new_value);
if (external_BreakoutGameArduino_send_log_property_changed_listener != 0x0) external_BreakoutGameArduino_send_log_property_changed_listener(_instance, inst, prop_name, ty, old_value, new_value);
;
}
void (*external_BreakoutGameArduino_send_log_message_lost_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String)= 0x0;
void (*BreakoutGameArduino_send_log_message_lost_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String)= 0x0;
void register_external_BreakoutGameArduino_send_log_message_lost_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String)){
external_BreakoutGameArduino_send_log_message_lost_listener = _listener;
}
void register_BreakoutGameArduino_send_log_message_lost_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String)){
BreakoutGameArduino_send_log_message_lost_listener = _listener;
}
void BreakoutGameArduino_send_log_message_lost(struct BreakoutGameArduino_Instance *_instance, String inst, String port_name, String msg_name, String params){
if (BreakoutGameArduino_send_log_message_lost_listener != 0x0) BreakoutGameArduino_send_log_message_lost_listener(_instance, inst, port_name, msg_name, params);
if (external_BreakoutGameArduino_send_log_message_lost_listener != 0x0) external_BreakoutGameArduino_send_log_message_lost_listener(_instance, inst, port_name, msg_name, params);
;
}
void (*external_BreakoutGameArduino_send_log_message_handled_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String, String, String)= 0x0;
void (*BreakoutGameArduino_send_log_message_handled_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String, String, String)= 0x0;
void register_external_BreakoutGameArduino_send_log_message_handled_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String, String, String)){
external_BreakoutGameArduino_send_log_message_handled_listener = _listener;
}
void register_BreakoutGameArduino_send_log_message_handled_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String, String, String)){
BreakoutGameArduino_send_log_message_handled_listener = _listener;
}
void BreakoutGameArduino_send_log_message_handled(struct BreakoutGameArduino_Instance *_instance, String inst, String source, String target, String port_name, String msg_name, String params){
if (BreakoutGameArduino_send_log_message_handled_listener != 0x0) BreakoutGameArduino_send_log_message_handled_listener(_instance, inst, source, target, port_name, msg_name, params);
if (external_BreakoutGameArduino_send_log_message_handled_listener != 0x0) external_BreakoutGameArduino_send_log_message_handled_listener(_instance, inst, source, target, port_name, msg_name, params);
;
}
void (*external_BreakoutGameArduino_send_log_message_sent_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String)= 0x0;
void (*BreakoutGameArduino_send_log_message_sent_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String)= 0x0;
void register_external_BreakoutGameArduino_send_log_message_sent_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String)){
external_BreakoutGameArduino_send_log_message_sent_listener = _listener;
}
void register_BreakoutGameArduino_send_log_message_sent_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, String, String, String, String)){
BreakoutGameArduino_send_log_message_sent_listener = _listener;
}
void BreakoutGameArduino_send_log_message_sent(struct BreakoutGameArduino_Instance *_instance, String inst, String port_name, String msg_name, String params){
if (BreakoutGameArduino_send_log_message_sent_listener != 0x0) BreakoutGameArduino_send_log_message_sent_listener(_instance, inst, port_name, msg_name, params);
if (external_BreakoutGameArduino_send_log_message_sent_listener != 0x0) external_BreakoutGameArduino_send_log_message_sent_listener(_instance, inst, port_name, msg_name, params);
;
}
void (*external_BreakoutGameArduino_send_clock_timer_start_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint16_t)= 0x0;
void (*BreakoutGameArduino_send_clock_timer_start_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint16_t)= 0x0;
void register_external_BreakoutGameArduino_send_clock_timer_start_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint16_t)){
external_BreakoutGameArduino_send_clock_timer_start_listener = _listener;
}
void register_BreakoutGameArduino_send_clock_timer_start_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint16_t)){
BreakoutGameArduino_send_clock_timer_start_listener = _listener;
}
void BreakoutGameArduino_send_clock_timer_start(struct BreakoutGameArduino_Instance *_instance, uint8_t id, uint16_t time){
if (BreakoutGameArduino_send_clock_timer_start_listener != 0x0) BreakoutGameArduino_send_clock_timer_start_listener(_instance, id, time);
if (external_BreakoutGameArduino_send_clock_timer_start_listener != 0x0) external_BreakoutGameArduino_send_clock_timer_start_listener(_instance, id, time);
;
}
void (*external_BreakoutGameArduino_send_clock_timer_cancel_listener)(struct BreakoutGameArduino_Instance *, uint8_t)= 0x0;
void (*BreakoutGameArduino_send_clock_timer_cancel_listener)(struct BreakoutGameArduino_Instance *, uint8_t)= 0x0;
void register_external_BreakoutGameArduino_send_clock_timer_cancel_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t)){
external_BreakoutGameArduino_send_clock_timer_cancel_listener = _listener;
}
void register_BreakoutGameArduino_send_clock_timer_cancel_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t)){
BreakoutGameArduino_send_clock_timer_cancel_listener = _listener;
}
void BreakoutGameArduino_send_clock_timer_cancel(struct BreakoutGameArduino_Instance *_instance, uint8_t id){
if (BreakoutGameArduino_send_clock_timer_cancel_listener != 0x0) BreakoutGameArduino_send_clock_timer_cancel_listener(_instance, id);
if (external_BreakoutGameArduino_send_clock_timer_cancel_listener != 0x0) external_BreakoutGameArduino_send_clock_timer_cancel_listener(_instance, id);
;
}
void (*external_BreakoutGameArduino_send_display_create_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t)= 0x0;
void (*BreakoutGameArduino_send_display_create_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t)= 0x0;
void register_external_BreakoutGameArduino_send_display_create_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t)){
external_BreakoutGameArduino_send_display_create_listener = _listener;
}
void register_BreakoutGameArduino_send_display_create_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t)){
BreakoutGameArduino_send_display_create_listener = _listener;
}
void BreakoutGameArduino_send_display_create(struct BreakoutGameArduino_Instance *_instance, uint8_t xsize, uint8_t ysize){
if (BreakoutGameArduino_send_display_create_listener != 0x0) BreakoutGameArduino_send_display_create_listener(_instance, xsize, ysize);
if (external_BreakoutGameArduino_send_display_create_listener != 0x0) external_BreakoutGameArduino_send_display_create_listener(_instance, xsize, ysize);
;
}
void (*external_BreakoutGameArduino_send_display_fillRect_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)= 0x0;
void (*BreakoutGameArduino_send_display_fillRect_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_BreakoutGameArduino_send_display_fillRect_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)){
external_BreakoutGameArduino_send_display_fillRect_listener = _listener;
}
void register_BreakoutGameArduino_send_display_fillRect_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)){
BreakoutGameArduino_send_display_fillRect_listener = _listener;
}
void BreakoutGameArduino_send_display_fillRect(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height){
if (BreakoutGameArduino_send_display_fillRect_listener != 0x0) BreakoutGameArduino_send_display_fillRect_listener(_instance, x, y, width, height);
if (external_BreakoutGameArduino_send_display_fillRect_listener != 0x0) external_BreakoutGameArduino_send_display_fillRect_listener(_instance, x, y, width, height);
;
}
void (*external_BreakoutGameArduino_send_display_drawRect_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)= 0x0;
void (*BreakoutGameArduino_send_display_drawRect_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_BreakoutGameArduino_send_display_drawRect_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)){
external_BreakoutGameArduino_send_display_drawRect_listener = _listener;
}
void register_BreakoutGameArduino_send_display_drawRect_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)){
BreakoutGameArduino_send_display_drawRect_listener = _listener;
}
void BreakoutGameArduino_send_display_drawRect(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height){
if (BreakoutGameArduino_send_display_drawRect_listener != 0x0) BreakoutGameArduino_send_display_drawRect_listener(_instance, x, y, width, height);
if (external_BreakoutGameArduino_send_display_drawRect_listener != 0x0) external_BreakoutGameArduino_send_display_drawRect_listener(_instance, x, y, width, height);
;
}
void (*external_BreakoutGameArduino_send_display_clear_listener)(struct BreakoutGameArduino_Instance *)= 0x0;
void (*BreakoutGameArduino_send_display_clear_listener)(struct BreakoutGameArduino_Instance *)= 0x0;
void register_external_BreakoutGameArduino_send_display_clear_listener(void (*_listener)(struct BreakoutGameArduino_Instance *)){
external_BreakoutGameArduino_send_display_clear_listener = _listener;
}
void register_BreakoutGameArduino_send_display_clear_listener(void (*_listener)(struct BreakoutGameArduino_Instance *)){
BreakoutGameArduino_send_display_clear_listener = _listener;
}
void BreakoutGameArduino_send_display_clear(struct BreakoutGameArduino_Instance *_instance){
if (BreakoutGameArduino_send_display_clear_listener != 0x0) BreakoutGameArduino_send_display_clear_listener(_instance);
if (external_BreakoutGameArduino_send_display_clear_listener != 0x0) external_BreakoutGameArduino_send_display_clear_listener(_instance);
;
}
void (*external_BreakoutGameArduino_send_display_setColor_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void (*BreakoutGameArduino_send_display_setColor_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_BreakoutGameArduino_send_display_setColor_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t)){
external_BreakoutGameArduino_send_display_setColor_listener = _listener;
}
void register_BreakoutGameArduino_send_display_setColor_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t)){
BreakoutGameArduino_send_display_setColor_listener = _listener;
}
void BreakoutGameArduino_send_display_setColor(struct BreakoutGameArduino_Instance *_instance, uint8_t r, uint8_t g, uint8_t b){
if (BreakoutGameArduino_send_display_setColor_listener != 0x0) BreakoutGameArduino_send_display_setColor_listener(_instance, r, g, b);
if (external_BreakoutGameArduino_send_display_setColor_listener != 0x0) external_BreakoutGameArduino_send_display_setColor_listener(_instance, r, g, b);
;
}
void (*external_BreakoutGameArduino_send_display_setBGColor_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void (*BreakoutGameArduino_send_display_setBGColor_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_BreakoutGameArduino_send_display_setBGColor_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t)){
external_BreakoutGameArduino_send_display_setBGColor_listener = _listener;
}
void register_BreakoutGameArduino_send_display_setBGColor_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t)){
BreakoutGameArduino_send_display_setBGColor_listener = _listener;
}
void BreakoutGameArduino_send_display_setBGColor(struct BreakoutGameArduino_Instance *_instance, uint8_t r, uint8_t g, uint8_t b){
if (BreakoutGameArduino_send_display_setBGColor_listener != 0x0) BreakoutGameArduino_send_display_setBGColor_listener(_instance, r, g, b);
if (external_BreakoutGameArduino_send_display_setBGColor_listener != 0x0) external_BreakoutGameArduino_send_display_setBGColor_listener(_instance, r, g, b);
;
}
void (*external_BreakoutGameArduino_send_display_drawInteger_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, int16_t, uint8_t, uint8_t)= 0x0;
void (*BreakoutGameArduino_send_display_drawInteger_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, int16_t, uint8_t, uint8_t)= 0x0;
void register_external_BreakoutGameArduino_send_display_drawInteger_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, int16_t, uint8_t, uint8_t)){
external_BreakoutGameArduino_send_display_drawInteger_listener = _listener;
}
void register_BreakoutGameArduino_send_display_drawInteger_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, int16_t, uint8_t, uint8_t)){
BreakoutGameArduino_send_display_drawInteger_listener = _listener;
}
void BreakoutGameArduino_send_display_drawInteger(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale){
if (BreakoutGameArduino_send_display_drawInteger_listener != 0x0) BreakoutGameArduino_send_display_drawInteger_listener(_instance, x, y, v, digits, scale);
if (external_BreakoutGameArduino_send_display_drawInteger_listener != 0x0) external_BreakoutGameArduino_send_display_drawInteger_listener(_instance, x, y, v, digits, scale);
;
}
void (*external_BreakoutGameArduino_send_display_update_listener)(struct BreakoutGameArduino_Instance *)= 0x0;
void (*BreakoutGameArduino_send_display_update_listener)(struct BreakoutGameArduino_Instance *)= 0x0;
void register_external_BreakoutGameArduino_send_display_update_listener(void (*_listener)(struct BreakoutGameArduino_Instance *)){
external_BreakoutGameArduino_send_display_update_listener = _listener;
}
void register_BreakoutGameArduino_send_display_update_listener(void (*_listener)(struct BreakoutGameArduino_Instance *)){
BreakoutGameArduino_send_display_update_listener = _listener;
}
void BreakoutGameArduino_send_display_update(struct BreakoutGameArduino_Instance *_instance){
if (BreakoutGameArduino_send_display_update_listener != 0x0) BreakoutGameArduino_send_display_update_listener(_instance);
if (external_BreakoutGameArduino_send_display_update_listener != 0x0) external_BreakoutGameArduino_send_display_update_listener(_instance);
;
}
void (*external_BreakoutGameArduino_send_display_drawThingML_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t)= 0x0;
void (*BreakoutGameArduino_send_display_drawThingML_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t)= 0x0;
void register_external_BreakoutGameArduino_send_display_drawThingML_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t)){
external_BreakoutGameArduino_send_display_drawThingML_listener = _listener;
}
void register_BreakoutGameArduino_send_display_drawThingML_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t)){
BreakoutGameArduino_send_display_drawThingML_listener = _listener;
}
void BreakoutGameArduino_send_display_drawThingML(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y){
if (BreakoutGameArduino_send_display_drawThingML_listener != 0x0) BreakoutGameArduino_send_display_drawThingML_listener(_instance, x, y);
if (external_BreakoutGameArduino_send_display_drawThingML_listener != 0x0) external_BreakoutGameArduino_send_display_drawThingML_listener(_instance, x, y);
;
}
void (*external_BreakoutGameArduino_send_ia_updateIA_listener)(struct BreakoutGameArduino_Instance *, int16_t, int16_t, int16_t, int16_t)= 0x0;
void (*BreakoutGameArduino_send_ia_updateIA_listener)(struct BreakoutGameArduino_Instance *, int16_t, int16_t, int16_t, int16_t)= 0x0;
void register_external_BreakoutGameArduino_send_ia_updateIA_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, int16_t, int16_t, int16_t, int16_t)){
external_BreakoutGameArduino_send_ia_updateIA_listener = _listener;
}
void register_BreakoutGameArduino_send_ia_updateIA_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, int16_t, int16_t, int16_t, int16_t)){
BreakoutGameArduino_send_ia_updateIA_listener = _listener;
}
void BreakoutGameArduino_send_ia_updateIA(struct BreakoutGameArduino_Instance *_instance, int16_t ballx, int16_t bally, int16_t padx, int16_t pady){
if (BreakoutGameArduino_send_ia_updateIA_listener != 0x0) BreakoutGameArduino_send_ia_updateIA_listener(_instance, ballx, bally, padx, pady);
if (external_BreakoutGameArduino_send_ia_updateIA_listener != 0x0) external_BreakoutGameArduino_send_ia_updateIA_listener(_instance, ballx, bally, padx, pady);
;
}
void (*external_BreakoutGameArduino_send_game_lostBall_listener)(struct BreakoutGameArduino_Instance *)= 0x0;
void (*BreakoutGameArduino_send_game_lostBall_listener)(struct BreakoutGameArduino_Instance *)= 0x0;
void register_external_BreakoutGameArduino_send_game_lostBall_listener(void (*_listener)(struct BreakoutGameArduino_Instance *)){
external_BreakoutGameArduino_send_game_lostBall_listener = _listener;
}
void register_BreakoutGameArduino_send_game_lostBall_listener(void (*_listener)(struct BreakoutGameArduino_Instance *)){
BreakoutGameArduino_send_game_lostBall_listener = _listener;
}
void BreakoutGameArduino_send_game_lostBall(struct BreakoutGameArduino_Instance *_instance){
if (BreakoutGameArduino_send_game_lostBall_listener != 0x0) BreakoutGameArduino_send_game_lostBall_listener(_instance);
if (external_BreakoutGameArduino_send_game_lostBall_listener != 0x0) external_BreakoutGameArduino_send_game_lostBall_listener(_instance);
;
}
void (*external_BreakoutGameArduino_send_game_nextLevel_listener)(struct BreakoutGameArduino_Instance *)= 0x0;
void (*BreakoutGameArduino_send_game_nextLevel_listener)(struct BreakoutGameArduino_Instance *)= 0x0;
void register_external_BreakoutGameArduino_send_game_nextLevel_listener(void (*_listener)(struct BreakoutGameArduino_Instance *)){
external_BreakoutGameArduino_send_game_nextLevel_listener = _listener;
}
void register_BreakoutGameArduino_send_game_nextLevel_listener(void (*_listener)(struct BreakoutGameArduino_Instance *)){
BreakoutGameArduino_send_game_nextLevel_listener = _listener;
}
void BreakoutGameArduino_send_game_nextLevel(struct BreakoutGameArduino_Instance *_instance){
if (BreakoutGameArduino_send_game_nextLevel_listener != 0x0) BreakoutGameArduino_send_game_nextLevel_listener(_instance);
if (external_BreakoutGameArduino_send_game_nextLevel_listener != 0x0) external_BreakoutGameArduino_send_game_nextLevel_listener(_instance);
;
}
void (*external_BreakoutGameArduino_send_req_game_lostBall_listener)(struct BreakoutGameArduino_Instance *)= 0x0;
void (*BreakoutGameArduino_send_req_game_lostBall_listener)(struct BreakoutGameArduino_Instance *)= 0x0;
void register_external_BreakoutGameArduino_send_req_game_lostBall_listener(void (*_listener)(struct BreakoutGameArduino_Instance *)){
external_BreakoutGameArduino_send_req_game_lostBall_listener = _listener;
}
void register_BreakoutGameArduino_send_req_game_lostBall_listener(void (*_listener)(struct BreakoutGameArduino_Instance *)){
BreakoutGameArduino_send_req_game_lostBall_listener = _listener;
}
void BreakoutGameArduino_send_req_game_lostBall(struct BreakoutGameArduino_Instance *_instance){
if (BreakoutGameArduino_send_req_game_lostBall_listener != 0x0) BreakoutGameArduino_send_req_game_lostBall_listener(_instance);
if (external_BreakoutGameArduino_send_req_game_lostBall_listener != 0x0) external_BreakoutGameArduino_send_req_game_lostBall_listener(_instance);
;
}
void (*external_BreakoutGameArduino_send_req_game_nextLevel_listener)(struct BreakoutGameArduino_Instance *)= 0x0;
void (*BreakoutGameArduino_send_req_game_nextLevel_listener)(struct BreakoutGameArduino_Instance *)= 0x0;
void register_external_BreakoutGameArduino_send_req_game_nextLevel_listener(void (*_listener)(struct BreakoutGameArduino_Instance *)){
external_BreakoutGameArduino_send_req_game_nextLevel_listener = _listener;
}
void register_BreakoutGameArduino_send_req_game_nextLevel_listener(void (*_listener)(struct BreakoutGameArduino_Instance *)){
BreakoutGameArduino_send_req_game_nextLevel_listener = _listener;
}
void BreakoutGameArduino_send_req_game_nextLevel(struct BreakoutGameArduino_Instance *_instance){
if (BreakoutGameArduino_send_req_game_nextLevel_listener != 0x0) BreakoutGameArduino_send_req_game_nextLevel_listener(_instance);
if (external_BreakoutGameArduino_send_req_game_nextLevel_listener != 0x0) external_BreakoutGameArduino_send_req_game_nextLevel_listener(_instance);
;
}



/*****************************************************************************
 * Implementation for type : BasicIAController
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void BasicIAController_SC_OnExit(int state, struct BasicIAController_Instance *_instance);
//Prototypes: Message Sending
void BasicIAController_send_controls_position(struct BasicIAController_Instance *_instance, int16_t x, int16_t y);
//Prototypes: Function
// Declaration of functions:

// Sessions functionss:


// On Entry Actions:
void BasicIAController_SC_OnEntry(int state, struct BasicIAController_Instance *_instance) {
switch(state) {
case BASICIACONTROLLER_SC_STATE:{
_instance->BasicIAController_SC_State = BASICIACONTROLLER_SC_FOLLOWING_STATE;
BasicIAController_SC_OnEntry(_instance->BasicIAController_SC_State, _instance);
break;
}
case BASICIACONTROLLER_SC_FOLLOWING_STATE:{
BasicIAController_send_controls_position(_instance, _instance->BasicIAController_ctrlx_var, 0);
break;
}
default: break;
}
}

// On Exit Actions:
void BasicIAController_SC_OnExit(int state, struct BasicIAController_Instance *_instance) {
switch(state) {
case BASICIACONTROLLER_SC_STATE:{
BasicIAController_SC_OnExit(_instance->BasicIAController_SC_State, _instance);
break;}
case BASICIACONTROLLER_SC_FOLLOWING_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void BasicIAController_handle_game_updateIA(struct BasicIAController_Instance *_instance, int16_t ballx, int16_t bally, int16_t padx, int16_t pady) {
if(!(_instance->active)) return;
//Region SC
uint8_t BasicIAController_SC_State_event_consumed = 0;
if (_instance->BasicIAController_SC_State == BASICIACONTROLLER_SC_FOLLOWING_STATE) {
if (BasicIAController_SC_State_event_consumed == 0 && 1) {
BasicIAController_SC_OnExit(BASICIACONTROLLER_SC_FOLLOWING_STATE, _instance);
_instance->BasicIAController_SC_State = BASICIACONTROLLER_SC_FOLLOWING_STATE;
if(ballx > padx + 400) {
_instance->BasicIAController_ctrlx_var = _instance->BasicIAController_ctrlx_var + 4;

} else {
if(ballx < padx - 400) {
_instance->BasicIAController_ctrlx_var = _instance->BasicIAController_ctrlx_var - 4;

}

}
if(_instance->BasicIAController_ctrlx_var <  -100) {
_instance->BasicIAController_ctrlx_var =  -100;

} else {
if(_instance->BasicIAController_ctrlx_var > 100) {
_instance->BasicIAController_ctrlx_var = 100;

}

}
BasicIAController_SC_OnEntry(BASICIACONTROLLER_SC_FOLLOWING_STATE, _instance);
BasicIAController_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}

// Observers for outgoing messages:
void (*external_BasicIAController_send_controls_position_listener)(struct BasicIAController_Instance *, int16_t, int16_t)= 0x0;
void (*BasicIAController_send_controls_position_listener)(struct BasicIAController_Instance *, int16_t, int16_t)= 0x0;
void register_external_BasicIAController_send_controls_position_listener(void (*_listener)(struct BasicIAController_Instance *, int16_t, int16_t)){
external_BasicIAController_send_controls_position_listener = _listener;
}
void register_BasicIAController_send_controls_position_listener(void (*_listener)(struct BasicIAController_Instance *, int16_t, int16_t)){
BasicIAController_send_controls_position_listener = _listener;
}
void BasicIAController_send_controls_position(struct BasicIAController_Instance *_instance, int16_t x, int16_t y){
if (BasicIAController_send_controls_position_listener != 0x0) BasicIAController_send_controls_position_listener(_instance, x, y);
if (external_BasicIAController_send_controls_position_listener != 0x0) external_BasicIAController_send_controls_position_listener(_instance, x, y);
;
}




#define MAX_INSTANCES 13
#define FIFO_SIZE 256

/*********************************
 * Instance IDs and lookup
 *********************************/

void * instances[MAX_INSTANCES];
uint16_t instances_count = 0;

void * instance_by_id(uint16_t id) {
  return instances[id];
}

uint16_t add_instance(void * instance_struct) {
  instances[instances_count] = instance_struct;
  return instances_count++;
}

/******************************************
 * Simple byte FIFO implementation
 ******************************************/

byte fifo[FIFO_SIZE];
int fifo_head = 0;
int fifo_tail = 0;

// Returns the number of byte currently in the fifo
int fifo_byte_length() {
  if (fifo_tail >= fifo_head)
    return fifo_tail - fifo_head;
  return fifo_tail + FIFO_SIZE - fifo_head;
}

// Returns the number of bytes currently available in the fifo
int fifo_byte_available() {
  return FIFO_SIZE - 1 - fifo_byte_length();
}

// Returns true if the fifo is empty
int fifo_empty() {
  return fifo_head == fifo_tail;
}

// Return true if the fifo is full
int fifo_full() {
  return fifo_head == ((fifo_tail + 1) % FIFO_SIZE);
}

// Enqueue 1 byte in the fifo if there is space
// returns 1 for sucess and 0 if the fifo was full
int fifo_enqueue(byte b) {
  int new_tail = (fifo_tail + 1) % FIFO_SIZE;
  if (new_tail == fifo_head) return 0; // the fifo is full
  fifo[fifo_tail] = b;
  fifo_tail = new_tail;
  return 1;
}

// Enqueue 1 byte in the fifo without checking for available space
// The caller should have checked that there is enough space
int _fifo_enqueue(byte b) {
  fifo[fifo_tail] = b;
  fifo_tail = (fifo_tail + 1) % FIFO_SIZE;
  return 0; // Dummy added by steffend
}

// Dequeue 1 byte in the fifo.
// The caller should check that the fifo is not empty
byte fifo_dequeue() {
  if (!fifo_empty()) {
    byte result = fifo[fifo_head];
    fifo_head = (fifo_head + 1) % FIFO_SIZE;
    return result;
  }
  return 0;
}

/*****************************************************************************
 * Implementation for type : TimerArduino
 *****************************************************************************/


// BEGIN: Code from the c_global annotation TimerArduino
uint32_t Timer_timeouts[NB_SOFT_TIMERS];
uint8_t  Timer_wraps[NB_SOFT_TIMERS];
uint32_t Timer_prev;
// END: Code from the c_global annotation TimerArduino

// Declaration of prototypes:
//Prototypes: State Machine
void TimerArduino_SoftTimer_OnExit(int state, struct TimerArduino_Instance *_instance);
//Prototypes: Message Sending
void TimerArduino_send_timer_timer_timeout(struct TimerArduino_Instance *_instance, uint8_t id);
//Prototypes: Function
uint32_t f_TimerArduino_time_ms(struct TimerArduino_Instance *_instance);
void f_TimerArduino_init_arrays(struct TimerArduino_Instance *_instance);
void f_TimerArduino_poll_soft_timers(struct TimerArduino_Instance *_instance);
void f_TimerArduino_startTimer(struct TimerArduino_Instance *_instance, uint8_t id, uint16_t delay);
void f_TimerArduino_cancel(struct TimerArduino_Instance *_instance, uint8_t id);
// Declaration of functions:
// Definition of function time_ms
uint32_t f_TimerArduino_time_ms(struct TimerArduino_Instance *_instance) {
return millis();
}
// Definition of function init_arrays
void f_TimerArduino_init_arrays(struct TimerArduino_Instance *_instance) {
uint8_t i;
	    for (i = 0; i < _instance->TimerArduino_NB_SOFT_TIMERS_var; i++) {
	        Timer_timeouts[i] = 0;
	        Timer_wraps[i] = 0;
	    }
	    Timer_prev = f_TimerArduino_time_ms(_instance);
}
// Definition of function poll_soft_timers
void f_TimerArduino_poll_soft_timers(struct TimerArduino_Instance *_instance) {
uint32_t current = f_TimerArduino_time_ms(_instance);
		uint8_t i;
		for (i = 0; i < _instance->TimerArduino_NB_SOFT_TIMERS_var; i++) {
		    if (Timer_timeouts[i] > 0) {
		        if (current >= Timer_prev) {
		            // Normal time progression
		            if (current > Timer_timeouts[i] && Timer_wraps[i] == 0) {
TimerArduino_send_timer_timer_timeout(_instance, i);
Timer_timeouts[i] = 0;
		                Timer_wraps[i] = 0;
		            }
		        } else {
		            // A wraparound has occurred
		            if (Timer_wraps[i] == 0) {
TimerArduino_send_timer_timer_timeout(_instance, i);
Timer_timeouts[i] = 0;
		            } else {
		                Timer_wraps[i] = 0;
		                if (current > Timer_timeouts[i]) {
TimerArduino_send_timer_timer_timeout(_instance, i);
Timer_timeouts[i] = 0;
		                }
		            }
		        }
		    }
		}
}
// Definition of function startTimer
void f_TimerArduino_startTimer(struct TimerArduino_Instance *_instance, uint8_t id, uint16_t delay) {

    	if (id < NB_SOFT_TIMERS) {
	        uint32_t current = f_TimerArduino_time_ms(_instance);
	        uint32_t timeout = current + delay;
	        if (timeout == 0) timeout = 1;
	
	        Timer_timeouts[id] = timeout;
	        Timer_wraps[id] = (timeout > current) ? 0 : 1;
	    }
    
}
// Definition of function cancel
void f_TimerArduino_cancel(struct TimerArduino_Instance *_instance, uint8_t id) {

        if (id < NB_SOFT_TIMERS) {
	        Timer_timeouts[id] = 0;
	        Timer_wraps[id] = 0;
	    }
      
}

// Sessions functionss:


// On Entry Actions:
void TimerArduino_SoftTimer_OnEntry(int state, struct TimerArduino_Instance *_instance) {
switch(state) {
case TIMERARDUINO_SOFTTIMER_STATE:{
_instance->TimerArduino_SoftTimer_State = TIMERARDUINO_SOFTTIMER_DEFAULT_STATE;
f_TimerArduino_init_arrays(_instance);
TimerArduino_SoftTimer_OnEntry(_instance->TimerArduino_SoftTimer_State, _instance);
break;
}
case TIMERARDUINO_SOFTTIMER_DEFAULT_STATE:{
break;
}
default: break;
}
}

// On Exit Actions:
void TimerArduino_SoftTimer_OnExit(int state, struct TimerArduino_Instance *_instance) {
switch(state) {
case TIMERARDUINO_SOFTTIMER_STATE:{
TimerArduino_SoftTimer_OnExit(_instance->TimerArduino_SoftTimer_State, _instance);
break;}
case TIMERARDUINO_SOFTTIMER_DEFAULT_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void TimerArduino_handle_timer_timer_cancel(struct TimerArduino_Instance *_instance, uint8_t id) {
if(!(_instance->active)) return;
//Region SoftTimer
uint8_t TimerArduino_SoftTimer_State_event_consumed = 0;
if (_instance->TimerArduino_SoftTimer_State == TIMERARDUINO_SOFTTIMER_DEFAULT_STATE) {
if (TimerArduino_SoftTimer_State_event_consumed == 0 && 1) {
f_TimerArduino_cancel(_instance, id);
TimerArduino_SoftTimer_State_event_consumed = 1;
}
}
//End Region SoftTimer
//End dsregion SoftTimer
//Session list: 
}
void TimerArduino_handle_timer_timer_start(struct TimerArduino_Instance *_instance, uint8_t id, uint16_t time) {
if(!(_instance->active)) return;
//Region SoftTimer
uint8_t TimerArduino_SoftTimer_State_event_consumed = 0;
if (_instance->TimerArduino_SoftTimer_State == TIMERARDUINO_SOFTTIMER_DEFAULT_STATE) {
if (TimerArduino_SoftTimer_State_event_consumed == 0 && time > 0) {
f_TimerArduino_startTimer(_instance, id, time);
TimerArduino_SoftTimer_State_event_consumed = 1;
}
else if (TimerArduino_SoftTimer_State_event_consumed == 0 && time == 0) {
TimerArduino_send_timer_timer_timeout(_instance, id);
TimerArduino_SoftTimer_State_event_consumed = 1;
}
}
//End Region SoftTimer
//End dsregion SoftTimer
//Session list: 
}

// Observers for outgoing messages:
void (*external_TimerArduino_send_timer_timer_timeout_listener)(struct TimerArduino_Instance *, uint8_t)= 0x0;
void (*TimerArduino_send_timer_timer_timeout_listener)(struct TimerArduino_Instance *, uint8_t)= 0x0;
void register_external_TimerArduino_send_timer_timer_timeout_listener(void (*_listener)(struct TimerArduino_Instance *, uint8_t)){
external_TimerArduino_send_timer_timer_timeout_listener = _listener;
}
void register_TimerArduino_send_timer_timer_timeout_listener(void (*_listener)(struct TimerArduino_Instance *, uint8_t)){
TimerArduino_send_timer_timer_timeout_listener = _listener;
}
void TimerArduino_send_timer_timer_timeout(struct TimerArduino_Instance *_instance, uint8_t id){
if (TimerArduino_send_timer_timer_timeout_listener != 0x0) TimerArduino_send_timer_timer_timeout_listener(_instance, id);
if (external_TimerArduino_send_timer_timer_timeout_listener != 0x0) external_TimerArduino_send_timer_timer_timeout_listener(_instance, id);
;
}



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



/*****************************************************************************
 * Implementation for type : ConsoleLogger
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void Logger_OnExit(int state, struct ConsoleLogger_Instance *_instance);
//Prototypes: Message Sending
//Prototypes: Function
void f_ConsoleLogger_log_function_called(struct ConsoleLogger_Instance *_instance, String inst, String fn_name, String ty, String returns, String params);
void f_ConsoleLogger_log_property_changed(struct ConsoleLogger_Instance *_instance, String inst, String prop_name, String ty, String old_value, String new_value);
void f_ConsoleLogger_log_message_lost(struct ConsoleLogger_Instance *_instance, String inst, String port_name, String msg_name, String params);
void f_ConsoleLogger_log_message_sent(struct ConsoleLogger_Instance *_instance, String inst, String port_name, String msg_name, String params);
void f_ConsoleLogger_log_message_handled(struct ConsoleLogger_Instance *_instance, String inst, String source, String target, String port_name, String msg_name, String params);
// Declaration of functions:
// Definition of function log_function_called
void f_ConsoleLogger_log_function_called(struct ConsoleLogger_Instance *_instance, String inst, String fn_name, String ty, String returns, String params) {
Serial.print("function_called(");
Serial.print(inst);
Serial.print(", ");
Serial.print(fn_name);
Serial.print(", ");
Serial.print(ty);
Serial.print(", ");
Serial.print(returns);
Serial.print(", ");
Serial.print(params);
Serial.print(")");
Serial.print("\n");
}
// Definition of function log_property_changed
void f_ConsoleLogger_log_property_changed(struct ConsoleLogger_Instance *_instance, String inst, String prop_name, String ty, String old_value, String new_value) {
Serial.print("property_changed(");
Serial.print(inst);
Serial.print(", ");
Serial.print(prop_name);
Serial.print(", ");
Serial.print(ty);
Serial.print(", ");
Serial.print(old_value);
Serial.print(", ");
Serial.print(new_value);
Serial.print(")");
Serial.print("\n");
}
// Definition of function log_message_lost
void f_ConsoleLogger_log_message_lost(struct ConsoleLogger_Instance *_instance, String inst, String port_name, String msg_name, String params) {
Serial.print("message_lost(");
Serial.print(inst);
Serial.print(", ");
Serial.print(port_name);
Serial.print(", ");
Serial.print(msg_name);
Serial.print(", ");
Serial.print(params);
Serial.print(")");
Serial.print("\n");
}
// Definition of function log_message_sent
void f_ConsoleLogger_log_message_sent(struct ConsoleLogger_Instance *_instance, String inst, String port_name, String msg_name, String params) {
Serial.print("message_sent(");
Serial.print(inst);
Serial.print(", ");
Serial.print(port_name);
Serial.print(", ");
Serial.print(msg_name);
Serial.print(", ");
Serial.print(params);
Serial.print(")");
Serial.print("\n");
}
// Definition of function log_message_handled
void f_ConsoleLogger_log_message_handled(struct ConsoleLogger_Instance *_instance, String inst, String source, String target, String port_name, String msg_name, String params) {
Serial.print("message_handled(");
Serial.print(inst);
Serial.print(", ");
Serial.print(source);
Serial.print(", ");
Serial.print(target);
Serial.print(", ");
Serial.print(port_name);
Serial.print(", ");
Serial.print(msg_name);
Serial.print(", ");
Serial.print(params);
Serial.print(")");
Serial.print("\n");
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
void ConsoleLogger_handle_log_property_changed(struct ConsoleLogger_Instance *_instance, String inst, String prop_name, String ty, String old_value, String new_value) {
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
void ConsoleLogger_handle_log_message_handled(struct ConsoleLogger_Instance *_instance, String inst, String source, String target, String port_name, String msg_name, String params) {
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
void ConsoleLogger_handle_log_function_called(struct ConsoleLogger_Instance *_instance, String inst, String fn_name, String ty, String returns, String params) {
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
void ConsoleLogger_handle_log_message_sent(struct ConsoleLogger_Instance *_instance, String inst, String port_name, String msg_name, String params) {
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
void ConsoleLogger_handle_log_message_lost(struct ConsoleLogger_Instance *_instance, String inst, String port_name, String msg_name, String params) {
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






/*****************************************************************************
 * Definitions for configuration : test
 *****************************************************************************/

uint8_t array_game_BreakoutGame_fgcolor_var[3];
uint8_t array_game_BreakoutGame_bgcolor_var[3];
uint8_t array_game_BreakoutGame_bricks_var[5];
//Declaration of instance variables
//Instance disp
// Variables for the properties of the instance
struct HeadlessDisplay_Instance disp_var;
// Variables for the sessions of the instance
//Instance timer
// Variables for the properties of the instance
struct TimerArduino_Instance timer_var;
// Variables for the sessions of the instance
//Instance ctrl
// Variables for the properties of the instance
struct BasicIAController_Instance ctrl_var;
// Variables for the sessions of the instance
//Instance log
// Variables for the properties of the instance
struct ConsoleLogger_Instance log_var;
// Variables for the sessions of the instance
//Instance game
// Variables for the properties of the instance
struct BreakoutGameArduino_Instance game_var;
// Variables for the sessions of the instance


// Enqueue of messages HeadlessDisplay::display::displayReady
void enqueue_HeadlessDisplay_send_display_displayReady(struct HeadlessDisplay_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (1 >> 8) & 0xFF );
_fifo_enqueue( 1 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_display >> 8) & 0xFF );
_fifo_enqueue( _instance->id_display & 0xFF );
}
}
// Enqueue of messages TimerArduino::timer::timer_timeout
void enqueue_TimerArduino_send_timer_timer_timeout(struct TimerArduino_Instance *_instance, uint8_t id){
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (2 >> 8) & 0xFF );
_fifo_enqueue( 2 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_timer >> 8) & 0xFF );
_fifo_enqueue( _instance->id_timer & 0xFF );

// parameter id
union u_id_t {
uint8_t p;
byte bytebuffer[1];
} u_id;
u_id.p = id;
_fifo_enqueue(u_id.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages BasicIAController::controls::position
void enqueue_BasicIAController_send_controls_position(struct BasicIAController_Instance *_instance, int16_t x, int16_t y){
if ( fifo_byte_available() > 8 ) {

_fifo_enqueue( (3 >> 8) & 0xFF );
_fifo_enqueue( 3 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_controls >> 8) & 0xFF );
_fifo_enqueue( _instance->id_controls & 0xFF );

// parameter x
union u_x_t {
int16_t p;
byte bytebuffer[2];
} u_x;
u_x.p = x;
_fifo_enqueue(u_x.bytebuffer[0] & 0xFF );
_fifo_enqueue(u_x.bytebuffer[1] & 0xFF );

// parameter y
union u_y_t {
int16_t p;
byte bytebuffer[2];
} u_y;
u_y.p = y;
_fifo_enqueue(u_y.bytebuffer[0] & 0xFF );
_fifo_enqueue(u_y.bytebuffer[1] & 0xFF );
}
}
// Enqueue of messages BreakoutGameArduino::clock::timer_cancel
void enqueue_BreakoutGameArduino_send_clock_timer_cancel(struct BreakoutGameArduino_Instance *_instance, uint8_t id){
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (4 >> 8) & 0xFF );
_fifo_enqueue( 4 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_clock >> 8) & 0xFF );
_fifo_enqueue( _instance->id_clock & 0xFF );

// parameter id
union u_id_t {
uint8_t p;
byte bytebuffer[1];
} u_id;
u_id.p = id;
_fifo_enqueue(u_id.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages BreakoutGameArduino::clock::timer_start
void enqueue_BreakoutGameArduino_send_clock_timer_start(struct BreakoutGameArduino_Instance *_instance, uint8_t id, uint16_t time){
if ( fifo_byte_available() > 7 ) {

_fifo_enqueue( (5 >> 8) & 0xFF );
_fifo_enqueue( 5 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_clock >> 8) & 0xFF );
_fifo_enqueue( _instance->id_clock & 0xFF );

// parameter id
union u_id_t {
uint8_t p;
byte bytebuffer[1];
} u_id;
u_id.p = id;
_fifo_enqueue(u_id.bytebuffer[0] & 0xFF );

// parameter time
union u_time_t {
uint16_t p;
byte bytebuffer[2];
} u_time;
u_time.p = time;
_fifo_enqueue(u_time.bytebuffer[0] & 0xFF );
_fifo_enqueue(u_time.bytebuffer[1] & 0xFF );
}
}
// Enqueue of messages BreakoutGameArduino::ia::updateIA
void enqueue_BreakoutGameArduino_send_ia_updateIA(struct BreakoutGameArduino_Instance *_instance, int16_t ballx, int16_t bally, int16_t padx, int16_t pady){
if ( fifo_byte_available() > 12 ) {

_fifo_enqueue( (6 >> 8) & 0xFF );
_fifo_enqueue( 6 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_ia >> 8) & 0xFF );
_fifo_enqueue( _instance->id_ia & 0xFF );

// parameter ballx
union u_ballx_t {
int16_t p;
byte bytebuffer[2];
} u_ballx;
u_ballx.p = ballx;
_fifo_enqueue(u_ballx.bytebuffer[0] & 0xFF );
_fifo_enqueue(u_ballx.bytebuffer[1] & 0xFF );

// parameter bally
union u_bally_t {
int16_t p;
byte bytebuffer[2];
} u_bally;
u_bally.p = bally;
_fifo_enqueue(u_bally.bytebuffer[0] & 0xFF );
_fifo_enqueue(u_bally.bytebuffer[1] & 0xFF );

// parameter padx
union u_padx_t {
int16_t p;
byte bytebuffer[2];
} u_padx;
u_padx.p = padx;
_fifo_enqueue(u_padx.bytebuffer[0] & 0xFF );
_fifo_enqueue(u_padx.bytebuffer[1] & 0xFF );

// parameter pady
union u_pady_t {
int16_t p;
byte bytebuffer[2];
} u_pady;
u_pady.p = pady;
_fifo_enqueue(u_pady.bytebuffer[0] & 0xFF );
_fifo_enqueue(u_pady.bytebuffer[1] & 0xFF );
}
}
// Enqueue of messages BreakoutGameArduino::game::lostBall
void enqueue_BreakoutGameArduino_send_game_lostBall(struct BreakoutGameArduino_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (7 >> 8) & 0xFF );
_fifo_enqueue( 7 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_game >> 8) & 0xFF );
_fifo_enqueue( _instance->id_game & 0xFF );
}
}
// Enqueue of messages BreakoutGameArduino::game::nextLevel
void enqueue_BreakoutGameArduino_send_game_nextLevel(struct BreakoutGameArduino_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (8 >> 8) & 0xFF );
_fifo_enqueue( 8 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_game >> 8) & 0xFF );
_fifo_enqueue( _instance->id_game & 0xFF );
}
}
// Enqueue of messages BreakoutGameArduino::req_game::lostBall
void enqueue_BreakoutGameArduino_send_req_game_lostBall(struct BreakoutGameArduino_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (7 >> 8) & 0xFF );
_fifo_enqueue( 7 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_req_game >> 8) & 0xFF );
_fifo_enqueue( _instance->id_req_game & 0xFF );
}
}
// Enqueue of messages BreakoutGameArduino::req_game::nextLevel
void enqueue_BreakoutGameArduino_send_req_game_nextLevel(struct BreakoutGameArduino_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (8 >> 8) & 0xFF );
_fifo_enqueue( 8 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_req_game >> 8) & 0xFF );
_fifo_enqueue( _instance->id_req_game & 0xFF );
}
}


//New dispatcher for messages
void dispatch_displayReady(uint16_t sender) {
if (sender == disp_var.id_display) {
BreakoutGameArduino_handle_display_displayReady(&game_var);

}
if (sender == game_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_position(uint16_t sender, int16_t param_x, int16_t param_y) {
if (sender == ctrl_var.id_controls) {
BreakoutGameArduino_handle_controller_position(&game_var, param_x, param_y);

}
if (sender == game_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_log_on(uint16_t sender) {
if (sender == game_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_timer_cancel(uint16_t sender, uint8_t param_id) {
if (sender == game_var.id_clock) {
TimerArduino_handle_timer_timer_cancel(&timer_var, param_id);

}
if (sender == game_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_message_lost(uint16_t sender, String param_inst, String param_port_name, String param_msg_name, String param_params) {
if (sender == game_var.id_game) {

}
if (sender == game_var.id_log) {
ConsoleLogger_handle_log_message_lost(&log_var, param_inst, param_port_name, param_msg_name, param_params);

}

}

void sync_dispatch_BreakoutGameArduino_send_log_message_lost(struct BreakoutGameArduino_Instance *_instance, String inst, String port_name, String msg_name, String params){
dispatch_message_lost(_instance->id_log, inst, port_name, msg_name, params);
}

//New dispatcher for messages
void dispatch_velocity(uint16_t sender, int16_t param_dx, int16_t param_dy) {
if (sender == game_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_lostBall(uint16_t sender) {
if (sender == game_var.id_req_game) {
BreakoutGameArduino_handle_pro_game_lostBall(&game_var);

}
if (sender == game_var.id_game) {
BreakoutGameArduino_handle_game_lostBall(&game_var);

}

}


//New dispatcher for messages
void dispatch_fillRect(uint16_t sender, uint8_t param_x, uint8_t param_y, uint8_t param_width, uint8_t param_height) {
if (sender == game_var.id_display) {
HeadlessDisplay_handle_display_fillRect(&disp_var, param_x, param_y, param_width, param_height);

}
if (sender == game_var.id_game) {

}

}

void sync_dispatch_BreakoutGameArduino_send_display_fillRect(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height){
dispatch_fillRect(_instance->id_display, x, y, width, height);
}

//New dispatcher for messages
void dispatch_setColor(uint16_t sender, uint8_t param_r, uint8_t param_g, uint8_t param_b) {
if (sender == game_var.id_display) {
HeadlessDisplay_handle_display_setColor(&disp_var, param_r, param_g, param_b);

}
if (sender == game_var.id_game) {

}

}

void sync_dispatch_BreakoutGameArduino_send_display_setColor(struct BreakoutGameArduino_Instance *_instance, uint8_t r, uint8_t g, uint8_t b){
dispatch_setColor(_instance->id_display, r, g, b);
}

//New dispatcher for messages
void dispatch_message_handled(uint16_t sender, String param_inst, String param_source, String param_target, String param_port_name, String param_msg_name, String param_params) {
if (sender == game_var.id_game) {

}
if (sender == game_var.id_log) {
ConsoleLogger_handle_log_message_handled(&log_var, param_inst, param_source, param_target, param_port_name, param_msg_name, param_params);

}

}

void sync_dispatch_BreakoutGameArduino_send_log_message_handled(struct BreakoutGameArduino_Instance *_instance, String inst, String source, String target, String port_name, String msg_name, String params){
dispatch_message_handled(_instance->id_log, inst, source, target, port_name, msg_name, params);
}

//New dispatcher for messages
void dispatch_create(uint16_t sender, uint8_t param_xsize, uint8_t param_ysize) {
if (sender == game_var.id_display) {
HeadlessDisplay_handle_display_create(&disp_var, param_xsize, param_ysize);

}
if (sender == game_var.id_game) {

}

}

void sync_dispatch_BreakoutGameArduino_send_display_create(struct BreakoutGameArduino_Instance *_instance, uint8_t xsize, uint8_t ysize){
dispatch_create(_instance->id_display, xsize, ysize);
}

//New dispatcher for messages
void dispatch_function_called(uint16_t sender, String param_inst, String param_fn_name, String param_ty, String param_returns, String param_params) {
if (sender == game_var.id_game) {

}
if (sender == game_var.id_log) {
ConsoleLogger_handle_log_function_called(&log_var, param_inst, param_fn_name, param_ty, param_returns, param_params);

}

}

void sync_dispatch_BreakoutGameArduino_send_log_function_called(struct BreakoutGameArduino_Instance *_instance, String inst, String fn_name, String ty, String returns, String params){
dispatch_function_called(_instance->id_log, inst, fn_name, ty, returns, params);
}

//New dispatcher for messages
void dispatch_log_off(uint16_t sender) {
if (sender == game_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_timer_timeout(uint16_t sender, uint8_t param_id) {
if (sender == timer_var.id_timer) {
BreakoutGameArduino_handle_clock_timer_timeout(&game_var, param_id);

}
if (sender == game_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_timer_start(uint16_t sender, uint8_t param_id, uint16_t param_time) {
if (sender == game_var.id_clock) {
TimerArduino_handle_timer_timer_start(&timer_var, param_id, param_time);

}
if (sender == game_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_nextLevel(uint16_t sender) {
if (sender == game_var.id_req_game) {
BreakoutGameArduino_handle_pro_game_nextLevel(&game_var);

}
if (sender == game_var.id_game) {
BreakoutGameArduino_handle_game_nextLevel(&game_var);

}

}


//New dispatcher for messages
void dispatch_setBGColor(uint16_t sender, uint8_t param_r, uint8_t param_g, uint8_t param_b) {
if (sender == game_var.id_display) {
HeadlessDisplay_handle_display_setBGColor(&disp_var, param_r, param_g, param_b);

}
if (sender == game_var.id_game) {

}

}

void sync_dispatch_BreakoutGameArduino_send_display_setBGColor(struct BreakoutGameArduino_Instance *_instance, uint8_t r, uint8_t g, uint8_t b){
dispatch_setBGColor(_instance->id_display, r, g, b);
}

//New dispatcher for messages
void dispatch_drawThingML(uint16_t sender, uint8_t param_x, uint8_t param_y) {
if (sender == game_var.id_display) {
HeadlessDisplay_handle_display_drawThingML(&disp_var, param_x, param_y);

}
if (sender == game_var.id_game) {

}

}

void sync_dispatch_BreakoutGameArduino_send_display_drawThingML(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y){
dispatch_drawThingML(_instance->id_display, x, y);
}

//New dispatcher for messages
void dispatch_update(uint16_t sender) {
if (sender == game_var.id_display) {
HeadlessDisplay_handle_display_update(&disp_var);

}
if (sender == game_var.id_game) {

}

}

void sync_dispatch_BreakoutGameArduino_send_display_update(struct BreakoutGameArduino_Instance *_instance){
dispatch_update(_instance->id_display);
}

//New dispatcher for messages
void dispatch_property_changed(uint16_t sender, String param_inst, String param_prop_name, String param_ty, String param_old_value, String param_new_value) {
if (sender == game_var.id_game) {

}
if (sender == game_var.id_log) {
ConsoleLogger_handle_log_property_changed(&log_var, param_inst, param_prop_name, param_ty, param_old_value, param_new_value);

}

}

void sync_dispatch_BreakoutGameArduino_send_log_property_changed(struct BreakoutGameArduino_Instance *_instance, String inst, String prop_name, String ty, String old_value, String new_value){
dispatch_property_changed(_instance->id_log, inst, prop_name, ty, old_value, new_value);
}

//New dispatcher for messages
void dispatch_drawInteger(uint16_t sender, uint8_t param_x, uint8_t param_y, int16_t param_v, uint8_t param_digits, uint8_t param_scale) {
if (sender == game_var.id_display) {
HeadlessDisplay_handle_display_drawInteger(&disp_var, param_x, param_y, param_v, param_digits, param_scale);

}
if (sender == game_var.id_game) {

}

}

void sync_dispatch_BreakoutGameArduino_send_display_drawInteger(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale){
dispatch_drawInteger(_instance->id_display, x, y, v, digits, scale);
}

//New dispatcher for messages
void dispatch_message_sent(uint16_t sender, String param_inst, String param_port_name, String param_msg_name, String param_params) {
if (sender == game_var.id_game) {

}
if (sender == game_var.id_log) {
ConsoleLogger_handle_log_message_sent(&log_var, param_inst, param_port_name, param_msg_name, param_params);

}

}

void sync_dispatch_BreakoutGameArduino_send_log_message_sent(struct BreakoutGameArduino_Instance *_instance, String inst, String port_name, String msg_name, String params){
dispatch_message_sent(_instance->id_log, inst, port_name, msg_name, params);
}

//New dispatcher for messages
void dispatch_drawRect(uint16_t sender, uint8_t param_x, uint8_t param_y, uint8_t param_width, uint8_t param_height) {
if (sender == game_var.id_display) {
HeadlessDisplay_handle_display_drawRect(&disp_var, param_x, param_y, param_width, param_height);

}
if (sender == game_var.id_game) {

}

}

void sync_dispatch_BreakoutGameArduino_send_display_drawRect(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height){
dispatch_drawRect(_instance->id_display, x, y, width, height);
}

//New dispatcher for messages
void dispatch_destroy(uint16_t sender) {
if (sender == game_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_updateIA(uint16_t sender, int16_t param_ballx, int16_t param_bally, int16_t param_padx, int16_t param_pady) {
if (sender == game_var.id_ia) {
BasicIAController_handle_game_updateIA(&ctrl_var, param_ballx, param_bally, param_padx, param_pady);

}
if (sender == game_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_clear(uint16_t sender) {
if (sender == game_var.id_display) {
HeadlessDisplay_handle_display_clear(&disp_var);

}
if (sender == game_var.id_game) {

}

}

void sync_dispatch_BreakoutGameArduino_send_display_clear(struct BreakoutGameArduino_Instance *_instance){
dispatch_clear(_instance->id_display);
}

int processMessageQueue() {
if (fifo_empty()) return 0; // return 0 if there is nothing to do

uint8_t mbufi = 0;

// Read the code of the next port/message in the queue
uint16_t code = fifo_dequeue() << 8;

code += fifo_dequeue();

// Switch to call the appropriate handler
switch(code) {
case 4:{
byte mbuf[5 - 2];
while (mbufi < (5 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_timer_cancel = 2;
union u_timer_cancel_id_t {
uint8_t p;
byte bytebuffer[1];
} u_timer_cancel_id;
u_timer_cancel_id.bytebuffer[0] = mbuf[mbufi_timer_cancel + 0];
mbufi_timer_cancel += 1;
dispatch_timer_cancel((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_timer_cancel_id.p /* id */ );
break;
}
case 2:{
byte mbuf[5 - 2];
while (mbufi < (5 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_timer_timeout = 2;
union u_timer_timeout_id_t {
uint8_t p;
byte bytebuffer[1];
} u_timer_timeout_id;
u_timer_timeout_id.bytebuffer[0] = mbuf[mbufi_timer_timeout + 0];
mbufi_timer_timeout += 1;
dispatch_timer_timeout((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_timer_timeout_id.p /* id */ );
break;
}
case 6:{
byte mbuf[12 - 2];
while (mbufi < (12 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_updateIA = 2;
union u_updateIA_ballx_t {
int16_t p;
byte bytebuffer[2];
} u_updateIA_ballx;
u_updateIA_ballx.bytebuffer[0] = mbuf[mbufi_updateIA + 0];
u_updateIA_ballx.bytebuffer[1] = mbuf[mbufi_updateIA + 1];
mbufi_updateIA += 2;
union u_updateIA_bally_t {
int16_t p;
byte bytebuffer[2];
} u_updateIA_bally;
u_updateIA_bally.bytebuffer[0] = mbuf[mbufi_updateIA + 0];
u_updateIA_bally.bytebuffer[1] = mbuf[mbufi_updateIA + 1];
mbufi_updateIA += 2;
union u_updateIA_padx_t {
int16_t p;
byte bytebuffer[2];
} u_updateIA_padx;
u_updateIA_padx.bytebuffer[0] = mbuf[mbufi_updateIA + 0];
u_updateIA_padx.bytebuffer[1] = mbuf[mbufi_updateIA + 1];
mbufi_updateIA += 2;
union u_updateIA_pady_t {
int16_t p;
byte bytebuffer[2];
} u_updateIA_pady;
u_updateIA_pady.bytebuffer[0] = mbuf[mbufi_updateIA + 0];
u_updateIA_pady.bytebuffer[1] = mbuf[mbufi_updateIA + 1];
mbufi_updateIA += 2;
dispatch_updateIA((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_updateIA_ballx.p /* ballx */ ,
 u_updateIA_bally.p /* bally */ ,
 u_updateIA_padx.p /* padx */ ,
 u_updateIA_pady.p /* pady */ );
break;
}
case 1:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_displayReady = 2;
dispatch_displayReady((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 5:{
byte mbuf[7 - 2];
while (mbufi < (7 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_timer_start = 2;
union u_timer_start_id_t {
uint8_t p;
byte bytebuffer[1];
} u_timer_start_id;
u_timer_start_id.bytebuffer[0] = mbuf[mbufi_timer_start + 0];
mbufi_timer_start += 1;
union u_timer_start_time_t {
uint16_t p;
byte bytebuffer[2];
} u_timer_start_time;
u_timer_start_time.bytebuffer[0] = mbuf[mbufi_timer_start + 0];
u_timer_start_time.bytebuffer[1] = mbuf[mbufi_timer_start + 1];
mbufi_timer_start += 2;
dispatch_timer_start((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_timer_start_id.p /* id */ ,
 u_timer_start_time.p /* time */ );
break;
}
case 7:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_lostBall = 2;
dispatch_lostBall((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 8:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_nextLevel = 2;
dispatch_nextLevel((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 3:{
byte mbuf[8 - 2];
while (mbufi < (8 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_position = 2;
union u_position_x_t {
int16_t p;
byte bytebuffer[2];
} u_position_x;
u_position_x.bytebuffer[0] = mbuf[mbufi_position + 0];
u_position_x.bytebuffer[1] = mbuf[mbufi_position + 1];
mbufi_position += 2;
union u_position_y_t {
int16_t p;
byte bytebuffer[2];
} u_position_y;
u_position_y.bytebuffer[0] = mbuf[mbufi_position + 0];
u_position_y.bytebuffer[1] = mbuf[mbufi_position + 1];
mbufi_position += 2;
dispatch_position((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_position_x.p /* x */ ,
 u_position_y.p /* y */ );
break;
}
}
return 1;
}


//external Message enqueue

void initialize_configuration_test() {
// Initialize connectors
register_HeadlessDisplay_send_display_displayReady_listener(&enqueue_HeadlessDisplay_send_display_displayReady);
register_TimerArduino_send_timer_timer_timeout_listener(&enqueue_TimerArduino_send_timer_timer_timeout);
register_BasicIAController_send_controls_position_listener(&enqueue_BasicIAController_send_controls_position);
register_BreakoutGameArduino_send_log_property_changed_listener(&sync_dispatch_BreakoutGameArduino_send_log_property_changed);
register_BreakoutGameArduino_send_log_message_handled_listener(&sync_dispatch_BreakoutGameArduino_send_log_message_handled);
register_BreakoutGameArduino_send_log_function_called_listener(&sync_dispatch_BreakoutGameArduino_send_log_function_called);
register_BreakoutGameArduino_send_log_message_sent_listener(&sync_dispatch_BreakoutGameArduino_send_log_message_sent);
register_BreakoutGameArduino_send_log_message_lost_listener(&sync_dispatch_BreakoutGameArduino_send_log_message_lost);
register_BreakoutGameArduino_send_clock_timer_cancel_listener(&enqueue_BreakoutGameArduino_send_clock_timer_cancel);
register_BreakoutGameArduino_send_clock_timer_start_listener(&enqueue_BreakoutGameArduino_send_clock_timer_start);
register_BreakoutGameArduino_send_display_fillRect_listener(&sync_dispatch_BreakoutGameArduino_send_display_fillRect);
register_BreakoutGameArduino_send_display_update_listener(&sync_dispatch_BreakoutGameArduino_send_display_update);
register_BreakoutGameArduino_send_display_setColor_listener(&sync_dispatch_BreakoutGameArduino_send_display_setColor);
register_BreakoutGameArduino_send_display_drawInteger_listener(&sync_dispatch_BreakoutGameArduino_send_display_drawInteger);
register_BreakoutGameArduino_send_display_create_listener(&sync_dispatch_BreakoutGameArduino_send_display_create);
register_BreakoutGameArduino_send_display_drawRect_listener(&sync_dispatch_BreakoutGameArduino_send_display_drawRect);
register_BreakoutGameArduino_send_display_clear_listener(&sync_dispatch_BreakoutGameArduino_send_display_clear);
register_BreakoutGameArduino_send_display_setBGColor_listener(&sync_dispatch_BreakoutGameArduino_send_display_setBGColor);
register_BreakoutGameArduino_send_display_drawThingML_listener(&sync_dispatch_BreakoutGameArduino_send_display_drawThingML);
register_BreakoutGameArduino_send_ia_updateIA_listener(&enqueue_BreakoutGameArduino_send_ia_updateIA);
register_BreakoutGameArduino_send_req_game_lostBall_listener(&enqueue_BreakoutGameArduino_send_req_game_lostBall);
register_BreakoutGameArduino_send_req_game_nextLevel_listener(&enqueue_BreakoutGameArduino_send_req_game_nextLevel);


// Network Initialization
// End Network Initialization

// Init the ID, state variables and properties for instance disp
disp_var.active = true;
disp_var.id_display = add_instance( (void*) &disp_var);
disp_var.HeadlessDisplay_State = HEADLESSDISPLAY_NULL_INIT_STATE;

HeadlessDisplay_OnEntry(HEADLESSDISPLAY_STATE, &disp_var);
// Init the ID, state variables and properties for instance timer
timer_var.active = true;
timer_var.id_timer = add_instance( (void*) &timer_var);
timer_var.TimerArduino_SoftTimer_State = TIMERARDUINO_SOFTTIMER_DEFAULT_STATE;
timer_var.TimerArduino_NB_SOFT_TIMERS_var = NB_SOFT_TIMERS;

TimerArduino_SoftTimer_OnEntry(TIMERARDUINO_SOFTTIMER_STATE, &timer_var);
// Init the ID, state variables and properties for instance log
log_var.active = true;
log_var.id_log = add_instance( (void*) &log_var);
log_var.Logger_State = LOGGER_NULL_STARTUP_STATE;
log_var.Logger_ACTIVATE_ON_STARTUP_var = 1;

Logger_OnEntry(LOGGER_STATE, &log_var);
// Init the ID, state variables and properties for instance game
game_var.active = true;
game_var.id_log = add_instance( (void*) &game_var);
game_var.id_clock = add_instance( (void*) &game_var);
game_var.id_display = add_instance( (void*) &game_var);
game_var.id_controller = add_instance( (void*) &game_var);
game_var.id_ia = add_instance( (void*) &game_var);
game_var.id_game = add_instance( (void*) &game_var);
game_var.id_req_game = add_instance( (void*) &game_var);
game_var.id_pro_game = add_instance( (void*) &game_var);
game_var.BreakoutGame_SC_State = BREAKOUTGAME_SC_INIT_STATE;
game_var.BreakoutGame_period_var = 3;
game_var.BreakoutGame_counter_var = 0;
game_var.BreakoutGame_prevPY_var =  -1;
game_var.BreakoutGame_dy_var =  -160 * 64 / 65;
game_var.BreakoutGame_by_var = 128 * 64;
game_var.BreakoutGame_level_var = 1;
game_var.BreakoutGame_TOP_var = 14 * 64;
game_var.BreakoutGame_padlen_var = 25 * 64;
game_var.BreakoutGame_prevBX_var =  -1;
game_var.BreakoutGame_YDISPSIZE_var = 128;
game_var.BreakoutGame_padx_var = 128 * 64 / 2;
game_var.BreakoutGameArduino_RAM_SIZE_var = 98304;
game_var.BreakoutGame_br_var = 3 * 64;
game_var.BreakoutGame_bx_var = 160 * 64 / 2;
game_var.BreakoutGame_YMAX_var = 128 * 64;
game_var.BreakoutGame_pady_var = 128 * 64 - 6 * 64;
game_var.BreakoutGame_RIGHT_var = 160 * 64 - 1 * 64;
game_var.BreakoutGame_BRICK_HEIGHT_var = 9;
game_var.BreakoutGame_prevPX_var =  -1;
game_var.BreakoutGame_lastTimestamp_var = 0;
game_var.BreakoutGame_dx_var = 160 * 64 / 98;
game_var.BreakoutGame_LEFT_var = 1 * 64;
game_var.BreakoutGame_XMAX_var = 160 * 64;
game_var.BreakoutGame_XDISPSIZE_var = 160;
game_var.BreakoutGame_lives_var = 3;
game_var.BreakoutGame_QUIET_var = 1;
game_var.BreakoutGame_score_var = 0;
game_var.BreakoutGame_BOTTOM_var = 128 * 64 + 8 * 64;
game_var.BreakoutGame_prevBY_var =  -1;
game_var.BreakoutGame_BRICK_ROWS_var = 5;
game_var.BreakoutGame_SCALE_var = 64;
game_var.WithLog_DEBUG_ID_var = "0";
game_var.BreakoutGame_fgcolor_var = array_game_BreakoutGame_fgcolor_var;
game_var.BreakoutGame_fgcolor_var_size = 3;
game_var.BreakoutGame_bgcolor_var = array_game_BreakoutGame_bgcolor_var;
game_var.BreakoutGame_bgcolor_var_size = 3;
game_var.BreakoutGame_bricks_var = array_game_BreakoutGame_bricks_var;
game_var.BreakoutGame_bricks_var_size = 5;

BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_STATE, &game_var);
// Init the ID, state variables and properties for instance ctrl
ctrl_var.active = true;
ctrl_var.id_controls = add_instance( (void*) &ctrl_var);
ctrl_var.id_game = add_instance( (void*) &ctrl_var);
ctrl_var.BasicIAController_SC_State = BASICIACONTROLLER_SC_FOLLOWING_STATE;
ctrl_var.BasicIAController_ctrlx_var = 0;

BasicIAController_SC_OnEntry(BASICIACONTROLLER_SC_STATE, &ctrl_var);
}




void setup() {
Serial.begin(250000);
initialize_configuration_test();

}

void loop() {

// Network Listener// End Network Listener

int emptyEventConsumed = 1;
while (emptyEventConsumed != 0) {
emptyEventConsumed = 0;
emptyEventConsumed += HeadlessDisplay_handle_empty_event(&disp_var);
emptyEventConsumed += ConsoleLogger_handle_empty_event(&log_var);
}
f_TimerArduino_poll_soft_timers(&timer_var);

    processMessageQueue();
}
