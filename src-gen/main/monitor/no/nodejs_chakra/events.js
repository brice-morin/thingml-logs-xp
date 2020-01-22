var SetColor_DisplayMsgs = /** @class */ (function () {
  function SetColor_DisplayMsgs(from, port,...params) {
    this.type = 'setColor';
    this.port = port;
    this.from = from;
    this.r = params[0];
    this.g = params[1];
    this.b = params[2];
  }

  SetColor_DisplayMsgs.prototype.is = function (type) {
    return this.type === type;
  };

  SetColor_DisplayMsgs.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + r + ', ' + g + ', ' + b + ')';
  };

  return SetColor_DisplayMsgs;
}());
exports.SetColor_DisplayMsgs = SetColor_DisplayMsgs;

var Destroy_DisplayMsgs = /** @class */ (function () {
  function Destroy_DisplayMsgs(from, port,...params) {
    this.type = 'destroy';
    this.port = port;
    this.from = from;
  }

  Destroy_DisplayMsgs.prototype.is = function (type) {
    return this.type === type;
  };

  Destroy_DisplayMsgs.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' +  + ')';
  };

  return Destroy_DisplayMsgs;
}());
exports.Destroy_DisplayMsgs = Destroy_DisplayMsgs;

var Position_ControllerMsgs = /** @class */ (function () {
  function Position_ControllerMsgs(from, port,...params) {
    this.type = 'position';
    this.port = port;
    this.from = from;
    this.x = params[0];
    this.y = params[1];
  }

  Position_ControllerMsgs.prototype.is = function (type) {
    return this.type === type;
  };

  Position_ControllerMsgs.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + x + ', ' + y + ')';
  };

  return Position_ControllerMsgs;
}());
exports.Position_ControllerMsgs = Position_ControllerMsgs;

var Clear_DisplayMsgs = /** @class */ (function () {
  function Clear_DisplayMsgs(from, port,...params) {
    this.type = 'clear';
    this.port = port;
    this.from = from;
  }

  Clear_DisplayMsgs.prototype.is = function (type) {
    return this.type === type;
  };

  Clear_DisplayMsgs.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' +  + ')';
  };

  return Clear_DisplayMsgs;
}());
exports.Clear_DisplayMsgs = Clear_DisplayMsgs;

var DrawThingML_DisplayMsgs = /** @class */ (function () {
  function DrawThingML_DisplayMsgs(from, port,...params) {
    this.type = 'drawThingML';
    this.port = port;
    this.from = from;
    this.x = params[0];
    this.y = params[1];
  }

  DrawThingML_DisplayMsgs.prototype.is = function (type) {
    return this.type === type;
  };

  DrawThingML_DisplayMsgs.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + x + ', ' + y + ')';
  };

  return DrawThingML_DisplayMsgs;
}());
exports.DrawThingML_DisplayMsgs = DrawThingML_DisplayMsgs;

var Timer_start_TimerMsgs = /** @class */ (function () {
  function Timer_start_TimerMsgs(from, port,...params) {
    this.type = 'timer_start';
    this.port = port;
    this.from = from;
    this.id = params[0];
    this.time = params[1];
  }

  Timer_start_TimerMsgs.prototype.is = function (type) {
    return this.type === type;
  };

  Timer_start_TimerMsgs.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + id + ', ' + time + ')';
  };

  return Timer_start_TimerMsgs;
}());
exports.Timer_start_TimerMsgs = Timer_start_TimerMsgs;

var LostBall_BreakoutGame = /** @class */ (function () {
  function LostBall_BreakoutGame(from, port,...params) {
    this.type = 'lostBall';
    this.port = port;
    this.from = from;
  }

  LostBall_BreakoutGame.prototype.is = function (type) {
    return this.type === type;
  };

  LostBall_BreakoutGame.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' +  + ')';
  };

  return LostBall_BreakoutGame;
}());
exports.LostBall_BreakoutGame = LostBall_BreakoutGame;

var FillRect_DisplayMsgs = /** @class */ (function () {
  function FillRect_DisplayMsgs(from, port,...params) {
    this.type = 'fillRect';
    this.port = port;
    this.from = from;
    this.x = params[0];
    this.y = params[1];
    this.width = params[2];
    this.height = params[3];
  }

  FillRect_DisplayMsgs.prototype.is = function (type) {
    return this.type === type;
  };

  FillRect_DisplayMsgs.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + x + ', ' + y + ', ' + width + ', ' + height + ')';
  };

  return FillRect_DisplayMsgs;
}());
exports.FillRect_DisplayMsgs = FillRect_DisplayMsgs;

var Timer_timeout_TimerMsgs = /** @class */ (function () {
  function Timer_timeout_TimerMsgs(from, port,...params) {
    this.type = 'timer_timeout';
    this.port = port;
    this.from = from;
    this.id = params[0];
  }

  Timer_timeout_TimerMsgs.prototype.is = function (type) {
    return this.type === type;
  };

  Timer_timeout_TimerMsgs.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + id + ')';
  };

  return Timer_timeout_TimerMsgs;
}());
exports.Timer_timeout_TimerMsgs = Timer_timeout_TimerMsgs;

var NextLevel_BreakoutGame = /** @class */ (function () {
  function NextLevel_BreakoutGame(from, port,...params) {
    this.type = 'nextLevel';
    this.port = port;
    this.from = from;
  }

  NextLevel_BreakoutGame.prototype.is = function (type) {
    return this.type === type;
  };

  NextLevel_BreakoutGame.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' +  + ')';
  };

  return NextLevel_BreakoutGame;
}());
exports.NextLevel_BreakoutGame = NextLevel_BreakoutGame;

var Update_DisplayMsgs = /** @class */ (function () {
  function Update_DisplayMsgs(from, port,...params) {
    this.type = 'update';
    this.port = port;
    this.from = from;
  }

  Update_DisplayMsgs.prototype.is = function (type) {
    return this.type === type;
  };

  Update_DisplayMsgs.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' +  + ')';
  };

  return Update_DisplayMsgs;
}());
exports.Update_DisplayMsgs = Update_DisplayMsgs;

var SetBGColor_DisplayMsgs = /** @class */ (function () {
  function SetBGColor_DisplayMsgs(from, port,...params) {
    this.type = 'setBGColor';
    this.port = port;
    this.from = from;
    this.r = params[0];
    this.g = params[1];
    this.b = params[2];
  }

  SetBGColor_DisplayMsgs.prototype.is = function (type) {
    return this.type === type;
  };

  SetBGColor_DisplayMsgs.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + r + ', ' + g + ', ' + b + ')';
  };

  return SetBGColor_DisplayMsgs;
}());
exports.SetBGColor_DisplayMsgs = SetBGColor_DisplayMsgs;

var UpdateIA_IAControllerMsg = /** @class */ (function () {
  function UpdateIA_IAControllerMsg(from, port,...params) {
    this.type = 'updateIA';
    this.port = port;
    this.from = from;
    this.ballx = params[0];
    this.bally = params[1];
    this.padx = params[2];
    this.pady = params[3];
  }

  UpdateIA_IAControllerMsg.prototype.is = function (type) {
    return this.type === type;
  };

  UpdateIA_IAControllerMsg.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + ballx + ', ' + bally + ', ' + padx + ', ' + pady + ')';
  };

  return UpdateIA_IAControllerMsg;
}());
exports.UpdateIA_IAControllerMsg = UpdateIA_IAControllerMsg;

var DrawInteger_DisplayMsgs = /** @class */ (function () {
  function DrawInteger_DisplayMsgs(from, port,...params) {
    this.type = 'drawInteger';
    this.port = port;
    this.from = from;
    this.x = params[0];
    this.y = params[1];
    this.v = params[2];
    this.digits = params[3];
    this.scale = params[4];
  }

  DrawInteger_DisplayMsgs.prototype.is = function (type) {
    return this.type === type;
  };

  DrawInteger_DisplayMsgs.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + x + ', ' + y + ', ' + v + ', ' + digits + ', ' + scale + ')';
  };

  return DrawInteger_DisplayMsgs;
}());
exports.DrawInteger_DisplayMsgs = DrawInteger_DisplayMsgs;

var Timer_cancel_TimerMsgs = /** @class */ (function () {
  function Timer_cancel_TimerMsgs(from, port,...params) {
    this.type = 'timer_cancel';
    this.port = port;
    this.from = from;
    this.id = params[0];
  }

  Timer_cancel_TimerMsgs.prototype.is = function (type) {
    return this.type === type;
  };

  Timer_cancel_TimerMsgs.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + id + ')';
  };

  return Timer_cancel_TimerMsgs;
}());
exports.Timer_cancel_TimerMsgs = Timer_cancel_TimerMsgs;

var DisplayReady_DisplayMsgs = /** @class */ (function () {
  function DisplayReady_DisplayMsgs(from, port,...params) {
    this.type = 'displayReady';
    this.port = port;
    this.from = from;
  }

  DisplayReady_DisplayMsgs.prototype.is = function (type) {
    return this.type === type;
  };

  DisplayReady_DisplayMsgs.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' +  + ')';
  };

  return DisplayReady_DisplayMsgs;
}());
exports.DisplayReady_DisplayMsgs = DisplayReady_DisplayMsgs;

var Velocity_ControllerMsgs = /** @class */ (function () {
  function Velocity_ControllerMsgs(from, port,...params) {
    this.type = 'velocity';
    this.port = port;
    this.from = from;
    this.dx = params[0];
    this.dy = params[1];
  }

  Velocity_ControllerMsgs.prototype.is = function (type) {
    return this.type === type;
  };

  Velocity_ControllerMsgs.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + dx + ', ' + dy + ')';
  };

  return Velocity_ControllerMsgs;
}());
exports.Velocity_ControllerMsgs = Velocity_ControllerMsgs;

var DrawRect_DisplayMsgs = /** @class */ (function () {
  function DrawRect_DisplayMsgs(from, port,...params) {
    this.type = 'drawRect';
    this.port = port;
    this.from = from;
    this.x = params[0];
    this.y = params[1];
    this.width = params[2];
    this.height = params[3];
  }

  DrawRect_DisplayMsgs.prototype.is = function (type) {
    return this.type === type;
  };

  DrawRect_DisplayMsgs.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + x + ', ' + y + ', ' + width + ', ' + height + ')';
  };

  return DrawRect_DisplayMsgs;
}());
exports.DrawRect_DisplayMsgs = DrawRect_DisplayMsgs;

var Create_DisplayMsgs = /** @class */ (function () {
  function Create_DisplayMsgs(from, port,...params) {
    this.type = 'create';
    this.port = port;
    this.from = from;
    this.xsize = params[0];
    this.ysize = params[1];
  }

  Create_DisplayMsgs.prototype.is = function (type) {
    return this.type === type;
  };

  Create_DisplayMsgs.prototype.toString = function () {
    return 'event ' + this.type + '?' + this.port + '(' + xsize + ', ' + ysize + ')';
  };

  return Create_DisplayMsgs;
}());
exports.Create_DisplayMsgs = Create_DisplayMsgs;

