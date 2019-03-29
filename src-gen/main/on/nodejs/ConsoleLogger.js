'use strict';

const Enum = require('./enums');
const StateJS = require('@steelbreeze/state');
const EventEmitter = require('events').EventEmitter;


/*
 * Definition for type : ConsoleLogger
 */

function ConsoleLogger(name, root) {
	this.name = name;
	this.root = (root === null)? this : root;
	this.ready = false;
	this.bus = (root === null)? new EventEmitter() : this.root.bus;
	
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
	Logger_null_OFF.to(Logger_null_ON).when((log_on) => {
		return log_on._port === 'log' && log_on._msg === 'log_on';
	});
	Logger_null_ON.to(null).when((message_handled) => {
		return message_handled._port === 'log' && message_handled._msg === 'message_handled';
	}).effect((message_handled) => {
		this.log_message_handled(message_handled.inst, message_handled.source, message_handled.target, message_handled.port_name, message_handled.msg_name, message_handled.params);
	});
	Logger_null_ON.to(null).when((message_lost) => {
		return message_lost._port === 'log' && message_lost._msg === 'message_lost';
	}).effect((message_lost) => {
		this.log_message_lost(message_lost.inst, message_lost.port_name, message_lost.msg_name, message_lost.params);
	});
	Logger_null_ON.to(null).when((property_changed) => {
		return property_changed._port === 'log' && property_changed._msg === 'property_changed';
	}).effect((property_changed) => {
		this.log_property_changed(property_changed.inst, property_changed.prop_name, property_changed.ty, property_changed.old_value, property_changed.new_value);
	});
	Logger_null_ON.to(null).when((function_called) => {
		return function_called._port === 'log' && function_called._msg === 'function_called';
	}).effect((function_called) => {
		this.log_function_called(function_called.inst, function_called.fn_name, function_called.ty, function_called.returns, function_called.params);
	});
	Logger_null_ON.to(null).when((message_sent) => {
		return message_sent._port === 'log' && message_sent._msg === 'message_sent';
	}).effect((message_sent) => {
		this.log_message_sent(message_sent.inst, message_sent.port_name, message_sent.msg_name, message_sent.params);
	});
	Logger_null_ON.to(Logger_null_OFF).when((log_off) => {
		return log_off._port === 'log' && log_off._msg === 'log_off';
	});
}
ConsoleLogger.prototype.log_function_called = function(ConsoleLogger_log_function_called_inst_var, ConsoleLogger_log_function_called_fn_name_var, ConsoleLogger_log_function_called_ty_var, ConsoleLogger_log_function_called_returns_var, ConsoleLogger_log_function_called_params_var) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'log: function_called(');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+ConsoleLogger_log_function_called_inst_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+', ');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+ConsoleLogger_log_function_called_fn_name_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+', ');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+ConsoleLogger_log_function_called_ty_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+', ');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+ConsoleLogger_log_function_called_returns_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+', ');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+ConsoleLogger_log_function_called_params_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+')');
	if (process.stdout) process.stdout.write('\n');
}

ConsoleLogger.prototype.log_property_changed = function(ConsoleLogger_log_property_changed_inst_var, ConsoleLogger_log_property_changed_prop_name_var, ConsoleLogger_log_property_changed_ty_var, ConsoleLogger_log_property_changed_old_var, ConsoleLogger_log_property_changed_new_var) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'log: property_changed(');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+ConsoleLogger_log_property_changed_inst_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+', ');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+ConsoleLogger_log_property_changed_prop_name_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+', ');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+ConsoleLogger_log_property_changed_ty_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+', ');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+ConsoleLogger_log_property_changed_old_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+', ');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+ConsoleLogger_log_property_changed_new_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+')');
	if (process.stdout) process.stdout.write('\n');
}

ConsoleLogger.prototype.log_message_lost = function(ConsoleLogger_log_message_lost_inst_var, ConsoleLogger_log_message_lost_port_name_var, ConsoleLogger_log_message_lost_msg_name_var, ConsoleLogger_log_message_lost_params_var) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'log: message_lost(');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+ConsoleLogger_log_message_lost_inst_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+', ');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+ConsoleLogger_log_message_lost_port_name_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+', ');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+ConsoleLogger_log_message_lost_msg_name_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+', ');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+ConsoleLogger_log_message_lost_params_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+')');
	if (process.stdout) process.stdout.write('\n');
}

ConsoleLogger.prototype.log_message_sent = function(ConsoleLogger_log_message_sent_inst_var, ConsoleLogger_log_message_sent_port_name_var, ConsoleLogger_log_message_sent_msg_name_var, ConsoleLogger_log_message_sent_params_var) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'log: message_sent(');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+ConsoleLogger_log_message_sent_inst_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+', ');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+ConsoleLogger_log_message_sent_port_name_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+', ');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+ConsoleLogger_log_message_sent_msg_name_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+', ');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+ConsoleLogger_log_message_sent_params_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+')');
	if (process.stdout) process.stdout.write('\n');
}

ConsoleLogger.prototype.log_message_handled = function(ConsoleLogger_log_message_handled_inst_var, ConsoleLogger_log_message_handled_source_var, ConsoleLogger_log_message_handled_target_var, ConsoleLogger_log_message_handled_port_name_var, ConsoleLogger_log_message_handled_msg_name_var, ConsoleLogger_log_message_handled_params_var) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'log: message_handled(');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+ConsoleLogger_log_message_handled_inst_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+', ');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+ConsoleLogger_log_message_handled_source_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+', ');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+ConsoleLogger_log_message_handled_target_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+', ');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+ConsoleLogger_log_message_handled_port_name_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+', ');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+ConsoleLogger_log_message_handled_msg_name_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+', ');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+ConsoleLogger_log_message_handled_params_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+')');
	if (process.stdout) process.stdout.write('\n');
}

ConsoleLogger.prototype._stop = function() {
	this.root = null;
	this.ready = false;
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
	/*msg = {_port:myPort, _msg:myMessage, paramN=paramN, ...}*/
	if (this.ready) {
		this._null_instance.evaluate(msg);
	} else {
		setTimeout(()=>this._receive(msg),0);
	}
}

ConsoleLogger.prototype.receivefunction_calledOnlog = function(inst, fn_name, ty, returns, params) {
	this._receive({_port:"log", _msg:"function_called", inst:inst, fn_name:fn_name, ty:ty, returns:returns, params:params});
}

ConsoleLogger.prototype.receiveproperty_changedOnlog = function(inst, prop_name, ty, old_value, new_value) {
	this._receive({_port:"log", _msg:"property_changed", inst:inst, prop_name:prop_name, ty:ty, old_value:old_value, new_value:new_value});
}

ConsoleLogger.prototype.receivemessage_lostOnlog = function(inst, port_name, msg_name, params) {
	this._receive({_port:"log", _msg:"message_lost", inst:inst, port_name:port_name, msg_name:msg_name, params:params});
}

ConsoleLogger.prototype.receivemessage_handledOnlog = function(inst, source, target, port_name, msg_name, params) {
	this._receive({_port:"log", _msg:"message_handled", inst:inst, source:source, target:target, port_name:port_name, msg_name:msg_name, params:params});
}

ConsoleLogger.prototype.receivemessage_sentOnlog = function(inst, port_name, msg_name, params) {
	this._receive({_port:"log", _msg:"message_sent", inst:inst, port_name:port_name, msg_name:msg_name, params:params});
}

ConsoleLogger.prototype.receivelog_onOnlog = function() {
	this._receive({_port:"log", _msg:"log_on"});
}

ConsoleLogger.prototype.receivelog_offOnlog = function() {
	this._receive({_port:"log", _msg:"log_off"});
}

ConsoleLogger.prototype.initLogger_ACTIVATE_ON_STARTUP_var = function(Logger_ACTIVATE_ON_STARTUP_var) {
	this.Logger_ACTIVATE_ON_STARTUP_var = Logger_ACTIVATE_ON_STARTUP_var;
}

ConsoleLogger.prototype.toString = function() {
	let result = 'instance ' + this.name + ':' + this.constructor.name + '\n';
	result += '\n\tACTIVATE_ON_STARTUP = ' + this.Logger_ACTIVATE_ON_STARTUP_var;
	result += '';
	return result;
}

module.exports = ConsoleLogger;
