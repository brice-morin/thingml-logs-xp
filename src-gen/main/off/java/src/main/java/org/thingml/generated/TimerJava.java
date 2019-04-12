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

//START: @java_import annotation
import java.util.*;

//END: @java_import annotation

/**
 * Definition for type : TimerJava
 **/
public class TimerJava extends Component implements ITimerJava_timer {


	// START: @java_features annotation

	Hashtable<Integer, TimerTask> tasks = new Hashtable<Integer, TimerTask>();
	Timer timer = new java.util.Timer();

	// END: @java_features annotation

private boolean debug = false;
public boolean isDebug() {return debug;}
public void setDebug(boolean debug) {this.debug = debug;}
public String toString() {
String result = "instance " + getName() + "\n";
result += "";
return result;
}

public synchronized void timer_start_via_timer(int TimerMsgs_timer_start_id_var, int TimerMsgs_timer_start_time_var){
final Event _msg = timer_startType.instantiate(TimerMsgs_timer_start_id_var, TimerMsgs_timer_start_time_var);
_msg.setPort(timer_port);
receive(_msg);
}

public synchronized void timer_cancel_via_timer(int TimerMsgs_timer_cancel_id_var){
final Event _msg = timer_cancelType.instantiate(TimerMsgs_timer_cancel_id_var);
_msg.setPort(timer_port);
receive(_msg);
}

private void sendTimer_timeout_via_timer(int TimerMsgs_timer_timeout_id_var){
timer_port.send(timer_timeoutType.instantiate(TimerMsgs_timer_timeout_id_var));
}

//Attributes
//Ports
private Port timer_port;
//Message types
protected final Timer_startMessageType timer_startType = new Timer_startMessageType();
protected final Timer_cancelMessageType timer_cancelType = new Timer_cancelMessageType();
protected final Timer_timeoutMessageType timer_timeoutType = new Timer_timeoutMessageType();
//Empty Constructor
public TimerJava() {
super();
}

//Getters and Setters for non readonly/final attributes
//Getters for Ports
public Port getTimer_port() {
return timer_port;
}
private CompositeState buildTimerJava_SoftTimer(){
final AtomicState state_TimerJava_SoftTimer_default = new AtomicState("default");
Handler h709853193 = new Handler();
h709853193.from(state_TimerJava_SoftTimer_default);
h709853193.event(timer_startType);
h709853193.guard((Event e)->{
final Timer_startMessageType.Timer_startMessage timer_start = (Timer_startMessageType.Timer_startMessage) e;
return timer_start.time > 0;
});

h709853193.port(timer_port);
h709853193.action((Event e)->{
final Timer_startMessageType.Timer_startMessage timer_start = (Timer_startMessageType.Timer_startMessage) e;
startTimer((int) (timer_start.id), (int) (timer_start.time));
});

Handler h968238821 = new Handler();
h968238821.from(state_TimerJava_SoftTimer_default);
h968238821.event(timer_startType);
h968238821.guard((Event e)->{
final Timer_startMessageType.Timer_startMessage timer_start = (Timer_startMessageType.Timer_startMessage) e;
return timer_start.time == 0;
});

h968238821.port(timer_port);
h968238821.action((Event e)->{
final Timer_startMessageType.Timer_startMessage timer_start = (Timer_startMessageType.Timer_startMessage) e;
sendTimer_timeout_via_timer((int) (timer_start.id));
});

Handler cancel = new Handler();
cancel.from(state_TimerJava_SoftTimer_default);
cancel.event(timer_cancelType);
cancel.port(timer_port);
cancel.action((Event e)->{
final Timer_cancelMessageType.Timer_cancelMessage timer_cancel = (Timer_cancelMessageType.Timer_cancelMessage) e;
cancel((int) (timer_cancel.id));
});

final CompositeState state_TimerJava_SoftTimer = new CompositeState("SoftTimer");
state_TimerJava_SoftTimer.onEntry(()->{
});
state_TimerJava_SoftTimer.add(state_TimerJava_SoftTimer_default);
state_TimerJava_SoftTimer.initial(state_TimerJava_SoftTimer_default);
return state_TimerJava_SoftTimer;
}

public Component buildBehavior(String session, Component root) {
if (root == null) {
//Init ports
timer_port = new Port("timer", this);
} else {
timer_port = ((TimerJava)root).timer_port;
}
if (session == null){
//Init state machine
behavior = buildTimerJava_SoftTimer();
}
return this;
}

 void startTimer(final int TimerJava_startTimer_id_var, final int TimerJava_startTimer_delay_var) {
cancel((int) (TimerJava_startTimer_id_var));
final int t_id = TimerJava_startTimer_id_var;
TimerTask t =  new TimerTask() { public void run(){
sendTimer_timeout_via_timer((int) (t_id));

        } };
        tasks.put(t_id, t);
        timer.schedule(t, TimerJava_startTimer_delay_var);
}
 void cancel(final int TimerJava_cancel_id_var) {
TimerTask t = tasks.get(TimerJava_cancel_id_var);
if (t != null) t.cancel();
timer.purge();
}
}
