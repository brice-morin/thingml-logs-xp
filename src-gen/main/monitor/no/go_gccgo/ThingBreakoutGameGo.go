package main

import (
	"os"
	"runtime"
	"time"
	"github.com/SINTEF-9012/gosm"
	"fmt"
)

/* -- Ports -- */
const (
	BreakoutGameGo_BreakoutGame_clock = 0
	BreakoutGameGo_BreakoutGame_display = 1
	BreakoutGameGo_BreakoutGame_controller = 2
	BreakoutGameGo_BreakoutGame_ia = 3
	BreakoutGameGo_BreakoutGame_game = 4
	BreakoutGameGo_BreakoutGame_req_game = 5
	BreakoutGameGo_BreakoutGame_pro_game = 6
)

/* -- Component --*/
type ThingBreakoutGameGo struct {
	 *gosm.Component
	QUIET bool
	startTime uint32
	stopTime uint32
	lastTimestamp uint32
	counter uint8
	XDISPSIZE uint8
	YDISPSIZE uint8
	SCALE int16
	XMAX int16
	YMAX int16
	TOP int16
	BOTTOM int16
	LEFT int16
	RIGHT int16
	br int16
	bx int16
	by int16
	dx int16
	dy int16
	padx int16
	pady int16
	padlen int16
	prevBX int16
	prevBY int16
	bgcolor []uint8
	fgcolor []uint8
	period uint16
	prevPX int16
	prevPY int16
	BRICK_ROWS uint8
	BRICK_HEIGHT uint8
	bricks []uint8
	score int16
	lives uint8
	level uint8
}

func (state *ThingBreakoutGameGo) log(logMem bool) {
	if state.counter == 0 || logMem {
		var ts uint32
		if state.lastTimestamp == 0 {
			ts = 0
			state.lastTimestamp = state.timestamp()
		} else {
			var t uint32 = state.timestamp()
			ts = t - state.lastTimestamp
			state.lastTimestamp = t
		}
		if  !(state.QUIET) {
			fmt.Println(""+("ts:")+fmt.Sprintf("%d", int64(ts))+(",lives:")+fmt.Sprintf("%d", int64(state.lives))+(",score:")+fmt.Sprintf("%d", int64(state.score))+(",level:")+fmt.Sprintf("%d", int64(state.level))+(",bx:")+fmt.Sprintf("%d", int64(state.bx))+(",by:")+fmt.Sprintf("%d", int64(state.by))+(",padx:")+fmt.Sprintf("%d", int64(state.padx)))
			fmt.Println(""+("#usedMem:")+fmt.Sprintf("%d", int64(state.usedMemory())))
		}
	}
	state.counter++
	if state.counter == 33 {
		state.counter = 0
	}
}
func (state *ThingBreakoutGameGo) initColors() {
	state.bgcolor[0] = 53
	state.bgcolor[1] = 40
	state.bgcolor[2] = 120
	state.fgcolor[0] = 107
	state.fgcolor[1] = 94
	state.fgcolor[2] = 174
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetBGColor{
		R: state.bgcolor[0],
		G: state.bgcolor[1],
		B: state.bgcolor[2],
	})
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: state.fgcolor[0],
		G: state.fgcolor[1],
		B: state.fgcolor[2],
	})
}
func (state *ThingBreakoutGameGo) resetBall() {
	state.bx = state.padx - state.br / state.SCALE
	state.by = state.pady - state.br / state.SCALE
	state.dx = (state.padx + state.prevBX + state.prevBY) % 300 - 150
	if state.dy > 0 {
		state.dy =  -(state.dy)
	}
	state.prevBX =  -(1)
	state.prevBY =  -(1)
}
func (state *ThingBreakoutGameGo) eraseBall() {
	var bs int16 = (state.br * 2) / state.SCALE
	if state.prevBX > 0 {
		state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
			R: state.bgcolor[0],
			G: state.bgcolor[1],
			B: state.bgcolor[2],
		})
		state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
			X: uint8(state.prevBX),
			Y: uint8(state.prevBY),
			Width: uint8(bs),
			Height: uint8(bs),
		})
	}
	state.prevBX =  -(1)
	state.prevBY =  -(1)
}
func (state *ThingBreakoutGameGo) drawBall() {
	var bs int16 = (state.br * 2) / state.SCALE
	state.eraseBall()
	state.prevBX = (state.bx - state.br) / state.SCALE
	state.prevBY = (state.by - state.br) / state.SCALE
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: 183,
		G: 199,
		B: 111,
	})
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
		X: uint8(state.prevBX),
		Y: uint8(state.prevBY),
		Width: uint8(bs),
		Height: uint8(bs),
	})
}
func (state *ThingBreakoutGameGo) erasePad() {
	var ps int16 = state.padlen / state.SCALE
	if state.prevPX > 0 {
		state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
			R: state.bgcolor[0],
			G: state.bgcolor[1],
			B: state.bgcolor[2],
		})
		state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
			X: uint8(state.prevPX),
			Y: uint8(state.prevPY),
			Width: uint8(ps),
			Height: 4,
		})
	}
}
func (state *ThingBreakoutGameGo) drawPad() {
	var ps int16 = state.padlen / state.SCALE
	state.erasePad()
	state.prevPX = (state.padx - (state.padlen / 2)) / state.SCALE
	state.prevPY = state.pady / state.SCALE
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: state.fgcolor[0],
		G: state.fgcolor[1],
		B: state.fgcolor[2],
	})
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
		X: uint8(state.prevPX),
		Y: uint8(state.prevPY),
		Width: uint8(ps),
		Height: 4,
	})
}
func (state *ThingBreakoutGameGo) drawCountDown(c int16) {
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: state.fgcolor[0],
		G: state.fgcolor[1],
		B: state.fgcolor[2],
	})
	if c > 0 {
		state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
			R: state.fgcolor[0],
			G: state.fgcolor[1],
			B: state.fgcolor[2],
		})
		state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetBGColor{
			R: state.bgcolor[0],
			G: state.bgcolor[1],
			B: state.bgcolor[2],
		})
		state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgdrawInteger{
			X: 80 - 6,
			Y: 90,
			V: c,
			Digits: 1,
			Scale: 4,
		})
	} else {
		state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
			R: state.bgcolor[0],
			G: state.bgcolor[1],
			B: state.bgcolor[2],
		})
		state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
			X: 80 - 6,
			Y: 90,
			Width: 12,
			Height: 20,
		})
	}
}
func (state *ThingBreakoutGameGo) drawWalls() {
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: state.fgcolor[0],
		G: state.fgcolor[1],
		B: state.fgcolor[2],
	})
	var left uint8 = uint8((state.LEFT / state.SCALE))
	var right uint8 = uint8((state.RIGHT / state.SCALE))
	var top uint8 = uint8((state.TOP / state.SCALE))
	var bottom uint8 = uint8((state.BOTTOM / state.SCALE))
	var xcenter uint8 = uint8(((state.RIGHT - state.LEFT) / state.SCALE))
	var ycenter uint8 = uint8(((state.BOTTOM - state.TOP) / state.SCALE))
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
		X: left - 1,
		Y: top - 1,
		Width: xcenter + 1,
		Height: 1,
	})
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
		X: left - 1,
		Y: bottom,
		Width: xcenter + 1,
		Height: 1,
	})
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
		X: left - 1,
		Y: top,
		Width: 1,
		Height: ycenter,
	})
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
		X: right,
		Y: top,
		Width: 1,
		Height: ycenter,
	})
}
func (state *ThingBreakoutGameGo) bitIsSet(variable uint8, bit uint8)  bool {
	return bool((((1 << bit) & variable) != 0))
}
func (state *ThingBreakoutGameGo) createBricks() {
	var y uint8 = 0
	for y < state.BRICK_ROWS {
		state.bricks[y] = 0xFF
		var x uint8 = 0
		for x < 8 {
			if state.bitIsSet(state.bricks[y], x) {
				state.drawBrick(x, y)
			}
			x = x + 1
		}
		y = y + 1
	}
}
func (state *ThingBreakoutGameGo) bricksLeft()  uint8 {
	var result uint8 = 0
	var y uint8 = 0
	for y < state.BRICK_ROWS {
		var x uint8 = 0
		for x < 8 {
			if state.bitIsSet(state.bricks[y], x) {
				result = result + 1
			}
			x = x + 1
		}
		y = y + 1
	}
	return result
}
func (state *ThingBreakoutGameGo) drawBrick(x uint8, y uint8) {
	var bx_1 uint8 = uint8(((state.LEFT + ((state.RIGHT - state.LEFT) / 8) * int16(x)) / state.SCALE + 1))
	var by_1 uint8 = uint8(((state.TOP + 20 * state.SCALE + int16(state.BRICK_HEIGHT) * int16(y) * state.SCALE) / state.SCALE + 1))
	var w uint8 = uint8((((state.RIGHT - state.LEFT) / 8) / state.SCALE - 2))
	var h uint8 = uint8((state.BRICK_HEIGHT - 2))
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: 155,
		G: 103,
		B: 89,
	})
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
		X: bx_1,
		Y: by_1,
		Width: w,
		Height: h,
	})
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: 100,
		G: 56,
		B: 43,
	})
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgdrawRect{
		X: bx_1,
		Y: by_1,
		Width: w,
		Height: h,
	})
}
func (state *ThingBreakoutGameGo) removeBrick(x uint8, y uint8) {
	var bx_1 uint8 = uint8(((state.LEFT + ((state.RIGHT - state.LEFT) / 8) * int16(x)) / state.SCALE + 1))
	var by_1 uint8 = uint8(((state.TOP + 20 * state.SCALE + int16(state.BRICK_HEIGHT) * int16(y) * state.SCALE) / state.SCALE + 1))
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: state.bgcolor[0],
		G: state.bgcolor[1],
		B: state.bgcolor[2],
	})
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
		X: bx_1,
		Y: by_1,
		Width: uint8((((state.RIGHT - state.LEFT) / 8) / state.SCALE - 2)),
		Height: state.BRICK_HEIGHT - 2,
	})
	state.bricks[y] = state.unsetBit(state.bricks[y], x)
}
func (state *ThingBreakoutGameGo) collideBrick(xpos int16, ypos int16)  bool {
	var bry int16 = (int16(ypos) - state.TOP - 20 * state.SCALE) / (int16(state.BRICK_HEIGHT) * state.SCALE)
	var result bool = false
	if bry >= 0 && bry < int16(state.BRICK_ROWS) {
		var brx int16 = (int16(xpos) - state.LEFT) / ((state.RIGHT - state.LEFT) / 8)
		if state.bitIsSet(state.bricks[bry], uint8(brx)) {
			state.removeBrick(uint8(brx), uint8(bry))
			result = true
		}
	}
	return result
}
func (state *ThingBreakoutGameGo) drawLevel() {
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: 158,
		G: 209,
		B: 130,
	})
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetBGColor{
		R: state.fgcolor[0],
		G: state.fgcolor[1],
		B: state.fgcolor[2],
	})
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: state.bgcolor[0],
		G: state.bgcolor[1],
		B: state.bgcolor[2],
	})
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgdrawInteger{
		X: 6,
		Y: 2,
		V: int16(state.level),
		Digits: 2,
		Scale: 2,
	})
}
func (state *ThingBreakoutGameGo) incrementScore(diff int8) {
	state.score = state.score + int16(diff)
	if state.score < 0 {
		state.score = 0
	}
	state.drawScore()
}
func (state *ThingBreakoutGameGo) drawScore() {
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: 158,
		G: 209,
		B: 130,
	})
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetBGColor{
		R: state.fgcolor[0],
		G: state.fgcolor[1],
		B: state.fgcolor[2],
	})
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgdrawInteger{
		X: 58,
		Y: 2,
		V: state.score,
		Digits: 5,
		Scale: 2,
	})
}
func (state *ThingBreakoutGameGo) drawLives() {
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: state.fgcolor[0],
		G: state.fgcolor[1],
		B: state.fgcolor[2],
	})
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
		X: 124,
		Y: 4,
		Width: 24 + 6,
		Height: 6,
	})
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: 183,
		G: 199,
		B: 111,
	})
	var i uint8 = 0
	for i < state.lives {
		state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
			X: 124 + (2 - i) * 12,
			Y: 4,
			Width: 6,
			Height: 6,
		})
		i = i + 1
	}
}
func (state *ThingBreakoutGameGo) quit() {
	runtime.GC();
	fmt.Println(""+(">done in ")+fmt.Sprintf("%d", int64(state.stopTime - state.startTime))+("ms!"))
	fmt.Println(""+(">lives:")+fmt.Sprintf("%d", int64(state.lives))+(",score:")+fmt.Sprintf("%d", int64(state.score))+(",level:")+fmt.Sprintf("%d", int64(state.level))+(",bx:")+fmt.Sprintf("%d", int64(state.bx))+(",by:")+fmt.Sprintf("%d", int64(state.by))+(",padx:")+fmt.Sprintf("%d", int64(state.padx)))
	fmt.Println(""+(">usedMem:")+fmt.Sprintf("%d", int64(state.usedMemory())))
	os.Exit(0);
}
func (state *ThingBreakoutGameGo) timestamp()  uint32 {
	return uint32(uint32(time.Now().UnixNano() / int64(time.Millisecond)))
}
func (state *ThingBreakoutGameGo) usedMemory()  uint32 {
	runtime.GC();
	var m runtime.MemStats
		runtime.ReadMemStats(&m)
	return uint32(m.HeapAlloc)
}
func (state *ThingBreakoutGameGo) unsetBit(variable uint8, bit uint8)  uint8 {
	return uint8((variable & ^(1 << bit)))
}
/* -- States -- */
type FragmentBreakoutGameStateChartSC struct {
	 gosm.CompositeState
	 *ThingBreakoutGameGo
}

type FragmentBreakoutGameStateChartSCStateINIT struct {
	 *FragmentBreakoutGameStateChartSC
	 *FragmentBreakoutGameStateChartSCStateLAUNCH
	 *FragmentBreakoutGameStateChartSCStatePLAY
	 *FragmentBreakoutGameStateChartSCStateLOSTBALL
	 *FragmentBreakoutGameStateChartSCStateNEXTLEVEL
	 *FragmentBreakoutGameStateChartSCStateGAMEOVER
}

type FragmentBreakoutGameStateChartSCStateLAUNCH struct {
	 *FragmentBreakoutGameStateChartSC
	 *FragmentBreakoutGameStateChartSCStateINIT
	 *FragmentBreakoutGameStateChartSCStatePLAY
	 *FragmentBreakoutGameStateChartSCStateLOSTBALL
	 *FragmentBreakoutGameStateChartSCStateNEXTLEVEL
	 *FragmentBreakoutGameStateChartSCStateGAMEOVER
	countdown uint8
}

type FragmentBreakoutGameStateChartSCStatePLAY struct {
	 *FragmentBreakoutGameStateChartSC
	 *FragmentBreakoutGameStateChartSCStateINIT
	 *FragmentBreakoutGameStateChartSCStateLAUNCH
	 *FragmentBreakoutGameStateChartSCStateLOSTBALL
	 *FragmentBreakoutGameStateChartSCStateNEXTLEVEL
	 *FragmentBreakoutGameStateChartSCStateGAMEOVER
}

type FragmentBreakoutGameStateChartSCStateLOSTBALL struct {
	 *FragmentBreakoutGameStateChartSC
	 *FragmentBreakoutGameStateChartSCStateINIT
	 *FragmentBreakoutGameStateChartSCStateLAUNCH
	 *FragmentBreakoutGameStateChartSCStatePLAY
	 *FragmentBreakoutGameStateChartSCStateNEXTLEVEL
	 *FragmentBreakoutGameStateChartSCStateGAMEOVER
}

type FragmentBreakoutGameStateChartSCStateNEXTLEVEL struct {
	 *FragmentBreakoutGameStateChartSC
	 *FragmentBreakoutGameStateChartSCStateINIT
	 *FragmentBreakoutGameStateChartSCStateLAUNCH
	 *FragmentBreakoutGameStateChartSCStatePLAY
	 *FragmentBreakoutGameStateChartSCStateLOSTBALL
	 *FragmentBreakoutGameStateChartSCStateGAMEOVER
}

type FragmentBreakoutGameStateChartSCStateGAMEOVER struct {
	 *FragmentBreakoutGameStateChartSC
	 *FragmentBreakoutGameStateChartSCStateINIT
	 *FragmentBreakoutGameStateChartSCStateLAUNCH
	 *FragmentBreakoutGameStateChartSCStatePLAY
	 *FragmentBreakoutGameStateChartSCStateLOSTBALL
	 *FragmentBreakoutGameStateChartSCStateNEXTLEVEL
}

/* -- Handlers -- */
func (state *FragmentBreakoutGameStateChartSC) OnEntry() {
	state.CompositeState.OnEntry()
}
func (state *FragmentBreakoutGameStateChartSC) Handle(port gosm.Port, message interface{}) (handled bool, internal bool, next gosm.State, action func()) {
	if handled, internal, next, action = state.CompositeState.Handle(port, message); handled {
		return
	}
	switch typedMessage := message.(type) {
	case FragmentControllerMsgsMsgposition:
		if e := typedMessage; port == BreakoutGameGo_BreakoutGame_controller {
			return true, true, state, func() {
				var center int32 = (int32(state.RIGHT) - int32(state.LEFT) - int32(state.padlen))
				center = int32(e.X) * center
				center = center / 200
				state.padx = int16((int32(state.LEFT) + center + (int32(state.RIGHT) - int32(state.LEFT)) / 2))
			}
		}
	}
	return false, false, state, nil
}
func (state *FragmentBreakoutGameStateChartSC) OnExit() {
	state.CompositeState.OnExit()
}

func (state *FragmentBreakoutGameStateChartSCStateINIT) OnEntry() {
	state.startTime = state.timestamp()
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgcreate{
		Xsize: state.XDISPSIZE,
		Ysize: state.YDISPSIZE,
	})
}
func (state *FragmentBreakoutGameStateChartSCStateINIT) Handle(port gosm.Port, message interface{}) (handled bool, internal bool, next gosm.State, action func()) {
	switch message.(type) {
	case FragmentDisplayMsgsMsgdisplayReady:
		if port == BreakoutGameGo_BreakoutGame_display {
			return true, false, state.FragmentBreakoutGameStateChartSCStateLAUNCH, func() {
				state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgclear{})
				state.initColors()
				state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
					R: state.bgcolor[0],
					G: state.bgcolor[1],
					B: state.bgcolor[2],
				})
				state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
					X: 0,
					Y: 0,
					Width: state.XDISPSIZE,
					Height: state.YDISPSIZE,
				})
				state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
					R: state.fgcolor[0],
					G: state.fgcolor[1],
					B: state.fgcolor[2],
				})
				state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
					X: 0,
					Y: 0,
					Width: state.XDISPSIZE,
					Height: 14,
				})
				state.drawWalls()
				state.createBricks()
				state.drawLevel()
			}
		}
	}
	return false, false, state, nil
}
func (state *FragmentBreakoutGameStateChartSCStateINIT) OnExit() {}

func (state *FragmentBreakoutGameStateChartSCStateLAUNCH) OnEntry() {
	state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_start{
		Id: 0,
		Time: state.period,
	})
	state.countdown = 3
	state.drawScore()
	state.drawLives()
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgupdate{})
}
func (state *FragmentBreakoutGameStateChartSCStateLAUNCH) Handle(port gosm.Port, message interface{}) (handled bool, internal bool, next gosm.State, action func()) {
	switch typedMessage := message.(type) {
	case FragmentTimerMsgsMsgtimer_timeout:
		if t := typedMessage; port == BreakoutGameGo_BreakoutGame_clock && (t.Id == 0 && state.countdown > 0) {
			return true, true, state, func() {
				state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_start{
					Id: 0,
					Time: state.period,
				})
				state.drawPad()
				if (state.countdown % 30) == 0 {
					state.drawCountDown(int16(state.countdown) / 30)
				}
				state.countdown = state.countdown - 1
				state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgupdate{})
			}
		}
		if t := typedMessage; port == BreakoutGameGo_BreakoutGame_clock && (t.Id == 0 && state.countdown == 0) {
			return true, false, state.FragmentBreakoutGameStateChartSCStatePLAY, func() {
				state.drawCountDown(0)
				state.resetBall()
				state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgupdate{})
			}
		}
	}
	return false, false, state, nil
}
func (state *FragmentBreakoutGameStateChartSCStateLAUNCH) OnExit() {}

func (state *FragmentBreakoutGameStateChartSCStatePLAY) OnEntry() {
	state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_start{
		Id: 0,
		Time: state.period,
	})
}
func (state *FragmentBreakoutGameStateChartSCStatePLAY) Handle(port gosm.Port, message interface{}) (handled bool, internal bool, next gosm.State, action func()) {
	switch typedMessage := message.(type) {
	case FragmentTimerMsgsMsgtimer_timeout:
		if t := typedMessage; port == BreakoutGameGo_BreakoutGame_clock && (t.Id == 0) {
			return true, true, state, func() {
				state.bx = state.bx + state.dx
				state.by = state.by + state.dy
				var wl int16 = state.LEFT + state.br
				var wr int16 = state.RIGHT - state.br
				var wt int16 = state.TOP + state.br
				var wb int16 = state.BOTTOM - state.br
				if state.bx < wl {
					state.dx =  -(state.dx)
					state.bx = 2 * wl - state.bx
					state.incrementScore( -(1))
				} else {
					if state.bx > wr {
						state.dx =  -(state.dx)
						state.bx = 2 * wr - state.bx
						state.incrementScore( -(1))
					}
				}
				if state.by < wt {
					state.dy =  -(state.dy)
					state.by = 2 * wt - state.by
					state.incrementScore( -(1))
				} else {
					if state.by > wb {
						state.Send(BreakoutGameGo_BreakoutGame_game, FragmentBreakoutGameMsglostBall{})
						state.Send(BreakoutGameGo_BreakoutGame_req_game, FragmentBreakoutGameMsglostBall{})
					}
				}
				if state.dy > 0 {
					if state.by > state.pady - state.br && state.by < state.pady + state.br {
						if state.bx > state.padx - state.padlen / 2 && state.bx < state.padx + state.padlen / 2 {
							state.dy =  -(state.dy)
							state.by = 2 * (state.pady - state.br) - state.by
							state.dx = state.dx / 4 + (state.bx - state.padx) / 4
						}
					}
				}
				var collision bool = state.collideBrick(state.bx - state.br, state.by - state.br) || state.collideBrick(state.bx + state.br, state.by - state.br) || state.collideBrick(state.bx + state.br, state.by + state.br) || state.collideBrick(state.bx - state.br, state.by + state.br)
				if collision {
					state.dy =  -(state.dy)
					state.incrementScore(10)
					if state.bricksLeft() == 0 {
						state.Send(BreakoutGameGo_BreakoutGame_game, FragmentBreakoutGameMsgnextLevel{})
						state.Send(BreakoutGameGo_BreakoutGame_req_game, FragmentBreakoutGameMsgnextLevel{})
					}
				}
				state.drawBall()
				state.drawPad()
				state.Send(BreakoutGameGo_BreakoutGame_ia, FragmentIAControllerMsgMsgupdateIA{
					Ballx: state.bx,
					Bally: state.by,
					Padx: state.padx,
					Pady: state.pady,
				})
				state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgupdate{})
				state.log(false)
				state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_start{
					Id: 0,
					Time: state.period,
				})
			}
		}
	case FragmentBreakoutGameMsglostBall:
		if port == BreakoutGameGo_BreakoutGame_game {
			return true, false, state.FragmentBreakoutGameStateChartSCStateLOSTBALL, func() {
				state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_cancel{
					Id: 0,
				})
			}
		}
		if port == BreakoutGameGo_BreakoutGame_pro_game {
			return true, false, state.FragmentBreakoutGameStateChartSCStateLOSTBALL, func() {
				state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_cancel{
					Id: 0,
				})
			}
		}
	case FragmentBreakoutGameMsgnextLevel:
		if port == BreakoutGameGo_BreakoutGame_game {
			return true, false, state.FragmentBreakoutGameStateChartSCStateNEXTLEVEL, func() {
				state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_cancel{
					Id: 0,
				})
			}
		}
		if port == BreakoutGameGo_BreakoutGame_pro_game {
			return true, false, state.FragmentBreakoutGameStateChartSCStateNEXTLEVEL, func() {
				state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_cancel{
					Id: 0,
				})
			}
		}
	}
	return false, false, state, nil
}
func (state *FragmentBreakoutGameStateChartSCStatePLAY) OnExit() {}

func (state *FragmentBreakoutGameStateChartSCStateLOSTBALL) OnEntry() {
	state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_start{
		Id: 0,
		Time: state.period,
	})
	state.lives = state.lives - 1
	state.eraseBall()
	state.erasePad()
	state.drawLives()
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgupdate{})
	state.log(true)
}
func (state *FragmentBreakoutGameStateChartSCStateLOSTBALL) Handle(port gosm.Port, message interface{}) (handled bool, internal bool, next gosm.State, action func()) {
	switch typedMessage := message.(type) {
	case FragmentTimerMsgsMsgtimer_timeout:
		if t := typedMessage; port == BreakoutGameGo_BreakoutGame_clock && (t.Id == 0 && state.lives > 0) {
			return true, false, state.FragmentBreakoutGameStateChartSCStateLAUNCH, nil
			
		}
		if t := typedMessage; port == BreakoutGameGo_BreakoutGame_clock && (t.Id == 0 && state.lives == 0) {
			return true, false, state.FragmentBreakoutGameStateChartSCStateGAMEOVER, nil
			
		}
	}
	return false, false, state, nil
}
func (state *FragmentBreakoutGameStateChartSCStateLOSTBALL) OnExit() {}

func (state *FragmentBreakoutGameStateChartSCStateNEXTLEVEL) OnEntry() {
	state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_start{
		Id: 0,
		Time: state.period,
	})
	state.level = state.level + 1
	state.drawLevel()
	state.eraseBall()
	state.erasePad()
	if (state.level % 2) == 0 && state.padlen > 5 * state.SCALE {
		state.padlen = state.padlen - (4 * state.SCALE)
	}
	if (state.level % 2) == 1 {
		state.dy = (state.dy * 3) / 2
	}
	state.drawLives()
	state.createBricks()
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgupdate{})
}
func (state *FragmentBreakoutGameStateChartSCStateNEXTLEVEL) Handle(port gosm.Port, message interface{}) (handled bool, internal bool, next gosm.State, action func()) {
	switch typedMessage := message.(type) {
	case FragmentTimerMsgsMsgtimer_timeout:
		if t := typedMessage; port == BreakoutGameGo_BreakoutGame_clock && (t.Id == 0) {
			return true, false, state.FragmentBreakoutGameStateChartSCStateLAUNCH, nil
			
		}
	}
	return false, false, state, nil
}
func (state *FragmentBreakoutGameStateChartSCStateNEXTLEVEL) OnExit() {}

func (state *FragmentBreakoutGameStateChartSCStateGAMEOVER) OnEntry() {
	state.eraseBall()
	state.erasePad()
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: 255,
		G: 255,
		B: 255,
	})
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
		X: 8,
		Y: 30,
		Width: 142,
		Height: 76,
	})
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: state.fgcolor[0],
		G: state.fgcolor[1],
		B: state.fgcolor[2],
	})
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
		X: 9,
		Y: 31,
		Width: 140,
		Height: 50,
	})
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetBGColor{
		R: state.fgcolor[0],
		G: state.fgcolor[1],
		B: state.fgcolor[2],
	})
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: 158,
		G: 209,
		B: 130,
	})
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgdrawInteger{
		X: 23,
		Y: 40,
		V: state.score,
		Digits: 5,
		Scale: 6,
	})
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgdrawThingML{
		X: 26,
		Y: 87,
	})
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgupdate{})
	state.log(true)
	state.stopTime = state.timestamp()
	state.quit()
}
func (state *FragmentBreakoutGameStateChartSCStateGAMEOVER) Handle(port gosm.Port, message interface{}) (handled bool, internal bool, next gosm.State, action func()) {
	return false, false, state, nil
}
func (state *FragmentBreakoutGameStateChartSCStateGAMEOVER) OnExit() {}

/* -- Instance Constructor -- */
func NewThingBreakoutGameGo()  *ThingBreakoutGameGo {
	/* Create instance struct */
	instance := &ThingBreakoutGameGo{}
	/* Initialize state structs */
	stateFragmentBreakoutGameStateChartSC := &FragmentBreakoutGameStateChartSC{}
	stateFragmentBreakoutGameStateChartSCStateINIT := &FragmentBreakoutGameStateChartSCStateINIT{}
	stateFragmentBreakoutGameStateChartSCStateLAUNCH := &FragmentBreakoutGameStateChartSCStateLAUNCH{}
	stateFragmentBreakoutGameStateChartSCStatePLAY := &FragmentBreakoutGameStateChartSCStatePLAY{}
	stateFragmentBreakoutGameStateChartSCStateLOSTBALL := &FragmentBreakoutGameStateChartSCStateLOSTBALL{}
	stateFragmentBreakoutGameStateChartSCStateNEXTLEVEL := &FragmentBreakoutGameStateChartSCStateNEXTLEVEL{}
	stateFragmentBreakoutGameStateChartSCStateGAMEOVER := &FragmentBreakoutGameStateChartSCStateGAMEOVER{}
	/* Initialize regions */
	stateFragmentBreakoutGameStateChartSC.CompositeState.Regions = []gosm.Region{
		gosm.Region{ Initial: stateFragmentBreakoutGameStateChartSCStateINIT, KeepsHistory: false},
	}
	/* Set state links */
	stateFragmentBreakoutGameStateChartSC.ThingBreakoutGameGo = instance
	stateFragmentBreakoutGameStateChartSCStateINIT.FragmentBreakoutGameStateChartSC = stateFragmentBreakoutGameStateChartSC
	stateFragmentBreakoutGameStateChartSCStateINIT.FragmentBreakoutGameStateChartSCStateLAUNCH = stateFragmentBreakoutGameStateChartSCStateLAUNCH
	stateFragmentBreakoutGameStateChartSCStateINIT.FragmentBreakoutGameStateChartSCStatePLAY = stateFragmentBreakoutGameStateChartSCStatePLAY
	stateFragmentBreakoutGameStateChartSCStateINIT.FragmentBreakoutGameStateChartSCStateLOSTBALL = stateFragmentBreakoutGameStateChartSCStateLOSTBALL
	stateFragmentBreakoutGameStateChartSCStateINIT.FragmentBreakoutGameStateChartSCStateNEXTLEVEL = stateFragmentBreakoutGameStateChartSCStateNEXTLEVEL
	stateFragmentBreakoutGameStateChartSCStateINIT.FragmentBreakoutGameStateChartSCStateGAMEOVER = stateFragmentBreakoutGameStateChartSCStateGAMEOVER
	stateFragmentBreakoutGameStateChartSCStateLAUNCH.FragmentBreakoutGameStateChartSC = stateFragmentBreakoutGameStateChartSC
	stateFragmentBreakoutGameStateChartSCStateLAUNCH.FragmentBreakoutGameStateChartSCStateINIT = stateFragmentBreakoutGameStateChartSCStateINIT
	stateFragmentBreakoutGameStateChartSCStateLAUNCH.FragmentBreakoutGameStateChartSCStatePLAY = stateFragmentBreakoutGameStateChartSCStatePLAY
	stateFragmentBreakoutGameStateChartSCStateLAUNCH.FragmentBreakoutGameStateChartSCStateLOSTBALL = stateFragmentBreakoutGameStateChartSCStateLOSTBALL
	stateFragmentBreakoutGameStateChartSCStateLAUNCH.FragmentBreakoutGameStateChartSCStateNEXTLEVEL = stateFragmentBreakoutGameStateChartSCStateNEXTLEVEL
	stateFragmentBreakoutGameStateChartSCStateLAUNCH.FragmentBreakoutGameStateChartSCStateGAMEOVER = stateFragmentBreakoutGameStateChartSCStateGAMEOVER
	stateFragmentBreakoutGameStateChartSCStatePLAY.FragmentBreakoutGameStateChartSC = stateFragmentBreakoutGameStateChartSC
	stateFragmentBreakoutGameStateChartSCStatePLAY.FragmentBreakoutGameStateChartSCStateINIT = stateFragmentBreakoutGameStateChartSCStateINIT
	stateFragmentBreakoutGameStateChartSCStatePLAY.FragmentBreakoutGameStateChartSCStateLAUNCH = stateFragmentBreakoutGameStateChartSCStateLAUNCH
	stateFragmentBreakoutGameStateChartSCStatePLAY.FragmentBreakoutGameStateChartSCStateLOSTBALL = stateFragmentBreakoutGameStateChartSCStateLOSTBALL
	stateFragmentBreakoutGameStateChartSCStatePLAY.FragmentBreakoutGameStateChartSCStateNEXTLEVEL = stateFragmentBreakoutGameStateChartSCStateNEXTLEVEL
	stateFragmentBreakoutGameStateChartSCStatePLAY.FragmentBreakoutGameStateChartSCStateGAMEOVER = stateFragmentBreakoutGameStateChartSCStateGAMEOVER
	stateFragmentBreakoutGameStateChartSCStateLOSTBALL.FragmentBreakoutGameStateChartSC = stateFragmentBreakoutGameStateChartSC
	stateFragmentBreakoutGameStateChartSCStateLOSTBALL.FragmentBreakoutGameStateChartSCStateINIT = stateFragmentBreakoutGameStateChartSCStateINIT
	stateFragmentBreakoutGameStateChartSCStateLOSTBALL.FragmentBreakoutGameStateChartSCStateLAUNCH = stateFragmentBreakoutGameStateChartSCStateLAUNCH
	stateFragmentBreakoutGameStateChartSCStateLOSTBALL.FragmentBreakoutGameStateChartSCStatePLAY = stateFragmentBreakoutGameStateChartSCStatePLAY
	stateFragmentBreakoutGameStateChartSCStateLOSTBALL.FragmentBreakoutGameStateChartSCStateNEXTLEVEL = stateFragmentBreakoutGameStateChartSCStateNEXTLEVEL
	stateFragmentBreakoutGameStateChartSCStateLOSTBALL.FragmentBreakoutGameStateChartSCStateGAMEOVER = stateFragmentBreakoutGameStateChartSCStateGAMEOVER
	stateFragmentBreakoutGameStateChartSCStateNEXTLEVEL.FragmentBreakoutGameStateChartSC = stateFragmentBreakoutGameStateChartSC
	stateFragmentBreakoutGameStateChartSCStateNEXTLEVEL.FragmentBreakoutGameStateChartSCStateINIT = stateFragmentBreakoutGameStateChartSCStateINIT
	stateFragmentBreakoutGameStateChartSCStateNEXTLEVEL.FragmentBreakoutGameStateChartSCStateLAUNCH = stateFragmentBreakoutGameStateChartSCStateLAUNCH
	stateFragmentBreakoutGameStateChartSCStateNEXTLEVEL.FragmentBreakoutGameStateChartSCStatePLAY = stateFragmentBreakoutGameStateChartSCStatePLAY
	stateFragmentBreakoutGameStateChartSCStateNEXTLEVEL.FragmentBreakoutGameStateChartSCStateLOSTBALL = stateFragmentBreakoutGameStateChartSCStateLOSTBALL
	stateFragmentBreakoutGameStateChartSCStateNEXTLEVEL.FragmentBreakoutGameStateChartSCStateGAMEOVER = stateFragmentBreakoutGameStateChartSCStateGAMEOVER
	stateFragmentBreakoutGameStateChartSCStateGAMEOVER.FragmentBreakoutGameStateChartSC = stateFragmentBreakoutGameStateChartSC
	stateFragmentBreakoutGameStateChartSCStateGAMEOVER.FragmentBreakoutGameStateChartSCStateINIT = stateFragmentBreakoutGameStateChartSCStateINIT
	stateFragmentBreakoutGameStateChartSCStateGAMEOVER.FragmentBreakoutGameStateChartSCStateLAUNCH = stateFragmentBreakoutGameStateChartSCStateLAUNCH
	stateFragmentBreakoutGameStateChartSCStateGAMEOVER.FragmentBreakoutGameStateChartSCStatePLAY = stateFragmentBreakoutGameStateChartSCStatePLAY
	stateFragmentBreakoutGameStateChartSCStateGAMEOVER.FragmentBreakoutGameStateChartSCStateLOSTBALL = stateFragmentBreakoutGameStateChartSCStateLOSTBALL
	stateFragmentBreakoutGameStateChartSCStateGAMEOVER.FragmentBreakoutGameStateChartSCStateNEXTLEVEL = stateFragmentBreakoutGameStateChartSCStateNEXTLEVEL
	/* Make component */
	component := gosm.MakeComponent(100, stateFragmentBreakoutGameStateChartSC)
	instance.Component = component
	/* Internal ports */
	gosm.InternalPort(instance.Component, BreakoutGameGo_BreakoutGame_game)
	return instance
}

func cloneThingBreakoutGameGo(original *ThingBreakoutGameGo)  *ThingBreakoutGameGo {
	clone := &ThingBreakoutGameGo{
		QUIET: original.QUIET,
		startTime: original.startTime,
		stopTime: original.stopTime,
		lastTimestamp: original.lastTimestamp,
		counter: original.counter,
		XDISPSIZE: original.XDISPSIZE,
		YDISPSIZE: original.YDISPSIZE,
		SCALE: original.SCALE,
		XMAX: original.XMAX,
		YMAX: original.YMAX,
		TOP: original.TOP,
		BOTTOM: original.BOTTOM,
		LEFT: original.LEFT,
		RIGHT: original.RIGHT,
		br: original.br,
		bx: original.bx,
		by: original.by,
		dx: original.dx,
		dy: original.dy,
		padx: original.padx,
		pady: original.pady,
		padlen: original.padlen,
		prevBX: original.prevBX,
		prevBY: original.prevBY,
		bgcolor: append([]uint8{}, original.bgcolor...),
		fgcolor: append([]uint8{}, original.fgcolor...),
		period: original.period,
		prevPX: original.prevPX,
		prevPY: original.prevPY,
		BRICK_ROWS: original.BRICK_ROWS,
		BRICK_HEIGHT: original.BRICK_HEIGHT,
		bricks: append([]uint8{}, original.bricks...),
		score: original.score,
		lives: original.lives,
		level: original.level,
	}
	return clone
}
/* -- Session forks -- */
