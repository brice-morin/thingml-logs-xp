'use strict';

const StateJS = require('@steelbreeze/state');
const EventEmitter = require('events').EventEmitter;
const Enum = require('./enums');
const Event = require('./events');


/*
 * Definition for type : TimerNodeJS
 */

function TimerNodeJS(name, root) {
	this.bus = (root === null)? new EventEmitter() : this.root.bus;
	this.name = name;
	this.root = (root === null)? this : root;
	this.ready = false;
	
	this.build(name);
}

TimerNodeJS.prototype.build = function(session) {
	/*State machine (states and regions)*/
	/*Building root component*/
	this._statemachine = new StateJS.State('SoftTimer');
	let _initial_TimerNodeJS_SoftTimer = new StateJS.PseudoState('_initial', this._statemachine, StateJS.PseudoStateKind.Initial);
	let TimerNodeJS_SoftTimer_default = new StateJS.State('default', this._statemachine);
	_initial_TimerNodeJS_SoftTimer.to(TimerNodeJS_SoftTimer_default);
	TimerNodeJS_SoftTimer_default.on(Event.Timer_start).when((timer_start) => {
		return timer_start.port === 'timer' && timer_start.type === 'timer_start' && (timer_start.time > 0);
	}).effect((timer_start) => {
		this.startTimer(timer_start.id, timer_start.time);
	});
	TimerNodeJS_SoftTimer_default.on(Event.Timer_start).when((timer_start) => {
		return timer_start.port === 'timer' && timer_start.type === 'timer_start' && (timer_start.time === 0);
	}).effect((timer_start) => {
		this.bus.emit('timer', new Event.Timer_timeout_TimerMsgs(this.name, 'timer', timer_start.id));
	});
	TimerNodeJS_SoftTimer_default.on(Event.Timer_cancel).when((timer_cancel) => {
		return timer_cancel.port === 'timer' && timer_cancel.type === 'timer_cancel';
	}).effect((timer_cancel) => {
		this.cancel(timer_cancel.id);
	});
}
TimerNodeJS.prototype.startTimer = function(TimerNodeJS_startTimer_id_var, TimerNodeJS_startTimer_delay_var) {
	
		if (this.TimerNodeJS_Timeouts_var[TimerNodeJS_startTimer_id_var] != undefined) {
	
	this.cancel(TimerNodeJS_startTimer_id_var);
	
		}
	
		this.TimerNodeJS_Timeouts_var[TimerNodeJS_startTimer_id_var] = this.TimerNodeJS_driftless_var.setDriftlessTimeout(() => {
	
	this.bus.emit('timer', new Event.Timer_timeout_TimerMsgs(this.name, 'timer', TimerNodeJS_startTimer_id_var));
	
		this.TimerNodeJS_Timeouts_var[TimerNodeJS_startTimer_id_var] = undefined;
	}, TimerNodeJS_startTimer_delay_var);
	
}

TimerNodeJS.prototype.cancel = function(TimerNodeJS_cancel_id_var) {
	
		if (this.TimerNodeJS_Timeouts_var[TimerNodeJS_cancel_id_var] != undefined) {
			this.TimerNodeJS_driftless_var.clearDriftless(this.TimerNodeJS_Timeouts_var[TimerNodeJS_cancel_id_var]);
			this.TimerNodeJS_Timeouts_var[TimerNodeJS_cancel_id_var] = undefined;
		}
	
}

TimerNodeJS.prototype._stop = function() {
	this.root = null;
	this.ready = false;
	this.stopped = true;
}

TimerNodeJS.prototype._delete = function() {
	this._statemachine = null;
	this._SoftTimer_instance = null;
	this.bus.removeAllListeners();
}

TimerNodeJS.prototype._init = function() {
	this._SoftTimer_instance = new StateJS.Instance("SoftTimer_instance", this._statemachine);
	this.ready = true;
}

TimerNodeJS.prototype._receive = function(msg) {
	if (this.ready) {
		this._SoftTimer_instance.evaluate(msg);
	} else if (!this.stopped) {
		setTimeout(()=>this._receive(msg),4);
	}
}

TimerNodeJS.prototype.toString = function() {
	let result = 'instance ' + this.name + ':' + this.constructor.name + '\n';
	result += '\n\tdriftless = ' + this.TimerNodeJS_driftless_var;
	result += '\n\tTimeouts = ' + this.TimerNodeJS_Timeouts_var;
	result += '';
	return result;
}

module.exports = TimerNodeJS;
