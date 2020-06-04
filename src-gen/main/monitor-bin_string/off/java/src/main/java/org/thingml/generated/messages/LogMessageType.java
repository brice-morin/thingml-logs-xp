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

public class LogMessageType extends EventType {
public LogMessageType(short code) {super("log", code);
}

public LogMessageType() {
super("log", (short) 0);
}

public Event instantiate(final byte[] payload, final int size) { return new LogMessage(this, payload, size); }
public Event instantiate(Map<String, Object> params) {return instantiate((byte[]) params.get("payload"), (Integer) params.get("size"));
}

public class LogMessage extends Event implements java.io.Serializable {

public final byte[] payload;
public final int size;
public String toString(){
return "log (" + "payload: " + payload + ", " + "size: " + size + ")";
}

protected LogMessage(EventType type, final byte[] payload, final int size) {
super(type);
this.payload = payload;
this.size = size;
}
public Event clone() {
return instantiate(this.payload, this.size);
}}

}
