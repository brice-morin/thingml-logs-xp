/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing Binary2StringLogger
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "Binary2StringLogger.h"

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
fprintf(stdout, "function_called(BreakoutGame0, initColors, void");
fprintf(stdout, ", _");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(func_ == 2) {
fprintf(stdout, "function_called(BreakoutGame0, resetBall, void");
fprintf(stdout, ", _");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(func_ == 3) {
fprintf(stdout, "function_called(BreakoutGame0, eraseBall, void");
fprintf(stdout, ", _");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(func_ == 4) {
fprintf(stdout, "function_called(BreakoutGame0, drawBall, void");
fprintf(stdout, ", _");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(func_ == 5) {
fprintf(stdout, "function_called(BreakoutGame0, erasePad, void");
fprintf(stdout, ", _");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(func_ == 6) {
fprintf(stdout, "function_called(BreakoutGame0, drawPad, void");
fprintf(stdout, ", _");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(func_ == 7) {
fprintf(stdout, "function_called(BreakoutGame0, drawCountDown, void");
fprintf(stdout, ", _");
fprintf(stdout, ", c=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[2]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(func_ == 8) {
fprintf(stdout, "function_called(BreakoutGame0, drawWalls, void");
fprintf(stdout, ", _");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(func_ == 9) {
fprintf(stdout, "function_called(BreakoutGame0, bitIsSet, Boolean");
fprintf(stdout, ", ");
fprintf(stdout, "%s", (((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0) != 0)) ? "true" : "false");
fprintf(stdout, ", variable=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[2]) << 0)));
fprintf(stdout, ", bit=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(func_ == 10) {
fprintf(stdout, "function_called(BreakoutGame0, createBricks, void");
fprintf(stdout, ", _");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(func_ == 11) {
fprintf(stdout, "function_called(BreakoutGame0, bricksLeft, UInt8");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[2]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(func_ == 12) {
fprintf(stdout, "function_called(BreakoutGame0, drawBrick, void");
fprintf(stdout, ", _");
fprintf(stdout, ", x=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[2]) << 0)));
fprintf(stdout, ", y=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(func_ == 13) {
fprintf(stdout, "function_called(BreakoutGame0, removeBrick, void");
fprintf(stdout, ", _");
fprintf(stdout, ", x=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[2]) << 0)));
fprintf(stdout, ", y=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(func_ == 14) {
fprintf(stdout, "function_called(BreakoutGame0, collideBrick, Boolean");
fprintf(stdout, ", ");
fprintf(stdout, "%s", (((f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0) != 0)) ? "true" : "false");
fprintf(stdout, ", xpos=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[2]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
fprintf(stdout, ", ypos=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[5]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(func_ == 15) {
fprintf(stdout, "function_called(BreakoutGame0, drawLevel, void");
fprintf(stdout, ", _");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(func_ == 16) {
fprintf(stdout, "function_called(BreakoutGame0, incrementScore, void");
fprintf(stdout, ", _");
fprintf(stdout, ", diff=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[2]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(func_ == 17) {
fprintf(stdout, "function_called(BreakoutGame0, drawScore, void");
fprintf(stdout, ", _");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(func_ == 18) {
fprintf(stdout, "function_called(BreakoutGame0, drawLives, void");
fprintf(stdout, ", _");
fprintf(stdout, ")");
fprintf(stdout, "\n");

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
if(prop == 0) {
fprintf(stdout, "property_changed(BreakoutGame0, XDISPSIZE, UInt8");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 1) {
fprintf(stdout, "property_changed(BreakoutGame0, YDISPSIZE, UInt8");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 2) {
fprintf(stdout, "property_changed(BreakoutGame0, SCALE, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 3) {
fprintf(stdout, "property_changed(BreakoutGame0, XMAX, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 4) {
fprintf(stdout, "property_changed(BreakoutGame0, YMAX, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 5) {
fprintf(stdout, "property_changed(BreakoutGame0, TOP, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 6) {
fprintf(stdout, "property_changed(BreakoutGame0, BOTTOM, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 7) {
fprintf(stdout, "property_changed(BreakoutGame0, LEFT, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 8) {
fprintf(stdout, "property_changed(BreakoutGame0, RIGHT, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 9) {
fprintf(stdout, "property_changed(BreakoutGame0, br, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 10) {
fprintf(stdout, "property_changed(BreakoutGame0, bx, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 11) {
fprintf(stdout, "property_changed(BreakoutGame0, by, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 12) {
fprintf(stdout, "property_changed(BreakoutGame0, dx, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 13) {
fprintf(stdout, "property_changed(BreakoutGame0, dy, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 14) {
fprintf(stdout, "property_changed(BreakoutGame0, padx, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 15) {
fprintf(stdout, "property_changed(BreakoutGame0, pady, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 16) {
fprintf(stdout, "property_changed(BreakoutGame0, padlen, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 17) {
fprintf(stdout, "property_changed(BreakoutGame0, prevBX, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 18) {
fprintf(stdout, "property_changed(BreakoutGame0, prevBY, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 19) {
fprintf(stdout, "property_changed(BreakoutGame0, bgcolor, UInt8");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 20) {
fprintf(stdout, "property_changed(BreakoutGame0, fgcolor, UInt8");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 21) {
fprintf(stdout, "property_changed(BreakoutGame0, period, UInt16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 22) {
fprintf(stdout, "property_changed(BreakoutGame0, prevPX, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 23) {
fprintf(stdout, "property_changed(BreakoutGame0, prevPY, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 24) {
fprintf(stdout, "property_changed(BreakoutGame0, BRICK_ROWS, UInt8");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 25) {
fprintf(stdout, "property_changed(BreakoutGame0, BRICK_HEIGHT, UInt8");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 26) {
fprintf(stdout, "property_changed(BreakoutGame0, bricks, UInt8");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 27) {
fprintf(stdout, "property_changed(BreakoutGame0, score, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 28) {
fprintf(stdout, "property_changed(BreakoutGame0, lives, UInt8");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 29) {
fprintf(stdout, "property_changed(BreakoutGame0, level, UInt8");
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
fprintf(stdout, ", ");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

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
fprintf(stdout, "message_lost(BreakoutGame0, clock, timer_timeout");
fprintf(stdout, ", id=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 1 && messageID == 15) {
fprintf(stdout, "message_lost(BreakoutGame0, display, displayReady");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 2 && messageID == 17) {
fprintf(stdout, "message_lost(BreakoutGame0, controller, position");
fprintf(stdout, ", x=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[5]) << 0)));
fprintf(stdout, ", y=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[6]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[7]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 4 && messageID == 0) {
fprintf(stdout, "message_lost(BreakoutGame0, game, lostBall");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 6 && messageID == 0) {
fprintf(stdout, "message_lost(BreakoutGame0, pro_game, lostBall");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 4 && messageID == 1) {
fprintf(stdout, "message_lost(BreakoutGame0, game, nextLevel");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 6 && messageID == 1) {
fprintf(stdout, "message_lost(BreakoutGame0, pro_game, nextLevel");
fprintf(stdout, ")");
fprintf(stdout, "\n");

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
fprintf(stdout, "message_sent(BreakoutGame0, clock, timer_start");
fprintf(stdout, ", id=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", time=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 0 && messageID == 20) {
fprintf(stdout, "message_sent(BreakoutGame0, clock, timer_cancel");
fprintf(stdout, ", id=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 1 && messageID == 5) {
fprintf(stdout, "message_sent(BreakoutGame0, display, clear");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 1 && messageID == 6) {
fprintf(stdout, "message_sent(BreakoutGame0, display, setColor");
fprintf(stdout, ", r=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", g=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 0)));
fprintf(stdout, ", b=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 1 && messageID == 7) {
fprintf(stdout, "message_sent(BreakoutGame0, display, setBGColor");
fprintf(stdout, ", r=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", g=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 0)));
fprintf(stdout, ", b=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 1 && messageID == 8) {
fprintf(stdout, "message_sent(BreakoutGame0, display, drawRect");
fprintf(stdout, ", x=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", y=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 0)));
fprintf(stdout, ", width=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
fprintf(stdout, ", height=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[7]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 1 && messageID == 9) {
fprintf(stdout, "message_sent(BreakoutGame0, display, fillRect");
fprintf(stdout, ", x=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", y=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 0)));
fprintf(stdout, ", width=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
fprintf(stdout, ", height=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[7]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 1 && messageID == 10) {
fprintf(stdout, "message_sent(BreakoutGame0, display, drawInteger");
fprintf(stdout, ", x=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", y=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 0)));
fprintf(stdout, ", v=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[6]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[7]) << 0)));
fprintf(stdout, ", digits=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[8]) << 0)));
fprintf(stdout, ", scale=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[9]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 1 && messageID == 11) {
fprintf(stdout, "message_sent(BreakoutGame0, display, drawThingML");
fprintf(stdout, ", x=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", y=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 1 && messageID == 12) {
fprintf(stdout, "message_sent(BreakoutGame0, display, create");
fprintf(stdout, ", xsize=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", ysize=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 1 && messageID == 14) {
fprintf(stdout, "message_sent(BreakoutGame0, display, update");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 3 && messageID == 18) {
fprintf(stdout, "message_sent(BreakoutGame0, ia, updateIA");
fprintf(stdout, ", ballx=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[4]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[5]) << 0)));
fprintf(stdout, ", bally=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[6]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[7]) << 0)));
fprintf(stdout, ", padx=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[8]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[9]) << 0)));
fprintf(stdout, ", pady=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[10]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[11]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 4 && messageID == 0) {
fprintf(stdout, "message_sent(BreakoutGame0, game, lostBall");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 5 && messageID == 0) {
fprintf(stdout, "message_sent(BreakoutGame0, req_game, lostBall");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 4 && messageID == 1) {
fprintf(stdout, "message_sent(BreakoutGame0, game, nextLevel");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 5 && messageID == 1) {
fprintf(stdout, "message_sent(BreakoutGame0, req_game, nextLevel");
fprintf(stdout, ")");
fprintf(stdout, "\n");

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
fprintf(stdout, "message_handled(BreakoutGame0, controller, position, SC, _, ");
fprintf(stdout, ", x=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[4]) << 0)));
fprintf(stdout, ", y=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[5]) << 8 | f_Binary2StringLogger_get_byte(_instance, payload[6]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(handlerID == 1) {
fprintf(stdout, "message_handled(BreakoutGame0, display, displayReady, INIT, LAUNCH, ");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(handlerID == 2) {
fprintf(stdout, "message_handled(BreakoutGame0, clock, timer_timeout, LAUNCH, _, ");
fprintf(stdout, ", id=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(handlerID == 3) {
fprintf(stdout, "message_handled(BreakoutGame0, clock, timer_timeout, LAUNCH, PLAY, ");
fprintf(stdout, ", id=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(handlerID == 4) {
fprintf(stdout, "message_handled(BreakoutGame0, clock, timer_timeout, PLAY, _, ");
fprintf(stdout, ", id=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(handlerID == 5) {
fprintf(stdout, "message_handled(BreakoutGame0, game, lostBall, PLAY, LOSTBALL, ");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(handlerID == 6) {
fprintf(stdout, "message_handled(BreakoutGame0, game, nextLevel, PLAY, NEXTLEVEL, ");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(handlerID == 7) {
fprintf(stdout, "message_handled(BreakoutGame0, pro_game, lostBall, PLAY, LOSTBALL, ");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(handlerID == 8) {
fprintf(stdout, "message_handled(BreakoutGame0, pro_game, nextLevel, PLAY, NEXTLEVEL, ");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(handlerID == 9) {
fprintf(stdout, "message_handled(BreakoutGame0, clock, timer_timeout, LOSTBALL, LAUNCH, ");
fprintf(stdout, ", id=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(handlerID == 10) {
fprintf(stdout, "message_handled(BreakoutGame0, clock, timer_timeout, LOSTBALL, GAMEOVER, ");
fprintf(stdout, ", id=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(handlerID == 11) {
fprintf(stdout, "message_handled(BreakoutGame0, clock, timer_timeout, NEXTLEVEL, LAUNCH, ");
fprintf(stdout, ", id=");
fprintf(stdout, "%i",((f_Binary2StringLogger_get_byte(_instance, payload[3]) << 0)));
fprintf(stdout, ")");
fprintf(stdout, "\n");

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
fprintf(stdout, "unknown");
fprintf(stdout, "\n");

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
void Logger_OnExit(int state, struct Binary2StringLogger_Instance *_instance) {
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



