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

