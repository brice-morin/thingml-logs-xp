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
 * Definition for type : ConsoleLogger
 **/
public class ConsoleLogger extends Component implements IConsoleLogger_log {

private boolean debug = false;
public boolean isDebug() {return debug;}
public void setDebug(boolean debug) {this.debug = debug;}
public String toString() {
String result = "instance " + getName() + "\n";
result += "\tACTIVATE_ON_STARTUP = " + Logger_ACTIVATE_ON_STARTUP_var;
result += "";
return result;
}

public synchronized void function_called_via_log(String LogMsgs_function_called_inst_var, String LogMsgs_function_called_fn_name_var, String LogMsgs_function_called_ty_var, String LogMsgs_function_called_returns_var, String LogMsgs_function_called_params_var){
final Event _msg = function_calledType.instantiate(LogMsgs_function_called_inst_var, LogMsgs_function_called_fn_name_var, LogMsgs_function_called_ty_var, LogMsgs_function_called_returns_var, LogMsgs_function_called_params_var);
_msg.setPort(log_port);
receive(_msg);
}

public synchronized void property_changed_via_log(String LogMsgs_property_changed_inst_var, String LogMsgs_property_changed_prop_name_var, String LogMsgs_property_changed_ty_var, String LogMsgs_property_changed_old_value_var, String LogMsgs_property_changed_new_value_var){
final Event _msg = property_changedType.instantiate(LogMsgs_property_changed_inst_var, LogMsgs_property_changed_prop_name_var, LogMsgs_property_changed_ty_var, LogMsgs_property_changed_old_value_var, LogMsgs_property_changed_new_value_var);
_msg.setPort(log_port);
receive(_msg);
}

public synchronized void message_lost_via_log(String LogMsgs_message_lost_inst_var, String LogMsgs_message_lost_port_name_var, String LogMsgs_message_lost_msg_name_var, String LogMsgs_message_lost_params_var){
final Event _msg = message_lostType.instantiate(LogMsgs_message_lost_inst_var, LogMsgs_message_lost_port_name_var, LogMsgs_message_lost_msg_name_var, LogMsgs_message_lost_params_var);
_msg.setPort(log_port);
receive(_msg);
}

public synchronized void message_handled_via_log(String LogMsgs_message_handled_inst_var, String LogMsgs_message_handled_source_var, String LogMsgs_message_handled_target_var, String LogMsgs_message_handled_port_name_var, String LogMsgs_message_handled_msg_name_var, String LogMsgs_message_handled_params_var){
final Event _msg = message_handledType.instantiate(LogMsgs_message_handled_inst_var, LogMsgs_message_handled_source_var, LogMsgs_message_handled_target_var, LogMsgs_message_handled_port_name_var, LogMsgs_message_handled_msg_name_var, LogMsgs_message_handled_params_var);
_msg.setPort(log_port);
receive(_msg);
}

public synchronized void message_sent_via_log(String LogMsgs_message_sent_inst_var, String LogMsgs_message_sent_port_name_var, String LogMsgs_message_sent_msg_name_var, String LogMsgs_message_sent_params_var){
final Event _msg = message_sentType.instantiate(LogMsgs_message_sent_inst_var, LogMsgs_message_sent_port_name_var, LogMsgs_message_sent_msg_name_var, LogMsgs_message_sent_params_var);
_msg.setPort(log_port);
receive(_msg);
}

public synchronized void log_on_via_log(){
final Event _msg = log_onType.instantiate();
_msg.setPort(log_port);
receive(_msg);
}

public synchronized void log_off_via_log(){
final Event _msg = log_offType.instantiate();
_msg.setPort(log_port);
receive(_msg);
}

//Attributes
private boolean Logger_ACTIVATE_ON_STARTUP_var;
//Ports
private Port log_port;
//Message types
protected final Log_onMessageType log_onType = new Log_onMessageType();
protected final Log_offMessageType log_offType = new Log_offMessageType();
protected final Function_calledMessageType function_calledType = new Function_calledMessageType();
protected final Property_changedMessageType property_changedType = new Property_changedMessageType();
protected final Message_sentMessageType message_sentType = new Message_sentMessageType();
protected final Message_lostMessageType message_lostType = new Message_lostMessageType();
protected final Message_handledMessageType message_handledType = new Message_handledMessageType();
//Empty Constructor
public ConsoleLogger() {
super();
}

//Getters and Setters for non readonly/final attributes
public boolean getLogger_ACTIVATE_ON_STARTUP_var() {
return Logger_ACTIVATE_ON_STARTUP_var;
}

public ConsoleLogger initLogger_ACTIVATE_ON_STARTUP_var(boolean Logger_ACTIVATE_ON_STARTUP_var) {
this.Logger_ACTIVATE_ON_STARTUP_var = Logger_ACTIVATE_ON_STARTUP_var;
return this;
}

//Getters for Ports
public Port getLog_port() {
return log_port;
}
private CompositeState buildLogger(){
final AtomicState state_Logger_null_STARTUP = new AtomicState("STARTUP");
final AtomicState state_Logger_null_ON = new AtomicState("ON");
final AtomicState state_Logger_null_OFF = new AtomicState("OFF");
Transition h718057154 = new Transition();
h718057154.from(state_Logger_null_STARTUP).to(state_Logger_null_ON);
h718057154.guard((Event e)->{
return getLogger_ACTIVATE_ON_STARTUP_var();
});

Transition h8633103 = new Transition();
h8633103.from(state_Logger_null_STARTUP).to(state_Logger_null_OFF);
h8633103.guard((Event e)->{
return  !(getLogger_ACTIVATE_ON_STARTUP_var());
});

Handler h1796938191 = new Handler();
h1796938191.from(state_Logger_null_ON);
h1796938191.event(function_calledType);
h1796938191.port(log_port);
h1796938191.action((Event e)->{
final Function_calledMessageType.Function_calledMessage function_called = (Function_calledMessageType.Function_calledMessage) e;
log_function_called((String) (function_called.inst), (String) (function_called.fn_name), (String) (function_called.ty), (String) (function_called.returns), (String) (function_called.params));
});

Handler h813583428 = new Handler();
h813583428.from(state_Logger_null_ON);
h813583428.event(property_changedType);
h813583428.port(log_port);
h813583428.action((Event e)->{
final Property_changedMessageType.Property_changedMessage property_changed = (Property_changedMessageType.Property_changedMessage) e;
log_property_changed((String) (property_changed.inst), (String) (property_changed.prop_name), (String) (property_changed.ty), (String) (property_changed.old_value), (String) (property_changed.new_value));
});

Handler h867909510 = new Handler();
h867909510.from(state_Logger_null_ON);
h867909510.event(message_lostType);
h867909510.port(log_port);
h867909510.action((Event e)->{
final Message_lostMessageType.Message_lostMessage message_lost = (Message_lostMessageType.Message_lostMessage) e;
log_message_lost((String) (message_lost.inst), (String) (message_lost.port_name), (String) (message_lost.msg_name), (String) (message_lost.params));
});

Handler h21063905 = new Handler();
h21063905.from(state_Logger_null_ON);
h21063905.event(message_sentType);
h21063905.port(log_port);
h21063905.action((Event e)->{
final Message_sentMessageType.Message_sentMessage message_sent = (Message_sentMessageType.Message_sentMessage) e;
log_message_sent((String) (message_sent.inst), (String) (message_sent.port_name), (String) (message_sent.msg_name), (String) (message_sent.params));
});

Handler h784961589 = new Handler();
h784961589.from(state_Logger_null_ON);
h784961589.event(message_handledType);
h784961589.port(log_port);
h784961589.action((Event e)->{
final Message_handledMessageType.Message_handledMessage message_handled = (Message_handledMessageType.Message_handledMessage) e;
log_message_handled((String) (message_handled.inst), (String) (message_handled.source), (String) (message_handled.target), (String) (message_handled.port_name), (String) (message_handled.msg_name), (String) (message_handled.params));
});

Transition h1656059001 = new Transition();
h1656059001.from(state_Logger_null_ON).to(state_Logger_null_OFF);
h1656059001.event(log_offType);
h1656059001.port(log_port);
Transition h323981046 = new Transition();
h323981046.from(state_Logger_null_OFF).to(state_Logger_null_ON);
h323981046.event(log_onType);
h323981046.port(log_port);
final CompositeState state_Logger = new CompositeState("null");
state_Logger.add(state_Logger_null_STARTUP);
state_Logger.add(state_Logger_null_ON);
state_Logger.add(state_Logger_null_OFF);
state_Logger.initial(state_Logger_null_STARTUP);
return state_Logger;
}

public Component buildBehavior(String session, Component root) {
if (root == null) {
//Init ports
log_port = new Port("log", this);
} else {
log_port = ((ConsoleLogger)root).log_port;
}
if (session == null){
//Init state machine
behavior = buildLogger();
}
return this;
}

 void log_function_called(final String ConsoleLogger_log_function_called_inst_var, final String ConsoleLogger_log_function_called_fn_name_var, final String ConsoleLogger_log_function_called_ty_var, final String ConsoleLogger_log_function_called_returns_var, final String ConsoleLogger_log_function_called_params_var) {
synchronized(System.out) {
System.out.println(""+("log: function_called(")+(ConsoleLogger_log_function_called_inst_var)+(", ")+(ConsoleLogger_log_function_called_fn_name_var)+(", ")+(ConsoleLogger_log_function_called_ty_var)+(", ")+(ConsoleLogger_log_function_called_returns_var)+(", ")+(ConsoleLogger_log_function_called_params_var)+(")"));
}
}
 void log_property_changed(final String ConsoleLogger_log_property_changed_inst_var, final String ConsoleLogger_log_property_changed_prop_name_var, final String ConsoleLogger_log_property_changed_ty_var, final String ConsoleLogger_log_property_changed_old_var, final String ConsoleLogger_log_property_changed_new_var) {
synchronized(System.out) {
System.out.println(""+("log: property_changed(")+(ConsoleLogger_log_property_changed_inst_var)+(", ")+(ConsoleLogger_log_property_changed_prop_name_var)+(", ")+(ConsoleLogger_log_property_changed_ty_var)+(", ")+(ConsoleLogger_log_property_changed_old_var)+(", ")+(ConsoleLogger_log_property_changed_new_var)+(")"));
}
}
 void log_message_lost(final String ConsoleLogger_log_message_lost_inst_var, final String ConsoleLogger_log_message_lost_port_name_var, final String ConsoleLogger_log_message_lost_msg_name_var, final String ConsoleLogger_log_message_lost_params_var) {
synchronized(System.out) {
System.out.println(""+("log: message_lost(")+(ConsoleLogger_log_message_lost_inst_var)+(", ")+(ConsoleLogger_log_message_lost_port_name_var)+(", ")+(ConsoleLogger_log_message_lost_msg_name_var)+(", ")+(ConsoleLogger_log_message_lost_params_var)+(")"));
}
}
 void log_message_sent(final String ConsoleLogger_log_message_sent_inst_var, final String ConsoleLogger_log_message_sent_port_name_var, final String ConsoleLogger_log_message_sent_msg_name_var, final String ConsoleLogger_log_message_sent_params_var) {
synchronized(System.out) {
System.out.println(""+("log: message_sent(")+(ConsoleLogger_log_message_sent_inst_var)+(", ")+(ConsoleLogger_log_message_sent_port_name_var)+(", ")+(ConsoleLogger_log_message_sent_msg_name_var)+(", ")+(ConsoleLogger_log_message_sent_params_var)+(")"));
}
}
 void log_message_handled(final String ConsoleLogger_log_message_handled_inst_var, final String ConsoleLogger_log_message_handled_source_var, final String ConsoleLogger_log_message_handled_target_var, final String ConsoleLogger_log_message_handled_port_name_var, final String ConsoleLogger_log_message_handled_msg_name_var, final String ConsoleLogger_log_message_handled_params_var) {
synchronized(System.out) {
System.out.println(""+("log: message_handled(")+(ConsoleLogger_log_message_handled_inst_var)+(", ")+(ConsoleLogger_log_message_handled_source_var)+(", ")+(ConsoleLogger_log_message_handled_target_var)+(", ")+(ConsoleLogger_log_message_handled_port_name_var)+(", ")+(ConsoleLogger_log_message_handled_msg_name_var)+(", ")+(ConsoleLogger_log_message_handled_params_var)+(")"));
}
}
}
