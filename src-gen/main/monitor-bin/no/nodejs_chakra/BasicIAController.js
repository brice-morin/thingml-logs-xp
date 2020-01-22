'use strict';

const StateJS = require('@steelbreeze/state');
const EventEmitter = require('events').EventEmitter;
const Enum = require('./enums');
const Event = require('./events');


/*
 * Definition for type : BasicIAController
 */

function BasicIAController(name, root) {
	this.bus = (root === null)? new EventEmitter() : this.root.bus;
	this.name = name;
	this.root = (root === null)? this : root;
	this.ready = false;
	
	this.build(name);
}

BasicIAController.prototype.build = function(session) {
	/*State machine (states and regions)*/
	/*Building root component*/
	this._statemachine = new StateJS.State('SC');
	let _initial_BasicIAController_SC = new StateJS.PseudoState('_initial', this._statemachine, StateJS.PseudoStateKind.Initial);
	let BasicIAController_SC_Following = new StateJS.State('Following', this._statemachine).entry(() => {
		this.bus.emit('controls', new Event.Position_ControllerMsgs(this.name, 'controls', this.BasicIAController_ctrlx_var, 0));
	});
	_initial_BasicIAController_SC.to(BasicIAController_SC_Following);
	BasicIAController_SC_Following.to(BasicIAController_SC_Following).on(Event.UpdateIA_IAControllerMsg).when((updateIA) => {
		return updateIA.port === 'game' && updateIA.type === 'updateIA';
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
	this.stopped = true;
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
	if (this.ready) {
		this._SC_instance.evaluate(msg);
	} else if (!this.stopped) {
		setTimeout(()=>this._receive(msg),4);
	}
}

BasicIAController.prototype.toString = function() {
	let result = 'instance ' + this.name + ':' + this.constructor.name + '\n';
	result += '\n\tctrlx = ' + this.BasicIAController_ctrlx_var;
	result += '';
	return result;
}

module.exports = BasicIAController;
