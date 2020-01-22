/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *      Implementation for Application test
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <signal.h>
#include <pthread.h>
#include "thingml_typedefs.h"
#include "runtime.h"
#include "TimerPosix.h"
#include "BasicIAController.h"
#include "BreakoutGamePosix.h"
#include "HeadlessDisplay.h"





/*****************************************************************************
 * Definitions for configuration : test
 *****************************************************************************/

uint8_t array_game_BreakoutGame_bricks_var[5];
uint8_t array_game_BreakoutGame_fgcolor_var[3];
uint8_t array_game_BreakoutGame_bgcolor_var[3];
//Declaration of instance variables
//Instance timer
// Variables for the properties of the instance
struct TimerPosix_Instance timer_var;
// Variables for the sessions of the instance
//Instance ctrl
// Variables for the properties of the instance
struct BasicIAController_Instance ctrl_var;
// Variables for the sessions of the instance
//Instance game
// Variables for the properties of the instance
struct BreakoutGamePosix_Instance game_var;
// Variables for the sessions of the instance
//Instance disp
// Variables for the properties of the instance
struct HeadlessDisplay_Instance disp_var;
// Variables for the sessions of the instance


// Enqueue of messages TimerPosix::timer::timer_timeout
void enqueue_TimerPosix_send_timer_timer_timeout(struct TimerPosix_Instance *_instance, uint8_t id){
fifo_lock();
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (1 >> 8) & 0xFF );
_fifo_enqueue( 1 & 0xFF );

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
fifo_unlock_and_notify();
}
// Enqueue of messages BasicIAController::controls::position
void enqueue_BasicIAController_send_controls_position(struct BasicIAController_Instance *_instance, int16_t x, int16_t y){
fifo_lock();
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
fifo_unlock_and_notify();
}
// Enqueue of messages BreakoutGamePosix::clock::timer_start
void enqueue_BreakoutGamePosix_send_clock_timer_start(struct BreakoutGamePosix_Instance *_instance, uint8_t id, uint16_t time){
fifo_lock();
if ( fifo_byte_available() > 7 ) {

_fifo_enqueue( (3 >> 8) & 0xFF );
_fifo_enqueue( 3 & 0xFF );

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
fifo_unlock_and_notify();
}
// Enqueue of messages BreakoutGamePosix::clock::timer_cancel
void enqueue_BreakoutGamePosix_send_clock_timer_cancel(struct BreakoutGamePosix_Instance *_instance, uint8_t id){
fifo_lock();
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
fifo_unlock_and_notify();
}
// Enqueue of messages BreakoutGamePosix::ia::updateIA
void enqueue_BreakoutGamePosix_send_ia_updateIA(struct BreakoutGamePosix_Instance *_instance, int16_t ballx, int16_t bally, int16_t padx, int16_t pady){
fifo_lock();
if ( fifo_byte_available() > 12 ) {

_fifo_enqueue( (5 >> 8) & 0xFF );
_fifo_enqueue( 5 & 0xFF );

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
fifo_unlock_and_notify();
}
// Enqueue of messages BreakoutGamePosix::game::lostBall
void enqueue_BreakoutGamePosix_send_game_lostBall(struct BreakoutGamePosix_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (6 >> 8) & 0xFF );
_fifo_enqueue( 6 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_game >> 8) & 0xFF );
_fifo_enqueue( _instance->id_game & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages BreakoutGamePosix::game::nextLevel
void enqueue_BreakoutGamePosix_send_game_nextLevel(struct BreakoutGamePosix_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (7 >> 8) & 0xFF );
_fifo_enqueue( 7 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_game >> 8) & 0xFF );
_fifo_enqueue( _instance->id_game & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages BreakoutGamePosix::req_game::lostBall
void enqueue_BreakoutGamePosix_send_req_game_lostBall(struct BreakoutGamePosix_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (6 >> 8) & 0xFF );
_fifo_enqueue( 6 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_req_game >> 8) & 0xFF );
_fifo_enqueue( _instance->id_req_game & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages BreakoutGamePosix::req_game::nextLevel
void enqueue_BreakoutGamePosix_send_req_game_nextLevel(struct BreakoutGamePosix_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (7 >> 8) & 0xFF );
_fifo_enqueue( 7 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_req_game >> 8) & 0xFF );
_fifo_enqueue( _instance->id_req_game & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages HeadlessDisplay::display::displayReady
void enqueue_HeadlessDisplay_send_display_displayReady(struct HeadlessDisplay_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (8 >> 8) & 0xFF );
_fifo_enqueue( 8 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_display >> 8) & 0xFF );
_fifo_enqueue( _instance->id_display & 0xFF );
}
fifo_unlock_and_notify();
}


//New dispatcher for messages
void dispatch_timer_timeout(uint16_t sender, uint8_t param_id) {
if (sender == game_var.id_game) {

}
if (sender == timer_var.id_timer) {
BreakoutGamePosix_handle_clock_timer_timeout(&game_var, param_id);

}

}


//New dispatcher for messages
void dispatch_position(uint16_t sender, int16_t param_x, int16_t param_y) {
if (sender == game_var.id_game) {

}
if (sender == ctrl_var.id_controls) {
BreakoutGamePosix_handle_controller_position(&game_var, param_x, param_y);

}

}


//New dispatcher for messages
void dispatch_drawRect(uint16_t sender, uint8_t param_x, uint8_t param_y, uint8_t param_width, uint8_t param_height) {
if (sender == game_var.id_game) {

}
if (sender == game_var.id_display) {
HeadlessDisplay_handle_display_drawRect(&disp_var, param_x, param_y, param_width, param_height);

}

}

void sync_dispatch_BreakoutGamePosix_send_display_drawRect(struct BreakoutGamePosix_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height){
dispatch_drawRect(_instance->id_display, x, y, width, height);
}

//New dispatcher for messages
void dispatch_timer_start(uint16_t sender, uint8_t param_id, uint16_t param_time) {
if (sender == game_var.id_game) {

}
if (sender == game_var.id_clock) {
TimerPosix_handle_timer_timer_start(&timer_var, param_id, param_time);

}

}


//New dispatcher for messages
void dispatch_destroy(uint16_t sender) {
if (sender == game_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_drawInteger(uint16_t sender, uint8_t param_x, uint8_t param_y, int16_t param_v, uint8_t param_digits, uint8_t param_scale) {
if (sender == game_var.id_game) {

}
if (sender == game_var.id_display) {
HeadlessDisplay_handle_display_drawInteger(&disp_var, param_x, param_y, param_v, param_digits, param_scale);

}

}

void sync_dispatch_BreakoutGamePosix_send_display_drawInteger(struct BreakoutGamePosix_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale){
dispatch_drawInteger(_instance->id_display, x, y, v, digits, scale);
}

//New dispatcher for messages
void dispatch_displayReady(uint16_t sender) {
if (sender == game_var.id_game) {

}
if (sender == disp_var.id_display) {
BreakoutGamePosix_handle_display_displayReady(&game_var);

}

}


//New dispatcher for messages
void dispatch_update(uint16_t sender) {
if (sender == game_var.id_game) {

}
if (sender == game_var.id_display) {
HeadlessDisplay_handle_display_update(&disp_var);

}

}

void sync_dispatch_BreakoutGamePosix_send_display_update(struct BreakoutGamePosix_Instance *_instance){
dispatch_update(_instance->id_display);
}

//New dispatcher for messages
void dispatch_lostBall(uint16_t sender) {
if (sender == game_var.id_game) {
BreakoutGamePosix_handle_game_lostBall(&game_var);

}
if (sender == game_var.id_req_game) {
BreakoutGamePosix_handle_pro_game_lostBall(&game_var);

}

}


//New dispatcher for messages
void dispatch_drawThingML(uint16_t sender, uint8_t param_x, uint8_t param_y) {
if (sender == game_var.id_game) {

}
if (sender == game_var.id_display) {
HeadlessDisplay_handle_display_drawThingML(&disp_var, param_x, param_y);

}

}

void sync_dispatch_BreakoutGamePosix_send_display_drawThingML(struct BreakoutGamePosix_Instance *_instance, uint8_t x, uint8_t y){
dispatch_drawThingML(_instance->id_display, x, y);
}

//New dispatcher for messages
void dispatch_create(uint16_t sender, uint8_t param_xsize, uint8_t param_ysize) {
if (sender == game_var.id_game) {

}
if (sender == game_var.id_display) {
HeadlessDisplay_handle_display_create(&disp_var, param_xsize, param_ysize);

}

}

void sync_dispatch_BreakoutGamePosix_send_display_create(struct BreakoutGamePosix_Instance *_instance, uint8_t xsize, uint8_t ysize){
dispatch_create(_instance->id_display, xsize, ysize);
}

//New dispatcher for messages
void dispatch_clear(uint16_t sender) {
if (sender == game_var.id_game) {

}
if (sender == game_var.id_display) {
HeadlessDisplay_handle_display_clear(&disp_var);

}

}

void sync_dispatch_BreakoutGamePosix_send_display_clear(struct BreakoutGamePosix_Instance *_instance){
dispatch_clear(_instance->id_display);
}

//New dispatcher for messages
void dispatch_updateIA(uint16_t sender, int16_t param_ballx, int16_t param_bally, int16_t param_padx, int16_t param_pady) {
if (sender == game_var.id_game) {

}
if (sender == game_var.id_ia) {
BasicIAController_handle_game_updateIA(&ctrl_var, param_ballx, param_bally, param_padx, param_pady);

}

}


//New dispatcher for messages
void dispatch_fillRect(uint16_t sender, uint8_t param_x, uint8_t param_y, uint8_t param_width, uint8_t param_height) {
if (sender == game_var.id_game) {

}
if (sender == game_var.id_display) {
HeadlessDisplay_handle_display_fillRect(&disp_var, param_x, param_y, param_width, param_height);

}

}

void sync_dispatch_BreakoutGamePosix_send_display_fillRect(struct BreakoutGamePosix_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height){
dispatch_fillRect(_instance->id_display, x, y, width, height);
}

//New dispatcher for messages
void dispatch_velocity(uint16_t sender, int16_t param_dx, int16_t param_dy) {
if (sender == game_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_setColor(uint16_t sender, uint8_t param_r, uint8_t param_g, uint8_t param_b) {
if (sender == game_var.id_game) {

}
if (sender == game_var.id_display) {
HeadlessDisplay_handle_display_setColor(&disp_var, param_r, param_g, param_b);

}

}

void sync_dispatch_BreakoutGamePosix_send_display_setColor(struct BreakoutGamePosix_Instance *_instance, uint8_t r, uint8_t g, uint8_t b){
dispatch_setColor(_instance->id_display, r, g, b);
}

//New dispatcher for messages
void dispatch_setBGColor(uint16_t sender, uint8_t param_r, uint8_t param_g, uint8_t param_b) {
if (sender == game_var.id_game) {

}
if (sender == game_var.id_display) {
HeadlessDisplay_handle_display_setBGColor(&disp_var, param_r, param_g, param_b);

}

}

void sync_dispatch_BreakoutGamePosix_send_display_setBGColor(struct BreakoutGamePosix_Instance *_instance, uint8_t r, uint8_t g, uint8_t b){
dispatch_setBGColor(_instance->id_display, r, g, b);
}

//New dispatcher for messages
void dispatch_timer_cancel(uint16_t sender, uint8_t param_id) {
if (sender == game_var.id_game) {

}
if (sender == game_var.id_clock) {
TimerPosix_handle_timer_timer_cancel(&timer_var, param_id);

}

}


//New dispatcher for messages
void dispatch_nextLevel(uint16_t sender) {
if (sender == game_var.id_game) {
BreakoutGamePosix_handle_game_nextLevel(&game_var);

}
if (sender == game_var.id_req_game) {
BreakoutGamePosix_handle_pro_game_nextLevel(&game_var);

}

}


int processMessageQueue() {
fifo_lock();
while (fifo_empty()) fifo_wait();
uint8_t mbufi = 0;

// Read the code of the next port/message in the queue
uint16_t code = fifo_dequeue() << 8;

code += fifo_dequeue();

// Switch to call the appropriate handler
switch(code) {
case 6:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_lostBall = 2;
dispatch_lostBall((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 1:{
byte mbuf[5 - 2];
while (mbufi < (5 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
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
case 2:{
byte mbuf[8 - 2];
while (mbufi < (8 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
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
case 5:{
byte mbuf[12 - 2];
while (mbufi < (12 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
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
case 3:{
byte mbuf[7 - 2];
while (mbufi < (7 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
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
case 8:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_displayReady = 2;
dispatch_displayReady((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 4:{
byte mbuf[5 - 2];
while (mbufi < (5 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
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
case 7:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_nextLevel = 2;
dispatch_nextLevel((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
}
return 1;
}


//external Message enqueue

void initialize_configuration_test() {
// Initialize connectors
register_TimerPosix_send_timer_timer_timeout_listener(&enqueue_TimerPosix_send_timer_timer_timeout);
register_BasicIAController_send_controls_position_listener(&enqueue_BasicIAController_send_controls_position);
register_BreakoutGamePosix_send_clock_timer_start_listener(&enqueue_BreakoutGamePosix_send_clock_timer_start);
register_BreakoutGamePosix_send_clock_timer_cancel_listener(&enqueue_BreakoutGamePosix_send_clock_timer_cancel);
register_BreakoutGamePosix_send_display_create_listener(&sync_dispatch_BreakoutGamePosix_send_display_create);
register_BreakoutGamePosix_send_display_drawThingML_listener(&sync_dispatch_BreakoutGamePosix_send_display_drawThingML);
register_BreakoutGamePosix_send_display_drawRect_listener(&sync_dispatch_BreakoutGamePosix_send_display_drawRect);
register_BreakoutGamePosix_send_display_clear_listener(&sync_dispatch_BreakoutGamePosix_send_display_clear);
register_BreakoutGamePosix_send_display_fillRect_listener(&sync_dispatch_BreakoutGamePosix_send_display_fillRect);
register_BreakoutGamePosix_send_display_setColor_listener(&sync_dispatch_BreakoutGamePosix_send_display_setColor);
register_BreakoutGamePosix_send_display_setBGColor_listener(&sync_dispatch_BreakoutGamePosix_send_display_setBGColor);
register_BreakoutGamePosix_send_display_drawInteger_listener(&sync_dispatch_BreakoutGamePosix_send_display_drawInteger);
register_BreakoutGamePosix_send_display_update_listener(&sync_dispatch_BreakoutGamePosix_send_display_update);
register_BreakoutGamePosix_send_ia_updateIA_listener(&enqueue_BreakoutGamePosix_send_ia_updateIA);
register_BreakoutGamePosix_send_req_game_lostBall_listener(&enqueue_BreakoutGamePosix_send_req_game_lostBall);
register_BreakoutGamePosix_send_req_game_nextLevel_listener(&enqueue_BreakoutGamePosix_send_req_game_nextLevel);
register_HeadlessDisplay_send_display_displayReady_listener(&enqueue_HeadlessDisplay_send_display_displayReady);


// Network Initialization
// End Network Initialization

// Init the ID, state variables and properties for instance timer
timer_var.active = true;
timer_var.id_timer = add_instance( (void*) &timer_var);
timer_var.TimerPosix_SoftTimer_State = TIMERPOSIX_SOFTTIMER_DEFAULT_STATE;
timer_var.TimerPosix_NB_SOFT_TIMERS_var = NB_SOFT_TIMERS;
timer_var.TimerPosix_SOFT_TIMER_PERIOD_var = 4;

TimerPosix_SoftTimer_OnEntry(TIMERPOSIX_SOFTTIMER_STATE, &timer_var);
// Init the ID, state variables and properties for instance disp
disp_var.active = true;
disp_var.id_display = add_instance( (void*) &disp_var);
disp_var.HeadlessDisplay_State = HEADLESSDISPLAY_NULL_INIT_STATE;

HeadlessDisplay_OnEntry(HEADLESSDISPLAY_STATE, &disp_var);
// Init the ID, state variables and properties for instance game
game_var.active = true;
game_var.id_clock = add_instance( (void*) &game_var);
game_var.id_display = add_instance( (void*) &game_var);
game_var.id_controller = add_instance( (void*) &game_var);
game_var.id_ia = add_instance( (void*) &game_var);
game_var.id_game = add_instance( (void*) &game_var);
game_var.id_req_game = add_instance( (void*) &game_var);
game_var.id_pro_game = add_instance( (void*) &game_var);
game_var.BreakoutGame_SC_State = BREAKOUTGAME_SC_INIT_STATE;
game_var.BreakoutGame_RIGHT_var = 160 * 64 - 1 * 64;
game_var.BreakoutGame_QUIET_var = 1;
game_var.BreakoutGame_dx_var = 160 * 64 / 98;
game_var.BreakoutGame_counter_var = 0;
game_var.BreakoutGame_XMAX_var = 160 * 64;
game_var.BreakoutGame_lastTimestamp_var = 0;
game_var.BreakoutGame_padx_var = 128 * 64 / 2;
game_var.BreakoutGame_padlen_var = 25 * 64;
game_var.BreakoutGame_dy_var =  -160 * 64 / 65;
game_var.BreakoutGame_YDISPSIZE_var = 128;
game_var.BreakoutGame_br_var = 3 * 64;
game_var.BreakoutGame_YMAX_var = 128 * 64;
game_var.BreakoutGame_prevPY_var =  -1;
game_var.BreakoutGame_prevBX_var =  -1;
game_var.BreakoutGame_XDISPSIZE_var = 160;
game_var.BreakoutGame_prevPX_var =  -1;
game_var.BreakoutGame_BRICK_ROWS_var = 5;
game_var.BreakoutGame_TOP_var = 14 * 64;
game_var.BreakoutGame_period_var = 3;
game_var.BreakoutGame_level_var = 1;
game_var.BreakoutGame_BRICK_HEIGHT_var = 9;
game_var.BreakoutGame_lives_var = 3;
game_var.BreakoutGame_pady_var = 128 * 64 - 6 * 64;
game_var.BreakoutGame_bx_var = 160 * 64 / 2;
game_var.BreakoutGame_SCALE_var = 64;
game_var.BreakoutGame_LEFT_var = 1 * 64;
game_var.BreakoutGame_score_var = 0;
game_var.BreakoutGame_prevBY_var =  -1;
game_var.BreakoutGame_by_var = 128 * 64;
game_var.BreakoutGame_BOTTOM_var = 128 * 64 + 8 * 64;
game_var.BreakoutGame_bricks_var = array_game_BreakoutGame_bricks_var;
game_var.BreakoutGame_bricks_var_size = 5;
game_var.BreakoutGame_fgcolor_var = array_game_BreakoutGame_fgcolor_var;
game_var.BreakoutGame_fgcolor_var_size = 3;
game_var.BreakoutGame_bgcolor_var = array_game_BreakoutGame_bgcolor_var;
game_var.BreakoutGame_bgcolor_var_size = 3;

BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_STATE, &game_var);
// Init the ID, state variables and properties for instance ctrl
ctrl_var.active = true;
ctrl_var.id_controls = add_instance( (void*) &ctrl_var);
ctrl_var.id_game = add_instance( (void*) &ctrl_var);
ctrl_var.BasicIAController_SC_State = BASICIACONTROLLER_SC_FOLLOWING_STATE;
ctrl_var.BasicIAController_ctrlx_var = 0;

BasicIAController_SC_OnEntry(BASICIACONTROLLER_SC_STATE, &ctrl_var);
}




void term(int signum)
{
    

    fflush(stdout);
    fflush(stderr);
    exit(signum);
}


int main(int argc, char *argv[]) {
    struct sigaction action;
    memset(&action, 0, sizeof(struct sigaction));
    action.sa_handler = term;
    sigaction(SIGINT, &action, NULL);
    sigaction(SIGTERM, &action, NULL);

    init_runtime();
    
    initialize_configuration_test();

    while (1) {
        
// Network Listener// End Network Listener

int emptyEventConsumed = 1;
while (emptyEventConsumed != 0) {
emptyEventConsumed = 0;
emptyEventConsumed += HeadlessDisplay_handle_empty_event(&disp_var);
}

        processMessageQueue();
  }
}