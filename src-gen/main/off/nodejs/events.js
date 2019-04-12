var DrawThingML = /** @class */ (function () {
  function DrawThingML(port,...params) {
    this.type = 'drawThingML';
    this.port = port;
    this.x = params[0];
    this.y = params[1];
  }

  DrawThingML.prototype.is = function (type) {
    return this.type === type;
  };

  DrawThingML.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + x + ', ' + y + ')';
  };

  return DrawThingML;
}());
exports.DrawThingML = DrawThingML;

var DisplayReady = /** @class */ (function () {
  function DisplayReady(port,...params) {
    this.type = 'displayReady';
    this.port = port;
  }

  DisplayReady.prototype.is = function (type) {
    return this.type === type;
  };

  DisplayReady.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' +  + ')';
  };

  return DisplayReady;
}());
exports.DisplayReady = DisplayReady;

var Timer_start = /** @class */ (function () {
  function Timer_start(port,...params) {
    this.type = 'timer_start';
    this.port = port;
    this.id = params[0];
    this.time = params[1];
  }

  Timer_start.prototype.is = function (type) {
    return this.type === type;
  };

  Timer_start.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + id + ', ' + time + ')';
  };

  return Timer_start;
}());
exports.Timer_start = Timer_start;

var SetColor = /** @class */ (function () {
  function SetColor(port,...params) {
    this.type = 'setColor';
    this.port = port;
    this.r = params[0];
    this.g = params[1];
    this.b = params[2];
  }

  SetColor.prototype.is = function (type) {
    return this.type === type;
  };

  SetColor.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + r + ', ' + g + ', ' + b + ')';
  };

  return SetColor;
}());
exports.SetColor = SetColor;

var Position = /** @class */ (function () {
  function Position(port,...params) {
    this.type = 'position';
    this.port = port;
    this.x = params[0];
    this.y = params[1];
  }

  Position.prototype.is = function (type) {
    return this.type === type;
  };

  Position.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + x + ', ' + y + ')';
  };

  return Position;
}());
exports.Position = Position;

var Log_on = /** @class */ (function () {
  function Log_on(port,...params) {
    this.type = 'log_on';
    this.port = port;
  }

  Log_on.prototype.is = function (type) {
    return this.type === type;
  };

  Log_on.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' +  + ')';
  };

  return Log_on;
}());
exports.Log_on = Log_on;

var Velocity = /** @class */ (function () {
  function Velocity(port,...params) {
    this.type = 'velocity';
    this.port = port;
    this.dx = params[0];
    this.dy = params[1];
  }

  Velocity.prototype.is = function (type) {
    return this.type === type;
  };

  Velocity.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + dx + ', ' + dy + ')';
  };

  return Velocity;
}());
exports.Velocity = Velocity;

var Timer_timeout = /** @class */ (function () {
  function Timer_timeout(port,...params) {
    this.type = 'timer_timeout';
    this.port = port;
    this.id = params[0];
  }

  Timer_timeout.prototype.is = function (type) {
    return this.type === type;
  };

  Timer_timeout.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + id + ')';
  };

  return Timer_timeout;
}());
exports.Timer_timeout = Timer_timeout;

var Create = /** @class */ (function () {
  function Create(port,...params) {
    this.type = 'create';
    this.port = port;
    this.xsize = params[0];
    this.ysize = params[1];
  }

  Create.prototype.is = function (type) {
    return this.type === type;
  };

  Create.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + xsize + ', ' + ysize + ')';
  };

  return Create;
}());
exports.Create = Create;

var SetBGColor = /** @class */ (function () {
  function SetBGColor(port,...params) {
    this.type = 'setBGColor';
    this.port = port;
    this.r = params[0];
    this.g = params[1];
    this.b = params[2];
  }

  SetBGColor.prototype.is = function (type) {
    return this.type === type;
  };

  SetBGColor.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + r + ', ' + g + ', ' + b + ')';
  };

  return SetBGColor;
}());
exports.SetBGColor = SetBGColor;

var LostBall = /** @class */ (function () {
  function LostBall(port,...params) {
    this.type = 'lostBall';
    this.port = port;
  }

  LostBall.prototype.is = function (type) {
    return this.type === type;
  };

  LostBall.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' +  + ')';
  };

  return LostBall;
}());
exports.LostBall = LostBall;

var Log_off = /** @class */ (function () {
  function Log_off(port,...params) {
    this.type = 'log_off';
    this.port = port;
  }

  Log_off.prototype.is = function (type) {
    return this.type === type;
  };

  Log_off.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' +  + ')';
  };

  return Log_off;
}());
exports.Log_off = Log_off;

var Timer_cancel = /** @class */ (function () {
  function Timer_cancel(port,...params) {
    this.type = 'timer_cancel';
    this.port = port;
    this.id = params[0];
  }

  Timer_cancel.prototype.is = function (type) {
    return this.type === type;
  };

  Timer_cancel.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + id + ')';
  };

  return Timer_cancel;
}());
exports.Timer_cancel = Timer_cancel;

var Message_handled = /** @class */ (function () {
  function Message_handled(port,...params) {
    this.type = 'message_handled';
    this.port = port;
    this.inst = params[0];
    this.source = params[1];
    this.target = params[2];
    this.port_name = params[3];
    this.msg_name = params[4];
    this.params = params[5];
  }

  Message_handled.prototype.is = function (type) {
    return this.type === type;
  };

  Message_handled.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + inst + ', ' + source + ', ' + target + ', ' + port_name + ', ' + msg_name + ', ' + params + ')';
  };

  return Message_handled;
}());
exports.Message_handled = Message_handled;

var NextLevel = /** @class */ (function () {
  function NextLevel(port,...params) {
    this.type = 'nextLevel';
    this.port = port;
  }

  NextLevel.prototype.is = function (type) {
    return this.type === type;
  };

  NextLevel.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' +  + ')';
  };

  return NextLevel;
}());
exports.NextLevel = NextLevel;

var DrawRect = /** @class */ (function () {
  function DrawRect(port,...params) {
    this.type = 'drawRect';
    this.port = port;
    this.x = params[0];
    this.y = params[1];
    this.width = params[2];
    this.height = params[3];
  }

  DrawRect.prototype.is = function (type) {
    return this.type === type;
  };

  DrawRect.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + x + ', ' + y + ', ' + width + ', ' + height + ')';
  };

  return DrawRect;
}());
exports.DrawRect = DrawRect;

var Message_lost = /** @class */ (function () {
  function Message_lost(port,...params) {
    this.type = 'message_lost';
    this.port = port;
    this.inst = params[0];
    this.port_name = params[1];
    this.msg_name = params[2];
    this.params = params[3];
  }

  Message_lost.prototype.is = function (type) {
    return this.type === type;
  };

  Message_lost.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + inst + ', ' + port_name + ', ' + msg_name + ', ' + params + ')';
  };

  return Message_lost;
}());
exports.Message_lost = Message_lost;

var UpdateIA = /** @class */ (function () {
  function UpdateIA(port,...params) {
    this.type = 'updateIA';
    this.port = port;
    this.ballx = params[0];
    this.bally = params[1];
    this.padx = params[2];
    this.pady = params[3];
  }

  UpdateIA.prototype.is = function (type) {
    return this.type === type;
  };

  UpdateIA.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + ballx + ', ' + bally + ', ' + padx + ', ' + pady + ')';
  };

  return UpdateIA;
}());
exports.UpdateIA = UpdateIA;

var Destroy = /** @class */ (function () {
  function Destroy(port,...params) {
    this.type = 'destroy';
    this.port = port;
  }

  Destroy.prototype.is = function (type) {
    return this.type === type;
  };

  Destroy.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' +  + ')';
  };

  return Destroy;
}());
exports.Destroy = Destroy;

var Clear = /** @class */ (function () {
  function Clear(port,...params) {
    this.type = 'clear';
    this.port = port;
  }

  Clear.prototype.is = function (type) {
    return this.type === type;
  };

  Clear.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' +  + ')';
  };

  return Clear;
}());
exports.Clear = Clear;

var Message_sent = /** @class */ (function () {
  function Message_sent(port,...params) {
    this.type = 'message_sent';
    this.port = port;
    this.inst = params[0];
    this.port_name = params[1];
    this.msg_name = params[2];
    this.params = params[3];
  }

  Message_sent.prototype.is = function (type) {
    return this.type === type;
  };

  Message_sent.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + inst + ', ' + port_name + ', ' + msg_name + ', ' + params + ')';
  };

  return Message_sent;
}());
exports.Message_sent = Message_sent;

var DrawInteger = /** @class */ (function () {
  function DrawInteger(port,...params) {
    this.type = 'drawInteger';
    this.port = port;
    this.x = params[0];
    this.y = params[1];
    this.v = params[2];
    this.digits = params[3];
    this.scale = params[4];
  }

  DrawInteger.prototype.is = function (type) {
    return this.type === type;
  };

  DrawInteger.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + x + ', ' + y + ', ' + v + ', ' + digits + ', ' + scale + ')';
  };

  return DrawInteger;
}());
exports.DrawInteger = DrawInteger;

var Function_called = /** @class */ (function () {
  function Function_called(port,...params) {
    this.type = 'function_called';
    this.port = port;
    this.inst = params[0];
    this.fn_name = params[1];
    this.ty = params[2];
    this.returns = params[3];
    this.params = params[4];
  }

  Function_called.prototype.is = function (type) {
    return this.type === type;
  };

  Function_called.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + inst + ', ' + fn_name + ', ' + ty + ', ' + returns + ', ' + params + ')';
  };

  return Function_called;
}());
exports.Function_called = Function_called;

var Update = /** @class */ (function () {
  function Update(port,...params) {
    this.type = 'update';
    this.port = port;
  }

  Update.prototype.is = function (type) {
    return this.type === type;
  };

  Update.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' +  + ')';
  };

  return Update;
}());
exports.Update = Update;

var FillRect = /** @class */ (function () {
  function FillRect(port,...params) {
    this.type = 'fillRect';
    this.port = port;
    this.x = params[0];
    this.y = params[1];
    this.width = params[2];
    this.height = params[3];
  }

  FillRect.prototype.is = function (type) {
    return this.type === type;
  };

  FillRect.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + x + ', ' + y + ', ' + width + ', ' + height + ')';
  };

  return FillRect;
}());
exports.FillRect = FillRect;

var Property_changed = /** @class */ (function () {
  function Property_changed(port,...params) {
    this.type = 'property_changed';
    this.port = port;
    this.inst = params[0];
    this.prop_name = params[1];
    this.ty = params[2];
    this.old_value = params[3];
    this.new_value = params[4];
  }

  Property_changed.prototype.is = function (type) {
    return this.type === type;
  };

  Property_changed.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + inst + ', ' + prop_name + ', ' + ty + ', ' + old_value + ', ' + new_value + ')';
  };

  return Property_changed;
}());
exports.Property_changed = Property_changed;

