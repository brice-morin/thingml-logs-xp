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
	Logger_null_OFF.to(Logger_null_ON).on(Event.Log_on_LogMsgs).when((log_on) => {
		return log_on.port === 'log' && log_on.type === 'log_on';
	});
	Logger_null_ON.to(Logger_null_OFF).on(Event.Log_off_LogMsgs).when((log_off) => {
		return log_off.port === 'log' && log_off.type === 'log_off';
	});
	Logger_null_ON.on(Event.Log).when((log) => {
		return log.port === 'log' && log.type === 'log';
	}).effect((log) => {
		this.do_log(log.payload, log.size);
	});
}
Binary2StringLogger.prototype.get_byte = function(Binary2StringLogger_get_byte_b_var) {
	if(this.Logger_HAS_SIGNED_BYTE_var) {
	return (Binary2StringLogger_get_byte_b_var & 0xFF);
	
	} else {
	return Binary2StringLogger_get_byte_b_var;
	
	}
}

Binary2StringLogger.prototype.stateName = function(Binary2StringLogger_stateName_id_var) {
	if(Binary2StringLogger_stateName_id_var === 0) {
	return 'BreakoutGame.SC';
	
	} else {
	if(Binary2StringLogger_stateName_id_var === 1) {
	return 'BreakoutGame.SC.INIT';
	
	} else {
	if(Binary2StringLogger_stateName_id_var === 2) {
	return 'BreakoutGame.SC.LAUNCH';
	
	} else {
	if(Binary2StringLogger_stateName_id_var === 3) {
	return 'BreakoutGame.SC.PLAY';
	
	} else {
	if(Binary2StringLogger_stateName_id_var === 4) {
	return 'BreakoutGame.SC.LOSTBALL';
	
	} else {
	if(Binary2StringLogger_stateName_id_var === 5) {
	return 'BreakoutGame.SC.NEXTLEVEL';
	
	} else {
	if(Binary2StringLogger_stateName_id_var === 6) {
	return 'BreakoutGame.SC.GAMEOVER';
	
	} else {
	if(Binary2StringLogger_stateName_id_var === 7) {
	return 'Logger';
	
	} else {
	if(Binary2StringLogger_stateName_id_var === 8) {
	return 'Logger.null.STARTUP';
	
	} else {
	if(Binary2StringLogger_stateName_id_var === 9) {
	return 'Logger.null.ON';
	
	} else {
	if(Binary2StringLogger_stateName_id_var === 10) {
	return 'Logger.null.OFF';
	
	} else {
	if(Binary2StringLogger_stateName_id_var === 11) {
	return 'HeadlessDisplay';
	
	} else {
	if(Binary2StringLogger_stateName_id_var === 12) {
	return 'HeadlessDisplay.null.INIT';
	
	} else {
	if(Binary2StringLogger_stateName_id_var === 13) {
	return 'HeadlessDisplay.null.MOCK';
	
	} else {
	if(Binary2StringLogger_stateName_id_var === 14) {
	return 'BasicIAController.SC';
	
	} else {
	if(Binary2StringLogger_stateName_id_var === 15) {
	return 'BasicIAController.SC.Following';
	
	} else {
	if(Binary2StringLogger_stateName_id_var === 16) {
	return 'TimerJava.SoftTimer';
	
	} else {
	if(Binary2StringLogger_stateName_id_var === 17) {
	return 'TimerJava.SoftTimer.default';
	
	} else {
	if(Binary2StringLogger_stateName_id_var === 18) {
	return 'TimerJS.SoftTimer';
	
	} else {
	if(Binary2StringLogger_stateName_id_var === 19) {
	return 'TimerJS.SoftTimer.default';
	
	} else {
	if(Binary2StringLogger_stateName_id_var === 20) {
	return 'TimerNodeJS.SoftTimer';
	
	} else {
	if(Binary2StringLogger_stateName_id_var === 21) {
	return 'TimerNodeJS.SoftTimer.default';
	
	} else {
	if(Binary2StringLogger_stateName_id_var === 22) {
	return 'TimerPosix.SoftTimer';
	
	} else {
	if(Binary2StringLogger_stateName_id_var === 23) {
	return 'TimerPosix.SoftTimer.default';
	
	} else {
	if(Binary2StringLogger_stateName_id_var === 24) {
	return 'TimerArduino.SoftTimer';
	
	} else {
	if(Binary2StringLogger_stateName_id_var === 25) {
	return 'TimerArduino.SoftTimer.default';
	
	} else {
	if(Binary2StringLogger_stateName_id_var === 26) {
	return 'TimerGo.SoftTimer';
	
	} else {
	if(Binary2StringLogger_stateName_id_var === 27) {
	return 'TimerGo.SoftTimer.default';
	
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
	return 'unknown';
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
	const bin_c_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 1])];
	let c_var = (bin_c_var[0] << 8 | bin_c_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	c_var = c_var + 256;
	
	}
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'function_called(BreakoutGame0, drawCountDown, void'+', _'+', c='+c_var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(func__var === 8) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'function_called(BreakoutGame0, drawWalls, void'+', _'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(func__var === 9) {
	const bin_result_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[Binary2StringLogger_do_log_size_var - 1 + 0])];
	let result_var = (bin_result_var[0] << 0) != 0;
	const bin_variable_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0])];
	let variable_var = (bin_variable_var[0] << 0);
	const bin_bit_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[4 + 0])];
	let bit_var = (bin_bit_var[0] << 0);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'function_called(BreakoutGame0, bitIsSet, Boolean'+', '+result_var+', variable='+variable_var+', bit='+bit_var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(func__var === 10) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'function_called(BreakoutGame0, createBricks, void'+', _'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(func__var === 11) {
	const bin_result_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[Binary2StringLogger_do_log_size_var - 1 + 0])];
	let result_var = (bin_result_var[0] << 0);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'function_called(BreakoutGame0, bricksLeft, UInt8'+', '+result_var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(func__var === 12) {
	const bin_x_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0])];
	let x_var = (bin_x_var[0] << 0);
	const bin_y_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[4 + 0])];
	let y_var = (bin_y_var[0] << 0);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'function_called(BreakoutGame0, drawBrick, void'+', _'+', x='+x_var+', y='+y_var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(func__var === 13) {
	const bin_x_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0])];
	let x_var = (bin_x_var[0] << 0);
	const bin_y_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[4 + 0])];
	let y_var = (bin_y_var[0] << 0);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'function_called(BreakoutGame0, removeBrick, void'+', _'+', x='+x_var+', y='+y_var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(func__var === 14) {
	const bin_result_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[Binary2StringLogger_do_log_size_var - 1 + 0])];
	let result_var = (bin_result_var[0] << 0) != 0;
	const bin_xpos_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 1])];
	let xpos_var = (bin_xpos_var[0] << 8 | bin_xpos_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	xpos_var = xpos_var + 256;
	
	}
	const bin_ypos_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 1])];
	let ypos_var = (bin_ypos_var[0] << 8 | bin_ypos_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	ypos_var = ypos_var + 256;
	
	}
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'function_called(BreakoutGame0, collideBrick, Boolean'+', '+result_var+', xpos='+xpos_var+', ypos='+ypos_var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(func__var === 15) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'function_called(BreakoutGame0, drawLevel, void'+', _'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(func__var === 16) {
	const bin_diff_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0])];
	let diff_var = (bin_diff_var[0] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	diff_var = diff_var + 1;
	
	}
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'function_called(BreakoutGame0, incrementScore, void'+', _'+', diff='+diff_var+')');
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
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0])];
	let old_var = (bin_old_var[0] << 0);
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[4 + 0])];
	let new__var = (bin_new__var[0] << 0);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, XDISPSIZE, UInt8'+', '+old_var+', '+new__var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 1) {
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0])];
	let old_var = (bin_old_var[0] << 0);
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[4 + 0])];
	let new__var = (bin_new__var[0] << 0);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, YDISPSIZE, UInt8'+', '+old_var+', '+new__var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 2) {
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 1])];
	let old_var = (bin_old_var[0] << 8 | bin_old_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	old_var = old_var + 256;
	
	}
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 1])];
	let new__var = (bin_new__var[0] << 8 | bin_new__var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	new__var = new__var + 256;
	
	}
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, SCALE, Int16'+', '+old_var+', '+new__var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 3) {
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 1])];
	let old_var = (bin_old_var[0] << 8 | bin_old_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	old_var = old_var + 256;
	
	}
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 1])];
	let new__var = (bin_new__var[0] << 8 | bin_new__var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	new__var = new__var + 256;
	
	}
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, XMAX, Int16'+', '+old_var+', '+new__var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 4) {
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 1])];
	let old_var = (bin_old_var[0] << 8 | bin_old_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	old_var = old_var + 256;
	
	}
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 1])];
	let new__var = (bin_new__var[0] << 8 | bin_new__var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	new__var = new__var + 256;
	
	}
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, YMAX, Int16'+', '+old_var+', '+new__var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 5) {
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 1])];
	let old_var = (bin_old_var[0] << 8 | bin_old_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	old_var = old_var + 256;
	
	}
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 1])];
	let new__var = (bin_new__var[0] << 8 | bin_new__var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	new__var = new__var + 256;
	
	}
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, TOP, Int16'+', '+old_var+', '+new__var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 6) {
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 1])];
	let old_var = (bin_old_var[0] << 8 | bin_old_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	old_var = old_var + 256;
	
	}
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 1])];
	let new__var = (bin_new__var[0] << 8 | bin_new__var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	new__var = new__var + 256;
	
	}
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, BOTTOM, Int16'+', '+old_var+', '+new__var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 7) {
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 1])];
	let old_var = (bin_old_var[0] << 8 | bin_old_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	old_var = old_var + 256;
	
	}
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 1])];
	let new__var = (bin_new__var[0] << 8 | bin_new__var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	new__var = new__var + 256;
	
	}
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, LEFT, Int16'+', '+old_var+', '+new__var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 8) {
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 1])];
	let old_var = (bin_old_var[0] << 8 | bin_old_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	old_var = old_var + 256;
	
	}
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 1])];
	let new__var = (bin_new__var[0] << 8 | bin_new__var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	new__var = new__var + 256;
	
	}
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, RIGHT, Int16'+', '+old_var+', '+new__var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 9) {
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 1])];
	let old_var = (bin_old_var[0] << 8 | bin_old_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	old_var = old_var + 256;
	
	}
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 1])];
	let new__var = (bin_new__var[0] << 8 | bin_new__var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	new__var = new__var + 256;
	
	}
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, br, Int16'+', '+old_var+', '+new__var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 10) {
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 1])];
	let old_var = (bin_old_var[0] << 8 | bin_old_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	old_var = old_var + 256;
	
	}
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 1])];
	let new__var = (bin_new__var[0] << 8 | bin_new__var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	new__var = new__var + 256;
	
	}
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, bx, Int16'+', '+old_var+', '+new__var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 11) {
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 1])];
	let old_var = (bin_old_var[0] << 8 | bin_old_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	old_var = old_var + 256;
	
	}
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 1])];
	let new__var = (bin_new__var[0] << 8 | bin_new__var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	new__var = new__var + 256;
	
	}
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, by, Int16'+', '+old_var+', '+new__var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 12) {
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 1])];
	let old_var = (bin_old_var[0] << 8 | bin_old_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	old_var = old_var + 256;
	
	}
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 1])];
	let new__var = (bin_new__var[0] << 8 | bin_new__var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	new__var = new__var + 256;
	
	}
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, dx, Int16'+', '+old_var+', '+new__var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 13) {
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 1])];
	let old_var = (bin_old_var[0] << 8 | bin_old_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	old_var = old_var + 256;
	
	}
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 1])];
	let new__var = (bin_new__var[0] << 8 | bin_new__var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	new__var = new__var + 256;
	
	}
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, dy, Int16'+', '+old_var+', '+new__var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 14) {
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 1])];
	let old_var = (bin_old_var[0] << 8 | bin_old_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	old_var = old_var + 256;
	
	}
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 1])];
	let new__var = (bin_new__var[0] << 8 | bin_new__var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	new__var = new__var + 256;
	
	}
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, padx, Int16'+', '+old_var+', '+new__var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 15) {
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 1])];
	let old_var = (bin_old_var[0] << 8 | bin_old_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	old_var = old_var + 256;
	
	}
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 1])];
	let new__var = (bin_new__var[0] << 8 | bin_new__var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	new__var = new__var + 256;
	
	}
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, pady, Int16'+', '+old_var+', '+new__var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 16) {
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 1])];
	let old_var = (bin_old_var[0] << 8 | bin_old_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	old_var = old_var + 256;
	
	}
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 1])];
	let new__var = (bin_new__var[0] << 8 | bin_new__var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	new__var = new__var + 256;
	
	}
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, padlen, Int16'+', '+old_var+', '+new__var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 17) {
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 1])];
	let old_var = (bin_old_var[0] << 8 | bin_old_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	old_var = old_var + 256;
	
	}
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 1])];
	let new__var = (bin_new__var[0] << 8 | bin_new__var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	new__var = new__var + 256;
	
	}
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, prevBX, Int16'+', '+old_var+', '+new__var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 18) {
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 1])];
	let old_var = (bin_old_var[0] << 8 | bin_old_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	old_var = old_var + 256;
	
	}
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 1])];
	let new__var = (bin_new__var[0] << 8 | bin_new__var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	new__var = new__var + 256;
	
	}
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, prevBY, Int16'+', '+old_var+', '+new__var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 19) {
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0])];
	let old_var = (bin_old_var[0] << 0);
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[4 + 0])];
	let new__var = (bin_new__var[0] << 0);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, bgcolor, UInt8'+', '+old_var+', '+new__var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 20) {
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0])];
	let old_var = (bin_old_var[0] << 0);
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[4 + 0])];
	let new__var = (bin_new__var[0] << 0);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, fgcolor, UInt8'+', '+old_var+', '+new__var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 21) {
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 1])];
	let old_var = (bin_old_var[0] << 8 | bin_old_var[1] << 0);
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 1])];
	let new__var = (bin_new__var[0] << 8 | bin_new__var[1] << 0);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, period, UInt16'+', '+old_var+', '+new__var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 22) {
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 1])];
	let old_var = (bin_old_var[0] << 8 | bin_old_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	old_var = old_var + 256;
	
	}
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 1])];
	let new__var = (bin_new__var[0] << 8 | bin_new__var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	new__var = new__var + 256;
	
	}
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, prevPX, Int16'+', '+old_var+', '+new__var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 23) {
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 1])];
	let old_var = (bin_old_var[0] << 8 | bin_old_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	old_var = old_var + 256;
	
	}
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 1])];
	let new__var = (bin_new__var[0] << 8 | bin_new__var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	new__var = new__var + 256;
	
	}
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, prevPY, Int16'+', '+old_var+', '+new__var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 24) {
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0])];
	let old_var = (bin_old_var[0] << 0);
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[4 + 0])];
	let new__var = (bin_new__var[0] << 0);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, BRICK_ROWS, UInt8'+', '+old_var+', '+new__var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 25) {
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0])];
	let old_var = (bin_old_var[0] << 0);
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[4 + 0])];
	let new__var = (bin_new__var[0] << 0);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, BRICK_HEIGHT, UInt8'+', '+old_var+', '+new__var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 26) {
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0])];
	let old_var = (bin_old_var[0] << 0);
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[4 + 0])];
	let new__var = (bin_new__var[0] << 0);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, bricks, UInt8'+', '+old_var+', '+new__var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 27) {
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 1])];
	let old_var = (bin_old_var[0] << 8 | bin_old_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	old_var = old_var + 256;
	
	}
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 1])];
	let new__var = (bin_new__var[0] << 8 | bin_new__var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	new__var = new__var + 256;
	
	}
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, score, Int16'+', '+old_var+', '+new__var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 28) {
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0])];
	let old_var = (bin_old_var[0] << 0);
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[4 + 0])];
	let new__var = (bin_new__var[0] << 0);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, lives, UInt8'+', '+old_var+', '+new__var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(prop_var === 29) {
	const bin_old_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[3 + 0])];
	let old_var = (bin_old_var[0] << 0);
	const bin_new__var = [this.get_byte(Binary2StringLogger_do_log_payload_var[4 + 0])];
	let new__var = (bin_new__var[0] << 0);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed(BreakoutGame0, level, UInt8'+', '+old_var+', '+new__var+')');
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
	if(portID_var === 1 && messageID_var === 22) {
	const bin_id_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[4 + 0])];
	let id_var = (bin_id_var[0] << 0);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_lost(BreakoutGame0, clock, timer_timeout'+', id='+id_var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 2 && messageID_var === 16) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_lost(BreakoutGame0, display, displayReady'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 3 && messageID_var === 18) {
	const bin_x_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[4 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[4 + 1])];
	let x_var = (bin_x_var[0] << 8 | bin_x_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	x_var = x_var + 256;
	
	}
	const bin_y_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[6 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[6 + 1])];
	let y_var = (bin_y_var[0] << 8 | bin_y_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	y_var = y_var + 256;
	
	}
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_lost(BreakoutGame0, controller, position'+', x='+x_var+', y='+y_var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 5 && messageID_var === 1) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_lost(BreakoutGame0, game, lostBall'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 7 && messageID_var === 1) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_lost(BreakoutGame0, pro_game, lostBall'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 5 && messageID_var === 2) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_lost(BreakoutGame0, game, nextLevel'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 7 && messageID_var === 2) {
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
	if(portID_var === 1 && messageID_var === 20) {
	const bin_id_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[4 + 0])];
	let id_var = (bin_id_var[0] << 0);
	const bin_time_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 1])];
	let time_var = (bin_time_var[0] << 8 | bin_time_var[1] << 0);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, clock, timer_start'+', id='+id_var+', time='+time_var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 1 && messageID_var === 21) {
	const bin_id_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[4 + 0])];
	let id_var = (bin_id_var[0] << 0);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, clock, timer_cancel'+', id='+id_var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 2 && messageID_var === 6) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, display, clear'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 2 && messageID_var === 7) {
	const bin_r_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[4 + 0])];
	let r_var = (bin_r_var[0] << 0);
	const bin_g_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0])];
	let g_var = (bin_g_var[0] << 0);
	const bin_b_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[6 + 0])];
	let b_var = (bin_b_var[0] << 0);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, display, setColor'+', r='+r_var+', g='+g_var+', b='+b_var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 2 && messageID_var === 8) {
	const bin_r_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[4 + 0])];
	let r_var = (bin_r_var[0] << 0);
	const bin_g_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0])];
	let g_var = (bin_g_var[0] << 0);
	const bin_b_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[6 + 0])];
	let b_var = (bin_b_var[0] << 0);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, display, setBGColor'+', r='+r_var+', g='+g_var+', b='+b_var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 2 && messageID_var === 9) {
	const bin_x_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[4 + 0])];
	let x_var = (bin_x_var[0] << 0);
	const bin_y_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0])];
	let y_var = (bin_y_var[0] << 0);
	const bin_width_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[6 + 0])];
	let width_var = (bin_width_var[0] << 0);
	const bin_height_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[7 + 0])];
	let height_var = (bin_height_var[0] << 0);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, display, drawRect'+', x='+x_var+', y='+y_var+', width='+width_var+', height='+height_var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 2 && messageID_var === 10) {
	const bin_x_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[4 + 0])];
	let x_var = (bin_x_var[0] << 0);
	const bin_y_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0])];
	let y_var = (bin_y_var[0] << 0);
	const bin_width_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[6 + 0])];
	let width_var = (bin_width_var[0] << 0);
	const bin_height_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[7 + 0])];
	let height_var = (bin_height_var[0] << 0);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, display, fillRect'+', x='+x_var+', y='+y_var+', width='+width_var+', height='+height_var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 2 && messageID_var === 11) {
	const bin_x_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[4 + 0])];
	let x_var = (bin_x_var[0] << 0);
	const bin_y_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0])];
	let y_var = (bin_y_var[0] << 0);
	const bin_v_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[6 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[6 + 1])];
	let v_var = (bin_v_var[0] << 8 | bin_v_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	v_var = v_var + 256;
	
	}
	const bin_digits_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[8 + 0])];
	let digits_var = (bin_digits_var[0] << 0);
	const bin_scale_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[9 + 0])];
	let scale_var = (bin_scale_var[0] << 0);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, display, drawInteger'+', x='+x_var+', y='+y_var+', v='+v_var+', digits='+digits_var+', scale='+scale_var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 2 && messageID_var === 12) {
	const bin_x_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[4 + 0])];
	let x_var = (bin_x_var[0] << 0);
	const bin_y_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0])];
	let y_var = (bin_y_var[0] << 0);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, display, drawThingML'+', x='+x_var+', y='+y_var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 2 && messageID_var === 13) {
	const bin_xsize_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[4 + 0])];
	let xsize_var = (bin_xsize_var[0] << 0);
	const bin_ysize_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[5 + 0])];
	let ysize_var = (bin_ysize_var[0] << 0);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, display, create'+', xsize='+xsize_var+', ysize='+ysize_var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 2 && messageID_var === 15) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, display, update'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 4 && messageID_var === 19) {
	const bin_ballx_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[4 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[4 + 1])];
	let ballx_var = (bin_ballx_var[0] << 8 | bin_ballx_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	ballx_var = ballx_var + 256;
	
	}
	const bin_bally_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[6 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[6 + 1])];
	let bally_var = (bin_bally_var[0] << 8 | bin_bally_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	bally_var = bally_var + 256;
	
	}
	const bin_padx_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[8 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[8 + 1])];
	let padx_var = (bin_padx_var[0] << 8 | bin_padx_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	padx_var = padx_var + 256;
	
	}
	const bin_pady_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[10 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[10 + 1])];
	let pady_var = (bin_pady_var[0] << 8 | bin_pady_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	pady_var = pady_var + 256;
	
	}
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, ia, updateIA'+', ballx='+ballx_var+', bally='+bally_var+', padx='+padx_var+', pady='+pady_var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 5 && messageID_var === 1) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, game, lostBall'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 6 && messageID_var === 1) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, req_game, lostBall'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 5 && messageID_var === 2) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent(BreakoutGame0, game, nextLevel'+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 6 && messageID_var === 2) {
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
	const portID_var = this.get_byte(Binary2StringLogger_do_log_payload_var[2]);
	const messageID_var = this.get_byte(Binary2StringLogger_do_log_payload_var[3]);
	const sourceID_var = this.get_byte(Binary2StringLogger_do_log_payload_var[4]);
	const targetID_var = this.get_byte(Binary2StringLogger_do_log_payload_var[5]);
	if(inst_var === 0) {
	if(portID_var === 1 && messageID_var === 22) {
	const bin_id_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[6 + 0])];
	let id_var = (bin_id_var[0] << 0);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_handled(BreakoutGame0, clock, timer_timeout, '+this.stateName(sourceID_var)+', '+this.stateName(targetID_var)+', id='+id_var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 2 && messageID_var === 16) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_handled(BreakoutGame0, display, displayReady, '+this.stateName(sourceID_var)+', '+this.stateName(targetID_var)+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 3 && messageID_var === 18) {
	const bin_x_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[6 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[6 + 1])];
	let x_var = (bin_x_var[0] << 8 | bin_x_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	x_var = x_var + 256;
	
	}
	const bin_y_var = [this.get_byte(Binary2StringLogger_do_log_payload_var[8 + 0]), this.get_byte(Binary2StringLogger_do_log_payload_var[8 + 1])];
	let y_var = (bin_y_var[0] << 8 | bin_y_var[1] << 0);
	if( !(this.Logger_HAS_SIGNED_BYTE_var)) {
	y_var = y_var + 256;
	
	}
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_handled(BreakoutGame0, controller, position, '+this.stateName(sourceID_var)+', '+this.stateName(targetID_var)+', x='+x_var+', y='+y_var+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 5 && messageID_var === 1) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_handled(BreakoutGame0, game, lostBall, '+this.stateName(sourceID_var)+', '+this.stateName(targetID_var)+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 7 && messageID_var === 1) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_handled(BreakoutGame0, pro_game, lostBall, '+this.stateName(sourceID_var)+', '+this.stateName(targetID_var)+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 5 && messageID_var === 2) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_handled(BreakoutGame0, game, nextLevel, '+this.stateName(sourceID_var)+', '+this.stateName(targetID_var)+')');
	if (process.stdout) process.stdout.write('\n');
	
	} else {
	if(portID_var === 7 && messageID_var === 2) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_handled(BreakoutGame0, pro_game, nextLevel, '+this.stateName(sourceID_var)+', '+this.stateName(targetID_var)+')');
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
