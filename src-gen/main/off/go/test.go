package main

import (
	"github.com/SINTEF-9012/gosm"
)

func main() {
	/* -- Construct instances -- */
	game := NewThingBreakoutGameGo()
	disp := NewThingHeadlessDisplay()
	timer := NewThingTimerGo()
	ctrl := NewThingBasicIAController()
	log := NewThingConsoleLogger()
	
	/* -- Create connectors -- */
	gosm.Connector(game.Component, timer.Component, BreakoutGameGo_BreakoutGame_clock, TimerGo_TimerGo_timer)
	gosm.Connector(game.Component, disp.Component, BreakoutGameGo_BreakoutGame_display, HeadlessDisplay_HeadlessDisplay_display)
	gosm.Connector(game.Component, ctrl.Component, BreakoutGameGo_BreakoutGame_controller, BasicIAController_Controller_controls)
	gosm.Connector(ctrl.Component, game.Component, BasicIAController_IAController_game, BreakoutGameGo_BreakoutGame_ia)
	gosm.Connector(game.Component, log.Component, BreakoutGameGo_WithLog_log, ConsoleLogger_Logger_log)
	
	/* -- Set instance properties -- */
	game.DEBUG_ID = "game"
	game.lastTimestamp = 0
	game.counter = 0
	game.XDISPSIZE = 160
	game.YDISPSIZE = 128
	game.SCALE = 64
	game.XMAX = int16(game.XDISPSIZE) * game.SCALE
	game.YMAX = int16(game.YDISPSIZE) * game.SCALE
	game.TOP = 14 * game.SCALE
	game.BOTTOM = game.YMAX + 8 * game.SCALE
	game.LEFT = 1 * game.SCALE
	game.RIGHT = game.XMAX - 1 * game.SCALE
	game.br = 3 * game.SCALE
	game.bx = game.XMAX / 2
	game.by = game.YMAX
	game.dx = game.XMAX / 98
	game.dy =  -(game.XMAX) / 65
	game.padx = game.YMAX / 2
	game.pady = game.YMAX - 6 * game.SCALE
	game.padlen = 25 * game.SCALE
	game.prevBX =  -(1)
	game.prevBY =  -(1)
	game.bgcolor = make([]uint8, 3)
	game.fgcolor = make([]uint8, 3)
	game.period = 3
	game.prevPX =  -(1)
	game.prevPY =  -(1)
	game.BRICK_ROWS = 5
	game.BRICK_HEIGHT = 9
	game.bricks = make([]uint8, game.BRICK_ROWS)
	game.score = 0
	game.lives = 3
	game.level = 1
	ctrl.ctrlx = 0
	log.ACTIVATE_ON_STARTUP = false
	/* -- Start execution -- */
	gosm.RunComponents(game.Component, disp.Component, timer.Component, ctrl.Component, log.Component)
}
