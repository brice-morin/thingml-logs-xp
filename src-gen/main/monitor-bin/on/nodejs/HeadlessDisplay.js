'use strict';

const StateJS = require('@steelbreeze/state');
const EventEmitter = require('events').EventEmitter;
const Enum = require('./enums');
const Event = require('./events');


/*
 * Definition for type : HeadlessDisplay
 */

function HeadlessDisplay(name, root) {
	this.bus = (root === null)? new EventEmitter() : this.root.bus;
	this.name = name;
	this.root = (root === null)? this : root;
	this.ready = false;
	
	this.build(name);
}

HeadlessDisplay.prototype.build = function(session) {
	/*State machine (states and regions)*/
	/*Building root component*/
	this._statemachine = new StateJS.State('default_statemachine');
	let _initial_HeadlessDisplay = new StateJS.PseudoState('_initial', this._statemachine, StateJS.PseudoStateKind.Initial);
	let HeadlessDisplay_null_INIT = new StateJS.State('INIT', this._statemachine).entry(() => {
		this.bus.emit('display', new Event.DisplayReady_DisplayMsgs(this.name, 'display'));
	});
	let HeadlessDisplay_null_MOCK = new StateJS.State('MOCK', this._statemachine);
	_initial_HeadlessDisplay.to(HeadlessDisplay_null_INIT);
	HeadlessDisplay_null_INIT.to(HeadlessDisplay_null_MOCK);
	HeadlessDisplay_null_MOCK.on(Event.DrawRect).when((drawRect) => {
		return drawRect.port === 'display' && drawRect.type === 'drawRect';
	}).effect((drawRect) => {
		this.mock();
	});
	HeadlessDisplay_null_MOCK.on(Event.Clear).when((clear) => {
		return clear.port === 'display' && clear.type === 'clear';
	}).effect((clear) => {
		this.mock();
	});
	HeadlessDisplay_null_MOCK.on(Event.DrawInteger).when((drawInteger) => {
		return drawInteger.port === 'display' && drawInteger.type === 'drawInteger';
	}).effect((drawInteger) => {
		this.mock();
	});
	HeadlessDisplay_null_MOCK.on(Event.Create).when((create) => {
		return create.port === 'display' && create.type === 'create';
	}).effect((create) => {
		this.mock();
	});
	HeadlessDisplay_null_MOCK.on(Event.DrawThingML).when((drawThingML) => {
		return drawThingML.port === 'display' && drawThingML.type === 'drawThingML';
	}).effect((drawThingML) => {
		this.mock();
	});
	HeadlessDisplay_null_MOCK.on(Event.Destroy).when((destroy) => {
		return destroy.port === 'display' && destroy.type === 'destroy';
	}).effect((destroy) => {
		this.mock();
	});
	HeadlessDisplay_null_MOCK.on(Event.SetBGColor).when((setBGColor) => {
		return setBGColor.port === 'display' && setBGColor.type === 'setBGColor';
	}).effect((setBGColor) => {
		this.mock();
	});
	HeadlessDisplay_null_MOCK.on(Event.SetColor).when((setColor) => {
		return setColor.port === 'display' && setColor.type === 'setColor';
	}).effect((setColor) => {
		this.mock();
	});
	HeadlessDisplay_null_MOCK.on(Event.FillRect).when((fillRect) => {
		return fillRect.port === 'display' && fillRect.type === 'fillRect';
	}).effect((fillRect) => {
		this.mock();
	});
	HeadlessDisplay_null_MOCK.on(Event.Update).when((update) => {
		return update.port === 'display' && update.type === 'update';
	}).effect((update) => {
		this.mock();
	});
}
HeadlessDisplay.prototype.mock = function() {
	
}

HeadlessDisplay.prototype._stop = function() {
	this.root = null;
	this.ready = false;
	this.stopped = true;
}

HeadlessDisplay.prototype._delete = function() {
	this._statemachine = null;
	this._null_instance = null;
	this.bus.removeAllListeners();
}

HeadlessDisplay.prototype._init = function() {
	this._null_instance = new StateJS.Instance("null_instance", this._statemachine);
	this.ready = true;
}

HeadlessDisplay.prototype._receive = function(msg) {
	if (this.ready) {
		this._null_instance.evaluate(msg);
	} else if (!this.stopped) {
		setTimeout(()=>this._receive(msg),4);
	}
}

HeadlessDisplay.prototype.toString = function() {
	let result = 'instance ' + this.name + ':' + this.constructor.name + '\n';
	result += '';
	return result;
}

module.exports = HeadlessDisplay;
