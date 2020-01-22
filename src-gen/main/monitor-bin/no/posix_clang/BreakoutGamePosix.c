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
BreakoutGamePosix_send_display_setBGColor(_instance, _instance->BreakoutGame_bgcolor_var[0], _instance->BreakoutGame_bgcolor_var[1], _instance->BreakoutGame_bgcolor_var[2]);
BreakoutGamePosix_send_display_setColor(_instance, _instance->BreakoutGame_fgcolor_var[0], _instance->BreakoutGame_fgcolor_var[1], _instance->BreakoutGame_fgcolor_var[2]);
}
// Definition of function resetBall
void f_BreakoutGamePosix_resetBall(struct BreakoutGamePosix_Instance *_instance) {
_instance->BreakoutGame_bx_var = _instance->BreakoutGame_padx_var - _instance->BreakoutGame_br_var / _instance->BreakoutGame_SCALE_var;
_instance->BreakoutGame_by_var = _instance->BreakoutGame_pady_var - _instance->BreakoutGame_br_var / _instance->BreakoutGame_SCALE_var;
_instance->BreakoutGame_dx_var = (_instance->BreakoutGame_padx_var + _instance->BreakoutGame_prevBX_var + _instance->BreakoutGame_prevBY_var) % 300 - 150;
if(_instance->BreakoutGame_dy_var > 0) {
_instance->BreakoutGame_dy_var =  -_instance->BreakoutGame_dy_var;

}
_instance->BreakoutGame_prevBX_var =  -1;
_instance->BreakoutGame_prevBY_var =  -1;
}
// Definition of function eraseBall
void f_BreakoutGamePosix_eraseBall(struct BreakoutGamePosix_Instance *_instance) {
int16_t bs = (_instance->BreakoutGame_br_var * 2) / _instance->BreakoutGame_SCALE_var;
if(_instance->BreakoutGame_prevBX_var > 0) {
BreakoutGamePosix_send_display_setColor(_instance, _instance->BreakoutGame_bgcolor_var[0], _instance->BreakoutGame_bgcolor_var[1], _instance->BreakoutGame_bgcolor_var[2]);
BreakoutGamePosix_send_display_fillRect(_instance, _instance->BreakoutGame_prevBX_var, _instance->BreakoutGame_prevBY_var, bs, bs);

}
_instance->BreakoutGame_prevBX_var =  -1;
_instance->BreakoutGame_prevBY_var =  -1;
}
// Definition of function drawBall
void f_BreakoutGamePosix_drawBall(struct BreakoutGamePosix_Instance *_instance) {
int16_t bs = (_instance->BreakoutGame_br_var * 2) / _instance->BreakoutGame_SCALE_var;
f_BreakoutGamePosix_eraseBall(_instance);
_instance->BreakoutGame_prevBX_var = (_instance->BreakoutGame_bx_var - _instance->BreakoutGame_br_var) / _instance->BreakoutGame_SCALE_var;
_instance->BreakoutGame_prevBY_var = (_instance->BreakoutGame_by_var - _instance->BreakoutGame_br_var) / _instance->BreakoutGame_SCALE_var;
BreakoutGamePosix_send_display_setColor(_instance, 183, 199, 111);
BreakoutGamePosix_send_display_fillRect(_instance, _instance->BreakoutGame_prevBX_var, _instance->BreakoutGame_prevBY_var, bs, bs);
}
// Definition of function erasePad
void f_BreakoutGamePosix_erasePad(struct BreakoutGamePosix_Instance *_instance) {
int16_t ps = _instance->BreakoutGame_padlen_var / _instance->BreakoutGame_SCALE_var;
if(_instance->BreakoutGame_prevPX_var > 0) {
BreakoutGamePosix_send_display_setColor(_instance, _instance->BreakoutGame_bgcolor_var[0], _instance->BreakoutGame_bgcolor_var[1], _instance->BreakoutGame_bgcolor_var[2]);
BreakoutGamePosix_send_display_fillRect(_instance, _instance->BreakoutGame_prevPX_var, _instance->BreakoutGame_prevPY_var, ps, 4);

}
}
// Definition of function drawPad
void f_BreakoutGamePosix_drawPad(struct BreakoutGamePosix_Instance *_instance) {
int16_t ps = _instance->BreakoutGame_padlen_var / _instance->BreakoutGame_SCALE_var;
f_BreakoutGamePosix_erasePad(_instance);
_instance->BreakoutGame_prevPX_var = (_instance->BreakoutGame_padx_var - (_instance->BreakoutGame_padlen_var / 2)) / _instance->BreakoutGame_SCALE_var;
_instance->BreakoutGame_prevPY_var = _instance->BreakoutGame_pady_var / _instance->BreakoutGame_SCALE_var;
BreakoutGamePosix_send_display_setColor(_instance, _instance->BreakoutGame_fgcolor_var[0], _instance->BreakoutGame_fgcolor_var[1], _instance->BreakoutGame_fgcolor_var[2]);
BreakoutGamePosix_send_display_fillRect(_instance, _instance->BreakoutGame_prevPX_var, _instance->BreakoutGame_prevPY_var, ps, 4);
}
// Definition of function drawCountDown
void f_BreakoutGamePosix_drawCountDown(struct BreakoutGamePosix_Instance *_instance, int16_t c) {
BreakoutGamePosix_send_display_setColor(_instance, _instance->BreakoutGame_fgcolor_var[0], _instance->BreakoutGame_fgcolor_var[1], _instance->BreakoutGame_fgcolor_var[2]);
if(c > 0) {
BreakoutGamePosix_send_display_setColor(_instance, _instance->BreakoutGame_fgcolor_var[0], _instance->BreakoutGame_fgcolor_var[1], _instance->BreakoutGame_fgcolor_var[2]);
BreakoutGamePosix_send_display_setBGColor(_instance, _instance->BreakoutGame_bgcolor_var[0], _instance->BreakoutGame_bgcolor_var[1], _instance->BreakoutGame_bgcolor_var[2]);
BreakoutGamePosix_send_display_drawInteger(_instance, 80 - 6, 90, c, 1, 4);

} else {
BreakoutGamePosix_send_display_setColor(_instance, _instance->BreakoutGame_bgcolor_var[0], _instance->BreakoutGame_bgcolor_var[1], _instance->BreakoutGame_bgcolor_var[2]);
BreakoutGamePosix_send_display_fillRect(_instance, 80 - 6, 90, 12, 20);

}
}
// Definition of function drawWalls
void f_BreakoutGamePosix_drawWalls(struct BreakoutGamePosix_Instance *_instance) {
BreakoutGamePosix_send_display_setColor(_instance, _instance->BreakoutGame_fgcolor_var[0], _instance->BreakoutGame_fgcolor_var[1], _instance->BreakoutGame_fgcolor_var[2]);
uint8_t left = (_instance->BreakoutGame_LEFT_var / _instance->BreakoutGame_SCALE_var);
uint8_t right = (_instance->BreakoutGame_RIGHT_var / _instance->BreakoutGame_SCALE_var);
uint8_t top = (_instance->BreakoutGame_TOP_var / _instance->BreakoutGame_SCALE_var);
uint8_t bottom = (_instance->BreakoutGame_BOTTOM_var / _instance->BreakoutGame_SCALE_var);
uint8_t xcenter = ((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / _instance->BreakoutGame_SCALE_var);
uint8_t ycenter = ((_instance->BreakoutGame_BOTTOM_var - _instance->BreakoutGame_TOP_var) / _instance->BreakoutGame_SCALE_var);
BreakoutGamePosix_send_display_fillRect(_instance, left - 1, top - 1, xcenter + 1, 1);
BreakoutGamePosix_send_display_fillRect(_instance, left - 1, bottom, xcenter + 1, 1);
BreakoutGamePosix_send_display_fillRect(_instance, left - 1, top, 1, ycenter);
BreakoutGamePosix_send_display_fillRect(_instance, right, top, 1, ycenter);
}
// Definition of function bitIsSet
bool f_BreakoutGamePosix_bitIsSet(struct BreakoutGamePosix_Instance *_instance, uint8_t variable, uint8_t bit) {
return (((1 << bit) & variable) != 0);
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
return result;
}
// Definition of function drawBrick
void f_BreakoutGamePosix_drawBrick(struct BreakoutGamePosix_Instance *_instance, uint8_t x, uint8_t y) {
uint8_t bx = ((_instance->BreakoutGame_LEFT_var + ((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 8) * x) / _instance->BreakoutGame_SCALE_var + 1);
uint8_t by = ((_instance->BreakoutGame_TOP_var + 20 * _instance->BreakoutGame_SCALE_var + _instance->BreakoutGame_BRICK_HEIGHT_var * y * _instance->BreakoutGame_SCALE_var) / _instance->BreakoutGame_SCALE_var + 1);
uint8_t w = (((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 8) / _instance->BreakoutGame_SCALE_var - 2);
uint8_t h = (_instance->BreakoutGame_BRICK_HEIGHT_var - 2);
BreakoutGamePosix_send_display_setColor(_instance, 155, 103, 89);
BreakoutGamePosix_send_display_fillRect(_instance, bx, by, w, h);
BreakoutGamePosix_send_display_setColor(_instance, 100, 56, 43);
BreakoutGamePosix_send_display_drawRect(_instance, bx, by, w, h);
}
// Definition of function removeBrick
void f_BreakoutGamePosix_removeBrick(struct BreakoutGamePosix_Instance *_instance, uint8_t x, uint8_t y) {
uint8_t bx = ((_instance->BreakoutGame_LEFT_var + ((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 8) * x) / _instance->BreakoutGame_SCALE_var + 1);
uint8_t by = ((_instance->BreakoutGame_TOP_var + 20 * _instance->BreakoutGame_SCALE_var + _instance->BreakoutGame_BRICK_HEIGHT_var * y * _instance->BreakoutGame_SCALE_var) / _instance->BreakoutGame_SCALE_var + 1);
BreakoutGamePosix_send_display_setColor(_instance, _instance->BreakoutGame_bgcolor_var[0], _instance->BreakoutGame_bgcolor_var[1], _instance->BreakoutGame_bgcolor_var[2]);
BreakoutGamePosix_send_display_fillRect(_instance, bx, by, (((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 8) / _instance->BreakoutGame_SCALE_var - 2), _instance->BreakoutGame_BRICK_HEIGHT_var - 2);
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
return result;
}
// Definition of function drawLevel
void f_BreakoutGamePosix_drawLevel(struct BreakoutGamePosix_Instance *_instance) {
BreakoutGamePosix_send_display_setColor(_instance, 158, 209, 130);
BreakoutGamePosix_send_display_setBGColor(_instance, _instance->BreakoutGame_fgcolor_var[0], _instance->BreakoutGame_fgcolor_var[1], _instance->BreakoutGame_fgcolor_var[2]);
BreakoutGamePosix_send_display_setColor(_instance, _instance->BreakoutGame_bgcolor_var[0], _instance->BreakoutGame_bgcolor_var[1], _instance->BreakoutGame_bgcolor_var[2]);
BreakoutGamePosix_send_display_drawInteger(_instance, 6, 2, _instance->BreakoutGame_level_var, 2, 2);
}
// Definition of function incrementScore
void f_BreakoutGamePosix_incrementScore(struct BreakoutGamePosix_Instance *_instance, int8_t diff) {
_instance->BreakoutGame_score_var = _instance->BreakoutGame_score_var + diff;
if(_instance->BreakoutGame_score_var < 0) {
_instance->BreakoutGame_score_var = 0;

}
f_BreakoutGamePosix_drawScore(_instance);
}
// Definition of function drawScore
void f_BreakoutGamePosix_drawScore(struct BreakoutGamePosix_Instance *_instance) {
BreakoutGamePosix_send_display_setColor(_instance, 158, 209, 130);
BreakoutGamePosix_send_display_setBGColor(_instance, _instance->BreakoutGame_fgcolor_var[0], _instance->BreakoutGame_fgcolor_var[1], _instance->BreakoutGame_fgcolor_var[2]);
BreakoutGamePosix_send_display_drawInteger(_instance, 58, 2, _instance->BreakoutGame_score_var, 5, 2);
}
// Definition of function drawLives
void f_BreakoutGamePosix_drawLives(struct BreakoutGamePosix_Instance *_instance) {
BreakoutGamePosix_send_display_setColor(_instance, _instance->BreakoutGame_fgcolor_var[0], _instance->BreakoutGame_fgcolor_var[1], _instance->BreakoutGame_fgcolor_var[2]);
BreakoutGamePosix_send_display_fillRect(_instance, 124, 4, 24 + 6, 6);
BreakoutGamePosix_send_display_setColor(_instance, 183, 199, 111);
uint8_t i = 0;
while(i < _instance->BreakoutGame_lives_var) {
BreakoutGamePosix_send_display_fillRect(_instance, 124 + (2 - i) * 12, 4, 6, 6);
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
case BREAKOUTGAME_SC_LAUNCH_STATE:{
BreakoutGamePosix_send_clock_timer_start(_instance, 0, _instance->BreakoutGame_period_var);
_instance->BreakoutGame_SC_LAUNCH_countdown_var = 3;
f_BreakoutGamePosix_drawScore(_instance);
f_BreakoutGamePosix_drawLives(_instance);
BreakoutGamePosix_send_display_update(_instance);
break;
}
case BREAKOUTGAME_SC_INIT_STATE:{
_instance->BreakoutGame_startTime_var = f_BreakoutGamePosix_timestamp(_instance);
BreakoutGamePosix_send_display_create(_instance, _instance->BreakoutGame_XDISPSIZE_var, _instance->BreakoutGame_YDISPSIZE_var);
break;
}
case BREAKOUTGAME_SC_NEXTLEVEL_STATE:{
BreakoutGamePosix_send_clock_timer_start(_instance, 0, _instance->BreakoutGame_period_var);
_instance->BreakoutGame_level_var = _instance->BreakoutGame_level_var + 1;
f_BreakoutGamePosix_drawLevel(_instance);
f_BreakoutGamePosix_eraseBall(_instance);
f_BreakoutGamePosix_erasePad(_instance);
if((_instance->BreakoutGame_level_var % 2) == 0 && _instance->BreakoutGame_padlen_var > 5 * _instance->BreakoutGame_SCALE_var) {
_instance->BreakoutGame_padlen_var = _instance->BreakoutGame_padlen_var - (4 * _instance->BreakoutGame_SCALE_var);

}
if((_instance->BreakoutGame_level_var % 2) == 1) {
_instance->BreakoutGame_dy_var = (_instance->BreakoutGame_dy_var * 3) / 2;

}
f_BreakoutGamePosix_drawLives(_instance);
f_BreakoutGamePosix_createBricks(_instance);
BreakoutGamePosix_send_display_update(_instance);
break;
}
case BREAKOUTGAME_SC_LOSTBALL_STATE:{
BreakoutGamePosix_send_clock_timer_start(_instance, 0, _instance->BreakoutGame_period_var);
_instance->BreakoutGame_lives_var = _instance->BreakoutGame_lives_var - 1;
f_BreakoutGamePosix_eraseBall(_instance);
f_BreakoutGamePosix_erasePad(_instance);
f_BreakoutGamePosix_drawLives(_instance);
BreakoutGamePosix_send_display_update(_instance);
f_BreakoutGamePosix_log(_instance, 1);
break;
}
case BREAKOUTGAME_SC_GAMEOVER_STATE:{
f_BreakoutGamePosix_eraseBall(_instance);
f_BreakoutGamePosix_erasePad(_instance);
BreakoutGamePosix_send_display_setColor(_instance, 255, 255, 255);
BreakoutGamePosix_send_display_fillRect(_instance, 8, 30, 142, 76);
BreakoutGamePosix_send_display_setColor(_instance, _instance->BreakoutGame_fgcolor_var[0], _instance->BreakoutGame_fgcolor_var[1], _instance->BreakoutGame_fgcolor_var[2]);
BreakoutGamePosix_send_display_fillRect(_instance, 9, 31, 140, 50);
BreakoutGamePosix_send_display_setBGColor(_instance, _instance->BreakoutGame_fgcolor_var[0], _instance->BreakoutGame_fgcolor_var[1], _instance->BreakoutGame_fgcolor_var[2]);
BreakoutGamePosix_send_display_setColor(_instance, 158, 209, 130);
BreakoutGamePosix_send_display_drawInteger(_instance, 23, 40, _instance->BreakoutGame_score_var, 5, 6);
BreakoutGamePosix_send_display_drawThingML(_instance, 26, 87);
BreakoutGamePosix_send_display_update(_instance);
f_BreakoutGamePosix_log(_instance, 1);
_instance->BreakoutGame_stopTime_var = f_BreakoutGamePosix_timestamp(_instance);
f_BreakoutGamePosix_quit(_instance);
_instance->active = false;
break;
}
case BREAKOUTGAME_SC_PLAY_STATE:{
BreakoutGamePosix_send_clock_timer_start(_instance, 0, _instance->BreakoutGame_period_var);
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
case BREAKOUTGAME_SC_LAUNCH_STATE:{
break;}
case BREAKOUTGAME_SC_INIT_STATE:{
break;}
case BREAKOUTGAME_SC_NEXTLEVEL_STATE:{
break;}
case BREAKOUTGAME_SC_LOSTBALL_STATE:{
break;}
case BREAKOUTGAME_SC_GAMEOVER_STATE:{
break;}
case BREAKOUTGAME_SC_PLAY_STATE:{
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
f_BreakoutGamePosix_drawCountDown(_instance, 0);
f_BreakoutGamePosix_resetBall(_instance);
BreakoutGamePosix_send_display_update(_instance);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_PLAY_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
else if (BreakoutGame_SC_State_event_consumed == 0 && id == 0 && _instance->BreakoutGame_SC_LAUNCH_countdown_var > 0) {
BreakoutGamePosix_send_clock_timer_start(_instance, 0, _instance->BreakoutGame_period_var);
f_BreakoutGamePosix_drawPad(_instance);
if((_instance->BreakoutGame_SC_LAUNCH_countdown_var % 30) == 0) {
f_BreakoutGamePosix_drawCountDown(_instance, _instance->BreakoutGame_SC_LAUNCH_countdown_var / 30);

}
_instance->BreakoutGame_SC_LAUNCH_countdown_var = _instance->BreakoutGame_SC_LAUNCH_countdown_var - 1;
BreakoutGamePosix_send_display_update(_instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
else if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_PLAY_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && id == 0) {
_instance->BreakoutGame_bx_var = _instance->BreakoutGame_bx_var + _instance->BreakoutGame_dx_var;
_instance->BreakoutGame_by_var = _instance->BreakoutGame_by_var + _instance->BreakoutGame_dy_var;
int16_t wl = _instance->BreakoutGame_LEFT_var + _instance->BreakoutGame_br_var;
int16_t wr = _instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_br_var;
int16_t wt = _instance->BreakoutGame_TOP_var + _instance->BreakoutGame_br_var;
int16_t wb = _instance->BreakoutGame_BOTTOM_var - _instance->BreakoutGame_br_var;
if(_instance->BreakoutGame_bx_var < wl) {
_instance->BreakoutGame_dx_var =  -_instance->BreakoutGame_dx_var;
_instance->BreakoutGame_bx_var = 2 * wl - _instance->BreakoutGame_bx_var;
f_BreakoutGamePosix_incrementScore(_instance,  -1);

} else {
if(_instance->BreakoutGame_bx_var > wr) {
_instance->BreakoutGame_dx_var =  -_instance->BreakoutGame_dx_var;
_instance->BreakoutGame_bx_var = 2 * wr - _instance->BreakoutGame_bx_var;
f_BreakoutGamePosix_incrementScore(_instance,  -1);

}

}
if(_instance->BreakoutGame_by_var < wt) {
_instance->BreakoutGame_dy_var =  -_instance->BreakoutGame_dy_var;
_instance->BreakoutGame_by_var = 2 * wt - _instance->BreakoutGame_by_var;
f_BreakoutGamePosix_incrementScore(_instance,  -1);

} else {
if(_instance->BreakoutGame_by_var > wb) {
BreakoutGamePosix_send_game_lostBall(_instance);
BreakoutGamePosix_send_req_game_lostBall(_instance);

}

}
if(_instance->BreakoutGame_dy_var > 0) {
if(_instance->BreakoutGame_by_var > _instance->BreakoutGame_pady_var - _instance->BreakoutGame_br_var && _instance->BreakoutGame_by_var < _instance->BreakoutGame_pady_var + _instance->BreakoutGame_br_var) {
if(_instance->BreakoutGame_bx_var > _instance->BreakoutGame_padx_var - _instance->BreakoutGame_padlen_var / 2 && _instance->BreakoutGame_bx_var < _instance->BreakoutGame_padx_var + _instance->BreakoutGame_padlen_var / 2) {
_instance->BreakoutGame_dy_var =  -_instance->BreakoutGame_dy_var;
_instance->BreakoutGame_by_var = 2 * (_instance->BreakoutGame_pady_var - _instance->BreakoutGame_br_var) - _instance->BreakoutGame_by_var;
_instance->BreakoutGame_dx_var = _instance->BreakoutGame_dx_var / 4 + (_instance->BreakoutGame_bx_var - _instance->BreakoutGame_padx_var) / 4;

}

}

}
bool collision = f_BreakoutGamePosix_collideBrick(_instance, _instance->BreakoutGame_bx_var - _instance->BreakoutGame_br_var, _instance->BreakoutGame_by_var - _instance->BreakoutGame_br_var) || f_BreakoutGamePosix_collideBrick(_instance, _instance->BreakoutGame_bx_var + _instance->BreakoutGame_br_var, _instance->BreakoutGame_by_var - _instance->BreakoutGame_br_var) || f_BreakoutGamePosix_collideBrick(_instance, _instance->BreakoutGame_bx_var + _instance->BreakoutGame_br_var, _instance->BreakoutGame_by_var + _instance->BreakoutGame_br_var) || f_BreakoutGamePosix_collideBrick(_instance, _instance->BreakoutGame_bx_var - _instance->BreakoutGame_br_var, _instance->BreakoutGame_by_var + _instance->BreakoutGame_br_var);
if(collision) {
_instance->BreakoutGame_dy_var =  -_instance->BreakoutGame_dy_var;
f_BreakoutGamePosix_incrementScore(_instance, 10);
if(f_BreakoutGamePosix_bricksLeft(_instance) == 0) {
BreakoutGamePosix_send_game_nextLevel(_instance);
BreakoutGamePosix_send_req_game_nextLevel(_instance);

}

}
f_BreakoutGamePosix_drawBall(_instance);
f_BreakoutGamePosix_drawPad(_instance);
BreakoutGamePosix_send_ia_updateIA(_instance, _instance->BreakoutGame_bx_var, _instance->BreakoutGame_by_var, _instance->BreakoutGame_padx_var, _instance->BreakoutGame_pady_var);
BreakoutGamePosix_send_display_update(_instance);
f_BreakoutGamePosix_log(_instance, 0);
BreakoutGamePosix_send_clock_timer_start(_instance, 0, _instance->BreakoutGame_period_var);
BreakoutGame_SC_State_event_consumed = 1;
}
}
else if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_LOSTBALL_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && id == 0 && _instance->BreakoutGame_lives_var > 0) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_LOSTBALL_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_LAUNCH_STATE;
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_LAUNCH_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
else if (BreakoutGame_SC_State_event_consumed == 0 && id == 0 && _instance->BreakoutGame_lives_var == 0) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_LOSTBALL_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_GAMEOVER_STATE;
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_GAMEOVER_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
else if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_NEXTLEVEL_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && id == 0) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_NEXTLEVEL_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_LAUNCH_STATE;
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_LAUNCH_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void BreakoutGamePosix_handle_display_displayReady(struct BreakoutGamePosix_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_INIT_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && 1) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_INIT_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_LAUNCH_STATE;
BreakoutGamePosix_send_display_clear(_instance);
f_BreakoutGamePosix_initColors(_instance);
BreakoutGamePosix_send_display_setColor(_instance, _instance->BreakoutGame_bgcolor_var[0], _instance->BreakoutGame_bgcolor_var[1], _instance->BreakoutGame_bgcolor_var[2]);
BreakoutGamePosix_send_display_fillRect(_instance, 0, 0, _instance->BreakoutGame_XDISPSIZE_var, _instance->BreakoutGame_YDISPSIZE_var);
BreakoutGamePosix_send_display_setColor(_instance, _instance->BreakoutGame_fgcolor_var[0], _instance->BreakoutGame_fgcolor_var[1], _instance->BreakoutGame_fgcolor_var[2]);
BreakoutGamePosix_send_display_fillRect(_instance, 0, 0, _instance->BreakoutGame_XDISPSIZE_var, 14);
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
}
void BreakoutGamePosix_handle_controller_position(struct BreakoutGamePosix_Instance *_instance, int16_t x, int16_t y) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
int32_t center = (_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var - _instance->BreakoutGame_padlen_var);
center = x * center;
center = center / 200;
_instance->BreakoutGame_padx_var = (_instance->BreakoutGame_LEFT_var + center + (_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 2);
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
BreakoutGamePosix_send_clock_timer_cancel(_instance, 0);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_LOSTBALL_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void BreakoutGamePosix_handle_pro_game_nextLevel(struct BreakoutGamePosix_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_PLAY_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && 1) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_PLAY_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_NEXTLEVEL_STATE;
BreakoutGamePosix_send_clock_timer_cancel(_instance, 0);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_NEXTLEVEL_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void BreakoutGamePosix_handle_game_lostBall(struct BreakoutGamePosix_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_PLAY_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && 1) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_PLAY_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_LOSTBALL_STATE;
BreakoutGamePosix_send_clock_timer_cancel(_instance, 0);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_LOSTBALL_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void BreakoutGamePosix_handle_game_nextLevel(struct BreakoutGamePosix_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_PLAY_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && 1) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_PLAY_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_NEXTLEVEL_STATE;
BreakoutGamePosix_send_clock_timer_cancel(_instance, 0);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_NEXTLEVEL_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}

// Observers for outgoing messages:
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



