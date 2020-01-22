/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing BreakoutGamePosix
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "BreakoutGamePosix.h"

/*****************************************************************************
 * Implementation for type : BreakoutGamePosix
 *****************************************************************************/


// BEGIN: Code from the c_global annotation BreakoutGamePosix
struct timespec t;

typedef struct {
	unsigned long size,resident,share,text,lib,data,dt;
} statm_t;
// END: Code from the c_global annotation BreakoutGamePosix

// Declaration of prototypes:
//Prototypes: State Machine
void BreakoutGame_SC_OnExit(int state, struct BreakoutGamePosix_Instance *_instance);
//Prototypes: Message Sending
void BreakoutGamePosix_send_log_function_called(struct BreakoutGamePosix_Instance *_instance, char * inst, char * fn_name, char * ty, char * returns, char * params);
void BreakoutGamePosix_send_log_property_changed(struct BreakoutGamePosix_Instance *_instance, char * inst, char * prop_name, char * ty, char * old_value, char * new_value);
void BreakoutGamePosix_send_log_message_lost(struct BreakoutGamePosix_Instance *_instance, char * inst, char * port_name, char * msg_name, char * params);
void BreakoutGamePosix_send_log_message_handled(struct BreakoutGamePosix_Instance *_instance, char * inst, char * source, char * target, char * port_name, char * msg_name, char * params);
void BreakoutGamePosix_send_log_message_sent(struct BreakoutGamePosix_Instance *_instance, char * inst, char * port_name, char * msg_name, char * params);
void BreakoutGamePosix_send_clock_timer_start(struct BreakoutGamePosix_Instance *_instance, uint8_t id, uint16_t time);
void BreakoutGamePosix_send_clock_timer_cancel(struct BreakoutGamePosix_Instance *_instance, uint8_t id);
void BreakoutGamePosix_send_display_create(struct BreakoutGamePosix_Instance *_instance, uint8_t xsize, uint8_t ysize);
void BreakoutGamePosix_send_display_fillRect(struct BreakoutGamePosix_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void BreakoutGamePosix_send_display_drawRect(struct BreakoutGamePosix_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void BreakoutGamePosix_send_display_clear(struct BreakoutGamePosix_Instance *_instance);
void BreakoutGamePosix_send_display_setColor(struct BreakoutGamePosix_Instance *_instance, uint8_t r, uint8_t g, uint8_t b);
void BreakoutGamePosix_send_display_setBGColor(struct BreakoutGamePosix_Instance *_instance, uint8_t r, uint8_t g, uint8_t b);
void BreakoutGamePosix_send_display_drawInteger(struct BreakoutGamePosix_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale);
void BreakoutGamePosix_send_display_update(struct BreakoutGamePosix_Instance *_instance);
void BreakoutGamePosix_send_display_drawThingML(struct BreakoutGamePosix_Instance *_instance, uint8_t x, uint8_t y);
void BreakoutGamePosix_send_ia_updateIA(struct BreakoutGamePosix_Instance *_instance, int16_t ballx, int16_t bally, int16_t padx, int16_t pady);
void BreakoutGamePosix_send_game_lostBall(struct BreakoutGamePosix_Instance *_instance);
void BreakoutGamePosix_send_game_nextLevel(struct BreakoutGamePosix_Instance *_instance);
void BreakoutGamePosix_send_req_game_lostBall(struct BreakoutGamePosix_Instance *_instance);
void BreakoutGamePosix_send_req_game_nextLevel(struct BreakoutGamePosix_Instance *_instance);
//Prototypes: Function
void f_BreakoutGamePosix_log(struct BreakoutGamePosix_Instance *_instance, bool logMem);
void f_BreakoutGamePosix_initColors(struct BreakoutGamePosix_Instance *_instance);
void f_BreakoutGamePosix_resetBall(struct BreakoutGamePosix_Instance *_instance);
void f_BreakoutGamePosix_eraseBall(struct BreakoutGamePosix_Instance *_instance);
void f_BreakoutGamePosix_drawBall(struct BreakoutGamePosix_Instance *_instance);
void f_BreakoutGamePosix_erasePad(struct BreakoutGamePosix_Instance *_instance);
void f_BreakoutGamePosix_drawPad(struct BreakoutGamePosix_Instance *_instance);
void f_BreakoutGamePosix_drawCountDown(struct BreakoutGamePosix_Instance *_instance, int16_t c);
void f_BreakoutGamePosix_drawWalls(struct BreakoutGamePosix_Instance *_instance);
bool f_BreakoutGamePosix_bitIsSet(struct BreakoutGamePosix_Instance *_instance, uint8_t variable, uint8_t bit);
void f_BreakoutGamePosix_createBricks(struct BreakoutGamePosix_Instance *_instance);
uint8_t f_BreakoutGamePosix_bricksLeft(struct BreakoutGamePosix_Instance *_instance);
void f_BreakoutGamePosix_drawBrick(struct BreakoutGamePosix_Instance *_instance, uint8_t x, uint8_t y);
void f_BreakoutGamePosix_removeBrick(struct BreakoutGamePosix_Instance *_instance, uint8_t x, uint8_t y);
bool f_BreakoutGamePosix_collideBrick(struct BreakoutGamePosix_Instance *_instance, int16_t xpos, int16_t ypos);
void f_BreakoutGamePosix_drawLevel(struct BreakoutGamePosix_Instance *_instance);
void f_BreakoutGamePosix_incrementScore(struct BreakoutGamePosix_Instance *_instance, int8_t diff);
void f_BreakoutGamePosix_drawScore(struct BreakoutGamePosix_Instance *_instance);
void f_BreakoutGamePosix_drawLives(struct BreakoutGamePosix_Instance *_instance);
void f_BreakoutGamePosix_quit(struct BreakoutGamePosix_Instance *_instance);
uint32_t f_BreakoutGamePosix_timestamp(struct BreakoutGamePosix_Instance *_instance);
uint32_t f_BreakoutGamePosix_usedMemory(struct BreakoutGamePosix_Instance *_instance);
uint8_t f_BreakoutGamePosix_unsetBit(struct BreakoutGamePosix_Instance *_instance, uint8_t variable, uint8_t bit);
// Declaration of functions:
// Definition of function log
void f_BreakoutGamePosix_log(struct BreakoutGamePosix_Instance *_instance, bool logMem) {
if(_instance->BreakoutGame_counter_var == 0 || logMem) {
uint32_t ts;
if(_instance->BreakoutGame_lastTimestamp_var == 0) {
ts = 0;
_instance->BreakoutGame_lastTimestamp_var = f_BreakoutGamePosix_timestamp(_instance);

} else {
uint32_t t = f_BreakoutGamePosix_timestamp(_instance);
ts = t - _instance->BreakoutGame_lastTimestamp_var;
_instance->BreakoutGame_lastTimestamp_var = t;

}
if( !(_instance->BreakoutGame_QUIET_var)) {
fprintf(stdout, "ts:");
fprintf(stdout, "%i",ts);
fprintf(stdout, ",lives:");
fprintf(stdout, "%i",_instance->BreakoutGame_lives_var);
fprintf(stdout, ",score:");
fprintf(stdout, "%i",_instance->BreakoutGame_score_var);
fprintf(stdout, ",level:");
fprintf(stdout, "%i",_instance->BreakoutGame_level_var);
fprintf(stdout, ",bx:");
fprintf(stdout, "%i",_instance->BreakoutGame_bx_var);
fprintf(stdout, ",by:");
fprintf(stdout, "%i",_instance->BreakoutGame_by_var);
fprintf(stdout, ",padx:");
fprintf(stdout, "%i",_instance->BreakoutGame_padx_var);
fprintf(stdout, "\n");
fprintf(stdout, "#usedMem:");
fprintf(stdout, "%i",f_BreakoutGamePosix_usedMemory(_instance));
fprintf(stdout, "\n");

}

}
_instance->BreakoutGame_counter_var++;
if(_instance->BreakoutGame_counter_var == 33) {
_instance->BreakoutGame_counter_var = 0;

}
}
// Definition of function initColors
void f_BreakoutGamePosix_initColors(struct BreakoutGamePosix_Instance *_instance) {
BreakoutGamePosix_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "initColors", "void_", "", "");
_instance->BreakoutGame_bgcolor_var[0] = 53;
_instance->BreakoutGame_bgcolor_var[1] = 40;
_instance->BreakoutGame_bgcolor_var[2] = 120;
_instance->BreakoutGame_fgcolor_var[0] = 107;
_instance->BreakoutGame_fgcolor_var[1] = 94;
_instance->BreakoutGame_fgcolor_var[2] = 174;
uint8_t r_0 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_1 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_2 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGamePosix_send_display_setBGColor(_instance, r_0, g_1, b_2);
char * params_3 = "" + ("r=" + (r_0 + ",")) + ("g=" + (g_1 + ",")) + ("b=" + (b_2 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setBGColor", params_3);
uint8_t r_4 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_5 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_6 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGamePosix_send_display_setColor(_instance, r_4, g_5, b_6);
char * params_7 = "" + ("r=" + (r_4 + ",")) + ("g=" + (g_5 + ",")) + ("b=" + (b_6 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_7);
}
// Definition of function resetBall
void f_BreakoutGamePosix_resetBall(struct BreakoutGamePosix_Instance *_instance) {
BreakoutGamePosix_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "resetBall", "void_", "", "");
char * old_bx_0 = "" + _instance->BreakoutGame_bx_var;
_instance->BreakoutGame_bx_var = _instance->BreakoutGame_padx_var - _instance->BreakoutGame_br_var / _instance->BreakoutGame_SCALE_var;
char * new_bx_0 = "" + _instance->BreakoutGame_bx_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "bx", "Int16", old_bx_0, new_bx_0);
char * old_by_8 = "" + _instance->BreakoutGame_by_var;
_instance->BreakoutGame_by_var = _instance->BreakoutGame_pady_var - _instance->BreakoutGame_br_var / _instance->BreakoutGame_SCALE_var;
char * new_by_8 = "" + _instance->BreakoutGame_by_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "by", "Int16", old_by_8, new_by_8);
char * old_dx_21 = "" + _instance->BreakoutGame_dx_var;
_instance->BreakoutGame_dx_var = (_instance->BreakoutGame_padx_var + _instance->BreakoutGame_prevBX_var + _instance->BreakoutGame_prevBY_var) % 300 - 150;
char * new_dx_21 = "" + _instance->BreakoutGame_dx_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "dx", "Int16", old_dx_21, new_dx_21);
if(_instance->BreakoutGame_dy_var > 0) {
char * old_dy_13 = "" + _instance->BreakoutGame_dy_var;
_instance->BreakoutGame_dy_var =  -_instance->BreakoutGame_dy_var;
char * new_dy_13 = "" + _instance->BreakoutGame_dy_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "dy", "Int16", old_dy_13, new_dy_13);

}
char * old_prevBX_18 = "" + _instance->BreakoutGame_prevBX_var;
_instance->BreakoutGame_prevBX_var =  -1;
char * new_prevBX_18 = "" + _instance->BreakoutGame_prevBX_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "prevBX", "Int16", old_prevBX_18, new_prevBX_18);
char * old_prevBY_30 = "" + _instance->BreakoutGame_prevBY_var;
_instance->BreakoutGame_prevBY_var =  -1;
char * new_prevBY_30 = "" + _instance->BreakoutGame_prevBY_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "prevBY", "Int16", old_prevBY_30, new_prevBY_30);
}
// Definition of function eraseBall
void f_BreakoutGamePosix_eraseBall(struct BreakoutGamePosix_Instance *_instance) {
BreakoutGamePosix_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "eraseBall", "void_", "", "");
int16_t bs = (_instance->BreakoutGame_br_var * 2) / _instance->BreakoutGame_SCALE_var;
if(_instance->BreakoutGame_prevBX_var > 0) {
uint8_t r_8 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_9 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_10 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGamePosix_send_display_setColor(_instance, r_8, g_9, b_10);
char * params_11 = "" + ("r=" + (r_8 + ",")) + ("g=" + (g_9 + ",")) + ("b=" + (b_10 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_11);
uint8_t x_12 = _instance->BreakoutGame_prevBX_var;
uint8_t y_13 = _instance->BreakoutGame_prevBY_var;
uint8_t width_14 = bs;
uint8_t height_15 = bs;
BreakoutGamePosix_send_display_fillRect(_instance, x_12, y_13, width_14, height_15);
char * params_16 = "" + ("x=" + (x_12 + ",")) + ("y=" + (y_13 + ",")) + ("width=" + (width_14 + ",")) + ("height=" + (height_15 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_16);

}
char * old_prevBX_19 = "" + _instance->BreakoutGame_prevBX_var;
_instance->BreakoutGame_prevBX_var =  -1;
char * new_prevBX_19 = "" + _instance->BreakoutGame_prevBX_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "prevBX", "Int16", old_prevBX_19, new_prevBX_19);
char * old_prevBY_31 = "" + _instance->BreakoutGame_prevBY_var;
_instance->BreakoutGame_prevBY_var =  -1;
char * new_prevBY_31 = "" + _instance->BreakoutGame_prevBY_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "prevBY", "Int16", old_prevBY_31, new_prevBY_31);
}
// Definition of function drawBall
void f_BreakoutGamePosix_drawBall(struct BreakoutGamePosix_Instance *_instance) {
BreakoutGamePosix_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "drawBall", "void_", "", "");
int16_t bs = (_instance->BreakoutGame_br_var * 2) / _instance->BreakoutGame_SCALE_var;
f_BreakoutGamePosix_eraseBall(_instance);
char * old_prevBX_20 = "" + _instance->BreakoutGame_prevBX_var;
_instance->BreakoutGame_prevBX_var = (_instance->BreakoutGame_bx_var - _instance->BreakoutGame_br_var) / _instance->BreakoutGame_SCALE_var;
char * new_prevBX_20 = "" + _instance->BreakoutGame_prevBX_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "prevBX", "Int16", old_prevBX_20, new_prevBX_20);
char * old_prevBY_32 = "" + _instance->BreakoutGame_prevBY_var;
_instance->BreakoutGame_prevBY_var = (_instance->BreakoutGame_by_var - _instance->BreakoutGame_br_var) / _instance->BreakoutGame_SCALE_var;
char * new_prevBY_32 = "" + _instance->BreakoutGame_prevBY_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "prevBY", "Int16", old_prevBY_32, new_prevBY_32);
uint8_t r_17 = 183;
uint8_t g_18 = 199;
uint8_t b_19 = 111;
BreakoutGamePosix_send_display_setColor(_instance, r_17, g_18, b_19);
char * params_20 = "" + ("r=" + (r_17 + ",")) + ("g=" + (g_18 + ",")) + ("b=" + (b_19 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_20);
uint8_t x_21 = _instance->BreakoutGame_prevBX_var;
uint8_t y_22 = _instance->BreakoutGame_prevBY_var;
uint8_t width_23 = bs;
uint8_t height_24 = bs;
BreakoutGamePosix_send_display_fillRect(_instance, x_21, y_22, width_23, height_24);
char * params_25 = "" + ("x=" + (x_21 + ",")) + ("y=" + (y_22 + ",")) + ("width=" + (width_23 + ",")) + ("height=" + (height_24 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_25);
}
// Definition of function erasePad
void f_BreakoutGamePosix_erasePad(struct BreakoutGamePosix_Instance *_instance) {
BreakoutGamePosix_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "erasePad", "void_", "", "");
int16_t ps = _instance->BreakoutGame_padlen_var / _instance->BreakoutGame_SCALE_var;
if(_instance->BreakoutGame_prevPX_var > 0) {
uint8_t r_26 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_27 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_28 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGamePosix_send_display_setColor(_instance, r_26, g_27, b_28);
char * params_29 = "" + ("r=" + (r_26 + ",")) + ("g=" + (g_27 + ",")) + ("b=" + (b_28 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_29);
uint8_t x_30 = _instance->BreakoutGame_prevPX_var;
uint8_t y_31 = _instance->BreakoutGame_prevPY_var;
uint8_t width_32 = ps;
uint8_t height_33 = 4;
BreakoutGamePosix_send_display_fillRect(_instance, x_30, y_31, width_32, height_33);
char * params_34 = "" + ("x=" + (x_30 + ",")) + ("y=" + (y_31 + ",")) + ("width=" + (width_32 + ",")) + ("height=" + (height_33 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_34);

}
}
// Definition of function drawPad
void f_BreakoutGamePosix_drawPad(struct BreakoutGamePosix_Instance *_instance) {
BreakoutGamePosix_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "drawPad", "void_", "", "");
int16_t ps = _instance->BreakoutGame_padlen_var / _instance->BreakoutGame_SCALE_var;
f_BreakoutGamePosix_erasePad(_instance);
char * old_prevPX_25 = "" + _instance->BreakoutGame_prevPX_var;
_instance->BreakoutGame_prevPX_var = (_instance->BreakoutGame_padx_var - (_instance->BreakoutGame_padlen_var / 2)) / _instance->BreakoutGame_SCALE_var;
char * new_prevPX_25 = "" + _instance->BreakoutGame_prevPX_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "prevPX", "Int16", old_prevPX_25, new_prevPX_25);
char * old_prevPY_5 = "" + _instance->BreakoutGame_prevPY_var;
_instance->BreakoutGame_prevPY_var = _instance->BreakoutGame_pady_var / _instance->BreakoutGame_SCALE_var;
char * new_prevPY_5 = "" + _instance->BreakoutGame_prevPY_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "prevPY", "Int16", old_prevPY_5, new_prevPY_5);
uint8_t r_35 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_36 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_37 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGamePosix_send_display_setColor(_instance, r_35, g_36, b_37);
char * params_38 = "" + ("r=" + (r_35 + ",")) + ("g=" + (g_36 + ",")) + ("b=" + (b_37 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_38);
uint8_t x_39 = _instance->BreakoutGame_prevPX_var;
uint8_t y_40 = _instance->BreakoutGame_prevPY_var;
uint8_t width_41 = ps;
uint8_t height_42 = 4;
BreakoutGamePosix_send_display_fillRect(_instance, x_39, y_40, width_41, height_42);
char * params_43 = "" + ("x=" + (x_39 + ",")) + ("y=" + (y_40 + ",")) + ("width=" + (width_41 + ",")) + ("height=" + (height_42 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_43);
}
// Definition of function drawCountDown
void f_BreakoutGamePosix_drawCountDown(struct BreakoutGamePosix_Instance *_instance, int16_t c) {
char * params = "" + ("c=" + (c + ","));
BreakoutGamePosix_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "drawCountDown", "void_", "", params);
uint8_t r_44 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_45 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_46 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGamePosix_send_display_setColor(_instance, r_44, g_45, b_46);
char * params_47 = "" + ("r=" + (r_44 + ",")) + ("g=" + (g_45 + ",")) + ("b=" + (b_46 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_47);
if(c > 0) {
uint8_t r_48 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_49 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_50 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGamePosix_send_display_setColor(_instance, r_48, g_49, b_50);
char * params_51 = "" + ("r=" + (r_48 + ",")) + ("g=" + (g_49 + ",")) + ("b=" + (b_50 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_51);
uint8_t r_52 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_53 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_54 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGamePosix_send_display_setBGColor(_instance, r_52, g_53, b_54);
char * params_55 = "" + ("r=" + (r_52 + ",")) + ("g=" + (g_53 + ",")) + ("b=" + (b_54 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setBGColor", params_55);
uint8_t x_56 = 80 - 6;
uint8_t y_57 = 90;
int16_t v_58 = c;
uint8_t digits_59 = 1;
uint8_t scale_60 = 4;
BreakoutGamePosix_send_display_drawInteger(_instance, x_56, y_57, v_58, digits_59, scale_60);
char * params_61 = "" + ("x=" + (x_56 + ",")) + ("y=" + (y_57 + ",")) + ("v=" + (v_58 + ",")) + ("digits=" + (digits_59 + ",")) + ("scale=" + (scale_60 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "drawInteger", params_61);

} else {
uint8_t r_62 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_63 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_64 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGamePosix_send_display_setColor(_instance, r_62, g_63, b_64);
char * params_65 = "" + ("r=" + (r_62 + ",")) + ("g=" + (g_63 + ",")) + ("b=" + (b_64 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_65);
uint8_t x_66 = 80 - 6;
uint8_t y_67 = 90;
uint8_t width_68 = 12;
uint8_t height_69 = 20;
BreakoutGamePosix_send_display_fillRect(_instance, x_66, y_67, width_68, height_69);
char * params_70 = "" + ("x=" + (x_66 + ",")) + ("y=" + (y_67 + ",")) + ("width=" + (width_68 + ",")) + ("height=" + (height_69 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_70);

}
}
// Definition of function drawWalls
void f_BreakoutGamePosix_drawWalls(struct BreakoutGamePosix_Instance *_instance) {
BreakoutGamePosix_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "drawWalls", "void_", "", "");
uint8_t r_71 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_72 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_73 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGamePosix_send_display_setColor(_instance, r_71, g_72, b_73);
char * params_74 = "" + ("r=" + (r_71 + ",")) + ("g=" + (g_72 + ",")) + ("b=" + (b_73 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_74);
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
BreakoutGamePosix_send_display_fillRect(_instance, x_75, y_76, width_77, height_78);
char * params_79 = "" + ("x=" + (x_75 + ",")) + ("y=" + (y_76 + ",")) + ("width=" + (width_77 + ",")) + ("height=" + (height_78 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_79);
uint8_t x_80 = left - 1;
uint8_t y_81 = bottom;
uint8_t width_82 = xcenter + 1;
uint8_t height_83 = 1;
BreakoutGamePosix_send_display_fillRect(_instance, x_80, y_81, width_82, height_83);
char * params_84 = "" + ("x=" + (x_80 + ",")) + ("y=" + (y_81 + ",")) + ("width=" + (width_82 + ",")) + ("height=" + (height_83 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_84);
uint8_t x_85 = left - 1;
uint8_t y_86 = top;
uint8_t width_87 = 1;
uint8_t height_88 = ycenter;
BreakoutGamePosix_send_display_fillRect(_instance, x_85, y_86, width_87, height_88);
char * params_89 = "" + ("x=" + (x_85 + ",")) + ("y=" + (y_86 + ",")) + ("width=" + (width_87 + ",")) + ("height=" + (height_88 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_89);
uint8_t x_90 = right;
uint8_t y_91 = top;
uint8_t width_92 = 1;
uint8_t height_93 = ycenter;
BreakoutGamePosix_send_display_fillRect(_instance, x_90, y_91, width_92, height_93);
char * params_94 = "" + ("x=" + (x_90 + ",")) + ("y=" + (y_91 + ",")) + ("width=" + (width_92 + ",")) + ("height=" + (height_93 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_94);
}
// Definition of function bitIsSet
bool f_BreakoutGamePosix_bitIsSet(struct BreakoutGamePosix_Instance *_instance, uint8_t variable, uint8_t bit) {
bool return_0 = (((1 << bit) & variable) != 0);
char * return_as_string0 = "" + (return_0);
char * params = "" + ("variable=" + (variable + ",")) + ("bit=" + (bit + ","));
BreakoutGamePosix_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "bitIsSet", "Boolean", return_as_string0, params);
return return_0;
}
// Definition of function createBricks
void f_BreakoutGamePosix_createBricks(struct BreakoutGamePosix_Instance *_instance) {
BreakoutGamePosix_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "createBricks", "void_", "", "");
uint8_t y = 0;
while(y < _instance->BreakoutGame_BRICK_ROWS_var) {
_instance->BreakoutGame_bricks_var[y] = 0xFF;
uint8_t x = 0;
while(x < 8) {
if(f_BreakoutGamePosix_bitIsSet(_instance, _instance->BreakoutGame_bricks_var[y], x)) {
f_BreakoutGamePosix_drawBrick(_instance, x, y);

}
x = x + 1;

}
y = y + 1;

}
}
// Definition of function bricksLeft
uint8_t f_BreakoutGamePosix_bricksLeft(struct BreakoutGamePosix_Instance *_instance) {
uint8_t result = 0;
uint8_t y = 0;
while(y < _instance->BreakoutGame_BRICK_ROWS_var) {
uint8_t x = 0;
while(x < 8) {
if(f_BreakoutGamePosix_bitIsSet(_instance, _instance->BreakoutGame_bricks_var[y], x)) {
result = result + 1;

}
x = x + 1;

}
y = y + 1;

}
uint8_t return_3 = result;
char * return_as_string3 = "" + (return_3);
BreakoutGamePosix_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "bricksLeft", "UInt8", return_as_string3, "");
return return_3;
}
// Definition of function drawBrick
void f_BreakoutGamePosix_drawBrick(struct BreakoutGamePosix_Instance *_instance, uint8_t x, uint8_t y) {
char * params = "" + ("x=" + (x + ",")) + ("y=" + (y + ","));
BreakoutGamePosix_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "drawBrick", "void_", "", params);
uint8_t bx = ((_instance->BreakoutGame_LEFT_var + ((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 8) * x) / _instance->BreakoutGame_SCALE_var + 1);
uint8_t by = ((_instance->BreakoutGame_TOP_var + 20 * _instance->BreakoutGame_SCALE_var + _instance->BreakoutGame_BRICK_HEIGHT_var * y * _instance->BreakoutGame_SCALE_var) / _instance->BreakoutGame_SCALE_var + 1);
uint8_t w = (((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 8) / _instance->BreakoutGame_SCALE_var - 2);
uint8_t h = (_instance->BreakoutGame_BRICK_HEIGHT_var - 2);
uint8_t r_95 = 155;
uint8_t g_96 = 103;
uint8_t b_97 = 89;
BreakoutGamePosix_send_display_setColor(_instance, r_95, g_96, b_97);
char * params_98 = "" + ("r=" + (r_95 + ",")) + ("g=" + (g_96 + ",")) + ("b=" + (b_97 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_98);
uint8_t x_99 = bx;
uint8_t y_100 = by;
uint8_t width_101 = w;
uint8_t height_102 = h;
BreakoutGamePosix_send_display_fillRect(_instance, x_99, y_100, width_101, height_102);
char * params_103 = "" + ("x=" + (x_99 + ",")) + ("y=" + (y_100 + ",")) + ("width=" + (width_101 + ",")) + ("height=" + (height_102 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_103);
uint8_t r_104 = 100;
uint8_t g_105 = 56;
uint8_t b_106 = 43;
BreakoutGamePosix_send_display_setColor(_instance, r_104, g_105, b_106);
char * params_107 = "" + ("r=" + (r_104 + ",")) + ("g=" + (g_105 + ",")) + ("b=" + (b_106 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_107);
uint8_t x_108 = bx;
uint8_t y_109 = by;
uint8_t width_110 = w;
uint8_t height_111 = h;
BreakoutGamePosix_send_display_drawRect(_instance, x_108, y_109, width_110, height_111);
char * params_112 = "" + ("x=" + (x_108 + ",")) + ("y=" + (y_109 + ",")) + ("width=" + (width_110 + ",")) + ("height=" + (height_111 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "drawRect", params_112);
}
// Definition of function removeBrick
void f_BreakoutGamePosix_removeBrick(struct BreakoutGamePosix_Instance *_instance, uint8_t x, uint8_t y) {
char * params = "" + ("x=" + (x + ",")) + ("y=" + (y + ","));
BreakoutGamePosix_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "removeBrick", "void_", "", params);
uint8_t bx = ((_instance->BreakoutGame_LEFT_var + ((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 8) * x) / _instance->BreakoutGame_SCALE_var + 1);
uint8_t by = ((_instance->BreakoutGame_TOP_var + 20 * _instance->BreakoutGame_SCALE_var + _instance->BreakoutGame_BRICK_HEIGHT_var * y * _instance->BreakoutGame_SCALE_var) / _instance->BreakoutGame_SCALE_var + 1);
uint8_t r_113 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_114 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_115 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGamePosix_send_display_setColor(_instance, r_113, g_114, b_115);
char * params_116 = "" + ("r=" + (r_113 + ",")) + ("g=" + (g_114 + ",")) + ("b=" + (b_115 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_116);
uint8_t x_117 = bx;
uint8_t y_118 = by;
uint8_t width_119 = (((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 8) / _instance->BreakoutGame_SCALE_var - 2);
uint8_t height_120 = _instance->BreakoutGame_BRICK_HEIGHT_var - 2;
BreakoutGamePosix_send_display_fillRect(_instance, x_117, y_118, width_119, height_120);
char * params_121 = "" + ("x=" + (x_117 + ",")) + ("y=" + (y_118 + ",")) + ("width=" + (width_119 + ",")) + ("height=" + (height_120 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_121);
_instance->BreakoutGame_bricks_var[y] = f_BreakoutGamePosix_unsetBit(_instance, _instance->BreakoutGame_bricks_var[y], x);
}
// Definition of function collideBrick
bool f_BreakoutGamePosix_collideBrick(struct BreakoutGamePosix_Instance *_instance, int16_t xpos, int16_t ypos) {
int16_t bry = (ypos - _instance->BreakoutGame_TOP_var - 20 * _instance->BreakoutGame_SCALE_var) / (_instance->BreakoutGame_BRICK_HEIGHT_var * _instance->BreakoutGame_SCALE_var);
bool result = 0;
if(bry >= 0 && bry < _instance->BreakoutGame_BRICK_ROWS_var) {
int16_t brx = (xpos - _instance->BreakoutGame_LEFT_var) / ((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 8);
if(f_BreakoutGamePosix_bitIsSet(_instance, _instance->BreakoutGame_bricks_var[bry], brx)) {
f_BreakoutGamePosix_removeBrick(_instance, brx, bry);
result = 1;

}

}
bool return_3 = result;
char * return_as_string3 = "" + (return_3);
char * params = "" + ("xpos=" + (xpos + ",")) + ("ypos=" + (ypos + ","));
BreakoutGamePosix_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "collideBrick", "Boolean", return_as_string3, params);
return return_3;
}
// Definition of function drawLevel
void f_BreakoutGamePosix_drawLevel(struct BreakoutGamePosix_Instance *_instance) {
BreakoutGamePosix_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "drawLevel", "void_", "", "");
uint8_t r_122 = 158;
uint8_t g_123 = 209;
uint8_t b_124 = 130;
BreakoutGamePosix_send_display_setColor(_instance, r_122, g_123, b_124);
char * params_125 = "" + ("r=" + (r_122 + ",")) + ("g=" + (g_123 + ",")) + ("b=" + (b_124 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_125);
uint8_t r_126 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_127 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_128 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGamePosix_send_display_setBGColor(_instance, r_126, g_127, b_128);
char * params_129 = "" + ("r=" + (r_126 + ",")) + ("g=" + (g_127 + ",")) + ("b=" + (b_128 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setBGColor", params_129);
uint8_t r_130 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_131 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_132 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGamePosix_send_display_setColor(_instance, r_130, g_131, b_132);
char * params_133 = "" + ("r=" + (r_130 + ",")) + ("g=" + (g_131 + ",")) + ("b=" + (b_132 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_133);
uint8_t x_134 = 6;
uint8_t y_135 = 2;
int16_t v_136 = _instance->BreakoutGame_level_var;
uint8_t digits_137 = 2;
uint8_t scale_138 = 2;
BreakoutGamePosix_send_display_drawInteger(_instance, x_134, y_135, v_136, digits_137, scale_138);
char * params_139 = "" + ("x=" + (x_134 + ",")) + ("y=" + (y_135 + ",")) + ("v=" + (v_136 + ",")) + ("digits=" + (digits_137 + ",")) + ("scale=" + (scale_138 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "drawInteger", params_139);
}
// Definition of function incrementScore
void f_BreakoutGamePosix_incrementScore(struct BreakoutGamePosix_Instance *_instance, int8_t diff) {
char * params = "" + ("diff=" + (diff + ","));
BreakoutGamePosix_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "incrementScore", "void_", "", params);
char * old_score_6 = "" + _instance->BreakoutGame_score_var;
_instance->BreakoutGame_score_var = _instance->BreakoutGame_score_var + diff;
char * new_score_6 = "" + _instance->BreakoutGame_score_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "score", "Int16", old_score_6, new_score_6);
if(_instance->BreakoutGame_score_var < 0) {
char * old_score_7 = "" + _instance->BreakoutGame_score_var;
_instance->BreakoutGame_score_var = 0;
char * new_score_7 = "" + _instance->BreakoutGame_score_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "score", "Int16", old_score_7, new_score_7);

}
f_BreakoutGamePosix_drawScore(_instance);
}
// Definition of function drawScore
void f_BreakoutGamePosix_drawScore(struct BreakoutGamePosix_Instance *_instance) {
BreakoutGamePosix_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "drawScore", "void_", "", "");
uint8_t r_140 = 158;
uint8_t g_141 = 209;
uint8_t b_142 = 130;
BreakoutGamePosix_send_display_setColor(_instance, r_140, g_141, b_142);
char * params_143 = "" + ("r=" + (r_140 + ",")) + ("g=" + (g_141 + ",")) + ("b=" + (b_142 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_143);
uint8_t r_144 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_145 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_146 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGamePosix_send_display_setBGColor(_instance, r_144, g_145, b_146);
char * params_147 = "" + ("r=" + (r_144 + ",")) + ("g=" + (g_145 + ",")) + ("b=" + (b_146 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setBGColor", params_147);
uint8_t x_148 = 58;
uint8_t y_149 = 2;
int16_t v_150 = _instance->BreakoutGame_score_var;
uint8_t digits_151 = 5;
uint8_t scale_152 = 2;
BreakoutGamePosix_send_display_drawInteger(_instance, x_148, y_149, v_150, digits_151, scale_152);
char * params_153 = "" + ("x=" + (x_148 + ",")) + ("y=" + (y_149 + ",")) + ("v=" + (v_150 + ",")) + ("digits=" + (digits_151 + ",")) + ("scale=" + (scale_152 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "drawInteger", params_153);
}
// Definition of function drawLives
void f_BreakoutGamePosix_drawLives(struct BreakoutGamePosix_Instance *_instance) {
BreakoutGamePosix_send_log_function_called(_instance, _instance->WithLog_DEBUG_ID_var, "drawLives", "void_", "", "");
uint8_t r_154 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_155 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_156 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGamePosix_send_display_setColor(_instance, r_154, g_155, b_156);
char * params_157 = "" + ("r=" + (r_154 + ",")) + ("g=" + (g_155 + ",")) + ("b=" + (b_156 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_157);
uint8_t x_158 = 124;
uint8_t y_159 = 4;
uint8_t width_160 = 24 + 6;
uint8_t height_161 = 6;
BreakoutGamePosix_send_display_fillRect(_instance, x_158, y_159, width_160, height_161);
char * params_162 = "" + ("x=" + (x_158 + ",")) + ("y=" + (y_159 + ",")) + ("width=" + (width_160 + ",")) + ("height=" + (height_161 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_162);
uint8_t r_163 = 183;
uint8_t g_164 = 199;
uint8_t b_165 = 111;
BreakoutGamePosix_send_display_setColor(_instance, r_163, g_164, b_165);
char * params_166 = "" + ("r=" + (r_163 + ",")) + ("g=" + (g_164 + ",")) + ("b=" + (b_165 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_166);
uint8_t i = 0;
while(i < _instance->BreakoutGame_lives_var) {
uint8_t x_167 = 124 + (2 - i) * 12;
uint8_t y_168 = 4;
uint8_t width_169 = 6;
uint8_t height_170 = 6;
BreakoutGamePosix_send_display_fillRect(_instance, x_167, y_168, width_169, height_170);
char * params_171 = "" + ("x=" + (x_167 + ",")) + ("y=" + (y_168 + ",")) + ("width=" + (width_169 + ",")) + ("height=" + (height_170 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_171);
i = i + 1;

}
}
// Definition of function quit
void f_BreakoutGamePosix_quit(struct BreakoutGamePosix_Instance *_instance) {
fprintf(stdout, ">done in ");
fprintf(stdout, "%i",_instance->BreakoutGame_stopTime_var - _instance->BreakoutGame_startTime_var);
fprintf(stdout, "ms!");
fprintf(stdout, "\n");
fprintf(stdout, ">lives:");
fprintf(stdout, "%i",_instance->BreakoutGame_lives_var);
fprintf(stdout, ",score:");
fprintf(stdout, "%i",_instance->BreakoutGame_score_var);
fprintf(stdout, ",level:");
fprintf(stdout, "%i",_instance->BreakoutGame_level_var);
fprintf(stdout, ",bx:");
fprintf(stdout, "%i",_instance->BreakoutGame_bx_var);
fprintf(stdout, ",by:");
fprintf(stdout, "%i",_instance->BreakoutGame_by_var);
fprintf(stdout, ",padx:");
fprintf(stdout, "%i",_instance->BreakoutGame_padx_var);
fprintf(stdout, "\n");
fprintf(stdout, ">usedMem:");
fprintf(stdout, "%i",f_BreakoutGamePosix_usedMemory(_instance));
fprintf(stdout, "\n");
exit(0);
}
// Definition of function timestamp
uint32_t f_BreakoutGamePosix_timestamp(struct BreakoutGamePosix_Instance *_instance) {
clock_gettime(CLOCK_REALTIME, &t);
return t.tv_sec*1000 + t.tv_nsec/1000000;
}
// Definition of function usedMemory
uint32_t f_BreakoutGamePosix_usedMemory(struct BreakoutGamePosix_Instance *_instance) {
statm_t result;
		const char* statm_path = "/proc/self/statm";
		FILE *f = fopen(statm_path, "r");
		if (!f) {
return  -1;
}
		if (7 != fscanf(f, "%ld %ld %ld %ld %ld %ld %ld", &result.size, &result.resident, &result.share, &result.text, &result.lib, &result.data, &result.dt)) {
return  -1;
}
return result.size;
}
// Definition of function unsetBit
uint8_t f_BreakoutGamePosix_unsetBit(struct BreakoutGamePosix_Instance *_instance, uint8_t variable, uint8_t bit) {
return (variable & ~(1 << bit));
}

// Sessions functionss:


// On Entry Actions:
void BreakoutGame_SC_OnEntry(int state, struct BreakoutGamePosix_Instance *_instance) {
switch(state) {
case BREAKOUTGAME_SC_STATE:{
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_INIT_STATE;
BreakoutGame_SC_OnEntry(_instance->BreakoutGame_SC_State, _instance);
break;
}
case BREAKOUTGAME_SC_GAMEOVER_STATE:{
f_BreakoutGamePosix_eraseBall(_instance);
f_BreakoutGamePosix_erasePad(_instance);
uint8_t r_224 = 255;
uint8_t g_225 = 255;
uint8_t b_226 = 255;
BreakoutGamePosix_send_display_setColor(_instance, r_224, g_225, b_226);
char * params_227 = "" + ("r=" + (r_224 + ",")) + ("g=" + (g_225 + ",")) + ("b=" + (b_226 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_227);
uint8_t x_228 = 8;
uint8_t y_229 = 30;
uint8_t width_230 = 142;
uint8_t height_231 = 76;
BreakoutGamePosix_send_display_fillRect(_instance, x_228, y_229, width_230, height_231);
char * params_232 = "" + ("x=" + (x_228 + ",")) + ("y=" + (y_229 + ",")) + ("width=" + (width_230 + ",")) + ("height=" + (height_231 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_232);
uint8_t r_233 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_234 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_235 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGamePosix_send_display_setColor(_instance, r_233, g_234, b_235);
char * params_236 = "" + ("r=" + (r_233 + ",")) + ("g=" + (g_234 + ",")) + ("b=" + (b_235 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_236);
uint8_t x_237 = 9;
uint8_t y_238 = 31;
uint8_t width_239 = 140;
uint8_t height_240 = 50;
BreakoutGamePosix_send_display_fillRect(_instance, x_237, y_238, width_239, height_240);
char * params_241 = "" + ("x=" + (x_237 + ",")) + ("y=" + (y_238 + ",")) + ("width=" + (width_239 + ",")) + ("height=" + (height_240 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_241);
uint8_t r_242 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_243 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_244 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGamePosix_send_display_setBGColor(_instance, r_242, g_243, b_244);
char * params_245 = "" + ("r=" + (r_242 + ",")) + ("g=" + (g_243 + ",")) + ("b=" + (b_244 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setBGColor", params_245);
uint8_t r_246 = 158;
uint8_t g_247 = 209;
uint8_t b_248 = 130;
BreakoutGamePosix_send_display_setColor(_instance, r_246, g_247, b_248);
char * params_249 = "" + ("r=" + (r_246 + ",")) + ("g=" + (g_247 + ",")) + ("b=" + (b_248 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_249);
uint8_t x_250 = 23;
uint8_t y_251 = 40;
int16_t v_252 = _instance->BreakoutGame_score_var;
uint8_t digits_253 = 5;
uint8_t scale_254 = 6;
BreakoutGamePosix_send_display_drawInteger(_instance, x_250, y_251, v_252, digits_253, scale_254);
char * params_255 = "" + ("x=" + (x_250 + ",")) + ("y=" + (y_251 + ",")) + ("v=" + (v_252 + ",")) + ("digits=" + (digits_253 + ",")) + ("scale=" + (scale_254 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "drawInteger", params_255);
uint8_t x_256 = 26;
uint8_t y_257 = 87;
BreakoutGamePosix_send_display_drawThingML(_instance, x_256, y_257);
char * params_258 = "" + ("x=" + (x_256 + ",")) + ("y=" + (y_257 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "drawThingML", params_258);
BreakoutGamePosix_send_display_update(_instance);
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "update", "");
f_BreakoutGamePosix_log(_instance, 1);
_instance->BreakoutGame_stopTime_var = f_BreakoutGamePosix_timestamp(_instance);
f_BreakoutGamePosix_quit(_instance);
_instance->active = false;
break;
}
case BREAKOUTGAME_SC_LOSTBALL_STATE:{
uint8_t id_218 = 0;
uint16_t time_219 = _instance->BreakoutGame_period_var;
BreakoutGamePosix_send_clock_timer_start(_instance, id_218, time_219);
char * params_220 = "" + ("id=" + (id_218 + ",")) + ("time=" + (time_219 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "clock", "timer_start", params_220);
char * old_lives_26 = "" + _instance->BreakoutGame_lives_var;
_instance->BreakoutGame_lives_var = _instance->BreakoutGame_lives_var - 1;
char * new_lives_26 = "" + _instance->BreakoutGame_lives_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "lives", "UInt8", old_lives_26, new_lives_26);
f_BreakoutGamePosix_eraseBall(_instance);
f_BreakoutGamePosix_erasePad(_instance);
f_BreakoutGamePosix_drawLives(_instance);
BreakoutGamePosix_send_display_update(_instance);
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "update", "");
f_BreakoutGamePosix_log(_instance, 1);
break;
}
case BREAKOUTGAME_SC_INIT_STATE:{
_instance->BreakoutGame_startTime_var = f_BreakoutGamePosix_timestamp(_instance);
uint8_t xsize_172 = _instance->BreakoutGame_XDISPSIZE_var;
uint8_t ysize_173 = _instance->BreakoutGame_YDISPSIZE_var;
BreakoutGamePosix_send_display_create(_instance, xsize_172, ysize_173);
char * params_174 = "" + ("xsize=" + (xsize_172 + ",")) + ("ysize=" + (ysize_173 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "create", params_174);
break;
}
case BREAKOUTGAME_SC_LAUNCH_STATE:{
uint8_t id_193 = 0;
uint16_t time_194 = _instance->BreakoutGame_period_var;
BreakoutGamePosix_send_clock_timer_start(_instance, id_193, time_194);
char * params_195 = "" + ("id=" + (id_193 + ",")) + ("time=" + (time_194 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "clock", "timer_start", params_195);
char * old_countdown_27 = "" + _instance->BreakoutGame_SC_LAUNCH_countdown_var;
_instance->BreakoutGame_SC_LAUNCH_countdown_var = 3;
char * new_countdown_27 = "" + _instance->BreakoutGame_SC_LAUNCH_countdown_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "countdown", "UInt8", old_countdown_27, new_countdown_27);
f_BreakoutGamePosix_drawScore(_instance);
f_BreakoutGamePosix_drawLives(_instance);
BreakoutGamePosix_send_display_update(_instance);
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "update", "");
break;
}
case BREAKOUTGAME_SC_PLAY_STATE:{
uint8_t id_199 = 0;
uint16_t time_200 = _instance->BreakoutGame_period_var;
BreakoutGamePosix_send_clock_timer_start(_instance, id_199, time_200);
char * params_201 = "" + ("id=" + (id_199 + ",")) + ("time=" + (time_200 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "clock", "timer_start", params_201);
break;
}
case BREAKOUTGAME_SC_NEXTLEVEL_STATE:{
uint8_t id_221 = 0;
uint16_t time_222 = _instance->BreakoutGame_period_var;
BreakoutGamePosix_send_clock_timer_start(_instance, id_221, time_222);
char * params_223 = "" + ("id=" + (id_221 + ",")) + ("time=" + (time_222 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "clock", "timer_start", params_223);
char * old_level_12 = "" + _instance->BreakoutGame_level_var;
_instance->BreakoutGame_level_var = _instance->BreakoutGame_level_var + 1;
char * new_level_12 = "" + _instance->BreakoutGame_level_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "level", "UInt8", old_level_12, new_level_12);
f_BreakoutGamePosix_drawLevel(_instance);
f_BreakoutGamePosix_eraseBall(_instance);
f_BreakoutGamePosix_erasePad(_instance);
if((_instance->BreakoutGame_level_var % 2) == 0 && _instance->BreakoutGame_padlen_var > 5 * _instance->BreakoutGame_SCALE_var) {
char * old_padlen_4 = "" + _instance->BreakoutGame_padlen_var;
_instance->BreakoutGame_padlen_var = _instance->BreakoutGame_padlen_var - (4 * _instance->BreakoutGame_SCALE_var);
char * new_padlen_4 = "" + _instance->BreakoutGame_padlen_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "padlen", "Int16", old_padlen_4, new_padlen_4);

}
if((_instance->BreakoutGame_level_var % 2) == 1) {
char * old_dy_17 = "" + _instance->BreakoutGame_dy_var;
_instance->BreakoutGame_dy_var = (_instance->BreakoutGame_dy_var * 3) / 2;
char * new_dy_17 = "" + _instance->BreakoutGame_dy_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "dy", "Int16", old_dy_17, new_dy_17);

}
f_BreakoutGamePosix_drawLives(_instance);
f_BreakoutGamePosix_createBricks(_instance);
BreakoutGamePosix_send_display_update(_instance);
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "update", "");
break;
}
default: break;
}
}

// On Exit Actions:
void BreakoutGame_SC_OnExit(int state, struct BreakoutGamePosix_Instance *_instance) {
switch(state) {
case BREAKOUTGAME_SC_STATE:{
BreakoutGame_SC_OnExit(_instance->BreakoutGame_SC_State, _instance);
break;}
case BREAKOUTGAME_SC_GAMEOVER_STATE:{
break;}
case BREAKOUTGAME_SC_LOSTBALL_STATE:{
break;}
case BREAKOUTGAME_SC_INIT_STATE:{
break;}
case BREAKOUTGAME_SC_LAUNCH_STATE:{
break;}
case BREAKOUTGAME_SC_PLAY_STATE:{
break;}
case BREAKOUTGAME_SC_NEXTLEVEL_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void BreakoutGamePosix_handle_display_displayReady(struct BreakoutGamePosix_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_INIT_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && 1) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_INIT_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_LAUNCH_STATE;
BreakoutGamePosix_send_log_message_handled(_instance, _instance->WithLog_DEBUG_ID_var, "SC.INIT", "SC.LAUNCH", "display", "displayReady", "_");
BreakoutGamePosix_send_display_clear(_instance);
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "clear", "");
f_BreakoutGamePosix_initColors(_instance);
uint8_t r_175 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_176 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_177 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGamePosix_send_display_setColor(_instance, r_175, g_176, b_177);
char * params_178 = "" + ("r=" + (r_175 + ",")) + ("g=" + (g_176 + ",")) + ("b=" + (b_177 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_178);
uint8_t x_179 = 0;
uint8_t y_180 = 0;
uint8_t width_181 = _instance->BreakoutGame_XDISPSIZE_var;
uint8_t height_182 = _instance->BreakoutGame_YDISPSIZE_var;
BreakoutGamePosix_send_display_fillRect(_instance, x_179, y_180, width_181, height_182);
char * params_183 = "" + ("x=" + (x_179 + ",")) + ("y=" + (y_180 + ",")) + ("width=" + (width_181 + ",")) + ("height=" + (height_182 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_183);
uint8_t r_184 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_185 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_186 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGamePosix_send_display_setColor(_instance, r_184, g_185, b_186);
char * params_187 = "" + ("r=" + (r_184 + ",")) + ("g=" + (g_185 + ",")) + ("b=" + (b_186 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "setColor", params_187);
uint8_t x_188 = 0;
uint8_t y_189 = 0;
uint8_t width_190 = _instance->BreakoutGame_XDISPSIZE_var;
uint8_t height_191 = 14;
BreakoutGamePosix_send_display_fillRect(_instance, x_188, y_189, width_190, height_191);
char * params_192 = "" + ("x=" + (x_188 + ",")) + ("y=" + (y_189 + ",")) + ("width=" + (width_190 + ",")) + ("height=" + (height_191 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "fillRect", params_192);
f_BreakoutGamePosix_drawWalls(_instance);
f_BreakoutGamePosix_createBricks(_instance);
f_BreakoutGamePosix_drawLevel(_instance);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_LAUNCH_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
BreakoutGamePosix_send_log_message_lost(_instance, _instance->WithLog_DEBUG_ID_var, "display", "displayReady", "");
BreakoutGame_SC_State_event_consumed = 1;
}
}
void BreakoutGamePosix_handle_game_lostBall(struct BreakoutGamePosix_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_PLAY_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && 1) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_PLAY_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_LOSTBALL_STATE;
BreakoutGamePosix_send_log_message_handled(_instance, _instance->WithLog_DEBUG_ID_var, "SC.PLAY", "SC.LOSTBALL", "game", "lostBall", "_");
uint8_t id_210 = 0;
BreakoutGamePosix_send_clock_timer_cancel(_instance, id_210);
char * params_211 = "" + ("id=" + (id_210 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "clock", "timer_cancel", params_211);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_LOSTBALL_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
BreakoutGamePosix_send_log_message_lost(_instance, _instance->WithLog_DEBUG_ID_var, "game", "lostBall", "");
BreakoutGame_SC_State_event_consumed = 1;
}
}
void BreakoutGamePosix_handle_game_nextLevel(struct BreakoutGamePosix_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_PLAY_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && 1) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_PLAY_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_NEXTLEVEL_STATE;
BreakoutGamePosix_send_log_message_handled(_instance, _instance->WithLog_DEBUG_ID_var, "SC.PLAY", "SC.NEXTLEVEL", "game", "nextLevel", "_");
uint8_t id_212 = 0;
BreakoutGamePosix_send_clock_timer_cancel(_instance, id_212);
char * params_213 = "" + ("id=" + (id_212 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "clock", "timer_cancel", params_213);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_NEXTLEVEL_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
BreakoutGamePosix_send_log_message_lost(_instance, _instance->WithLog_DEBUG_ID_var, "game", "nextLevel", "");
BreakoutGame_SC_State_event_consumed = 1;
}
}
void BreakoutGamePosix_handle_controller_position(struct BreakoutGamePosix_Instance *_instance, int16_t x, int16_t y) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
char * params = "" + ("x=" + (x + ",")) + ("y=" + (y + ","));
BreakoutGamePosix_send_log_message_handled(_instance, _instance->WithLog_DEBUG_ID_var, "SC", "_", "controller", "position", params);
int32_t center = (_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var - _instance->BreakoutGame_padlen_var);
center = x * center;
center = center / 200;
char * old_padx_29 = "" + _instance->BreakoutGame_padx_var;
_instance->BreakoutGame_padx_var = (_instance->BreakoutGame_LEFT_var + center + (_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 2);
char * new_padx_29 = "" + _instance->BreakoutGame_padx_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "padx", "Int16", old_padx_29, new_padx_29);
BreakoutGame_SC_State_event_consumed = 1;
}
}
void BreakoutGamePosix_handle_pro_game_lostBall(struct BreakoutGamePosix_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_PLAY_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && 1) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_PLAY_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_LOSTBALL_STATE;
BreakoutGamePosix_send_log_message_handled(_instance, _instance->WithLog_DEBUG_ID_var, "SC.PLAY", "SC.LOSTBALL", "pro_game", "lostBall", "_");
uint8_t id_214 = 0;
BreakoutGamePosix_send_clock_timer_cancel(_instance, id_214);
char * params_215 = "" + ("id=" + (id_214 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "clock", "timer_cancel", params_215);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_LOSTBALL_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
BreakoutGamePosix_send_log_message_lost(_instance, _instance->WithLog_DEBUG_ID_var, "pro_game", "lostBall", "");
BreakoutGame_SC_State_event_consumed = 1;
}
}
void BreakoutGamePosix_handle_pro_game_nextLevel(struct BreakoutGamePosix_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_PLAY_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && 1) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_PLAY_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_NEXTLEVEL_STATE;
BreakoutGamePosix_send_log_message_handled(_instance, _instance->WithLog_DEBUG_ID_var, "SC.PLAY", "SC.NEXTLEVEL", "pro_game", "nextLevel", "_");
uint8_t id_216 = 0;
BreakoutGamePosix_send_clock_timer_cancel(_instance, id_216);
char * params_217 = "" + ("id=" + (id_216 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "clock", "timer_cancel", params_217);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_NEXTLEVEL_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
BreakoutGamePosix_send_log_message_lost(_instance, _instance->WithLog_DEBUG_ID_var, "pro_game", "nextLevel", "");
BreakoutGame_SC_State_event_consumed = 1;
}
}
void BreakoutGamePosix_handle_clock_timer_timeout(struct BreakoutGamePosix_Instance *_instance, uint8_t id) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_LAUNCH_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && id == 0 && _instance->BreakoutGame_SC_LAUNCH_countdown_var == 0) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_LAUNCH_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_PLAY_STATE;
char * params = "" + ("id=" + (id + ","));
BreakoutGamePosix_send_log_message_handled(_instance, _instance->WithLog_DEBUG_ID_var, "SC.LAUNCH", "SC.PLAY", "clock", "timer_timeout", params);
f_BreakoutGamePosix_drawCountDown(_instance, 0);
f_BreakoutGamePosix_resetBall(_instance);
BreakoutGamePosix_send_display_update(_instance);
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "update", "");
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_PLAY_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
else if (BreakoutGame_SC_State_event_consumed == 0 && id == 0 && _instance->BreakoutGame_SC_LAUNCH_countdown_var > 0) {
char * params = "" + ("id=" + (id + ","));
BreakoutGamePosix_send_log_message_handled(_instance, _instance->WithLog_DEBUG_ID_var, "SC.LAUNCH", "_", "clock", "timer_timeout", params);
uint8_t id_196 = 0;
uint16_t time_197 = _instance->BreakoutGame_period_var;
BreakoutGamePosix_send_clock_timer_start(_instance, id_196, time_197);
char * params_198 = "" + ("id=" + (id_196 + ",")) + ("time=" + (time_197 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "clock", "timer_start", params_198);
f_BreakoutGamePosix_drawPad(_instance);
if((_instance->BreakoutGame_SC_LAUNCH_countdown_var % 30) == 0) {
f_BreakoutGamePosix_drawCountDown(_instance, _instance->BreakoutGame_SC_LAUNCH_countdown_var / 30);

}
char * old_countdown_28 = "" + _instance->BreakoutGame_SC_LAUNCH_countdown_var;
_instance->BreakoutGame_SC_LAUNCH_countdown_var = _instance->BreakoutGame_SC_LAUNCH_countdown_var - 1;
char * new_countdown_28 = "" + _instance->BreakoutGame_SC_LAUNCH_countdown_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "countdown", "UInt8", old_countdown_28, new_countdown_28);
BreakoutGamePosix_send_display_update(_instance);
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "update", "");
BreakoutGame_SC_State_event_consumed = 1;
}
}
else if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_PLAY_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && id == 0) {
char * params = "" + ("id=" + (id + ","));
BreakoutGamePosix_send_log_message_handled(_instance, _instance->WithLog_DEBUG_ID_var, "SC.PLAY", "_", "clock", "timer_timeout", params);
char * old_bx_1 = "" + _instance->BreakoutGame_bx_var;
_instance->BreakoutGame_bx_var = _instance->BreakoutGame_bx_var + _instance->BreakoutGame_dx_var;
char * new_bx_1 = "" + _instance->BreakoutGame_bx_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "bx", "Int16", old_bx_1, new_bx_1);
char * old_by_9 = "" + _instance->BreakoutGame_by_var;
_instance->BreakoutGame_by_var = _instance->BreakoutGame_by_var + _instance->BreakoutGame_dy_var;
char * new_by_9 = "" + _instance->BreakoutGame_by_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "by", "Int16", old_by_9, new_by_9);
int16_t wl = _instance->BreakoutGame_LEFT_var + _instance->BreakoutGame_br_var;
int16_t wr = _instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_br_var;
int16_t wt = _instance->BreakoutGame_TOP_var + _instance->BreakoutGame_br_var;
int16_t wb = _instance->BreakoutGame_BOTTOM_var - _instance->BreakoutGame_br_var;
if(_instance->BreakoutGame_bx_var < wl) {
char * old_dx_22 = "" + _instance->BreakoutGame_dx_var;
_instance->BreakoutGame_dx_var =  -_instance->BreakoutGame_dx_var;
char * new_dx_22 = "" + _instance->BreakoutGame_dx_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "dx", "Int16", old_dx_22, new_dx_22);
char * old_bx_2 = "" + _instance->BreakoutGame_bx_var;
_instance->BreakoutGame_bx_var = 2 * wl - _instance->BreakoutGame_bx_var;
char * new_bx_2 = "" + _instance->BreakoutGame_bx_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "bx", "Int16", old_bx_2, new_bx_2);
f_BreakoutGamePosix_incrementScore(_instance,  -1);

} else {
if(_instance->BreakoutGame_bx_var > wr) {
char * old_dx_23 = "" + _instance->BreakoutGame_dx_var;
_instance->BreakoutGame_dx_var =  -_instance->BreakoutGame_dx_var;
char * new_dx_23 = "" + _instance->BreakoutGame_dx_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "dx", "Int16", old_dx_23, new_dx_23);
char * old_bx_3 = "" + _instance->BreakoutGame_bx_var;
_instance->BreakoutGame_bx_var = 2 * wr - _instance->BreakoutGame_bx_var;
char * new_bx_3 = "" + _instance->BreakoutGame_bx_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "bx", "Int16", old_bx_3, new_bx_3);
f_BreakoutGamePosix_incrementScore(_instance,  -1);

}

}
if(_instance->BreakoutGame_by_var < wt) {
char * old_dy_14 = "" + _instance->BreakoutGame_dy_var;
_instance->BreakoutGame_dy_var =  -_instance->BreakoutGame_dy_var;
char * new_dy_14 = "" + _instance->BreakoutGame_dy_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "dy", "Int16", old_dy_14, new_dy_14);
char * old_by_10 = "" + _instance->BreakoutGame_by_var;
_instance->BreakoutGame_by_var = 2 * wt - _instance->BreakoutGame_by_var;
char * new_by_10 = "" + _instance->BreakoutGame_by_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "by", "Int16", old_by_10, new_by_10);
f_BreakoutGamePosix_incrementScore(_instance,  -1);

} else {
if(_instance->BreakoutGame_by_var > wb) {
BreakoutGamePosix_send_game_lostBall(_instance);
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "game", "lostBall", "");
BreakoutGamePosix_send_req_game_lostBall(_instance);
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "req_game", "lostBall", "");

}

}
if(_instance->BreakoutGame_dy_var > 0) {
if(_instance->BreakoutGame_by_var > _instance->BreakoutGame_pady_var - _instance->BreakoutGame_br_var && _instance->BreakoutGame_by_var < _instance->BreakoutGame_pady_var + _instance->BreakoutGame_br_var) {
if(_instance->BreakoutGame_bx_var > _instance->BreakoutGame_padx_var - _instance->BreakoutGame_padlen_var / 2 && _instance->BreakoutGame_bx_var < _instance->BreakoutGame_padx_var + _instance->BreakoutGame_padlen_var / 2) {
char * old_dy_15 = "" + _instance->BreakoutGame_dy_var;
_instance->BreakoutGame_dy_var =  -_instance->BreakoutGame_dy_var;
char * new_dy_15 = "" + _instance->BreakoutGame_dy_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "dy", "Int16", old_dy_15, new_dy_15);
char * old_by_11 = "" + _instance->BreakoutGame_by_var;
_instance->BreakoutGame_by_var = 2 * (_instance->BreakoutGame_pady_var - _instance->BreakoutGame_br_var) - _instance->BreakoutGame_by_var;
char * new_by_11 = "" + _instance->BreakoutGame_by_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "by", "Int16", old_by_11, new_by_11);
char * old_dx_24 = "" + _instance->BreakoutGame_dx_var;
_instance->BreakoutGame_dx_var = _instance->BreakoutGame_dx_var / 4 + (_instance->BreakoutGame_bx_var - _instance->BreakoutGame_padx_var) / 4;
char * new_dx_24 = "" + _instance->BreakoutGame_dx_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "dx", "Int16", old_dx_24, new_dx_24);

}

}

}
bool collision = f_BreakoutGamePosix_collideBrick(_instance, _instance->BreakoutGame_bx_var - _instance->BreakoutGame_br_var, _instance->BreakoutGame_by_var - _instance->BreakoutGame_br_var) || f_BreakoutGamePosix_collideBrick(_instance, _instance->BreakoutGame_bx_var + _instance->BreakoutGame_br_var, _instance->BreakoutGame_by_var - _instance->BreakoutGame_br_var) || f_BreakoutGamePosix_collideBrick(_instance, _instance->BreakoutGame_bx_var + _instance->BreakoutGame_br_var, _instance->BreakoutGame_by_var + _instance->BreakoutGame_br_var) || f_BreakoutGamePosix_collideBrick(_instance, _instance->BreakoutGame_bx_var - _instance->BreakoutGame_br_var, _instance->BreakoutGame_by_var + _instance->BreakoutGame_br_var);
if(collision) {
char * old_dy_16 = "" + _instance->BreakoutGame_dy_var;
_instance->BreakoutGame_dy_var =  -_instance->BreakoutGame_dy_var;
char * new_dy_16 = "" + _instance->BreakoutGame_dy_var;
BreakoutGamePosix_send_log_property_changed(_instance, _instance->WithLog_DEBUG_ID_var, "dy", "Int16", old_dy_16, new_dy_16);
f_BreakoutGamePosix_incrementScore(_instance, 10);
if(f_BreakoutGamePosix_bricksLeft(_instance) == 0) {
BreakoutGamePosix_send_game_nextLevel(_instance);
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "game", "nextLevel", "");
BreakoutGamePosix_send_req_game_nextLevel(_instance);
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "req_game", "nextLevel", "");

}

}
f_BreakoutGamePosix_drawBall(_instance);
f_BreakoutGamePosix_drawPad(_instance);
int16_t ballx_202 = _instance->BreakoutGame_bx_var;
int16_t bally_203 = _instance->BreakoutGame_by_var;
int16_t padx_204 = _instance->BreakoutGame_padx_var;
int16_t pady_205 = _instance->BreakoutGame_pady_var;
BreakoutGamePosix_send_ia_updateIA(_instance, ballx_202, bally_203, padx_204, pady_205);
char * params_206 = "" + ("ballx=" + (ballx_202 + ",")) + ("bally=" + (bally_203 + ",")) + ("padx=" + (padx_204 + ",")) + ("pady=" + (pady_205 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "ia", "updateIA", params_206);
BreakoutGamePosix_send_display_update(_instance);
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "display", "update", "");
f_BreakoutGamePosix_log(_instance, 0);
uint8_t id_207 = 0;
uint16_t time_208 = _instance->BreakoutGame_period_var;
BreakoutGamePosix_send_clock_timer_start(_instance, id_207, time_208);
char * params_209 = "" + ("id=" + (id_207 + ",")) + ("time=" + (time_208 + ","));
BreakoutGamePosix_send_log_message_sent(_instance, _instance->WithLog_DEBUG_ID_var, "clock", "timer_start", params_209);
BreakoutGame_SC_State_event_consumed = 1;
}
}
else if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_LOSTBALL_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && id == 0 && _instance->BreakoutGame_lives_var > 0) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_LOSTBALL_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_LAUNCH_STATE;
char * params = "" + ("id=" + (id + ","));
BreakoutGamePosix_send_log_message_handled(_instance, _instance->WithLog_DEBUG_ID_var, "SC.LOSTBALL", "SC.LAUNCH", "clock", "timer_timeout", params);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_LAUNCH_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
else if (BreakoutGame_SC_State_event_consumed == 0 && id == 0 && _instance->BreakoutGame_lives_var == 0) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_LOSTBALL_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_GAMEOVER_STATE;
char * params = "" + ("id=" + (id + ","));
BreakoutGamePosix_send_log_message_handled(_instance, _instance->WithLog_DEBUG_ID_var, "SC.LOSTBALL", "SC.GAMEOVER", "clock", "timer_timeout", params);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_GAMEOVER_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
else if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_NEXTLEVEL_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && id == 0) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_NEXTLEVEL_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_LAUNCH_STATE;
char * params = "" + ("id=" + (id + ","));
BreakoutGamePosix_send_log_message_handled(_instance, _instance->WithLog_DEBUG_ID_var, "SC.NEXTLEVEL", "SC.LAUNCH", "clock", "timer_timeout", params);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_LAUNCH_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
char * params = "" + ("id=" + (id + ","));
BreakoutGamePosix_send_log_message_lost(_instance, _instance->WithLog_DEBUG_ID_var, "clock", "timer_timeout", params);
BreakoutGame_SC_State_event_consumed = 1;
}
}

// Observers for outgoing messages:
void (*external_BreakoutGamePosix_send_log_function_called_listener)(struct BreakoutGamePosix_Instance *, char *, char *, char *, char *, char *)= 0x0;
void (*BreakoutGamePosix_send_log_function_called_listener)(struct BreakoutGamePosix_Instance *, char *, char *, char *, char *, char *)= 0x0;
void register_external_BreakoutGamePosix_send_log_function_called_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, char *, char *, char *, char *, char *)){
external_BreakoutGamePosix_send_log_function_called_listener = _listener;
}
void register_BreakoutGamePosix_send_log_function_called_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, char *, char *, char *, char *, char *)){
BreakoutGamePosix_send_log_function_called_listener = _listener;
}
void BreakoutGamePosix_send_log_function_called(struct BreakoutGamePosix_Instance *_instance, char * inst, char * fn_name, char * ty, char * returns, char * params){
if (BreakoutGamePosix_send_log_function_called_listener != 0x0) BreakoutGamePosix_send_log_function_called_listener(_instance, inst, fn_name, ty, returns, params);
if (external_BreakoutGamePosix_send_log_function_called_listener != 0x0) external_BreakoutGamePosix_send_log_function_called_listener(_instance, inst, fn_name, ty, returns, params);
;
}
void (*external_BreakoutGamePosix_send_log_property_changed_listener)(struct BreakoutGamePosix_Instance *, char *, char *, char *, char *, char *)= 0x0;
void (*BreakoutGamePosix_send_log_property_changed_listener)(struct BreakoutGamePosix_Instance *, char *, char *, char *, char *, char *)= 0x0;
void register_external_BreakoutGamePosix_send_log_property_changed_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, char *, char *, char *, char *, char *)){
external_BreakoutGamePosix_send_log_property_changed_listener = _listener;
}
void register_BreakoutGamePosix_send_log_property_changed_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, char *, char *, char *, char *, char *)){
BreakoutGamePosix_send_log_property_changed_listener = _listener;
}
void BreakoutGamePosix_send_log_property_changed(struct BreakoutGamePosix_Instance *_instance, char * inst, char * prop_name, char * ty, char * old_value, char * new_value){
if (BreakoutGamePosix_send_log_property_changed_listener != 0x0) BreakoutGamePosix_send_log_property_changed_listener(_instance, inst, prop_name, ty, old_value, new_value);
if (external_BreakoutGamePosix_send_log_property_changed_listener != 0x0) external_BreakoutGamePosix_send_log_property_changed_listener(_instance, inst, prop_name, ty, old_value, new_value);
;
}
void (*external_BreakoutGamePosix_send_log_message_lost_listener)(struct BreakoutGamePosix_Instance *, char *, char *, char *, char *)= 0x0;
void (*BreakoutGamePosix_send_log_message_lost_listener)(struct BreakoutGamePosix_Instance *, char *, char *, char *, char *)= 0x0;
void register_external_BreakoutGamePosix_send_log_message_lost_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, char *, char *, char *, char *)){
external_BreakoutGamePosix_send_log_message_lost_listener = _listener;
}
void register_BreakoutGamePosix_send_log_message_lost_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, char *, char *, char *, char *)){
BreakoutGamePosix_send_log_message_lost_listener = _listener;
}
void BreakoutGamePosix_send_log_message_lost(struct BreakoutGamePosix_Instance *_instance, char * inst, char * port_name, char * msg_name, char * params){
if (BreakoutGamePosix_send_log_message_lost_listener != 0x0) BreakoutGamePosix_send_log_message_lost_listener(_instance, inst, port_name, msg_name, params);
if (external_BreakoutGamePosix_send_log_message_lost_listener != 0x0) external_BreakoutGamePosix_send_log_message_lost_listener(_instance, inst, port_name, msg_name, params);
;
}
void (*external_BreakoutGamePosix_send_log_message_handled_listener)(struct BreakoutGamePosix_Instance *, char *, char *, char *, char *, char *, char *)= 0x0;
void (*BreakoutGamePosix_send_log_message_handled_listener)(struct BreakoutGamePosix_Instance *, char *, char *, char *, char *, char *, char *)= 0x0;
void register_external_BreakoutGamePosix_send_log_message_handled_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, char *, char *, char *, char *, char *, char *)){
external_BreakoutGamePosix_send_log_message_handled_listener = _listener;
}
void register_BreakoutGamePosix_send_log_message_handled_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, char *, char *, char *, char *, char *, char *)){
BreakoutGamePosix_send_log_message_handled_listener = _listener;
}
void BreakoutGamePosix_send_log_message_handled(struct BreakoutGamePosix_Instance *_instance, char * inst, char * source, char * target, char * port_name, char * msg_name, char * params){
if (BreakoutGamePosix_send_log_message_handled_listener != 0x0) BreakoutGamePosix_send_log_message_handled_listener(_instance, inst, source, target, port_name, msg_name, params);
if (external_BreakoutGamePosix_send_log_message_handled_listener != 0x0) external_BreakoutGamePosix_send_log_message_handled_listener(_instance, inst, source, target, port_name, msg_name, params);
;
}
void (*external_BreakoutGamePosix_send_log_message_sent_listener)(struct BreakoutGamePosix_Instance *, char *, char *, char *, char *)= 0x0;
void (*BreakoutGamePosix_send_log_message_sent_listener)(struct BreakoutGamePosix_Instance *, char *, char *, char *, char *)= 0x0;
void register_external_BreakoutGamePosix_send_log_message_sent_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, char *, char *, char *, char *)){
external_BreakoutGamePosix_send_log_message_sent_listener = _listener;
}
void register_BreakoutGamePosix_send_log_message_sent_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, char *, char *, char *, char *)){
BreakoutGamePosix_send_log_message_sent_listener = _listener;
}
void BreakoutGamePosix_send_log_message_sent(struct BreakoutGamePosix_Instance *_instance, char * inst, char * port_name, char * msg_name, char * params){
if (BreakoutGamePosix_send_log_message_sent_listener != 0x0) BreakoutGamePosix_send_log_message_sent_listener(_instance, inst, port_name, msg_name, params);
if (external_BreakoutGamePosix_send_log_message_sent_listener != 0x0) external_BreakoutGamePosix_send_log_message_sent_listener(_instance, inst, port_name, msg_name, params);
;
}
void (*external_BreakoutGamePosix_send_clock_timer_start_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint16_t)= 0x0;
void (*BreakoutGamePosix_send_clock_timer_start_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint16_t)= 0x0;
void register_external_BreakoutGamePosix_send_clock_timer_start_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint16_t)){
external_BreakoutGamePosix_send_clock_timer_start_listener = _listener;
}
void register_BreakoutGamePosix_send_clock_timer_start_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint16_t)){
BreakoutGamePosix_send_clock_timer_start_listener = _listener;
}
void BreakoutGamePosix_send_clock_timer_start(struct BreakoutGamePosix_Instance *_instance, uint8_t id, uint16_t time){
if (BreakoutGamePosix_send_clock_timer_start_listener != 0x0) BreakoutGamePosix_send_clock_timer_start_listener(_instance, id, time);
if (external_BreakoutGamePosix_send_clock_timer_start_listener != 0x0) external_BreakoutGamePosix_send_clock_timer_start_listener(_instance, id, time);
;
}
void (*external_BreakoutGamePosix_send_clock_timer_cancel_listener)(struct BreakoutGamePosix_Instance *, uint8_t)= 0x0;
void (*BreakoutGamePosix_send_clock_timer_cancel_listener)(struct BreakoutGamePosix_Instance *, uint8_t)= 0x0;
void register_external_BreakoutGamePosix_send_clock_timer_cancel_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t)){
external_BreakoutGamePosix_send_clock_timer_cancel_listener = _listener;
}
void register_BreakoutGamePosix_send_clock_timer_cancel_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t)){
BreakoutGamePosix_send_clock_timer_cancel_listener = _listener;
}
void BreakoutGamePosix_send_clock_timer_cancel(struct BreakoutGamePosix_Instance *_instance, uint8_t id){
if (BreakoutGamePosix_send_clock_timer_cancel_listener != 0x0) BreakoutGamePosix_send_clock_timer_cancel_listener(_instance, id);
if (external_BreakoutGamePosix_send_clock_timer_cancel_listener != 0x0) external_BreakoutGamePosix_send_clock_timer_cancel_listener(_instance, id);
;
}
void (*external_BreakoutGamePosix_send_display_create_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t)= 0x0;
void (*BreakoutGamePosix_send_display_create_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t)= 0x0;
void register_external_BreakoutGamePosix_send_display_create_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t)){
external_BreakoutGamePosix_send_display_create_listener = _listener;
}
void register_BreakoutGamePosix_send_display_create_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t)){
BreakoutGamePosix_send_display_create_listener = _listener;
}
void BreakoutGamePosix_send_display_create(struct BreakoutGamePosix_Instance *_instance, uint8_t xsize, uint8_t ysize){
if (BreakoutGamePosix_send_display_create_listener != 0x0) BreakoutGamePosix_send_display_create_listener(_instance, xsize, ysize);
if (external_BreakoutGamePosix_send_display_create_listener != 0x0) external_BreakoutGamePosix_send_display_create_listener(_instance, xsize, ysize);
;
}
void (*external_BreakoutGamePosix_send_display_fillRect_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)= 0x0;
void (*BreakoutGamePosix_send_display_fillRect_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_BreakoutGamePosix_send_display_fillRect_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)){
external_BreakoutGamePosix_send_display_fillRect_listener = _listener;
}
void register_BreakoutGamePosix_send_display_fillRect_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)){
BreakoutGamePosix_send_display_fillRect_listener = _listener;
}
void BreakoutGamePosix_send_display_fillRect(struct BreakoutGamePosix_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height){
if (BreakoutGamePosix_send_display_fillRect_listener != 0x0) BreakoutGamePosix_send_display_fillRect_listener(_instance, x, y, width, height);
if (external_BreakoutGamePosix_send_display_fillRect_listener != 0x0) external_BreakoutGamePosix_send_display_fillRect_listener(_instance, x, y, width, height);
;
}
void (*external_BreakoutGamePosix_send_display_drawRect_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)= 0x0;
void (*BreakoutGamePosix_send_display_drawRect_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_BreakoutGamePosix_send_display_drawRect_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)){
external_BreakoutGamePosix_send_display_drawRect_listener = _listener;
}
void register_BreakoutGamePosix_send_display_drawRect_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)){
BreakoutGamePosix_send_display_drawRect_listener = _listener;
}
void BreakoutGamePosix_send_display_drawRect(struct BreakoutGamePosix_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height){
if (BreakoutGamePosix_send_display_drawRect_listener != 0x0) BreakoutGamePosix_send_display_drawRect_listener(_instance, x, y, width, height);
if (external_BreakoutGamePosix_send_display_drawRect_listener != 0x0) external_BreakoutGamePosix_send_display_drawRect_listener(_instance, x, y, width, height);
;
}
void (*external_BreakoutGamePosix_send_display_clear_listener)(struct BreakoutGamePosix_Instance *)= 0x0;
void (*BreakoutGamePosix_send_display_clear_listener)(struct BreakoutGamePosix_Instance *)= 0x0;
void register_external_BreakoutGamePosix_send_display_clear_listener(void (*_listener)(struct BreakoutGamePosix_Instance *)){
external_BreakoutGamePosix_send_display_clear_listener = _listener;
}
void register_BreakoutGamePosix_send_display_clear_listener(void (*_listener)(struct BreakoutGamePosix_Instance *)){
BreakoutGamePosix_send_display_clear_listener = _listener;
}
void BreakoutGamePosix_send_display_clear(struct BreakoutGamePosix_Instance *_instance){
if (BreakoutGamePosix_send_display_clear_listener != 0x0) BreakoutGamePosix_send_display_clear_listener(_instance);
if (external_BreakoutGamePosix_send_display_clear_listener != 0x0) external_BreakoutGamePosix_send_display_clear_listener(_instance);
;
}
void (*external_BreakoutGamePosix_send_display_setColor_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void (*BreakoutGamePosix_send_display_setColor_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_BreakoutGamePosix_send_display_setColor_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, uint8_t)){
external_BreakoutGamePosix_send_display_setColor_listener = _listener;
}
void register_BreakoutGamePosix_send_display_setColor_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, uint8_t)){
BreakoutGamePosix_send_display_setColor_listener = _listener;
}
void BreakoutGamePosix_send_display_setColor(struct BreakoutGamePosix_Instance *_instance, uint8_t r, uint8_t g, uint8_t b){
if (BreakoutGamePosix_send_display_setColor_listener != 0x0) BreakoutGamePosix_send_display_setColor_listener(_instance, r, g, b);
if (external_BreakoutGamePosix_send_display_setColor_listener != 0x0) external_BreakoutGamePosix_send_display_setColor_listener(_instance, r, g, b);
;
}
void (*external_BreakoutGamePosix_send_display_setBGColor_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void (*BreakoutGamePosix_send_display_setBGColor_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_BreakoutGamePosix_send_display_setBGColor_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, uint8_t)){
external_BreakoutGamePosix_send_display_setBGColor_listener = _listener;
}
void register_BreakoutGamePosix_send_display_setBGColor_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, uint8_t)){
BreakoutGamePosix_send_display_setBGColor_listener = _listener;
}
void BreakoutGamePosix_send_display_setBGColor(struct BreakoutGamePosix_Instance *_instance, uint8_t r, uint8_t g, uint8_t b){
if (BreakoutGamePosix_send_display_setBGColor_listener != 0x0) BreakoutGamePosix_send_display_setBGColor_listener(_instance, r, g, b);
if (external_BreakoutGamePosix_send_display_setBGColor_listener != 0x0) external_BreakoutGamePosix_send_display_setBGColor_listener(_instance, r, g, b);
;
}
void (*external_BreakoutGamePosix_send_display_drawInteger_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, int16_t, uint8_t, uint8_t)= 0x0;
void (*BreakoutGamePosix_send_display_drawInteger_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, int16_t, uint8_t, uint8_t)= 0x0;
void register_external_BreakoutGamePosix_send_display_drawInteger_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, int16_t, uint8_t, uint8_t)){
external_BreakoutGamePosix_send_display_drawInteger_listener = _listener;
}
void register_BreakoutGamePosix_send_display_drawInteger_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t, int16_t, uint8_t, uint8_t)){
BreakoutGamePosix_send_display_drawInteger_listener = _listener;
}
void BreakoutGamePosix_send_display_drawInteger(struct BreakoutGamePosix_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale){
if (BreakoutGamePosix_send_display_drawInteger_listener != 0x0) BreakoutGamePosix_send_display_drawInteger_listener(_instance, x, y, v, digits, scale);
if (external_BreakoutGamePosix_send_display_drawInteger_listener != 0x0) external_BreakoutGamePosix_send_display_drawInteger_listener(_instance, x, y, v, digits, scale);
;
}
void (*external_BreakoutGamePosix_send_display_update_listener)(struct BreakoutGamePosix_Instance *)= 0x0;
void (*BreakoutGamePosix_send_display_update_listener)(struct BreakoutGamePosix_Instance *)= 0x0;
void register_external_BreakoutGamePosix_send_display_update_listener(void (*_listener)(struct BreakoutGamePosix_Instance *)){
external_BreakoutGamePosix_send_display_update_listener = _listener;
}
void register_BreakoutGamePosix_send_display_update_listener(void (*_listener)(struct BreakoutGamePosix_Instance *)){
BreakoutGamePosix_send_display_update_listener = _listener;
}
void BreakoutGamePosix_send_display_update(struct BreakoutGamePosix_Instance *_instance){
if (BreakoutGamePosix_send_display_update_listener != 0x0) BreakoutGamePosix_send_display_update_listener(_instance);
if (external_BreakoutGamePosix_send_display_update_listener != 0x0) external_BreakoutGamePosix_send_display_update_listener(_instance);
;
}
void (*external_BreakoutGamePosix_send_display_drawThingML_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t)= 0x0;
void (*BreakoutGamePosix_send_display_drawThingML_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t)= 0x0;
void register_external_BreakoutGamePosix_send_display_drawThingML_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t)){
external_BreakoutGamePosix_send_display_drawThingML_listener = _listener;
}
void register_BreakoutGamePosix_send_display_drawThingML_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t, uint8_t)){
BreakoutGamePosix_send_display_drawThingML_listener = _listener;
}
void BreakoutGamePosix_send_display_drawThingML(struct BreakoutGamePosix_Instance *_instance, uint8_t x, uint8_t y){
if (BreakoutGamePosix_send_display_drawThingML_listener != 0x0) BreakoutGamePosix_send_display_drawThingML_listener(_instance, x, y);
if (external_BreakoutGamePosix_send_display_drawThingML_listener != 0x0) external_BreakoutGamePosix_send_display_drawThingML_listener(_instance, x, y);
;
}
void (*external_BreakoutGamePosix_send_ia_updateIA_listener)(struct BreakoutGamePosix_Instance *, int16_t, int16_t, int16_t, int16_t)= 0x0;
void (*BreakoutGamePosix_send_ia_updateIA_listener)(struct BreakoutGamePosix_Instance *, int16_t, int16_t, int16_t, int16_t)= 0x0;
void register_external_BreakoutGamePosix_send_ia_updateIA_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, int16_t, int16_t, int16_t, int16_t)){
external_BreakoutGamePosix_send_ia_updateIA_listener = _listener;
}
void register_BreakoutGamePosix_send_ia_updateIA_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, int16_t, int16_t, int16_t, int16_t)){
BreakoutGamePosix_send_ia_updateIA_listener = _listener;
}
void BreakoutGamePosix_send_ia_updateIA(struct BreakoutGamePosix_Instance *_instance, int16_t ballx, int16_t bally, int16_t padx, int16_t pady){
if (BreakoutGamePosix_send_ia_updateIA_listener != 0x0) BreakoutGamePosix_send_ia_updateIA_listener(_instance, ballx, bally, padx, pady);
if (external_BreakoutGamePosix_send_ia_updateIA_listener != 0x0) external_BreakoutGamePosix_send_ia_updateIA_listener(_instance, ballx, bally, padx, pady);
;
}
void (*external_BreakoutGamePosix_send_game_lostBall_listener)(struct BreakoutGamePosix_Instance *)= 0x0;
void (*BreakoutGamePosix_send_game_lostBall_listener)(struct BreakoutGamePosix_Instance *)= 0x0;
void register_external_BreakoutGamePosix_send_game_lostBall_listener(void (*_listener)(struct BreakoutGamePosix_Instance *)){
external_BreakoutGamePosix_send_game_lostBall_listener = _listener;
}
void register_BreakoutGamePosix_send_game_lostBall_listener(void (*_listener)(struct BreakoutGamePosix_Instance *)){
BreakoutGamePosix_send_game_lostBall_listener = _listener;
}
void BreakoutGamePosix_send_game_lostBall(struct BreakoutGamePosix_Instance *_instance){
if (BreakoutGamePosix_send_game_lostBall_listener != 0x0) BreakoutGamePosix_send_game_lostBall_listener(_instance);
if (external_BreakoutGamePosix_send_game_lostBall_listener != 0x0) external_BreakoutGamePosix_send_game_lostBall_listener(_instance);
;
}
void (*external_BreakoutGamePosix_send_game_nextLevel_listener)(struct BreakoutGamePosix_Instance *)= 0x0;
void (*BreakoutGamePosix_send_game_nextLevel_listener)(struct BreakoutGamePosix_Instance *)= 0x0;
void register_external_BreakoutGamePosix_send_game_nextLevel_listener(void (*_listener)(struct BreakoutGamePosix_Instance *)){
external_BreakoutGamePosix_send_game_nextLevel_listener = _listener;
}
void register_BreakoutGamePosix_send_game_nextLevel_listener(void (*_listener)(struct BreakoutGamePosix_Instance *)){
BreakoutGamePosix_send_game_nextLevel_listener = _listener;
}
void BreakoutGamePosix_send_game_nextLevel(struct BreakoutGamePosix_Instance *_instance){
if (BreakoutGamePosix_send_game_nextLevel_listener != 0x0) BreakoutGamePosix_send_game_nextLevel_listener(_instance);
if (external_BreakoutGamePosix_send_game_nextLevel_listener != 0x0) external_BreakoutGamePosix_send_game_nextLevel_listener(_instance);
;
}
void (*external_BreakoutGamePosix_send_req_game_lostBall_listener)(struct BreakoutGamePosix_Instance *)= 0x0;
void (*BreakoutGamePosix_send_req_game_lostBall_listener)(struct BreakoutGamePosix_Instance *)= 0x0;
void register_external_BreakoutGamePosix_send_req_game_lostBall_listener(void (*_listener)(struct BreakoutGamePosix_Instance *)){
external_BreakoutGamePosix_send_req_game_lostBall_listener = _listener;
}
void register_BreakoutGamePosix_send_req_game_lostBall_listener(void (*_listener)(struct BreakoutGamePosix_Instance *)){
BreakoutGamePosix_send_req_game_lostBall_listener = _listener;
}
void BreakoutGamePosix_send_req_game_lostBall(struct BreakoutGamePosix_Instance *_instance){
if (BreakoutGamePosix_send_req_game_lostBall_listener != 0x0) BreakoutGamePosix_send_req_game_lostBall_listener(_instance);
if (external_BreakoutGamePosix_send_req_game_lostBall_listener != 0x0) external_BreakoutGamePosix_send_req_game_lostBall_listener(_instance);
;
}
void (*external_BreakoutGamePosix_send_req_game_nextLevel_listener)(struct BreakoutGamePosix_Instance *)= 0x0;
void (*BreakoutGamePosix_send_req_game_nextLevel_listener)(struct BreakoutGamePosix_Instance *)= 0x0;
void register_external_BreakoutGamePosix_send_req_game_nextLevel_listener(void (*_listener)(struct BreakoutGamePosix_Instance *)){
external_BreakoutGamePosix_send_req_game_nextLevel_listener = _listener;
}
void register_BreakoutGamePosix_send_req_game_nextLevel_listener(void (*_listener)(struct BreakoutGamePosix_Instance *)){
BreakoutGamePosix_send_req_game_nextLevel_listener = _listener;
}
void BreakoutGamePosix_send_req_game_nextLevel(struct BreakoutGamePosix_Instance *_instance){
if (BreakoutGamePosix_send_req_game_nextLevel_listener != 0x0) BreakoutGamePosix_send_req_game_nextLevel_listener(_instance);
if (external_BreakoutGamePosix_send_req_game_nextLevel_listener != 0x0) external_BreakoutGamePosix_send_req_game_nextLevel_listener(_instance);
;
}



