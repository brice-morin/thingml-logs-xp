'use strict';

const StateJS = require('@steelbreeze/state');
const EventEmitter = require('events').EventEmitter;
const Enum = require('./enums');
const Event = require('./events');


/*
 * Definition for type : ConsoleLogger
 */

function ConsoleLogger(name, root) {
	this.bus = (root === null)? new EventEmitter() : this.root.bus;
	this.name = name;
	this.root = (root === null)? this : root;
	this.ready = false;
	
	this.build(name);
}

ConsoleLogger.prototype.build = function(session) {
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
ConsoleLogger.prototype.do_log = function(ConsoleLogger_do_log_payload_var, ConsoleLogger_do_log_size_var) {
	let i_var = 0;
	while(i_var < ConsoleLogger_do_log_size_var) {
	if(this.Logger_HAS_SIGNED_BYTE_var) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+(ConsoleLogger_do_log_payload_var[i_var] & 0xFF));
	
	} else {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+ConsoleLogger_do_log_payload_var[i_var]);
	
	}
	i_var++;
	
	}
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'');
	if (process.stdout) process.stdout.write('\n');
}

ConsoleLogger.prototype._stop = function() {
	this.root = null;
	this.ready = false;
	this.stopped = true;
}

ConsoleLogger.prototype._delete = function() {
	this._statemachine = null;
	this._null_instance = null;
	this.bus.removeAllListeners();
}

ConsoleLogger.prototype._init = function() {
	this._null_instance = new StateJS.Instance("null_instance", this._statemachine);
	this.ready = true;
}

ConsoleLogger.prototype._receive = function(msg) {
	if (this.ready) {
		this._null_instance.evaluate(msg);
	} else if (!this.stopped) {
		setTimeout(()=>this._receive(msg),4);
	}
}

ConsoleLogger.prototype.toString = function() {
	let result = 'instance ' + this.name + ':' + this.constructor.name + '\n';
	result += '\n\tACTIVATE_ON_STARTUP = ' + this.Logger_ACTIVATE_ON_STARTUP_var;
	result += '\n\tHAS_SIGNED_BYTE = ' + this.Logger_HAS_SIGNED_BYTE_var;
	result += '';
	return result;
}

module.exports = ConsoleLogger;
