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
		const createsent_log_174_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0D, xsize_172_var, ysize_173_var];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', createsent_log_174_var, 6));
	});
	let BreakoutGame_SC_LAUNCH = new StateJS.State('LAUNCH', this._statemachine).entry(() => {
		const id_194_var = 0;
		const time_195_var = this.BreakoutGame_period_var;
		this.bus.emit('clock', new Event.Timer_start_TimerMsgs(this.name, 'clock', id_194_var, time_195_var));
		const timer_startsent_log_196_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x14, id_194_var, (((time_195_var >> 8) & 0xFF)), (((time_195_var >> 0) & 0xFF))];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', timer_startsent_log_196_var, 7));
		const old_countdown_10_var = this.BreakoutGame_SC_LAUNCH_countdown_var;
		this.BreakoutGame_SC_LAUNCH_countdown_var = 3;
		const new_countdown_10_var = this.BreakoutGame_SC_LAUNCH_countdown_var;
		const countdown_log_10_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x1E, old_countdown_10_var, new_countdown_10_var];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', countdown_log_10_var, 5));
		this.drawScore();
		this.drawLives();
		this.bus.emit('display', new Event.Update_DisplayMsgs(this.name, 'display'));
		const updatesent_log_197_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0F];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', updatesent_log_197_var, 4));
	});
	let BreakoutGame_SC_PLAY = new StateJS.State('PLAY', this._statemachine).entry(() => {
		const id_203_var = 0;
		const time_204_var = this.BreakoutGame_period_var;
		this.bus.emit('clock', new Event.Timer_start_TimerMsgs(this.name, 'clock', id_203_var, time_204_var));
		const timer_startsent_log_205_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x14, id_203_var, (((time_204_var >> 8) & 0xFF)), (((time_204_var >> 0) & 0xFF))];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', timer_startsent_log_205_var, 7));
	});
	let BreakoutGame_SC_LOSTBALL = new StateJS.State('LOSTBALL', this._statemachine).entry(() => {
		const id_227_var = 0;
		const time_228_var = this.BreakoutGame_period_var;
		this.bus.emit('clock', new Event.Timer_start_TimerMsgs(this.name, 'clock', id_227_var, time_228_var));
		const timer_startsent_log_229_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x14, id_227_var, (((time_228_var >> 8) & 0xFF)), (((time_228_var >> 0) & 0xFF))];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', timer_startsent_log_229_var, 7));
		const old_lives_16_var = this.BreakoutGame_lives_var;
		this.BreakoutGame_lives_var = this.BreakoutGame_lives_var - 1;
		const new_lives_16_var = this.BreakoutGame_lives_var;
		const lives_log_16_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x1C, old_lives_16_var, new_lives_16_var];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', lives_log_16_var, 5));
		this.eraseBall();
		this.erasePad();
		this.drawLives();
		this.bus.emit('display', new Event.Update_DisplayMsgs(this.name, 'display'));
		const updatesent_log_230_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0F];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', updatesent_log_230_var, 4));
		this.log(true);
	});
	let BreakoutGame_SC_NEXTLEVEL = new StateJS.State('NEXTLEVEL', this._statemachine).entry(() => {
		const id_231_var = 0;
		const time_232_var = this.BreakoutGame_period_var;
		this.bus.emit('clock', new Event.Timer_start_TimerMsgs(this.name, 'clock', id_231_var, time_232_var));
		const timer_startsent_log_233_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x14, id_231_var, (((time_232_var >> 8) & 0xFF)), (((time_232_var >> 0) & 0xFF))];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', timer_startsent_log_233_var, 7));
		const old_level_2_var = this.BreakoutGame_level_var;
		this.BreakoutGame_level_var = this.BreakoutGame_level_var + 1;
		const new_level_2_var = this.BreakoutGame_level_var;
		const level_log_2_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x1D, old_level_2_var, new_level_2_var];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', level_log_2_var, 5));
		this.drawLevel();
		this.eraseBall();
		this.erasePad();
		if((this.BreakoutGame_level_var % 2) === 0 && this.BreakoutGame_padlen_var > 5 * this.BreakoutGame_SCALE_var) {
		const old_padlen_3_var = this.BreakoutGame_padlen_var;
		this.BreakoutGame_padlen_var = this.BreakoutGame_padlen_var - (4 * this.BreakoutGame_SCALE_var);
		const new_padlen_3_var = this.BreakoutGame_padlen_var;
		const padlen_log_3_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x10, (((old_padlen_3_var >> 8) & 0xFF)), (((old_padlen_3_var >> 0) & 0xFF)), (((new_padlen_3_var >> 8) & 0xFF)), (((new_padlen_3_var >> 0) & 0xFF))];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', padlen_log_3_var, 7));
		
		}
		if((this.BreakoutGame_level_var % 2) === 1) {
		const old_dy_8_var = this.BreakoutGame_dy_var;
		this.BreakoutGame_dy_var = Math.trunc((this.BreakoutGame_dy_var * 3) / 2);
		const new_dy_8_var = this.BreakoutGame_dy_var;
		const dy_log_8_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x0D, (((old_dy_8_var >> 8) & 0xFF)), (((old_dy_8_var >> 0) & 0xFF)), (((new_dy_8_var >> 8) & 0xFF)), (((new_dy_8_var >> 0) & 0xFF))];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', dy_log_8_var, 7));
		
		}
		this.drawLives();
		this.createBricks();
		this.bus.emit('display', new Event.Update_DisplayMsgs(this.name, 'display'));
		const updatesent_log_234_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0F];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', updatesent_log_234_var, 4));
	});
	let BreakoutGame_SC_GAMEOVER = new StateJS.State('GAMEOVER', this._statemachine).entry(() => {
		this.eraseBall();
		this.erasePad();
		const r_235_var = 255;
		const g_236_var = 255;
		const b_237_var = 255;
		this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_235_var, g_236_var, b_237_var));
		const setColorsent_log_238_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_235_var, g_236_var, b_237_var];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', setColorsent_log_238_var, 7));
		const x_239_var = 8;
		const y_240_var = 30;
		const width_241_var = 142;
		const height_242_var = 76;
		this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_239_var, y_240_var, width_241_var, height_242_var));
		const fillRectsent_log_243_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_239_var, y_240_var, width_241_var, height_242_var];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', fillRectsent_log_243_var, 8));
		const r_244_var = this.BreakoutGame_fgcolor_var[0];
		const g_245_var = this.BreakoutGame_fgcolor_var[1];
		const b_246_var = this.BreakoutGame_fgcolor_var[2];
		this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_244_var, g_245_var, b_246_var));
		const setColorsent_log_247_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_244_var, g_245_var, b_246_var];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', setColorsent_log_247_var, 7));
		const x_248_var = 9;
		const y_249_var = 31;
		const width_250_var = 140;
		const height_251_var = 50;
		this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_248_var, y_249_var, width_250_var, height_251_var));
		const fillRectsent_log_252_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_248_var, y_249_var, width_250_var, height_251_var];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', fillRectsent_log_252_var, 8));
		const r_253_var = this.BreakoutGame_fgcolor_var[0];
		const g_254_var = this.BreakoutGame_fgcolor_var[1];
		const b_255_var = this.BreakoutGame_fgcolor_var[2];
		this.bus.emit('display', new Event.SetBGColor_DisplayMsgs(this.name, 'display', r_253_var, g_254_var, b_255_var));
		const setBGColorsent_log_256_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x08, r_253_var, g_254_var, b_255_var];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', setBGColorsent_log_256_var, 7));
		const r_257_var = 158;
		const g_258_var = 209;
		const b_259_var = 130;
		this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_257_var, g_258_var, b_259_var));
		const setColorsent_log_260_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_257_var, g_258_var, b_259_var];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', setColorsent_log_260_var, 7));
		const x_261_var = 23;
		const y_262_var = 40;
		const v_263_var = this.BreakoutGame_score_var;
		const digits_264_var = 5;
		const scale_265_var = 6;
		this.bus.emit('display', new Event.DrawInteger_DisplayMsgs(this.name, 'display', x_261_var, y_262_var, v_263_var, digits_264_var, scale_265_var));
		const drawIntegersent_log_266_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0B, x_261_var, y_262_var, (((v_263_var >> 8) & 0xFF)), (((v_263_var >> 0) & 0xFF)), digits_264_var, scale_265_var];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', drawIntegersent_log_266_var, 10));
		const x_267_var = 26;
		const y_268_var = 87;
		this.bus.emit('display', new Event.DrawThingML_DisplayMsgs(this.name, 'display', x_267_var, y_268_var));
		const drawThingMLsent_log_269_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0C, x_267_var, y_268_var];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', drawThingMLsent_log_269_var, 6));
		this.bus.emit('display', new Event.Update_DisplayMsgs(this.name, 'display'));
		const updatesent_log_270_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0F];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', updatesent_log_270_var, 4));
		this.log(true);
		this.BreakoutGame_stopTime_var = this.timestamp();
		this.quit();
		setImmediate(()=>this._stop());
	});
	_initial_BreakoutGame_SC.to(BreakoutGame_SC_INIT);
	BreakoutGame_SC_NEXTLEVEL.to(BreakoutGame_SC_LAUNCH).on(Event.Timer_timeout_TimerMsgs).when((timer_timeout) => {
		return timer_timeout.port === 'clock' && timer_timeout.type === 'timer_timeout' && (timer_timeout.id === 0);
	}).effect((timer_timeout) => {
		const timer_timeouthandled_log_282_var = [Enum.LogType_ENUM.MESSAGE_HANDLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x16, 0x05, 0x02, timer_timeout.id];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', timer_timeouthandled_log_282_var, 7));
	});
	BreakoutGame_SC_LAUNCH.to(BreakoutGame_SC_PLAY).on(Event.Timer_timeout_TimerMsgs).when((timer_timeout) => {
		return timer_timeout.port === 'clock' && timer_timeout.type === 'timer_timeout' && (timer_timeout.id === 0 && this.BreakoutGame_SC_LAUNCH_countdown_var === 0);
	}).effect((timer_timeout) => {
		const timer_timeouthandled_log_277_var = [Enum.LogType_ENUM.MESSAGE_HANDLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x16, 0x02, 0x03, timer_timeout.id];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', timer_timeouthandled_log_277_var, 7));
		this.drawCountDown(0);
		this.resetBall();
		this.bus.emit('display', new Event.Update_DisplayMsgs(this.name, 'display'));
		const updatesent_log_202_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0F];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', updatesent_log_202_var, 4));
	});
	BreakoutGame_SC_LAUNCH.on(Event.Timer_timeout).when((timer_timeout) => {
		return timer_timeout.port === 'clock' && timer_timeout.type === 'timer_timeout' && (timer_timeout.id === 0 && this.BreakoutGame_SC_LAUNCH_countdown_var > 0);
	}).effect((timer_timeout) => {
		const timer_timeouthandled_log_278_var = [Enum.LogType_ENUM.MESSAGE_HANDLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x16, 0x02, 0x00, timer_timeout.id];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', timer_timeouthandled_log_278_var, 7));
		const id_198_var = 0;
		const time_199_var = this.BreakoutGame_period_var;
		this.bus.emit('clock', new Event.Timer_start_TimerMsgs(this.name, 'clock', id_198_var, time_199_var));
		const timer_startsent_log_200_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x14, id_198_var, (((time_199_var >> 8) & 0xFF)), (((time_199_var >> 0) & 0xFF))];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', timer_startsent_log_200_var, 7));
		this.drawPad();
		if((this.BreakoutGame_SC_LAUNCH_countdown_var % 30) === 0) {
		this.drawCountDown(Math.trunc(this.BreakoutGame_SC_LAUNCH_countdown_var / 30));
		
		}
		const old_countdown_11_var = this.BreakoutGame_SC_LAUNCH_countdown_var;
		this.BreakoutGame_SC_LAUNCH_countdown_var = this.BreakoutGame_SC_LAUNCH_countdown_var - 1;
		const new_countdown_11_var = this.BreakoutGame_SC_LAUNCH_countdown_var;
		const countdown_log_11_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x1E, old_countdown_11_var, new_countdown_11_var];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', countdown_log_11_var, 5));
		this.bus.emit('display', new Event.Update_DisplayMsgs(this.name, 'display'));
		const updatesent_log_201_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0F];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', updatesent_log_201_var, 4));
	});
	BreakoutGame_SC_PLAY.on(Event.Timer_timeout).when((timer_timeout) => {
		return timer_timeout.port === 'clock' && timer_timeout.type === 'timer_timeout' && (timer_timeout.id === 0);
	}).effect((timer_timeout) => {
		const timer_timeouthandled_log_281_var = [Enum.LogType_ENUM.MESSAGE_HANDLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x16, 0x03, 0x00, timer_timeout.id];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', timer_timeouthandled_log_281_var, 7));
		const old_bx_22_var = this.BreakoutGame_bx_var;
		this.BreakoutGame_bx_var = this.BreakoutGame_bx_var + this.BreakoutGame_dx_var;
		const new_bx_22_var = this.BreakoutGame_bx_var;
		const bx_log_22_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x0A, (((old_bx_22_var >> 8) & 0xFF)), (((old_bx_22_var >> 0) & 0xFF)), (((new_bx_22_var >> 8) & 0xFF)), (((new_bx_22_var >> 0) & 0xFF))];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', bx_log_22_var, 7));
		const old_by_29_var = this.BreakoutGame_by_var;
		this.BreakoutGame_by_var = this.BreakoutGame_by_var + this.BreakoutGame_dy_var;
		const new_by_29_var = this.BreakoutGame_by_var;
		const by_log_29_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x0B, (((old_by_29_var >> 8) & 0xFF)), (((old_by_29_var >> 0) & 0xFF)), (((new_by_29_var >> 8) & 0xFF)), (((new_by_29_var >> 0) & 0xFF))];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', by_log_29_var, 7));
		let wl_var = this.BreakoutGame_LEFT_var + this.BreakoutGame_br_var;
		let wr_var = this.BreakoutGame_RIGHT_var - this.BreakoutGame_br_var;
		let wt_var = this.BreakoutGame_TOP_var + this.BreakoutGame_br_var;
		let wb_var = this.BreakoutGame_BOTTOM_var - this.BreakoutGame_br_var;
		if(this.BreakoutGame_bx_var < wl_var) {
		const old_dx_13_var = this.BreakoutGame_dx_var;
		this.BreakoutGame_dx_var =  -this.BreakoutGame_dx_var;
		const new_dx_13_var = this.BreakoutGame_dx_var;
		const dx_log_13_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x0C, (((old_dx_13_var >> 8) & 0xFF)), (((old_dx_13_var >> 0) & 0xFF)), (((new_dx_13_var >> 8) & 0xFF)), (((new_dx_13_var >> 0) & 0xFF))];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', dx_log_13_var, 7));
		const old_bx_23_var = this.BreakoutGame_bx_var;
		this.BreakoutGame_bx_var = 2 * wl_var - this.BreakoutGame_bx_var;
		const new_bx_23_var = this.BreakoutGame_bx_var;
		const bx_log_23_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x0A, (((old_bx_23_var >> 8) & 0xFF)), (((old_bx_23_var >> 0) & 0xFF)), (((new_bx_23_var >> 8) & 0xFF)), (((new_bx_23_var >> 0) & 0xFF))];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', bx_log_23_var, 7));
		this.incrementScore( -1);
		
		} else {
		if(this.BreakoutGame_bx_var > wr_var) {
		const old_dx_14_var = this.BreakoutGame_dx_var;
		this.BreakoutGame_dx_var =  -this.BreakoutGame_dx_var;
		const new_dx_14_var = this.BreakoutGame_dx_var;
		const dx_log_14_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x0C, (((old_dx_14_var >> 8) & 0xFF)), (((old_dx_14_var >> 0) & 0xFF)), (((new_dx_14_var >> 8) & 0xFF)), (((new_dx_14_var >> 0) & 0xFF))];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', dx_log_14_var, 7));
		const old_bx_24_var = this.BreakoutGame_bx_var;
		this.BreakoutGame_bx_var = 2 * wr_var - this.BreakoutGame_bx_var;
		const new_bx_24_var = this.BreakoutGame_bx_var;
		const bx_log_24_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x0A, (((old_bx_24_var >> 8) & 0xFF)), (((old_bx_24_var >> 0) & 0xFF)), (((new_bx_24_var >> 8) & 0xFF)), (((new_bx_24_var >> 0) & 0xFF))];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', bx_log_24_var, 7));
		this.incrementScore( -1);
		
		}
		
		}
		if(this.BreakoutGame_by_var < wt_var) {
		const old_dy_5_var = this.BreakoutGame_dy_var;
		this.BreakoutGame_dy_var =  -this.BreakoutGame_dy_var;
		const new_dy_5_var = this.BreakoutGame_dy_var;
		const dy_log_5_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x0D, (((old_dy_5_var >> 8) & 0xFF)), (((old_dy_5_var >> 0) & 0xFF)), (((new_dy_5_var >> 8) & 0xFF)), (((new_dy_5_var >> 0) & 0xFF))];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', dy_log_5_var, 7));
		const old_by_30_var = this.BreakoutGame_by_var;
		this.BreakoutGame_by_var = 2 * wt_var - this.BreakoutGame_by_var;
		const new_by_30_var = this.BreakoutGame_by_var;
		const by_log_30_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x0B, (((old_by_30_var >> 8) & 0xFF)), (((old_by_30_var >> 0) & 0xFF)), (((new_by_30_var >> 8) & 0xFF)), (((new_by_30_var >> 0) & 0xFF))];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', by_log_30_var, 7));
		this.incrementScore( -1);
		
		} else {
		if(this.BreakoutGame_by_var > wb_var) {
		this.bus.emit('game', new Event.LostBall_BreakoutGame(this.name, 'game'));
		const lostBallsent_log_206_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x05, 0x01];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', lostBallsent_log_206_var, 4));
		this.bus.emit('req_game', new Event.LostBall_BreakoutGame(this.name, 'req_game'));
		const lostBallsent_log_207_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x06, 0x01];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', lostBallsent_log_207_var, 4));
		
		}
		
		}
		if(this.BreakoutGame_dy_var > 0) {
		if(this.BreakoutGame_by_var > this.BreakoutGame_pady_var - this.BreakoutGame_br_var && this.BreakoutGame_by_var < this.BreakoutGame_pady_var + this.BreakoutGame_br_var) {
		if(this.BreakoutGame_bx_var > this.BreakoutGame_padx_var - Math.trunc(this.BreakoutGame_padlen_var / 2) && this.BreakoutGame_bx_var < this.BreakoutGame_padx_var + Math.trunc(this.BreakoutGame_padlen_var / 2)) {
		const old_dy_6_var = this.BreakoutGame_dy_var;
		this.BreakoutGame_dy_var =  -this.BreakoutGame_dy_var;
		const new_dy_6_var = this.BreakoutGame_dy_var;
		const dy_log_6_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x0D, (((old_dy_6_var >> 8) & 0xFF)), (((old_dy_6_var >> 0) & 0xFF)), (((new_dy_6_var >> 8) & 0xFF)), (((new_dy_6_var >> 0) & 0xFF))];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', dy_log_6_var, 7));
		const old_by_31_var = this.BreakoutGame_by_var;
		this.BreakoutGame_by_var = 2 * (this.BreakoutGame_pady_var - this.BreakoutGame_br_var) - this.BreakoutGame_by_var;
		const new_by_31_var = this.BreakoutGame_by_var;
		const by_log_31_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x0B, (((old_by_31_var >> 8) & 0xFF)), (((old_by_31_var >> 0) & 0xFF)), (((new_by_31_var >> 8) & 0xFF)), (((new_by_31_var >> 0) & 0xFF))];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', by_log_31_var, 7));
		const old_dx_15_var = this.BreakoutGame_dx_var;
		this.BreakoutGame_dx_var = Math.trunc(this.BreakoutGame_dx_var / 4) + Math.trunc((this.BreakoutGame_bx_var - this.BreakoutGame_padx_var) / 4);
		const new_dx_15_var = this.BreakoutGame_dx_var;
		const dx_log_15_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x0C, (((old_dx_15_var >> 8) & 0xFF)), (((old_dx_15_var >> 0) & 0xFF)), (((new_dx_15_var >> 8) & 0xFF)), (((new_dx_15_var >> 0) & 0xFF))];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', dx_log_15_var, 7));
		
		}
		
		}
		
		}
		let collision_var = this.collideBrick(this.BreakoutGame_bx_var - this.BreakoutGame_br_var, this.BreakoutGame_by_var - this.BreakoutGame_br_var) || this.collideBrick(this.BreakoutGame_bx_var + this.BreakoutGame_br_var, this.BreakoutGame_by_var - this.BreakoutGame_br_var) || this.collideBrick(this.BreakoutGame_bx_var + this.BreakoutGame_br_var, this.BreakoutGame_by_var + this.BreakoutGame_br_var) || this.collideBrick(this.BreakoutGame_bx_var - this.BreakoutGame_br_var, this.BreakoutGame_by_var + this.BreakoutGame_br_var);
		if(collision_var) {
		const old_dy_7_var = this.BreakoutGame_dy_var;
		this.BreakoutGame_dy_var =  -this.BreakoutGame_dy_var;
		const new_dy_7_var = this.BreakoutGame_dy_var;
		const dy_log_7_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x0D, (((old_dy_7_var >> 8) & 0xFF)), (((old_dy_7_var >> 0) & 0xFF)), (((new_dy_7_var >> 8) & 0xFF)), (((new_dy_7_var >> 0) & 0xFF))];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', dy_log_7_var, 7));
		this.incrementScore(10);
		if(this.bricksLeft() === 0) {
		this.bus.emit('game', new Event.NextLevel_BreakoutGame(this.name, 'game'));
		const nextLevelsent_log_208_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x05, 0x02];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', nextLevelsent_log_208_var, 4));
		this.bus.emit('req_game', new Event.NextLevel_BreakoutGame(this.name, 'req_game'));
		const nextLevelsent_log_209_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x06, 0x02];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', nextLevelsent_log_209_var, 4));
		
		}
		
		}
		this.drawBall();
		this.drawPad();
		const ballx_210_var = this.BreakoutGame_bx_var;
		const bally_211_var = this.BreakoutGame_by_var;
		const padx_212_var = this.BreakoutGame_padx_var;
		const pady_213_var = this.BreakoutGame_pady_var;
		this.bus.emit('ia', new Event.UpdateIA_IAControllerMsg(this.name, 'ia', ballx_210_var, bally_211_var, padx_212_var, pady_213_var));
		const updateIAsent_log_214_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x04, 0x13, (((ballx_210_var >> 8) & 0xFF)), (((ballx_210_var >> 0) & 0xFF)), (((bally_211_var >> 8) & 0xFF)), (((bally_211_var >> 0) & 0xFF)), (((padx_212_var >> 8) & 0xFF)), (((padx_212_var >> 0) & 0xFF)), (((pady_213_var >> 8) & 0xFF)), (((pady_213_var >> 0) & 0xFF))];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', updateIAsent_log_214_var, 12));
		this.bus.emit('display', new Event.Update_DisplayMsgs(this.name, 'display'));
		const updatesent_log_215_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0F];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', updatesent_log_215_var, 4));
		this.log(false);
		const id_216_var = 0;
		const time_217_var = this.BreakoutGame_period_var;
		this.bus.emit('clock', new Event.Timer_start_TimerMsgs(this.name, 'clock', id_216_var, time_217_var));
		const timer_startsent_log_218_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x14, id_216_var, (((time_217_var >> 8) & 0xFF)), (((time_217_var >> 0) & 0xFF))];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', timer_startsent_log_218_var, 7));
	});
	BreakoutGame_SC_LOSTBALL.to(BreakoutGame_SC_LAUNCH).on(Event.Timer_timeout_TimerMsgs).when((timer_timeout) => {
		return timer_timeout.port === 'clock' && timer_timeout.type === 'timer_timeout' && (timer_timeout.id === 0 && this.BreakoutGame_lives_var > 0);
	}).effect((timer_timeout) => {
		const timer_timeouthandled_log_279_var = [Enum.LogType_ENUM.MESSAGE_HANDLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x16, 0x04, 0x02, timer_timeout.id];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', timer_timeouthandled_log_279_var, 7));
	});
	BreakoutGame_SC_LOSTBALL.to(BreakoutGame_SC_GAMEOVER).on(Event.Timer_timeout_TimerMsgs).when((timer_timeout) => {
		return timer_timeout.port === 'clock' && timer_timeout.type === 'timer_timeout' && (timer_timeout.id === 0 && this.BreakoutGame_lives_var === 0);
	}).effect((timer_timeout) => {
		const timer_timeouthandled_log_280_var = [Enum.LogType_ENUM.MESSAGE_HANDLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x16, 0x04, 0x06, timer_timeout.id];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', timer_timeouthandled_log_280_var, 7));
	});
	this._statemachine.on(Event.Timer_timeout).when((timer_timeout) => {
		return timer_timeout.port === 'clock' && timer_timeout.type === 'timer_timeout' && (true);
	}).effect((timer_timeout) => {
		const timer_timeoutlost_log_283_var = [Enum.LogType_ENUM.MESSAGE_LOST, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x16, timer_timeout.id];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', timer_timeoutlost_log_283_var, 5));
	});
	BreakoutGame_SC_PLAY.to(BreakoutGame_SC_LOSTBALL).on(Event.LostBall_BreakoutGame).when((lostBall) => {
		return lostBall.port === 'game' && lostBall.type === 'lostBall';
	}).effect((lostBall) => {
		const lostBallhandled_log_273_var = [Enum.LogType_ENUM.MESSAGE_HANDLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x05, 0x01, 0x03, 0x04];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', lostBallhandled_log_273_var, 6));
		const id_219_var = 0;
		this.bus.emit('clock', new Event.Timer_cancel_TimerMsgs(this.name, 'clock', id_219_var));
		const timer_cancelsent_log_220_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x15, id_219_var];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', timer_cancelsent_log_220_var, 5));
	});
	this._statemachine.on(Event.LostBall).when((lostBall) => {
		return lostBall.port === 'game' && lostBall.type === 'lostBall' && (true);
	}).effect((lostBall) => {
		const lostBalllost_log_285_var = [Enum.LogType_ENUM.MESSAGE_LOST, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x05, 0x01];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', lostBalllost_log_285_var, 4));
	});
	BreakoutGame_SC_PLAY.to(BreakoutGame_SC_NEXTLEVEL).on(Event.NextLevel_BreakoutGame).when((nextLevel) => {
		return nextLevel.port === 'game' && nextLevel.type === 'nextLevel';
	}).effect((nextLevel) => {
		const nextLevelhandled_log_274_var = [Enum.LogType_ENUM.MESSAGE_HANDLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x05, 0x02, 0x03, 0x05];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', nextLevelhandled_log_274_var, 6));
		const id_221_var = 0;
		this.bus.emit('clock', new Event.Timer_cancel_TimerMsgs(this.name, 'clock', id_221_var));
		const timer_cancelsent_log_222_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x15, id_221_var];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', timer_cancelsent_log_222_var, 5));
	});
	this._statemachine.on(Event.NextLevel).when((nextLevel) => {
		return nextLevel.port === 'game' && nextLevel.type === 'nextLevel' && (true);
	}).effect((nextLevel) => {
		const nextLevellost_log_286_var = [Enum.LogType_ENUM.MESSAGE_LOST, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x05, 0x02];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', nextLevellost_log_286_var, 4));
	});
	BreakoutGame_SC_INIT.to(BreakoutGame_SC_LAUNCH).on(Event.DisplayReady_DisplayMsgs).when((displayReady) => {
		return displayReady.port === 'display' && displayReady.type === 'displayReady';
	}).effect((displayReady) => {
		const displayReadyhandled_log_276_var = [Enum.LogType_ENUM.MESSAGE_HANDLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x10, 0x01, 0x02];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', displayReadyhandled_log_276_var, 6));
		this.bus.emit('display', new Event.Clear_DisplayMsgs(this.name, 'display'));
		const clearsent_log_175_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x06];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', clearsent_log_175_var, 4));
		this.initColors();
		const r_176_var = this.BreakoutGame_bgcolor_var[0];
		const g_177_var = this.BreakoutGame_bgcolor_var[1];
		const b_178_var = this.BreakoutGame_bgcolor_var[2];
		this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_176_var, g_177_var, b_178_var));
		const setColorsent_log_179_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_176_var, g_177_var, b_178_var];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', setColorsent_log_179_var, 7));
		const x_180_var = 0;
		const y_181_var = 0;
		const width_182_var = this.BreakoutGame_XDISPSIZE_var;
		const height_183_var = this.BreakoutGame_YDISPSIZE_var;
		this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_180_var, y_181_var, width_182_var, height_183_var));
		const fillRectsent_log_184_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_180_var, y_181_var, width_182_var, height_183_var];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', fillRectsent_log_184_var, 8));
		const r_185_var = this.BreakoutGame_fgcolor_var[0];
		const g_186_var = this.BreakoutGame_fgcolor_var[1];
		const b_187_var = this.BreakoutGame_fgcolor_var[2];
		this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_185_var, g_186_var, b_187_var));
		const setColorsent_log_188_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_185_var, g_186_var, b_187_var];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', setColorsent_log_188_var, 7));
		const x_189_var = 0;
		const y_190_var = 0;
		const width_191_var = this.BreakoutGame_XDISPSIZE_var;
		const height_192_var = 14;
		this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_189_var, y_190_var, width_191_var, height_192_var));
		const fillRectsent_log_193_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_189_var, y_190_var, width_191_var, height_192_var];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', fillRectsent_log_193_var, 8));
		this.drawWalls();
		this.createBricks();
		this.drawLevel();
	});
	this._statemachine.on(Event.DisplayReady).when((displayReady) => {
		return displayReady.port === 'display' && displayReady.type === 'displayReady' && (true);
	}).effect((displayReady) => {
		const displayReadylost_log_284_var = [Enum.LogType_ENUM.MESSAGE_LOST, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x10];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', displayReadylost_log_284_var, 4));
	});
	BreakoutGame_SC_PLAY.to(BreakoutGame_SC_LOSTBALL).on(Event.LostBall_BreakoutGame).when((lostBall) => {
		return lostBall.port === 'pro_game' && lostBall.type === 'lostBall';
	}).effect((lostBall) => {
		const lostBallhandled_log_271_var = [Enum.LogType_ENUM.MESSAGE_HANDLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x07, 0x01, 0x03, 0x04];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', lostBallhandled_log_271_var, 6));
		const id_223_var = 0;
		this.bus.emit('clock', new Event.Timer_cancel_TimerMsgs(this.name, 'clock', id_223_var));
		const timer_cancelsent_log_224_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x15, id_223_var];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', timer_cancelsent_log_224_var, 5));
	});
	this._statemachine.on(Event.LostBall).when((lostBall) => {
		return lostBall.port === 'pro_game' && lostBall.type === 'lostBall' && (true);
	}).effect((lostBall) => {
		const lostBalllost_log_287_var = [Enum.LogType_ENUM.MESSAGE_LOST, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x07, 0x01];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', lostBalllost_log_287_var, 4));
	});
	BreakoutGame_SC_PLAY.to(BreakoutGame_SC_NEXTLEVEL).on(Event.NextLevel_BreakoutGame).when((nextLevel) => {
		return nextLevel.port === 'pro_game' && nextLevel.type === 'nextLevel';
	}).effect((nextLevel) => {
		const nextLevelhandled_log_272_var = [Enum.LogType_ENUM.MESSAGE_HANDLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x07, 0x02, 0x03, 0x05];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', nextLevelhandled_log_272_var, 6));
		const id_225_var = 0;
		this.bus.emit('clock', new Event.Timer_cancel_TimerMsgs(this.name, 'clock', id_225_var));
		const timer_cancelsent_log_226_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x15, id_225_var];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', timer_cancelsent_log_226_var, 5));
	});
	this._statemachine.on(Event.NextLevel).when((nextLevel) => {
		return nextLevel.port === 'pro_game' && nextLevel.type === 'nextLevel' && (true);
	}).effect((nextLevel) => {
		const nextLevellost_log_288_var = [Enum.LogType_ENUM.MESSAGE_LOST, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x07, 0x02];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', nextLevellost_log_288_var, 4));
	});
	this._statemachine.on(Event.Position).when((position) => {
		return position.port === 'controller' && position.type === 'position';
	}).effect((position) => {
		const positionhandled_log_275_var = [Enum.LogType_ENUM.MESSAGE_HANDLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x03, 0x12, 0x00, 0x00, (((position.x >> 8) & 0xFF)), (((position.x >> 0) & 0xFF)), (((position.y >> 8) & 0xFF)), (((position.y >> 0) & 0xFF))];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', positionhandled_log_275_var, 10));
		let center_var = (this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var - this.BreakoutGame_padlen_var);
		center_var = position.x * center_var;
		center_var = Math.trunc(center_var / 200);
		const old_padx_9_var = this.BreakoutGame_padx_var;
		this.BreakoutGame_padx_var = (this.BreakoutGame_LEFT_var + center_var + Math.trunc((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / 2));
		const new_padx_9_var = this.BreakoutGame_padx_var;
		const padx_log_9_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x0E, (((old_padx_9_var >> 8) & 0xFF)), (((old_padx_9_var >> 0) & 0xFF)), (((new_padx_9_var >> 8) & 0xFF)), (((new_padx_9_var >> 0) & 0xFF))];
		this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', padx_log_9_var, 7));
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
	const r_0_var = this.BreakoutGame_bgcolor_var[0];
	const g_1_var = this.BreakoutGame_bgcolor_var[1];
	const b_2_var = this.BreakoutGame_bgcolor_var[2];
	this.bus.emit('display', new Event.SetBGColor_DisplayMsgs(this.name, 'display', r_0_var, g_1_var, b_2_var));
	const setBGColorsent_log_3_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x08, r_0_var, g_1_var, b_2_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', setBGColorsent_log_3_var, 7));
	const r_4_var = this.BreakoutGame_fgcolor_var[0];
	const g_5_var = this.BreakoutGame_fgcolor_var[1];
	const b_6_var = this.BreakoutGame_fgcolor_var[2];
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_4_var, g_5_var, b_6_var));
	const setColorsent_log_7_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_4_var, g_5_var, b_6_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', setColorsent_log_7_var, 7));
	const initColors_log0_var = [Enum.LogType_ENUM.FUNCTION_CALLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x00];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', initColors_log0_var, 4));
}

BreakoutGameNodeJS.prototype.resetBall = function() {
	const old_bx_21_var = this.BreakoutGame_bx_var;
	this.BreakoutGame_bx_var = this.BreakoutGame_padx_var - Math.trunc(this.BreakoutGame_br_var / this.BreakoutGame_SCALE_var);
	const new_bx_21_var = this.BreakoutGame_bx_var;
	const bx_log_21_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x0A, (((old_bx_21_var >> 8) & 0xFF)), (((old_bx_21_var >> 0) & 0xFF)), (((new_bx_21_var >> 8) & 0xFF)), (((new_bx_21_var >> 0) & 0xFF))];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', bx_log_21_var, 7));
	const old_by_28_var = this.BreakoutGame_by_var;
	this.BreakoutGame_by_var = this.BreakoutGame_pady_var - Math.trunc(this.BreakoutGame_br_var / this.BreakoutGame_SCALE_var);
	const new_by_28_var = this.BreakoutGame_by_var;
	const by_log_28_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x0B, (((old_by_28_var >> 8) & 0xFF)), (((old_by_28_var >> 0) & 0xFF)), (((new_by_28_var >> 8) & 0xFF)), (((new_by_28_var >> 0) & 0xFF))];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', by_log_28_var, 7));
	const old_dx_12_var = this.BreakoutGame_dx_var;
	this.BreakoutGame_dx_var = (this.BreakoutGame_padx_var + this.BreakoutGame_prevBX_var + this.BreakoutGame_prevBY_var) % 300 - 150;
	const new_dx_12_var = this.BreakoutGame_dx_var;
	const dx_log_12_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x0C, (((old_dx_12_var >> 8) & 0xFF)), (((old_dx_12_var >> 0) & 0xFF)), (((new_dx_12_var >> 8) & 0xFF)), (((new_dx_12_var >> 0) & 0xFF))];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', dx_log_12_var, 7));
	if(this.BreakoutGame_dy_var > 0) {
	const old_dy_4_var = this.BreakoutGame_dy_var;
	this.BreakoutGame_dy_var =  -this.BreakoutGame_dy_var;
	const new_dy_4_var = this.BreakoutGame_dy_var;
	const dy_log_4_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x0D, (((old_dy_4_var >> 8) & 0xFF)), (((old_dy_4_var >> 0) & 0xFF)), (((new_dy_4_var >> 8) & 0xFF)), (((new_dy_4_var >> 0) & 0xFF))];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', dy_log_4_var, 7));
	
	}
	const old_prevBX_25_var = this.BreakoutGame_prevBX_var;
	this.BreakoutGame_prevBX_var =  -1;
	const new_prevBX_25_var = this.BreakoutGame_prevBX_var;
	const prevBX_log_25_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x11, (((old_prevBX_25_var >> 8) & 0xFF)), (((old_prevBX_25_var >> 0) & 0xFF)), (((new_prevBX_25_var >> 8) & 0xFF)), (((new_prevBX_25_var >> 0) & 0xFF))];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', prevBX_log_25_var, 7));
	const old_prevBY_17_var = this.BreakoutGame_prevBY_var;
	this.BreakoutGame_prevBY_var =  -1;
	const new_prevBY_17_var = this.BreakoutGame_prevBY_var;
	const prevBY_log_17_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x12, (((old_prevBY_17_var >> 8) & 0xFF)), (((old_prevBY_17_var >> 0) & 0xFF)), (((new_prevBY_17_var >> 8) & 0xFF)), (((new_prevBY_17_var >> 0) & 0xFF))];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', prevBY_log_17_var, 7));
	const resetBall_log1_var = [Enum.LogType_ENUM.FUNCTION_CALLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x00];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', resetBall_log1_var, 4));
}

BreakoutGameNodeJS.prototype.eraseBall = function() {
	let bs_var = Math.trunc((this.BreakoutGame_br_var * 2) / this.BreakoutGame_SCALE_var);
	if(this.BreakoutGame_prevBX_var > 0) {
	const r_8_var = this.BreakoutGame_bgcolor_var[0];
	const g_9_var = this.BreakoutGame_bgcolor_var[1];
	const b_10_var = this.BreakoutGame_bgcolor_var[2];
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_8_var, g_9_var, b_10_var));
	const setColorsent_log_11_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_8_var, g_9_var, b_10_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', setColorsent_log_11_var, 7));
	const x_12_var = this.BreakoutGame_prevBX_var;
	const y_13_var = this.BreakoutGame_prevBY_var;
	const width_14_var = bs_var;
	const height_15_var = bs_var;
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_12_var, y_13_var, width_14_var, height_15_var));
	const fillRectsent_log_16_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_12_var, y_13_var, width_14_var, height_15_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', fillRectsent_log_16_var, 8));
	
	}
	const old_prevBX_26_var = this.BreakoutGame_prevBX_var;
	this.BreakoutGame_prevBX_var =  -1;
	const new_prevBX_26_var = this.BreakoutGame_prevBX_var;
	const prevBX_log_26_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x11, (((old_prevBX_26_var >> 8) & 0xFF)), (((old_prevBX_26_var >> 0) & 0xFF)), (((new_prevBX_26_var >> 8) & 0xFF)), (((new_prevBX_26_var >> 0) & 0xFF))];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', prevBX_log_26_var, 7));
	const old_prevBY_18_var = this.BreakoutGame_prevBY_var;
	this.BreakoutGame_prevBY_var =  -1;
	const new_prevBY_18_var = this.BreakoutGame_prevBY_var;
	const prevBY_log_18_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x12, (((old_prevBY_18_var >> 8) & 0xFF)), (((old_prevBY_18_var >> 0) & 0xFF)), (((new_prevBY_18_var >> 8) & 0xFF)), (((new_prevBY_18_var >> 0) & 0xFF))];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', prevBY_log_18_var, 7));
	const eraseBall_log2_var = [Enum.LogType_ENUM.FUNCTION_CALLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x03, 0x00];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', eraseBall_log2_var, 4));
}

BreakoutGameNodeJS.prototype.drawBall = function() {
	let bs_var = Math.trunc((this.BreakoutGame_br_var * 2) / this.BreakoutGame_SCALE_var);
	this.eraseBall();
	const old_prevBX_27_var = this.BreakoutGame_prevBX_var;
	this.BreakoutGame_prevBX_var = Math.trunc((this.BreakoutGame_bx_var - this.BreakoutGame_br_var) / this.BreakoutGame_SCALE_var);
	const new_prevBX_27_var = this.BreakoutGame_prevBX_var;
	const prevBX_log_27_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x11, (((old_prevBX_27_var >> 8) & 0xFF)), (((old_prevBX_27_var >> 0) & 0xFF)), (((new_prevBX_27_var >> 8) & 0xFF)), (((new_prevBX_27_var >> 0) & 0xFF))];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', prevBX_log_27_var, 7));
	const old_prevBY_19_var = this.BreakoutGame_prevBY_var;
	this.BreakoutGame_prevBY_var = Math.trunc((this.BreakoutGame_by_var - this.BreakoutGame_br_var) / this.BreakoutGame_SCALE_var);
	const new_prevBY_19_var = this.BreakoutGame_prevBY_var;
	const prevBY_log_19_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x12, (((old_prevBY_19_var >> 8) & 0xFF)), (((old_prevBY_19_var >> 0) & 0xFF)), (((new_prevBY_19_var >> 8) & 0xFF)), (((new_prevBY_19_var >> 0) & 0xFF))];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', prevBY_log_19_var, 7));
	const r_17_var = 183;
	const g_18_var = 199;
	const b_19_var = 111;
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_17_var, g_18_var, b_19_var));
	const setColorsent_log_20_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_17_var, g_18_var, b_19_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', setColorsent_log_20_var, 7));
	const x_21_var = this.BreakoutGame_prevBX_var;
	const y_22_var = this.BreakoutGame_prevBY_var;
	const width_23_var = bs_var;
	const height_24_var = bs_var;
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_21_var, y_22_var, width_23_var, height_24_var));
	const fillRectsent_log_25_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_21_var, y_22_var, width_23_var, height_24_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', fillRectsent_log_25_var, 8));
	const drawBall_log3_var = [Enum.LogType_ENUM.FUNCTION_CALLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x04, 0x00];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', drawBall_log3_var, 4));
}

BreakoutGameNodeJS.prototype.erasePad = function() {
	let ps_var = Math.trunc(this.BreakoutGame_padlen_var / this.BreakoutGame_SCALE_var);
	if(this.BreakoutGame_prevPX_var > 0) {
	const r_26_var = this.BreakoutGame_bgcolor_var[0];
	const g_27_var = this.BreakoutGame_bgcolor_var[1];
	const b_28_var = this.BreakoutGame_bgcolor_var[2];
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_26_var, g_27_var, b_28_var));
	const setColorsent_log_29_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_26_var, g_27_var, b_28_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', setColorsent_log_29_var, 7));
	const x_30_var = this.BreakoutGame_prevPX_var;
	const y_31_var = this.BreakoutGame_prevPY_var;
	const width_32_var = ps_var;
	const height_33_var = 4;
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_30_var, y_31_var, width_32_var, height_33_var));
	const fillRectsent_log_34_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_30_var, y_31_var, width_32_var, height_33_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', fillRectsent_log_34_var, 8));
	
	}
	const erasePad_log4_var = [Enum.LogType_ENUM.FUNCTION_CALLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x05, 0x00];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', erasePad_log4_var, 4));
}

BreakoutGameNodeJS.prototype.drawPad = function() {
	let ps_var = Math.trunc(this.BreakoutGame_padlen_var / this.BreakoutGame_SCALE_var);
	this.erasePad();
	const old_prevPX_20_var = this.BreakoutGame_prevPX_var;
	this.BreakoutGame_prevPX_var = Math.trunc((this.BreakoutGame_padx_var - (Math.trunc(this.BreakoutGame_padlen_var / 2))) / this.BreakoutGame_SCALE_var);
	const new_prevPX_20_var = this.BreakoutGame_prevPX_var;
	const prevPX_log_20_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x16, (((old_prevPX_20_var >> 8) & 0xFF)), (((old_prevPX_20_var >> 0) & 0xFF)), (((new_prevPX_20_var >> 8) & 0xFF)), (((new_prevPX_20_var >> 0) & 0xFF))];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', prevPX_log_20_var, 7));
	const old_prevPY_32_var = this.BreakoutGame_prevPY_var;
	this.BreakoutGame_prevPY_var = Math.trunc(this.BreakoutGame_pady_var / this.BreakoutGame_SCALE_var);
	const new_prevPY_32_var = this.BreakoutGame_prevPY_var;
	const prevPY_log_32_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x17, (((old_prevPY_32_var >> 8) & 0xFF)), (((old_prevPY_32_var >> 0) & 0xFF)), (((new_prevPY_32_var >> 8) & 0xFF)), (((new_prevPY_32_var >> 0) & 0xFF))];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', prevPY_log_32_var, 7));
	const r_35_var = this.BreakoutGame_fgcolor_var[0];
	const g_36_var = this.BreakoutGame_fgcolor_var[1];
	const b_37_var = this.BreakoutGame_fgcolor_var[2];
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_35_var, g_36_var, b_37_var));
	const setColorsent_log_38_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_35_var, g_36_var, b_37_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', setColorsent_log_38_var, 7));
	const x_39_var = this.BreakoutGame_prevPX_var;
	const y_40_var = this.BreakoutGame_prevPY_var;
	const width_41_var = ps_var;
	const height_42_var = 4;
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_39_var, y_40_var, width_41_var, height_42_var));
	const fillRectsent_log_43_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_39_var, y_40_var, width_41_var, height_42_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', fillRectsent_log_43_var, 8));
	const drawPad_log5_var = [Enum.LogType_ENUM.FUNCTION_CALLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x06, 0x00];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', drawPad_log5_var, 4));
}

BreakoutGameNodeJS.prototype.drawCountDown = function(BreakoutGame_drawCountDown_c_var) {
	const r_44_var = this.BreakoutGame_fgcolor_var[0];
	const g_45_var = this.BreakoutGame_fgcolor_var[1];
	const b_46_var = this.BreakoutGame_fgcolor_var[2];
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_44_var, g_45_var, b_46_var));
	const setColorsent_log_47_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_44_var, g_45_var, b_46_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', setColorsent_log_47_var, 7));
	if(BreakoutGame_drawCountDown_c_var > 0) {
	const r_48_var = this.BreakoutGame_fgcolor_var[0];
	const g_49_var = this.BreakoutGame_fgcolor_var[1];
	const b_50_var = this.BreakoutGame_fgcolor_var[2];
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_48_var, g_49_var, b_50_var));
	const setColorsent_log_51_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_48_var, g_49_var, b_50_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', setColorsent_log_51_var, 7));
	const r_52_var = this.BreakoutGame_bgcolor_var[0];
	const g_53_var = this.BreakoutGame_bgcolor_var[1];
	const b_54_var = this.BreakoutGame_bgcolor_var[2];
	this.bus.emit('display', new Event.SetBGColor_DisplayMsgs(this.name, 'display', r_52_var, g_53_var, b_54_var));
	const setBGColorsent_log_55_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x08, r_52_var, g_53_var, b_54_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', setBGColorsent_log_55_var, 7));
	const x_56_var = 80 - 6;
	const y_57_var = 90;
	const v_58_var = BreakoutGame_drawCountDown_c_var;
	const digits_59_var = 1;
	const scale_60_var = 4;
	this.bus.emit('display', new Event.DrawInteger_DisplayMsgs(this.name, 'display', x_56_var, y_57_var, v_58_var, digits_59_var, scale_60_var));
	const drawIntegersent_log_61_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0B, x_56_var, y_57_var, (((v_58_var >> 8) & 0xFF)), (((v_58_var >> 0) & 0xFF)), digits_59_var, scale_60_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', drawIntegersent_log_61_var, 10));
	
	} else {
	const r_62_var = this.BreakoutGame_bgcolor_var[0];
	const g_63_var = this.BreakoutGame_bgcolor_var[1];
	const b_64_var = this.BreakoutGame_bgcolor_var[2];
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_62_var, g_63_var, b_64_var));
	const setColorsent_log_65_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_62_var, g_63_var, b_64_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', setColorsent_log_65_var, 7));
	const x_66_var = 80 - 6;
	const y_67_var = 90;
	const width_68_var = 12;
	const height_69_var = 20;
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_66_var, y_67_var, width_68_var, height_69_var));
	const fillRectsent_log_70_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_66_var, y_67_var, width_68_var, height_69_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', fillRectsent_log_70_var, 8));
	
	}
	const drawCountDown_log6_var = [Enum.LogType_ENUM.FUNCTION_CALLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x07, 0x00, (((BreakoutGame_drawCountDown_c_var >> 8) & 0xFF)), (((BreakoutGame_drawCountDown_c_var >> 0) & 0xFF))];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', drawCountDown_log6_var, 6));
}

BreakoutGameNodeJS.prototype.drawWalls = function() {
	const r_71_var = this.BreakoutGame_fgcolor_var[0];
	const g_72_var = this.BreakoutGame_fgcolor_var[1];
	const b_73_var = this.BreakoutGame_fgcolor_var[2];
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_71_var, g_72_var, b_73_var));
	const setColorsent_log_74_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_71_var, g_72_var, b_73_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', setColorsent_log_74_var, 7));
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
	const fillRectsent_log_79_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_75_var, y_76_var, width_77_var, height_78_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', fillRectsent_log_79_var, 8));
	const x_80_var = left_var - 1;
	const y_81_var = bottom_var;
	const width_82_var = xcenter_var + 1;
	const height_83_var = 1;
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_80_var, y_81_var, width_82_var, height_83_var));
	const fillRectsent_log_84_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_80_var, y_81_var, width_82_var, height_83_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', fillRectsent_log_84_var, 8));
	const x_85_var = left_var - 1;
	const y_86_var = top_var;
	const width_87_var = 1;
	const height_88_var = ycenter_var;
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_85_var, y_86_var, width_87_var, height_88_var));
	const fillRectsent_log_89_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_85_var, y_86_var, width_87_var, height_88_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', fillRectsent_log_89_var, 8));
	const x_90_var = right_var;
	const y_91_var = top_var;
	const width_92_var = 1;
	const height_93_var = ycenter_var;
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_90_var, y_91_var, width_92_var, height_93_var));
	const fillRectsent_log_94_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_90_var, y_91_var, width_92_var, height_93_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', fillRectsent_log_94_var, 8));
	const drawWalls_log7_var = [Enum.LogType_ENUM.FUNCTION_CALLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x08, 0x00];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', drawWalls_log7_var, 4));
}

BreakoutGameNodeJS.prototype.bitIsSet = function(BreakoutGame_bitIsSet_variable_var, BreakoutGame_bitIsSet_bit_var) {
	const return_0_var = (((1 << BreakoutGame_bitIsSet_bit_var) & BreakoutGame_bitIsSet_variable_var) != 0);
	const bitIsSet_log8_var = [Enum.LogType_ENUM.FUNCTION_CALLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x09, 0x00, BreakoutGame_bitIsSet_variable_var, BreakoutGame_bitIsSet_bit_var, return_0_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', bitIsSet_log8_var, 7));
	return return_0_var;
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
	const createBricks_log9_var = [Enum.LogType_ENUM.FUNCTION_CALLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x0A, 0x00];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', createBricks_log9_var, 4));
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
	const bricksLeft_log10_var = [Enum.LogType_ENUM.FUNCTION_CALLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x0B, 0x00, return_3_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', bricksLeft_log10_var, 5));
	return return_3_var;
}

BreakoutGameNodeJS.prototype.drawBrick = function(BreakoutGame_drawBrick_x_var, BreakoutGame_drawBrick_y_var) {
	const bx_var = (Math.trunc((this.BreakoutGame_LEFT_var + (Math.trunc((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / 8)) * BreakoutGame_drawBrick_x_var) / this.BreakoutGame_SCALE_var) + 1);
	const by_var = (Math.trunc((this.BreakoutGame_TOP_var + 20 * this.BreakoutGame_SCALE_var + this.BreakoutGame_BRICK_HEIGHT_var * BreakoutGame_drawBrick_y_var * this.BreakoutGame_SCALE_var) / this.BreakoutGame_SCALE_var) + 1);
	const w_var = (Math.trunc((Math.trunc((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / 8)) / this.BreakoutGame_SCALE_var) - 2);
	const h_var = (this.BreakoutGame_BRICK_HEIGHT_var - 2);
	const r_95_var = 155;
	const g_96_var = 103;
	const b_97_var = 89;
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_95_var, g_96_var, b_97_var));
	const setColorsent_log_98_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_95_var, g_96_var, b_97_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', setColorsent_log_98_var, 7));
	const x_99_var = bx_var;
	const y_100_var = by_var;
	const width_101_var = w_var;
	const height_102_var = h_var;
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_99_var, y_100_var, width_101_var, height_102_var));
	const fillRectsent_log_103_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_99_var, y_100_var, width_101_var, height_102_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', fillRectsent_log_103_var, 8));
	const r_104_var = 100;
	const g_105_var = 56;
	const b_106_var = 43;
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_104_var, g_105_var, b_106_var));
	const setColorsent_log_107_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_104_var, g_105_var, b_106_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', setColorsent_log_107_var, 7));
	const x_108_var = bx_var;
	const y_109_var = by_var;
	const width_110_var = w_var;
	const height_111_var = h_var;
	this.bus.emit('display', new Event.DrawRect_DisplayMsgs(this.name, 'display', x_108_var, y_109_var, width_110_var, height_111_var));
	const drawRectsent_log_112_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x09, x_108_var, y_109_var, width_110_var, height_111_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', drawRectsent_log_112_var, 8));
	const drawBrick_log11_var = [Enum.LogType_ENUM.FUNCTION_CALLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x0C, 0x00, BreakoutGame_drawBrick_x_var, BreakoutGame_drawBrick_y_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', drawBrick_log11_var, 6));
}

BreakoutGameNodeJS.prototype.removeBrick = function(BreakoutGame_removeBrick_x_var, BreakoutGame_removeBrick_y_var) {
	const bx_var = (Math.trunc((this.BreakoutGame_LEFT_var + (Math.trunc((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / 8)) * BreakoutGame_removeBrick_x_var) / this.BreakoutGame_SCALE_var) + 1);
	const by_var = (Math.trunc((this.BreakoutGame_TOP_var + 20 * this.BreakoutGame_SCALE_var + this.BreakoutGame_BRICK_HEIGHT_var * BreakoutGame_removeBrick_y_var * this.BreakoutGame_SCALE_var) / this.BreakoutGame_SCALE_var) + 1);
	const r_113_var = this.BreakoutGame_bgcolor_var[0];
	const g_114_var = this.BreakoutGame_bgcolor_var[1];
	const b_115_var = this.BreakoutGame_bgcolor_var[2];
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_113_var, g_114_var, b_115_var));
	const setColorsent_log_116_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_113_var, g_114_var, b_115_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', setColorsent_log_116_var, 7));
	const x_117_var = bx_var;
	const y_118_var = by_var;
	const width_119_var = (Math.trunc((Math.trunc((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / 8)) / this.BreakoutGame_SCALE_var) - 2);
	const height_120_var = this.BreakoutGame_BRICK_HEIGHT_var - 2;
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_117_var, y_118_var, width_119_var, height_120_var));
	const fillRectsent_log_121_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_117_var, y_118_var, width_119_var, height_120_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', fillRectsent_log_121_var, 8));
	this.BreakoutGame_bricks_var[BreakoutGame_removeBrick_y_var] = this.unsetBit(this.BreakoutGame_bricks_var[BreakoutGame_removeBrick_y_var], BreakoutGame_removeBrick_x_var);
	const removeBrick_log12_var = [Enum.LogType_ENUM.FUNCTION_CALLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x0D, 0x00, BreakoutGame_removeBrick_x_var, BreakoutGame_removeBrick_y_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', removeBrick_log12_var, 6));
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
	const collideBrick_log13_var = [Enum.LogType_ENUM.FUNCTION_CALLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x0E, 0x00, (((BreakoutGame_collideBrick_xpos_var >> 8) & 0xFF)), (((BreakoutGame_collideBrick_xpos_var >> 0) & 0xFF)), (((BreakoutGame_collideBrick_ypos_var >> 8) & 0xFF)), (((BreakoutGame_collideBrick_ypos_var >> 0) & 0xFF)), return_3_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', collideBrick_log13_var, 9));
	return return_3_var;
}

BreakoutGameNodeJS.prototype.drawLevel = function() {
	const r_122_var = 158;
	const g_123_var = 209;
	const b_124_var = 130;
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_122_var, g_123_var, b_124_var));
	const setColorsent_log_125_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_122_var, g_123_var, b_124_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', setColorsent_log_125_var, 7));
	const r_126_var = this.BreakoutGame_fgcolor_var[0];
	const g_127_var = this.BreakoutGame_fgcolor_var[1];
	const b_128_var = this.BreakoutGame_fgcolor_var[2];
	this.bus.emit('display', new Event.SetBGColor_DisplayMsgs(this.name, 'display', r_126_var, g_127_var, b_128_var));
	const setBGColorsent_log_129_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x08, r_126_var, g_127_var, b_128_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', setBGColorsent_log_129_var, 7));
	const r_130_var = this.BreakoutGame_bgcolor_var[0];
	const g_131_var = this.BreakoutGame_bgcolor_var[1];
	const b_132_var = this.BreakoutGame_bgcolor_var[2];
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_130_var, g_131_var, b_132_var));
	const setColorsent_log_133_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_130_var, g_131_var, b_132_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', setColorsent_log_133_var, 7));
	const x_134_var = 6;
	const y_135_var = 2;
	const v_136_var = this.BreakoutGame_level_var;
	const digits_137_var = 2;
	const scale_138_var = 2;
	this.bus.emit('display', new Event.DrawInteger_DisplayMsgs(this.name, 'display', x_134_var, y_135_var, v_136_var, digits_137_var, scale_138_var));
	const drawIntegersent_log_139_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0B, x_134_var, y_135_var, (((v_136_var >> 8) & 0xFF)), (((v_136_var >> 0) & 0xFF)), digits_137_var, scale_138_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', drawIntegersent_log_139_var, 10));
	const drawLevel_log14_var = [Enum.LogType_ENUM.FUNCTION_CALLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x0F, 0x00];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', drawLevel_log14_var, 4));
}

BreakoutGameNodeJS.prototype.incrementScore = function(BreakoutGame_incrementScore_diff_var) {
	const old_score_0_var = this.BreakoutGame_score_var;
	this.BreakoutGame_score_var = this.BreakoutGame_score_var + BreakoutGame_incrementScore_diff_var;
	const new_score_0_var = this.BreakoutGame_score_var;
	const score_log_0_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x1B, (((old_score_0_var >> 8) & 0xFF)), (((old_score_0_var >> 0) & 0xFF)), (((new_score_0_var >> 8) & 0xFF)), (((new_score_0_var >> 0) & 0xFF))];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', score_log_0_var, 7));
	if(this.BreakoutGame_score_var < 0) {
	const old_score_1_var = this.BreakoutGame_score_var;
	this.BreakoutGame_score_var = 0;
	const new_score_1_var = this.BreakoutGame_score_var;
	const score_log_1_var = [Enum.LogType_ENUM.PROPERTY_CHANGED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x1B, (((old_score_1_var >> 8) & 0xFF)), (((old_score_1_var >> 0) & 0xFF)), (((new_score_1_var >> 8) & 0xFF)), (((new_score_1_var >> 0) & 0xFF))];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', score_log_1_var, 7));
	
	}
	this.drawScore();
	const incrementScore_log15_var = [Enum.LogType_ENUM.FUNCTION_CALLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x10, 0x00, BreakoutGame_incrementScore_diff_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', incrementScore_log15_var, 5));
}

BreakoutGameNodeJS.prototype.drawScore = function() {
	const r_140_var = 158;
	const g_141_var = 209;
	const b_142_var = 130;
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_140_var, g_141_var, b_142_var));
	const setColorsent_log_143_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_140_var, g_141_var, b_142_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', setColorsent_log_143_var, 7));
	const r_144_var = this.BreakoutGame_fgcolor_var[0];
	const g_145_var = this.BreakoutGame_fgcolor_var[1];
	const b_146_var = this.BreakoutGame_fgcolor_var[2];
	this.bus.emit('display', new Event.SetBGColor_DisplayMsgs(this.name, 'display', r_144_var, g_145_var, b_146_var));
	const setBGColorsent_log_147_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x08, r_144_var, g_145_var, b_146_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', setBGColorsent_log_147_var, 7));
	const x_148_var = 58;
	const y_149_var = 2;
	const v_150_var = this.BreakoutGame_score_var;
	const digits_151_var = 5;
	const scale_152_var = 2;
	this.bus.emit('display', new Event.DrawInteger_DisplayMsgs(this.name, 'display', x_148_var, y_149_var, v_150_var, digits_151_var, scale_152_var));
	const drawIntegersent_log_153_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0B, x_148_var, y_149_var, (((v_150_var >> 8) & 0xFF)), (((v_150_var >> 0) & 0xFF)), digits_151_var, scale_152_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', drawIntegersent_log_153_var, 10));
	const drawScore_log16_var = [Enum.LogType_ENUM.FUNCTION_CALLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x11, 0x00];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', drawScore_log16_var, 4));
}

BreakoutGameNodeJS.prototype.drawLives = function() {
	const r_154_var = this.BreakoutGame_fgcolor_var[0];
	const g_155_var = this.BreakoutGame_fgcolor_var[1];
	const b_156_var = this.BreakoutGame_fgcolor_var[2];
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_154_var, g_155_var, b_156_var));
	const setColorsent_log_157_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_154_var, g_155_var, b_156_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', setColorsent_log_157_var, 7));
	const x_158_var = 124;
	const y_159_var = 4;
	const width_160_var = 24 + 6;
	const height_161_var = 6;
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_158_var, y_159_var, width_160_var, height_161_var));
	const fillRectsent_log_162_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_158_var, y_159_var, width_160_var, height_161_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', fillRectsent_log_162_var, 8));
	const r_163_var = 183;
	const g_164_var = 199;
	const b_165_var = 111;
	this.bus.emit('display', new Event.SetColor_DisplayMsgs(this.name, 'display', r_163_var, g_164_var, b_165_var));
	const setColorsent_log_166_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_163_var, g_164_var, b_165_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', setColorsent_log_166_var, 7));
	let i_var = 0;
	while(i_var < this.BreakoutGame_lives_var) {
	const x_167_var = 124 + (2 - i_var) * 12;
	const y_168_var = 4;
	const width_169_var = 6;
	const height_170_var = 6;
	this.bus.emit('display', new Event.FillRect_DisplayMsgs(this.name, 'display', x_167_var, y_168_var, width_169_var, height_170_var));
	const fillRectsent_log_171_var = [Enum.LogType_ENUM.MESSAGE_SENT, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_167_var, y_168_var, width_169_var, height_170_var];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', fillRectsent_log_171_var, 8));
	i_var = i_var + 1;
	
	}
	const drawLives_log17_var = [Enum.LogType_ENUM.FUNCTION_CALLED, this.WithBinaryLog_DEBUG_BIN_ID_var, 0x12, 0x00];
	this.bus.emit('log', new Event.Log_LogMsgs(this.name, 'log', drawLives_log17_var, 4));
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
	result += '\n\tLEFT = ' + this.BreakoutGame_LEFT_var;
	result += '\n\tDEBUG_BIN_ID = ' + this.WithBinaryLog_DEBUG_BIN_ID_var;
	result += '\n\tBRICK_HEIGHT = ' + this.BreakoutGame_BRICK_HEIGHT_var;
	result += '\n\tby = ' + this.BreakoutGame_by_var;
	result += '\n\tlastTimestamp = ' + this.BreakoutGame_lastTimestamp_var;
	result += '\n\tSCALE = ' + this.BreakoutGame_SCALE_var;
	result += '\n\tstopTime = ' + this.BreakoutGame_stopTime_var;
	result += '\n\tdy = ' + this.BreakoutGame_dy_var;
	result += '\n\tpady = ' + this.BreakoutGame_pady_var;
	result += '\n\tdx = ' + this.BreakoutGame_dx_var;
	result += '\n\tXDISPSIZE = ' + this.BreakoutGame_XDISPSIZE_var;
	result += '\n\tRIGHT = ' + this.BreakoutGame_RIGHT_var;
	result += '\n\tXMAX = ' + this.BreakoutGame_XMAX_var;
	result += '\n\tprevPX = ' + this.BreakoutGame_prevPX_var;
	result += '\n\tpadlen = ' + this.BreakoutGame_padlen_var;
	result += '\n\tcounter = ' + this.BreakoutGame_counter_var;
	result += '\n\tstartTime = ' + this.BreakoutGame_startTime_var;
	result += '\n\tperiod = ' + this.BreakoutGame_period_var;
	result += '\n\tprevPY = ' + this.BreakoutGame_prevPY_var;
	result += '\n\tYMAX = ' + this.BreakoutGame_YMAX_var;
	result += '\n\tfgcolor = ' + this.BreakoutGame_fgcolor_var;
	result += '\n\tlives = ' + this.BreakoutGame_lives_var;
	result += '\n\tcountdown = ' + this.BreakoutGame_SC_LAUNCH_countdown_var;
	result += '\n\tBRICK_ROWS = ' + this.BreakoutGame_BRICK_ROWS_var;
	result += '\n\tscore = ' + this.BreakoutGame_score_var;
	result += '\n\tpadx = ' + this.BreakoutGame_padx_var;
	result += '\n\tQUIET = ' + this.BreakoutGame_QUIET_var;
	result += '\n\tbr = ' + this.BreakoutGame_br_var;
	result += '\n\tYDISPSIZE = ' + this.BreakoutGame_YDISPSIZE_var;
	result += '\n\tbgcolor = ' + this.BreakoutGame_bgcolor_var;
	result += '\n\tBOTTOM = ' + this.BreakoutGame_BOTTOM_var;
	result += '\n\tbricks = ' + this.BreakoutGame_bricks_var;
	result += '\n\tprevBX = ' + this.BreakoutGame_prevBX_var;
	result += '\n\tlevel = ' + this.BreakoutGame_level_var;
	result += '\n\tbx = ' + this.BreakoutGame_bx_var;
	result += '\n\tTOP = ' + this.BreakoutGame_TOP_var;
	result += '\n\tprevBY = ' + this.BreakoutGame_prevBY_var;
	result += '';
	return result;
}

module.exports = BreakoutGameNodeJS;
