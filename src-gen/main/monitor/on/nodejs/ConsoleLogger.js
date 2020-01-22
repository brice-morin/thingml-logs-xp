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
	Logger_null_ON.on(Event.Function_called).when((function_called) => {
		return function_called.port === 'log' && function_called.type === 'function_called';
	}).effect((function_called) => {
		this.log_function_called(function_called.inst, function_called.fn_name, function_called.ty, function_called.returns, function_called.params);
	});
	Logger_null_ON.on(Event.Property_changed).when((property_changed) => {
		return property_changed.port === 'log' && property_changed.type === 'property_changed';
	}).effect((property_changed) => {
		this.log_property_changed(property_changed.inst, property_changed.prop_name, property_changed.ty, property_changed.old_value, property_changed.new_value);
	});
	Logger_null_OFF.to(Logger_null_ON).on(Event.Log_on_LogMsgs).when((log_on) => {
		return log_on.port === 'log' && log_on.type === 'log_on';
	});
	Logger_null_ON.on(Event.Message_lost).when((message_lost) => {
		return message_lost.port === 'log' && message_lost.type === 'message_lost';
	}).effect((message_lost) => {
		this.log_message_lost(message_lost.inst, message_lost.port_name, message_lost.msg_name, message_lost.params);
	});
	Logger_null_ON.to(Logger_null_OFF).on(Event.Log_off_LogMsgs).when((log_off) => {
		return log_off.port === 'log' && log_off.type === 'log_off';
	});
	Logger_null_ON.on(Event.Message_handled).when((message_handled) => {
		return message_handled.port === 'log' && message_handled.type === 'message_handled';
	}).effect((message_handled) => {
		this.log_message_handled(message_handled.inst, message_handled.source, message_handled.target, message_handled.port_name, message_handled.msg_name, message_handled.params);
	});
	Logger_null_ON.on(Event.Message_sent).when((message_sent) => {
		return message_sent.port === 'log' && message_sent.type === 'message_sent';
	}).effect((message_sent) => {
		this.log_message_sent(message_sent.inst, message_sent.port_name, message_sent.msg_name, message_sent.params);
	});
}
ConsoleLogger.prototype.log_function_called = function(ConsoleLogger_log_function_called_inst_var, ConsoleLogger_log_function_called_fn_name_var, ConsoleLogger_log_function_called_ty_var, ConsoleLogger_log_function_called_returns_var, ConsoleLogger_log_function_called_params_var) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'function_called('+ConsoleLogger_log_function_called_inst_var+', '+ConsoleLogger_log_function_called_fn_name_var+', '+ConsoleLogger_log_function_called_ty_var+', '+ConsoleLogger_log_function_called_returns_var+', '+ConsoleLogger_log_function_called_params_var+')');
	if (process.stdout) process.stdout.write('\n');
}

ConsoleLogger.prototype.log_property_changed = function(ConsoleLogger_log_property_changed_inst_var, ConsoleLogger_log_property_changed_prop_name_var, ConsoleLogger_log_property_changed_ty_var, ConsoleLogger_log_property_changed_old_value_var, ConsoleLogger_log_property_changed_new_value_var) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'property_changed('+ConsoleLogger_log_property_changed_inst_var+', '+ConsoleLogger_log_property_changed_prop_name_var+', '+ConsoleLogger_log_property_changed_ty_var+', '+ConsoleLogger_log_property_changed_old_value_var+', '+ConsoleLogger_log_property_changed_new_value_var+')');
	if (process.stdout) process.stdout.write('\n');
}

ConsoleLogger.prototype.log_message_lost = function(ConsoleLogger_log_message_lost_inst_var, ConsoleLogger_log_message_lost_port_name_var, ConsoleLogger_log_message_lost_msg_name_var, ConsoleLogger_log_message_lost_params_var) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_lost('+ConsoleLogger_log_message_lost_inst_var+', '+ConsoleLogger_log_message_lost_port_name_var+', '+ConsoleLogger_log_message_lost_msg_name_var+', '+ConsoleLogger_log_message_lost_params_var+')');
	if (process.stdout) process.stdout.write('\n');
}

ConsoleLogger.prototype.log_message_sent = function(ConsoleLogger_log_message_sent_inst_var, ConsoleLogger_log_message_sent_port_name_var, ConsoleLogger_log_message_sent_msg_name_var, ConsoleLogger_log_message_sent_params_var) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_sent('+ConsoleLogger_log_message_sent_inst_var+', '+ConsoleLogger_log_message_sent_port_name_var+', '+ConsoleLogger_log_message_sent_msg_name_var+', '+ConsoleLogger_log_message_sent_params_var+')');
	if (process.stdout) process.stdout.write('\n');
}

ConsoleLogger.prototype.log_message_handled = function(ConsoleLogger_log_message_handled_inst_var, ConsoleLogger_log_message_handled_source_var, ConsoleLogger_log_message_handled_target_var, ConsoleLogger_log_message_handled_port_name_var, ConsoleLogger_log_message_handled_msg_name_var, ConsoleLogger_log_message_handled_params_var) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'message_handled('+ConsoleLogger_log_message_handled_inst_var+', '+ConsoleLogger_log_message_handled_source_var+', '+ConsoleLogger_log_message_handled_target_var+', '+ConsoleLogger_log_message_handled_port_name_var+', '+ConsoleLogger_log_message_handled_msg_name_var+', '+ConsoleLogger_log_message_handled_params_var+')');
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
	result += '';
	return result;
}

module.exports = ConsoleLogger;
