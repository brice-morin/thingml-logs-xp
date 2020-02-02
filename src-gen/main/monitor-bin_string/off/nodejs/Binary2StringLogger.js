'use strict';

const StateJS = require('@steelbreeze/state');
const EventEmitter = require('events').EventEmitter;
const Enum = require('./enums');
const Event = require('./events');


/*
 * Definition for type : Binary2StringLogger
 */

function Binary2StringLogger(name, root) {
	this.bus = (root === null)? new EventEmitter() : this.root.bus;
	this.name = name;
	this.root = (root === null)? this : root;
	this.ready = false;
	
	this.build(name);
}

Binary2StringLogger.prototype.build = function(session) {
	/*State machine (states and regions)*/
	/*Building root component*/
	this._statemachine = new StateJS.State('default_statemachine');
	let _initial_Logger = new StateJS.PseudoState('_initial', this._statemachine, StateJS.PseudoStateKind.Initial);
	let Logger_null_STARTUP = new StateJS.State('STARTUP', this._statemachine);
	let Logger_null_ON = new StateJS.State('ON', this._statemachine);
	let Logger_null_OFF = new StateJS.State('OFF', this._statemachine);
	_initial_Logger.to(Logger_null_STARTUP);
	Logger_null_STARTUP.to(Logger_null_ON).when(() => {
		return (this.Logger_ACTIVATE_ON_STARTUP_var);
	});
	Logger_null_STARTUP.to(Logger_null_OFF).when(() => {
		return (!(this.Logger_ACTIVATE_ON_STARTUP_var));
	});
	Logger_null_ON.on(Event.Log).when((log) => {
		return log.port === 'log' && log.type === 'log';
	}).effect((log) => {
		this.do_log(log.payload, log.size);
	});
	Logger_null_ON.to(Logger_null_OFF).on(Event.Log_off_LogMsgs).when((log_off) => {
		return log_off.port === 'log' && log_off.type === 'log_off';
	});
	Logger_null_OFF.to(Logger_null_ON).on(Event.Log_on_LogMsgs).when((log_on) => {
		return log_on.port === 'log' && log_on.type === 'log_on';
	});
}
Binary2StringLogger.prototype.get_byte = function(Binary2StringLogger_get_byte_b_var) {
	if(this.Logger_HAS_SIGNED_BYTE_var) {
	return (Binary2StringLogger_get_byte_b_var & 0xFF);
	
	} else {
	return Binary2StringLogger_get_byte_b_var;
	
	}
}

Binary2StringLogger.prototype.do_log = function(Binary2StringLogger_do_log_payload_var, Binary2StringLogger_do_log_size_var) {
	const log_type_var = this.get_byte(Binary2StringLogger_do_log_payload_var[0]);
	const inst_var = this.get_byte(Binary2StringLogger_do_log_payload_var[1]);
	if(log_type_var === Enum.LogType_ENUM.FUNCTION_CALLED) {
	const func__var = this.get_byte(Binary2StringLogger_do_log_payload_var[2]);
	if(inst_var === 0) {
	if(func__var === 1) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'function_called(BreakoutGame0, initColors, void'+', _'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(func__var === 2) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'function_called(BreakoutGame0, resetBall, void'+', _'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(func__var === 3) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'function_called(BreakoutGame0, eraseBall, void'+', _'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(func__var === 4) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'function_called(BreakoutGame0, drawBall, void'+', _'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(func__var === 5) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'function_called(BreakoutGame0, erasePad, void'+', _'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(func__var === 6) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'function_called(BreakoutGame0, drawPad, void'+', _'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(func__var === 7) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'function_called(BreakoutGame0, drawCountDown, void'+', _'+', c='+((this.get_byte(Binary2StringLogger_do_log_payload_var[2]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(func__var === 8) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'function_called(BreakoutGame0, drawWalls, void'+', _'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(func__var === 9) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'function_called(BreakoutGame0, bitIsSet, Boolean'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0) != 0)+', variable='+((this.get_byte(Binary2StringLogger_do_log_payload_var[2]) << 0))+', bit='+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(func__var === 10) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'function_called(BreakoutGame0, createBricks, void'+', _'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(func__var === 11) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'function_called(BreakoutGame0, bricksLeft, UInt8'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[2]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(func__var === 12) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'function_called(BreakoutGame0, drawBrick, void'+', _'+', x='+((this.get_byte(Binary2StringLogger_do_log_payload_var[2]) << 0))+', y='+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(func__var === 13) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'function_called(BreakoutGame0, removeBrick, void'+', _'+', x='+((this.get_byte(Binary2StringLogger_do_log_payload_var[2]) << 0))+', y='+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(func__var === 14) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'function_called(BreakoutGame0, collideBrick, Boolean'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 0) != 0)+', xpos='+((this.get_byte(Binary2StringLogger_do_log_payload_var[2]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 0))+', ypos='+((this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(func__var === 15) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'function_called(BreakoutGame0, drawLevel, void'+', _'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(func__var === 16) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'function_called(BreakoutGame0, incrementScore, void'+', _'+', diff='+((this.get_byte(Binary2StringLogger_do_log_payload_var[2]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(func__var === 17) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'function_called(BreakoutGame0, drawScore, void'+', _'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(func__var === 18) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'function_called(BreakoutGame0, drawLives, void'+', _'+')');
	if (process.stdout) process.stdout.write('\n');
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	} else {
	if(log_type_var === Enum.LogType_ENUM.PROPERTY_CHANGED) {
	const prop_var = this.get_byte(Binary2StringLogger_do_log_payload_var[2]);
	if(inst_var === 0) {
	if(prop_var === 0) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, XDISPSIZE, UInt8'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 1) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, YDISPSIZE, UInt8'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 2) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, SCALE, Int16'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 3) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, XMAX, Int16'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 4) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, YMAX, Int16'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 5) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, TOP, Int16'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 6) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, BOTTOM, Int16'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 7) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, LEFT, Int16'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 8) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, RIGHT, Int16'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 9) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, br, Int16'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 10) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, bx, Int16'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 11) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, by, Int16'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 12) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, dx, Int16'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 13) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, dy, Int16'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 14) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, padx, Int16'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 15) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, pady, Int16'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 16) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, padlen, Int16'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 17) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, prevBX, Int16'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 18) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, prevBY, Int16'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 19) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, bgcolor, UInt8'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 20) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, fgcolor, UInt8'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 21) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, period, UInt16'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 22) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, prevPX, Int16'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 23) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, prevPY, Int16'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 24) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, BRICK_ROWS, UInt8'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 25) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, BRICK_HEIGHT, UInt8'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 26) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, bricks, UInt8'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 27) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, score, Int16'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 28) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, lives, UInt8'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 29) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, level, UInt8'+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 0))+', '+((this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	} else {
	if(log_type_var === Enum.LogType_ENUM.MESSAGE_LOST) {
	const portID_var = this.get_byte(Binary2StringLogger_do_log_payload_var[2]);
	const messageID_var = this.get_byte(Binary2StringLogger_do_log_payload_var[3]);
	if(inst_var === 0) {
	if(portID_var === 0 && messageID_var === 21) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_lost(BreakoutGame0, clock, timer_timeout'+', id='+((this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 1 && messageID_var === 15) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_lost(BreakoutGame0, display, displayReady'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 2 && messageID_var === 17) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_lost(BreakoutGame0, controller, position'+', x='+((this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 0))+', y='+((this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[7]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 4 && messageID_var === 0) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_lost(BreakoutGame0, game, lostBall'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 6 && messageID_var === 0) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_lost(BreakoutGame0, pro_game, lostBall'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 4 && messageID_var === 1) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_lost(BreakoutGame0, game, nextLevel'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 6 && messageID_var === 1) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_lost(BreakoutGame0, pro_game, nextLevel'+')');
	if (process.stdout) process.stdout.write('\n');
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	} else {
	if(log_type_var === Enum.LogType_ENUM.MESSAGE_SENT) {
	const portID_var = this.get_byte(Binary2StringLogger_do_log_payload_var[2]);
	const messageID_var = this.get_byte(Binary2StringLogger_do_log_payload_var[3]);
	if(inst_var === 0) {
	if(portID_var === 0 && messageID_var === 19) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, clock, timer_start'+', id='+((this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', time='+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 0 && messageID_var === 20) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, clock, timer_cancel'+', id='+((this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 1 && messageID_var === 5) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, display, clear'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 1 && messageID_var === 6) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, display, setColor'+', r='+((this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', g='+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 0))+', b='+((this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 1 && messageID_var === 7) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, display, setBGColor'+', r='+((this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', g='+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 0))+', b='+((this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 1 && messageID_var === 8) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, display, drawRect'+', x='+((this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', y='+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 0))+', width='+((this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 0))+', height='+((this.get_byte(Binary2StringLogger_do_log_payload_var[7]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 1 && messageID_var === 9) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, display, fillRect'+', x='+((this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', y='+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 0))+', width='+((this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 0))+', height='+((this.get_byte(Binary2StringLogger_do_log_payload_var[7]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 1 && messageID_var === 10) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, display, drawInteger'+', x='+((this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', y='+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 0))+', v='+((this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[7]) << 0))+', digits='+((this.get_byte(Binary2StringLogger_do_log_payload_var[8]) << 0))+', scale='+((this.get_byte(Binary2StringLogger_do_log_payload_var[9]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 1 && messageID_var === 11) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, display, drawThingML'+', x='+((this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', y='+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 1 && messageID_var === 12) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, display, create'+', xsize='+((this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', ysize='+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 1 && messageID_var === 14) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, display, update'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 3 && messageID_var === 18) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, ia, updateIA'+', ballx='+((this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 0))+', bally='+((this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[7]) << 0))+', padx='+((this.get_byte(Binary2StringLogger_do_log_payload_var[8]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[9]) << 0))+', pady='+((this.get_byte(Binary2StringLogger_do_log_payload_var[10]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[11]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 4 && messageID_var === 0) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, game, lostBall'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 5 && messageID_var === 0) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, req_game, lostBall'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 4 && messageID_var === 1) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, game, nextLevel'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 5 && messageID_var === 1) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, req_game, nextLevel'+')');
	if (process.stdout) process.stdout.write('\n');
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	} else {
	if(log_type_var === Enum.LogType_ENUM.MESSAGE_HANDLED) {
	const handlerID_var = this.get_byte(Binary2StringLogger_do_log_payload_var[2]);
	if(inst_var === 0) {
	if(handlerID_var === 0) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_handled(BreakoutGame0, controller, position, SC, _, '+', x='+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[4]) << 0))+', y='+((this.get_byte(Binary2StringLogger_do_log_payload_var[5]) << 8 | this.get_byte(Binary2StringLogger_do_log_payload_var[6]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(handlerID_var === 1) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_handled(BreakoutGame0, display, displayReady, INIT, LAUNCH, '+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(handlerID_var === 2) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_handled(BreakoutGame0, clock, timer_timeout, LAUNCH, _, '+', id='+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(handlerID_var === 3) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_handled(BreakoutGame0, clock, timer_timeout, LAUNCH, PLAY, '+', id='+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(handlerID_var === 4) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_handled(BreakoutGame0, clock, timer_timeout, PLAY, _, '+', id='+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(handlerID_var === 5) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_handled(BreakoutGame0, game, lostBall, PLAY, LOSTBALL, '+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(handlerID_var === 6) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_handled(BreakoutGame0, game, nextLevel, PLAY, NEXTLEVEL, '+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(handlerID_var === 7) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_handled(BreakoutGame0, pro_game, lostBall, PLAY, LOSTBALL, '+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(handlerID_var === 8) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_handled(BreakoutGame0, pro_game, nextLevel, PLAY, NEXTLEVEL, '+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(handlerID_var === 9) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_handled(BreakoutGame0, clock, timer_timeout, LOSTBALL, LAUNCH, '+', id='+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(handlerID_var === 10) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_handled(BreakoutGame0, clock, timer_timeout, LOSTBALL, GAMEOVER, '+', id='+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(handlerID_var === 11) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_handled(BreakoutGame0, clock, timer_timeout, NEXTLEVEL, LAUNCH, '+', id='+((this.get_byte(Binary2StringLogger_do_log_payload_var[3]) << 0))+')');
	if (process.stdout) process.stdout.write('\n');
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	}
	
	} else {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'unknown');
	if (process.stdout) process.stdout.write('\n');
	
	}
	
	}
	
	}
	
	}
	
	}
}

Binary2StringLogger.prototype._stop = function() {
	this.root = null;
	this.ready = false;
	this.stopped = true;
}

Binary2StringLogger.prototype._delete = function() {
	this._statemachine = null;
	this._null_instance = null;
	this.bus.removeAllListeners();
}

Binary2StringLogger.prototype._init = function() {
	this._null_instance = new StateJS.Instance("null_instance", this._statemachine);
	this.ready = true;
}

Binary2StringLogger.prototype._receive = function(msg) {
	if (this.ready) {
		this._null_instance.evaluate(msg);
	} else if (!this.stopped) {
		setTimeout(()=>this._receive(msg),4);
	}
}

Binary2StringLogger.prototype.toString = function() {
	let result = 'instance ' + this.name + ':' + this.constructor.name + '\n';
	result += '\n\tACTIVATE_ON_STARTUP = ' + this.Logger_ACTIVATE_ON_STARTUP_var;
	result += '\n\tHAS_SIGNED_BYTE = ' + this.Logger_HAS_SIGNED_BYTE_var;
	result += '';
	return result;
}

module.exports = Binary2StringLogger;
