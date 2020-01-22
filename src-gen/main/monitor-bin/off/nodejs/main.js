'use strict';

const Enum = require('./enums');
const ConsoleLogger = require('./ConsoleLogger');
const BasicIAController = require('./BasicIAController');
const TimerNodeJS = require('./TimerNodeJS');
const HeadlessDisplay = require('./HeadlessDisplay');
const BreakoutGameNodeJS = require('./BreakoutGameNodeJS');
/*$REQUIRE_PLUGINS$*/


const inst_log = new ConsoleLogger('log', null);
const inst_ctrl = new BasicIAController('ctrl', null);
const inst_timer = new TimerNodeJS('timer', null);
const inst_disp = new HeadlessDisplay('disp', null);
const inst_game = new BreakoutGameNodeJS('game', null);
/*$PLUGINS$*/
/*Connecting internal ports...*/
inst_game.bus.on('game', (e) => {
setImmediate(() => {
e.port = 'game';
inst_game._receive(e)
});

});
/*Connecting ports...*/
inst_ctrl.bus.on('controls', (e) => {
setImmediate(() => {
e.port = 'controller';
inst_game._receive(e)
});

});
inst_disp.bus.on('display', (e) => {
e.port = 'display';
inst_game._receive(e)
});
inst_game.bus.on('display', (e) => {
e.port = 'display';
inst_disp._receive(e)
});
inst_game.bus.on('log', (e) => {
e.port = 'log';
inst_log._receive(e)
});
inst_timer.bus.on('timer', (e) => {
setImmediate(() => {
e.port = 'clock';
inst_game._receive(e)
});

});
inst_game.bus.on('clock', (e) => {
setImmediate(() => {
e.port = 'timer';
inst_timer._receive(e)
});

});
inst_game.bus.on('ia', (e) => {
setImmediate(() => {
e.port = 'game';
inst_ctrl._receive(e)
});

});
inst_log.Logger_ACTIVATE_ON_STARTUP_var = false;
inst_log.Logger_HAS_SIGNED_BYTE_var = true;
inst_log.ConsoleLogger_QUIET_var = true;

inst_ctrl.BasicIAController_ctrlx_var = 0;

inst_timer.TimerNodeJS_Timeouts_var = {};
inst_timer.TimerNodeJS_driftless_var = require('driftless');

var inst_game_fgcolor = [];
var inst_game_bgcolor = [];
var inst_game_bricks = [];
inst_game.BreakoutGame_fgcolor_var = inst_game_fgcolor;
inst_game.BreakoutGame_bgcolor_var = inst_game_bgcolor;
inst_game.BreakoutGame_bricks_var = inst_game_bricks;
inst_game.WithBinaryLog_DEBUG_BIN_ID_var = 0;
inst_game.BreakoutGame_QUIET_var = true;
inst_game.BreakoutGame_startTime_var = 0;
inst_game.BreakoutGame_stopTime_var = 0;
inst_game.BreakoutGame_lastTimestamp_var = 0;
inst_game.BreakoutGame_counter_var = 0;
inst_game.BreakoutGame_XDISPSIZE_var = 160;
inst_game.BreakoutGame_YDISPSIZE_var = 128;
inst_game.BreakoutGame_SCALE_var = 64;
inst_game.BreakoutGame_XMAX_var = 160 * 64;
inst_game.BreakoutGame_YMAX_var = 128 * 64;
inst_game.BreakoutGame_TOP_var = 14 * 64;
inst_game.BreakoutGame_BOTTOM_var = 128 * 64 + 8 * 64;
inst_game.BreakoutGame_LEFT_var = 1 * 64;
inst_game.BreakoutGame_RIGHT_var = 160 * 64 - 1 * 64;
inst_game.BreakoutGame_br_var = 3 * 64;
inst_game.BreakoutGame_bx_var = Math.trunc(160 * 64 / 2);
inst_game.BreakoutGame_by_var = 128 * 64;
inst_game.BreakoutGame_dx_var = Math.trunc(160 * 64 / 98);
inst_game.BreakoutGame_dy_var = Math.trunc( -160 * 64 / 65);
inst_game.BreakoutGame_padx_var = Math.trunc(128 * 64 / 2);
inst_game.BreakoutGame_pady_var = 128 * 64 - 6 * 64;
inst_game.BreakoutGame_padlen_var = 25 * 64;
inst_game.BreakoutGame_prevBX_var =  -1;
inst_game.BreakoutGame_prevBY_var =  -1;
inst_game.BreakoutGame_period_var = 3;
inst_game.BreakoutGame_prevPX_var =  -1;
inst_game.BreakoutGame_prevPY_var =  -1;
inst_game.BreakoutGame_BRICK_ROWS_var = 5;
inst_game.BreakoutGame_BRICK_HEIGHT_var = 9;
inst_game.BreakoutGame_score_var = 0;
inst_game.BreakoutGame_lives_var = 3;
inst_game.BreakoutGame_level_var = 1;
inst_game.BreakoutGame_SC_LAUNCH_countdown_var = 0;

/*$PLUGINS_CONNECTORS$*/
inst_log._init();
inst_disp._init();
inst_timer._init();
inst_game._init();
inst_ctrl._init();
/*$PLUGINS_END$*/

function terminate() {
	inst_ctrl._stop();
	inst_ctrl._delete();
	inst_game._stop();
	inst_game._delete();
	inst_timer._stop();
	inst_timer._delete();
	inst_disp._stop();
	inst_disp._delete();
	inst_log._stop();
	inst_log._delete();
};
/*terminate all things on SIGINT (e.g. CTRL+C)*/
if (process && process.on) {
	process.on('SIGINT', function() {
		terminate();
		/*$STOP_PLUGINS$*/
		setTimeout(() => {
			process.exit();
		}, 1000);
	});
}
