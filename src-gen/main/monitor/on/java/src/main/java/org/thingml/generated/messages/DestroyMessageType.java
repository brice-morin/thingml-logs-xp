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

public class DestroyMessageType extends EventType {
public DestroyMessageType(short code) {super("destroy", code);
}

public DestroyMessageType() {
super("destroy", (short) 0);
}

public Event instantiate() { return new DestroyMessage(this); }
public Event instantiate(Map<String, Object> params) {return instantiate();
}

public class DestroyMessage extends Event implements java.io.Serializable {

public String toString(){
return "destroy (" + ")";
}

protected DestroyMessage(EventType type) {
super(type);
}
public Event clone() {
return instantiate();
}}

}

