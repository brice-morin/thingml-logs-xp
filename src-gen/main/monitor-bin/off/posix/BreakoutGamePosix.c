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
void BreakoutGamePosix_send_log_log(struct BreakoutGamePosix_Instance *_instance, uint8_t* payload, uint8_t size);
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
uint8_t setBGColorsent_log_3[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x08, r_0, g_1, b_2};
BreakoutGamePosix_send_log_log(_instance, setBGColorsent_log_3, 7);
uint8_t r_4 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_5 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_6 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGamePosix_send_display_setColor(_instance, r_4, g_5, b_6);
uint8_t setColorsent_log_7[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_4, g_5, b_6};
BreakoutGamePosix_send_log_log(_instance, setColorsent_log_7, 7);
uint8_t initColors_log0[4] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x00};
BreakoutGamePosix_send_log_log(_instance, initColors_log0, 4);
}
// Definition of function resetBall
void f_BreakoutGamePosix_resetBall(struct BreakoutGamePosix_Instance *_instance) {
int16_t old_bx_10 = _instance->BreakoutGame_bx_var;
_instance->BreakoutGame_bx_var = _instance->BreakoutGame_padx_var - _instance->BreakoutGame_br_var / _instance->BreakoutGame_SCALE_var;
int16_t new_bx_10 = _instance->BreakoutGame_bx_var;
uint8_t bx_log_10[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0A, (((old_bx_10 >> 8) & 0xFF)), (((old_bx_10 >> 0) & 0xFF)), (((new_bx_10 >> 8) & 0xFF)), (((new_bx_10 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, bx_log_10, 7);
int16_t old_by_6 = _instance->BreakoutGame_by_var;
_instance->BreakoutGame_by_var = _instance->BreakoutGame_pady_var - _instance->BreakoutGame_br_var / _instance->BreakoutGame_SCALE_var;
int16_t new_by_6 = _instance->BreakoutGame_by_var;
uint8_t by_log_6[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0B, (((old_by_6 >> 8) & 0xFF)), (((old_by_6 >> 0) & 0xFF)), (((new_by_6 >> 8) & 0xFF)), (((new_by_6 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, by_log_6, 7);
int16_t old_dx_1 = _instance->BreakoutGame_dx_var;
_instance->BreakoutGame_dx_var = (_instance->BreakoutGame_padx_var + _instance->BreakoutGame_prevBX_var + _instance->BreakoutGame_prevBY_var) % 300 - 150;
int16_t new_dx_1 = _instance->BreakoutGame_dx_var;
uint8_t dx_log_1[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0C, (((old_dx_1 >> 8) & 0xFF)), (((old_dx_1 >> 0) & 0xFF)), (((new_dx_1 >> 8) & 0xFF)), (((new_dx_1 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, dx_log_1, 7);
if(_instance->BreakoutGame_dy_var > 0) {
int16_t old_dy_27 = _instance->BreakoutGame_dy_var;
_instance->BreakoutGame_dy_var =  -_instance->BreakoutGame_dy_var;
int16_t new_dy_27 = _instance->BreakoutGame_dy_var;
uint8_t dy_log_27[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0D, (((old_dy_27 >> 8) & 0xFF)), (((old_dy_27 >> 0) & 0xFF)), (((new_dy_27 >> 8) & 0xFF)), (((new_dy_27 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, dy_log_27, 7);

}
int16_t old_prevBX_24 = _instance->BreakoutGame_prevBX_var;
_instance->BreakoutGame_prevBX_var =  -1;
int16_t new_prevBX_24 = _instance->BreakoutGame_prevBX_var;
uint8_t prevBX_log_24[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x11, (((old_prevBX_24 >> 8) & 0xFF)), (((old_prevBX_24 >> 0) & 0xFF)), (((new_prevBX_24 >> 8) & 0xFF)), (((new_prevBX_24 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, prevBX_log_24, 7);
int16_t old_prevBY_17 = _instance->BreakoutGame_prevBY_var;
_instance->BreakoutGame_prevBY_var =  -1;
int16_t new_prevBY_17 = _instance->BreakoutGame_prevBY_var;
uint8_t prevBY_log_17[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x12, (((old_prevBY_17 >> 8) & 0xFF)), (((old_prevBY_17 >> 0) & 0xFF)), (((new_prevBY_17 >> 8) & 0xFF)), (((new_prevBY_17 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, prevBY_log_17, 7);
uint8_t resetBall_log1[4] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x00};
BreakoutGamePosix_send_log_log(_instance, resetBall_log1, 4);
}
// Definition of function eraseBall
void f_BreakoutGamePosix_eraseBall(struct BreakoutGamePosix_Instance *_instance) {
int16_t bs = (_instance->BreakoutGame_br_var * 2) / _instance->BreakoutGame_SCALE_var;
if(_instance->BreakoutGame_prevBX_var > 0) {
uint8_t r_8 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_9 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_10 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGamePosix_send_display_setColor(_instance, r_8, g_9, b_10);
uint8_t setColorsent_log_11[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_8, g_9, b_10};
BreakoutGamePosix_send_log_log(_instance, setColorsent_log_11, 7);
uint8_t x_12 = _instance->BreakoutGame_prevBX_var;
uint8_t y_13 = _instance->BreakoutGame_prevBY_var;
uint8_t width_14 = bs;
uint8_t height_15 = bs;
BreakoutGamePosix_send_display_fillRect(_instance, x_12, y_13, width_14, height_15);
uint8_t fillRectsent_log_16[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_12, y_13, width_14, height_15};
BreakoutGamePosix_send_log_log(_instance, fillRectsent_log_16, 8);

}
int16_t old_prevBX_25 = _instance->BreakoutGame_prevBX_var;
_instance->BreakoutGame_prevBX_var =  -1;
int16_t new_prevBX_25 = _instance->BreakoutGame_prevBX_var;
uint8_t prevBX_log_25[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x11, (((old_prevBX_25 >> 8) & 0xFF)), (((old_prevBX_25 >> 0) & 0xFF)), (((new_prevBX_25 >> 8) & 0xFF)), (((new_prevBX_25 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, prevBX_log_25, 7);
int16_t old_prevBY_18 = _instance->BreakoutGame_prevBY_var;
_instance->BreakoutGame_prevBY_var =  -1;
int16_t new_prevBY_18 = _instance->BreakoutGame_prevBY_var;
uint8_t prevBY_log_18[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x12, (((old_prevBY_18 >> 8) & 0xFF)), (((old_prevBY_18 >> 0) & 0xFF)), (((new_prevBY_18 >> 8) & 0xFF)), (((new_prevBY_18 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, prevBY_log_18, 7);
uint8_t eraseBall_log2[4] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x03, 0x00};
BreakoutGamePosix_send_log_log(_instance, eraseBall_log2, 4);
}
// Definition of function drawBall
void f_BreakoutGamePosix_drawBall(struct BreakoutGamePosix_Instance *_instance) {
int16_t bs = (_instance->BreakoutGame_br_var * 2) / _instance->BreakoutGame_SCALE_var;
f_BreakoutGamePosix_eraseBall(_instance);
int16_t old_prevBX_26 = _instance->BreakoutGame_prevBX_var;
_instance->BreakoutGame_prevBX_var = (_instance->BreakoutGame_bx_var - _instance->BreakoutGame_br_var) / _instance->BreakoutGame_SCALE_var;
int16_t new_prevBX_26 = _instance->BreakoutGame_prevBX_var;
uint8_t prevBX_log_26[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x11, (((old_prevBX_26 >> 8) & 0xFF)), (((old_prevBX_26 >> 0) & 0xFF)), (((new_prevBX_26 >> 8) & 0xFF)), (((new_prevBX_26 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, prevBX_log_26, 7);
int16_t old_prevBY_19 = _instance->BreakoutGame_prevBY_var;
_instance->BreakoutGame_prevBY_var = (_instance->BreakoutGame_by_var - _instance->BreakoutGame_br_var) / _instance->BreakoutGame_SCALE_var;
int16_t new_prevBY_19 = _instance->BreakoutGame_prevBY_var;
uint8_t prevBY_log_19[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x12, (((old_prevBY_19 >> 8) & 0xFF)), (((old_prevBY_19 >> 0) & 0xFF)), (((new_prevBY_19 >> 8) & 0xFF)), (((new_prevBY_19 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, prevBY_log_19, 7);
uint8_t r_17 = 183;
uint8_t g_18 = 199;
uint8_t b_19 = 111;
BreakoutGamePosix_send_display_setColor(_instance, r_17, g_18, b_19);
uint8_t setColorsent_log_20[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_17, g_18, b_19};
BreakoutGamePosix_send_log_log(_instance, setColorsent_log_20, 7);
uint8_t x_21 = _instance->BreakoutGame_prevBX_var;
uint8_t y_22 = _instance->BreakoutGame_prevBY_var;
uint8_t width_23 = bs;
uint8_t height_24 = bs;
BreakoutGamePosix_send_display_fillRect(_instance, x_21, y_22, width_23, height_24);
uint8_t fillRectsent_log_25[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_21, y_22, width_23, height_24};
BreakoutGamePosix_send_log_log(_instance, fillRectsent_log_25, 8);
uint8_t drawBall_log3[4] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x04, 0x00};
BreakoutGamePosix_send_log_log(_instance, drawBall_log3, 4);
}
// Definition of function erasePad
void f_BreakoutGamePosix_erasePad(struct BreakoutGamePosix_Instance *_instance) {
int16_t ps = _instance->BreakoutGame_padlen_var / _instance->BreakoutGame_SCALE_var;
if(_instance->BreakoutGame_prevPX_var > 0) {
uint8_t r_26 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_27 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_28 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGamePosix_send_display_setColor(_instance, r_26, g_27, b_28);
uint8_t setColorsent_log_29[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_26, g_27, b_28};
BreakoutGamePosix_send_log_log(_instance, setColorsent_log_29, 7);
uint8_t x_30 = _instance->BreakoutGame_prevPX_var;
uint8_t y_31 = _instance->BreakoutGame_prevPY_var;
uint8_t width_32 = ps;
uint8_t height_33 = 4;
BreakoutGamePosix_send_display_fillRect(_instance, x_30, y_31, width_32, height_33);
uint8_t fillRectsent_log_34[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_30, y_31, width_32, height_33};
BreakoutGamePosix_send_log_log(_instance, fillRectsent_log_34, 8);

}
uint8_t erasePad_log4[4] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x05, 0x00};
BreakoutGamePosix_send_log_log(_instance, erasePad_log4, 4);
}
// Definition of function drawPad
void f_BreakoutGamePosix_drawPad(struct BreakoutGamePosix_Instance *_instance) {
int16_t ps = _instance->BreakoutGame_padlen_var / _instance->BreakoutGame_SCALE_var;
f_BreakoutGamePosix_erasePad(_instance);
int16_t old_prevPX_22 = _instance->BreakoutGame_prevPX_var;
_instance->BreakoutGame_prevPX_var = (_instance->BreakoutGame_padx_var - (_instance->BreakoutGame_padlen_var / 2)) / _instance->BreakoutGame_SCALE_var;
int16_t new_prevPX_22 = _instance->BreakoutGame_prevPX_var;
uint8_t prevPX_log_22[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x16, (((old_prevPX_22 >> 8) & 0xFF)), (((old_prevPX_22 >> 0) & 0xFF)), (((new_prevPX_22 >> 8) & 0xFF)), (((new_prevPX_22 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, prevPX_log_22, 7);
int16_t old_prevPY_0 = _instance->BreakoutGame_prevPY_var;
_instance->BreakoutGame_prevPY_var = _instance->BreakoutGame_pady_var / _instance->BreakoutGame_SCALE_var;
int16_t new_prevPY_0 = _instance->BreakoutGame_prevPY_var;
uint8_t prevPY_log_0[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x17, (((old_prevPY_0 >> 8) & 0xFF)), (((old_prevPY_0 >> 0) & 0xFF)), (((new_prevPY_0 >> 8) & 0xFF)), (((new_prevPY_0 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, prevPY_log_0, 7);
uint8_t r_35 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_36 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_37 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGamePosix_send_display_setColor(_instance, r_35, g_36, b_37);
uint8_t setColorsent_log_38[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_35, g_36, b_37};
BreakoutGamePosix_send_log_log(_instance, setColorsent_log_38, 7);
uint8_t x_39 = _instance->BreakoutGame_prevPX_var;
uint8_t y_40 = _instance->BreakoutGame_prevPY_var;
uint8_t width_41 = ps;
uint8_t height_42 = 4;
BreakoutGamePosix_send_display_fillRect(_instance, x_39, y_40, width_41, height_42);
uint8_t fillRectsent_log_43[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_39, y_40, width_41, height_42};
BreakoutGamePosix_send_log_log(_instance, fillRectsent_log_43, 8);
uint8_t drawPad_log5[4] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x06, 0x00};
BreakoutGamePosix_send_log_log(_instance, drawPad_log5, 4);
}
// Definition of function drawCountDown
void f_BreakoutGamePosix_drawCountDown(struct BreakoutGamePosix_Instance *_instance, int16_t c) {
uint8_t r_44 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_45 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_46 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGamePosix_send_display_setColor(_instance, r_44, g_45, b_46);
uint8_t setColorsent_log_47[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_44, g_45, b_46};
BreakoutGamePosix_send_log_log(_instance, setColorsent_log_47, 7);
if(c > 0) {
uint8_t r_48 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_49 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_50 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGamePosix_send_display_setColor(_instance, r_48, g_49, b_50);
uint8_t setColorsent_log_51[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_48, g_49, b_50};
BreakoutGamePosix_send_log_log(_instance, setColorsent_log_51, 7);
uint8_t r_52 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_53 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_54 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGamePosix_send_display_setBGColor(_instance, r_52, g_53, b_54);
uint8_t setBGColorsent_log_55[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x08, r_52, g_53, b_54};
BreakoutGamePosix_send_log_log(_instance, setBGColorsent_log_55, 7);
uint8_t x_56 = 80 - 6;
uint8_t y_57 = 90;
int16_t v_58 = c;
uint8_t digits_59 = 1;
uint8_t scale_60 = 4;
BreakoutGamePosix_send_display_drawInteger(_instance, x_56, y_57, v_58, digits_59, scale_60);
uint8_t drawIntegersent_log_61[10] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0B, x_56, y_57, (((v_58 >> 8) & 0xFF)), (((v_58 >> 0) & 0xFF)), digits_59, scale_60};
BreakoutGamePosix_send_log_log(_instance, drawIntegersent_log_61, 10);

} else {
uint8_t r_62 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_63 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_64 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGamePosix_send_display_setColor(_instance, r_62, g_63, b_64);
uint8_t setColorsent_log_65[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_62, g_63, b_64};
BreakoutGamePosix_send_log_log(_instance, setColorsent_log_65, 7);
uint8_t x_66 = 80 - 6;
uint8_t y_67 = 90;
uint8_t width_68 = 12;
uint8_t height_69 = 20;
BreakoutGamePosix_send_display_fillRect(_instance, x_66, y_67, width_68, height_69);
uint8_t fillRectsent_log_70[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_66, y_67, width_68, height_69};
BreakoutGamePosix_send_log_log(_instance, fillRectsent_log_70, 8);

}
uint8_t drawCountDown_log6[6] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x07, 0x00, (((c >> 8) & 0xFF)), (((c >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, drawCountDown_log6, 6);
}
// Definition of function drawWalls
void f_BreakoutGamePosix_drawWalls(struct BreakoutGamePosix_Instance *_instance) {
uint8_t r_71 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_72 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_73 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGamePosix_send_display_setColor(_instance, r_71, g_72, b_73);
uint8_t setColorsent_log_74[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_71, g_72, b_73};
BreakoutGamePosix_send_log_log(_instance, setColorsent_log_74, 7);
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
uint8_t fillRectsent_log_79[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_75, y_76, width_77, height_78};
BreakoutGamePosix_send_log_log(_instance, fillRectsent_log_79, 8);
uint8_t x_80 = left - 1;
uint8_t y_81 = bottom;
uint8_t width_82 = xcenter + 1;
uint8_t height_83 = 1;
BreakoutGamePosix_send_display_fillRect(_instance, x_80, y_81, width_82, height_83);
uint8_t fillRectsent_log_84[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_80, y_81, width_82, height_83};
BreakoutGamePosix_send_log_log(_instance, fillRectsent_log_84, 8);
uint8_t x_85 = left - 1;
uint8_t y_86 = top;
uint8_t width_87 = 1;
uint8_t height_88 = ycenter;
BreakoutGamePosix_send_display_fillRect(_instance, x_85, y_86, width_87, height_88);
uint8_t fillRectsent_log_89[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_85, y_86, width_87, height_88};
BreakoutGamePosix_send_log_log(_instance, fillRectsent_log_89, 8);
uint8_t x_90 = right;
uint8_t y_91 = top;
uint8_t width_92 = 1;
uint8_t height_93 = ycenter;
BreakoutGamePosix_send_display_fillRect(_instance, x_90, y_91, width_92, height_93);
uint8_t fillRectsent_log_94[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_90, y_91, width_92, height_93};
BreakoutGamePosix_send_log_log(_instance, fillRectsent_log_94, 8);
uint8_t drawWalls_log7[4] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x08, 0x00};
BreakoutGamePosix_send_log_log(_instance, drawWalls_log7, 4);
}
// Definition of function bitIsSet
bool f_BreakoutGamePosix_bitIsSet(struct BreakoutGamePosix_Instance *_instance, uint8_t variable, uint8_t bit) {
bool return_0 = (((1 << bit) & variable) != 0);
uint8_t bitIsSet_log8[7] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x09, 0x00, variable, bit, return_0};
BreakoutGamePosix_send_log_log(_instance, bitIsSet_log8, 7);
return return_0;
}
// Definition of function createBricks
void f_BreakoutGamePosix_createBricks(struct BreakoutGamePosix_Instance *_instance) {
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
uint8_t createBricks_log9[4] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0A, 0x00};
BreakoutGamePosix_send_log_log(_instance, createBricks_log9, 4);
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
uint8_t bricksLeft_log10[5] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0B, 0x00, return_3};
BreakoutGamePosix_send_log_log(_instance, bricksLeft_log10, 5);
return return_3;
}
// Definition of function drawBrick
void f_BreakoutGamePosix_drawBrick(struct BreakoutGamePosix_Instance *_instance, uint8_t x, uint8_t y) {
uint8_t bx = ((_instance->BreakoutGame_LEFT_var + ((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 8) * x) / _instance->BreakoutGame_SCALE_var + 1);
uint8_t by = ((_instance->BreakoutGame_TOP_var + 20 * _instance->BreakoutGame_SCALE_var + _instance->BreakoutGame_BRICK_HEIGHT_var * y * _instance->BreakoutGame_SCALE_var) / _instance->BreakoutGame_SCALE_var + 1);
uint8_t w = (((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 8) / _instance->BreakoutGame_SCALE_var - 2);
uint8_t h = (_instance->BreakoutGame_BRICK_HEIGHT_var - 2);
uint8_t r_95 = 155;
uint8_t g_96 = 103;
uint8_t b_97 = 89;
BreakoutGamePosix_send_display_setColor(_instance, r_95, g_96, b_97);
uint8_t setColorsent_log_98[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_95, g_96, b_97};
BreakoutGamePosix_send_log_log(_instance, setColorsent_log_98, 7);
uint8_t x_99 = bx;
uint8_t y_100 = by;
uint8_t width_101 = w;
uint8_t height_102 = h;
BreakoutGamePosix_send_display_fillRect(_instance, x_99, y_100, width_101, height_102);
uint8_t fillRectsent_log_103[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_99, y_100, width_101, height_102};
BreakoutGamePosix_send_log_log(_instance, fillRectsent_log_103, 8);
uint8_t r_104 = 100;
uint8_t g_105 = 56;
uint8_t b_106 = 43;
BreakoutGamePosix_send_display_setColor(_instance, r_104, g_105, b_106);
uint8_t setColorsent_log_107[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_104, g_105, b_106};
BreakoutGamePosix_send_log_log(_instance, setColorsent_log_107, 7);
uint8_t x_108 = bx;
uint8_t y_109 = by;
uint8_t width_110 = w;
uint8_t height_111 = h;
BreakoutGamePosix_send_display_drawRect(_instance, x_108, y_109, width_110, height_111);
uint8_t drawRectsent_log_112[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x09, x_108, y_109, width_110, height_111};
BreakoutGamePosix_send_log_log(_instance, drawRectsent_log_112, 8);
uint8_t drawBrick_log11[6] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0C, 0x00, x, y};
BreakoutGamePosix_send_log_log(_instance, drawBrick_log11, 6);
}
// Definition of function removeBrick
void f_BreakoutGamePosix_removeBrick(struct BreakoutGamePosix_Instance *_instance, uint8_t x, uint8_t y) {
uint8_t bx = ((_instance->BreakoutGame_LEFT_var + ((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 8) * x) / _instance->BreakoutGame_SCALE_var + 1);
uint8_t by = ((_instance->BreakoutGame_TOP_var + 20 * _instance->BreakoutGame_SCALE_var + _instance->BreakoutGame_BRICK_HEIGHT_var * y * _instance->BreakoutGame_SCALE_var) / _instance->BreakoutGame_SCALE_var + 1);
uint8_t r_113 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_114 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_115 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGamePosix_send_display_setColor(_instance, r_113, g_114, b_115);
uint8_t setColorsent_log_116[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_113, g_114, b_115};
BreakoutGamePosix_send_log_log(_instance, setColorsent_log_116, 7);
uint8_t x_117 = bx;
uint8_t y_118 = by;
uint8_t width_119 = (((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 8) / _instance->BreakoutGame_SCALE_var - 2);
uint8_t height_120 = _instance->BreakoutGame_BRICK_HEIGHT_var - 2;
BreakoutGamePosix_send_display_fillRect(_instance, x_117, y_118, width_119, height_120);
uint8_t fillRectsent_log_121[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_117, y_118, width_119, height_120};
BreakoutGamePosix_send_log_log(_instance, fillRectsent_log_121, 8);
_instance->BreakoutGame_bricks_var[y] = f_BreakoutGamePosix_unsetBit(_instance, _instance->BreakoutGame_bricks_var[y], x);
uint8_t removeBrick_log12[6] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0D, 0x00, x, y};
BreakoutGamePosix_send_log_log(_instance, removeBrick_log12, 6);
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
uint8_t collideBrick_log13[9] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0E, 0x00, (((xpos >> 8) & 0xFF)), (((xpos >> 0) & 0xFF)), (((ypos >> 8) & 0xFF)), (((ypos >> 0) & 0xFF)), return_3};
BreakoutGamePosix_send_log_log(_instance, collideBrick_log13, 9);
return return_3;
}
// Definition of function drawLevel
void f_BreakoutGamePosix_drawLevel(struct BreakoutGamePosix_Instance *_instance) {
uint8_t r_122 = 158;
uint8_t g_123 = 209;
uint8_t b_124 = 130;
BreakoutGamePosix_send_display_setColor(_instance, r_122, g_123, b_124);
uint8_t setColorsent_log_125[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_122, g_123, b_124};
BreakoutGamePosix_send_log_log(_instance, setColorsent_log_125, 7);
uint8_t r_126 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_127 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_128 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGamePosix_send_display_setBGColor(_instance, r_126, g_127, b_128);
uint8_t setBGColorsent_log_129[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x08, r_126, g_127, b_128};
BreakoutGamePosix_send_log_log(_instance, setBGColorsent_log_129, 7);
uint8_t r_130 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_131 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_132 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGamePosix_send_display_setColor(_instance, r_130, g_131, b_132);
uint8_t setColorsent_log_133[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_130, g_131, b_132};
BreakoutGamePosix_send_log_log(_instance, setColorsent_log_133, 7);
uint8_t x_134 = 6;
uint8_t y_135 = 2;
int16_t v_136 = _instance->BreakoutGame_level_var;
uint8_t digits_137 = 2;
uint8_t scale_138 = 2;
BreakoutGamePosix_send_display_drawInteger(_instance, x_134, y_135, v_136, digits_137, scale_138);
uint8_t drawIntegersent_log_139[10] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0B, x_134, y_135, (((v_136 >> 8) & 0xFF)), (((v_136 >> 0) & 0xFF)), digits_137, scale_138};
BreakoutGamePosix_send_log_log(_instance, drawIntegersent_log_139, 10);
uint8_t drawLevel_log14[4] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0F, 0x00};
BreakoutGamePosix_send_log_log(_instance, drawLevel_log14, 4);
}
// Definition of function incrementScore
void f_BreakoutGamePosix_incrementScore(struct BreakoutGamePosix_Instance *_instance, int8_t diff) {
int16_t old_score_14 = _instance->BreakoutGame_score_var;
_instance->BreakoutGame_score_var = _instance->BreakoutGame_score_var + diff;
int16_t new_score_14 = _instance->BreakoutGame_score_var;
uint8_t score_log_14[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x1B, (((old_score_14 >> 8) & 0xFF)), (((old_score_14 >> 0) & 0xFF)), (((new_score_14 >> 8) & 0xFF)), (((new_score_14 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, score_log_14, 7);
if(_instance->BreakoutGame_score_var < 0) {
int16_t old_score_15 = _instance->BreakoutGame_score_var;
_instance->BreakoutGame_score_var = 0;
int16_t new_score_15 = _instance->BreakoutGame_score_var;
uint8_t score_log_15[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x1B, (((old_score_15 >> 8) & 0xFF)), (((old_score_15 >> 0) & 0xFF)), (((new_score_15 >> 8) & 0xFF)), (((new_score_15 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, score_log_15, 7);

}
f_BreakoutGamePosix_drawScore(_instance);
uint8_t incrementScore_log15[5] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x10, 0x00, diff};
BreakoutGamePosix_send_log_log(_instance, incrementScore_log15, 5);
}
// Definition of function drawScore
void f_BreakoutGamePosix_drawScore(struct BreakoutGamePosix_Instance *_instance) {
uint8_t r_140 = 158;
uint8_t g_141 = 209;
uint8_t b_142 = 130;
BreakoutGamePosix_send_display_setColor(_instance, r_140, g_141, b_142);
uint8_t setColorsent_log_143[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_140, g_141, b_142};
BreakoutGamePosix_send_log_log(_instance, setColorsent_log_143, 7);
uint8_t r_144 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_145 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_146 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGamePosix_send_display_setBGColor(_instance, r_144, g_145, b_146);
uint8_t setBGColorsent_log_147[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x08, r_144, g_145, b_146};
BreakoutGamePosix_send_log_log(_instance, setBGColorsent_log_147, 7);
uint8_t x_148 = 58;
uint8_t y_149 = 2;
int16_t v_150 = _instance->BreakoutGame_score_var;
uint8_t digits_151 = 5;
uint8_t scale_152 = 2;
BreakoutGamePosix_send_display_drawInteger(_instance, x_148, y_149, v_150, digits_151, scale_152);
uint8_t drawIntegersent_log_153[10] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0B, x_148, y_149, (((v_150 >> 8) & 0xFF)), (((v_150 >> 0) & 0xFF)), digits_151, scale_152};
BreakoutGamePosix_send_log_log(_instance, drawIntegersent_log_153, 10);
uint8_t drawScore_log16[4] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x11, 0x00};
BreakoutGamePosix_send_log_log(_instance, drawScore_log16, 4);
}
// Definition of function drawLives
void f_BreakoutGamePosix_drawLives(struct BreakoutGamePosix_Instance *_instance) {
uint8_t r_154 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_155 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_156 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGamePosix_send_display_setColor(_instance, r_154, g_155, b_156);
uint8_t setColorsent_log_157[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_154, g_155, b_156};
BreakoutGamePosix_send_log_log(_instance, setColorsent_log_157, 7);
uint8_t x_158 = 124;
uint8_t y_159 = 4;
uint8_t width_160 = 24 + 6;
uint8_t height_161 = 6;
BreakoutGamePosix_send_display_fillRect(_instance, x_158, y_159, width_160, height_161);
uint8_t fillRectsent_log_162[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_158, y_159, width_160, height_161};
BreakoutGamePosix_send_log_log(_instance, fillRectsent_log_162, 8);
uint8_t r_163 = 183;
uint8_t g_164 = 199;
uint8_t b_165 = 111;
BreakoutGamePosix_send_display_setColor(_instance, r_163, g_164, b_165);
uint8_t setColorsent_log_166[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_163, g_164, b_165};
BreakoutGamePosix_send_log_log(_instance, setColorsent_log_166, 7);
uint8_t i = 0;
while(i < _instance->BreakoutGame_lives_var) {
uint8_t x_167 = 124 + (2 - i) * 12;
uint8_t y_168 = 4;
uint8_t width_169 = 6;
uint8_t height_170 = 6;
BreakoutGamePosix_send_display_fillRect(_instance, x_167, y_168, width_169, height_170);
uint8_t fillRectsent_log_171[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_167, y_168, width_169, height_170};
BreakoutGamePosix_send_log_log(_instance, fillRectsent_log_171, 8);
i = i + 1;

}
uint8_t drawLives_log17[4] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x12, 0x00};
BreakoutGamePosix_send_log_log(_instance, drawLives_log17, 4);
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
uint8_t r_235 = 255;
uint8_t g_236 = 255;
uint8_t b_237 = 255;
BreakoutGamePosix_send_display_setColor(_instance, r_235, g_236, b_237);
uint8_t setColorsent_log_238[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_235, g_236, b_237};
BreakoutGamePosix_send_log_log(_instance, setColorsent_log_238, 7);
uint8_t x_239 = 8;
uint8_t y_240 = 30;
uint8_t width_241 = 142;
uint8_t height_242 = 76;
BreakoutGamePosix_send_display_fillRect(_instance, x_239, y_240, width_241, height_242);
uint8_t fillRectsent_log_243[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_239, y_240, width_241, height_242};
BreakoutGamePosix_send_log_log(_instance, fillRectsent_log_243, 8);
uint8_t r_244 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_245 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_246 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGamePosix_send_display_setColor(_instance, r_244, g_245, b_246);
uint8_t setColorsent_log_247[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_244, g_245, b_246};
BreakoutGamePosix_send_log_log(_instance, setColorsent_log_247, 7);
uint8_t x_248 = 9;
uint8_t y_249 = 31;
uint8_t width_250 = 140;
uint8_t height_251 = 50;
BreakoutGamePosix_send_display_fillRect(_instance, x_248, y_249, width_250, height_251);
uint8_t fillRectsent_log_252[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_248, y_249, width_250, height_251};
BreakoutGamePosix_send_log_log(_instance, fillRectsent_log_252, 8);
uint8_t r_253 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_254 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_255 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGamePosix_send_display_setBGColor(_instance, r_253, g_254, b_255);
uint8_t setBGColorsent_log_256[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x08, r_253, g_254, b_255};
BreakoutGamePosix_send_log_log(_instance, setBGColorsent_log_256, 7);
uint8_t r_257 = 158;
uint8_t g_258 = 209;
uint8_t b_259 = 130;
BreakoutGamePosix_send_display_setColor(_instance, r_257, g_258, b_259);
uint8_t setColorsent_log_260[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_257, g_258, b_259};
BreakoutGamePosix_send_log_log(_instance, setColorsent_log_260, 7);
uint8_t x_261 = 23;
uint8_t y_262 = 40;
int16_t v_263 = _instance->BreakoutGame_score_var;
uint8_t digits_264 = 5;
uint8_t scale_265 = 6;
BreakoutGamePosix_send_display_drawInteger(_instance, x_261, y_262, v_263, digits_264, scale_265);
uint8_t drawIntegersent_log_266[10] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0B, x_261, y_262, (((v_263 >> 8) & 0xFF)), (((v_263 >> 0) & 0xFF)), digits_264, scale_265};
BreakoutGamePosix_send_log_log(_instance, drawIntegersent_log_266, 10);
uint8_t x_267 = 26;
uint8_t y_268 = 87;
BreakoutGamePosix_send_display_drawThingML(_instance, x_267, y_268);
uint8_t drawThingMLsent_log_269[6] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0C, x_267, y_268};
BreakoutGamePosix_send_log_log(_instance, drawThingMLsent_log_269, 6);
BreakoutGamePosix_send_display_update(_instance);
uint8_t updatesent_log_270[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0F};
BreakoutGamePosix_send_log_log(_instance, updatesent_log_270, 4);
f_BreakoutGamePosix_log(_instance, 1);
_instance->BreakoutGame_stopTime_var = f_BreakoutGamePosix_timestamp(_instance);
f_BreakoutGamePosix_quit(_instance);
_instance->active = false;
break;
}
case BREAKOUTGAME_SC_PLAY_STATE:{
uint8_t id_203 = 0;
uint16_t time_204 = _instance->BreakoutGame_period_var;
BreakoutGamePosix_send_clock_timer_start(_instance, id_203, time_204);
uint8_t timer_startsent_log_205[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x14, id_203, (((time_204 >> 8) & 0xFF)), (((time_204 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, timer_startsent_log_205, 7);
break;
}
case BREAKOUTGAME_SC_LAUNCH_STATE:{
uint8_t id_194 = 0;
uint16_t time_195 = _instance->BreakoutGame_period_var;
BreakoutGamePosix_send_clock_timer_start(_instance, id_194, time_195);
uint8_t timer_startsent_log_196[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x14, id_194, (((time_195 >> 8) & 0xFF)), (((time_195 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, timer_startsent_log_196, 7);
uint8_t old_countdown_20 = _instance->BreakoutGame_SC_LAUNCH_countdown_var;
_instance->BreakoutGame_SC_LAUNCH_countdown_var = 3;
uint8_t new_countdown_20 = _instance->BreakoutGame_SC_LAUNCH_countdown_var;
uint8_t countdown_log_20[5] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x1E, old_countdown_20, new_countdown_20};
BreakoutGamePosix_send_log_log(_instance, countdown_log_20, 5);
f_BreakoutGamePosix_drawScore(_instance);
f_BreakoutGamePosix_drawLives(_instance);
BreakoutGamePosix_send_display_update(_instance);
uint8_t updatesent_log_197[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0F};
BreakoutGamePosix_send_log_log(_instance, updatesent_log_197, 4);
break;
}
case BREAKOUTGAME_SC_INIT_STATE:{
_instance->BreakoutGame_startTime_var = f_BreakoutGamePosix_timestamp(_instance);
uint8_t xsize_172 = _instance->BreakoutGame_XDISPSIZE_var;
uint8_t ysize_173 = _instance->BreakoutGame_YDISPSIZE_var;
BreakoutGamePosix_send_display_create(_instance, xsize_172, ysize_173);
uint8_t createsent_log_174[6] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0D, xsize_172, ysize_173};
BreakoutGamePosix_send_log_log(_instance, createsent_log_174, 6);
break;
}
case BREAKOUTGAME_SC_LOSTBALL_STATE:{
uint8_t id_227 = 0;
uint16_t time_228 = _instance->BreakoutGame_period_var;
BreakoutGamePosix_send_clock_timer_start(_instance, id_227, time_228);
uint8_t timer_startsent_log_229[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x14, id_227, (((time_228 >> 8) & 0xFF)), (((time_228 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, timer_startsent_log_229, 7);
uint8_t old_lives_16 = _instance->BreakoutGame_lives_var;
_instance->BreakoutGame_lives_var = _instance->BreakoutGame_lives_var - 1;
uint8_t new_lives_16 = _instance->BreakoutGame_lives_var;
uint8_t lives_log_16[5] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x1C, old_lives_16, new_lives_16};
BreakoutGamePosix_send_log_log(_instance, lives_log_16, 5);
f_BreakoutGamePosix_eraseBall(_instance);
f_BreakoutGamePosix_erasePad(_instance);
f_BreakoutGamePosix_drawLives(_instance);
BreakoutGamePosix_send_display_update(_instance);
uint8_t updatesent_log_230[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0F};
BreakoutGamePosix_send_log_log(_instance, updatesent_log_230, 4);
f_BreakoutGamePosix_log(_instance, 1);
break;
}
case BREAKOUTGAME_SC_NEXTLEVEL_STATE:{
uint8_t id_231 = 0;
uint16_t time_232 = _instance->BreakoutGame_period_var;
BreakoutGamePosix_send_clock_timer_start(_instance, id_231, time_232);
uint8_t timer_startsent_log_233[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x14, id_231, (((time_232 >> 8) & 0xFF)), (((time_232 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, timer_startsent_log_233, 7);
uint8_t old_level_23 = _instance->BreakoutGame_level_var;
_instance->BreakoutGame_level_var = _instance->BreakoutGame_level_var + 1;
uint8_t new_level_23 = _instance->BreakoutGame_level_var;
uint8_t level_log_23[5] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x1D, old_level_23, new_level_23};
BreakoutGamePosix_send_log_log(_instance, level_log_23, 5);
f_BreakoutGamePosix_drawLevel(_instance);
f_BreakoutGamePosix_eraseBall(_instance);
f_BreakoutGamePosix_erasePad(_instance);
if((_instance->BreakoutGame_level_var % 2) == 0 && _instance->BreakoutGame_padlen_var > 5 * _instance->BreakoutGame_SCALE_var) {
int16_t old_padlen_5 = _instance->BreakoutGame_padlen_var;
_instance->BreakoutGame_padlen_var = _instance->BreakoutGame_padlen_var - (4 * _instance->BreakoutGame_SCALE_var);
int16_t new_padlen_5 = _instance->BreakoutGame_padlen_var;
uint8_t padlen_log_5[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x10, (((old_padlen_5 >> 8) & 0xFF)), (((old_padlen_5 >> 0) & 0xFF)), (((new_padlen_5 >> 8) & 0xFF)), (((new_padlen_5 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, padlen_log_5, 7);

}
if((_instance->BreakoutGame_level_var % 2) == 1) {
int16_t old_dy_31 = _instance->BreakoutGame_dy_var;
_instance->BreakoutGame_dy_var = (_instance->BreakoutGame_dy_var * 3) / 2;
int16_t new_dy_31 = _instance->BreakoutGame_dy_var;
uint8_t dy_log_31[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0D, (((old_dy_31 >> 8) & 0xFF)), (((old_dy_31 >> 0) & 0xFF)), (((new_dy_31 >> 8) & 0xFF)), (((new_dy_31 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, dy_log_31, 7);

}
f_BreakoutGamePosix_drawLives(_instance);
f_BreakoutGamePosix_createBricks(_instance);
BreakoutGamePosix_send_display_update(_instance);
uint8_t updatesent_log_234[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0F};
BreakoutGamePosix_send_log_log(_instance, updatesent_log_234, 4);
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
case BREAKOUTGAME_SC_PLAY_STATE:{
break;}
case BREAKOUTGAME_SC_LAUNCH_STATE:{
break;}
case BREAKOUTGAME_SC_INIT_STATE:{
break;}
case BREAKOUTGAME_SC_LOSTBALL_STATE:{
break;}
case BREAKOUTGAME_SC_NEXTLEVEL_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void BreakoutGamePosix_handle_clock_timer_timeout(struct BreakoutGamePosix_Instance *_instance, uint8_t id) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_LAUNCH_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && id == 0 && _instance->BreakoutGame_SC_LAUNCH_countdown_var == 0) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_LAUNCH_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_PLAY_STATE;
uint8_t timer_timeouthandled_log_272[7] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x16, 0x02, 0x03, id};
BreakoutGamePosix_send_log_log(_instance, timer_timeouthandled_log_272, 7);
f_BreakoutGamePosix_drawCountDown(_instance, 0);
f_BreakoutGamePosix_resetBall(_instance);
BreakoutGamePosix_send_display_update(_instance);
uint8_t updatesent_log_202[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0F};
BreakoutGamePosix_send_log_log(_instance, updatesent_log_202, 4);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_PLAY_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
else if (BreakoutGame_SC_State_event_consumed == 0 && id == 0 && _instance->BreakoutGame_SC_LAUNCH_countdown_var > 0) {
uint8_t timer_timeouthandled_log_273[7] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x16, 0x02, 0x00, id};
BreakoutGamePosix_send_log_log(_instance, timer_timeouthandled_log_273, 7);
uint8_t id_198 = 0;
uint16_t time_199 = _instance->BreakoutGame_period_var;
BreakoutGamePosix_send_clock_timer_start(_instance, id_198, time_199);
uint8_t timer_startsent_log_200[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x14, id_198, (((time_199 >> 8) & 0xFF)), (((time_199 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, timer_startsent_log_200, 7);
f_BreakoutGamePosix_drawPad(_instance);
if((_instance->BreakoutGame_SC_LAUNCH_countdown_var % 30) == 0) {
f_BreakoutGamePosix_drawCountDown(_instance, _instance->BreakoutGame_SC_LAUNCH_countdown_var / 30);

}
uint8_t old_countdown_21 = _instance->BreakoutGame_SC_LAUNCH_countdown_var;
_instance->BreakoutGame_SC_LAUNCH_countdown_var = _instance->BreakoutGame_SC_LAUNCH_countdown_var - 1;
uint8_t new_countdown_21 = _instance->BreakoutGame_SC_LAUNCH_countdown_var;
uint8_t countdown_log_21[5] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x1E, old_countdown_21, new_countdown_21};
BreakoutGamePosix_send_log_log(_instance, countdown_log_21, 5);
BreakoutGamePosix_send_display_update(_instance);
uint8_t updatesent_log_201[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0F};
BreakoutGamePosix_send_log_log(_instance, updatesent_log_201, 4);
BreakoutGame_SC_State_event_consumed = 1;
}
}
else if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_PLAY_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && id == 0) {
uint8_t timer_timeouthandled_log_271[7] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x16, 0x03, 0x00, id};
BreakoutGamePosix_send_log_log(_instance, timer_timeouthandled_log_271, 7);
int16_t old_bx_11 = _instance->BreakoutGame_bx_var;
_instance->BreakoutGame_bx_var = _instance->BreakoutGame_bx_var + _instance->BreakoutGame_dx_var;
int16_t new_bx_11 = _instance->BreakoutGame_bx_var;
uint8_t bx_log_11[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0A, (((old_bx_11 >> 8) & 0xFF)), (((old_bx_11 >> 0) & 0xFF)), (((new_bx_11 >> 8) & 0xFF)), (((new_bx_11 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, bx_log_11, 7);
int16_t old_by_7 = _instance->BreakoutGame_by_var;
_instance->BreakoutGame_by_var = _instance->BreakoutGame_by_var + _instance->BreakoutGame_dy_var;
int16_t new_by_7 = _instance->BreakoutGame_by_var;
uint8_t by_log_7[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0B, (((old_by_7 >> 8) & 0xFF)), (((old_by_7 >> 0) & 0xFF)), (((new_by_7 >> 8) & 0xFF)), (((new_by_7 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, by_log_7, 7);
int16_t wl = _instance->BreakoutGame_LEFT_var + _instance->BreakoutGame_br_var;
int16_t wr = _instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_br_var;
int16_t wt = _instance->BreakoutGame_TOP_var + _instance->BreakoutGame_br_var;
int16_t wb = _instance->BreakoutGame_BOTTOM_var - _instance->BreakoutGame_br_var;
if(_instance->BreakoutGame_bx_var < wl) {
int16_t old_dx_2 = _instance->BreakoutGame_dx_var;
_instance->BreakoutGame_dx_var =  -_instance->BreakoutGame_dx_var;
int16_t new_dx_2 = _instance->BreakoutGame_dx_var;
uint8_t dx_log_2[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0C, (((old_dx_2 >> 8) & 0xFF)), (((old_dx_2 >> 0) & 0xFF)), (((new_dx_2 >> 8) & 0xFF)), (((new_dx_2 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, dx_log_2, 7);
int16_t old_bx_12 = _instance->BreakoutGame_bx_var;
_instance->BreakoutGame_bx_var = 2 * wl - _instance->BreakoutGame_bx_var;
int16_t new_bx_12 = _instance->BreakoutGame_bx_var;
uint8_t bx_log_12[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0A, (((old_bx_12 >> 8) & 0xFF)), (((old_bx_12 >> 0) & 0xFF)), (((new_bx_12 >> 8) & 0xFF)), (((new_bx_12 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, bx_log_12, 7);
f_BreakoutGamePosix_incrementScore(_instance,  -1);

} else {
if(_instance->BreakoutGame_bx_var > wr) {
int16_t old_dx_3 = _instance->BreakoutGame_dx_var;
_instance->BreakoutGame_dx_var =  -_instance->BreakoutGame_dx_var;
int16_t new_dx_3 = _instance->BreakoutGame_dx_var;
uint8_t dx_log_3[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0C, (((old_dx_3 >> 8) & 0xFF)), (((old_dx_3 >> 0) & 0xFF)), (((new_dx_3 >> 8) & 0xFF)), (((new_dx_3 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, dx_log_3, 7);
int16_t old_bx_13 = _instance->BreakoutGame_bx_var;
_instance->BreakoutGame_bx_var = 2 * wr - _instance->BreakoutGame_bx_var;
int16_t new_bx_13 = _instance->BreakoutGame_bx_var;
uint8_t bx_log_13[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0A, (((old_bx_13 >> 8) & 0xFF)), (((old_bx_13 >> 0) & 0xFF)), (((new_bx_13 >> 8) & 0xFF)), (((new_bx_13 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, bx_log_13, 7);
f_BreakoutGamePosix_incrementScore(_instance,  -1);

}

}
if(_instance->BreakoutGame_by_var < wt) {
int16_t old_dy_28 = _instance->BreakoutGame_dy_var;
_instance->BreakoutGame_dy_var =  -_instance->BreakoutGame_dy_var;
int16_t new_dy_28 = _instance->BreakoutGame_dy_var;
uint8_t dy_log_28[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0D, (((old_dy_28 >> 8) & 0xFF)), (((old_dy_28 >> 0) & 0xFF)), (((new_dy_28 >> 8) & 0xFF)), (((new_dy_28 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, dy_log_28, 7);
int16_t old_by_8 = _instance->BreakoutGame_by_var;
_instance->BreakoutGame_by_var = 2 * wt - _instance->BreakoutGame_by_var;
int16_t new_by_8 = _instance->BreakoutGame_by_var;
uint8_t by_log_8[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0B, (((old_by_8 >> 8) & 0xFF)), (((old_by_8 >> 0) & 0xFF)), (((new_by_8 >> 8) & 0xFF)), (((new_by_8 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, by_log_8, 7);
f_BreakoutGamePosix_incrementScore(_instance,  -1);

} else {
if(_instance->BreakoutGame_by_var > wb) {
BreakoutGamePosix_send_game_lostBall(_instance);
uint8_t lostBallsent_log_206[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x05, 0x01};
BreakoutGamePosix_send_log_log(_instance, lostBallsent_log_206, 4);
BreakoutGamePosix_send_req_game_lostBall(_instance);
uint8_t lostBallsent_log_207[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x06, 0x01};
BreakoutGamePosix_send_log_log(_instance, lostBallsent_log_207, 4);

}

}
if(_instance->BreakoutGame_dy_var > 0) {
if(_instance->BreakoutGame_by_var > _instance->BreakoutGame_pady_var - _instance->BreakoutGame_br_var && _instance->BreakoutGame_by_var < _instance->BreakoutGame_pady_var + _instance->BreakoutGame_br_var) {
if(_instance->BreakoutGame_bx_var > _instance->BreakoutGame_padx_var - _instance->BreakoutGame_padlen_var / 2 && _instance->BreakoutGame_bx_var < _instance->BreakoutGame_padx_var + _instance->BreakoutGame_padlen_var / 2) {
int16_t old_dy_29 = _instance->BreakoutGame_dy_var;
_instance->BreakoutGame_dy_var =  -_instance->BreakoutGame_dy_var;
int16_t new_dy_29 = _instance->BreakoutGame_dy_var;
uint8_t dy_log_29[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0D, (((old_dy_29 >> 8) & 0xFF)), (((old_dy_29 >> 0) & 0xFF)), (((new_dy_29 >> 8) & 0xFF)), (((new_dy_29 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, dy_log_29, 7);
int16_t old_by_9 = _instance->BreakoutGame_by_var;
_instance->BreakoutGame_by_var = 2 * (_instance->BreakoutGame_pady_var - _instance->BreakoutGame_br_var) - _instance->BreakoutGame_by_var;
int16_t new_by_9 = _instance->BreakoutGame_by_var;
uint8_t by_log_9[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0B, (((old_by_9 >> 8) & 0xFF)), (((old_by_9 >> 0) & 0xFF)), (((new_by_9 >> 8) & 0xFF)), (((new_by_9 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, by_log_9, 7);
int16_t old_dx_4 = _instance->BreakoutGame_dx_var;
_instance->BreakoutGame_dx_var = _instance->BreakoutGame_dx_var / 4 + (_instance->BreakoutGame_bx_var - _instance->BreakoutGame_padx_var) / 4;
int16_t new_dx_4 = _instance->BreakoutGame_dx_var;
uint8_t dx_log_4[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0C, (((old_dx_4 >> 8) & 0xFF)), (((old_dx_4 >> 0) & 0xFF)), (((new_dx_4 >> 8) & 0xFF)), (((new_dx_4 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, dx_log_4, 7);

}

}

}
bool collision = f_BreakoutGamePosix_collideBrick(_instance, _instance->BreakoutGame_bx_var - _instance->BreakoutGame_br_var, _instance->BreakoutGame_by_var - _instance->BreakoutGame_br_var) || f_BreakoutGamePosix_collideBrick(_instance, _instance->BreakoutGame_bx_var + _instance->BreakoutGame_br_var, _instance->BreakoutGame_by_var - _instance->BreakoutGame_br_var) || f_BreakoutGamePosix_collideBrick(_instance, _instance->BreakoutGame_bx_var + _instance->BreakoutGame_br_var, _instance->BreakoutGame_by_var + _instance->BreakoutGame_br_var) || f_BreakoutGamePosix_collideBrick(_instance, _instance->BreakoutGame_bx_var - _instance->BreakoutGame_br_var, _instance->BreakoutGame_by_var + _instance->BreakoutGame_br_var);
if(collision) {
int16_t old_dy_30 = _instance->BreakoutGame_dy_var;
_instance->BreakoutGame_dy_var =  -_instance->BreakoutGame_dy_var;
int16_t new_dy_30 = _instance->BreakoutGame_dy_var;
uint8_t dy_log_30[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0D, (((old_dy_30 >> 8) & 0xFF)), (((old_dy_30 >> 0) & 0xFF)), (((new_dy_30 >> 8) & 0xFF)), (((new_dy_30 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, dy_log_30, 7);
f_BreakoutGamePosix_incrementScore(_instance, 10);
if(f_BreakoutGamePosix_bricksLeft(_instance) == 0) {
BreakoutGamePosix_send_game_nextLevel(_instance);
uint8_t nextLevelsent_log_208[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x05, 0x02};
BreakoutGamePosix_send_log_log(_instance, nextLevelsent_log_208, 4);
BreakoutGamePosix_send_req_game_nextLevel(_instance);
uint8_t nextLevelsent_log_209[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x06, 0x02};
BreakoutGamePosix_send_log_log(_instance, nextLevelsent_log_209, 4);

}

}
f_BreakoutGamePosix_drawBall(_instance);
f_BreakoutGamePosix_drawPad(_instance);
int16_t ballx_210 = _instance->BreakoutGame_bx_var;
int16_t bally_211 = _instance->BreakoutGame_by_var;
int16_t padx_212 = _instance->BreakoutGame_padx_var;
int16_t pady_213 = _instance->BreakoutGame_pady_var;
BreakoutGamePosix_send_ia_updateIA(_instance, ballx_210, bally_211, padx_212, pady_213);
uint8_t updateIAsent_log_214[12] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x04, 0x13, (((ballx_210 >> 8) & 0xFF)), (((ballx_210 >> 0) & 0xFF)), (((bally_211 >> 8) & 0xFF)), (((bally_211 >> 0) & 0xFF)), (((padx_212 >> 8) & 0xFF)), (((padx_212 >> 0) & 0xFF)), (((pady_213 >> 8) & 0xFF)), (((pady_213 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, updateIAsent_log_214, 12);
BreakoutGamePosix_send_display_update(_instance);
uint8_t updatesent_log_215[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0F};
BreakoutGamePosix_send_log_log(_instance, updatesent_log_215, 4);
f_BreakoutGamePosix_log(_instance, 0);
uint8_t id_216 = 0;
uint16_t time_217 = _instance->BreakoutGame_period_var;
BreakoutGamePosix_send_clock_timer_start(_instance, id_216, time_217);
uint8_t timer_startsent_log_218[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x14, id_216, (((time_217 >> 8) & 0xFF)), (((time_217 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, timer_startsent_log_218, 7);
BreakoutGame_SC_State_event_consumed = 1;
}
}
else if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_LOSTBALL_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && id == 0 && _instance->BreakoutGame_lives_var > 0) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_LOSTBALL_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_LAUNCH_STATE;
uint8_t timer_timeouthandled_log_275[7] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x16, 0x04, 0x02, id};
BreakoutGamePosix_send_log_log(_instance, timer_timeouthandled_log_275, 7);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_LAUNCH_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
else if (BreakoutGame_SC_State_event_consumed == 0 && id == 0 && _instance->BreakoutGame_lives_var == 0) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_LOSTBALL_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_GAMEOVER_STATE;
uint8_t timer_timeouthandled_log_276[7] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x16, 0x04, 0x06, id};
BreakoutGamePosix_send_log_log(_instance, timer_timeouthandled_log_276, 7);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_GAMEOVER_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
else if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_NEXTLEVEL_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && id == 0) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_NEXTLEVEL_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_LAUNCH_STATE;
uint8_t timer_timeouthandled_log_274[7] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x16, 0x05, 0x02, id};
BreakoutGamePosix_send_log_log(_instance, timer_timeouthandled_log_274, 7);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_LAUNCH_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
uint8_t timer_timeoutlost_log_283[5] = {LOGTYPE_MESSAGE_LOST, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x16, id};
BreakoutGamePosix_send_log_log(_instance, timer_timeoutlost_log_283, 5);
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
uint8_t positionhandled_log_278[10] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x03, 0x12, 0x00, 0x00, (((x >> 8) & 0xFF)), (((x >> 0) & 0xFF)), (((y >> 8) & 0xFF)), (((y >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, positionhandled_log_278, 10);
int32_t center = (_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var - _instance->BreakoutGame_padlen_var);
center = x * center;
center = center / 200;
int16_t old_padx_32 = _instance->BreakoutGame_padx_var;
_instance->BreakoutGame_padx_var = (_instance->BreakoutGame_LEFT_var + center + (_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 2);
int16_t new_padx_32 = _instance->BreakoutGame_padx_var;
uint8_t padx_log_32[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0E, (((old_padx_32 >> 8) & 0xFF)), (((old_padx_32 >> 0) & 0xFF)), (((new_padx_32 >> 8) & 0xFF)), (((new_padx_32 >> 0) & 0xFF))};
BreakoutGamePosix_send_log_log(_instance, padx_log_32, 7);
BreakoutGame_SC_State_event_consumed = 1;
}
}
void BreakoutGamePosix_handle_display_displayReady(struct BreakoutGamePosix_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_INIT_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && 1) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_INIT_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_LAUNCH_STATE;
uint8_t displayReadyhandled_log_277[6] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x10, 0x01, 0x02};
BreakoutGamePosix_send_log_log(_instance, displayReadyhandled_log_277, 6);
BreakoutGamePosix_send_display_clear(_instance);
uint8_t clearsent_log_175[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x06};
BreakoutGamePosix_send_log_log(_instance, clearsent_log_175, 4);
f_BreakoutGamePosix_initColors(_instance);
uint8_t r_176 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_177 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_178 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGamePosix_send_display_setColor(_instance, r_176, g_177, b_178);
uint8_t setColorsent_log_179[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_176, g_177, b_178};
BreakoutGamePosix_send_log_log(_instance, setColorsent_log_179, 7);
uint8_t x_180 = 0;
uint8_t y_181 = 0;
uint8_t width_182 = _instance->BreakoutGame_XDISPSIZE_var;
uint8_t height_183 = _instance->BreakoutGame_YDISPSIZE_var;
BreakoutGamePosix_send_display_fillRect(_instance, x_180, y_181, width_182, height_183);
uint8_t fillRectsent_log_184[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_180, y_181, width_182, height_183};
BreakoutGamePosix_send_log_log(_instance, fillRectsent_log_184, 8);
uint8_t r_185 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_186 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_187 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGamePosix_send_display_setColor(_instance, r_185, g_186, b_187);
uint8_t setColorsent_log_188[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_185, g_186, b_187};
BreakoutGamePosix_send_log_log(_instance, setColorsent_log_188, 7);
uint8_t x_189 = 0;
uint8_t y_190 = 0;
uint8_t width_191 = _instance->BreakoutGame_XDISPSIZE_var;
uint8_t height_192 = 14;
BreakoutGamePosix_send_display_fillRect(_instance, x_189, y_190, width_191, height_192);
uint8_t fillRectsent_log_193[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_189, y_190, width_191, height_192};
BreakoutGamePosix_send_log_log(_instance, fillRectsent_log_193, 8);
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
uint8_t displayReadylost_log_284[4] = {LOGTYPE_MESSAGE_LOST, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x10};
BreakoutGamePosix_send_log_log(_instance, displayReadylost_log_284, 4);
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
uint8_t lostBallhandled_log_282[6] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x07, 0x01, 0x03, 0x04};
BreakoutGamePosix_send_log_log(_instance, lostBallhandled_log_282, 6);
uint8_t id_223 = 0;
BreakoutGamePosix_send_clock_timer_cancel(_instance, id_223);
uint8_t timer_cancelsent_log_224[5] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x15, id_223};
BreakoutGamePosix_send_log_log(_instance, timer_cancelsent_log_224, 5);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_LOSTBALL_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
uint8_t lostBalllost_log_287[4] = {LOGTYPE_MESSAGE_LOST, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x07, 0x01};
BreakoutGamePosix_send_log_log(_instance, lostBalllost_log_287, 4);
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
uint8_t nextLevelhandled_log_281[6] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x07, 0x02, 0x03, 0x05};
BreakoutGamePosix_send_log_log(_instance, nextLevelhandled_log_281, 6);
uint8_t id_225 = 0;
BreakoutGamePosix_send_clock_timer_cancel(_instance, id_225);
uint8_t timer_cancelsent_log_226[5] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x15, id_225};
BreakoutGamePosix_send_log_log(_instance, timer_cancelsent_log_226, 5);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_NEXTLEVEL_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
uint8_t nextLevellost_log_288[4] = {LOGTYPE_MESSAGE_LOST, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x07, 0x02};
BreakoutGamePosix_send_log_log(_instance, nextLevellost_log_288, 4);
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
uint8_t lostBallhandled_log_280[6] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x05, 0x01, 0x03, 0x04};
BreakoutGamePosix_send_log_log(_instance, lostBallhandled_log_280, 6);
uint8_t id_219 = 0;
BreakoutGamePosix_send_clock_timer_cancel(_instance, id_219);
uint8_t timer_cancelsent_log_220[5] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x15, id_219};
BreakoutGamePosix_send_log_log(_instance, timer_cancelsent_log_220, 5);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_LOSTBALL_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
uint8_t lostBalllost_log_285[4] = {LOGTYPE_MESSAGE_LOST, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x05, 0x01};
BreakoutGamePosix_send_log_log(_instance, lostBalllost_log_285, 4);
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
uint8_t nextLevelhandled_log_279[6] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x05, 0x02, 0x03, 0x05};
BreakoutGamePosix_send_log_log(_instance, nextLevelhandled_log_279, 6);
uint8_t id_221 = 0;
BreakoutGamePosix_send_clock_timer_cancel(_instance, id_221);
uint8_t timer_cancelsent_log_222[5] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x15, id_221};
BreakoutGamePosix_send_log_log(_instance, timer_cancelsent_log_222, 5);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_NEXTLEVEL_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
uint8_t nextLevellost_log_286[4] = {LOGTYPE_MESSAGE_LOST, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x05, 0x02};
BreakoutGamePosix_send_log_log(_instance, nextLevellost_log_286, 4);
BreakoutGame_SC_State_event_consumed = 1;
}
}

// Observers for outgoing messages:
void (*external_BreakoutGamePosix_send_log_log_listener)(struct BreakoutGamePosix_Instance *, uint8_t*, uint8_t)= 0x0;
void (*BreakoutGamePosix_send_log_log_listener)(struct BreakoutGamePosix_Instance *, uint8_t*, uint8_t)= 0x0;
void register_external_BreakoutGamePosix_send_log_log_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t*, uint8_t)){
external_BreakoutGamePosix_send_log_log_listener = _listener;
}
void register_BreakoutGamePosix_send_log_log_listener(void (*_listener)(struct BreakoutGamePosix_Instance *, uint8_t*, uint8_t)){
BreakoutGamePosix_send_log_log_listener = _listener;
}
void BreakoutGamePosix_send_log_log(struct BreakoutGamePosix_Instance *_instance, uint8_t* payload, uint8_t size){
if (BreakoutGamePosix_send_log_log_listener != 0x0) BreakoutGamePosix_send_log_log_listener(_instance, payload, size);
if (external_BreakoutGamePosix_send_log_log_listener != 0x0) external_BreakoutGamePosix_send_log_log_listener(_instance, payload, size);
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



