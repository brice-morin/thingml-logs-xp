/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing BreakoutGamePosix
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef BreakoutGamePosix_H_
#define BreakoutGamePosix_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : BreakoutGamePosix
 *****************************************************************************/


// BEGIN: Code from the c_header annotation BreakoutGamePosix
#include <time.h>
#include <stdlib.h>
// END: Code from the c_header annotation BreakoutGamePosix

// Definition of the instance struct:
struct BreakoutGamePosix_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
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
int16_t BreakoutGame_bx_var;
uint32_t BreakoutGame_stopTime_var;
bool BreakoutGame_QUIET_var;
uint8_t BreakoutGame_lives_var;
int16_t BreakoutGame_padx_var;
uint8_t BreakoutGame_YDISPSIZE_var;
int16_t BreakoutGame_TOP_var;
uint8_t BreakoutGame_XDISPSIZE_var;
int16_t BreakoutGame_padlen_var;
int16_t BreakoutGame_prevBY_var;
int16_t BreakoutGame_pady_var;
int16_t BreakoutGame_XMAX_var;
int16_t BreakoutGame_by_var;
int16_t BreakoutGame_BOTTOM_var;
uint8_t BreakoutGame_BRICK_HEIGHT_var;
uint8_t * BreakoutGame_bgcolor_var;
uint16_t BreakoutGame_bgcolor_var_size;
uint8_t BreakoutGame_SC_LAUNCH_countdown_var;
int16_t BreakoutGame_SCALE_var;
uint8_t BreakoutGame_counter_var;
uint8_t BreakoutGame_BRICK_ROWS_var;
uint8_t * BreakoutGame_bricks_var;
uint16_t BreakoutGame_bricks_var_size;
int16_t BreakoutGame_LEFT_var;
int16_t BreakoutGame_prevPY_var;
int16_t BreakoutGame_score_var;
int16_t BreakoutGame_prevBX_var;
uint32_t BreakoutGame_lastTimestamp_var;
uint32_t BreakoutGame_startTime_var;
int16_t BreakoutGame_dx_var;
int16_t BreakoutGame_YMAX_var;
int16_t BreakoutGame_prevPX_var;
int16_t BreakoutGame_br_var;
uint8_t BreakoutGame_level_var;
uint8_t * BreakoutGame_fgcolor_var;
uint16_t BreakoutGame_fgcolor_var_size;
int16_t BreakoutGame_dy_var;
int16_t BreakoutGame_RIGHT_var;
uint16_t BreakoutGame_period_var;

};
// Declaration of prototypes outgoing messages :
void BreakoutGame_SC_OnEntry(int state, struct BreakoutGamePosix_Instance *_instance);
void BreakoutGamePosix_handle_game_lostBall(struct BreakoutGamePosix_Instance *_instance);
void BreakoutGamePosix_handle_game_nextLevel(struct BreakoutGamePosix_Instance *_instance);
void BreakoutGamePosix_handle_display_displayReady(struct BreakoutGamePosix_Instance *_instance);
void BreakoutGamePosix_handle_pro_game_lostBall(struct BreakoutGamePosix_Instance *_instance);
void BreakoutGamePosix_handle_pro_game_nextLevel(struct BreakoutGamePosix_Instance *_instance);
void BreakoutGamePosix_handle_clock_timer_timeout(struct BreakoutGamePosix_Instance *_instance, uint8_t id);
void BreakoutGamePosix_handle_controller_position(struct BreakoutGamePosix_Instance *_instance, int16_t x, int16_t y);
// Declaration of callbacks for incoming messages:
void register_BreakoutGamePosix_send_clock_timer_start_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint16_t));
void register_external_BreakoutGamePosix_send_clock_timer_start_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint16_t));
void register_BreakoutGamePosix_send_clock_timer_cancel_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t));
void register_external_BreakoutGamePosix_send_clock_timer_cancel_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t));
void register_BreakoutGamePosix_send_display_create_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t));
void register_external_BreakoutGamePosix_send_display_create_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t));
void register_BreakoutGamePosix_send_display_fillRect_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, uint8_t, uint8_t));
void register_external_BreakoutGamePosix_send_display_fillRect_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, uint8_t, uint8_t));
void register_BreakoutGamePosix_send_display_drawRect_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, uint8_t, uint8_t));
void register_external_BreakoutGamePosix_send_display_drawRect_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, uint8_t, uint8_t));
void register_BreakoutGamePosix_send_display_clear_listener(void (*_listener)(struct BreakoutGamePosix_Instance *));
void register_external_BreakoutGamePosix_send_display_clear_listener(void (*_listener)(struct BreakoutGamePosix_Instance *));
void register_BreakoutGamePosix_send_display_setColor_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, uint8_t));
void register_external_BreakoutGamePosix_send_display_setColor_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, uint8_t));
void register_BreakoutGamePosix_send_display_setBGColor_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, uint8_t));
void register_external_BreakoutGamePosix_send_display_setBGColor_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, uint8_t));
void register_BreakoutGamePosix_send_display_drawInteger_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, int16_t, uint8_t, uint8_t));
void register_external_BreakoutGamePosix_send_display_drawInteger_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, int16_t, uint8_t, uint8_t));
void register_BreakoutGamePosix_send_display_update_listener(void (*_listener)(struct BreakoutGamePosix_Instance *));
void register_external_BreakoutGamePosix_send_display_update_listener(void (*_listener)(struct BreakoutGamePosix_Instance *));
void register_BreakoutGamePosix_send_display_drawThingML_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t));
void register_external_BreakoutGamePosix_send_display_drawThingML_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t));
void register_BreakoutGamePosix_send_ia_updateIA_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, int16_t, int16_t, int16_t, int16_t));
void register_external_BreakoutGamePosix_send_ia_updateIA_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, int16_t, int16_t, int16_t, int16_t));
void register_BreakoutGamePosix_send_game_lostBall_listener(void (*_listener)(struct BreakoutGamePosix_Instance *));
void register_external_BreakoutGamePosix_send_game_lostBall_listener(void (*_listener)(struct BreakoutGamePosix_Instance *));
void register_BreakoutGamePosix_send_game_nextLevel_listener(void (*_listener)(struct BreakoutGamePosix_Instance *));
void register_external_BreakoutGamePosix_send_game_nextLevel_listener(void (*_listener)(struct BreakoutGamePosix_Instance *));
void register_BreakoutGamePosix_send_req_game_lostBall_listener(void (*_listener)(struct BreakoutGamePosix_Instance *));
void register_external_BreakoutGamePosix_send_req_game_lostBall_listener(void (*_listener)(struct BreakoutGamePosix_Instance *));
void register_BreakoutGamePosix_send_req_game_nextLevel_listener(void (*_listener)(struct BreakoutGamePosix_Instance *));
void register_external_BreakoutGamePosix_send_req_game_nextLevel_listener(void (*_listener)(struct BreakoutGamePosix_Instance *));

// Definition of the states:
#define BREAKOUTGAME_SC_GAMEOVER_STATE 0
#define BREAKOUTGAME_SC_PLAY_STATE 1
#define BREAKOUTGAME_SC_STATE 2
#define BREAKOUTGAME_SC_LAUNCH_STATE 3
#define BREAKOUTGAME_SC_LOSTBALL_STATE 4
#define BREAKOUTGAME_SC_INIT_STATE 5
#define BREAKOUTGAME_SC_NEXTLEVEL_STATE 6



#ifdef __cplusplus
}
#endif

#endif //BreakoutGamePosix_H_
