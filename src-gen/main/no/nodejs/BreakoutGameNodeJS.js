'use strict';

const Enum = require('./enums');
const StateJS = require('@steelbreeze/state');
const EventEmitter = require('events').EventEmitter;


/*
 * Definition for type : BreakoutGameNodeJS
 */

function BreakoutGameNodeJS(name, root) {
	this.name = name;
	this.root = (root === null)? this : root;
	this.ready = false;
	this.bus = (root === null)? new EventEmitter() : this.root.bus;
	
	this.build(name);
}

BreakoutGameNodeJS.prototype.build = function(session) {
	/*State machine (states and regions)*/
	/*Building root component*/
	this._statemachine = new StateJS.State('SC');
	let _initial_BreakoutGame_SC = new StateJS.PseudoState('_initial', this._statemachine, StateJS.PseudoStateKind.Initial);
	let BreakoutGame_SC_INIT = new StateJS.State('INIT', this._statemachine).entry(() => {
		this.BreakoutGame_startTime_var = this.timestamp();
		this.bus.emit('display?create', this.BreakoutGame_XDISPSIZE_var, this.BreakoutGame_YDISPSIZE_var);
	});
	let BreakoutGame_SC_LAUNCH = new StateJS.State('LAUNCH', this._statemachine).entry(() => {
		setImmediate(() => {this.bus.emit('clock?timer_start', 0, this.BreakoutGame_period_var)});
		this.BreakoutGame_SC_LAUNCH_countdown_var = 3;
		this.drawScore();
		this.drawLives();
		this.bus.emit('display?update');
	});
	let BreakoutGame_SC_PLAY = new StateJS.State('PLAY', this._statemachine).entry(() => {
		setImmediate(() => {this.bus.emit('clock?timer_start', 0, this.BreakoutGame_period_var)});
	});
	let BreakoutGame_SC_LOSTBALL = new StateJS.State('LOSTBALL', this._statemachine).entry(() => {
		setImmediate(() => {this.bus.emit('clock?timer_start', 0, this.BreakoutGame_period_var)});
		this.BreakoutGame_lives_var = this.BreakoutGame_lives_var - 1;
		this.eraseBall();
		this.erasePad();
		this.drawLives();
		this.bus.emit('display?update');
		this.log(true);
	});
	let BreakoutGame_SC_NEXTLEVEL = new StateJS.State('NEXTLEVEL', this._statemachine).entry(() => {
		setImmediate(() => {this.bus.emit('clock?timer_start', 0, this.BreakoutGame_period_var)});
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
		this.bus.emit('display?update');
	});
	let BreakoutGame_SC_GAMEOVER = new StateJS.State('GAMEOVER', this._statemachine).entry(() => {
		this.eraseBall();
		this.erasePad();
		this.bus.emit('display?setColor', 255, 255, 255);
		this.bus.emit('display?fillRect', 8, 30, 142, 76);
		this.bus.emit('display?setColor', this.BreakoutGame_fgcolor_var[0]
		, this.BreakoutGame_fgcolor_var[1]
		, this.BreakoutGame_fgcolor_var[2]
		);
		this.bus.emit('display?fillRect', 9, 31, 140, 50);
		this.bus.emit('display?setBGColor', this.BreakoutGame_fgcolor_var[0]
		, this.BreakoutGame_fgcolor_var[1]
		, this.BreakoutGame_fgcolor_var[2]
		);
		this.bus.emit('display?setColor', 158, 209, 130);
		this.bus.emit('display?drawInteger', 23, 40, this.BreakoutGame_score_var, 5, 6);
		this.bus.emit('display?drawThingML', 26, 87);
		this.bus.emit('display?update');
		this.log(true);
		this.BreakoutGame_stopTime_var = this.timestamp();
		this.quit();
		setImmediate(()=>this._stop());
	});
	_initial_BreakoutGame_SC.to(BreakoutGame_SC_INIT);
	BreakoutGame_SC_PLAY.to(BreakoutGame_SC_NEXTLEVEL).when((nextLevel) => {
		return nextLevel._port === 'game' && nextLevel._msg === 'nextLevel';
	}).effect((nextLevel) => {
		setImmediate(() => {this.bus.emit('clock?timer_cancel', 0)});
	});
	BreakoutGame_SC_PLAY.to(BreakoutGame_SC_LOSTBALL).when((lostBall) => {
		return lostBall._port === 'game' && lostBall._msg === 'lostBall';
	}).effect((lostBall) => {
		setImmediate(() => {this.bus.emit('clock?timer_cancel', 0)});
	});
	BreakoutGame_SC_INIT.to(BreakoutGame_SC_LAUNCH).when((displayReady) => {
		return displayReady._port === 'display' && displayReady._msg === 'displayReady';
	}).effect((displayReady) => {
		this.bus.emit('display?clear');
		this.initColors();
		this.bus.emit('display?setColor', this.BreakoutGame_bgcolor_var[0]
		, this.BreakoutGame_bgcolor_var[1]
		, this.BreakoutGame_bgcolor_var[2]
		);
		this.bus.emit('display?fillRect', 0, 0, this.BreakoutGame_XDISPSIZE_var, this.BreakoutGame_YDISPSIZE_var);
		this.bus.emit('display?setColor', this.BreakoutGame_fgcolor_var[0]
		, this.BreakoutGame_fgcolor_var[1]
		, this.BreakoutGame_fgcolor_var[2]
		);
		this.bus.emit('display?fillRect', 0, 0, this.BreakoutGame_XDISPSIZE_var, 14);
		this.drawWalls();
		this.createBricks();
		this.drawLevel();
	});
	BreakoutGame_SC_PLAY.to(BreakoutGame_SC_NEXTLEVEL).when((nextLevel) => {
		return nextLevel._port === 'pro_game' && nextLevel._msg === 'nextLevel';
	}).effect((nextLevel) => {
		setImmediate(() => {this.bus.emit('clock?timer_cancel', 0)});
	});
	BreakoutGame_SC_PLAY.to(BreakoutGame_SC_LOSTBALL).when((lostBall) => {
		return lostBall._port === 'pro_game' && lostBall._msg === 'lostBall';
	}).effect((lostBall) => {
		setImmediate(() => {this.bus.emit('clock?timer_cancel', 0)});
	});
	this._statemachine.to(null).when((position) => {
		return position._port === 'controller' && position._msg === 'position';
	}).effect((position) => {
		let center_var = (this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var - this.BreakoutGame_padlen_var);
		center_var = position.x * center_var;
		center_var = Math.trunc(center_var / 200);
		this.BreakoutGame_padx_var = (this.BreakoutGame_LEFT_var + center_var + Math.trunc((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / 2));
	});
	BreakoutGame_SC_PLAY.to(null).when((timer_timeout) => {
		return timer_timeout._port === 'clock' && timer_timeout._msg === 'timer_timeout' && (timer_timeout.id === 0);
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
		setImmediate(() => {this.bus.emit('game?lostBall')});
		setImmediate(() => {this.bus.emit('req_game?lostBall')});
		
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
		setImmediate(() => {this.bus.emit('game?nextLevel')});
		setImmediate(() => {this.bus.emit('req_game?nextLevel')});
		
		}
		
		}
		this.drawBall();
		this.drawPad();
		setImmediate(() => {this.bus.emit('ia?updateIA', this.BreakoutGame_bx_var, this.BreakoutGame_by_var, this.BreakoutGame_padx_var, this.BreakoutGame_pady_var)});
		this.bus.emit('display?update');
		this.log(false);
		setImmediate(() => {this.bus.emit('clock?timer_start', 0, this.BreakoutGame_period_var)});
	});
	BreakoutGame_SC_LAUNCH.to(BreakoutGame_SC_PLAY).when((timer_timeout) => {
		return timer_timeout._port === 'clock' && timer_timeout._msg === 'timer_timeout' && (timer_timeout.id === 0 && this.BreakoutGame_SC_LAUNCH_countdown_var === 0);
	}).effect((timer_timeout) => {
		this.drawCountDown(0);
		this.resetBall();
		this.bus.emit('display?update');
	});
	BreakoutGame_SC_LAUNCH.to(null).when((timer_timeout) => {
		return timer_timeout._port === 'clock' && timer_timeout._msg === 'timer_timeout' && (timer_timeout.id === 0 && this.BreakoutGame_SC_LAUNCH_countdown_var > 0);
	}).effect((timer_timeout) => {
		setImmediate(() => {this.bus.emit('clock?timer_start', 0, this.BreakoutGame_period_var)});
		this.drawPad();
		if((this.BreakoutGame_SC_LAUNCH_countdown_var % 30) === 0) {
		this.drawCountDown(Math.trunc(this.BreakoutGame_SC_LAUNCH_countdown_var / 30));
		
		}
		this.BreakoutGame_SC_LAUNCH_countdown_var = this.BreakoutGame_SC_LAUNCH_countdown_var - 1;
		this.bus.emit('display?update');
	});
	BreakoutGame_SC_LOSTBALL.to(BreakoutGame_SC_LAUNCH).when((timer_timeout) => {
		return timer_timeout._port === 'clock' && timer_timeout._msg === 'timer_timeout' && (timer_timeout.id === 0 && this.BreakoutGame_lives_var > 0);
	});
	BreakoutGame_SC_LOSTBALL.to(BreakoutGame_SC_GAMEOVER).when((timer_timeout) => {
		return timer_timeout._port === 'clock' && timer_timeout._msg === 'timer_timeout' && (timer_timeout.id === 0 && this.BreakoutGame_lives_var === 0);
	});
	BreakoutGame_SC_NEXTLEVEL.to(BreakoutGame_SC_LAUNCH).when((timer_timeout) => {
		return timer_timeout._port === 'clock' && timer_timeout._msg === 'timer_timeout' && (timer_timeout.id === 0);
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
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'ts:');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+ts_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+',lives:');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+this.BreakoutGame_lives_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+',score:');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+this.BreakoutGame_score_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+',level:');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+this.BreakoutGame_level_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+',bx:');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+this.BreakoutGame_bx_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+',by:');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+this.BreakoutGame_by_var);
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+',padx:');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+this.BreakoutGame_padx_var);
	if (process.stdout) process.stdout.write('\n');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'#usedMem:');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+this.usedMemory());
	if (process.stdout) process.stdout.write('\n');
	
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
	this.bus.emit('display?setBGColor', this.BreakoutGame_bgcolor_var[0]
	, this.BreakoutGame_bgcolor_var[1]
	, this.BreakoutGame_bgcolor_var[2]
	);
	this.bus.emit('display?setColor', this.BreakoutGame_fgcolor_var[0]
	, this.BreakoutGame_fgcolor_var[1]
	, this.BreakoutGame_fgcolor_var[2]
	);
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
	this.bus.emit('display?setColor', this.BreakoutGame_bgcolor_var[0]
	, this.BreakoutGame_bgcolor_var[1]
	, this.BreakoutGame_bgcolor_var[2]
	);
	this.bus.emit('display?fillRect', this.BreakoutGame_prevBX_var, this.BreakoutGame_prevBY_var, bs_var, bs_var);
	
	}
	this.BreakoutGame_prevBX_var =  -1;
	this.BreakoutGame_prevBY_var =  -1;
}

BreakoutGameNodeJS.prototype.drawBall = function() {
	let bs_var = Math.trunc((this.BreakoutGame_br_var * 2) / this.BreakoutGame_SCALE_var);
	this.eraseBall();
	this.BreakoutGame_prevBX_var = Math.trunc((this.BreakoutGame_bx_var - this.BreakoutGame_br_var) / this.BreakoutGame_SCALE_var);
	this.BreakoutGame_prevBY_var = Math.trunc((this.BreakoutGame_by_var - this.BreakoutGame_br_var) / this.BreakoutGame_SCALE_var);
	this.bus.emit('display?setColor', 183, 199, 111);
	this.bus.emit('display?fillRect', this.BreakoutGame_prevBX_var, this.BreakoutGame_prevBY_var, bs_var, bs_var);
}

BreakoutGameNodeJS.prototype.erasePad = function() {
	let ps_var = Math.trunc(this.BreakoutGame_padlen_var / this.BreakoutGame_SCALE_var);
	if(this.BreakoutGame_prevPX_var > 0) {
	this.bus.emit('display?setColor', this.BreakoutGame_bgcolor_var[0]
	, this.BreakoutGame_bgcolor_var[1]
	, this.BreakoutGame_bgcolor_var[2]
	);
	this.bus.emit('display?fillRect', this.BreakoutGame_prevPX_var, this.BreakoutGame_prevPY_var, ps_var, 4);
	
	}
}

BreakoutGameNodeJS.prototype.drawPad = function() {
	let ps_var = Math.trunc(this.BreakoutGame_padlen_var / this.BreakoutGame_SCALE_var);
	this.erasePad();
	this.BreakoutGame_prevPX_var = Math.trunc((this.BreakoutGame_padx_var - (Math.trunc(this.BreakoutGame_padlen_var / 2))) / this.BreakoutGame_SCALE_var);
	this.BreakoutGame_prevPY_var = Math.trunc(this.BreakoutGame_pady_var / this.BreakoutGame_SCALE_var);
	this.bus.emit('display?setColor', this.BreakoutGame_fgcolor_var[0]
	, this.BreakoutGame_fgcolor_var[1]
	, this.BreakoutGame_fgcolor_var[2]
	);
	this.bus.emit('display?fillRect', this.BreakoutGame_prevPX_var, this.BreakoutGame_prevPY_var, ps_var, 4);
}

BreakoutGameNodeJS.prototype.drawCountDown = function(BreakoutGame_drawCountDown_c_var) {
	this.bus.emit('display?setColor', this.BreakoutGame_fgcolor_var[0]
	, this.BreakoutGame_fgcolor_var[1]
	, this.BreakoutGame_fgcolor_var[2]
	);
	if(BreakoutGame_drawCountDown_c_var > 0) {
	this.bus.emit('display?setColor', this.BreakoutGame_fgcolor_var[0]
	, this.BreakoutGame_fgcolor_var[1]
	, this.BreakoutGame_fgcolor_var[2]
	);
	this.bus.emit('display?setBGColor', this.BreakoutGame_bgcolor_var[0]
	, this.BreakoutGame_bgcolor_var[1]
	, this.BreakoutGame_bgcolor_var[2]
	);
	this.bus.emit('display?drawInteger', 80 - 6, 90, BreakoutGame_drawCountDown_c_var, 1, 4);
	
	} else {
	this.bus.emit('display?setColor', this.BreakoutGame_bgcolor_var[0]
	, this.BreakoutGame_bgcolor_var[1]
	, this.BreakoutGame_bgcolor_var[2]
	);
	this.bus.emit('display?fillRect', 80 - 6, 90, 12, 20);
	
	}
}

BreakoutGameNodeJS.prototype.drawWalls = function() {
	this.bus.emit('display?setColor', this.BreakoutGame_fgcolor_var[0]
	, this.BreakoutGame_fgcolor_var[1]
	, this.BreakoutGame_fgcolor_var[2]
	);
	const left_var = (Math.trunc(this.BreakoutGame_LEFT_var / this.BreakoutGame_SCALE_var));
	const right_var = (Math.trunc(this.BreakoutGame_RIGHT_var / this.BreakoutGame_SCALE_var));
	const top_var = (Math.trunc(this.BreakoutGame_TOP_var / this.BreakoutGame_SCALE_var));
	const bottom_var = (Math.trunc(this.BreakoutGame_BOTTOM_var / this.BreakoutGame_SCALE_var));
	const xcenter_var = (Math.trunc((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / this.BreakoutGame_SCALE_var));
	const ycenter_var = (Math.trunc((this.BreakoutGame_BOTTOM_var - this.BreakoutGame_TOP_var) / this.BreakoutGame_SCALE_var));
	this.bus.emit('display?fillRect', left_var - 1, top_var - 1, xcenter_var + 1, 1);
	this.bus.emit('display?fillRect', left_var - 1, bottom_var, xcenter_var + 1, 1);
	this.bus.emit('display?fillRect', left_var - 1, top_var, 1, ycenter_var);
	this.bus.emit('display?fillRect', right_var, top_var, 1, ycenter_var);
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
	if(this.bitIsSet(this.BreakoutGame_bricks_var[y_var]
	, x_var)) {
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
	if(this.bitIsSet(this.BreakoutGame_bricks_var[y_var]
	, x_var)) {
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
	this.bus.emit('display?setColor', 155, 103, 89);
	this.bus.emit('display?fillRect', bx_var, by_var, w_var, h_var);
	this.bus.emit('display?setColor', 100, 56, 43);
	this.bus.emit('display?drawRect', bx_var, by_var, w_var, h_var);
}

BreakoutGameNodeJS.prototype.removeBrick = function(BreakoutGame_removeBrick_x_var, BreakoutGame_removeBrick_y_var) {
	const bx_var = (Math.trunc((this.BreakoutGame_LEFT_var + (Math.trunc((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / 8)) * BreakoutGame_removeBrick_x_var) / this.BreakoutGame_SCALE_var) + 1);
	const by_var = (Math.trunc((this.BreakoutGame_TOP_var + 20 * this.BreakoutGame_SCALE_var + this.BreakoutGame_BRICK_HEIGHT_var * BreakoutGame_removeBrick_y_var * this.BreakoutGame_SCALE_var) / this.BreakoutGame_SCALE_var) + 1);
	this.bus.emit('display?setColor', this.BreakoutGame_bgcolor_var[0]
	, this.BreakoutGame_bgcolor_var[1]
	, this.BreakoutGame_bgcolor_var[2]
	);
	this.bus.emit('display?fillRect', bx_var, by_var, (Math.trunc((Math.trunc((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / 8)) / this.BreakoutGame_SCALE_var) - 2), this.BreakoutGame_BRICK_HEIGHT_var - 2);
	this.BreakoutGame_bricks_var[BreakoutGame_removeBrick_y_var] = this.unsetBit(this.BreakoutGame_bricks_var[BreakoutGame_removeBrick_y_var]
	, BreakoutGame_removeBrick_x_var);
}

BreakoutGameNodeJS.prototype.collideBrick = function(BreakoutGame_collideBrick_xpos_var, BreakoutGame_collideBrick_ypos_var) {
	let bry_var = Math.trunc((BreakoutGame_collideBrick_ypos_var - this.BreakoutGame_TOP_var - 20 * this.BreakoutGame_SCALE_var) / (this.BreakoutGame_BRICK_HEIGHT_var * this.BreakoutGame_SCALE_var));
	let result_var = false;
	if(bry_var >= 0 && bry_var < this.BreakoutGame_BRICK_ROWS_var) {
	let brx_var = Math.trunc((BreakoutGame_collideBrick_xpos_var - this.BreakoutGame_LEFT_var) / (Math.trunc((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / 8)));
	if(this.bitIsSet(this.BreakoutGame_bricks_var[bry_var]
	, brx_var)) {
	this.removeBrick(brx_var, bry_var);
	result_var = true;
	
	}
	
	}
	return result_var;
}

BreakoutGameNodeJS.prototype.drawLevel = function() {
	this.bus.emit('display?setColor', 158, 209, 130);
	this.bus.emit('display?setBGColor', this.BreakoutGame_fgcolor_var[0]
	, this.BreakoutGame_fgcolor_var[1]
	, this.BreakoutGame_fgcolor_var[2]
	);
	this.bus.emit('display?setColor', this.BreakoutGame_bgcolor_var[0]
	, this.BreakoutGame_bgcolor_var[1]
	, this.BreakoutGame_bgcolor_var[2]
	);
	this.bus.emit('display?drawInteger', 6, 2, this.BreakoutGame_level_var, 2, 2);
}

BreakoutGameNodeJS.prototype.incrementScore = function(BreakoutGame_incrementScore_diff_var) {
	this.BreakoutGame_score_var = this.BreakoutGame_score_var + BreakoutGame_incrementScore_diff_var;
	if(this.BreakoutGame_score_var < 0) {
	this.BreakoutGame_score_var = 0;
	
	}
	this.drawScore();
}

BreakoutGameNodeJS.prototype.drawScore = function() {
	this.bus.emit('display?setColor', 158, 209, 130);
	this.bus.emit('display?setBGColor', this.BreakoutGame_fgcolor_var[0]
	, this.BreakoutGame_fgcolor_var[1]
	, this.BreakoutGame_fgcolor_var[2]
	);
	this.bus.emit('display?drawInteger', 58, 2, this.BreakoutGame_score_var, 5, 2);
}

BreakoutGameNodeJS.prototype.drawLives = function() {
	this.bus.emit('display?setColor', this.BreakoutGame_fgcolor_var[0]
	, this.BreakoutGame_fgcolor_var[1]
	, this.BreakoutGame_fgcolor_var[2]
	);
	this.bus.emit('display?fillRect', 124, 4, 24 + 6, 6);
	this.bus.emit('display?setColor', 183, 199, 111);
	let i_var = 0;
	while(i_var < this.BreakoutGame_lives_var) {
	this.bus.emit('display?fillRect', 124 + (2 - i_var) * 12, 4, 6, 6);
	i_var = i_var + 1;
	
	}
}

BreakoutGameNodeJS.prototype.quit = function() {
	if (global.gc) {
		global.gc();
	}
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'>done in ');
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+(Number(this.BreakoutGame_stopTime_var) - Number(this.BreakoutGame_startTime_var)));
	((process.stdout && process.stdout.write) || console.log).call(process.stdout, ''+'ms!');
	if (process.stdout) process.stdout.write('\n');
	this.log(true);
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
	/*msg = {_port:myPort, _msg:myMessage, paramN=paramN, ...}*/
	if (this.ready) {
		this._SC_instance.evaluate(msg);
	} else {
		setTimeout(()=>this._receive(msg),0);
	}
}

BreakoutGameNodeJS.prototype.receivetimer_timeoutOnclock = function(id) {
	this._receive({_port:"clock", _msg:"timer_timeout", id:id});
}

BreakoutGameNodeJS.prototype.receivedisplayReadyOndisplay = function() {
	this._receive({_port:"display", _msg:"displayReady"});
}

BreakoutGameNodeJS.prototype.receivepositionOncontroller = function(x, y) {
	this._receive({_port:"controller", _msg:"position", x:x, y:y});
}

BreakoutGameNodeJS.prototype.receivelostBallOngame = function() {
	this._receive({_port:"game", _msg:"lostBall"});
}

BreakoutGameNodeJS.prototype.receivenextLevelOngame = function() {
	this._receive({_port:"game", _msg:"nextLevel"});
}

BreakoutGameNodeJS.prototype.receivelostBallOnpro_game = function() {
	this._receive({_port:"pro_game", _msg:"lostBall"});
}

BreakoutGameNodeJS.prototype.receivenextLevelOnpro_game = function() {
	this._receive({_port:"pro_game", _msg:"nextLevel"});
}

BreakoutGameNodeJS.prototype.initBreakoutGame_XMAX_var = function(BreakoutGame_XMAX_var) {
	this.BreakoutGame_XMAX_var = BreakoutGame_XMAX_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_counter_var = function(BreakoutGame_counter_var) {
	this.BreakoutGame_counter_var = BreakoutGame_counter_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_lastTimestamp_var = function(BreakoutGame_lastTimestamp_var) {
	this.BreakoutGame_lastTimestamp_var = BreakoutGame_lastTimestamp_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_TOP_var = function(BreakoutGame_TOP_var) {
	this.BreakoutGame_TOP_var = BreakoutGame_TOP_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_prevPX_var = function(BreakoutGame_prevPX_var) {
	this.BreakoutGame_prevPX_var = BreakoutGame_prevPX_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_br_var = function(BreakoutGame_br_var) {
	this.BreakoutGame_br_var = BreakoutGame_br_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_RIGHT_var = function(BreakoutGame_RIGHT_var) {
	this.BreakoutGame_RIGHT_var = BreakoutGame_RIGHT_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_lives_var = function(BreakoutGame_lives_var) {
	this.BreakoutGame_lives_var = BreakoutGame_lives_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_stopTime_var = function(BreakoutGame_stopTime_var) {
	this.BreakoutGame_stopTime_var = BreakoutGame_stopTime_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_bx_var = function(BreakoutGame_bx_var) {
	this.BreakoutGame_bx_var = BreakoutGame_bx_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_prevBX_var = function(BreakoutGame_prevBX_var) {
	this.BreakoutGame_prevBX_var = BreakoutGame_prevBX_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_startTime_var = function(BreakoutGame_startTime_var) {
	this.BreakoutGame_startTime_var = BreakoutGame_startTime_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_dx_var = function(BreakoutGame_dx_var) {
	this.BreakoutGame_dx_var = BreakoutGame_dx_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_padx_var = function(BreakoutGame_padx_var) {
	this.BreakoutGame_padx_var = BreakoutGame_padx_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_BOTTOM_var = function(BreakoutGame_BOTTOM_var) {
	this.BreakoutGame_BOTTOM_var = BreakoutGame_BOTTOM_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_fgcolor_var = function(BreakoutGame_fgcolor_var) {
	this.BreakoutGame_fgcolor_var = BreakoutGame_fgcolor_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_dy_var = function(BreakoutGame_dy_var) {
	this.BreakoutGame_dy_var = BreakoutGame_dy_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_YDISPSIZE_var = function(BreakoutGame_YDISPSIZE_var) {
	this.BreakoutGame_YDISPSIZE_var = BreakoutGame_YDISPSIZE_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_bgcolor_var = function(BreakoutGame_bgcolor_var) {
	this.BreakoutGame_bgcolor_var = BreakoutGame_bgcolor_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_level_var = function(BreakoutGame_level_var) {
	this.BreakoutGame_level_var = BreakoutGame_level_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_prevBY_var = function(BreakoutGame_prevBY_var) {
	this.BreakoutGame_prevBY_var = BreakoutGame_prevBY_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_pady_var = function(BreakoutGame_pady_var) {
	this.BreakoutGame_pady_var = BreakoutGame_pady_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_bricks_var = function(BreakoutGame_bricks_var) {
	this.BreakoutGame_bricks_var = BreakoutGame_bricks_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_padlen_var = function(BreakoutGame_padlen_var) {
	this.BreakoutGame_padlen_var = BreakoutGame_padlen_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_XDISPSIZE_var = function(BreakoutGame_XDISPSIZE_var) {
	this.BreakoutGame_XDISPSIZE_var = BreakoutGame_XDISPSIZE_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_period_var = function(BreakoutGame_period_var) {
	this.BreakoutGame_period_var = BreakoutGame_period_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_prevPY_var = function(BreakoutGame_prevPY_var) {
	this.BreakoutGame_prevPY_var = BreakoutGame_prevPY_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_BRICK_ROWS_var = function(BreakoutGame_BRICK_ROWS_var) {
	this.BreakoutGame_BRICK_ROWS_var = BreakoutGame_BRICK_ROWS_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_LEFT_var = function(BreakoutGame_LEFT_var) {
	this.BreakoutGame_LEFT_var = BreakoutGame_LEFT_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_by_var = function(BreakoutGame_by_var) {
	this.BreakoutGame_by_var = BreakoutGame_by_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_SC_LAUNCH_countdown_var = function(BreakoutGame_SC_LAUNCH_countdown_var) {
	this.BreakoutGame_SC_LAUNCH_countdown_var = BreakoutGame_SC_LAUNCH_countdown_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_score_var = function(BreakoutGame_score_var) {
	this.BreakoutGame_score_var = BreakoutGame_score_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_SCALE_var = function(BreakoutGame_SCALE_var) {
	this.BreakoutGame_SCALE_var = BreakoutGame_SCALE_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_YMAX_var = function(BreakoutGame_YMAX_var) {
	this.BreakoutGame_YMAX_var = BreakoutGame_YMAX_var;
}

BreakoutGameNodeJS.prototype.initBreakoutGame_BRICK_HEIGHT_var = function(BreakoutGame_BRICK_HEIGHT_var) {
	this.BreakoutGame_BRICK_HEIGHT_var = BreakoutGame_BRICK_HEIGHT_var;
}

BreakoutGameNodeJS.prototype.toString = function() {
	let result = 'instance ' + this.name + ':' + this.constructor.name + '\n';
	result += '\n\tXMAX = ' + this.BreakoutGame_XMAX_var;
	result += '\n\tcounter = ' + this.BreakoutGame_counter_var;
	result += '\n\tlastTimestamp = ' + this.BreakoutGame_lastTimestamp_var;
	result += '\n\tTOP = ' + this.BreakoutGame_TOP_var;
	result += '\n\tprevPX = ' + this.BreakoutGame_prevPX_var;
	result += '\n\tbr = ' + this.BreakoutGame_br_var;
	result += '\n\tRIGHT = ' + this.BreakoutGame_RIGHT_var;
	result += '\n\tlives = ' + this.BreakoutGame_lives_var;
	result += '\n\tstopTime = ' + this.BreakoutGame_stopTime_var;
	result += '\n\tbx = ' + this.BreakoutGame_bx_var;
	result += '\n\tprevBX = ' + this.BreakoutGame_prevBX_var;
	result += '\n\tstartTime = ' + this.BreakoutGame_startTime_var;
	result += '\n\tdx = ' + this.BreakoutGame_dx_var;
	result += '\n\tpadx = ' + this.BreakoutGame_padx_var;
	result += '\n\tBOTTOM = ' + this.BreakoutGame_BOTTOM_var;
	result += '\n\tfgcolor = ' + this.BreakoutGame_fgcolor_var;
	result += '\n\tdy = ' + this.BreakoutGame_dy_var;
	result += '\n\tYDISPSIZE = ' + this.BreakoutGame_YDISPSIZE_var;
	result += '\n\tbgcolor = ' + this.BreakoutGame_bgcolor_var;
	result += '\n\tlevel = ' + this.BreakoutGame_level_var;
	result += '\n\tprevBY = ' + this.BreakoutGame_prevBY_var;
	result += '\n\tpady = ' + this.BreakoutGame_pady_var;
	result += '\n\tbricks = ' + this.BreakoutGame_bricks_var;
	result += '\n\tpadlen = ' + this.BreakoutGame_padlen_var;
	result += '\n\tXDISPSIZE = ' + this.BreakoutGame_XDISPSIZE_var;
	result += '\n\tperiod = ' + this.BreakoutGame_period_var;
	result += '\n\tprevPY = ' + this.BreakoutGame_prevPY_var;
	result += '\n\tBRICK_ROWS = ' + this.BreakoutGame_BRICK_ROWS_var;
	result += '\n\tLEFT = ' + this.BreakoutGame_LEFT_var;
	result += '\n\tby = ' + this.BreakoutGame_by_var;
	result += '\n\tcountdown = ' + this.BreakoutGame_SC_LAUNCH_countdown_var;
	result += '\n\tscore = ' + this.BreakoutGame_score_var;
	result += '\n\tSCALE = ' + this.BreakoutGame_SCALE_var;
	result += '\n\tYMAX = ' + this.BreakoutGame_YMAX_var;
	result += '\n\tBRICK_HEIGHT = ' + this.BreakoutGame_BRICK_HEIGHT_var;
	result += '';
	return result;
}

module.exports = BreakoutGameNodeJS;
