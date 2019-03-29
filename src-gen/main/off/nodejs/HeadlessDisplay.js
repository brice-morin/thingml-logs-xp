'use strict';

const Enum = require('./enums');
const StateJS = require('@steelbreeze/state');
const EventEmitter = require('events').EventEmitter;


/*
 * Definition for type : HeadlessDisplay
 */

function HeadlessDisplay(name, root) {
	this.name = name;
	this.root = (root === null)? this : root;
	this.ready = false;
	this.bus = (root === null)? new EventEmitter() : this.root.bus;
	
	this.build(name);
}

HeadlessDisplay.prototype.build = function(session) {
	/*State machine (states and regions)*/
	/*Building root component*/
	this._statemachine = new StateJS.State('default_statemachine');
	let _initial_HeadlessDisplay = new StateJS.PseudoState('_initial', this._statemachine, StateJS.PseudoStateKind.Initial);
	let HeadlessDisplay_null_INIT = new StateJS.State('INIT', this._statemachine).entry(() => {
		setImmediate(() => {this.bus.emit('display?displayReady')});
	});
	let HeadlessDisplay_null_MOCK = new StateJS.State('MOCK', this._statemachine);
	_initial_HeadlessDisplay.to(HeadlessDisplay_null_INIT);
	HeadlessDisplay_null_INIT.to(HeadlessDisplay_null_MOCK);
	HeadlessDisplay_null_MOCK.to(null).when((update) => {
		return update._port === 'display' && update._msg === 'update';
	}).effect((update) => {
		this.mock();
	});
	HeadlessDisplay_null_MOCK.to(null).when((destroy) => {
		return destroy._port === 'display' && destroy._msg === 'destroy';
	}).effect((destroy) => {
		this.mock();
	});
	HeadlessDisplay_null_MOCK.to(null).when((drawRect) => {
		return drawRect._port === 'display' && drawRect._msg === 'drawRect';
	}).effect((drawRect) => {
		this.mock();
	});
	HeadlessDisplay_null_MOCK.to(null).when((create) => {
		return create._port === 'display' && create._msg === 'create';
	}).effect((create) => {
		this.mock();
	});
	HeadlessDisplay_null_MOCK.to(null).when((clear) => {
		return clear._port === 'display' && clear._msg === 'clear';
	}).effect((clear) => {
		this.mock();
	});
	HeadlessDisplay_null_MOCK.to(null).when((setBGColor) => {
		return setBGColor._port === 'display' && setBGColor._msg === 'setBGColor';
	}).effect((setBGColor) => {
		this.mock();
	});
	HeadlessDisplay_null_MOCK.to(null).when((fillRect) => {
		return fillRect._port === 'display' && fillRect._msg === 'fillRect';
	}).effect((fillRect) => {
		this.mock();
	});
	HeadlessDisplay_null_MOCK.to(null).when((drawInteger) => {
		return drawInteger._port === 'display' && drawInteger._msg === 'drawInteger';
	}).effect((drawInteger) => {
		this.mock();
	});
	HeadlessDisplay_null_MOCK.to(null).when((setColor) => {
		return setColor._port === 'display' && setColor._msg === 'setColor';
	}).effect((setColor) => {
		this.mock();
	});
	HeadlessDisplay_null_MOCK.to(null).when((drawThingML) => {
		return drawThingML._port === 'display' && drawThingML._msg === 'drawThingML';
	}).effect((drawThingML) => {
		this.mock();
	});
}
HeadlessDisplay.prototype.mock = function() {
	
}

HeadlessDisplay.prototype._stop = function() {
	this.root = null;
	this.ready = false;
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
	/*msg = {_port:myPort, _msg:myMessage, paramN=paramN, ...}*/
	if (this.ready) {
		this._null_instance.evaluate(msg);
	} else {
		setTimeout(()=>this._receive(msg),0);
	}
}

HeadlessDisplay.prototype.receivecreateOndisplay = function(xsize, ysize) {
	this._receive({_port:"display", _msg:"create", xsize:xsize, ysize:ysize});
}

HeadlessDisplay.prototype.receivedestroyOndisplay = function() {
	this._receive({_port:"display", _msg:"destroy"});
}

HeadlessDisplay.prototype.receiveupdateOndisplay = function() {
	this._receive({_port:"display", _msg:"update"});
}

HeadlessDisplay.prototype.receiveclearOndisplay = function() {
	this._receive({_port:"display", _msg:"clear"});
}

HeadlessDisplay.prototype.receivesetColorOndisplay = function(r, g, b) {
	this._receive({_port:"display", _msg:"setColor", r:r, g:g, b:b});
}

HeadlessDisplay.prototype.receivesetBGColorOndisplay = function(r, g, b) {
	this._receive({_port:"display", _msg:"setBGColor", r:r, g:g, b:b});
}

HeadlessDisplay.prototype.receivedrawRectOndisplay = function(x, y, width, height) {
	this._receive({_port:"display", _msg:"drawRect", x:x, y:y, width:width, height:height});
}

HeadlessDisplay.prototype.receivefillRectOndisplay = function(x, y, width, height) {
	this._receive({_port:"display", _msg:"fillRect", x:x, y:y, width:width, height:height});
}

HeadlessDisplay.prototype.receivedrawIntegerOndisplay = function(x, y, v, digits, scale) {
	this._receive({_port:"display", _msg:"drawInteger", x:x, y:y, v:v, digits:digits, scale:scale});
}

HeadlessDisplay.prototype.receivedrawThingMLOndisplay = function(x, y) {
	this._receive({_port:"display", _msg:"drawThingML", x:x, y:y});
}

HeadlessDisplay.prototype.toString = function() {
	let result = 'instance ' + this.name + ':' + this.constructor.name + '\n';
	result += '';
	return result;
}

module.exports = HeadlessDisplay;
