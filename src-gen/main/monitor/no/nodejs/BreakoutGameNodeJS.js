'use strict';

const StateJS = require('@steelbreeze/state');
const EventEmitter = require('events').EventEmitter;
const Enum = require('./enums');
const Event = require('./events');


/*
 * Definition for type : BreakoutGameNodeJS
 */

function BreakoutGameNodeJS(name, root) {
	this.bus = (root === null)? new EventEmitter() : this.root.bus;
	this.name = name;
	this.root = (root === null)? this : root;
	this.ready = false;
	
	this.build(name);
}

BreakoutGameNodeJS.prototype.build = function(session) {
	/*State machine (states and regions)*/
	/*Building root component*/
	this._statemachine = new StateJS.State('SC');
	let _initial_BreakoutGame_SC = new StateJS.PseudoState('_initial', this._statemachine, StateJS.PseudoStateKind.Initial);
	let BreakoutGame_SC_INIT = new StateJS.State('INIT', this._statemachine).entry(() => {
		this.BreakoutGame_startTime_var = this.timestamp();
		this.bus.emit('display', new Event.Create_DisplayMsgs(this.name, 'display', this.BreakoutGame_XDISPSIZE_var, this.BreakoutGame_YDISPSIZE_var));
	});
	let BreakoutGame_SC_LAUNCH = new StateJS.State('LAUNCH', this._statemachine).entry(() => {
		this.bus.emit('clock', new Event.Timer_start_TimerMsgs(this.name, 'clock', 0, this.BreakoutGame_period_var));
		this.BreakoutGame_SC_LAUNCH_countdown_var = 3;
		this.drawScore();
		this.drawLives();
		this.bus.emit('display', new Event.Update_DisplayMsgs(this.name, 'display'));
	});
	let BreakoutGame_SC_PLAY = new StateJS.State('PLAY', this._statemachine).entry(() => {
		this.bus.emit('clock', new Event.Timer_start_TimerMsgs(this.name, 'clock', 0, this.BreakoutGame_period_var));
	});
	let BreakoutGame_SC_LOSTBALL = new StateJS.State('LOSTBALL', this._statemachine).entry(() => {
		this.bus.emit('clock', new Event.Timer_start_TimerMsgs(this.name, 'clock', 0, this.BreakoutGame_period_var));
		this.BreakoutGame_lives_var = this.BreakoutGame_lives_var - 1;
		this.eraseBall();
		this.erasePad();
		this.drawLives();
		this.bus.emit('display', new Event.Update_DisplayMsgs(this.name, 'display'));
		this.log(true);
	});
	let BreakoutGame_SC_NEXTLEVEL = new StateJS.State('NEXTLEVEL', this._statemachine).entry(() => {
		this.bus.emit('clock', new Event.Timer_start_TimerMsgs(this.name, 'clock', 0, this.BreakoutGame_period_var));
		this.BreakoutGame_level_var = this.BreakoutGame_level_var + 1;
		this.drawLevel();
		this.eraseBall();
		this.erasePad();
		if((this.BreakoutGame_level_var % 2) === 0 && this.BreakoutGame_padlen_var > 5 * this.BreakoutGame_SCALE_var) {
		this.BreakoutGame_padlen_var = this.BreakoutGame_padlen_var - (4 * this.BreakoutGame_SCALE_var);
		
		}
		if((this.BreakoutGame_level_var % 2) === 1) {
		this.BreakoutGame_dy_var = Math.trunc((this.BreakoutGame_dy_var * 3) / 2);
		
		}
		this.drawLives();
		this.createBricks();
		this.bus.emit('display', new Event.Update_DisplayMsgs(this.name, 'display'));
	});
	let BreakoutGame_SC_GAMEOVER = new StateJS.State('GAMEOVER', this._statemachine).entry(() => {
		this.eraseBall();
		this.erasePad();
		this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', 255, 255, 255));
		this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', 8, 30, 142, 76));
		this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', this.BreakoutGame_fgcolor_var[0], this.BreakoutGame_fgcolor_var[1], this.BreakoutGame_fgcolor_var[2]));
		this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', 9, 31, 140, 50));
		this.bus.emit('display', new Event.SetBGColor_DisplayMsgs(this.name, 'display', this.BreakoutGame_fgcolor_var[0], this.BreakoutGame_fgcolor_var[1], this.BreakoutGame_fgcolor_var[2]));
		this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', 158, 209, 130));
		this.bus.emit('display', new Event.DrawInteger_DisplayMsgs(this.name, 'display', 23, 40, this.BreakoutGame_score_var, 5, 6));
		this.bus.emit('display', new Event.DrawThingML_DisplayMsgs(this.name, 'display', 26, 87));
		this.bus.emit('display', new Event.Update_DisplayMsgs(this.name, 'display'));
		this.log(true);
		this.BreakoutGame_stopTime_var = this.timestamp();
		this.quit();
		setImmediate(()=>this._stop());
	});
	_initial_BreakoutGame_SC.to(BreakoutGame_SC_INIT);
	this._statemachine.on(Event.Position).when((position) => {
		return position.port === 'controller' && position.type === 'position';
	}).effect((position) => {
		let center_var = (this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var - this.BreakoutGame_padlen_var);
		center_var = position.x * center_var;
		center_var = Math.trunc(center_var / 200);
		this.BreakoutGame_padx_var = (this.BreakoutGame_LEFT_var + center_var + Math.trunc((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / 2));
	});
	BreakoutGame_SC_PLAY.to(BreakoutGame_SC_LOSTBALL).on(Event.LostBall_BreakoutGame).when((lostBall) => {
		return lostBall.port === 'game' && lostBall.type === 'lostBall';
	}).effect((lostBall) => {
		this.bus.emit('clock', new Event.Timer_cancel_TimerMsgs(this.name, 'clock', 0));
	});
	BreakoutGame_SC_PLAY.to(BreakoutGame_SC_NEXTLEVEL).on(Event.NextLevel_BreakoutGame).when((nextLevel) => {
		return nextLevel.port === 'game' && nextLevel.type === 'nextLevel';
	}).effect((nextLevel) => {
		this.bus.emit('clock', new Event.Timer_cancel_TimerMsgs(this.name, 'clock', 0));
	});
	BreakoutGame_SC_LAUNCH.to(BreakoutGame_SC_PLAY).on(Event.Timer_timeout_TimerMsgs).when((timer_timeout) => {
		return timer_timeout.port === 'clock' && timer_timeout.type === 'timer_timeout' && (timer_timeout.id === 0 && this.BreakoutGame_SC_LAUNCH_countdown_var === 0);
	}).effect((timer_timeout) => {
		this.drawCountDown(0);
		this.resetBall();
		this.bus.emit('display', new Event.Update_DisplayMsgs(this.name, 'display'));
	});
	BreakoutGame_SC_LAUNCH.on(Event.Timer_timeout).when((timer_timeout) => {
		return timer_timeout.port === 'clock' && timer_timeout.type === 'timer_timeout' && (timer_timeout.id === 0 && this.BreakoutGame_SC_LAUNCH_countdown_var > 0);
	}).effect((timer_timeout) => {
		this.bus.emit('clock', new Event.Timer_start_TimerMsgs(this.name, 'clock', 0, this.BreakoutGame_period_var));
		this.drawPad();
		if((this.BreakoutGame_SC_LAUNCH_countdown_var % 30) === 0) {
		this.drawCountDown(Math.trunc(this.BreakoutGame_SC_LAUNCH_countdown_var / 30));
		
		}
		this.BreakoutGame_SC_LAUNCH_countdown_var = this.BreakoutGame_SC_LAUNCH_countdown_var - 1;
		this.bus.emit('display', new Event.Update_DisplayMsgs(this.name, 'display'));
	});
	BreakoutGame_SC_PLAY.on(Event.Timer_timeout).when((timer_timeout) => {
		return timer_timeout.port === 'clock' && timer_timeout.type === 'timer_timeout' && (timer_timeout.id === 0);
	}).effect((timer_timeout) => {
		this.BreakoutGame_bx_var = this.BreakoutGame_bx_var + this.BreakoutGame_dx_var;
		this.BreakoutGame_by_var = this.BreakoutGame_by_var + this.BreakoutGame_dy_var;
		let wl_var = this.BreakoutGame_LEFT_var + this.BreakoutGame_br_var;
		let wr_var = this.BreakoutGame_RIGHT_var - this.BreakoutGame_br_var;
		let wt_var = this.BreakoutGame_TOP_var + this.BreakoutGame_br_var;
		let wb_var = this.BreakoutGame_BOTTOM_var - this.BreakoutGame_br_var;
		if(this.BreakoutGame_bx_var < wl_var) {
		this.BreakoutGame_dx_var =  -this.BreakoutGame_dx_var;
		this.BreakoutGame_bx_var = 2 * wl_var - this.BreakoutGame_bx_var;
		this.incrementScore( -1);
		
		} else {
		if(this.BreakoutGame_bx_var > wr_var) {
		this.BreakoutGame_dx_var =  -this.BreakoutGame_dx_var;
		this.BreakoutGame_bx_var = 2 * wr_var - this.BreakoutGame_bx_var;
		this.incrementScore( -1);
		
		}
		
		}
		if(this.BreakoutGame_by_var < wt_var) {
		this.BreakoutGame_dy_var =  -this.BreakoutGame_dy_var;
		this.BreakoutGame_by_var = 2 * wt_var - this.BreakoutGame_by_var;
		this.incrementScore( -1);
		
		} else {
		if(this.BreakoutGame_by_var > wb_var) {
		this.bus.emit('game', new Event.LostBall_BreakoutGame(this.name, 'game'));
		this.bus.emit('req_game', new Event.LostBall_BreakoutGame(this.name, 'req_game'));
		
		}
		
		}
		if(this.BreakoutGame_dy_var > 0) {
		if(this.BreakoutGame_by_var > this.BreakoutGame_pady_var - this.BreakoutGame_br_var && this.BreakoutGame_by_var < this.BreakoutGame_pady_var + this.BreakoutGame_br_var) {
		if(this.BreakoutGame_bx_var > this.BreakoutGame_padx_var - Math.trunc(this.BreakoutGame_padlen_var / 2) && this.BreakoutGame_bx_var < this.BreakoutGame_padx_var + Math.trunc(this.BreakoutGame_padlen_var / 2)) {
		this.BreakoutGame_dy_var =  -this.BreakoutGame_dy_var;
		this.BreakoutGame_by_var = 2 * (this.BreakoutGame_pady_var - this.BreakoutGame_br_var) - this.BreakoutGame_by_var;
		this.BreakoutGame_dx_var = Math.trunc(this.BreakoutGame_dx_var / 4) + Math.trunc((this.BreakoutGame_bx_var - this.BreakoutGame_padx_var) / 4);
		
		}
		
		}
		
		}
		let collision_var = this.collideBrick(this.BreakoutGame_bx_var - this.BreakoutGame_br_var, this.BreakoutGame_by_var - this.BreakoutGame_br_var) || this.collideBrick(this.BreakoutGame_bx_var + this.BreakoutGame_br_var, this.BreakoutGame_by_var - this.BreakoutGame_br_var) || this.collideBrick(this.BreakoutGame_bx_var + this.BreakoutGame_br_var, this.BreakoutGame_by_var + this.BreakoutGame_br_var) || this.collideBrick(this.BreakoutGame_bx_var - this.BreakoutGame_br_var, this.BreakoutGame_by_var + this.BreakoutGame_br_var);
		if(collision_var) {
		this.BreakoutGame_dy_var =  -this.BreakoutGame_dy_var;
		this.incrementScore(10);
		if(this.bricksLeft() === 0) {
		this.bus.emit('game', new Event.NextLevel_BreakoutGame(this.name, 'game'));
		this.bus.emit('req_game', new Event.NextLevel_BreakoutGame(this.name, 'req_game'));
		
		}
		
		}
		this.drawBall();
		this.drawPad();
		this.bus.emit('ia', new Event.UpdateIA_IAControllerMsg(this.name, 'ia', this.BreakoutGame_bx_var, this.BreakoutGame_by_var, this.BreakoutGame_padx_var, this.BreakoutGame_pady_var));
		this.bus.emit('display', new Event.Update_DisplayMsgs(this.name, 'display'));
		this.log(false);
		this.bus.emit('clock', new Event.Timer_start_TimerMsgs(this.name, 'clock', 0, this.BreakoutGame_period_var));
	});
	BreakoutGame_SC_LOSTBALL.to(BreakoutGame_SC_LAUNCH).on(Event.Timer_timeout_TimerMsgs).when((timer_timeout) => {
		return timer_timeout.port === 'clock' && timer_timeout.type === 'timer_timeout' && (timer_timeout.id === 0 && this.BreakoutGame_lives_var > 0);
	});
	BreakoutGame_SC_LOSTBALL.to(BreakoutGame_SC_GAMEOVER).on(Event.Timer_timeout_TimerMsgs).when((timer_timeout) => {
		return timer_timeout.port === 'clock' && timer_timeout.type === 'timer_timeout' && (timer_timeout.id === 0 && this.BreakoutGame_lives_var === 0);
	});
	BreakoutGame_SC_NEXTLEVEL.to(BreakoutGame_SC_LAUNCH).on(Event.Timer_timeout_TimerMsgs).when((timer_timeout) => {
		return timer_timeout.port === 'clock' && timer_timeout.type === 'timer_timeout' && (timer_timeout.id === 0);
	});
	BreakoutGame_SC_INIT.to(BreakoutGame_SC_LAUNCH).on(Event.DisplayReady_DisplayMsgs).when((displayReady) => {
		return displayReady.port === 'display' && displayReady.type === 'displayReady';
	}).effect((displayReady) => {
		this.bus.emit('display', new Event.Clear_DisplayMsgs(this.name, 'display'));
		this.initColors();
		this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', this.BreakoutGame_bgcolor_var[0], this.BreakoutGame_bgcolor_var[1], this.BreakoutGame_bgcolor_var[2]));
		this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', 0, 0, this.BreakoutGame_XDISPSIZE_var, this.BreakoutGame_YDISPSIZE_var));
		this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', this.BreakoutGame_fgcolor_var[0], this.BreakoutGame_fgcolor_var[1], this.BreakoutGame_fgcolor_var[2]));
		this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', 0, 0, this.BreakoutGame_XDISPSIZE_var, 14));
		this.drawWalls();
		this.createBricks();
		this.drawLevel();
	});
	BreakoutGame_SC_PLAY.to(BreakoutGame_SC_LOSTBALL).on(Event.LostBall_BreakoutGame).when((lostBall) => {
		return lostBall.port === 'pro_game' && lostBall.type === 'lostBall';
	}).effect((lostBall) => {
		this.bus.emit('clock', new Event.Timer_cancel_TimerMsgs(this.name, 'clock', 0));
	});
	BreakoutGame_SC_PLAY.to(BreakoutGame_SC_NEXTLEVEL).on(Event.NextLevel_BreakoutGame).when((nextLevel) => {
		return nextLevel.port === 'pro_game' && nextLevel.type === 'nextLevel';
	}).effect((nextLevel) => {
		this.bus.emit('clock', new Event.Timer_cancel_TimerMsgs(this.name, 'clock', 0));
	});
}
BreakoutGameNodeJS.prototype.log = function(BreakoutGame_log_logMem_var) {
	if(this.BreakoutGame_counter_var === 0 || BreakoutGame_log_logMem_var) {
	let ts_var;
	if(this.BreakoutGame_lastTimestamp_var === 0) {
	ts_var = 0;
	this.BreakoutGame_lastTimestamp_var = this.timestamp();
	
	} else {
	let t_var = this.timestamp();
	ts_var = t_var - this.BreakoutGame_lastTimestamp_var;
	this.BreakoutGame_lastTimestamp_var = t_var;
	
	}
	if( !(this.BreakoutGame_QUIET_var)) {
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'ts:'+ts_var+',lives:'+this.BreakoutGame_lives_var+',score:'+this.BreakoutGame_score_var+',level:'+this.BreakoutGame_level_var+',bx:'+this.BreakoutGame_bx_var+',by:'+this.BreakoutGame_by_var+',padx:'+this.BreakoutGame_padx_var);
	if (process.stdout) process.stdout.write('\n');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'#usedMem:'+this.usedMemory());
	if (process.stdout) process.stdout.write('\n');
	
	}
	
	}
	this.BreakoutGame_counter_var++;
	if(this.BreakoutGame_counter_var === 33) {
	this.BreakoutGame_counter_var = 0;
	
	}
}

BreakoutGameNodeJS.prototype.initColors = function() {
	this.BreakoutGame_bgcolor_var[0] = 53;
	this.BreakoutGame_bgcolor_var[1] = 40;
	this.BreakoutGame_bgcolor_var[2] = 120;
	this.BreakoutGame_fgcolor_var[0] = 107;
	this.BreakoutGame_fgcolor_var[1] = 94;
	this.BreakoutGame_fgcolor_var[2] = 174;
	this.bus.emit('display', new Event.SetBGColor_DisplayMsgs(this.name, 'display', this.BreakoutGame_bgcolor_var[0], this.BreakoutGame_bgcolor_var[1], this.BreakoutGame_bgcolor_var[2]));
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', this.BreakoutGame_fgcolor_var[0], this.BreakoutGame_fgcolor_var[1], this.BreakoutGame_fgcolor_var[2]));
}

BreakoutGameNodeJS.prototype.resetBall = function() {
	this.BreakoutGame_bx_var = this.BreakoutGame_padx_var - Math.trunc(this.BreakoutGame_br_var / this.BreakoutGame_SCALE_var);
	this.BreakoutGame_by_var = this.BreakoutGame_pady_var - Math.trunc(this.BreakoutGame_br_var / this.BreakoutGame_SCALE_var);
	this.BreakoutGame_dx_var = (this.BreakoutGame_padx_var + this.BreakoutGame_prevBX_var + this.BreakoutGame_prevBY_var) % 300 - 150;
	if(this.BreakoutGame_dy_var > 0) {
	this.BreakoutGame_dy_var =  -this.BreakoutGame_dy_var;
	
	}
	this.BreakoutGame_prevBX_var =  -1;
	this.BreakoutGame_prevBY_var =  -1;
}

BreakoutGameNodeJS.prototype.eraseBall = function() {
	let bs_var = Math.trunc((this.BreakoutGame_br_var * 2) / this.BreakoutGame_SCALE_var);
	if(this.BreakoutGame_prevBX_var > 0) {
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', this.BreakoutGame_bgcolor_var[0], this.BreakoutGame_bgcolor_var[1], this.BreakoutGame_bgcolor_var[2]));
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', this.BreakoutGame_prevBX_var, this.BreakoutGame_prevBY_var, bs_var, bs_var));
	
	}
	this.BreakoutGame_prevBX_var =  -1;
	this.BreakoutGame_prevBY_var =  -1;
}

BreakoutGameNodeJS.prototype.drawBall = function() {
	let bs_var = Math.trunc((this.BreakoutGame_br_var * 2) / this.BreakoutGame_SCALE_var);
	this.eraseBall();
	this.BreakoutGame_prevBX_var = Math.trunc((this.BreakoutGame_bx_var - this.BreakoutGame_br_var) / this.BreakoutGame_SCALE_var);
	this.BreakoutGame_prevBY_var = Math.trunc((this.BreakoutGame_by_var - this.BreakoutGame_br_var) / this.BreakoutGame_SCALE_var);
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', 183, 199, 111));
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', this.BreakoutGame_prevBX_var, this.BreakoutGame_prevBY_var, bs_var, bs_var));
}

BreakoutGameNodeJS.prototype.erasePad = function() {
	let ps_var = Math.trunc(this.BreakoutGame_padlen_var / this.BreakoutGame_SCALE_var);
	if(this.BreakoutGame_prevPX_var > 0) {
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', this.BreakoutGame_bgcolor_var[0], this.BreakoutGame_bgcolor_var[1], this.BreakoutGame_bgcolor_var[2]));
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', this.BreakoutGame_prevPX_var, this.BreakoutGame_prevPY_var, ps_var, 4));
	
	}
}

BreakoutGameNodeJS.prototype.drawPad = function() {
	let ps_var = Math.trunc(this.BreakoutGame_padlen_var / this.BreakoutGame_SCALE_var);
	this.erasePad();
	this.BreakoutGame_prevPX_var = Math.trunc((this.BreakoutGame_padx_var - (Math.trunc(this.BreakoutGame_padlen_var / 2))) / this.BreakoutGame_SCALE_var);
	this.BreakoutGame_prevPY_var = Math.trunc(this.BreakoutGame_pady_var / this.BreakoutGame_SCALE_var);
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', this.BreakoutGame_fgcolor_var[0], this.BreakoutGame_fgcolor_var[1], this.BreakoutGame_fgcolor_var[2]));
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', this.BreakoutGame_prevPX_var, this.BreakoutGame_prevPY_var, ps_var, 4));
}

BreakoutGameNodeJS.prototype.drawCountDown = function(BreakoutGame_drawCountDown_c_var) {
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', this.BreakoutGame_fgcolor_var[0], this.BreakoutGame_fgcolor_var[1], this.BreakoutGame_fgcolor_var[2]));
	if(BreakoutGame_drawCountDown_c_var > 0) {
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', this.BreakoutGame_fgcolor_var[0], this.BreakoutGame_fgcolor_var[1], this.BreakoutGame_fgcolor_var[2]));
	this.bus.emit('display', new Event.SetBGColor_DisplayMsgs(this.name, 'display', this.BreakoutGame_bgcolor_var[0], this.BreakoutGame_bgcolor_var[1], this.BreakoutGame_bgcolor_var[2]));
	this.bus.emit('display', new Event.DrawInteger_DisplayMsgs(this.name, 'display', 80 - 6, 90, BreakoutGame_drawCountDown_c_var, 1, 4));
	
	} else {
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', this.BreakoutGame_bgcolor_var[0], this.BreakoutGame_bgcolor_var[1], this.BreakoutGame_bgcolor_var[2]));
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', 80 - 6, 90, 12, 20));
	
	}
}

BreakoutGameNodeJS.prototype.drawWalls = function() {
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', this.BreakoutGame_fgcolor_var[0], this.BreakoutGame_fgcolor_var[1], this.BreakoutGame_fgcolor_var[2]));
	const left_var = (Math.trunc(this.BreakoutGame_LEFT_var / this.BreakoutGame_SCALE_var));
	const right_var = (Math.trunc(this.BreakoutGame_RIGHT_var / this.BreakoutGame_SCALE_var));
	const top_var = (Math.trunc(this.BreakoutGame_TOP_var / this.BreakoutGame_SCALE_var));
	const bottom_var = (Math.trunc(this.BreakoutGame_BOTTOM_var / this.BreakoutGame_SCALE_var));
	const xcenter_var = (Math.trunc((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / this.BreakoutGame_SCALE_var));
	const ycenter_var = (Math.trunc((this.BreakoutGame_BOTTOM_var - this.BreakoutGame_TOP_var) / this.BreakoutGame_SCALE_var));
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', left_var - 1, top_var - 1, xcenter_var + 1, 1));
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', left_var - 1, bottom_var, xcenter_var + 1, 1));
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', left_var - 1, top_var, 1, ycenter_var));
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', right_var, top_var, 1, ycenter_var));
}

BreakoutGameNodeJS.prototype.bitIsSet = function(BreakoutGame_bitIsSet_variable_var, BreakoutGame_bitIsSet_bit_var) {
	return (((1 << BreakoutGame_bitIsSet_bit_var) & BreakoutGame_bitIsSet_variable_var) != 0);
}

BreakoutGameNodeJS.prototype.createBricks = function() {
	let y_var = 0;
	while(y_var < this.BreakoutGame_BRICK_ROWS_var) {
	this.BreakoutGame_bricks_var[y_var] = 0xFF;
	let x_var = 0;
	while(x_var < 8) {
	if(this.bitIsSet(this.BreakoutGame_bricks_var[y_var], x_var)) {
	this.drawBrick(x_var, y_var);
	
	}
	x_var = x_var + 1;
	
	}
	y_var = y_var + 1;
	
	}
}

BreakoutGameNodeJS.prototype.bricksLeft = function() {
	let result_var = 0;
	let y_var = 0;
	while(y_var < this.BreakoutGame_BRICK_ROWS_var) {
	let x_var = 0;
	while(x_var < 8) {
	if(this.bitIsSet(this.BreakoutGame_bricks_var[y_var], x_var)) {
	result_var = result_var + 1;
	
	}
	x_var = x_var + 1;
	
	}
	y_var = y_var + 1;
	
	}
	return result_var;
}

BreakoutGameNodeJS.prototype.drawBrick = function(BreakoutGame_drawBrick_x_var, BreakoutGame_drawBrick_y_var) {
	const bx_var = (Math.trunc((this.BreakoutGame_LEFT_var + (Math.trunc((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / 8)) * BreakoutGame_drawBrick_x_var) / this.BreakoutGame_SCALE_var) + 1);
	const by_var = (Math.trunc((this.BreakoutGame_TOP_var + 20 * this.BreakoutGame_SCALE_var + this.BreakoutGame_BRICK_HEIGHT_var * BreakoutGame_drawBrick_y_var * this.BreakoutGame_SCALE_var) / this.BreakoutGame_SCALE_var) + 1);
	const w_var = (Math.trunc((Math.trunc((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / 8)) / this.BreakoutGame_SCALE_var) - 2);
	const h_var = (this.BreakoutGame_BRICK_HEIGHT_var - 2);
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', 155, 103, 89));
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', bx_var, by_var, w_var, h_var));
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', 100, 56, 43));
	this.bus.emit('display', new Event.DrawRect_DisplayMsgs(this.name, 'display', bx_var, by_var, w_var, h_var));
}

BreakoutGameNodeJS.prototype.removeBrick = function(BreakoutGame_removeBrick_x_var, BreakoutGame_removeBrick_y_var) {
	const bx_var = (Math.trunc((this.BreakoutGame_LEFT_var + (Math.trunc((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / 8)) * BreakoutGame_removeBrick_x_var) / this.BreakoutGame_SCALE_var) + 1);
	const by_var = (Math.trunc((this.BreakoutGame_TOP_var + 20 * this.BreakoutGame_SCALE_var + this.BreakoutGame_BRICK_HEIGHT_var * BreakoutGame_removeBrick_y_var * this.BreakoutGame_SCALE_var) / this.BreakoutGame_SCALE_var) + 1);
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', this.BreakoutGame_bgcolor_var[0], this.BreakoutGame_bgcolor_var[1], this.BreakoutGame_bgcolor_var[2]));
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', bx_var, by_var, (Math.trunc((Math.trunc((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / 8)) / this.BreakoutGame_SCALE_var) - 2), this.BreakoutGame_BRICK_HEIGHT_var - 2));
	this.BreakoutGame_bricks_var[BreakoutGame_removeBrick_y_var] = this.unsetBit(this.BreakoutGame_bricks_var[BreakoutGame_removeBrick_y_var], BreakoutGame_removeBrick_x_var);
}

BreakoutGameNodeJS.prototype.collideBrick = function(BreakoutGame_collideBrick_xpos_var, BreakoutGame_collideBrick_ypos_var) {
	let bry_var = Math.trunc((BreakoutGame_collideBrick_ypos_var - this.BreakoutGame_TOP_var - 20 * this.BreakoutGame_SCALE_var) / (this.BreakoutGame_BRICK_HEIGHT_var * this.BreakoutGame_SCALE_var));
	let result_var = false;
	if(bry_var >= 0 && bry_var < this.BreakoutGame_BRICK_ROWS_var) {
	let brx_var = Math.trunc((BreakoutGame_collideBrick_xpos_var - this.BreakoutGame_LEFT_var) / (Math.trunc((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / 8)));
	if(this.bitIsSet(this.BreakoutGame_bricks_var[bry_var], brx_var)) {
	this.removeBrick(brx_var, bry_var);
	result_var = true;
	
	}
	
	}
	return result_var;
}

BreakoutGameNodeJS.prototype.drawLevel = function() {
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', 158, 209, 130));
	this.bus.emit('display', new Event.SetBGColor_DisplayMsgs(this.name, 'display', this.BreakoutGame_fgcolor_var[0], this.BreakoutGame_fgcolor_var[1], this.BreakoutGame_fgcolor_var[2]));
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', this.BreakoutGame_bgcolor_var[0], this.BreakoutGame_bgcolor_var[1], this.BreakoutGame_bgcolor_var[2]));
	this.bus.emit('display', new Event.DrawInteger_DisplayMsgs(this.name, 'display', 6, 2, this.BreakoutGame_level_var, 2, 2));
}

BreakoutGameNodeJS.prototype.incrementScore = function(BreakoutGame_incrementScore_diff_var) {
	this.BreakoutGame_score_var = this.BreakoutGame_score_var + BreakoutGame_incrementScore_diff_var;
	if(this.BreakoutGame_score_var < 0) {
	this.BreakoutGame_score_var = 0;
	
	}
	this.drawScore();
}

BreakoutGameNodeJS.prototype.drawScore = function() {
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', 158, 209, 130));
	this.bus.emit('display', new Event.SetBGColor_DisplayMsgs(this.name, 'display', this.BreakoutGame_fgcolor_var[0], this.BreakoutGame_fgcolor_var[1], this.BreakoutGame_fgcolor_var[2]));
	this.bus.emit('display', new Event.DrawInteger_DisplayMsgs(this.name, 'display', 58, 2, this.BreakoutGame_score_var, 5, 2));
}

BreakoutGameNodeJS.prototype.drawLives = function() {
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', this.BreakoutGame_fgcolor_var[0], this.BreakoutGame_fgcolor_var[1], this.BreakoutGame_fgcolor_var[2]));
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', 124, 4, 24 + 6, 6));
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', 183, 199, 111));
	let i_var = 0;
	while(i_var < this.BreakoutGame_lives_var) {
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', 124 + (2 - i_var) * 12, 4, 6, 6));
	i_var = i_var + 1;
	
	}
}

BreakoutGameNodeJS.prototype.quit = function() {
	if (global.gc) {
		global.gc();
	}
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'>done in '+(Number(this.BreakoutGame_stopTime_var) - Number(this.BreakoutGame_startTime_var))+'ms!');
	if (process.stdout) process.stdout.write('\n');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'>lives:'+this.BreakoutGame_lives_var+',score:'+this.BreakoutGame_score_var+',level:'+this.BreakoutGame_level_var+',bx:'+this.BreakoutGame_bx_var+',by:'+this.BreakoutGame_by_var+',padx:'+this.BreakoutGame_padx_var);
	if (process.stdout) process.stdout.write('\n');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'>usedMem:'+this.usedMemory());
	if (process.stdout) process.stdout.write('\n');
	process.exitCode = 1;
}

BreakoutGameNodeJS.prototype.timestamp = function() {
	return process.hrtime.bigint()/BigInt(1000000);
}

BreakoutGameNodeJS.prototype.usedMemory = function() {
	if (global.gc) {
		global.gc();
	}
	return process.memoryUsage().heapUsed;
}

BreakoutGameNodeJS.prototype.unsetBit = function(BreakoutGameNodeJS_unsetBit_variable_var, BreakoutGameNodeJS_unsetBit_bit_var) {
	return (BreakoutGameNodeJS_unsetBit_variable_var & ~(1 << BreakoutGameNodeJS_unsetBit_bit_var));
}

BreakoutGameNodeJS.prototype._stop = function() {
	this.root = null;
	this.ready = false;
	this.stopped = true;
}

BreakoutGameNodeJS.prototype._delete = function() {
	this._statemachine = null;
	this._SC_instance = null;
	this.bus.removeAllListeners();
}

BreakoutGameNodeJS.prototype._init = function() {
	this._SC_instance = new StateJS.Instance("SC_instance", this._statemachine);
	this.ready = true;
}

BreakoutGameNodeJS.prototype._receive = function(msg) {
	if (this.ready) {
		this._SC_instance.evaluate(msg);
	} else if (!this.stopped) {
		setTimeout(()=>this._receive(msg),4);
	}
}

BreakoutGameNodeJS.prototype.toString = function() {
	let result = 'instance ' + this.name + ':' + this.constructor.name + '\n';
	result += '\n\tdx = ' + this.BreakoutGame_dx_var;
	result += '\n\tcounter = ' + this.BreakoutGame_counter_var;
	result += '\n\tstopTime = ' + this.BreakoutGame_stopTime_var;
	result += '\n\tpadlen = ' + this.BreakoutGame_padlen_var;
	result += '\n\tXMAX = ' + this.BreakoutGame_XMAX_var;
	result += '\n\tLEFT = ' + this.BreakoutGame_LEFT_var;
	result += '\n\tSCALE = ' + this.BreakoutGame_SCALE_var;
	result += '\n\tprevBY = ' + this.BreakoutGame_prevBY_var;
	result += '\n\tfgcolor = ' + this.BreakoutGame_fgcolor_var;
	result += '\n\tprevBX = ' + this.BreakoutGame_prevBX_var;
	result += '\n\tTOP = ' + this.BreakoutGame_TOP_var;
	result += '\n\tdy = ' + this.BreakoutGame_dy_var;
	result += '\n\tRIGHT = ' + this.BreakoutGame_RIGHT_var;
	result += '\n\tscore = ' + this.BreakoutGame_score_var;
	result += '\n\tperiod = ' + this.BreakoutGame_period_var;
	result += '\n\tYMAX = ' + this.BreakoutGame_YMAX_var;
	result += '\n\tYDISPSIZE = ' + this.BreakoutGame_YDISPSIZE_var;
	result += '\n\tbricks = ' + this.BreakoutGame_bricks_var;
	result += '\n\tlives = ' + this.BreakoutGame_lives_var;
	result += '\n\tstartTime = ' + this.BreakoutGame_startTime_var;
	result += '\n\tbr = ' + this.BreakoutGame_br_var;
	result += '\n\tBRICK_HEIGHT = ' + this.BreakoutGame_BRICK_HEIGHT_var;
	result += '\n\tlevel = ' + this.BreakoutGame_level_var;
	result += '\n\tcountdown = ' + this.BreakoutGame_SC_LAUNCH_countdown_var;
	result += '\n\tQUIET = ' + this.BreakoutGame_QUIET_var;
	result += '\n\tbgcolor = ' + this.BreakoutGame_bgcolor_var;
	result += '\n\tXDISPSIZE = ' + this.BreakoutGame_XDISPSIZE_var;
	result += '\n\tlastTimestamp = ' + this.BreakoutGame_lastTimestamp_var;
	result += '\n\tpadx = ' + this.BreakoutGame_padx_var;
	result += '\n\tBOTTOM = ' + this.BreakoutGame_BOTTOM_var;
	result += '\n\tBRICK_ROWS = ' + this.BreakoutGame_BRICK_ROWS_var;
	result += '\n\tby = ' + this.BreakoutGame_by_var;
	result += '\n\tprevPX = ' + this.BreakoutGame_prevPX_var;
	result += '\n\tpady = ' + this.BreakoutGame_pady_var;
	result += '\n\tbx = ' + this.BreakoutGame_bx_var;
	result += '\n\tprevPY = ' + this.BreakoutGame_prevPY_var;
	result += '';
	return result;
}

module.exports = BreakoutGameNodeJS;
