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
Transition h1871580398 = new Transition();
h1871580398.from(state_HeadlessDisplay_null_INIT).to(state_HeadlessDisplay_null_MOCK);
Handler h1360440329 = new Handler();
h1360440329.from(state_HeadlessDisplay_null_MOCK);
h1360440329.event(createType);
h1360440329.port(display_port);
h1360440329.action((Event e)->{
final CreateMessageType.CreateMessage create = (CreateMessageType.CreateMessage) e;
mock();
});

Handler h841483227 = new Handler();
h841483227.from(state_HeadlessDisplay_null_MOCK);
h841483227.event(destroyType);
h841483227.port(display_port);
h841483227.action((Event e)->{
mock();
});

Handler h2110785285 = new Handler();
h2110785285.from(state_HeadlessDisplay_null_MOCK);
h2110785285.event(updateType);
h2110785285.port(display_port);
h2110785285.action((Event e)->{
mock();
});

Handler h982634822 = new Handler();
h982634822.from(state_HeadlessDisplay_null_MOCK);
h982634822.event(clearType);
h982634822.port(display_port);
h982634822.action((Event e)->{
mock();
});

Handler h1499825229 = new Handler();
h1499825229.from(state_HeadlessDisplay_null_MOCK);
h1499825229.event(setColorType);
h1499825229.port(display_port);
h1499825229.action((Event e)->{
final SetColorMessageType.SetColorMessage setColor = (SetColorMessageType.SetColorMessage) e;
mock();
});

Handler h1285072597 = new Handler();
h1285072597.from(state_HeadlessDisplay_null_MOCK);
h1285072597.event(setBGColorType);
h1285072597.port(display_port);
h1285072597.action((Event e)->{
final SetBGColorMessageType.SetBGColorMessage setBGColor = (SetBGColorMessageType.SetBGColorMessage) e;
mock();
});

Handler h234857227 = new Handler();
h234857227.from(state_HeadlessDisplay_null_MOCK);
h234857227.event(drawRectType);
h234857227.port(display_port);
h234857227.action((Event e)->{
final DrawRectMessageType.DrawRectMessage drawRect = (DrawRectMessageType.DrawRectMessage) e;
mock();
});

Handler h1800959603 = new Handler();
h1800959603.from(state_HeadlessDisplay_null_MOCK);
h1800959603.event(fillRectType);
h1800959603.port(display_port);
h1800959603.action((Event e)->{
final FillRectMessageType.FillRectMessage fillRect = (FillRectMessageType.FillRectMessage) e;
mock();
});

Handler h1399398408 = new Handler();
h1399398408.from(state_HeadlessDisplay_null_MOCK);
h1399398408.event(drawIntegerType);
h1399398408.port(display_port);
h1399398408.action((Event e)->{
final DrawIntegerMessageType.DrawIntegerMessage drawInteger = (DrawIntegerMessageType.DrawIntegerMessage) e;
mock();
});

Handler h1175154004 = new Handler();
h1175154004.from(state_HeadlessDisplay_null_MOCK);
h1175154004.event(drawThingMLType);
h1175154004.port(display_port);
h1175154004.action((Event e)->{
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
