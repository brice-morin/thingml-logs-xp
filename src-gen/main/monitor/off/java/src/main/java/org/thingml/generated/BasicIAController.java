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
 * Definition for type : BasicIAController
 **/
public class BasicIAController extends Component implements IBasicIAController_game {

private boolean debug = false;
public boolean isDebug() {return debug;}
public void setDebug(boolean debug) {this.debug = debug;}
public String toString() {
String result = "instance " + getName() + "\n";
result += "\tctrlx = " + BasicIAController_ctrlx_var;
result += "";
return result;
}

public synchronized void updateIA_via_game(int IAControllerMsg_updateIA_ballx_var, int IAControllerMsg_updateIA_bally_var, int IAControllerMsg_updateIA_padx_var, int IAControllerMsg_updateIA_pady_var){
final Event _msg = updateIAType.instantiate(IAControllerMsg_updateIA_ballx_var, IAControllerMsg_updateIA_bally_var, IAControllerMsg_updateIA_padx_var, IAControllerMsg_updateIA_pady_var);
_msg.setPort(game_port);
receive(_msg);
}

private void sendPosition_via_controls(int ControllerMsgs_position_x_var, int ControllerMsgs_position_y_var){
controls_port.send(positionType.instantiate(ControllerMsgs_position_x_var, ControllerMsgs_position_y_var));
}

//Attributes
private int BasicIAController_ctrlx_var;
//Ports
private Port controls_port;
private Port game_port;
//Message types
protected final VelocityMessageType velocityType = new VelocityMessageType();
protected final PositionMessageType positionType = new PositionMessageType();
protected final UpdateIAMessageType updateIAType = new UpdateIAMessageType();
//Empty Constructor
public BasicIAController() {
super();
}

//Getters and Setters for non readonly/final attributes
public int getBasicIAController_ctrlx_var() {
return BasicIAController_ctrlx_var;
}

public void setBasicIAController_ctrlx_var(int BasicIAController_ctrlx_var) {
this.BasicIAController_ctrlx_var = BasicIAController_ctrlx_var;
}

public BasicIAController initBasicIAController_ctrlx_var(int BasicIAController_ctrlx_var) {
this.BasicIAController_ctrlx_var = BasicIAController_ctrlx_var;
return this;
}

//Getters for Ports
public Port getControls_port() {
return controls_port;
}
public Port getGame_port() {
return game_port;
}
private CompositeState buildBasicIAController_SC(){
final AtomicState state_BasicIAController_SC_Following = new AtomicState("Following");
state_BasicIAController_SC_Following.onEntry(()->{
sendPosition_via_controls((int) (getBasicIAController_ctrlx_var()), (int) (0));
});
Transition h1485129132 = new Transition();
h1485129132.from(state_BasicIAController_SC_Following).to(state_BasicIAController_SC_Following);
h1485129132.event(updateIAType);
h1485129132.port(game_port);
h1485129132.action((Event e)->{
final UpdateIAMessageType.UpdateIAMessage updateIA = (UpdateIAMessageType.UpdateIAMessage) e;
if(updateIA.ballx > updateIA.padx + 400) {
BasicIAController_ctrlx_var = (int) (getBasicIAController_ctrlx_var() + 4);

} else {
if(updateIA.ballx < updateIA.padx - 400) {
BasicIAController_ctrlx_var = (int) (getBasicIAController_ctrlx_var() - 4);

}

}
if(getBasicIAController_ctrlx_var() <  -100) {
BasicIAController_ctrlx_var = (int) ( -100);

} else {
if(getBasicIAController_ctrlx_var() > 100) {
BasicIAController_ctrlx_var = (int) (100);

}

}
});

final CompositeState state_BasicIAController_SC = new CompositeState("SC");
state_BasicIAController_SC.onEntry(()->{
});
state_BasicIAController_SC.add(state_BasicIAController_SC_Following);
state_BasicIAController_SC.initial(state_BasicIAController_SC_Following);
return state_BasicIAController_SC;
}

public Component buildBehavior(String session, Component root) {
if (root == null) {
//Init ports
controls_port = new Port("controls", this);
game_port = new Port("game", this);
} else {
controls_port = ((BasicIAController)root).controls_port;
game_port = ((BasicIAController)root).game_port;
}
if (session == null){
//Init state machine
behavior = buildBasicIAController_SC();
}
return this;
}

}
