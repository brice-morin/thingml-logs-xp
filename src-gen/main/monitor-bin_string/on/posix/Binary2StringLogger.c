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
char * f_Binary2StringLogger_stateName(struct Binary2StringLogger_Instance *_instance, uint8_t id);
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
// Definition of function stateName
char * f_Binary2StringLogger_stateName(struct Binary2StringLogger_Instance *_instance, uint8_t id) {
if(id == 0) {
return "BreakoutGame.SC";

} else {
if(id == 1) {
return "BreakoutGame.SC.INIT";

} else {
if(id == 2) {
return "BreakoutGame.SC.LAUNCH";

} else {
if(id == 3) {
return "BreakoutGame.SC.PLAY";

} else {
if(id == 4) {
return "BreakoutGame.SC.LOSTBALL";

} else {
if(id == 5) {
return "BreakoutGame.SC.NEXTLEVEL";

} else {
if(id == 6) {
return "BreakoutGame.SC.GAMEOVER";

} else {
if(id == 7) {
return "Logger";

} else {
if(id == 8) {
return "Logger.null.STARTUP";

} else {
if(id == 9) {
return "Logger.null.ON";

} else {
if(id == 10) {
return "Logger.null.OFF";

} else {
if(id == 11) {
return "HeadlessDisplay";

} else {
if(id == 12) {
return "HeadlessDisplay.null.INIT";

} else {
if(id == 13) {
return "HeadlessDisplay.null.MOCK";

} else {
if(id == 14) {
return "BasicIAController.SC";

} else {
if(id == 15) {
return "BasicIAController.SC.Following";

} else {
if(id == 16) {
return "TimerJava.SoftTimer";

} else {
if(id == 17) {
return "TimerJava.SoftTimer.default";

} else {
if(id == 18) {
return "TimerJS.SoftTimer";

} else {
if(id == 19) {
return "TimerJS.SoftTimer.default";

} else {
if(id == 20) {
return "TimerNodeJS.SoftTimer";

} else {
if(id == 21) {
return "TimerNodeJS.SoftTimer.default";

} else {
if(id == 22) {
return "TimerPosix.SoftTimer";

} else {
if(id == 23) {
return "TimerPosix.SoftTimer.default";

} else {
if(id == 24) {
return "TimerArduino.SoftTimer";

} else {
if(id == 25) {
return "TimerArduino.SoftTimer.default";

} else {
if(id == 26) {
return "TimerGo.SoftTimer";

} else {
if(id == 27) {
return "TimerGo.SoftTimer.default";

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
return "unknown";
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
uint8_t bin_c[2] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[3 + 1])};
int16_t c = (bin_c[0] << 8 | bin_c[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
c = c + 256;

}
fprintf(stdout, "function_called(BreakoutGame0, drawCountDown, void");
fprintf(stdout, ", _");
fprintf(stdout, ", c=");
fprintf(stdout, "%i",c);
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
uint8_t bin_result[1] = {f_Binary2StringLogger_get_byte(_instance, payload[size - 1 + 0])};
bool result = (bin_result[0] << 0) != 0;
uint8_t bin_variable[1] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0])};
uint8_t variable = (bin_variable[0] << 0);
uint8_t bin_bit[1] = {f_Binary2StringLogger_get_byte(_instance, payload[4 + 0])};
uint8_t bit = (bin_bit[0] << 0);
fprintf(stdout, "function_called(BreakoutGame0, bitIsSet, Boolean");
fprintf(stdout, ", ");
fprintf(stdout, "%s", (result) ? "true" : "false");
fprintf(stdout, ", variable=");
fprintf(stdout, "%i",variable);
fprintf(stdout, ", bit=");
fprintf(stdout, "%i",bit);
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
uint8_t bin_result[1] = {f_Binary2StringLogger_get_byte(_instance, payload[size - 1 + 0])};
uint8_t result = (bin_result[0] << 0);
fprintf(stdout, "function_called(BreakoutGame0, bricksLeft, UInt8");
fprintf(stdout, ", ");
fprintf(stdout, "%i",result);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(func_ == 12) {
uint8_t bin_x[1] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0])};
uint8_t x = (bin_x[0] << 0);
uint8_t bin_y[1] = {f_Binary2StringLogger_get_byte(_instance, payload[4 + 0])};
uint8_t y = (bin_y[0] << 0);
fprintf(stdout, "function_called(BreakoutGame0, drawBrick, void");
fprintf(stdout, ", _");
fprintf(stdout, ", x=");
fprintf(stdout, "%i",x);
fprintf(stdout, ", y=");
fprintf(stdout, "%i",y);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(func_ == 13) {
uint8_t bin_x[1] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0])};
uint8_t x = (bin_x[0] << 0);
uint8_t bin_y[1] = {f_Binary2StringLogger_get_byte(_instance, payload[4 + 0])};
uint8_t y = (bin_y[0] << 0);
fprintf(stdout, "function_called(BreakoutGame0, removeBrick, void");
fprintf(stdout, ", _");
fprintf(stdout, ", x=");
fprintf(stdout, "%i",x);
fprintf(stdout, ", y=");
fprintf(stdout, "%i",y);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(func_ == 14) {
uint8_t bin_result[1] = {f_Binary2StringLogger_get_byte(_instance, payload[size - 1 + 0])};
bool result = (bin_result[0] << 0) != 0;
uint8_t bin_xpos[2] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[3 + 1])};
int16_t xpos = (bin_xpos[0] << 8 | bin_xpos[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
xpos = xpos + 256;

}
uint8_t bin_ypos[2] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[5 + 1])};
int16_t ypos = (bin_ypos[0] << 8 | bin_ypos[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
ypos = ypos + 256;

}
fprintf(stdout, "function_called(BreakoutGame0, collideBrick, Boolean");
fprintf(stdout, ", ");
fprintf(stdout, "%s", (result) ? "true" : "false");
fprintf(stdout, ", xpos=");
fprintf(stdout, "%i",xpos);
fprintf(stdout, ", ypos=");
fprintf(stdout, "%i",ypos);
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
uint8_t bin_diff[1] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0])};
int8_t diff = (bin_diff[0] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
diff = diff + 1;

}
fprintf(stdout, "function_called(BreakoutGame0, incrementScore, void");
fprintf(stdout, ", _");
fprintf(stdout, ", diff=");
fprintf(stdout, "%i",diff);
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
uint8_t bin_old[1] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0])};
uint8_t old = (bin_old[0] << 0);
uint8_t bin_new_[1] = {f_Binary2StringLogger_get_byte(_instance, payload[4 + 0])};
uint8_t new_ = (bin_new_[0] << 0);
fprintf(stdout, "property_changed(BreakoutGame0, XDISPSIZE, UInt8");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 1) {
uint8_t bin_old[1] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0])};
uint8_t old = (bin_old[0] << 0);
uint8_t bin_new_[1] = {f_Binary2StringLogger_get_byte(_instance, payload[4 + 0])};
uint8_t new_ = (bin_new_[0] << 0);
fprintf(stdout, "property_changed(BreakoutGame0, YDISPSIZE, UInt8");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 2) {
uint8_t bin_old[2] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[3 + 1])};
int16_t old = (bin_old[0] << 8 | bin_old[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
old = old + 256;

}
uint8_t bin_new_[2] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[5 + 1])};
int16_t new_ = (bin_new_[0] << 8 | bin_new_[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
new_ = new_ + 256;

}
fprintf(stdout, "property_changed(BreakoutGame0, SCALE, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 3) {
uint8_t bin_old[2] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[3 + 1])};
int16_t old = (bin_old[0] << 8 | bin_old[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
old = old + 256;

}
uint8_t bin_new_[2] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[5 + 1])};
int16_t new_ = (bin_new_[0] << 8 | bin_new_[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
new_ = new_ + 256;

}
fprintf(stdout, "property_changed(BreakoutGame0, XMAX, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 4) {
uint8_t bin_old[2] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[3 + 1])};
int16_t old = (bin_old[0] << 8 | bin_old[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
old = old + 256;

}
uint8_t bin_new_[2] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[5 + 1])};
int16_t new_ = (bin_new_[0] << 8 | bin_new_[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
new_ = new_ + 256;

}
fprintf(stdout, "property_changed(BreakoutGame0, YMAX, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 5) {
uint8_t bin_old[2] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[3 + 1])};
int16_t old = (bin_old[0] << 8 | bin_old[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
old = old + 256;

}
uint8_t bin_new_[2] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[5 + 1])};
int16_t new_ = (bin_new_[0] << 8 | bin_new_[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
new_ = new_ + 256;

}
fprintf(stdout, "property_changed(BreakoutGame0, TOP, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 6) {
uint8_t bin_old[2] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[3 + 1])};
int16_t old = (bin_old[0] << 8 | bin_old[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
old = old + 256;

}
uint8_t bin_new_[2] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[5 + 1])};
int16_t new_ = (bin_new_[0] << 8 | bin_new_[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
new_ = new_ + 256;

}
fprintf(stdout, "property_changed(BreakoutGame0, BOTTOM, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 7) {
uint8_t bin_old[2] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[3 + 1])};
int16_t old = (bin_old[0] << 8 | bin_old[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
old = old + 256;

}
uint8_t bin_new_[2] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[5 + 1])};
int16_t new_ = (bin_new_[0] << 8 | bin_new_[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
new_ = new_ + 256;

}
fprintf(stdout, "property_changed(BreakoutGame0, LEFT, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 8) {
uint8_t bin_old[2] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[3 + 1])};
int16_t old = (bin_old[0] << 8 | bin_old[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
old = old + 256;

}
uint8_t bin_new_[2] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[5 + 1])};
int16_t new_ = (bin_new_[0] << 8 | bin_new_[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
new_ = new_ + 256;

}
fprintf(stdout, "property_changed(BreakoutGame0, RIGHT, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 9) {
uint8_t bin_old[2] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[3 + 1])};
int16_t old = (bin_old[0] << 8 | bin_old[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
old = old + 256;

}
uint8_t bin_new_[2] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[5 + 1])};
int16_t new_ = (bin_new_[0] << 8 | bin_new_[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
new_ = new_ + 256;

}
fprintf(stdout, "property_changed(BreakoutGame0, br, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 10) {
uint8_t bin_old[2] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[3 + 1])};
int16_t old = (bin_old[0] << 8 | bin_old[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
old = old + 256;

}
uint8_t bin_new_[2] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[5 + 1])};
int16_t new_ = (bin_new_[0] << 8 | bin_new_[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
new_ = new_ + 256;

}
fprintf(stdout, "property_changed(BreakoutGame0, bx, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 11) {
uint8_t bin_old[2] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[3 + 1])};
int16_t old = (bin_old[0] << 8 | bin_old[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
old = old + 256;

}
uint8_t bin_new_[2] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[5 + 1])};
int16_t new_ = (bin_new_[0] << 8 | bin_new_[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
new_ = new_ + 256;

}
fprintf(stdout, "property_changed(BreakoutGame0, by, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 12) {
uint8_t bin_old[2] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[3 + 1])};
int16_t old = (bin_old[0] << 8 | bin_old[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
old = old + 256;

}
uint8_t bin_new_[2] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[5 + 1])};
int16_t new_ = (bin_new_[0] << 8 | bin_new_[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
new_ = new_ + 256;

}
fprintf(stdout, "property_changed(BreakoutGame0, dx, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 13) {
uint8_t bin_old[2] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[3 + 1])};
int16_t old = (bin_old[0] << 8 | bin_old[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
old = old + 256;

}
uint8_t bin_new_[2] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[5 + 1])};
int16_t new_ = (bin_new_[0] << 8 | bin_new_[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
new_ = new_ + 256;

}
fprintf(stdout, "property_changed(BreakoutGame0, dy, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 14) {
uint8_t bin_old[2] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[3 + 1])};
int16_t old = (bin_old[0] << 8 | bin_old[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
old = old + 256;

}
uint8_t bin_new_[2] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[5 + 1])};
int16_t new_ = (bin_new_[0] << 8 | bin_new_[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
new_ = new_ + 256;

}
fprintf(stdout, "property_changed(BreakoutGame0, padx, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 15) {
uint8_t bin_old[2] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[3 + 1])};
int16_t old = (bin_old[0] << 8 | bin_old[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
old = old + 256;

}
uint8_t bin_new_[2] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[5 + 1])};
int16_t new_ = (bin_new_[0] << 8 | bin_new_[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
new_ = new_ + 256;

}
fprintf(stdout, "property_changed(BreakoutGame0, pady, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 16) {
uint8_t bin_old[2] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[3 + 1])};
int16_t old = (bin_old[0] << 8 | bin_old[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
old = old + 256;

}
uint8_t bin_new_[2] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[5 + 1])};
int16_t new_ = (bin_new_[0] << 8 | bin_new_[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
new_ = new_ + 256;

}
fprintf(stdout, "property_changed(BreakoutGame0, padlen, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 17) {
uint8_t bin_old[2] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[3 + 1])};
int16_t old = (bin_old[0] << 8 | bin_old[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
old = old + 256;

}
uint8_t bin_new_[2] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[5 + 1])};
int16_t new_ = (bin_new_[0] << 8 | bin_new_[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
new_ = new_ + 256;

}
fprintf(stdout, "property_changed(BreakoutGame0, prevBX, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 18) {
uint8_t bin_old[2] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[3 + 1])};
int16_t old = (bin_old[0] << 8 | bin_old[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
old = old + 256;

}
uint8_t bin_new_[2] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[5 + 1])};
int16_t new_ = (bin_new_[0] << 8 | bin_new_[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
new_ = new_ + 256;

}
fprintf(stdout, "property_changed(BreakoutGame0, prevBY, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 19) {
uint8_t bin_old[1] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0])};
uint8_t old = (bin_old[0] << 0);
uint8_t bin_new_[1] = {f_Binary2StringLogger_get_byte(_instance, payload[4 + 0])};
uint8_t new_ = (bin_new_[0] << 0);
fprintf(stdout, "property_changed(BreakoutGame0, bgcolor, UInt8");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 20) {
uint8_t bin_old[1] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0])};
uint8_t old = (bin_old[0] << 0);
uint8_t bin_new_[1] = {f_Binary2StringLogger_get_byte(_instance, payload[4 + 0])};
uint8_t new_ = (bin_new_[0] << 0);
fprintf(stdout, "property_changed(BreakoutGame0, fgcolor, UInt8");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 21) {
uint8_t bin_old[2] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[3 + 1])};
uint16_t old = (bin_old[0] << 8 | bin_old[1] << 0);
uint8_t bin_new_[2] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[5 + 1])};
uint16_t new_ = (bin_new_[0] << 8 | bin_new_[1] << 0);
fprintf(stdout, "property_changed(BreakoutGame0, period, UInt16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 22) {
uint8_t bin_old[2] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[3 + 1])};
int16_t old = (bin_old[0] << 8 | bin_old[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
old = old + 256;

}
uint8_t bin_new_[2] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[5 + 1])};
int16_t new_ = (bin_new_[0] << 8 | bin_new_[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
new_ = new_ + 256;

}
fprintf(stdout, "property_changed(BreakoutGame0, prevPX, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 23) {
uint8_t bin_old[2] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[3 + 1])};
int16_t old = (bin_old[0] << 8 | bin_old[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
old = old + 256;

}
uint8_t bin_new_[2] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[5 + 1])};
int16_t new_ = (bin_new_[0] << 8 | bin_new_[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
new_ = new_ + 256;

}
fprintf(stdout, "property_changed(BreakoutGame0, prevPY, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 24) {
uint8_t bin_old[1] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0])};
uint8_t old = (bin_old[0] << 0);
uint8_t bin_new_[1] = {f_Binary2StringLogger_get_byte(_instance, payload[4 + 0])};
uint8_t new_ = (bin_new_[0] << 0);
fprintf(stdout, "property_changed(BreakoutGame0, BRICK_ROWS, UInt8");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 25) {
uint8_t bin_old[1] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0])};
uint8_t old = (bin_old[0] << 0);
uint8_t bin_new_[1] = {f_Binary2StringLogger_get_byte(_instance, payload[4 + 0])};
uint8_t new_ = (bin_new_[0] << 0);
fprintf(stdout, "property_changed(BreakoutGame0, BRICK_HEIGHT, UInt8");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 26) {
uint8_t bin_old[1] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0])};
uint8_t old = (bin_old[0] << 0);
uint8_t bin_new_[1] = {f_Binary2StringLogger_get_byte(_instance, payload[4 + 0])};
uint8_t new_ = (bin_new_[0] << 0);
fprintf(stdout, "property_changed(BreakoutGame0, bricks, UInt8");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 27) {
uint8_t bin_old[2] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[3 + 1])};
int16_t old = (bin_old[0] << 8 | bin_old[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
old = old + 256;

}
uint8_t bin_new_[2] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[5 + 1])};
int16_t new_ = (bin_new_[0] << 8 | bin_new_[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
new_ = new_ + 256;

}
fprintf(stdout, "property_changed(BreakoutGame0, score, Int16");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 28) {
uint8_t bin_old[1] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0])};
uint8_t old = (bin_old[0] << 0);
uint8_t bin_new_[1] = {f_Binary2StringLogger_get_byte(_instance, payload[4 + 0])};
uint8_t new_ = (bin_new_[0] << 0);
fprintf(stdout, "property_changed(BreakoutGame0, lives, UInt8");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(prop == 29) {
uint8_t bin_old[1] = {f_Binary2StringLogger_get_byte(_instance, payload[3 + 0])};
uint8_t old = (bin_old[0] << 0);
uint8_t bin_new_[1] = {f_Binary2StringLogger_get_byte(_instance, payload[4 + 0])};
uint8_t new_ = (bin_new_[0] << 0);
fprintf(stdout, "property_changed(BreakoutGame0, level, UInt8");
fprintf(stdout, ", ");
fprintf(stdout, "%i",old);
fprintf(stdout, ", ");
fprintf(stdout, "%i",new_);
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
if(portID == 1 && messageID == 22) {
uint8_t bin_id[1] = {f_Binary2StringLogger_get_byte(_instance, payload[4 + 0])};
uint8_t id = (bin_id[0] << 0);
fprintf(stdout, "message_lost(BreakoutGame0, clock, timer_timeout");
fprintf(stdout, ", id=");
fprintf(stdout, "%i",id);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 2 && messageID == 16) {
fprintf(stdout, "message_lost(BreakoutGame0, display, displayReady");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 3 && messageID == 18) {
uint8_t bin_x[2] = {f_Binary2StringLogger_get_byte(_instance, payload[4 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[4 + 1])};
int16_t x = (bin_x[0] << 8 | bin_x[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
x = x + 256;

}
uint8_t bin_y[2] = {f_Binary2StringLogger_get_byte(_instance, payload[6 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[6 + 1])};
int16_t y = (bin_y[0] << 8 | bin_y[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
y = y + 256;

}
fprintf(stdout, "message_lost(BreakoutGame0, controller, position");
fprintf(stdout, ", x=");
fprintf(stdout, "%i",x);
fprintf(stdout, ", y=");
fprintf(stdout, "%i",y);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 5 && messageID == 1) {
fprintf(stdout, "message_lost(BreakoutGame0, game, lostBall");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 7 && messageID == 1) {
fprintf(stdout, "message_lost(BreakoutGame0, pro_game, lostBall");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 5 && messageID == 2) {
fprintf(stdout, "message_lost(BreakoutGame0, game, nextLevel");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 7 && messageID == 2) {
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
if(portID == 1 && messageID == 20) {
uint8_t bin_id[1] = {f_Binary2StringLogger_get_byte(_instance, payload[4 + 0])};
uint8_t id = (bin_id[0] << 0);
uint8_t bin_time[2] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[5 + 1])};
uint16_t time = (bin_time[0] << 8 | bin_time[1] << 0);
fprintf(stdout, "message_sent(BreakoutGame0, clock, timer_start");
fprintf(stdout, ", id=");
fprintf(stdout, "%i",id);
fprintf(stdout, ", time=");
fprintf(stdout, "%i",time);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 1 && messageID == 21) {
uint8_t bin_id[1] = {f_Binary2StringLogger_get_byte(_instance, payload[4 + 0])};
uint8_t id = (bin_id[0] << 0);
fprintf(stdout, "message_sent(BreakoutGame0, clock, timer_cancel");
fprintf(stdout, ", id=");
fprintf(stdout, "%i",id);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 2 && messageID == 6) {
fprintf(stdout, "message_sent(BreakoutGame0, display, clear");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 2 && messageID == 7) {
uint8_t bin_r[1] = {f_Binary2StringLogger_get_byte(_instance, payload[4 + 0])};
uint8_t r = (bin_r[0] << 0);
uint8_t bin_g[1] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0])};
uint8_t g = (bin_g[0] << 0);
uint8_t bin_b[1] = {f_Binary2StringLogger_get_byte(_instance, payload[6 + 0])};
uint8_t b = (bin_b[0] << 0);
fprintf(stdout, "message_sent(BreakoutGame0, display, setColor");
fprintf(stdout, ", r=");
fprintf(stdout, "%i",r);
fprintf(stdout, ", g=");
fprintf(stdout, "%i",g);
fprintf(stdout, ", b=");
fprintf(stdout, "%i",b);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 2 && messageID == 8) {
uint8_t bin_r[1] = {f_Binary2StringLogger_get_byte(_instance, payload[4 + 0])};
uint8_t r = (bin_r[0] << 0);
uint8_t bin_g[1] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0])};
uint8_t g = (bin_g[0] << 0);
uint8_t bin_b[1] = {f_Binary2StringLogger_get_byte(_instance, payload[6 + 0])};
uint8_t b = (bin_b[0] << 0);
fprintf(stdout, "message_sent(BreakoutGame0, display, setBGColor");
fprintf(stdout, ", r=");
fprintf(stdout, "%i",r);
fprintf(stdout, ", g=");
fprintf(stdout, "%i",g);
fprintf(stdout, ", b=");
fprintf(stdout, "%i",b);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 2 && messageID == 9) {
uint8_t bin_x[1] = {f_Binary2StringLogger_get_byte(_instance, payload[4 + 0])};
uint8_t x = (bin_x[0] << 0);
uint8_t bin_y[1] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0])};
uint8_t y = (bin_y[0] << 0);
uint8_t bin_width[1] = {f_Binary2StringLogger_get_byte(_instance, payload[6 + 0])};
uint8_t width = (bin_width[0] << 0);
uint8_t bin_height[1] = {f_Binary2StringLogger_get_byte(_instance, payload[7 + 0])};
uint8_t height = (bin_height[0] << 0);
fprintf(stdout, "message_sent(BreakoutGame0, display, drawRect");
fprintf(stdout, ", x=");
fprintf(stdout, "%i",x);
fprintf(stdout, ", y=");
fprintf(stdout, "%i",y);
fprintf(stdout, ", width=");
fprintf(stdout, "%i",width);
fprintf(stdout, ", height=");
fprintf(stdout, "%i",height);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 2 && messageID == 10) {
uint8_t bin_x[1] = {f_Binary2StringLogger_get_byte(_instance, payload[4 + 0])};
uint8_t x = (bin_x[0] << 0);
uint8_t bin_y[1] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0])};
uint8_t y = (bin_y[0] << 0);
uint8_t bin_width[1] = {f_Binary2StringLogger_get_byte(_instance, payload[6 + 0])};
uint8_t width = (bin_width[0] << 0);
uint8_t bin_height[1] = {f_Binary2StringLogger_get_byte(_instance, payload[7 + 0])};
uint8_t height = (bin_height[0] << 0);
fprintf(stdout, "message_sent(BreakoutGame0, display, fillRect");
fprintf(stdout, ", x=");
fprintf(stdout, "%i",x);
fprintf(stdout, ", y=");
fprintf(stdout, "%i",y);
fprintf(stdout, ", width=");
fprintf(stdout, "%i",width);
fprintf(stdout, ", height=");
fprintf(stdout, "%i",height);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 2 && messageID == 11) {
uint8_t bin_x[1] = {f_Binary2StringLogger_get_byte(_instance, payload[4 + 0])};
uint8_t x = (bin_x[0] << 0);
uint8_t bin_y[1] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0])};
uint8_t y = (bin_y[0] << 0);
uint8_t bin_v[2] = {f_Binary2StringLogger_get_byte(_instance, payload[6 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[6 + 1])};
int16_t v = (bin_v[0] << 8 | bin_v[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
v = v + 256;

}
uint8_t bin_digits[1] = {f_Binary2StringLogger_get_byte(_instance, payload[8 + 0])};
uint8_t digits = (bin_digits[0] << 0);
uint8_t bin_scale[1] = {f_Binary2StringLogger_get_byte(_instance, payload[9 + 0])};
uint8_t scale = (bin_scale[0] << 0);
fprintf(stdout, "message_sent(BreakoutGame0, display, drawInteger");
fprintf(stdout, ", x=");
fprintf(stdout, "%i",x);
fprintf(stdout, ", y=");
fprintf(stdout, "%i",y);
fprintf(stdout, ", v=");
fprintf(stdout, "%i",v);
fprintf(stdout, ", digits=");
fprintf(stdout, "%i",digits);
fprintf(stdout, ", scale=");
fprintf(stdout, "%i",scale);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 2 && messageID == 12) {
uint8_t bin_x[1] = {f_Binary2StringLogger_get_byte(_instance, payload[4 + 0])};
uint8_t x = (bin_x[0] << 0);
uint8_t bin_y[1] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0])};
uint8_t y = (bin_y[0] << 0);
fprintf(stdout, "message_sent(BreakoutGame0, display, drawThingML");
fprintf(stdout, ", x=");
fprintf(stdout, "%i",x);
fprintf(stdout, ", y=");
fprintf(stdout, "%i",y);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 2 && messageID == 13) {
uint8_t bin_xsize[1] = {f_Binary2StringLogger_get_byte(_instance, payload[4 + 0])};
uint8_t xsize = (bin_xsize[0] << 0);
uint8_t bin_ysize[1] = {f_Binary2StringLogger_get_byte(_instance, payload[5 + 0])};
uint8_t ysize = (bin_ysize[0] << 0);
fprintf(stdout, "message_sent(BreakoutGame0, display, create");
fprintf(stdout, ", xsize=");
fprintf(stdout, "%i",xsize);
fprintf(stdout, ", ysize=");
fprintf(stdout, "%i",ysize);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 2 && messageID == 15) {
fprintf(stdout, "message_sent(BreakoutGame0, display, update");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 4 && messageID == 19) {
uint8_t bin_ballx[2] = {f_Binary2StringLogger_get_byte(_instance, payload[4 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[4 + 1])};
int16_t ballx = (bin_ballx[0] << 8 | bin_ballx[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
ballx = ballx + 256;

}
uint8_t bin_bally[2] = {f_Binary2StringLogger_get_byte(_instance, payload[6 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[6 + 1])};
int16_t bally = (bin_bally[0] << 8 | bin_bally[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
bally = bally + 256;

}
uint8_t bin_padx[2] = {f_Binary2StringLogger_get_byte(_instance, payload[8 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[8 + 1])};
int16_t padx = (bin_padx[0] << 8 | bin_padx[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
padx = padx + 256;

}
uint8_t bin_pady[2] = {f_Binary2StringLogger_get_byte(_instance, payload[10 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[10 + 1])};
int16_t pady = (bin_pady[0] << 8 | bin_pady[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
pady = pady + 256;

}
fprintf(stdout, "message_sent(BreakoutGame0, ia, updateIA");
fprintf(stdout, ", ballx=");
fprintf(stdout, "%i",ballx);
fprintf(stdout, ", bally=");
fprintf(stdout, "%i",bally);
fprintf(stdout, ", padx=");
fprintf(stdout, "%i",padx);
fprintf(stdout, ", pady=");
fprintf(stdout, "%i",pady);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 5 && messageID == 1) {
fprintf(stdout, "message_sent(BreakoutGame0, game, lostBall");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 6 && messageID == 1) {
fprintf(stdout, "message_sent(BreakoutGame0, req_game, lostBall");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 5 && messageID == 2) {
fprintf(stdout, "message_sent(BreakoutGame0, game, nextLevel");
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 6 && messageID == 2) {
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
uint8_t portID = f_Binary2StringLogger_get_byte(_instance, payload[2]);
uint8_t messageID = f_Binary2StringLogger_get_byte(_instance, payload[3]);
uint8_t sourceID = f_Binary2StringLogger_get_byte(_instance, payload[4]);
uint8_t targetID = f_Binary2StringLogger_get_byte(_instance, payload[5]);
if(inst == 0) {
if(portID == 1 && messageID == 22) {
uint8_t bin_id[1] = {f_Binary2StringLogger_get_byte(_instance, payload[6 + 0])};
uint8_t id = (bin_id[0] << 0);
fprintf(stdout, "message_handled(BreakoutGame0, clock, timer_timeout, ");
fprintf(stdout, f_Binary2StringLogger_stateName(_instance, sourceID));
fprintf(stdout, ", ");
fprintf(stdout, f_Binary2StringLogger_stateName(_instance, targetID));
fprintf(stdout, ", id=");
fprintf(stdout, "%i",id);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 2 && messageID == 16) {
fprintf(stdout, "message_handled(BreakoutGame0, display, displayReady, ");
fprintf(stdout, f_Binary2StringLogger_stateName(_instance, sourceID));
fprintf(stdout, ", ");
fprintf(stdout, f_Binary2StringLogger_stateName(_instance, targetID));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 3 && messageID == 18) {
uint8_t bin_x[2] = {f_Binary2StringLogger_get_byte(_instance, payload[6 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[6 + 1])};
int16_t x = (bin_x[0] << 8 | bin_x[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
x = x + 256;

}
uint8_t bin_y[2] = {f_Binary2StringLogger_get_byte(_instance, payload[8 + 0]), f_Binary2StringLogger_get_byte(_instance, payload[8 + 1])};
int16_t y = (bin_y[0] << 8 | bin_y[1] << 0);
if( !(_instance->Logger_HAS_SIGNED_BYTE_var)) {
y = y + 256;

}
fprintf(stdout, "message_handled(BreakoutGame0, controller, position, ");
fprintf(stdout, f_Binary2StringLogger_stateName(_instance, sourceID));
fprintf(stdout, ", ");
fprintf(stdout, f_Binary2StringLogger_stateName(_instance, targetID));
fprintf(stdout, ", x=");
fprintf(stdout, "%i",x);
fprintf(stdout, ", y=");
fprintf(stdout, "%i",y);
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 5 && messageID == 1) {
fprintf(stdout, "message_handled(BreakoutGame0, game, lostBall, ");
fprintf(stdout, f_Binary2StringLogger_stateName(_instance, sourceID));
fprintf(stdout, ", ");
fprintf(stdout, f_Binary2StringLogger_stateName(_instance, targetID));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 7 && messageID == 1) {
fprintf(stdout, "message_handled(BreakoutGame0, pro_game, lostBall, ");
fprintf(stdout, f_Binary2StringLogger_stateName(_instance, sourceID));
fprintf(stdout, ", ");
fprintf(stdout, f_Binary2StringLogger_stateName(_instance, targetID));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 5 && messageID == 2) {
fprintf(stdout, "message_handled(BreakoutGame0, game, nextLevel, ");
fprintf(stdout, f_Binary2StringLogger_stateName(_instance, sourceID));
fprintf(stdout, ", ");
fprintf(stdout, f_Binary2StringLogger_stateName(_instance, targetID));
fprintf(stdout, ")");
fprintf(stdout, "\n");

} else {
if(portID == 7 && messageID == 2) {
fprintf(stdout, "message_handled(BreakoutGame0, pro_game, nextLevel, ");
fprintf(stdout, f_Binary2StringLogger_stateName(_instance, sourceID));
fprintf(stdout, ", ");
fprintf(stdout, f_Binary2StringLogger_stateName(_instance, targetID));
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
case LOGGER_NULL_OFF_STATE:{
break;
}
case LOGGER_NULL_ON_STATE:{
break;
}
case LOGGER_NULL_STARTUP_STATE:{
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
case LOGGER_NULL_ON_STATE:{
break;}
case LOGGER_NULL_STARTUP_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
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



