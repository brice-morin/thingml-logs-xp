/**
 * File generated by the ThingML IDE
 * /!\Do not edit this file/!\
 * In case of a bug in the generated code,
 * please submit an issue on our GitHub
 **/

package org.thingml.generated;

import no.sintef.jasm.*;
import no.sintef.jasm.ext.*;

import org.thingml.generated.api.*;
import org.thingml.generated.messages.*;

import java.util.*;

/**
 * Definition for type : HeadlessDisplay
 **/
public class HeadlessDisplay extends Component implements IHeadlessDisplay_display {

private boolean debug = false;
public boolean isDebug() {return debug;}
public void setDebug(boolean debug) {this.debug = debug;}
public String toString() {
String result = "instance " + getName() + "\n";
result += "";
return result;
}

public synchronized void create_via_display(int DisplayMsgs_create_xsize_var, int DisplayMsgs_create_ysize_var){
final Event _msg = createType.instantiate(DisplayMsgs_create_xsize_var, DisplayMsgs_create_ysize_var);
_msg.setPort(display_port);
receive(_msg);
}

public synchronized void destroy_via_display(){
final Event _msg = destroyType.instantiate();
_msg.setPort(display_port);
receive(_msg);
}

public synchronized void update_via_display(){
final Event _msg = updateType.instantiate();
_msg.setPort(display_port);
receive(_msg);
}

public synchronized void clear_via_display(){
final Event _msg = clearType.instantiate();
_msg.setPort(display_port);
receive(_msg);
}

public synchronized void setColor_via_display(int DisplayMsgs_setColor_r_var, int DisplayMsgs_setColor_g_var, int DisplayMsgs_setColor_b_var){
final Event _msg = setColorType.instantiate(DisplayMsgs_setColor_r_var, DisplayMsgs_setColor_g_var, DisplayMsgs_setColor_b_var);
_msg.setPort(display_port);
receive(_msg);
}

public synchronized void setBGColor_via_display(int DisplayMsgs_setBGColor_r_var, int DisplayMsgs_setBGColor_g_var, int DisplayMsgs_setBGColor_b_var){
final Event _msg = setBGColorType.instantiate(DisplayMsgs_setBGColor_r_var, DisplayMsgs_setBGColor_g_var, DisplayMsgs_setBGColor_b_var);
_msg.setPort(display_port);
receive(_msg);
}

public synchronized void drawRect_via_display(int DisplayMsgs_drawRect_x_var, int DisplayMsgs_drawRect_y_var, int DisplayMsgs_drawRect_width_var, int DisplayMsgs_drawRect_height_var){
final Event _msg = drawRectType.instantiate(DisplayMsgs_drawRect_x_var, DisplayMsgs_drawRect_y_var, DisplayMsgs_drawRect_width_var, DisplayMsgs_drawRect_height_var);
_msg.setPort(display_port);
receive(_msg);
}

public synchronized void fillRect_via_display(int DisplayMsgs_fillRect_x_var, int DisplayMsgs_fillRect_y_var, int DisplayMsgs_fillRect_width_var, int DisplayMsgs_fillRect_height_var){
final Event _msg = fillRectType.instantiate(DisplayMsgs_fillRect_x_var, DisplayMsgs_fillRect_y_var, DisplayMsgs_fillRect_width_var, DisplayMsgs_fillRect_height_var);
_msg.setPort(display_port);
receive(_msg);
}

public synchronized void drawInteger_via_display(int DisplayMsgs_drawInteger_x_var, int DisplayMsgs_drawInteger_y_var, int DisplayMsgs_drawInteger_v_var, int DisplayMsgs_drawInteger_digits_var, int DisplayMsgs_drawInteger_scale_var){
final Event _msg = drawIntegerType.instantiate(DisplayMsgs_drawInteger_x_var, DisplayMsgs_drawInteger_y_var, DisplayMsgs_drawInteger_v_var, DisplayMsgs_drawInteger_digits_var, DisplayMsgs_drawInteger_scale_var);
_msg.setPort(display_port);
receive(_msg);
}

public synchronized void drawThingML_via_display(int DisplayMsgs_drawThingML_x_var, int DisplayMsgs_drawThingML_y_var){
final Event _msg = drawThingMLType.instantiate(DisplayMsgs_drawThingML_x_var, DisplayMsgs_drawThingML_y_var);
_msg.setPort(display_port);
receive(_msg);
}

private void sendDisplayReady_via_display(){
display_port.send(displayReadyType.instantiate());
}

//Attributes
//Ports
private Port display_port;
//Message types
protected final ClearMessageType clearType = new ClearMessageType();
protected final SetColorMessageType setColorType = new SetColorMessageType();
protected final SetBGColorMessageType setBGColorType = new SetBGColorMessageType();
protected final DrawRectMessageType drawRectType = new DrawRectMessageType();
protected final FillRectMessageType fillRectType = new FillRectMessageType();
protected final DrawIntegerMessageType drawIntegerType = new DrawIntegerMessageType();
protected final DrawThingMLMessageType drawThingMLType = new DrawThingMLMessageType();
protected final CreateMessageType createType = new CreateMessageType();
protected final DestroyMessageType destroyType = new DestroyMessageType();
protected final UpdateMessageType updateType = new UpdateMessageType();
protected final DisplayReadyMessageType displayReadyType = new DisplayReadyMessageType();
//Empty Constructor
public HeadlessDisplay() {
super();
}

//Getters and Setters for non readonly/final attributes
//Getters for Ports
public Port getDisplay_port() {
return display_port;
}
private CompositeState buildHeadlessDisplay(){
final AtomicState state_HeadlessDisplay_null_INIT = new AtomicState("INIT");
state_HeadlessDisplay_null_INIT.onEntry(()->{
sendDisplayReady_via_display();
});
final AtomicState state_HeadlessDisplay_null_MOCK = new AtomicState("MOCK");
Transition h1583992583 = new Transition();
h1583992583.from(state_HeadlessDisplay_null_INIT).to(state_HeadlessDisplay_null_MOCK);
Handler h722929970 = new Handler();
h722929970.from(state_HeadlessDisplay_null_MOCK);
h722929970.event(createType);
h722929970.port(display_port);
h722929970.action((Event e)->{
final CreateMessageType.CreateMessage create = (CreateMessageType.CreateMessage) e;
mock();
});

Handler h1142350221 = new Handler();
h1142350221.from(state_HeadlessDisplay_null_MOCK);
h1142350221.event(destroyType);
h1142350221.port(display_port);
h1142350221.action((Event e)->{
mock();
});

Handler h1891930552 = new Handler();
h1891930552.from(state_HeadlessDisplay_null_MOCK);
h1891930552.event(updateType);
h1891930552.port(display_port);
h1891930552.action((Event e)->{
mock();
});

Handler h27325257 = new Handler();
h27325257.from(state_HeadlessDisplay_null_MOCK);
h27325257.event(clearType);
h27325257.port(display_port);
h27325257.action((Event e)->{
mock();
});

Handler h1009260571 = new Handler();
h1009260571.from(state_HeadlessDisplay_null_MOCK);
h1009260571.event(setColorType);
h1009260571.port(display_port);
h1009260571.action((Event e)->{
final SetColorMessageType.SetColorMessage setColor = (SetColorMessageType.SetColorMessage) e;
mock();
});

Handler h1224970135 = new Handler();
h1224970135.from(state_HeadlessDisplay_null_MOCK);
h1224970135.event(setBGColorType);
h1224970135.port(display_port);
h1224970135.action((Event e)->{
final SetBGColorMessageType.SetBGColorMessage setBGColor = (SetBGColorMessageType.SetBGColorMessage) e;
mock();
});

Handler h14093978 = new Handler();
h14093978.from(state_HeadlessDisplay_null_MOCK);
h14093978.event(drawRectType);
h14093978.port(display_port);
h14093978.action((Event e)->{
final DrawRectMessageType.DrawRectMessage drawRect = (DrawRectMessageType.DrawRectMessage) e;
mock();
});

Handler h2132762784 = new Handler();
h2132762784.from(state_HeadlessDisplay_null_MOCK);
h2132762784.event(fillRectType);
h2132762784.port(display_port);
h2132762784.action((Event e)->{
final FillRectMessageType.FillRectMessage fillRect = (FillRectMessageType.FillRectMessage) e;
mock();
});

Handler h863313225 = new Handler();
h863313225.from(state_HeadlessDisplay_null_MOCK);
h863313225.event(drawIntegerType);
h863313225.port(display_port);
h863313225.action((Event e)->{
final DrawIntegerMessageType.DrawIntegerMessage drawInteger = (DrawIntegerMessageType.DrawIntegerMessage) e;
mock();
});

Handler h1625094636 = new Handler();
h1625094636.from(state_HeadlessDisplay_null_MOCK);
h1625094636.event(drawThingMLType);
h1625094636.port(display_port);
h1625094636.action((Event e)->{
final DrawThingMLMessageType.DrawThingMLMessage drawThingML = (DrawThingMLMessageType.DrawThingMLMessage) e;
mock();
});

final CompositeState state_HeadlessDisplay = new CompositeState("null");
state_HeadlessDisplay.onEntry(()->{
});
state_HeadlessDisplay.add(state_HeadlessDisplay_null_INIT);
state_HeadlessDisplay.add(state_HeadlessDisplay_null_MOCK);
state_HeadlessDisplay.initial(state_HeadlessDisplay_null_INIT);
return state_HeadlessDisplay;
}

public Component buildBehavior(String session, Component root) {
if (root == null) {
//Init ports
display_port = new Port("display", this);
} else {
display_port = ((HeadlessDisplay)root).display_port;
}
if (session == null){
//Init state machine
behavior = buildHeadlessDisplay();
}
return this;
}

 void mock() {
}
}
