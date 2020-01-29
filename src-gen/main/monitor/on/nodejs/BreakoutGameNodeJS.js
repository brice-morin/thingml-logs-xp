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
		const xsize_172_var = this.BreakoutGame_XDISPSIZE_var;
		const ysize_173_var = this.BreakoutGame_YDISPSIZE_var;
		this.bus.emit('display', new Event.Create_DisplayMsgs(this.name, 'display', xsize_172_var, ysize_173_var));
		const params_174_var = '' + ('xsize=' + (xsize_172_var + ',')) + ('ysize=' + (ysize_173_var + ','));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'create', params_174_var));
	});
	let BreakoutGame_SC_LAUNCH = new StateJS.State('LAUNCH', this._statemachine).entry(() => {
		const id_193_var = 0;
		const time_194_var = this.BreakoutGame_period_var;
		this.bus.emit('clock', new Event.Timer_start_TimerMsgs(this.name, 'clock', id_193_var, time_194_var));
		const params_195_var = '' + ('id=' + (id_193_var + ',')) + ('time=' + (time_194_var + ','));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'clock', 'timer_start', params_195_var));
		const old_countdown_14_var = '' + this.BreakoutGame_SC_LAUNCH_countdown_var;
		this.BreakoutGame_SC_LAUNCH_countdown_var = 3;
		const new_countdown_14_var = '' + this.BreakoutGame_SC_LAUNCH_countdown_var;
		this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'countdown', 'UInt8', old_countdown_14_var, new_countdown_14_var));
		this.drawScore();
		this.drawLives();
		this.bus.emit('display', new Event.Update_DisplayMsgs(this.name, 'display'));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'update', ''));
	});
	let BreakoutGame_SC_PLAY = new StateJS.State('PLAY', this._statemachine).entry(() => {
		const id_199_var = 0;
		const time_200_var = this.BreakoutGame_period_var;
		this.bus.emit('clock', new Event.Timer_start_TimerMsgs(this.name, 'clock', id_199_var, time_200_var));
		const params_201_var = '' + ('id=' + (id_199_var + ',')) + ('time=' + (time_200_var + ','));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'clock', 'timer_start', params_201_var));
	});
	let BreakoutGame_SC_LOSTBALL = new StateJS.State('LOSTBALL', this._statemachine).entry(() => {
		const id_218_var = 0;
		const time_219_var = this.BreakoutGame_period_var;
		this.bus.emit('clock', new Event.Timer_start_TimerMsgs(this.name, 'clock', id_218_var, time_219_var));
		const params_220_var = '' + ('id=' + (id_218_var + ',')) + ('time=' + (time_219_var + ','));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'clock', 'timer_start', params_220_var));
		const old_lives_11_var = '' + this.BreakoutGame_lives_var;
		this.BreakoutGame_lives_var = this.BreakoutGame_lives_var - 1;
		const new_lives_11_var = '' + this.BreakoutGame_lives_var;
		this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'lives', 'UInt8', old_lives_11_var, new_lives_11_var));
		this.eraseBall();
		this.erasePad();
		this.drawLives();
		this.bus.emit('display', new Event.Update_DisplayMsgs(this.name, 'display'));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'update', ''));
		this.log(true);
	});
	let BreakoutGame_SC_NEXTLEVEL = new StateJS.State('NEXTLEVEL', this._statemachine).entry(() => {
		const id_221_var = 0;
		const time_222_var = this.BreakoutGame_period_var;
		this.bus.emit('clock', new Event.Timer_start_TimerMsgs(this.name, 'clock', id_221_var, time_222_var));
		const params_223_var = '' + ('id=' + (id_221_var + ',')) + ('time=' + (time_222_var + ','));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'clock', 'timer_start', params_223_var));
		const old_level_3_var = '' + this.BreakoutGame_level_var;
		this.BreakoutGame_level_var = this.BreakoutGame_level_var + 1;
		const new_level_3_var = '' + this.BreakoutGame_level_var;
		this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'level', 'UInt8', old_level_3_var, new_level_3_var));
		this.drawLevel();
		this.eraseBall();
		this.erasePad();
		if((this.BreakoutGame_level_var % 2) === 0 && this.BreakoutGame_padlen_var > 5 * this.BreakoutGame_SCALE_var) {
		const old_padlen_12_var = '' + this.BreakoutGame_padlen_var;
		this.BreakoutGame_padlen_var = this.BreakoutGame_padlen_var - (4 * this.BreakoutGame_SCALE_var);
		const new_padlen_12_var = '' + this.BreakoutGame_padlen_var;
		this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'padlen', 'Int16', old_padlen_12_var, new_padlen_12_var));
		
		}
		if((this.BreakoutGame_level_var % 2) === 1) {
		const old_dy_28_var = '' + this.BreakoutGame_dy_var;
		this.BreakoutGame_dy_var = Math.trunc((this.BreakoutGame_dy_var * 3) / 2);
		const new_dy_28_var = '' + this.BreakoutGame_dy_var;
		this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'dy', 'Int16', old_dy_28_var, new_dy_28_var));
		
		}
		this.drawLives();
		this.createBricks();
		this.bus.emit('display', new Event.Update_DisplayMsgs(this.name, 'display'));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'update', ''));
	});
	let BreakoutGame_SC_GAMEOVER = new StateJS.State('GAMEOVER', this._statemachine).entry(() => {
		this.eraseBall();
		this.erasePad();
		const r_224_var = 255;
		const g_225_var = 255;
		const b_226_var = 255;
		this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_224_var, g_225_var, b_226_var));
		const params_227_var = '' + ('r=' + (r_224_var + ',')) + ('g=' + (g_225_var + ',')) + ('b=' + (b_226_var + ','));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'setColor', params_227_var));
		const x_228_var = 8;
		const y_229_var = 30;
		const width_230_var = 142;
		const height_231_var = 76;
		this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_228_var, y_229_var, width_230_var, height_231_var));
		const params_232_var = '' + ('x=' + (x_228_var + ',')) + ('y=' + (y_229_var + ',')) + ('width=' + (width_230_var + ',')) + ('height=' + (height_231_var + ','));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'fillRect', params_232_var));
		const r_233_var = this.BreakoutGame_fgcolor_var[0];
		const g_234_var = this.BreakoutGame_fgcolor_var[1];
		const b_235_var = this.BreakoutGame_fgcolor_var[2];
		this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_233_var, g_234_var, b_235_var));
		const params_236_var = '' + ('r=' + (r_233_var + ',')) + ('g=' + (g_234_var + ',')) + ('b=' + (b_235_var + ','));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'setColor', params_236_var));
		const x_237_var = 9;
		const y_238_var = 31;
		const width_239_var = 140;
		const height_240_var = 50;
		this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_237_var, y_238_var, width_239_var, height_240_var));
		const params_241_var = '' + ('x=' + (x_237_var + ',')) + ('y=' + (y_238_var + ',')) + ('width=' + (width_239_var + ',')) + ('height=' + (height_240_var + ','));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'fillRect', params_241_var));
		const r_242_var = this.BreakoutGame_fgcolor_var[0];
		const g_243_var = this.BreakoutGame_fgcolor_var[1];
		const b_244_var = this.BreakoutGame_fgcolor_var[2];
		this.bus.emit('display', new Event.SetBGColor_DisplayMsgs(this.name, 'display', r_242_var, g_243_var, b_244_var));
		const params_245_var = '' + ('r=' + (r_242_var + ',')) + ('g=' + (g_243_var + ',')) + ('b=' + (b_244_var + ','));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'setBGColor', params_245_var));
		const r_246_var = 158;
		const g_247_var = 209;
		const b_248_var = 130;
		this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_246_var, g_247_var, b_248_var));
		const params_249_var = '' + ('r=' + (r_246_var + ',')) + ('g=' + (g_247_var + ',')) + ('b=' + (b_248_var + ','));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'setColor', params_249_var));
		const x_250_var = 23;
		const y_251_var = 40;
		const v_252_var = this.BreakoutGame_score_var;
		const digits_253_var = 5;
		const scale_254_var = 6;
		this.bus.emit('display', new Event.DrawInteger_DisplayMsgs(this.name, 'display', x_250_var, y_251_var, v_252_var, digits_253_var, scale_254_var));
		const params_255_var = '' + ('x=' + (x_250_var + ',')) + ('y=' + (y_251_var + ',')) + ('v=' + (v_252_var + ',')) + ('digits=' + (digits_253_var + ',')) + ('scale=' + (scale_254_var + ','));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'drawInteger', params_255_var));
		const x_256_var = 26;
		const y_257_var = 87;
		this.bus.emit('display', new Event.DrawThingML_DisplayMsgs(this.name, 'display', x_256_var, y_257_var));
		const params_258_var = '' + ('x=' + (x_256_var + ',')) + ('y=' + (y_257_var + ','));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'drawThingML', params_258_var));
		this.bus.emit('display', new Event.Update_DisplayMsgs(this.name, 'display'));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'update', ''));
		this.log(true);
		this.BreakoutGame_stopTime_var = this.timestamp();
		this.quit();
		setImmediate(()=>this._stop());
	});
	_initial_BreakoutGame_SC.to(BreakoutGame_SC_INIT);
	BreakoutGame_SC_PLAY.to(BreakoutGame_SC_LOSTBALL).on(Event.LostBall_BreakoutGame).when((lostBall) => {
		return lostBall.port === 'game' && lostBall.type === 'lostBall';
	}).effect((lostBall) => {
		this.bus.emit('log', new Event.Message_handled_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'SC.PLAY', 'SC.LOSTBALL', 'game', 'lostBall', '_'));
		const id_210_var = 0;
		this.bus.emit('clock', new Event.Timer_cancel_TimerMsgs(this.name, 'clock', id_210_var));
		const params_211_var = '' + ('id=' + (id_210_var + ','));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'clock', 'timer_cancel', params_211_var));
	});
	this._statemachine.on(Event.LostBall).when((lostBall) => {
		return lostBall.port === 'game' && lostBall.type === 'lostBall' && (true);
	}).effect((lostBall) => {
		this.bus.emit('log', new Event.Message_lost_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'game', 'lostBall', ''));
	});
	BreakoutGame_SC_PLAY.to(BreakoutGame_SC_NEXTLEVEL).on(Event.NextLevel_BreakoutGame).when((nextLevel) => {
		return nextLevel.port === 'game' && nextLevel.type === 'nextLevel';
	}).effect((nextLevel) => {
		this.bus.emit('log', new Event.Message_handled_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'SC.PLAY', 'SC.NEXTLEVEL', 'game', 'nextLevel', '_'));
		const id_212_var = 0;
		this.bus.emit('clock', new Event.Timer_cancel_TimerMsgs(this.name, 'clock', id_212_var));
		const params_213_var = '' + ('id=' + (id_212_var + ','));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'clock', 'timer_cancel', params_213_var));
	});
	this._statemachine.on(Event.NextLevel).when((nextLevel) => {
		return nextLevel.port === 'game' && nextLevel.type === 'nextLevel' && (true);
	}).effect((nextLevel) => {
		this.bus.emit('log', new Event.Message_lost_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'game', 'nextLevel', ''));
	});
	this._statemachine.on(Event.Position).when((position) => {
		return position.port === 'controller' && position.type === 'position';
	}).effect((position) => {
		const params_var = '' + ('x=' + (position.x + ',')) + ('y=' + (position.y + ','));
		this.bus.emit('log', new Event.Message_handled_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'SC', '_', 'controller', 'position', params_var));
		let center_var = (this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var - this.BreakoutGame_padlen_var);
		center_var = position.x * center_var;
		center_var = Math.trunc(center_var / 200);
		const old_padx_8_var = '' + this.BreakoutGame_padx_var;
		this.BreakoutGame_padx_var = (this.BreakoutGame_LEFT_var + center_var + Math.trunc((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / 2));
		const new_padx_8_var = '' + this.BreakoutGame_padx_var;
		this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'padx', 'Int16', old_padx_8_var, new_padx_8_var));
	});
	this._statemachine.on(Event.DisplayReady).when((displayReady) => {
		return displayReady.port === 'display' && displayReady.type === 'displayReady' && (true);
	}).effect((displayReady) => {
		this.bus.emit('log', new Event.Message_lost_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'displayReady', ''));
	});
	BreakoutGame_SC_INIT.to(BreakoutGame_SC_LAUNCH).on(Event.DisplayReady_DisplayMsgs).when((displayReady) => {
		return displayReady.port === 'display' && displayReady.type === 'displayReady';
	}).effect((displayReady) => {
		this.bus.emit('log', new Event.Message_handled_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'SC.INIT', 'SC.LAUNCH', 'display', 'displayReady', '_'));
		this.bus.emit('display', new Event.Clear_DisplayMsgs(this.name, 'display'));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'clear', ''));
		this.initColors();
		const r_175_var = this.BreakoutGame_bgcolor_var[0];
		const g_176_var = this.BreakoutGame_bgcolor_var[1];
		const b_177_var = this.BreakoutGame_bgcolor_var[2];
		this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_175_var, g_176_var, b_177_var));
		const params_178_var = '' + ('r=' + (r_175_var + ',')) + ('g=' + (g_176_var + ',')) + ('b=' + (b_177_var + ','));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'setColor', params_178_var));
		const x_179_var = 0;
		const y_180_var = 0;
		const width_181_var = this.BreakoutGame_XDISPSIZE_var;
		const height_182_var = this.BreakoutGame_YDISPSIZE_var;
		this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_179_var, y_180_var, width_181_var, height_182_var));
		const params_183_var = '' + ('x=' + (x_179_var + ',')) + ('y=' + (y_180_var + ',')) + ('width=' + (width_181_var + ',')) + ('height=' + (height_182_var + ','));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'fillRect', params_183_var));
		const r_184_var = this.BreakoutGame_fgcolor_var[0];
		const g_185_var = this.BreakoutGame_fgcolor_var[1];
		const b_186_var = this.BreakoutGame_fgcolor_var[2];
		this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_184_var, g_185_var, b_186_var));
		const params_187_var = '' + ('r=' + (r_184_var + ',')) + ('g=' + (g_185_var + ',')) + ('b=' + (b_186_var + ','));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'setColor', params_187_var));
		const x_188_var = 0;
		const y_189_var = 0;
		const width_190_var = this.BreakoutGame_XDISPSIZE_var;
		const height_191_var = 14;
		this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_188_var, y_189_var, width_190_var, height_191_var));
		const params_192_var = '' + ('x=' + (x_188_var + ',')) + ('y=' + (y_189_var + ',')) + ('width=' + (width_190_var + ',')) + ('height=' + (height_191_var + ','));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'fillRect', params_192_var));
		this.drawWalls();
		this.createBricks();
		this.drawLevel();
	});
	BreakoutGame_SC_PLAY.on(Event.Timer_timeout).when((timer_timeout) => {
		return timer_timeout.port === 'clock' && timer_timeout.type === 'timer_timeout' && (timer_timeout.id === 0);
	}).effect((timer_timeout) => {
		const params_var = '' + ('id=' + (timer_timeout.id + ','));
		this.bus.emit('log', new Event.Message_handled_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'SC.PLAY', '_', 'clock', 'timer_timeout', params_var));
		const old_bx_5_var = '' + this.BreakoutGame_bx_var;
		this.BreakoutGame_bx_var = this.BreakoutGame_bx_var + this.BreakoutGame_dx_var;
		const new_bx_5_var = '' + this.BreakoutGame_bx_var;
		this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'bx', 'Int16', old_bx_5_var, new_bx_5_var));
		const old_by_18_var = '' + this.BreakoutGame_by_var;
		this.BreakoutGame_by_var = this.BreakoutGame_by_var + this.BreakoutGame_dy_var;
		const new_by_18_var = '' + this.BreakoutGame_by_var;
		this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'by', 'Int16', old_by_18_var, new_by_18_var));
		let wl_var = this.BreakoutGame_LEFT_var + this.BreakoutGame_br_var;
		let wr_var = this.BreakoutGame_RIGHT_var - this.BreakoutGame_br_var;
		let wt_var = this.BreakoutGame_TOP_var + this.BreakoutGame_br_var;
		let wb_var = this.BreakoutGame_BOTTOM_var - this.BreakoutGame_br_var;
		if(this.BreakoutGame_bx_var < wl_var) {
		const old_dx_30_var = '' + this.BreakoutGame_dx_var;
		this.BreakoutGame_dx_var =  -this.BreakoutGame_dx_var;
		const new_dx_30_var = '' + this.BreakoutGame_dx_var;
		this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'dx', 'Int16', old_dx_30_var, new_dx_30_var));
		const old_bx_6_var = '' + this.BreakoutGame_bx_var;
		this.BreakoutGame_bx_var = 2 * wl_var - this.BreakoutGame_bx_var;
		const new_bx_6_var = '' + this.BreakoutGame_bx_var;
		this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'bx', 'Int16', old_bx_6_var, new_bx_6_var));
		this.incrementScore( -1);
		
		} else {
		if(this.BreakoutGame_bx_var > wr_var) {
		const old_dx_31_var = '' + this.BreakoutGame_dx_var;
		this.BreakoutGame_dx_var =  -this.BreakoutGame_dx_var;
		const new_dx_31_var = '' + this.BreakoutGame_dx_var;
		this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'dx', 'Int16', old_dx_31_var, new_dx_31_var));
		const old_bx_7_var = '' + this.BreakoutGame_bx_var;
		this.BreakoutGame_bx_var = 2 * wr_var - this.BreakoutGame_bx_var;
		const new_bx_7_var = '' + this.BreakoutGame_bx_var;
		this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'bx', 'Int16', old_bx_7_var, new_bx_7_var));
		this.incrementScore( -1);
		
		}
		
		}
		if(this.BreakoutGame_by_var < wt_var) {
		const old_dy_25_var = '' + this.BreakoutGame_dy_var;
		this.BreakoutGame_dy_var =  -this.BreakoutGame_dy_var;
		const new_dy_25_var = '' + this.BreakoutGame_dy_var;
		this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'dy', 'Int16', old_dy_25_var, new_dy_25_var));
		const old_by_19_var = '' + this.BreakoutGame_by_var;
		this.BreakoutGame_by_var = 2 * wt_var - this.BreakoutGame_by_var;
		const new_by_19_var = '' + this.BreakoutGame_by_var;
		this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'by', 'Int16', old_by_19_var, new_by_19_var));
		this.incrementScore( -1);
		
		} else {
		if(this.BreakoutGame_by_var > wb_var) {
		this.bus.emit('game', new Event.LostBall_BreakoutGame(this.name, 'game'));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'game', 'lostBall', ''));
		this.bus.emit('req_game', new Event.LostBall_BreakoutGame(this.name, 'req_game'));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'req_game', 'lostBall', ''));
		
		}
		
		}
		if(this.BreakoutGame_dy_var > 0) {
		if(this.BreakoutGame_by_var > this.BreakoutGame_pady_var - this.BreakoutGame_br_var && this.BreakoutGame_by_var < this.BreakoutGame_pady_var + this.BreakoutGame_br_var) {
		if(this.BreakoutGame_bx_var > this.BreakoutGame_padx_var - Math.trunc(this.BreakoutGame_padlen_var / 2) && this.BreakoutGame_bx_var < this.BreakoutGame_padx_var + Math.trunc(this.BreakoutGame_padlen_var / 2)) {
		const old_dy_26_var = '' + this.BreakoutGame_dy_var;
		this.BreakoutGame_dy_var =  -this.BreakoutGame_dy_var;
		const new_dy_26_var = '' + this.BreakoutGame_dy_var;
		this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'dy', 'Int16', old_dy_26_var, new_dy_26_var));
		const old_by_20_var = '' + this.BreakoutGame_by_var;
		this.BreakoutGame_by_var = 2 * (this.BreakoutGame_pady_var - this.BreakoutGame_br_var) - this.BreakoutGame_by_var;
		const new_by_20_var = '' + this.BreakoutGame_by_var;
		this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'by', 'Int16', old_by_20_var, new_by_20_var));
		const old_dx_32_var = '' + this.BreakoutGame_dx_var;
		this.BreakoutGame_dx_var = Math.trunc(this.BreakoutGame_dx_var / 4) + Math.trunc((this.BreakoutGame_bx_var - this.BreakoutGame_padx_var) / 4);
		const new_dx_32_var = '' + this.BreakoutGame_dx_var;
		this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'dx', 'Int16', old_dx_32_var, new_dx_32_var));
		
		}
		
		}
		
		}
		let collision_var = this.collideBrick(this.BreakoutGame_bx_var - this.BreakoutGame_br_var, this.BreakoutGame_by_var - this.BreakoutGame_br_var) || this.collideBrick(this.BreakoutGame_bx_var + this.BreakoutGame_br_var, this.BreakoutGame_by_var - this.BreakoutGame_br_var) || this.collideBrick(this.BreakoutGame_bx_var + this.BreakoutGame_br_var, this.BreakoutGame_by_var + this.BreakoutGame_br_var) || this.collideBrick(this.BreakoutGame_bx_var - this.BreakoutGame_br_var, this.BreakoutGame_by_var + this.BreakoutGame_br_var);
		if(collision_var) {
		const old_dy_27_var = '' + this.BreakoutGame_dy_var;
		this.BreakoutGame_dy_var =  -this.BreakoutGame_dy_var;
		const new_dy_27_var = '' + this.BreakoutGame_dy_var;
		this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'dy', 'Int16', old_dy_27_var, new_dy_27_var));
		this.incrementScore(10);
		if(this.bricksLeft() === 0) {
		this.bus.emit('game', new Event.NextLevel_BreakoutGame(this.name, 'game'));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'game', 'nextLevel', ''));
		this.bus.emit('req_game', new Event.NextLevel_BreakoutGame(this.name, 'req_game'));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'req_game', 'nextLevel', ''));
		
		}
		
		}
		this.drawBall();
		this.drawPad();
		const ballx_202_var = this.BreakoutGame_bx_var;
		const bally_203_var = this.BreakoutGame_by_var;
		const padx_204_var = this.BreakoutGame_padx_var;
		const pady_205_var = this.BreakoutGame_pady_var;
		this.bus.emit('ia', new Event.UpdateIA_IAControllerMsg(this.name, 'ia', ballx_202_var, bally_203_var, padx_204_var, pady_205_var));
		const params_206_var = '' + ('ballx=' + (ballx_202_var + ',')) + ('bally=' + (bally_203_var + ',')) + ('padx=' + (padx_204_var + ',')) + ('pady=' + (pady_205_var + ','));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'ia', 'updateIA', params_206_var));
		this.bus.emit('display', new Event.Update_DisplayMsgs(this.name, 'display'));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'update', ''));
		this.log(false);
		const id_207_var = 0;
		const time_208_var = this.BreakoutGame_period_var;
		this.bus.emit('clock', new Event.Timer_start_TimerMsgs(this.name, 'clock', id_207_var, time_208_var));
		const params_209_var = '' + ('id=' + (id_207_var + ',')) + ('time=' + (time_208_var + ','));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'clock', 'timer_start', params_209_var));
	});
	BreakoutGame_SC_LAUNCH.to(BreakoutGame_SC_PLAY).on(Event.Timer_timeout_TimerMsgs).when((timer_timeout) => {
		return timer_timeout.port === 'clock' && timer_timeout.type === 'timer_timeout' && (timer_timeout.id === 0 && this.BreakoutGame_SC_LAUNCH_countdown_var === 0);
	}).effect((timer_timeout) => {
		const params_var = '' + ('id=' + (timer_timeout.id + ','));
		this.bus.emit('log', new Event.Message_handled_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'SC.LAUNCH', 'SC.PLAY', 'clock', 'timer_timeout', params_var));
		this.drawCountDown(0);
		this.resetBall();
		this.bus.emit('display', new Event.Update_DisplayMsgs(this.name, 'display'));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'update', ''));
	});
	BreakoutGame_SC_LAUNCH.on(Event.Timer_timeout).when((timer_timeout) => {
		return timer_timeout.port === 'clock' && timer_timeout.type === 'timer_timeout' && (timer_timeout.id === 0 && this.BreakoutGame_SC_LAUNCH_countdown_var > 0);
	}).effect((timer_timeout) => {
		const params_var = '' + ('id=' + (timer_timeout.id + ','));
		this.bus.emit('log', new Event.Message_handled_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'SC.LAUNCH', '_', 'clock', 'timer_timeout', params_var));
		const id_196_var = 0;
		const time_197_var = this.BreakoutGame_period_var;
		this.bus.emit('clock', new Event.Timer_start_TimerMsgs(this.name, 'clock', id_196_var, time_197_var));
		const params_198_var = '' + ('id=' + (id_196_var + ',')) + ('time=' + (time_197_var + ','));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'clock', 'timer_start', params_198_var));
		this.drawPad();
		if((this.BreakoutGame_SC_LAUNCH_countdown_var % 30) === 0) {
		this.drawCountDown(Math.trunc(this.BreakoutGame_SC_LAUNCH_countdown_var / 30));
		
		}
		const old_countdown_15_var = '' + this.BreakoutGame_SC_LAUNCH_countdown_var;
		this.BreakoutGame_SC_LAUNCH_countdown_var = this.BreakoutGame_SC_LAUNCH_countdown_var - 1;
		const new_countdown_15_var = '' + this.BreakoutGame_SC_LAUNCH_countdown_var;
		this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'countdown', 'UInt8', old_countdown_15_var, new_countdown_15_var));
		this.bus.emit('display', new Event.Update_DisplayMsgs(this.name, 'display'));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'update', ''));
	});
	BreakoutGame_SC_NEXTLEVEL.to(BreakoutGame_SC_LAUNCH).on(Event.Timer_timeout_TimerMsgs).when((timer_timeout) => {
		return timer_timeout.port === 'clock' && timer_timeout.type === 'timer_timeout' && (timer_timeout.id === 0);
	}).effect((timer_timeout) => {
		const params_var = '' + ('id=' + (timer_timeout.id + ','));
		this.bus.emit('log', new Event.Message_handled_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'SC.NEXTLEVEL', 'SC.LAUNCH', 'clock', 'timer_timeout', params_var));
	});
	this._statemachine.on(Event.Timer_timeout).when((timer_timeout) => {
		return timer_timeout.port === 'clock' && timer_timeout.type === 'timer_timeout' && (true);
	}).effect((timer_timeout) => {
		const params_var = '' + ('id=' + (timer_timeout.id + ','));
		this.bus.emit('log', new Event.Message_lost_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'clock', 'timer_timeout', params_var));
	});
	BreakoutGame_SC_LOSTBALL.to(BreakoutGame_SC_LAUNCH).on(Event.Timer_timeout_TimerMsgs).when((timer_timeout) => {
		return timer_timeout.port === 'clock' && timer_timeout.type === 'timer_timeout' && (timer_timeout.id === 0 && this.BreakoutGame_lives_var > 0);
	}).effect((timer_timeout) => {
		const params_var = '' + ('id=' + (timer_timeout.id + ','));
		this.bus.emit('log', new Event.Message_handled_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'SC.LOSTBALL', 'SC.LAUNCH', 'clock', 'timer_timeout', params_var));
	});
	BreakoutGame_SC_LOSTBALL.to(BreakoutGame_SC_GAMEOVER).on(Event.Timer_timeout_TimerMsgs).when((timer_timeout) => {
		return timer_timeout.port === 'clock' && timer_timeout.type === 'timer_timeout' && (timer_timeout.id === 0 && this.BreakoutGame_lives_var === 0);
	}).effect((timer_timeout) => {
		const params_var = '' + ('id=' + (timer_timeout.id + ','));
		this.bus.emit('log', new Event.Message_handled_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'SC.LOSTBALL', 'SC.GAMEOVER', 'clock', 'timer_timeout', params_var));
	});
	BreakoutGame_SC_PLAY.to(BreakoutGame_SC_LOSTBALL).on(Event.LostBall_BreakoutGame).when((lostBall) => {
		return lostBall.port === 'pro_game' && lostBall.type === 'lostBall';
	}).effect((lostBall) => {
		this.bus.emit('log', new Event.Message_handled_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'SC.PLAY', 'SC.LOSTBALL', 'pro_game', 'lostBall', '_'));
		const id_214_var = 0;
		this.bus.emit('clock', new Event.Timer_cancel_TimerMsgs(this.name, 'clock', id_214_var));
		const params_215_var = '' + ('id=' + (id_214_var + ','));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'clock', 'timer_cancel', params_215_var));
	});
	this._statemachine.on(Event.LostBall).when((lostBall) => {
		return lostBall.port === 'pro_game' && lostBall.type === 'lostBall' && (true);
	}).effect((lostBall) => {
		this.bus.emit('log', new Event.Message_lost_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'pro_game', 'lostBall', ''));
	});
	BreakoutGame_SC_PLAY.to(BreakoutGame_SC_NEXTLEVEL).on(Event.NextLevel_BreakoutGame).when((nextLevel) => {
		return nextLevel.port === 'pro_game' && nextLevel.type === 'nextLevel';
	}).effect((nextLevel) => {
		this.bus.emit('log', new Event.Message_handled_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'SC.PLAY', 'SC.NEXTLEVEL', 'pro_game', 'nextLevel', '_'));
		const id_216_var = 0;
		this.bus.emit('clock', new Event.Timer_cancel_TimerMsgs(this.name, 'clock', id_216_var));
		const params_217_var = '' + ('id=' + (id_216_var + ','));
		this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'clock', 'timer_cancel', params_217_var));
	});
	this._statemachine.on(Event.NextLevel).when((nextLevel) => {
		return nextLevel.port === 'pro_game' && nextLevel.type === 'nextLevel' && (true);
	}).effect((nextLevel) => {
		this.bus.emit('log', new Event.Message_lost_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'pro_game', 'nextLevel', ''));
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
	this.bus.emit('log', new Event.Function_called_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'initColors', 'void_', '', ''));
	this.BreakoutGame_bgcolor_var[0] = 53;
	this.BreakoutGame_bgcolor_var[1] = 40;
	this.BreakoutGame_bgcolor_var[2] = 120;
	this.BreakoutGame_fgcolor_var[0] = 107;
	this.BreakoutGame_fgcolor_var[1] = 94;
	this.BreakoutGame_fgcolor_var[2] = 174;
	const r_0_var = this.BreakoutGame_bgcolor_var[0];
	const g_1_var = this.BreakoutGame_bgcolor_var[1];
	const b_2_var = this.BreakoutGame_bgcolor_var[2];
	this.bus.emit('display', new Event.SetBGColor_DisplayMsgs(this.name, 'display', r_0_var, g_1_var, b_2_var));
	const params_3_var = '' + ('r=' + (r_0_var + ',')) + ('g=' + (g_1_var + ',')) + ('b=' + (b_2_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'setBGColor', params_3_var));
	const r_4_var = this.BreakoutGame_fgcolor_var[0];
	const g_5_var = this.BreakoutGame_fgcolor_var[1];
	const b_6_var = this.BreakoutGame_fgcolor_var[2];
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_4_var, g_5_var, b_6_var));
	const params_7_var = '' + ('r=' + (r_4_var + ',')) + ('g=' + (g_5_var + ',')) + ('b=' + (b_6_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'setColor', params_7_var));
}

BreakoutGameNodeJS.prototype.resetBall = function() {
	this.bus.emit('log', new Event.Function_called_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'resetBall', 'void_', '', ''));
	const old_bx_4_var = '' + this.BreakoutGame_bx_var;
	this.BreakoutGame_bx_var = this.BreakoutGame_padx_var - Math.trunc(this.BreakoutGame_br_var / this.BreakoutGame_SCALE_var);
	const new_bx_4_var = '' + this.BreakoutGame_bx_var;
	this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'bx', 'Int16', old_bx_4_var, new_bx_4_var));
	const old_by_17_var = '' + this.BreakoutGame_by_var;
	this.BreakoutGame_by_var = this.BreakoutGame_pady_var - Math.trunc(this.BreakoutGame_br_var / this.BreakoutGame_SCALE_var);
	const new_by_17_var = '' + this.BreakoutGame_by_var;
	this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'by', 'Int16', old_by_17_var, new_by_17_var));
	const old_dx_29_var = '' + this.BreakoutGame_dx_var;
	this.BreakoutGame_dx_var = (this.BreakoutGame_padx_var + this.BreakoutGame_prevBX_var + this.BreakoutGame_prevBY_var) % 300 - 150;
	const new_dx_29_var = '' + this.BreakoutGame_dx_var;
	this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'dx', 'Int16', old_dx_29_var, new_dx_29_var));
	if(this.BreakoutGame_dy_var > 0) {
	const old_dy_24_var = '' + this.BreakoutGame_dy_var;
	this.BreakoutGame_dy_var =  -this.BreakoutGame_dy_var;
	const new_dy_24_var = '' + this.BreakoutGame_dy_var;
	this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'dy', 'Int16', old_dy_24_var, new_dy_24_var));
	
	}
	const old_prevBX_21_var = '' + this.BreakoutGame_prevBX_var;
	this.BreakoutGame_prevBX_var =  -1;
	const new_prevBX_21_var = '' + this.BreakoutGame_prevBX_var;
	this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'prevBX', 'Int16', old_prevBX_21_var, new_prevBX_21_var));
	const old_prevBY_0_var = '' + this.BreakoutGame_prevBY_var;
	this.BreakoutGame_prevBY_var =  -1;
	const new_prevBY_0_var = '' + this.BreakoutGame_prevBY_var;
	this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'prevBY', 'Int16', old_prevBY_0_var, new_prevBY_0_var));
}

BreakoutGameNodeJS.prototype.eraseBall = function() {
	this.bus.emit('log', new Event.Function_called_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'eraseBall', 'void_', '', ''));
	let bs_var = Math.trunc((this.BreakoutGame_br_var * 2) / this.BreakoutGame_SCALE_var);
	if(this.BreakoutGame_prevBX_var > 0) {
	const r_8_var = this.BreakoutGame_bgcolor_var[0];
	const g_9_var = this.BreakoutGame_bgcolor_var[1];
	const b_10_var = this.BreakoutGame_bgcolor_var[2];
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_8_var, g_9_var, b_10_var));
	const params_11_var = '' + ('r=' + (r_8_var + ',')) + ('g=' + (g_9_var + ',')) + ('b=' + (b_10_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'setColor', params_11_var));
	const x_12_var = this.BreakoutGame_prevBX_var;
	const y_13_var = this.BreakoutGame_prevBY_var;
	const width_14_var = bs_var;
	const height_15_var = bs_var;
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_12_var, y_13_var, width_14_var, height_15_var));
	const params_16_var = '' + ('x=' + (x_12_var + ',')) + ('y=' + (y_13_var + ',')) + ('width=' + (width_14_var + ',')) + ('height=' + (height_15_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'fillRect', params_16_var));
	
	}
	const old_prevBX_22_var = '' + this.BreakoutGame_prevBX_var;
	this.BreakoutGame_prevBX_var =  -1;
	const new_prevBX_22_var = '' + this.BreakoutGame_prevBX_var;
	this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'prevBX', 'Int16', old_prevBX_22_var, new_prevBX_22_var));
	const old_prevBY_1_var = '' + this.BreakoutGame_prevBY_var;
	this.BreakoutGame_prevBY_var =  -1;
	const new_prevBY_1_var = '' + this.BreakoutGame_prevBY_var;
	this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'prevBY', 'Int16', old_prevBY_1_var, new_prevBY_1_var));
}

BreakoutGameNodeJS.prototype.drawBall = function() {
	this.bus.emit('log', new Event.Function_called_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'drawBall', 'void_', '', ''));
	let bs_var = Math.trunc((this.BreakoutGame_br_var * 2) / this.BreakoutGame_SCALE_var);
	this.eraseBall();
	const old_prevBX_23_var = '' + this.BreakoutGame_prevBX_var;
	this.BreakoutGame_prevBX_var = Math.trunc((this.BreakoutGame_bx_var - this.BreakoutGame_br_var) / this.BreakoutGame_SCALE_var);
	const new_prevBX_23_var = '' + this.BreakoutGame_prevBX_var;
	this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'prevBX', 'Int16', old_prevBX_23_var, new_prevBX_23_var));
	const old_prevBY_2_var = '' + this.BreakoutGame_prevBY_var;
	this.BreakoutGame_prevBY_var = Math.trunc((this.BreakoutGame_by_var - this.BreakoutGame_br_var) / this.BreakoutGame_SCALE_var);
	const new_prevBY_2_var = '' + this.BreakoutGame_prevBY_var;
	this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'prevBY', 'Int16', old_prevBY_2_var, new_prevBY_2_var));
	const r_17_var = 183;
	const g_18_var = 199;
	const b_19_var = 111;
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_17_var, g_18_var, b_19_var));
	const params_20_var = '' + ('r=' + (r_17_var + ',')) + ('g=' + (g_18_var + ',')) + ('b=' + (b_19_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'setColor', params_20_var));
	const x_21_var = this.BreakoutGame_prevBX_var;
	const y_22_var = this.BreakoutGame_prevBY_var;
	const width_23_var = bs_var;
	const height_24_var = bs_var;
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_21_var, y_22_var, width_23_var, height_24_var));
	const params_25_var = '' + ('x=' + (x_21_var + ',')) + ('y=' + (y_22_var + ',')) + ('width=' + (width_23_var + ',')) + ('height=' + (height_24_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'fillRect', params_25_var));
}

BreakoutGameNodeJS.prototype.erasePad = function() {
	this.bus.emit('log', new Event.Function_called_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'erasePad', 'void_', '', ''));
	let ps_var = Math.trunc(this.BreakoutGame_padlen_var / this.BreakoutGame_SCALE_var);
	if(this.BreakoutGame_prevPX_var > 0) {
	const r_26_var = this.BreakoutGame_bgcolor_var[0];
	const g_27_var = this.BreakoutGame_bgcolor_var[1];
	const b_28_var = this.BreakoutGame_bgcolor_var[2];
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_26_var, g_27_var, b_28_var));
	const params_29_var = '' + ('r=' + (r_26_var + ',')) + ('g=' + (g_27_var + ',')) + ('b=' + (b_28_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'setColor', params_29_var));
	const x_30_var = this.BreakoutGame_prevPX_var;
	const y_31_var = this.BreakoutGame_prevPY_var;
	const width_32_var = ps_var;
	const height_33_var = 4;
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_30_var, y_31_var, width_32_var, height_33_var));
	const params_34_var = '' + ('x=' + (x_30_var + ',')) + ('y=' + (y_31_var + ',')) + ('width=' + (width_32_var + ',')) + ('height=' + (height_33_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'fillRect', params_34_var));
	
	}
}

BreakoutGameNodeJS.prototype.drawPad = function() {
	this.bus.emit('log', new Event.Function_called_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'drawPad', 'void_', '', ''));
	let ps_var = Math.trunc(this.BreakoutGame_padlen_var / this.BreakoutGame_SCALE_var);
	this.erasePad();
	const old_prevPX_13_var = '' + this.BreakoutGame_prevPX_var;
	this.BreakoutGame_prevPX_var = Math.trunc((this.BreakoutGame_padx_var - (Math.trunc(this.BreakoutGame_padlen_var / 2))) / this.BreakoutGame_SCALE_var);
	const new_prevPX_13_var = '' + this.BreakoutGame_prevPX_var;
	this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'prevPX', 'Int16', old_prevPX_13_var, new_prevPX_13_var));
	const old_prevPY_16_var = '' + this.BreakoutGame_prevPY_var;
	this.BreakoutGame_prevPY_var = Math.trunc(this.BreakoutGame_pady_var / this.BreakoutGame_SCALE_var);
	const new_prevPY_16_var = '' + this.BreakoutGame_prevPY_var;
	this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'prevPY', 'Int16', old_prevPY_16_var, new_prevPY_16_var));
	const r_35_var = this.BreakoutGame_fgcolor_var[0];
	const g_36_var = this.BreakoutGame_fgcolor_var[1];
	const b_37_var = this.BreakoutGame_fgcolor_var[2];
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_35_var, g_36_var, b_37_var));
	const params_38_var = '' + ('r=' + (r_35_var + ',')) + ('g=' + (g_36_var + ',')) + ('b=' + (b_37_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'setColor', params_38_var));
	const x_39_var = this.BreakoutGame_prevPX_var;
	const y_40_var = this.BreakoutGame_prevPY_var;
	const width_41_var = ps_var;
	const height_42_var = 4;
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_39_var, y_40_var, width_41_var, height_42_var));
	const params_43_var = '' + ('x=' + (x_39_var + ',')) + ('y=' + (y_40_var + ',')) + ('width=' + (width_41_var + ',')) + ('height=' + (height_42_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'fillRect', params_43_var));
}

BreakoutGameNodeJS.prototype.drawCountDown = function(BreakoutGame_drawCountDown_c_var) {
	const params_var = '' + ('c=' + (BreakoutGame_drawCountDown_c_var + ','));
	this.bus.emit('log', new Event.Function_called_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'drawCountDown', 'void_', '', params_var));
	const r_44_var = this.BreakoutGame_fgcolor_var[0];
	const g_45_var = this.BreakoutGame_fgcolor_var[1];
	const b_46_var = this.BreakoutGame_fgcolor_var[2];
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_44_var, g_45_var, b_46_var));
	const params_47_var = '' + ('r=' + (r_44_var + ',')) + ('g=' + (g_45_var + ',')) + ('b=' + (b_46_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'setColor', params_47_var));
	if(BreakoutGame_drawCountDown_c_var > 0) {
	const r_48_var = this.BreakoutGame_fgcolor_var[0];
	const g_49_var = this.BreakoutGame_fgcolor_var[1];
	const b_50_var = this.BreakoutGame_fgcolor_var[2];
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_48_var, g_49_var, b_50_var));
	const params_51_var = '' + ('r=' + (r_48_var + ',')) + ('g=' + (g_49_var + ',')) + ('b=' + (b_50_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'setColor', params_51_var));
	const r_52_var = this.BreakoutGame_bgcolor_var[0];
	const g_53_var = this.BreakoutGame_bgcolor_var[1];
	const b_54_var = this.BreakoutGame_bgcolor_var[2];
	this.bus.emit('display', new Event.SetBGColor_DisplayMsgs(this.name, 'display', r_52_var, g_53_var, b_54_var));
	const params_55_var = '' + ('r=' + (r_52_var + ',')) + ('g=' + (g_53_var + ',')) + ('b=' + (b_54_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'setBGColor', params_55_var));
	const x_56_var = 80 - 6;
	const y_57_var = 90;
	const v_58_var = BreakoutGame_drawCountDown_c_var;
	const digits_59_var = 1;
	const scale_60_var = 4;
	this.bus.emit('display', new Event.DrawInteger_DisplayMsgs(this.name, 'display', x_56_var, y_57_var, v_58_var, digits_59_var, scale_60_var));
	const params_61_var = '' + ('x=' + (x_56_var + ',')) + ('y=' + (y_57_var + ',')) + ('v=' + (v_58_var + ',')) + ('digits=' + (digits_59_var + ',')) + ('scale=' + (scale_60_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'drawInteger', params_61_var));
	
	} else {
	const r_62_var = this.BreakoutGame_bgcolor_var[0];
	const g_63_var = this.BreakoutGame_bgcolor_var[1];
	const b_64_var = this.BreakoutGame_bgcolor_var[2];
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_62_var, g_63_var, b_64_var));
	const params_65_var = '' + ('r=' + (r_62_var + ',')) + ('g=' + (g_63_var + ',')) + ('b=' + (b_64_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'setColor', params_65_var));
	const x_66_var = 80 - 6;
	const y_67_var = 90;
	const width_68_var = 12;
	const height_69_var = 20;
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_66_var, y_67_var, width_68_var, height_69_var));
	const params_70_var = '' + ('x=' + (x_66_var + ',')) + ('y=' + (y_67_var + ',')) + ('width=' + (width_68_var + ',')) + ('height=' + (height_69_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'fillRect', params_70_var));
	
	}
}

BreakoutGameNodeJS.prototype.drawWalls = function() {
	this.bus.emit('log', new Event.Function_called_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'drawWalls', 'void_', '', ''));
	const r_71_var = this.BreakoutGame_fgcolor_var[0];
	const g_72_var = this.BreakoutGame_fgcolor_var[1];
	const b_73_var = this.BreakoutGame_fgcolor_var[2];
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_71_var, g_72_var, b_73_var));
	const params_74_var = '' + ('r=' + (r_71_var + ',')) + ('g=' + (g_72_var + ',')) + ('b=' + (b_73_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'setColor', params_74_var));
	const left_var = (Math.trunc(this.BreakoutGame_LEFT_var / this.BreakoutGame_SCALE_var));
	const right_var = (Math.trunc(this.BreakoutGame_RIGHT_var / this.BreakoutGame_SCALE_var));
	const top_var = (Math.trunc(this.BreakoutGame_TOP_var / this.BreakoutGame_SCALE_var));
	const bottom_var = (Math.trunc(this.BreakoutGame_BOTTOM_var / this.BreakoutGame_SCALE_var));
	const xcenter_var = (Math.trunc((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / this.BreakoutGame_SCALE_var));
	const ycenter_var = (Math.trunc((this.BreakoutGame_BOTTOM_var - this.BreakoutGame_TOP_var) / this.BreakoutGame_SCALE_var));
	const x_75_var = left_var - 1;
	const y_76_var = top_var - 1;
	const width_77_var = xcenter_var + 1;
	const height_78_var = 1;
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_75_var, y_76_var, width_77_var, height_78_var));
	const params_79_var = '' + ('x=' + (x_75_var + ',')) + ('y=' + (y_76_var + ',')) + ('width=' + (width_77_var + ',')) + ('height=' + (height_78_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'fillRect', params_79_var));
	const x_80_var = left_var - 1;
	const y_81_var = bottom_var;
	const width_82_var = xcenter_var + 1;
	const height_83_var = 1;
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_80_var, y_81_var, width_82_var, height_83_var));
	const params_84_var = '' + ('x=' + (x_80_var + ',')) + ('y=' + (y_81_var + ',')) + ('width=' + (width_82_var + ',')) + ('height=' + (height_83_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'fillRect', params_84_var));
	const x_85_var = left_var - 1;
	const y_86_var = top_var;
	const width_87_var = 1;
	const height_88_var = ycenter_var;
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_85_var, y_86_var, width_87_var, height_88_var));
	const params_89_var = '' + ('x=' + (x_85_var + ',')) + ('y=' + (y_86_var + ',')) + ('width=' + (width_87_var + ',')) + ('height=' + (height_88_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'fillRect', params_89_var));
	const x_90_var = right_var;
	const y_91_var = top_var;
	const width_92_var = 1;
	const height_93_var = ycenter_var;
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_90_var, y_91_var, width_92_var, height_93_var));
	const params_94_var = '' + ('x=' + (x_90_var + ',')) + ('y=' + (y_91_var + ',')) + ('width=' + (width_92_var + ',')) + ('height=' + (height_93_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'fillRect', params_94_var));
}

BreakoutGameNodeJS.prototype.bitIsSet = function(BreakoutGame_bitIsSet_variable_var, BreakoutGame_bitIsSet_bit_var) {
	const return_0_var = (((1 << BreakoutGame_bitIsSet_bit_var) & BreakoutGame_bitIsSet_variable_var) != 0);
	const return_as_string0_var = '' + (return_0_var);
	const params_var = '' + ('variable=' + (BreakoutGame_bitIsSet_variable_var + ',')) + ('bit=' + (BreakoutGame_bitIsSet_bit_var + ','));
	this.bus.emit('log', new Event.Function_called_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'bitIsSet', 'Boolean', return_as_string0_var, params_var));
	return return_0_var;
}

BreakoutGameNodeJS.prototype.createBricks = function() {
	this.bus.emit('log', new Event.Function_called_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'createBricks', 'void_', '', ''));
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
	const return_3_var = result_var;
	const return_as_string3_var = '' + (return_3_var);
	this.bus.emit('log', new Event.Function_called_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'bricksLeft', 'UInt8', return_as_string3_var, ''));
	return return_3_var;
}

BreakoutGameNodeJS.prototype.drawBrick = function(BreakoutGame_drawBrick_x_var, BreakoutGame_drawBrick_y_var) {
	const params_var = '' + ('x=' + (BreakoutGame_drawBrick_x_var + ',')) + ('y=' + (BreakoutGame_drawBrick_y_var + ','));
	this.bus.emit('log', new Event.Function_called_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'drawBrick', 'void_', '', params_var));
	const bx_var = (Math.trunc((this.BreakoutGame_LEFT_var + (Math.trunc((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / 8)) * BreakoutGame_drawBrick_x_var) / this.BreakoutGame_SCALE_var) + 1);
	const by_var = (Math.trunc((this.BreakoutGame_TOP_var + 20 * this.BreakoutGame_SCALE_var + this.BreakoutGame_BRICK_HEIGHT_var * BreakoutGame_drawBrick_y_var * this.BreakoutGame_SCALE_var) / this.BreakoutGame_SCALE_var) + 1);
	const w_var = (Math.trunc((Math.trunc((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / 8)) / this.BreakoutGame_SCALE_var) - 2);
	const h_var = (this.BreakoutGame_BRICK_HEIGHT_var - 2);
	const r_95_var = 155;
	const g_96_var = 103;
	const b_97_var = 89;
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_95_var, g_96_var, b_97_var));
	const params_98_var = '' + ('r=' + (r_95_var + ',')) + ('g=' + (g_96_var + ',')) + ('b=' + (b_97_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'setColor', params_98_var));
	const x_99_var = bx_var;
	const y_100_var = by_var;
	const width_101_var = w_var;
	const height_102_var = h_var;
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_99_var, y_100_var, width_101_var, height_102_var));
	const params_103_var = '' + ('x=' + (x_99_var + ',')) + ('y=' + (y_100_var + ',')) + ('width=' + (width_101_var + ',')) + ('height=' + (height_102_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'fillRect', params_103_var));
	const r_104_var = 100;
	const g_105_var = 56;
	const b_106_var = 43;
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_104_var, g_105_var, b_106_var));
	const params_107_var = '' + ('r=' + (r_104_var + ',')) + ('g=' + (g_105_var + ',')) + ('b=' + (b_106_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'setColor', params_107_var));
	const x_108_var = bx_var;
	const y_109_var = by_var;
	const width_110_var = w_var;
	const height_111_var = h_var;
	this.bus.emit('display', new Event.DrawRect_DisplayMsgs(this.name, 'display', x_108_var, y_109_var, width_110_var, height_111_var));
	const params_112_var = '' + ('x=' + (x_108_var + ',')) + ('y=' + (y_109_var + ',')) + ('width=' + (width_110_var + ',')) + ('height=' + (height_111_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'drawRect', params_112_var));
}

BreakoutGameNodeJS.prototype.removeBrick = function(BreakoutGame_removeBrick_x_var, BreakoutGame_removeBrick_y_var) {
	const params_var = '' + ('x=' + (BreakoutGame_removeBrick_x_var + ',')) + ('y=' + (BreakoutGame_removeBrick_y_var + ','));
	this.bus.emit('log', new Event.Function_called_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'removeBrick', 'void_', '', params_var));
	const bx_var = (Math.trunc((this.BreakoutGame_LEFT_var + (Math.trunc((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / 8)) * BreakoutGame_removeBrick_x_var) / this.BreakoutGame_SCALE_var) + 1);
	const by_var = (Math.trunc((this.BreakoutGame_TOP_var + 20 * this.BreakoutGame_SCALE_var + this.BreakoutGame_BRICK_HEIGHT_var * BreakoutGame_removeBrick_y_var * this.BreakoutGame_SCALE_var) / this.BreakoutGame_SCALE_var) + 1);
	const r_113_var = this.BreakoutGame_bgcolor_var[0];
	const g_114_var = this.BreakoutGame_bgcolor_var[1];
	const b_115_var = this.BreakoutGame_bgcolor_var[2];
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_113_var, g_114_var, b_115_var));
	const params_116_var = '' + ('r=' + (r_113_var + ',')) + ('g=' + (g_114_var + ',')) + ('b=' + (b_115_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'setColor', params_116_var));
	const x_117_var = bx_var;
	const y_118_var = by_var;
	const width_119_var = (Math.trunc((Math.trunc((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / 8)) / this.BreakoutGame_SCALE_var) - 2);
	const height_120_var = this.BreakoutGame_BRICK_HEIGHT_var - 2;
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_117_var, y_118_var, width_119_var, height_120_var));
	const params_121_var = '' + ('x=' + (x_117_var + ',')) + ('y=' + (y_118_var + ',')) + ('width=' + (width_119_var + ',')) + ('height=' + (height_120_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'fillRect', params_121_var));
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
	const return_3_var = result_var;
	const return_as_string3_var = '' + (return_3_var);
	const params_var = '' + ('xpos=' + (BreakoutGame_collideBrick_xpos_var + ',')) + ('ypos=' + (BreakoutGame_collideBrick_ypos_var + ','));
	this.bus.emit('log', new Event.Function_called_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'collideBrick', 'Boolean', return_as_string3_var, params_var));
	return return_3_var;
}

BreakoutGameNodeJS.prototype.drawLevel = function() {
	this.bus.emit('log', new Event.Function_called_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'drawLevel', 'void_', '', ''));
	const r_122_var = 158;
	const g_123_var = 209;
	const b_124_var = 130;
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_122_var, g_123_var, b_124_var));
	const params_125_var = '' + ('r=' + (r_122_var + ',')) + ('g=' + (g_123_var + ',')) + ('b=' + (b_124_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'setColor', params_125_var));
	const r_126_var = this.BreakoutGame_fgcolor_var[0];
	const g_127_var = this.BreakoutGame_fgcolor_var[1];
	const b_128_var = this.BreakoutGame_fgcolor_var[2];
	this.bus.emit('display', new Event.SetBGColor_DisplayMsgs(this.name, 'display', r_126_var, g_127_var, b_128_var));
	const params_129_var = '' + ('r=' + (r_126_var + ',')) + ('g=' + (g_127_var + ',')) + ('b=' + (b_128_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'setBGColor', params_129_var));
	const r_130_var = this.BreakoutGame_bgcolor_var[0];
	const g_131_var = this.BreakoutGame_bgcolor_var[1];
	const b_132_var = this.BreakoutGame_bgcolor_var[2];
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_130_var, g_131_var, b_132_var));
	const params_133_var = '' + ('r=' + (r_130_var + ',')) + ('g=' + (g_131_var + ',')) + ('b=' + (b_132_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'setColor', params_133_var));
	const x_134_var = 6;
	const y_135_var = 2;
	const v_136_var = this.BreakoutGame_level_var;
	const digits_137_var = 2;
	const scale_138_var = 2;
	this.bus.emit('display', new Event.DrawInteger_DisplayMsgs(this.name, 'display', x_134_var, y_135_var, v_136_var, digits_137_var, scale_138_var));
	const params_139_var = '' + ('x=' + (x_134_var + ',')) + ('y=' + (y_135_var + ',')) + ('v=' + (v_136_var + ',')) + ('digits=' + (digits_137_var + ',')) + ('scale=' + (scale_138_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'drawInteger', params_139_var));
}

BreakoutGameNodeJS.prototype.incrementScore = function(BreakoutGame_incrementScore_diff_var) {
	const params_var = '' + ('diff=' + (BreakoutGame_incrementScore_diff_var + ','));
	this.bus.emit('log', new Event.Function_called_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'incrementScore', 'void_', '', params_var));
	const old_score_9_var = '' + this.BreakoutGame_score_var;
	this.BreakoutGame_score_var = this.BreakoutGame_score_var + BreakoutGame_incrementScore_diff_var;
	const new_score_9_var = '' + this.BreakoutGame_score_var;
	this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'score', 'Int16', old_score_9_var, new_score_9_var));
	if(this.BreakoutGame_score_var < 0) {
	const old_score_10_var = '' + this.BreakoutGame_score_var;
	this.BreakoutGame_score_var = 0;
	const new_score_10_var = '' + this.BreakoutGame_score_var;
	this.bus.emit('log', new Event.Property_changed_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'score', 'Int16', old_score_10_var, new_score_10_var));
	
	}
	this.drawScore();
}

BreakoutGameNodeJS.prototype.drawScore = function() {
	this.bus.emit('log', new Event.Function_called_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'drawScore', 'void_', '', ''));
	const r_140_var = 158;
	const g_141_var = 209;
	const b_142_var = 130;
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_140_var, g_141_var, b_142_var));
	const params_143_var = '' + ('r=' + (r_140_var + ',')) + ('g=' + (g_141_var + ',')) + ('b=' + (b_142_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'setColor', params_143_var));
	const r_144_var = this.BreakoutGame_fgcolor_var[0];
	const g_145_var = this.BreakoutGame_fgcolor_var[1];
	const b_146_var = this.BreakoutGame_fgcolor_var[2];
	this.bus.emit('display', new Event.SetBGColor_DisplayMsgs(this.name, 'display', r_144_var, g_145_var, b_146_var));
	const params_147_var = '' + ('r=' + (r_144_var + ',')) + ('g=' + (g_145_var + ',')) + ('b=' + (b_146_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'setBGColor', params_147_var));
	const x_148_var = 58;
	const y_149_var = 2;
	const v_150_var = this.BreakoutGame_score_var;
	const digits_151_var = 5;
	const scale_152_var = 2;
	this.bus.emit('display', new Event.DrawInteger_DisplayMsgs(this.name, 'display', x_148_var, y_149_var, v_150_var, digits_151_var, scale_152_var));
	const params_153_var = '' + ('x=' + (x_148_var + ',')) + ('y=' + (y_149_var + ',')) + ('v=' + (v_150_var + ',')) + ('digits=' + (digits_151_var + ',')) + ('scale=' + (scale_152_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'drawInteger', params_153_var));
}

BreakoutGameNodeJS.prototype.drawLives = function() {
	this.bus.emit('log', new Event.Function_called_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'drawLives', 'void_', '', ''));
	const r_154_var = this.BreakoutGame_fgcolor_var[0];
	const g_155_var = this.BreakoutGame_fgcolor_var[1];
	const b_156_var = this.BreakoutGame_fgcolor_var[2];
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_154_var, g_155_var, b_156_var));
	const params_157_var = '' + ('r=' + (r_154_var + ',')) + ('g=' + (g_155_var + ',')) + ('b=' + (b_156_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'setColor', params_157_var));
	const x_158_var = 124;
	const y_159_var = 4;
	const width_160_var = 24 + 6;
	const height_161_var = 6;
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_158_var, y_159_var, width_160_var, height_161_var));
	const params_162_var = '' + ('x=' + (x_158_var + ',')) + ('y=' + (y_159_var + ',')) + ('width=' + (width_160_var + ',')) + ('height=' + (height_161_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'fillRect', params_162_var));
	const r_163_var = 183;
	const g_164_var = 199;
	const b_165_var = 111;
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_163_var, g_164_var, b_165_var));
	const params_166_var = '' + ('r=' + (r_163_var + ',')) + ('g=' + (g_164_var + ',')) + ('b=' + (b_165_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'setColor', params_166_var));
	let i_var = 0;
	while(i_var < this.BreakoutGame_lives_var) {
	const x_167_var = 124 + (2 - i_var) * 12;
	const y_168_var = 4;
	const width_169_var = 6;
	const height_170_var = 6;
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_167_var, y_168_var, width_169_var, height_170_var));
	const params_171_var = '' + ('x=' + (x_167_var + ',')) + ('y=' + (y_168_var + ',')) + ('width=' + (width_169_var + ',')) + ('height=' + (height_170_var + ','));
	this.bus.emit('log', new Event.Message_sent_LogMsgs(this.name, 'log', this.WithLog_DEBUG_ID_var, 'display', 'fillRect', params_171_var));
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
	result += '\n\tdy = ' + this.BreakoutGame_dy_var;
	result += '\n\tXDISPSIZE = ' + this.BreakoutGame_XDISPSIZE_var;
	result += '\n\tlastTimestamp = ' + this.BreakoutGame_lastTimestamp_var;
	result += '\n\tprevBX = ' + this.BreakoutGame_prevBX_var;
	result += '\n\tYMAX = ' + this.BreakoutGame_YMAX_var;
	result += '\n\tcountdown = ' + this.BreakoutGame_SC_LAUNCH_countdown_var;
	result += '\n\tRIGHT = ' + this.BreakoutGame_RIGHT_var;
	result += '\n\tXMAX = ' + this.BreakoutGame_XMAX_var;
	result += '\n\tbgcolor = ' + this.BreakoutGame_bgcolor_var;
	result += '\n\tperiod = ' + this.BreakoutGame_period_var;
	result += '\n\tprevBY = ' + this.BreakoutGame_prevBY_var;
	result += '\n\tBOTTOM = ' + this.BreakoutGame_BOTTOM_var;
	result += '\n\tpadx = ' + this.BreakoutGame_padx_var;
	result += '\n\tbr = ' + this.BreakoutGame_br_var;
	result += '\n\tlives = ' + this.BreakoutGame_lives_var;
	result += '\n\tprevPX = ' + this.BreakoutGame_prevPX_var;
	result += '\n\tDEBUG_ID = ' + this.WithLog_DEBUG_ID_var;
	result += '\n\tTOP = ' + this.BreakoutGame_TOP_var;
	result += '\n\tSCALE = ' + this.BreakoutGame_SCALE_var;
	result += '\n\tscore = ' + this.BreakoutGame_score_var;
	result += '\n\tlevel = ' + this.BreakoutGame_level_var;
	result += '\n\tstopTime = ' + this.BreakoutGame_stopTime_var;
	result += '\n\tbx = ' + this.BreakoutGame_bx_var;
	result += '\n\tbricks = ' + this.BreakoutGame_bricks_var;
	result += '\n\tstartTime = ' + this.BreakoutGame_startTime_var;
	result += '\n\tQUIET = ' + this.BreakoutGame_QUIET_var;
	result += '\n\tfgcolor = ' + this.BreakoutGame_fgcolor_var;
	result += '\n\tYDISPSIZE = ' + this.BreakoutGame_YDISPSIZE_var;
	result += '\n\tcounter = ' + this.BreakoutGame_counter_var;
	result += '\n\tpady = ' + this.BreakoutGame_pady_var;
	result += '\n\tLEFT = ' + this.BreakoutGame_LEFT_var;
	result += '\n\tBRICK_HEIGHT = ' + this.BreakoutGame_BRICK_HEIGHT_var;
	result += '\n\tdx = ' + this.BreakoutGame_dx_var;
	result += '\n\tprevPY = ' + this.BreakoutGame_prevPY_var;
	result += '\n\tpadlen = ' + this.BreakoutGame_padlen_var;
	result += '\n\tby = ' + this.BreakoutGame_by_var;
	result += '\n\tBRICK_ROWS = ' + this.BreakoutGame_BRICK_ROWS_var;
	result += '';
	return result;
}

module.exports = BreakoutGameNodeJS;
