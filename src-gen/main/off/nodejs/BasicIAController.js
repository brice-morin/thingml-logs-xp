'use strict';

const Enum = require('./enums');
const StateJS = require('@steelbreeze/state');
const EventEmitter = require('events').EventEmitter;


/*
 * Definition for type : BasicIAController
 */

function BasicIAController(name, root) {
	this.name = name;
	this.root = (root === null)? this : root;
	this.ready = false;
	this.bus = (root === null)? new EventEmitter() : this.root.bus;
	
	this.build(name);
}

BasicIAController.prototype.build = function(session) {
	/*State machine (states and regions)*/
	/*Building root component*/
	this._statemachine = new StateJS.State('SC');
	let _initial_BasicIAController_SC = new StateJS.PseudoState('_initial', this._statemachine, StateJS.PseudoStateKind.Initial);
	let BasicIAController_SC_Following = new StateJS.State('Following', this._statemachine).entry(() => {
		setImmediate(() => {this.bus.emit('controls?position', this.BasicIAController_ctrlx_var, 0)});
	});
	_initial_BasicIAController_SC.to(BasicIAController_SC_Following);
	BasicIAController_SC_Following.to(BasicIAController_SC_Following).when((updateIA) => {
		return updateIA._port === 'game' && updateIA._msg === 'updateIA';
	}).effect((updateIA) => {
		if(updateIA.ballx > updateIA.padx + 400) {
		this.BasicIAController_ctrlx_var = this.BasicIAController_ctrlx_var + 4;
		
		} else {
		if(updateIA.ballx < updateIA.padx - 400) {
		this.BasicIAController_ctrlx_var = this.BasicIAController_ctrlx_var - 4;
		
		}
		
		}
		if(this.BasicIAController_ctrlx_var <  -100) {
		this.BasicIAController_ctrlx_var =  -100;
		
		} else {
		if(this.BasicIAController_ctrlx_var > 100) {
		this.BasicIAController_ctrlx_var = 100;
		
		}
		
		}
	});
}
BasicIAController.prototype._stop = function() {
	this.root = null;
	this.ready = false;
}

BasicIAController.prototype._delete = function() {
	this._statemachine = null;
	this._SC_instance = null;
	this.bus.removeAllListeners();
}

BasicIAController.prototype._init = function() {
	this._SC_instance = new StateJS.Instance("SC_instance", this._statemachine);
	this.ready = true;
}

BasicIAController.prototype._receive = function(msg) {
	/*msg = {_port:myPort, _msg:myMessage, paramN=paramN, ...}*/
	if (this.ready) {
		this._SC_instance.evaluate(msg);
	} else {
		setTimeout(()=>this._receive(msg),0);
	}
}

BasicIAController.prototype.receiveupdateIAOngame = function(ballx, bally, padx, pady) {
	this._receive({_port:"game", _msg:"updateIA", ballx:ballx, bally:bally, padx:padx, pady:pady});
}

BasicIAController.prototype.initBasicIAController_ctrlx_var = function(BasicIAController_ctrlx_var) {
	this.BasicIAController_ctrlx_var = BasicIAController_ctrlx_var;
}

BasicIAController.prototype.toString = function() {
	let result = 'instance ' + this.name + ':' + this.constructor.name + '\n';
	result += '\n\tctrlx = ' + this.BasicIAController_ctrlx_var;
	result += '';
	return result;
}

module.exports = BasicIAController;
