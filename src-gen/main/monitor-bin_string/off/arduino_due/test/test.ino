#include <stdint.h>
#include <Arduino.h>
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
void HeadlessDisplay_handle_display_create(struct HeadlessDisplay_Instance *_instance, uint8_t xsize, uint8_t ysize);
void HeadlessDisplay_handle_display_drawRect(struct HeadlessDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void HeadlessDisplay_handle_display_setBGColor(struct HeadlessDisplay_Instance *_instance, uint8_t r, uint8_t g, uint8_t b);
void HeadlessDisplay_handle_display_drawInteger(struct HeadlessDisplay_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale);
void HeadlessDisplay_handle_display_fillRect(struct HeadlessDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void HeadlessDisplay_handle_display_destroy(struct HeadlessDisplay_Instance *_instance);
void HeadlessDisplay_handle_display_update(struct HeadlessDisplay_Instance *_instance);
void HeadlessDisplay_handle_display_setColor(struct HeadlessDisplay_Instance *_instance, uint8_t r, uint8_t g, uint8_t b);
// Declaration of callbacks for incoming messages:
void register_HeadlessDisplay_send_display_displayReady_listener(void (*_listener)(struct HeadlessDisplay_Instance *));
void register_external_HeadlessDisplay_send_display_displayReady_listener(void (*_listener)(struct HeadlessDisplay_Instance *));

// Definition of the states:
#define HEADLESSDISPLAY_NULL_INIT_STATE 0
#define HEADLESSDISPLAY_NULL_MOCK_STATE 1
#define HEADLESSDISPLAY_STATE 2


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
void TimerArduino_handle_timer_timer_start(struct TimerArduino_Instance *_instance, uint8_t id, uint16_t time);
void TimerArduino_handle_timer_timer_cancel(struct TimerArduino_Instance *_instance, uint8_t id);
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
uint32_t BreakoutGame_stopTime_var;
int16_t BreakoutGame_RIGHT_var;
uint8_t * BreakoutGame_bricks_var;
uint16_t BreakoutGame_bricks_var_size;
uint8_t BreakoutGame_lives_var;
uint8_t BreakoutGame_SC_LAUNCH_countdown_var;
int16_t BreakoutGame_score_var;
uint32_t BreakoutGame_startTime_var;
int16_t BreakoutGame_LEFT_var;
uint8_t BreakoutGame_counter_var;
uint32_t BreakoutGameArduino_RAM_SIZE_var;
int16_t BreakoutGame_dx_var;
uint8_t BreakoutGame_level_var;
int16_t BreakoutGame_prevBY_var;
uint32_t BreakoutGame_lastTimestamp_var;
int16_t BreakoutGame_pady_var;
int16_t BreakoutGame_prevPX_var;
int16_t BreakoutGame_BOTTOM_var;
uint8_t * BreakoutGame_bgcolor_var;
uint16_t BreakoutGame_bgcolor_var_size;
int16_t BreakoutGame_SCALE_var;
uint8_t BreakoutGame_BRICK_HEIGHT_var;
int16_t BreakoutGame_by_var;
int16_t BreakoutGame_bx_var;
int16_t BreakoutGame_YMAX_var;
uint8_t BreakoutGame_YDISPSIZE_var;
int16_t BreakoutGame_dy_var;
uint8_t * BreakoutGame_fgcolor_var;
uint16_t BreakoutGame_fgcolor_var_size;
uint8_t BreakoutGame_XDISPSIZE_var;
uint8_t WithBinaryLog_DEBUG_BIN_ID_var;
uint16_t BreakoutGame_period_var;
bool BreakoutGame_QUIET_var;
int16_t BreakoutGame_br_var;
int16_t BreakoutGame_padx_var;
int16_t BreakoutGame_padlen_var;
int16_t BreakoutGame_TOP_var;
int16_t BreakoutGame_prevBX_var;
int16_t BreakoutGame_XMAX_var;
uint8_t BreakoutGame_BRICK_ROWS_var;
int16_t BreakoutGame_prevPY_var;

};
// Declaration of prototypes outgoing messages :
void BreakoutGame_SC_OnEntry(int state, struct BreakoutGameArduino_Instance *_instance);
void BreakoutGameArduino_handle_display_displayReady(struct BreakoutGameArduino_Instance *_instance);
void BreakoutGameArduino_handle_game_lostBall(struct BreakoutGameArduino_Instance *_instance);
void BreakoutGameArduino_handle_game_nextLevel(struct BreakoutGameArduino_Instance *_instance);
void BreakoutGameArduino_handle_clock_timer_timeout(struct BreakoutGameArduino_Instance *_instance, uint8_t id);
void BreakoutGameArduino_handle_controller_position(struct BreakoutGameArduino_Instance *_instance, int16_t x, int16_t y);
void BreakoutGameArduino_handle_pro_game_lostBall(struct BreakoutGameArduino_Instance *_instance);
void BreakoutGameArduino_handle_pro_game_nextLevel(struct BreakoutGameArduino_Instance *_instance);
// Declaration of callbacks for incoming messages:
void register_BreakoutGameArduino_send_log_log_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t*, uint8_t));
void register_external_BreakoutGameArduino_send_log_log_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t*, uint8_t));
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
#define BREAKOUTGAME_SC_INIT_STATE 0
#define BREAKOUTGAME_SC_NEXTLEVEL_STATE 1
#define BREAKOUTGAME_SC_LOSTBALL_STATE 2
#define BREAKOUTGAME_SC_LAUNCH_STATE 3
#define BREAKOUTGAME_SC_STATE 4
#define BREAKOUTGAME_SC_PLAY_STATE 5
#define BREAKOUTGAME_SC_GAMEOVER_STATE 6


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
bool Logger_HAS_SIGNED_BYTE_var;
bool Logger_ACTIVATE_ON_STARTUP_var;

};
// Declaration of prototypes outgoing messages :
void Logger_OnEntry(int state, struct Binary2StringLogger_Instance *_instance);
void Binary2StringLogger_handle_log_log_off(struct Binary2StringLogger_Instance *_instance);
void Binary2StringLogger_handle_log_log_on(struct Binary2StringLogger_Instance *_instance);
void Binary2StringLogger_handle_log_log(struct Binary2StringLogger_Instance *_instance, uint8_t* payload, uint8_t size);
// Declaration of callbacks for incoming messages:

// Definition of the states:
#define LOGGER_NULL_OFF_STATE 0
#define LOGGER_STATE 1
#define LOGGER_NULL_STARTUP_STATE 2
#define LOGGER_NULL_ON_STATE 3


// Definition of Enumeration  LogType
#define LOGTYPE_FUNCTION_CALLED 0
#define LOGTYPE_PROPERTY_CHANGED 1
#define LOGTYPE_MESSAGE_LOST 2
#define LOGTYPE_MESSAGE_SENT 3
#define LOGTYPE_MESSAGE_HANDLED 4

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
void BreakoutGameArduino_send_log_log(struct BreakoutGameArduino_Instance *_instance, uint8_t* payload, uint8_t size);
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
_instance->BreakoutGame_bgcolor_var[0] = 53;
_instance->BreakoutGame_bgcolor_var[1] = 40;
_instance->BreakoutGame_bgcolor_var[2] = 120;
_instance->BreakoutGame_fgcolor_var[0] = 107;
_instance->BreakoutGame_fgcolor_var[1] = 94;
_instance->BreakoutGame_fgcolor_var[2] = 174;
uint8_t r_289 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_290 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_291 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGameArduino_send_display_setBGColor(_instance, r_289, g_290, b_291);
uint8_t setBGColorsent_log_292[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x07, r_289, g_290, b_291};
BreakoutGameArduino_send_log_log(_instance, setBGColorsent_log_292, 7);
uint8_t r_293 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_294 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_295 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_293, g_294, b_295);
uint8_t setColorsent_log_296[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x06, r_293, g_294, b_295};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_296, 7);
uint8_t initColors_log0[3] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01};
BreakoutGameArduino_send_log_log(_instance, initColors_log0, 3);
}
// Definition of function resetBall
void f_BreakoutGameArduino_resetBall(struct BreakoutGameArduino_Instance *_instance) {
int16_t old_bx_7 = _instance->BreakoutGame_bx_var;
_instance->BreakoutGame_bx_var = _instance->BreakoutGame_padx_var - _instance->BreakoutGame_br_var / _instance->BreakoutGame_SCALE_var;
uint8_t bx_log_7[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0B, (((old_bx_7 >> 8) & 0xFF)), (((old_bx_7 >> 0) & 0xFF)), (((_instance->BreakoutGame_bx_var >> 8) & 0xFF)), (((_instance->BreakoutGame_bx_var >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, bx_log_7, 7);
int16_t old_by_29 = _instance->BreakoutGame_by_var;
_instance->BreakoutGame_by_var = _instance->BreakoutGame_pady_var - _instance->BreakoutGame_br_var / _instance->BreakoutGame_SCALE_var;
uint8_t by_log_29[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0C, (((old_by_29 >> 8) & 0xFF)), (((old_by_29 >> 0) & 0xFF)), (((_instance->BreakoutGame_by_var >> 8) & 0xFF)), (((_instance->BreakoutGame_by_var >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, by_log_29, 7);
int16_t old_dx_20 = _instance->BreakoutGame_dx_var;
_instance->BreakoutGame_dx_var = (_instance->BreakoutGame_padx_var + _instance->BreakoutGame_prevBX_var + _instance->BreakoutGame_prevBY_var) % 300 - 150;
uint8_t dx_log_20[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0D, (((old_dx_20 >> 8) & 0xFF)), (((old_dx_20 >> 0) & 0xFF)), (((_instance->BreakoutGame_dx_var >> 8) & 0xFF)), (((_instance->BreakoutGame_dx_var >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, dx_log_20, 7);
if(_instance->BreakoutGame_dy_var > 0) {
int16_t old_dy_13 = _instance->BreakoutGame_dy_var;
_instance->BreakoutGame_dy_var =  -_instance->BreakoutGame_dy_var;
uint8_t dy_log_13[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0E, (((old_dy_13 >> 8) & 0xFF)), (((old_dy_13 >> 0) & 0xFF)), (((_instance->BreakoutGame_dy_var >> 8) & 0xFF)), (((_instance->BreakoutGame_dy_var >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, dy_log_13, 7);

}
int16_t old_prevBX_25 = _instance->BreakoutGame_prevBX_var;
_instance->BreakoutGame_prevBX_var =  -1;
uint8_t prevBX_log_25[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x12, (((old_prevBX_25 >> 8) & 0xFF)), (((old_prevBX_25 >> 0) & 0xFF)), (((_instance->BreakoutGame_prevBX_var >> 8) & 0xFF)), (((_instance->BreakoutGame_prevBX_var >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, prevBX_log_25, 7);
int16_t old_prevBY_1 = _instance->BreakoutGame_prevBY_var;
_instance->BreakoutGame_prevBY_var =  -1;
uint8_t prevBY_log_1[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x13, (((old_prevBY_1 >> 8) & 0xFF)), (((old_prevBY_1 >> 0) & 0xFF)), (((_instance->BreakoutGame_prevBY_var >> 8) & 0xFF)), (((_instance->BreakoutGame_prevBY_var >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, prevBY_log_1, 7);
uint8_t resetBall_log1[3] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02};
BreakoutGameArduino_send_log_log(_instance, resetBall_log1, 3);
}
// Definition of function eraseBall
void f_BreakoutGameArduino_eraseBall(struct BreakoutGameArduino_Instance *_instance) {
int16_t bs = (_instance->BreakoutGame_br_var * 2) / _instance->BreakoutGame_SCALE_var;
if(_instance->BreakoutGame_prevBX_var > 0) {
uint8_t r_297 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_298 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_299 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_297, g_298, b_299);
uint8_t setColorsent_log_300[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x06, r_297, g_298, b_299};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_300, 7);
uint8_t x_301 = _instance->BreakoutGame_prevBX_var;
uint8_t y_302 = _instance->BreakoutGame_prevBY_var;
uint8_t width_303 = bs;
uint8_t height_304 = bs;
BreakoutGameArduino_send_display_fillRect(_instance, x_301, y_302, width_303, height_304);
uint8_t fillRectsent_log_305[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x09, x_301, y_302, width_303, height_304};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_305, 8);

}
int16_t old_prevBX_26 = _instance->BreakoutGame_prevBX_var;
_instance->BreakoutGame_prevBX_var =  -1;
uint8_t prevBX_log_26[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x12, (((old_prevBX_26 >> 8) & 0xFF)), (((old_prevBX_26 >> 0) & 0xFF)), (((_instance->BreakoutGame_prevBX_var >> 8) & 0xFF)), (((_instance->BreakoutGame_prevBX_var >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, prevBX_log_26, 7);
int16_t old_prevBY_2 = _instance->BreakoutGame_prevBY_var;
_instance->BreakoutGame_prevBY_var =  -1;
uint8_t prevBY_log_2[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x13, (((old_prevBY_2 >> 8) & 0xFF)), (((old_prevBY_2 >> 0) & 0xFF)), (((_instance->BreakoutGame_prevBY_var >> 8) & 0xFF)), (((_instance->BreakoutGame_prevBY_var >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, prevBY_log_2, 7);
uint8_t eraseBall_log2[3] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x03};
BreakoutGameArduino_send_log_log(_instance, eraseBall_log2, 3);
}
// Definition of function drawBall
void f_BreakoutGameArduino_drawBall(struct BreakoutGameArduino_Instance *_instance) {
int16_t bs = (_instance->BreakoutGame_br_var * 2) / _instance->BreakoutGame_SCALE_var;
f_BreakoutGameArduino_eraseBall(_instance);
int16_t old_prevBX_27 = _instance->BreakoutGame_prevBX_var;
_instance->BreakoutGame_prevBX_var = (_instance->BreakoutGame_bx_var - _instance->BreakoutGame_br_var) / _instance->BreakoutGame_SCALE_var;
uint8_t prevBX_log_27[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x12, (((old_prevBX_27 >> 8) & 0xFF)), (((old_prevBX_27 >> 0) & 0xFF)), (((_instance->BreakoutGame_prevBX_var >> 8) & 0xFF)), (((_instance->BreakoutGame_prevBX_var >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, prevBX_log_27, 7);
int16_t old_prevBY_3 = _instance->BreakoutGame_prevBY_var;
_instance->BreakoutGame_prevBY_var = (_instance->BreakoutGame_by_var - _instance->BreakoutGame_br_var) / _instance->BreakoutGame_SCALE_var;
uint8_t prevBY_log_3[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x13, (((old_prevBY_3 >> 8) & 0xFF)), (((old_prevBY_3 >> 0) & 0xFF)), (((_instance->BreakoutGame_prevBY_var >> 8) & 0xFF)), (((_instance->BreakoutGame_prevBY_var >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, prevBY_log_3, 7);
uint8_t r_306 = 183;
uint8_t g_307 = 199;
uint8_t b_308 = 111;
BreakoutGameArduino_send_display_setColor(_instance, r_306, g_307, b_308);
uint8_t setColorsent_log_309[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x06, r_306, g_307, b_308};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_309, 7);
uint8_t x_310 = _instance->BreakoutGame_prevBX_var;
uint8_t y_311 = _instance->BreakoutGame_prevBY_var;
uint8_t width_312 = bs;
uint8_t height_313 = bs;
BreakoutGameArduino_send_display_fillRect(_instance, x_310, y_311, width_312, height_313);
uint8_t fillRectsent_log_314[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x09, x_310, y_311, width_312, height_313};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_314, 8);
uint8_t drawBall_log3[3] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x04};
BreakoutGameArduino_send_log_log(_instance, drawBall_log3, 3);
}
// Definition of function erasePad
void f_BreakoutGameArduino_erasePad(struct BreakoutGameArduino_Instance *_instance) {
int16_t ps = _instance->BreakoutGame_padlen_var / _instance->BreakoutGame_SCALE_var;
if(_instance->BreakoutGame_prevPX_var > 0) {
uint8_t r_315 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_316 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_317 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_315, g_316, b_317);
uint8_t setColorsent_log_318[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x06, r_315, g_316, b_317};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_318, 7);
uint8_t x_319 = _instance->BreakoutGame_prevPX_var;
uint8_t y_320 = _instance->BreakoutGame_prevPY_var;
uint8_t width_321 = ps;
uint8_t height_322 = 4;
BreakoutGameArduino_send_display_fillRect(_instance, x_319, y_320, width_321, height_322);
uint8_t fillRectsent_log_323[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x09, x_319, y_320, width_321, height_322};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_323, 8);

}
uint8_t erasePad_log4[3] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x05};
BreakoutGameArduino_send_log_log(_instance, erasePad_log4, 3);
}
// Definition of function drawPad
void f_BreakoutGameArduino_drawPad(struct BreakoutGameArduino_Instance *_instance) {
int16_t ps = _instance->BreakoutGame_padlen_var / _instance->BreakoutGame_SCALE_var;
f_BreakoutGameArduino_erasePad(_instance);
int16_t old_prevPX_19 = _instance->BreakoutGame_prevPX_var;
_instance->BreakoutGame_prevPX_var = (_instance->BreakoutGame_padx_var - (_instance->BreakoutGame_padlen_var / 2)) / _instance->BreakoutGame_SCALE_var;
uint8_t prevPX_log_19[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x17, (((old_prevPX_19 >> 8) & 0xFF)), (((old_prevPX_19 >> 0) & 0xFF)), (((_instance->BreakoutGame_prevPX_var >> 8) & 0xFF)), (((_instance->BreakoutGame_prevPX_var >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, prevPX_log_19, 7);
int16_t old_prevPY_18 = _instance->BreakoutGame_prevPY_var;
_instance->BreakoutGame_prevPY_var = _instance->BreakoutGame_pady_var / _instance->BreakoutGame_SCALE_var;
uint8_t prevPY_log_18[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x18, (((old_prevPY_18 >> 8) & 0xFF)), (((old_prevPY_18 >> 0) & 0xFF)), (((_instance->BreakoutGame_prevPY_var >> 8) & 0xFF)), (((_instance->BreakoutGame_prevPY_var >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, prevPY_log_18, 7);
uint8_t r_324 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_325 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_326 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_324, g_325, b_326);
uint8_t setColorsent_log_327[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x06, r_324, g_325, b_326};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_327, 7);
uint8_t x_328 = _instance->BreakoutGame_prevPX_var;
uint8_t y_329 = _instance->BreakoutGame_prevPY_var;
uint8_t width_330 = ps;
uint8_t height_331 = 4;
BreakoutGameArduino_send_display_fillRect(_instance, x_328, y_329, width_330, height_331);
uint8_t fillRectsent_log_332[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x09, x_328, y_329, width_330, height_331};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_332, 8);
uint8_t drawPad_log5[3] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x06};
BreakoutGameArduino_send_log_log(_instance, drawPad_log5, 3);
}
// Definition of function drawCountDown
void f_BreakoutGameArduino_drawCountDown(struct BreakoutGameArduino_Instance *_instance, int16_t c) {
uint8_t r_333 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_334 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_335 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_333, g_334, b_335);
uint8_t setColorsent_log_336[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x06, r_333, g_334, b_335};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_336, 7);
if(c > 0) {
uint8_t r_337 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_338 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_339 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_337, g_338, b_339);
uint8_t setColorsent_log_340[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x06, r_337, g_338, b_339};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_340, 7);
uint8_t r_341 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_342 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_343 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGameArduino_send_display_setBGColor(_instance, r_341, g_342, b_343);
uint8_t setBGColorsent_log_344[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x07, r_341, g_342, b_343};
BreakoutGameArduino_send_log_log(_instance, setBGColorsent_log_344, 7);
uint8_t x_345 = 80 - 6;
uint8_t y_346 = 90;
int16_t v_347 = c;
uint8_t digits_348 = 1;
uint8_t scale_349 = 4;
BreakoutGameArduino_send_display_drawInteger(_instance, x_345, y_346, v_347, digits_348, scale_349);
uint8_t drawIntegersent_log_350[10] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x0A, x_345, y_346, (((v_347 >> 8) & 0xFF)), (((v_347 >> 0) & 0xFF)), digits_348, scale_349};
BreakoutGameArduino_send_log_log(_instance, drawIntegersent_log_350, 10);

} else {
uint8_t r_351 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_352 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_353 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_351, g_352, b_353);
uint8_t setColorsent_log_354[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x06, r_351, g_352, b_353};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_354, 7);
uint8_t x_355 = 80 - 6;
uint8_t y_356 = 90;
uint8_t width_357 = 12;
uint8_t height_358 = 20;
BreakoutGameArduino_send_display_fillRect(_instance, x_355, y_356, width_357, height_358);
uint8_t fillRectsent_log_359[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x09, x_355, y_356, width_357, height_358};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_359, 8);

}
uint8_t drawCountDown_log6[5] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x07, (((c >> 8) & 0xFF)), (((c >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, drawCountDown_log6, 5);
}
// Definition of function drawWalls
void f_BreakoutGameArduino_drawWalls(struct BreakoutGameArduino_Instance *_instance) {
uint8_t r_360 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_361 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_362 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_360, g_361, b_362);
uint8_t setColorsent_log_363[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x06, r_360, g_361, b_362};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_363, 7);
uint8_t left = (_instance->BreakoutGame_LEFT_var / _instance->BreakoutGame_SCALE_var);
uint8_t right = (_instance->BreakoutGame_RIGHT_var / _instance->BreakoutGame_SCALE_var);
uint8_t top = (_instance->BreakoutGame_TOP_var / _instance->BreakoutGame_SCALE_var);
uint8_t bottom = (_instance->BreakoutGame_BOTTOM_var / _instance->BreakoutGame_SCALE_var);
uint8_t xcenter = ((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / _instance->BreakoutGame_SCALE_var);
uint8_t ycenter = ((_instance->BreakoutGame_BOTTOM_var - _instance->BreakoutGame_TOP_var) / _instance->BreakoutGame_SCALE_var);
uint8_t x_364 = left - 1;
uint8_t y_365 = top - 1;
uint8_t width_366 = xcenter + 1;
uint8_t height_367 = 1;
BreakoutGameArduino_send_display_fillRect(_instance, x_364, y_365, width_366, height_367);
uint8_t fillRectsent_log_368[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x09, x_364, y_365, width_366, height_367};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_368, 8);
uint8_t x_369 = left - 1;
uint8_t y_370 = bottom;
uint8_t width_371 = xcenter + 1;
uint8_t height_372 = 1;
BreakoutGameArduino_send_display_fillRect(_instance, x_369, y_370, width_371, height_372);
uint8_t fillRectsent_log_373[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x09, x_369, y_370, width_371, height_372};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_373, 8);
uint8_t x_374 = left - 1;
uint8_t y_375 = top;
uint8_t width_376 = 1;
uint8_t height_377 = ycenter;
BreakoutGameArduino_send_display_fillRect(_instance, x_374, y_375, width_376, height_377);
uint8_t fillRectsent_log_378[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x09, x_374, y_375, width_376, height_377};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_378, 8);
uint8_t x_379 = right;
uint8_t y_380 = top;
uint8_t width_381 = 1;
uint8_t height_382 = ycenter;
BreakoutGameArduino_send_display_fillRect(_instance, x_379, y_380, width_381, height_382);
uint8_t fillRectsent_log_383[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x09, x_379, y_380, width_381, height_382};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_383, 8);
uint8_t drawWalls_log7[3] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x08};
BreakoutGameArduino_send_log_log(_instance, drawWalls_log7, 3);
}
// Definition of function bitIsSet
bool f_BreakoutGameArduino_bitIsSet(struct BreakoutGameArduino_Instance *_instance, uint8_t variable, uint8_t bit) {
bool return_0 = (((1 << bit) & variable) != 0);
uint8_t bitIsSet_log8[6] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x09, variable, bit, return_0};
BreakoutGameArduino_send_log_log(_instance, bitIsSet_log8, 6);
return return_0;
}
// Definition of function createBricks
void f_BreakoutGameArduino_createBricks(struct BreakoutGameArduino_Instance *_instance) {
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
uint8_t createBricks_log9[3] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0A};
BreakoutGameArduino_send_log_log(_instance, createBricks_log9, 3);
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
uint8_t bricksLeft_log10[4] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0B, return_3};
BreakoutGameArduino_send_log_log(_instance, bricksLeft_log10, 4);
return return_3;
}
// Definition of function drawBrick
void f_BreakoutGameArduino_drawBrick(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y) {
uint8_t bx = ((_instance->BreakoutGame_LEFT_var + ((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 8) * x) / _instance->BreakoutGame_SCALE_var + 1);
uint8_t by = ((_instance->BreakoutGame_TOP_var + 20 * _instance->BreakoutGame_SCALE_var + _instance->BreakoutGame_BRICK_HEIGHT_var * y * _instance->BreakoutGame_SCALE_var) / _instance->BreakoutGame_SCALE_var + 1);
uint8_t w = (((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 8) / _instance->BreakoutGame_SCALE_var - 2);
uint8_t h = (_instance->BreakoutGame_BRICK_HEIGHT_var - 2);
uint8_t r_384 = 155;
uint8_t g_385 = 103;
uint8_t b_386 = 89;
BreakoutGameArduino_send_display_setColor(_instance, r_384, g_385, b_386);
uint8_t setColorsent_log_387[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x06, r_384, g_385, b_386};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_387, 7);
uint8_t x_388 = bx;
uint8_t y_389 = by;
uint8_t width_390 = w;
uint8_t height_391 = h;
BreakoutGameArduino_send_display_fillRect(_instance, x_388, y_389, width_390, height_391);
uint8_t fillRectsent_log_392[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x09, x_388, y_389, width_390, height_391};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_392, 8);
uint8_t r_393 = 100;
uint8_t g_394 = 56;
uint8_t b_395 = 43;
BreakoutGameArduino_send_display_setColor(_instance, r_393, g_394, b_395);
uint8_t setColorsent_log_396[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x06, r_393, g_394, b_395};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_396, 7);
uint8_t x_397 = bx;
uint8_t y_398 = by;
uint8_t width_399 = w;
uint8_t height_400 = h;
BreakoutGameArduino_send_display_drawRect(_instance, x_397, y_398, width_399, height_400);
uint8_t drawRectsent_log_401[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x08, x_397, y_398, width_399, height_400};
BreakoutGameArduino_send_log_log(_instance, drawRectsent_log_401, 8);
uint8_t drawBrick_log11[5] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0C, x, y};
BreakoutGameArduino_send_log_log(_instance, drawBrick_log11, 5);
}
// Definition of function removeBrick
void f_BreakoutGameArduino_removeBrick(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y) {
uint8_t bx = ((_instance->BreakoutGame_LEFT_var + ((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 8) * x) / _instance->BreakoutGame_SCALE_var + 1);
uint8_t by = ((_instance->BreakoutGame_TOP_var + 20 * _instance->BreakoutGame_SCALE_var + _instance->BreakoutGame_BRICK_HEIGHT_var * y * _instance->BreakoutGame_SCALE_var) / _instance->BreakoutGame_SCALE_var + 1);
uint8_t r_402 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_403 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_404 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_402, g_403, b_404);
uint8_t setColorsent_log_405[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x06, r_402, g_403, b_404};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_405, 7);
uint8_t x_406 = bx;
uint8_t y_407 = by;
uint8_t width_408 = (((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 8) / _instance->BreakoutGame_SCALE_var - 2);
uint8_t height_409 = _instance->BreakoutGame_BRICK_HEIGHT_var - 2;
BreakoutGameArduino_send_display_fillRect(_instance, x_406, y_407, width_408, height_409);
uint8_t fillRectsent_log_410[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x09, x_406, y_407, width_408, height_409};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_410, 8);
_instance->BreakoutGame_bricks_var[y] = f_BreakoutGameArduino_unsetBit(_instance, _instance->BreakoutGame_bricks_var[y], x);
uint8_t removeBrick_log12[5] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0D, x, y};
BreakoutGameArduino_send_log_log(_instance, removeBrick_log12, 5);
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
uint8_t collideBrick_log13[8] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0E, (((xpos >> 8) & 0xFF)), (((xpos >> 0) & 0xFF)), (((ypos >> 8) & 0xFF)), (((ypos >> 0) & 0xFF)), return_3};
BreakoutGameArduino_send_log_log(_instance, collideBrick_log13, 8);
return return_3;
}
// Definition of function drawLevel
void f_BreakoutGameArduino_drawLevel(struct BreakoutGameArduino_Instance *_instance) {
uint8_t r_411 = 158;
uint8_t g_412 = 209;
uint8_t b_413 = 130;
BreakoutGameArduino_send_display_setColor(_instance, r_411, g_412, b_413);
uint8_t setColorsent_log_414[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x06, r_411, g_412, b_413};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_414, 7);
uint8_t r_415 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_416 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_417 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setBGColor(_instance, r_415, g_416, b_417);
uint8_t setBGColorsent_log_418[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x07, r_415, g_416, b_417};
BreakoutGameArduino_send_log_log(_instance, setBGColorsent_log_418, 7);
uint8_t r_419 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_420 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_421 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_419, g_420, b_421);
uint8_t setColorsent_log_422[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x06, r_419, g_420, b_421};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_422, 7);
uint8_t x_423 = 6;
uint8_t y_424 = 2;
int16_t v_425 = _instance->BreakoutGame_level_var;
uint8_t digits_426 = 2;
uint8_t scale_427 = 2;
BreakoutGameArduino_send_display_drawInteger(_instance, x_423, y_424, v_425, digits_426, scale_427);
uint8_t drawIntegersent_log_428[10] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x0A, x_423, y_424, (((v_425 >> 8) & 0xFF)), (((v_425 >> 0) & 0xFF)), digits_426, scale_427};
BreakoutGameArduino_send_log_log(_instance, drawIntegersent_log_428, 10);
uint8_t drawLevel_log14[3] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0F};
BreakoutGameArduino_send_log_log(_instance, drawLevel_log14, 3);
}
// Definition of function incrementScore
void f_BreakoutGameArduino_incrementScore(struct BreakoutGameArduino_Instance *_instance, int8_t diff) {
int16_t old_score_11 = _instance->BreakoutGame_score_var;
_instance->BreakoutGame_score_var = _instance->BreakoutGame_score_var + diff;
uint8_t score_log_11[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x1C, (((old_score_11 >> 8) & 0xFF)), (((old_score_11 >> 0) & 0xFF)), (((_instance->BreakoutGame_score_var >> 8) & 0xFF)), (((_instance->BreakoutGame_score_var >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, score_log_11, 7);
if(_instance->BreakoutGame_score_var < 0) {
int16_t old_score_12 = _instance->BreakoutGame_score_var;
_instance->BreakoutGame_score_var = 0;
uint8_t score_log_12[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x1C, (((old_score_12 >> 8) & 0xFF)), (((old_score_12 >> 0) & 0xFF)), (((_instance->BreakoutGame_score_var >> 8) & 0xFF)), (((_instance->BreakoutGame_score_var >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, score_log_12, 7);

}
f_BreakoutGameArduino_drawScore(_instance);
uint8_t incrementScore_log15[4] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x10, diff};
BreakoutGameArduino_send_log_log(_instance, incrementScore_log15, 4);
}
// Definition of function drawScore
void f_BreakoutGameArduino_drawScore(struct BreakoutGameArduino_Instance *_instance) {
uint8_t r_429 = 158;
uint8_t g_430 = 209;
uint8_t b_431 = 130;
BreakoutGameArduino_send_display_setColor(_instance, r_429, g_430, b_431);
uint8_t setColorsent_log_432[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x06, r_429, g_430, b_431};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_432, 7);
uint8_t r_433 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_434 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_435 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setBGColor(_instance, r_433, g_434, b_435);
uint8_t setBGColorsent_log_436[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x07, r_433, g_434, b_435};
BreakoutGameArduino_send_log_log(_instance, setBGColorsent_log_436, 7);
uint8_t x_437 = 58;
uint8_t y_438 = 2;
int16_t v_439 = _instance->BreakoutGame_score_var;
uint8_t digits_440 = 5;
uint8_t scale_441 = 2;
BreakoutGameArduino_send_display_drawInteger(_instance, x_437, y_438, v_439, digits_440, scale_441);
uint8_t drawIntegersent_log_442[10] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x0A, x_437, y_438, (((v_439 >> 8) & 0xFF)), (((v_439 >> 0) & 0xFF)), digits_440, scale_441};
BreakoutGameArduino_send_log_log(_instance, drawIntegersent_log_442, 10);
uint8_t drawScore_log16[3] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x11};
BreakoutGameArduino_send_log_log(_instance, drawScore_log16, 3);
}
// Definition of function drawLives
void f_BreakoutGameArduino_drawLives(struct BreakoutGameArduino_Instance *_instance) {
uint8_t r_443 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_444 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_445 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_443, g_444, b_445);
uint8_t setColorsent_log_446[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x06, r_443, g_444, b_445};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_446, 7);
uint8_t x_447 = 124;
uint8_t y_448 = 4;
uint8_t width_449 = 24 + 6;
uint8_t height_450 = 6;
BreakoutGameArduino_send_display_fillRect(_instance, x_447, y_448, width_449, height_450);
uint8_t fillRectsent_log_451[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x09, x_447, y_448, width_449, height_450};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_451, 8);
uint8_t r_452 = 183;
uint8_t g_453 = 199;
uint8_t b_454 = 111;
BreakoutGameArduino_send_display_setColor(_instance, r_452, g_453, b_454);
uint8_t setColorsent_log_455[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x06, r_452, g_453, b_454};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_455, 7);
uint8_t i = 0;
while(i < _instance->BreakoutGame_lives_var) {
uint8_t x_456 = 124 + (2 - i) * 12;
uint8_t y_457 = 4;
uint8_t width_458 = 6;
uint8_t height_459 = 6;
BreakoutGameArduino_send_display_fillRect(_instance, x_456, y_457, width_458, height_459);
uint8_t fillRectsent_log_460[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x09, x_456, y_457, width_458, height_459};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_460, 8);
i = i + 1;

}
uint8_t drawLives_log17[3] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x12};
BreakoutGameArduino_send_log_log(_instance, drawLives_log17, 3);
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
case BREAKOUTGAME_SC_INIT_STATE:{
_instance->BreakoutGame_startTime_var = f_BreakoutGameArduino_timestamp(_instance);
uint8_t xsize_461 = _instance->BreakoutGame_XDISPSIZE_var;
uint8_t ysize_462 = _instance->BreakoutGame_YDISPSIZE_var;
BreakoutGameArduino_send_display_create(_instance, xsize_461, ysize_462);
uint8_t createsent_log_463[6] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x0C, xsize_461, ysize_462};
BreakoutGameArduino_send_log_log(_instance, createsent_log_463, 6);
break;
}
case BREAKOUTGAME_SC_NEXTLEVEL_STATE:{
uint8_t id_520 = 0;
uint16_t time_521 = _instance->BreakoutGame_period_var;
BreakoutGameArduino_send_clock_timer_start(_instance, id_520, time_521);
uint8_t timer_startsent_log_522[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x00, 0x13, id_520, (((time_521 >> 8) & 0xFF)), (((time_521 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, timer_startsent_log_522, 7);
uint8_t old_level_28 = _instance->BreakoutGame_level_var;
_instance->BreakoutGame_level_var = _instance->BreakoutGame_level_var + 1;
uint8_t level_log_28[5] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x1E, old_level_28, _instance->BreakoutGame_level_var};
BreakoutGameArduino_send_log_log(_instance, level_log_28, 5);
f_BreakoutGameArduino_drawLevel(_instance);
f_BreakoutGameArduino_eraseBall(_instance);
f_BreakoutGameArduino_erasePad(_instance);
if((_instance->BreakoutGame_level_var % 2) == 0 && _instance->BreakoutGame_padlen_var > 5 * _instance->BreakoutGame_SCALE_var) {
int16_t old_padlen_6 = _instance->BreakoutGame_padlen_var;
_instance->BreakoutGame_padlen_var = _instance->BreakoutGame_padlen_var - (4 * _instance->BreakoutGame_SCALE_var);
uint8_t padlen_log_6[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x11, (((old_padlen_6 >> 8) & 0xFF)), (((old_padlen_6 >> 0) & 0xFF)), (((_instance->BreakoutGame_padlen_var >> 8) & 0xFF)), (((_instance->BreakoutGame_padlen_var >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, padlen_log_6, 7);

}
if((_instance->BreakoutGame_level_var % 2) == 1) {
int16_t old_dy_17 = _instance->BreakoutGame_dy_var;
_instance->BreakoutGame_dy_var = (_instance->BreakoutGame_dy_var * 3) / 2;
uint8_t dy_log_17[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0E, (((old_dy_17 >> 8) & 0xFF)), (((old_dy_17 >> 0) & 0xFF)), (((_instance->BreakoutGame_dy_var >> 8) & 0xFF)), (((_instance->BreakoutGame_dy_var >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, dy_log_17, 7);

}
f_BreakoutGameArduino_drawLives(_instance);
f_BreakoutGameArduino_createBricks(_instance);
BreakoutGameArduino_send_display_update(_instance);
uint8_t updatesent_log_523[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x0E};
BreakoutGameArduino_send_log_log(_instance, updatesent_log_523, 4);
break;
}
case BREAKOUTGAME_SC_LOSTBALL_STATE:{
uint8_t id_516 = 0;
uint16_t time_517 = _instance->BreakoutGame_period_var;
BreakoutGameArduino_send_clock_timer_start(_instance, id_516, time_517);
uint8_t timer_startsent_log_518[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x00, 0x13, id_516, (((time_517 >> 8) & 0xFF)), (((time_517 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, timer_startsent_log_518, 7);
uint8_t old_lives_24 = _instance->BreakoutGame_lives_var;
_instance->BreakoutGame_lives_var = _instance->BreakoutGame_lives_var - 1;
uint8_t lives_log_24[5] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x1D, old_lives_24, _instance->BreakoutGame_lives_var};
BreakoutGameArduino_send_log_log(_instance, lives_log_24, 5);
f_BreakoutGameArduino_eraseBall(_instance);
f_BreakoutGameArduino_erasePad(_instance);
f_BreakoutGameArduino_drawLives(_instance);
BreakoutGameArduino_send_display_update(_instance);
uint8_t updatesent_log_519[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x0E};
BreakoutGameArduino_send_log_log(_instance, updatesent_log_519, 4);
f_BreakoutGameArduino_log(_instance, 1);
break;
}
case BREAKOUTGAME_SC_LAUNCH_STATE:{
uint8_t id_483 = 0;
uint16_t time_484 = _instance->BreakoutGame_period_var;
BreakoutGameArduino_send_clock_timer_start(_instance, id_483, time_484);
uint8_t timer_startsent_log_485[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x00, 0x13, id_483, (((time_484 >> 8) & 0xFF)), (((time_484 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, timer_startsent_log_485, 7);
uint8_t old_countdown_4 = _instance->BreakoutGame_SC_LAUNCH_countdown_var;
_instance->BreakoutGame_SC_LAUNCH_countdown_var = 3;
uint8_t countdown_log_4[5] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x1F, old_countdown_4, _instance->BreakoutGame_SC_LAUNCH_countdown_var};
BreakoutGameArduino_send_log_log(_instance, countdown_log_4, 5);
f_BreakoutGameArduino_drawScore(_instance);
f_BreakoutGameArduino_drawLives(_instance);
BreakoutGameArduino_send_display_update(_instance);
uint8_t updatesent_log_486[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x0E};
BreakoutGameArduino_send_log_log(_instance, updatesent_log_486, 4);
break;
}
case BREAKOUTGAME_SC_PLAY_STATE:{
uint8_t id_492 = 0;
uint16_t time_493 = _instance->BreakoutGame_period_var;
BreakoutGameArduino_send_clock_timer_start(_instance, id_492, time_493);
uint8_t timer_startsent_log_494[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x00, 0x13, id_492, (((time_493 >> 8) & 0xFF)), (((time_493 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, timer_startsent_log_494, 7);
break;
}
case BREAKOUTGAME_SC_GAMEOVER_STATE:{
f_BreakoutGameArduino_eraseBall(_instance);
f_BreakoutGameArduino_erasePad(_instance);
uint8_t r_524 = 255;
uint8_t g_525 = 255;
uint8_t b_526 = 255;
BreakoutGameArduino_send_display_setColor(_instance, r_524, g_525, b_526);
uint8_t setColorsent_log_527[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x06, r_524, g_525, b_526};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_527, 7);
uint8_t x_528 = 8;
uint8_t y_529 = 30;
uint8_t width_530 = 142;
uint8_t height_531 = 76;
BreakoutGameArduino_send_display_fillRect(_instance, x_528, y_529, width_530, height_531);
uint8_t fillRectsent_log_532[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x09, x_528, y_529, width_530, height_531};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_532, 8);
uint8_t r_533 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_534 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_535 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_533, g_534, b_535);
uint8_t setColorsent_log_536[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x06, r_533, g_534, b_535};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_536, 7);
uint8_t x_537 = 9;
uint8_t y_538 = 31;
uint8_t width_539 = 140;
uint8_t height_540 = 50;
BreakoutGameArduino_send_display_fillRect(_instance, x_537, y_538, width_539, height_540);
uint8_t fillRectsent_log_541[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x09, x_537, y_538, width_539, height_540};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_541, 8);
uint8_t r_542 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_543 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_544 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setBGColor(_instance, r_542, g_543, b_544);
uint8_t setBGColorsent_log_545[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x07, r_542, g_543, b_544};
BreakoutGameArduino_send_log_log(_instance, setBGColorsent_log_545, 7);
uint8_t r_546 = 158;
uint8_t g_547 = 209;
uint8_t b_548 = 130;
BreakoutGameArduino_send_display_setColor(_instance, r_546, g_547, b_548);
uint8_t setColorsent_log_549[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x06, r_546, g_547, b_548};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_549, 7);
uint8_t x_550 = 23;
uint8_t y_551 = 40;
int16_t v_552 = _instance->BreakoutGame_score_var;
uint8_t digits_553 = 5;
uint8_t scale_554 = 6;
BreakoutGameArduino_send_display_drawInteger(_instance, x_550, y_551, v_552, digits_553, scale_554);
uint8_t drawIntegersent_log_555[10] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x0A, x_550, y_551, (((v_552 >> 8) & 0xFF)), (((v_552 >> 0) & 0xFF)), digits_553, scale_554};
BreakoutGameArduino_send_log_log(_instance, drawIntegersent_log_555, 10);
uint8_t x_556 = 26;
uint8_t y_557 = 87;
BreakoutGameArduino_send_display_drawThingML(_instance, x_556, y_557);
uint8_t drawThingMLsent_log_558[6] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x0B, x_556, y_557};
BreakoutGameArduino_send_log_log(_instance, drawThingMLsent_log_558, 6);
BreakoutGameArduino_send_display_update(_instance);
uint8_t updatesent_log_559[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x0E};
BreakoutGameArduino_send_log_log(_instance, updatesent_log_559, 4);
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
case BREAKOUTGAME_SC_INIT_STATE:{
break;}
case BREAKOUTGAME_SC_NEXTLEVEL_STATE:{
break;}
case BREAKOUTGAME_SC_LOSTBALL_STATE:{
break;}
case BREAKOUTGAME_SC_LAUNCH_STATE:{
break;}
case BREAKOUTGAME_SC_PLAY_STATE:{
break;}
case BREAKOUTGAME_SC_GAMEOVER_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void BreakoutGameArduino_handle_display_displayReady(struct BreakoutGameArduino_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_INIT_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && 1) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_INIT_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_LAUNCH_STATE;
uint8_t displayReadyhandled_log_568[3] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01};
BreakoutGameArduino_send_log_log(_instance, displayReadyhandled_log_568, 3);
BreakoutGameArduino_send_display_clear(_instance);
uint8_t clearsent_log_464[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x05};
BreakoutGameArduino_send_log_log(_instance, clearsent_log_464, 4);
f_BreakoutGameArduino_initColors(_instance);
uint8_t r_465 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_466 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_467 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_465, g_466, b_467);
uint8_t setColorsent_log_468[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x06, r_465, g_466, b_467};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_468, 7);
uint8_t x_469 = 0;
uint8_t y_470 = 0;
uint8_t width_471 = _instance->BreakoutGame_XDISPSIZE_var;
uint8_t height_472 = _instance->BreakoutGame_YDISPSIZE_var;
BreakoutGameArduino_send_display_fillRect(_instance, x_469, y_470, width_471, height_472);
uint8_t fillRectsent_log_473[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x09, x_469, y_470, width_471, height_472};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_473, 8);
uint8_t r_474 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_475 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_476 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_474, g_475, b_476);
uint8_t setColorsent_log_477[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x06, r_474, g_475, b_476};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_477, 7);
uint8_t x_478 = 0;
uint8_t y_479 = 0;
uint8_t width_480 = _instance->BreakoutGame_XDISPSIZE_var;
uint8_t height_481 = 14;
BreakoutGameArduino_send_display_fillRect(_instance, x_478, y_479, width_480, height_481);
uint8_t fillRectsent_log_482[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x09, x_478, y_479, width_480, height_481};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_482, 8);
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
uint8_t displayReadylost_log_573[4] = {LOGTYPE_MESSAGE_LOST, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x0F};
BreakoutGameArduino_send_log_log(_instance, displayReadylost_log_573, 4);
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
uint8_t lostBallhandled_log_566[3] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x05};
BreakoutGameArduino_send_log_log(_instance, lostBallhandled_log_566, 3);
uint8_t id_508 = 0;
BreakoutGameArduino_send_clock_timer_cancel(_instance, id_508);
uint8_t timer_cancelsent_log_509[5] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x00, 0x14, id_508};
BreakoutGameArduino_send_log_log(_instance, timer_cancelsent_log_509, 5);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_LOSTBALL_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
uint8_t lostBalllost_log_574[4] = {LOGTYPE_MESSAGE_LOST, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x04, 0x00};
BreakoutGameArduino_send_log_log(_instance, lostBalllost_log_574, 4);
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
uint8_t nextLevelhandled_log_567[3] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x06};
BreakoutGameArduino_send_log_log(_instance, nextLevelhandled_log_567, 3);
uint8_t id_510 = 0;
BreakoutGameArduino_send_clock_timer_cancel(_instance, id_510);
uint8_t timer_cancelsent_log_511[5] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x00, 0x14, id_510};
BreakoutGameArduino_send_log_log(_instance, timer_cancelsent_log_511, 5);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_NEXTLEVEL_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
uint8_t nextLevellost_log_575[4] = {LOGTYPE_MESSAGE_LOST, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x04, 0x01};
BreakoutGameArduino_send_log_log(_instance, nextLevellost_log_575, 4);
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
uint8_t timer_timeouthandled_log_560[4] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x03, id};
BreakoutGameArduino_send_log_log(_instance, timer_timeouthandled_log_560, 4);
f_BreakoutGameArduino_drawCountDown(_instance, 0);
f_BreakoutGameArduino_resetBall(_instance);
BreakoutGameArduino_send_display_update(_instance);
uint8_t updatesent_log_491[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x0E};
BreakoutGameArduino_send_log_log(_instance, updatesent_log_491, 4);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_PLAY_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
else if (BreakoutGame_SC_State_event_consumed == 0 && id == 0 && _instance->BreakoutGame_SC_LAUNCH_countdown_var > 0) {
uint8_t timer_timeouthandled_log_561[4] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, id};
BreakoutGameArduino_send_log_log(_instance, timer_timeouthandled_log_561, 4);
uint8_t id_487 = 0;
uint16_t time_488 = _instance->BreakoutGame_period_var;
BreakoutGameArduino_send_clock_timer_start(_instance, id_487, time_488);
uint8_t timer_startsent_log_489[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x00, 0x13, id_487, (((time_488 >> 8) & 0xFF)), (((time_488 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, timer_startsent_log_489, 7);
f_BreakoutGameArduino_drawPad(_instance);
if((_instance->BreakoutGame_SC_LAUNCH_countdown_var % 30) == 0) {
f_BreakoutGameArduino_drawCountDown(_instance, _instance->BreakoutGame_SC_LAUNCH_countdown_var / 30);

}
uint8_t old_countdown_5 = _instance->BreakoutGame_SC_LAUNCH_countdown_var;
_instance->BreakoutGame_SC_LAUNCH_countdown_var = _instance->BreakoutGame_SC_LAUNCH_countdown_var - 1;
uint8_t countdown_log_5[5] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x1F, old_countdown_5, _instance->BreakoutGame_SC_LAUNCH_countdown_var};
BreakoutGameArduino_send_log_log(_instance, countdown_log_5, 5);
BreakoutGameArduino_send_display_update(_instance);
uint8_t updatesent_log_490[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x0E};
BreakoutGameArduino_send_log_log(_instance, updatesent_log_490, 4);
BreakoutGame_SC_State_event_consumed = 1;
}
}
else if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_PLAY_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && id == 0) {
uint8_t timer_timeouthandled_log_564[4] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x04, id};
BreakoutGameArduino_send_log_log(_instance, timer_timeouthandled_log_564, 4);
int16_t old_bx_8 = _instance->BreakoutGame_bx_var;
_instance->BreakoutGame_bx_var = _instance->BreakoutGame_bx_var + _instance->BreakoutGame_dx_var;
uint8_t bx_log_8[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0B, (((old_bx_8 >> 8) & 0xFF)), (((old_bx_8 >> 0) & 0xFF)), (((_instance->BreakoutGame_bx_var >> 8) & 0xFF)), (((_instance->BreakoutGame_bx_var >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, bx_log_8, 7);
int16_t old_by_30 = _instance->BreakoutGame_by_var;
_instance->BreakoutGame_by_var = _instance->BreakoutGame_by_var + _instance->BreakoutGame_dy_var;
uint8_t by_log_30[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0C, (((old_by_30 >> 8) & 0xFF)), (((old_by_30 >> 0) & 0xFF)), (((_instance->BreakoutGame_by_var >> 8) & 0xFF)), (((_instance->BreakoutGame_by_var >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, by_log_30, 7);
int16_t wl = _instance->BreakoutGame_LEFT_var + _instance->BreakoutGame_br_var;
int16_t wr = _instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_br_var;
int16_t wt = _instance->BreakoutGame_TOP_var + _instance->BreakoutGame_br_var;
int16_t wb = _instance->BreakoutGame_BOTTOM_var - _instance->BreakoutGame_br_var;
if(_instance->BreakoutGame_bx_var < wl) {
int16_t old_dx_21 = _instance->BreakoutGame_dx_var;
_instance->BreakoutGame_dx_var =  -_instance->BreakoutGame_dx_var;
uint8_t dx_log_21[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0D, (((old_dx_21 >> 8) & 0xFF)), (((old_dx_21 >> 0) & 0xFF)), (((_instance->BreakoutGame_dx_var >> 8) & 0xFF)), (((_instance->BreakoutGame_dx_var >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, dx_log_21, 7);
int16_t old_bx_9 = _instance->BreakoutGame_bx_var;
_instance->BreakoutGame_bx_var = 2 * wl - _instance->BreakoutGame_bx_var;
uint8_t bx_log_9[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0B, (((old_bx_9 >> 8) & 0xFF)), (((old_bx_9 >> 0) & 0xFF)), (((_instance->BreakoutGame_bx_var >> 8) & 0xFF)), (((_instance->BreakoutGame_bx_var >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, bx_log_9, 7);
f_BreakoutGameArduino_incrementScore(_instance,  -1);

} else {
if(_instance->BreakoutGame_bx_var > wr) {
int16_t old_dx_22 = _instance->BreakoutGame_dx_var;
_instance->BreakoutGame_dx_var =  -_instance->BreakoutGame_dx_var;
uint8_t dx_log_22[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0D, (((old_dx_22 >> 8) & 0xFF)), (((old_dx_22 >> 0) & 0xFF)), (((_instance->BreakoutGame_dx_var >> 8) & 0xFF)), (((_instance->BreakoutGame_dx_var >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, dx_log_22, 7);
int16_t old_bx_10 = _instance->BreakoutGame_bx_var;
_instance->BreakoutGame_bx_var = 2 * wr - _instance->BreakoutGame_bx_var;
uint8_t bx_log_10[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0B, (((old_bx_10 >> 8) & 0xFF)), (((old_bx_10 >> 0) & 0xFF)), (((_instance->BreakoutGame_bx_var >> 8) & 0xFF)), (((_instance->BreakoutGame_bx_var >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, bx_log_10, 7);
f_BreakoutGameArduino_incrementScore(_instance,  -1);

}

}
if(_instance->BreakoutGame_by_var < wt) {
int16_t old_dy_14 = _instance->BreakoutGame_dy_var;
_instance->BreakoutGame_dy_var =  -_instance->BreakoutGame_dy_var;
uint8_t dy_log_14[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0E, (((old_dy_14 >> 8) & 0xFF)), (((old_dy_14 >> 0) & 0xFF)), (((_instance->BreakoutGame_dy_var >> 8) & 0xFF)), (((_instance->BreakoutGame_dy_var >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, dy_log_14, 7);
int16_t old_by_31 = _instance->BreakoutGame_by_var;
_instance->BreakoutGame_by_var = 2 * wt - _instance->BreakoutGame_by_var;
uint8_t by_log_31[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0C, (((old_by_31 >> 8) & 0xFF)), (((old_by_31 >> 0) & 0xFF)), (((_instance->BreakoutGame_by_var >> 8) & 0xFF)), (((_instance->BreakoutGame_by_var >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, by_log_31, 7);
f_BreakoutGameArduino_incrementScore(_instance,  -1);

} else {
if(_instance->BreakoutGame_by_var > wb) {
BreakoutGameArduino_send_game_lostBall(_instance);
uint8_t lostBallsent_log_495[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x04, 0x00};
BreakoutGameArduino_send_log_log(_instance, lostBallsent_log_495, 4);
BreakoutGameArduino_send_req_game_lostBall(_instance);
uint8_t lostBallsent_log_496[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x05, 0x00};
BreakoutGameArduino_send_log_log(_instance, lostBallsent_log_496, 4);

}

}
if(_instance->BreakoutGame_dy_var > 0) {
if(_instance->BreakoutGame_by_var > _instance->BreakoutGame_pady_var - _instance->BreakoutGame_br_var && _instance->BreakoutGame_by_var < _instance->BreakoutGame_pady_var + _instance->BreakoutGame_br_var) {
if(_instance->BreakoutGame_bx_var > _instance->BreakoutGame_padx_var - _instance->BreakoutGame_padlen_var / 2 && _instance->BreakoutGame_bx_var < _instance->BreakoutGame_padx_var + _instance->BreakoutGame_padlen_var / 2) {
int16_t old_dy_15 = _instance->BreakoutGame_dy_var;
_instance->BreakoutGame_dy_var =  -_instance->BreakoutGame_dy_var;
uint8_t dy_log_15[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0E, (((old_dy_15 >> 8) & 0xFF)), (((old_dy_15 >> 0) & 0xFF)), (((_instance->BreakoutGame_dy_var >> 8) & 0xFF)), (((_instance->BreakoutGame_dy_var >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, dy_log_15, 7);
int16_t old_by_32 = _instance->BreakoutGame_by_var;
_instance->BreakoutGame_by_var = 2 * (_instance->BreakoutGame_pady_var - _instance->BreakoutGame_br_var) - _instance->BreakoutGame_by_var;
uint8_t by_log_32[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0C, (((old_by_32 >> 8) & 0xFF)), (((old_by_32 >> 0) & 0xFF)), (((_instance->BreakoutGame_by_var >> 8) & 0xFF)), (((_instance->BreakoutGame_by_var >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, by_log_32, 7);
int16_t old_dx_23 = _instance->BreakoutGame_dx_var;
_instance->BreakoutGame_dx_var = _instance->BreakoutGame_dx_var / 4 + (_instance->BreakoutGame_bx_var - _instance->BreakoutGame_padx_var) / 4;
uint8_t dx_log_23[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0D, (((old_dx_23 >> 8) & 0xFF)), (((old_dx_23 >> 0) & 0xFF)), (((_instance->BreakoutGame_dx_var >> 8) & 0xFF)), (((_instance->BreakoutGame_dx_var >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, dx_log_23, 7);

}

}

}
bool collision = f_BreakoutGameArduino_collideBrick(_instance, _instance->BreakoutGame_bx_var - _instance->BreakoutGame_br_var, _instance->BreakoutGame_by_var - _instance->BreakoutGame_br_var) || f_BreakoutGameArduino_collideBrick(_instance, _instance->BreakoutGame_bx_var + _instance->BreakoutGame_br_var, _instance->BreakoutGame_by_var - _instance->BreakoutGame_br_var) || f_BreakoutGameArduino_collideBrick(_instance, _instance->BreakoutGame_bx_var + _instance->BreakoutGame_br_var, _instance->BreakoutGame_by_var + _instance->BreakoutGame_br_var) || f_BreakoutGameArduino_collideBrick(_instance, _instance->BreakoutGame_bx_var - _instance->BreakoutGame_br_var, _instance->BreakoutGame_by_var + _instance->BreakoutGame_br_var);
if(collision) {
int16_t old_dy_16 = _instance->BreakoutGame_dy_var;
_instance->BreakoutGame_dy_var =  -_instance->BreakoutGame_dy_var;
uint8_t dy_log_16[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0E, (((old_dy_16 >> 8) & 0xFF)), (((old_dy_16 >> 0) & 0xFF)), (((_instance->BreakoutGame_dy_var >> 8) & 0xFF)), (((_instance->BreakoutGame_dy_var >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, dy_log_16, 7);
f_BreakoutGameArduino_incrementScore(_instance, 10);
if(f_BreakoutGameArduino_bricksLeft(_instance) == 0) {
BreakoutGameArduino_send_game_nextLevel(_instance);
uint8_t nextLevelsent_log_497[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x04, 0x01};
BreakoutGameArduino_send_log_log(_instance, nextLevelsent_log_497, 4);
BreakoutGameArduino_send_req_game_nextLevel(_instance);
uint8_t nextLevelsent_log_498[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x05, 0x01};
BreakoutGameArduino_send_log_log(_instance, nextLevelsent_log_498, 4);

}

}
f_BreakoutGameArduino_drawBall(_instance);
f_BreakoutGameArduino_drawPad(_instance);
int16_t ballx_499 = _instance->BreakoutGame_bx_var;
int16_t bally_500 = _instance->BreakoutGame_by_var;
int16_t padx_501 = _instance->BreakoutGame_padx_var;
int16_t pady_502 = _instance->BreakoutGame_pady_var;
BreakoutGameArduino_send_ia_updateIA(_instance, ballx_499, bally_500, padx_501, pady_502);
uint8_t updateIAsent_log_503[12] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x03, 0x12, (((ballx_499 >> 8) & 0xFF)), (((ballx_499 >> 0) & 0xFF)), (((bally_500 >> 8) & 0xFF)), (((bally_500 >> 0) & 0xFF)), (((padx_501 >> 8) & 0xFF)), (((padx_501 >> 0) & 0xFF)), (((pady_502 >> 8) & 0xFF)), (((pady_502 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, updateIAsent_log_503, 12);
BreakoutGameArduino_send_display_update(_instance);
uint8_t updatesent_log_504[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x0E};
BreakoutGameArduino_send_log_log(_instance, updatesent_log_504, 4);
f_BreakoutGameArduino_log(_instance, 0);
uint8_t id_505 = 0;
uint16_t time_506 = _instance->BreakoutGame_period_var;
BreakoutGameArduino_send_clock_timer_start(_instance, id_505, time_506);
uint8_t timer_startsent_log_507[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x00, 0x13, id_505, (((time_506 >> 8) & 0xFF)), (((time_506 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, timer_startsent_log_507, 7);
BreakoutGame_SC_State_event_consumed = 1;
}
}
else if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_LOSTBALL_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && id == 0 && _instance->BreakoutGame_lives_var > 0) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_LOSTBALL_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_LAUNCH_STATE;
uint8_t timer_timeouthandled_log_562[4] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x09, id};
BreakoutGameArduino_send_log_log(_instance, timer_timeouthandled_log_562, 4);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_LAUNCH_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
else if (BreakoutGame_SC_State_event_consumed == 0 && id == 0 && _instance->BreakoutGame_lives_var == 0) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_LOSTBALL_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_GAMEOVER_STATE;
uint8_t timer_timeouthandled_log_563[4] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0A, id};
BreakoutGameArduino_send_log_log(_instance, timer_timeouthandled_log_563, 4);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_GAMEOVER_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
else if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_NEXTLEVEL_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && id == 0) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_NEXTLEVEL_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_LAUNCH_STATE;
uint8_t timer_timeouthandled_log_565[4] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0B, id};
BreakoutGameArduino_send_log_log(_instance, timer_timeouthandled_log_565, 4);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_LAUNCH_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
uint8_t timer_timeoutlost_log_572[5] = {LOGTYPE_MESSAGE_LOST, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x00, 0x15, id};
BreakoutGameArduino_send_log_log(_instance, timer_timeoutlost_log_572, 5);
BreakoutGame_SC_State_event_consumed = 1;
}
}
void BreakoutGameArduino_handle_controller_position(struct BreakoutGameArduino_Instance *_instance, int16_t x, int16_t y) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
uint8_t positionhandled_log_569[7] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x00, (((x >> 8) & 0xFF)), (((x >> 0) & 0xFF)), (((y >> 8) & 0xFF)), (((y >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, positionhandled_log_569, 7);
int32_t center = (_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var - _instance->BreakoutGame_padlen_var);
center = x * center;
center = center / 200;
int16_t old_padx_0 = _instance->BreakoutGame_padx_var;
_instance->BreakoutGame_padx_var = (_instance->BreakoutGame_LEFT_var + center + (_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 2);
uint8_t padx_log_0[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0F, (((old_padx_0 >> 8) & 0xFF)), (((old_padx_0 >> 0) & 0xFF)), (((_instance->BreakoutGame_padx_var >> 8) & 0xFF)), (((_instance->BreakoutGame_padx_var >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, padx_log_0, 7);
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
uint8_t lostBallhandled_log_570[3] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x07};
BreakoutGameArduino_send_log_log(_instance, lostBallhandled_log_570, 3);
uint8_t id_512 = 0;
BreakoutGameArduino_send_clock_timer_cancel(_instance, id_512);
uint8_t timer_cancelsent_log_513[5] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x00, 0x14, id_512};
BreakoutGameArduino_send_log_log(_instance, timer_cancelsent_log_513, 5);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_LOSTBALL_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
uint8_t lostBalllost_log_576[4] = {LOGTYPE_MESSAGE_LOST, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x06, 0x00};
BreakoutGameArduino_send_log_log(_instance, lostBalllost_log_576, 4);
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
uint8_t nextLevelhandled_log_571[3] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x08};
BreakoutGameArduino_send_log_log(_instance, nextLevelhandled_log_571, 3);
uint8_t id_514 = 0;
BreakoutGameArduino_send_clock_timer_cancel(_instance, id_514);
uint8_t timer_cancelsent_log_515[5] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x00, 0x14, id_514};
BreakoutGameArduino_send_log_log(_instance, timer_cancelsent_log_515, 5);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_NEXTLEVEL_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
uint8_t nextLevellost_log_577[4] = {LOGTYPE_MESSAGE_LOST, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x06, 0x01};
BreakoutGameArduino_send_log_log(_instance, nextLevellost_log_577, 4);
BreakoutGame_SC_State_event_consumed = 1;
}
}

// Observers for outgoing messages:
void (*external_BreakoutGameArduino_send_log_log_listener)(struct BreakoutGameArduino_Instance *, uint8_t*, uint8_t)= 0x0;
void (*BreakoutGameArduino_send_log_log_listener)(struct BreakoutGameArduino_Instance *, uint8_t*, uint8_t)= 0x0;
void register_external_BreakoutGameArduino_send_log_log_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t*, uint8_t)){
external_BreakoutGameArduino_send_log_log_listener = _listener;
}
void register_BreakoutGameArduino_send_log_log_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t*, uint8_t)){
BreakoutGameArduino_send_log_log_listener = _listener;
}
void BreakoutGameArduino_send_log_log(struct BreakoutGameArduino_Instance *_instance, uint8_t* payload, uint8_t size){
if (BreakoutGameArduino_send_log_log_listener != 0x0) BreakoutGameArduino_send_log_log_listener(_instance, payload, size);
if (external_BreakoutGameArduino_send_log_log_listener != 0x0) external_BreakoutGameArduino_send_log_log_listener(_instance, payload, size);
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
 * Implementation for type : Binary2StringLogger
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void Logger_OnExit(int state, struct Binary2StringLogger_Instance *_instance);
//Prototypes: Message Sending
//Prototypes: Function
uint8_t f_Binary2StringLogger_get_byte(struct Binary2StringLogger_Instance *_instance, uint8_t b);
void f_Binary2StringLogger_do_log(struct Binary2StringLogger_Instance *_instance, uint8_t* payload, uint8_t size);
// Declaration of functions:
// Definition of function get_byte
uint8_t f_Binary2StringLogger_get_byte(struct Binary2StringLogger_Instance *_instance, uint8_t b) {
if(_instance->Logger_HAS_SIGNED_BYTE_var) {
return (b & 0xFF);

} else {
return b;

}
}
// Definition of function do_log
void f_Binary2StringLogger_do_log(struct Binary2StringLogger_Instance *_instance, uint8_t* payload, uint8_t size) {
uint8_t log_type = f_Binary2StringLogger_get_byte(_instance, payload[0]);
uint8_t inst = f_Binary2StringLogger_get_byte(_instance, payload[1]);
if(log_type == LOGTYPE_FUNCTION_CALLED) {
uint8_t func_ = f_Binary2StringLogger_get_byte(_instance, payload[2]);
if(inst == 0) {
if(func_ == 1) {
Serial.print("function_called(BreakoutGame0, initColors, void");
Serial.print(", _");
Serial.print(")");
Serial.print("\n");

} else {
if(func_ == 2) {
Serial.print("function_called(BreakoutGame0, resetBall, void");
Serial.print(", _");
Serial.print(")");
Serial.print("\n");

} else {
if(func_ == 3) {
Serial.print("function_called(BreakoutGame0, eraseBall, void");
Serial.print(", _");
Serial.print(")");
Serial.print("\n");

} else {
if(func_ == 4) {
Serial.print("function_called(BreakoutGame0, drawBall, void");
Serial.print(", _");
Serial.print(")");
Serial.print("\n");

} else {
if(func_ == 5) {
Serial.print("function_called(BreakoutGame0, erasePad, void");
Serial.print(", _");
Serial.print(")");
Serial.print("\n");

} else {
if(func_ == 6) {
Serial.print("function_called(BreakoutGame0, drawPad, void");
Serial.print(", _");
Serial.print(")");
Serial.print("\n");

} else {
if(func_ == 7) {
Serial.print("function_called(BreakoutGame0, drawCountDown, void");
Serial.print(", _");
Serial.print(", c=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[2]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(func_ == 8) {
Serial.print("function_called(BreakoutGame0, drawWalls, void");
Serial.print(", _");
Serial.print(")");
Serial.print("\n");

} else {
if(func_ == 9) {
Serial.print("function_called(BreakoutGame0, bitIsSet, Boolean");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0) != 0));
Serial.print(", variable=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[2]) << 0)));
Serial.print(", bit=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(func_ == 10) {
Serial.print("function_called(BreakoutGame0, createBricks, void");
Serial.print(", _");
Serial.print(")");
Serial.print("\n");

} else {
if(func_ == 11) {
Serial.print("function_called(BreakoutGame0, bricksLeft, UInt8");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[2]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(func_ == 12) {
Serial.print("function_called(BreakoutGame0, drawBrick, void");
Serial.print(", _");
Serial.print(", x=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[2]) << 0)));
Serial.print(", y=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(func_ == 13) {
Serial.print("function_called(BreakoutGame0, removeBrick, void");
Serial.print(", _");
Serial.print(", x=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[2]) << 0)));
Serial.print(", y=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(func_ == 14) {
Serial.print("function_called(BreakoutGame0, collideBrick, Boolean");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0) != 0));
Serial.print(", xpos=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[2]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
Serial.print(", ypos=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[5]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(func_ == 15) {
Serial.print("function_called(BreakoutGame0, drawLevel, void");
Serial.print(", _");
Serial.print(")");
Serial.print("\n");

} else {
if(func_ == 16) {
Serial.print("function_called(BreakoutGame0, incrementScore, void");
Serial.print(", _");
Serial.print(", diff=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[2]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(func_ == 17) {
Serial.print("function_called(BreakoutGame0, drawScore, void");
Serial.print(", _");
Serial.print(")");
Serial.print("\n");

} else {
if(func_ == 18) {
Serial.print("function_called(BreakoutGame0, drawLives, void");
Serial.print(", _");
Serial.print(")");
Serial.print("\n");

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

} else {
if(log_type == LOGTYPE_PROPERTY_CHANGED) {
uint8_t prop = f_Binary2StringLogger_get_byte(_instance, payload[2]);
if(inst == 0) {
if(prop == 1) {
Serial.print("property_changed(BreakoutGame0, XDISPSIZE, UInt8");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(prop == 2) {
Serial.print("property_changed(BreakoutGame0, YDISPSIZE, UInt8");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(prop == 3) {
Serial.print("property_changed(BreakoutGame0, SCALE, Int16");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(prop == 4) {
Serial.print("property_changed(BreakoutGame0, XMAX, Int16");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(prop == 5) {
Serial.print("property_changed(BreakoutGame0, YMAX, Int16");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(prop == 6) {
Serial.print("property_changed(BreakoutGame0, TOP, Int16");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(prop == 7) {
Serial.print("property_changed(BreakoutGame0, BOTTOM, Int16");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(prop == 8) {
Serial.print("property_changed(BreakoutGame0, LEFT, Int16");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(prop == 9) {
Serial.print("property_changed(BreakoutGame0, RIGHT, Int16");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(prop == 10) {
Serial.print("property_changed(BreakoutGame0, br, Int16");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(prop == 11) {
Serial.print("property_changed(BreakoutGame0, bx, Int16");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(prop == 12) {
Serial.print("property_changed(BreakoutGame0, by, Int16");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(prop == 13) {
Serial.print("property_changed(BreakoutGame0, dx, Int16");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(prop == 14) {
Serial.print("property_changed(BreakoutGame0, dy, Int16");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(prop == 15) {
Serial.print("property_changed(BreakoutGame0, padx, Int16");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(prop == 16) {
Serial.print("property_changed(BreakoutGame0, pady, Int16");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(prop == 17) {
Serial.print("property_changed(BreakoutGame0, padlen, Int16");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(prop == 18) {
Serial.print("property_changed(BreakoutGame0, prevBX, Int16");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(prop == 19) {
Serial.print("property_changed(BreakoutGame0, prevBY, Int16");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(prop == 20) {
Serial.print("property_changed(BreakoutGame0, bgcolor, UInt8");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(prop == 21) {
Serial.print("property_changed(BreakoutGame0, fgcolor, UInt8");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(prop == 22) {
Serial.print("property_changed(BreakoutGame0, period, UInt16");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(prop == 23) {
Serial.print("property_changed(BreakoutGame0, prevPX, Int16");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(prop == 24) {
Serial.print("property_changed(BreakoutGame0, prevPY, Int16");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(prop == 25) {
Serial.print("property_changed(BreakoutGame0, BRICK_ROWS, UInt8");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(prop == 26) {
Serial.print("property_changed(BreakoutGame0, BRICK_HEIGHT, UInt8");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(prop == 27) {
Serial.print("property_changed(BreakoutGame0, bricks, UInt8");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(prop == 28) {
Serial.print("property_changed(BreakoutGame0, score, Int16");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(prop == 29) {
Serial.print("property_changed(BreakoutGame0, lives, UInt8");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(prop == 30) {
Serial.print("property_changed(BreakoutGame0, level, UInt8");
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
Serial.print(", ");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(")");
Serial.print("\n");

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

} else {
if(log_type == LOGTYPE_MESSAGE_LOST) {
uint8_t portID = f_Binary2StringLogger_get_byte(_instance, payload[2]);
uint8_t messageID = f_Binary2StringLogger_get_byte(_instance, payload[3]);
if(inst == 0) {
if(portID == 0 && messageID == 21) {
Serial.print("message_lost(BreakoutGame0, clock, timer_timeout");
Serial.print(", id=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(portID == 1 && messageID == 15) {
Serial.print("message_lost(BreakoutGame0, display, displayReady");
Serial.print(")");
Serial.print("\n");

} else {
if(portID == 2 && messageID == 17) {
Serial.print("message_lost(BreakoutGame0, controller, position");
Serial.print(", x=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[5]) << 0)));
Serial.print(", y=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[6]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[7]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(portID == 4 && messageID == 0) {
Serial.print("message_lost(BreakoutGame0, game, lostBall");
Serial.print(")");
Serial.print("\n");

} else {
if(portID == 6 && messageID == 0) {
Serial.print("message_lost(BreakoutGame0, pro_game, lostBall");
Serial.print(")");
Serial.print("\n");

} else {
if(portID == 4 && messageID == 1) {
Serial.print("message_lost(BreakoutGame0, game, nextLevel");
Serial.print(")");
Serial.print("\n");

} else {
if(portID == 6 && messageID == 1) {
Serial.print("message_lost(BreakoutGame0, pro_game, nextLevel");
Serial.print(")");
Serial.print("\n");

}

}

}

}

}

}

}

}

} else {
if(log_type == LOGTYPE_MESSAGE_SENT) {
uint8_t portID = f_Binary2StringLogger_get_byte(_instance, payload[2]);
uint8_t messageID = f_Binary2StringLogger_get_byte(_instance, payload[3]);
if(inst == 0) {
if(portID == 0 && messageID == 19) {
Serial.print("message_sent(BreakoutGame0, clock, timer_start");
Serial.print(", id=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", time=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(portID == 0 && messageID == 20) {
Serial.print("message_sent(BreakoutGame0, clock, timer_cancel");
Serial.print(", id=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(portID == 1 && messageID == 5) {
Serial.print("message_sent(BreakoutGame0, display, clear");
Serial.print(")");
Serial.print("\n");

} else {
if(portID == 1 && messageID == 6) {
Serial.print("message_sent(BreakoutGame0, display, setColor");
Serial.print(", r=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", g=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 0)));
Serial.print(", b=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(portID == 1 && messageID == 7) {
Serial.print("message_sent(BreakoutGame0, display, setBGColor");
Serial.print(", r=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", g=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 0)));
Serial.print(", b=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(portID == 1 && messageID == 8) {
Serial.print("message_sent(BreakoutGame0, display, drawRect");
Serial.print(", x=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", y=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 0)));
Serial.print(", width=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
Serial.print(", height=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[7]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(portID == 1 && messageID == 9) {
Serial.print("message_sent(BreakoutGame0, display, fillRect");
Serial.print(", x=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", y=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 0)));
Serial.print(", width=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
Serial.print(", height=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[7]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(portID == 1 && messageID == 10) {
Serial.print("message_sent(BreakoutGame0, display, drawInteger");
Serial.print(", x=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", y=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 0)));
Serial.print(", v=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[6]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[7]) << 0)));
Serial.print(", digits=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[8]) << 0)));
Serial.print(", scale=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[9]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(portID == 1 && messageID == 11) {
Serial.print("message_sent(BreakoutGame0, display, drawThingML");
Serial.print(", x=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", y=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(portID == 1 && messageID == 12) {
Serial.print("message_sent(BreakoutGame0, display, create");
Serial.print(", xsize=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", ysize=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(portID == 1 && messageID == 14) {
Serial.print("message_sent(BreakoutGame0, display, update");
Serial.print(")");
Serial.print("\n");

} else {
if(portID == 3 && messageID == 18) {
Serial.print("message_sent(BreakoutGame0, ia, updateIA");
Serial.print(", ballx=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[5]) << 0)));
Serial.print(", bally=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[6]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[7]) << 0)));
Serial.print(", padx=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[8]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[9]) << 0)));
Serial.print(", pady=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[10]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[11]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(portID == 4 && messageID == 0) {
Serial.print("message_sent(BreakoutGame0, game, lostBall");
Serial.print(")");
Serial.print("\n");

} else {
if(portID == 5 && messageID == 0) {
Serial.print("message_sent(BreakoutGame0, req_game, lostBall");
Serial.print(")");
Serial.print("\n");

} else {
if(portID == 4 && messageID == 1) {
Serial.print("message_sent(BreakoutGame0, game, nextLevel");
Serial.print(")");
Serial.print("\n");

} else {
if(portID == 5 && messageID == 1) {
Serial.print("message_sent(BreakoutGame0, req_game, nextLevel");
Serial.print(")");
Serial.print("\n");

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

}

} else {
if(log_type == LOGTYPE_MESSAGE_HANDLED) {
uint8_t handlerID = f_Binary2StringLogger_get_byte(_instance, payload[2]);
if(inst == 0) {
if(handlerID == 0) {
Serial.print("message_handled(BreakoutGame0, controller, position, SC, _, ");
Serial.print(", x=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
Serial.print(", y=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(handlerID == 1) {
Serial.print("message_handled(BreakoutGame0, display, displayReady, INIT, LAUNCH, ");
Serial.print(")");
Serial.print("\n");

} else {
if(handlerID == 2) {
Serial.print("message_handled(BreakoutGame0, clock, timer_timeout, LAUNCH, _, ");
Serial.print(", id=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(handlerID == 3) {
Serial.print("message_handled(BreakoutGame0, clock, timer_timeout, LAUNCH, PLAY, ");
Serial.print(", id=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(handlerID == 4) {
Serial.print("message_handled(BreakoutGame0, clock, timer_timeout, PLAY, _, ");
Serial.print(", id=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(handlerID == 5) {
Serial.print("message_handled(BreakoutGame0, game, lostBall, PLAY, LOSTBALL, ");
Serial.print(")");
Serial.print("\n");

} else {
if(handlerID == 6) {
Serial.print("message_handled(BreakoutGame0, game, nextLevel, PLAY, NEXTLEVEL, ");
Serial.print(")");
Serial.print("\n");

} else {
if(handlerID == 7) {
Serial.print("message_handled(BreakoutGame0, pro_game, lostBall, PLAY, LOSTBALL, ");
Serial.print(")");
Serial.print("\n");

} else {
if(handlerID == 8) {
Serial.print("message_handled(BreakoutGame0, pro_game, nextLevel, PLAY, NEXTLEVEL, ");
Serial.print(")");
Serial.print("\n");

} else {
if(handlerID == 9) {
Serial.print("message_handled(BreakoutGame0, clock, timer_timeout, LOSTBALL, LAUNCH, ");
Serial.print(", id=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(handlerID == 10) {
Serial.print("message_handled(BreakoutGame0, clock, timer_timeout, LOSTBALL, GAMEOVER, ");
Serial.print(", id=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
Serial.print(")");
Serial.print("\n");

} else {
if(handlerID == 11) {
Serial.print("message_handled(BreakoutGame0, clock, timer_timeout, NEXTLEVEL, LAUNCH, ");
Serial.print(", id=");
Serial.print(((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
Serial.print(")");
Serial.print("\n");

}

}

}

}

}

}

}

}

}

}

}

}

}

} else {
Serial.print("unknown");
Serial.print("\n");

}

}

}

}

}
}

// Sessions functionss:


// On Entry Actions:
void Logger_OnEntry(int state, struct Binary2StringLogger_Instance *_instance) {
switch(state) {
case LOGGER_STATE:{
_instance->Logger_State = LOGGER_NULL_STARTUP_STATE;
Logger_OnEntry(_instance->Logger_State, _instance);
break;
}
case LOGGER_NULL_OFF_STATE:{
break;
}
case LOGGER_NULL_STARTUP_STATE:{
break;
}
case LOGGER_NULL_ON_STATE:{
break;
}
default: break;
}
}

// On Exit Actions:
void Logger_OnExit(int state, struct Binary2StringLogger_Instance *_instance) {
switch(state) {
case LOGGER_STATE:{
Logger_OnExit(_instance->Logger_State, _instance);
break;}
case LOGGER_NULL_OFF_STATE:{
break;}
case LOGGER_NULL_STARTUP_STATE:{
break;}
case LOGGER_NULL_ON_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void Binary2StringLogger_handle_log_log_off(struct Binary2StringLogger_Instance *_instance) {
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
void Binary2StringLogger_handle_log_log_on(struct Binary2StringLogger_Instance *_instance) {
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
void Binary2StringLogger_handle_log_log(struct Binary2StringLogger_Instance *_instance, uint8_t* payload, uint8_t size) {
if(!(_instance->active)) return;
//Region null
uint8_t Logger_State_event_consumed = 0;
if (_instance->Logger_State == LOGGER_NULL_ON_STATE) {
if (Logger_State_event_consumed == 0 && 1) {
f_Binary2StringLogger_do_log(_instance, payload, size);
Logger_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
int Binary2StringLogger_handle_empty_event(struct Binary2StringLogger_Instance *_instance) {
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
case HEADLESSDISPLAY_NULL_INIT_STATE:{
HeadlessDisplay_send_display_displayReady(_instance);
break;
}
case HEADLESSDISPLAY_NULL_MOCK_STATE:{
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
case HEADLESSDISPLAY_NULL_INIT_STATE:{
break;}
case HEADLESSDISPLAY_NULL_MOCK_STATE:{
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
 * Definitions for configuration : test
 *****************************************************************************/

uint8_t array_game_BreakoutGame_bricks_var[5];
uint8_t array_game_BreakoutGame_bgcolor_var[3];
uint8_t array_game_BreakoutGame_fgcolor_var[3];
//Declaration of instance variables
//Instance disp
// Variables for the properties of the instance
struct HeadlessDisplay_Instance disp_var;
// Variables for the sessions of the instance
//Instance ctrl
// Variables for the properties of the instance
struct BasicIAController_Instance ctrl_var;
// Variables for the sessions of the instance
//Instance timer
// Variables for the properties of the instance
struct TimerArduino_Instance timer_var;
// Variables for the sessions of the instance
//Instance game
// Variables for the properties of the instance
struct BreakoutGameArduino_Instance game_var;
// Variables for the sessions of the instance
//Instance log
// Variables for the properties of the instance
struct Binary2StringLogger_Instance log_var;
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
// Enqueue of messages BasicIAController::controls::position
void enqueue_BasicIAController_send_controls_position(struct BasicIAController_Instance *_instance, int16_t x, int16_t y){
if ( fifo_byte_available() > 8 ) {

_fifo_enqueue( (2 >> 8) & 0xFF );
_fifo_enqueue( 2 & 0xFF );

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
// Enqueue of messages TimerArduino::timer::timer_timeout
void enqueue_TimerArduino_send_timer_timer_timeout(struct TimerArduino_Instance *_instance, uint8_t id){
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (3 >> 8) & 0xFF );
_fifo_enqueue( 3 & 0xFF );

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
// Enqueue of messages BreakoutGameArduino::clock::timer_start
void enqueue_BreakoutGameArduino_send_clock_timer_start(struct BreakoutGameArduino_Instance *_instance, uint8_t id, uint16_t time){
if ( fifo_byte_available() > 7 ) {

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
// Enqueue of messages BreakoutGameArduino::clock::timer_cancel
void enqueue_BreakoutGameArduino_send_clock_timer_cancel(struct BreakoutGameArduino_Instance *_instance, uint8_t id){
if ( fifo_byte_available() > 5 ) {

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
void dispatch_timer_cancel(uint16_t sender, uint8_t param_id) {
if (sender == game_var.id_clock) {
TimerArduino_handle_timer_timer_cancel(&timer_var, param_id);

}
if (sender == game_var.id_game) {

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
void dispatch_nextLevel(uint16_t sender) {
if (sender == game_var.id_req_game) {
BreakoutGameArduino_handle_pro_game_nextLevel(&game_var);

}
if (sender == game_var.id_game) {
BreakoutGameArduino_handle_game_nextLevel(&game_var);

}

}


//New dispatcher for messages
void dispatch_log(uint16_t sender, uint8_t* param_payload, uint8_t param_size) {
if (sender == game_var.id_log) {
Binary2StringLogger_handle_log_log(&log_var, param_payload, param_size);

}
if (sender == game_var.id_game) {

}

}

void sync_dispatch_BreakoutGameArduino_send_log_log(struct BreakoutGameArduino_Instance *_instance, uint8_t* payload, uint8_t size){
dispatch_log(_instance->id_log, payload, size);
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
void dispatch_destroy(uint16_t sender) {
if (sender == game_var.id_game) {

}

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
void dispatch_velocity(uint16_t sender, int16_t param_dx, int16_t param_dy) {
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

//New dispatcher for messages
void dispatch_position(uint16_t sender, int16_t param_x, int16_t param_y) {
if (sender == ctrl_var.id_controls) {
BreakoutGameArduino_handle_controller_position(&game_var, param_x, param_y);

}
if (sender == game_var.id_game) {

}

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
void dispatch_lostBall(uint16_t sender) {
if (sender == game_var.id_req_game) {
BreakoutGameArduino_handle_pro_game_lostBall(&game_var);

}
if (sender == game_var.id_game) {
BreakoutGameArduino_handle_game_lostBall(&game_var);

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
void dispatch_log_off(uint16_t sender) {
if (sender == game_var.id_game) {

}

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
void dispatch_timer_start(uint16_t sender, uint8_t param_id, uint16_t param_time) {
if (sender == game_var.id_clock) {
TimerArduino_handle_timer_timer_start(&timer_var, param_id, param_time);

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
void dispatch_displayReady(uint16_t sender) {
if (sender == disp_var.id_display) {
BreakoutGameArduino_handle_display_displayReady(&game_var);

}
if (sender == game_var.id_game) {

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
void dispatch_updateIA(uint16_t sender, int16_t param_ballx, int16_t param_bally, int16_t param_padx, int16_t param_pady) {
if (sender == game_var.id_ia) {
BasicIAController_handle_game_updateIA(&ctrl_var, param_ballx, param_bally, param_padx, param_pady);

}
if (sender == game_var.id_game) {

}

}


int processMessageQueue() {
if (fifo_empty()) return 0; // return 0 if there is nothing to do

uint8_t mbufi = 0;

// Read the code of the next port/message in the queue
uint16_t code = fifo_dequeue() << 8;

code += fifo_dequeue();

// Switch to call the appropriate handler
switch(code) {
case 2:{
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
case 7:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_lostBall = 2;
dispatch_lostBall((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 3:{
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
case 4:{
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
case 5:{
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
case 1:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_displayReady = 2;
dispatch_displayReady((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 8:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_nextLevel = 2;
dispatch_nextLevel((mbuf[0] << 8) + mbuf[1] /* instance port*/);
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
}
return 1;
}


//external Message enqueue

void initialize_configuration_test() {
// Initialize connectors
register_HeadlessDisplay_send_display_displayReady_listener(&enqueue_HeadlessDisplay_send_display_displayReady);
register_BasicIAController_send_controls_position_listener(&enqueue_BasicIAController_send_controls_position);
register_TimerArduino_send_timer_timer_timeout_listener(&enqueue_TimerArduino_send_timer_timer_timeout);
register_BreakoutGameArduino_send_log_log_listener(&sync_dispatch_BreakoutGameArduino_send_log_log);
register_BreakoutGameArduino_send_clock_timer_start_listener(&enqueue_BreakoutGameArduino_send_clock_timer_start);
register_BreakoutGameArduino_send_clock_timer_cancel_listener(&enqueue_BreakoutGameArduino_send_clock_timer_cancel);
register_BreakoutGameArduino_send_display_clear_listener(&sync_dispatch_BreakoutGameArduino_send_display_clear);
register_BreakoutGameArduino_send_display_drawThingML_listener(&sync_dispatch_BreakoutGameArduino_send_display_drawThingML);
register_BreakoutGameArduino_send_display_create_listener(&sync_dispatch_BreakoutGameArduino_send_display_create);
register_BreakoutGameArduino_send_display_drawRect_listener(&sync_dispatch_BreakoutGameArduino_send_display_drawRect);
register_BreakoutGameArduino_send_display_setBGColor_listener(&sync_dispatch_BreakoutGameArduino_send_display_setBGColor);
register_BreakoutGameArduino_send_display_drawInteger_listener(&sync_dispatch_BreakoutGameArduino_send_display_drawInteger);
register_BreakoutGameArduino_send_display_fillRect_listener(&sync_dispatch_BreakoutGameArduino_send_display_fillRect);
register_BreakoutGameArduino_send_display_setColor_listener(&sync_dispatch_BreakoutGameArduino_send_display_setColor);
register_BreakoutGameArduino_send_display_update_listener(&sync_dispatch_BreakoutGameArduino_send_display_update);
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
log_var.Logger_HAS_SIGNED_BYTE_var = 0;
log_var.Logger_ACTIVATE_ON_STARTUP_var = 0;

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
game_var.BreakoutGame_RIGHT_var = 160 * 64 - 1 * 64;
game_var.BreakoutGame_lives_var = 3;
game_var.BreakoutGame_score_var = 0;
game_var.BreakoutGame_LEFT_var = 1 * 64;
game_var.BreakoutGame_counter_var = 0;
game_var.BreakoutGameArduino_RAM_SIZE_var = 98304;
game_var.BreakoutGame_dx_var = 160 * 64 / 98;
game_var.BreakoutGame_level_var = 1;
game_var.BreakoutGame_prevBY_var =  -1;
game_var.BreakoutGame_lastTimestamp_var = 0;
game_var.BreakoutGame_pady_var = 128 * 64 - 6 * 64;
game_var.BreakoutGame_prevPX_var =  -1;
game_var.BreakoutGame_BOTTOM_var = 128 * 64 + 8 * 64;
game_var.BreakoutGame_SCALE_var = 64;
game_var.BreakoutGame_BRICK_HEIGHT_var = 9;
game_var.BreakoutGame_by_var = 128 * 64;
game_var.BreakoutGame_bx_var = 160 * 64 / 2;
game_var.BreakoutGame_YMAX_var = 128 * 64;
game_var.BreakoutGame_YDISPSIZE_var = 128;
game_var.BreakoutGame_dy_var =  -160 * 64 / 65;
game_var.BreakoutGame_XDISPSIZE_var = 160;
game_var.WithBinaryLog_DEBUG_BIN_ID_var = 0x00;
game_var.BreakoutGame_period_var = 3;
game_var.BreakoutGame_QUIET_var = 1;
game_var.BreakoutGame_br_var = 3 * 64;
game_var.BreakoutGame_padx_var = 128 * 64 / 2;
game_var.BreakoutGame_padlen_var = 25 * 64;
game_var.BreakoutGame_TOP_var = 14 * 64;
game_var.BreakoutGame_prevBX_var =  -1;
game_var.BreakoutGame_XMAX_var = 160 * 64;
game_var.BreakoutGame_BRICK_ROWS_var = 5;
game_var.BreakoutGame_prevPY_var =  -1;
game_var.BreakoutGame_bricks_var = array_game_BreakoutGame_bricks_var;
game_var.BreakoutGame_bricks_var_size = 5;
game_var.BreakoutGame_bgcolor_var = array_game_BreakoutGame_bgcolor_var;
game_var.BreakoutGame_bgcolor_var_size = 3;
game_var.BreakoutGame_fgcolor_var = array_game_BreakoutGame_fgcolor_var;
game_var.BreakoutGame_fgcolor_var_size = 3;

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
emptyEventConsumed += Binary2StringLogger_handle_empty_event(&log_var);
}
f_TimerArduino_poll_soft_timers(&timer_var);

    processMessageQueue();
}
