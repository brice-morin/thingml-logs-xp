/**
 * File generated by the ThingML IDE
 * /!\Do not edit this file/!\
 * In case of a bug in the generated code,
 * please submit an issue on our GitHub
 **/

package org.thingml.generated.messages;

import no.sintef.jasm.*;
import no.sintef.jasm.ext.*;

import java.util.*;
import java.nio.*;

public class Message_handledMessageType extends EventType {
public Message_handledMessageType(short code) {super("message_handled", code);
}

public Message_handledMessageType() {
super("message_handled", (short) 0);
}

public Event instantiate(final String inst, final String source, final String target, final String port_name, final String msg_name, final String params) { return new Message_handledMessage(this, inst, source, target, port_name, msg_name, params); }
public Event instantiate(Map<String, Object> params) {return instantiate((String) params.get("inst"), (String) params.get("source"), (String) params.get("target"), (String) params.get("port_name"), (String) params.get("msg_name"), (String) params.get("params"));
}

public class Message_handledMessage extends Event implements java.io.Serializable {

public final String inst;
public final String source;
public final String target;
public final String port_name;
public final String msg_name;
public final String params;
public String toString(){
return "message_handled (" + "inst: " + inst + ", " + "source: " + source + ", " + "target: " + target + ", " + "port_name: " + port_name + ", " + "msg_name: " + msg_name + ", " + "params: " + params + ")";
}

protected Message_handledMessage(EventType type, final String inst, final String source, final String target, final String port_name, final String msg_name, final String params) {
super(type);
this.inst = inst;
this.source = source;
this.target = target;
this.port_name = port_name;
this.msg_name = msg_name;
this.params = params;
}
public Event clone() {
return instantiate(this.inst, this.source, this.target, this.port_name, this.msg_name, this.params);
}}

}

