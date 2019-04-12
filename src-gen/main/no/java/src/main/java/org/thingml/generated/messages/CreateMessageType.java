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

public class CreateMessageType extends EventType {
public CreateMessageType(short code) {super("create", code);
}

public CreateMessageType() {
super("create", (short) 0);
}

public Event instantiate(final int xsize, final int ysize) { return new CreateMessage(this, xsize, ysize); }
public Event instantiate(Map<String, Object> params) {return instantiate((Integer) params.get("xsize"), (Integer) params.get("ysize"));
}

public class CreateMessage extends Event implements java.io.Serializable {

public final int xsize;
public final int ysize;
public String toString(){
return "create (" + "xsize: " + xsize + ", " + "ysize: " + ysize + ")";
}

protected CreateMessage(EventType type, final int xsize, final int ysize) {
super(type);
this.xsize = xsize;
this.ysize = ysize;
}
public Event clone() {
return instantiate(this.xsize, this.ysize);
}}

}
