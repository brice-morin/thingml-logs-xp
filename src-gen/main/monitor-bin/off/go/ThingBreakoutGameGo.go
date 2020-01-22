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
	BreakoutGameGo_WithBinaryLog_log = 0
	BreakoutGameGo_BreakoutGame_clock = 1
	BreakoutGameGo_BreakoutGame_display = 2
	BreakoutGameGo_BreakoutGame_controller = 3
	BreakoutGameGo_BreakoutGame_ia = 4
	BreakoutGameGo_BreakoutGame_game = 5
	BreakoutGameGo_BreakoutGame_req_game = 6
	BreakoutGameGo_BreakoutGame_pro_game = 7
)

/* -- Component --*/
type ThingBreakoutGameGo struct {
	 *gosm.Component
	DEBUG_BIN_ID byte
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
	var r_0 uint8 = state.bgcolor[0]
	var g_1 uint8 = state.bgcolor[1]
	var b_2 uint8 = state.bgcolor[2]
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetBGColor{
		R: r_0,
		G: g_1,
		B: b_2,
	})
	var setBGColorsent_log_3 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x08, byte(r_0), byte(g_1), byte(b_2) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: setBGColorsent_log_3,
		Size: 7,
	})
	var r_4 uint8 = state.fgcolor[0]
	var g_5 uint8 = state.fgcolor[1]
	var b_6 uint8 = state.fgcolor[2]
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_4,
		G: g_5,
		B: b_6,
	})
	var setColorsent_log_7 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x07, byte(r_4), byte(g_5), byte(b_6) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: setColorsent_log_7,
		Size: 7,
	})
	var initColors_log0 []byte = []byte{ LogType_function_called, state.DEBUG_BIN_ID, 0x01, 0x00 }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: initColors_log0,
		Size: 4,
	})
}
func (state *ThingBreakoutGameGo) resetBall() {
	var old_bx_21 int16 = state.bx
	state.bx = state.padx - state.br / state.SCALE
	var new_bx_21 int16 = state.bx
	var bx_log_21 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x0A, byte((((old_bx_21 >> 8) & 0xFF))), byte((((old_bx_21 >> 0) & 0xFF))), byte((((new_bx_21 >> 8) & 0xFF))), byte((((new_bx_21 >> 0) & 0xFF))) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: bx_log_21,
		Size: 7,
	})
	var old_by_28 int16 = state.by
	state.by = state.pady - state.br / state.SCALE
	var new_by_28 int16 = state.by
	var by_log_28 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x0B, byte((((old_by_28 >> 8) & 0xFF))), byte((((old_by_28 >> 0) & 0xFF))), byte((((new_by_28 >> 8) & 0xFF))), byte((((new_by_28 >> 0) & 0xFF))) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: by_log_28,
		Size: 7,
	})
	var old_dx_12 int16 = state.dx
	state.dx = (state.padx + state.prevBX + state.prevBY) % 300 - 150
	var new_dx_12 int16 = state.dx
	var dx_log_12 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x0C, byte((((old_dx_12 >> 8) & 0xFF))), byte((((old_dx_12 >> 0) & 0xFF))), byte((((new_dx_12 >> 8) & 0xFF))), byte((((new_dx_12 >> 0) & 0xFF))) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: dx_log_12,
		Size: 7,
	})
	if state.dy > 0 {
		var old_dy_4 int16 = state.dy
		state.dy =  -(state.dy)
		var new_dy_4 int16 = state.dy
		var dy_log_4 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x0D, byte((((old_dy_4 >> 8) & 0xFF))), byte((((old_dy_4 >> 0) & 0xFF))), byte((((new_dy_4 >> 8) & 0xFF))), byte((((new_dy_4 >> 0) & 0xFF))) }
		state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
			Payload: dy_log_4,
			Size: 7,
		})
	}
	var old_prevBX_25 int16 = state.prevBX
	state.prevBX =  -(1)
	var new_prevBX_25 int16 = state.prevBX
	var prevBX_log_25 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x11, byte((((old_prevBX_25 >> 8) & 0xFF))), byte((((old_prevBX_25 >> 0) & 0xFF))), byte((((new_prevBX_25 >> 8) & 0xFF))), byte((((new_prevBX_25 >> 0) & 0xFF))) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: prevBX_log_25,
		Size: 7,
	})
	var old_prevBY_17 int16 = state.prevBY
	state.prevBY =  -(1)
	var new_prevBY_17 int16 = state.prevBY
	var prevBY_log_17 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x12, byte((((old_prevBY_17 >> 8) & 0xFF))), byte((((old_prevBY_17 >> 0) & 0xFF))), byte((((new_prevBY_17 >> 8) & 0xFF))), byte((((new_prevBY_17 >> 0) & 0xFF))) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: prevBY_log_17,
		Size: 7,
	})
	var resetBall_log1 []byte = []byte{ LogType_function_called, state.DEBUG_BIN_ID, 0x02, 0x00 }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: resetBall_log1,
		Size: 4,
	})
}
func (state *ThingBreakoutGameGo) eraseBall() {
	var bs int16 = (state.br * 2) / state.SCALE
	if state.prevBX > 0 {
		var r_8 uint8 = state.bgcolor[0]
		var g_9 uint8 = state.bgcolor[1]
		var b_10 uint8 = state.bgcolor[2]
		state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
			R: r_8,
			G: g_9,
			B: b_10,
		})
		var setColorsent_log_11 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x07, byte(r_8), byte(g_9), byte(b_10) }
		state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
			Payload: setColorsent_log_11,
			Size: 7,
		})
		var x_12 uint8 = uint8(state.prevBX)
		var y_13 uint8 = uint8(state.prevBY)
		var width_14 uint8 = uint8(bs)
		var height_15 uint8 = uint8(bs)
		state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
			X: x_12,
			Y: y_13,
			Width: width_14,
			Height: height_15,
		})
		var fillRectsent_log_16 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0A, byte(x_12), byte(y_13), byte(width_14), byte(height_15) }
		state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
			Payload: fillRectsent_log_16,
			Size: 8,
		})
	}
	var old_prevBX_26 int16 = state.prevBX
	state.prevBX =  -(1)
	var new_prevBX_26 int16 = state.prevBX
	var prevBX_log_26 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x11, byte((((old_prevBX_26 >> 8) & 0xFF))), byte((((old_prevBX_26 >> 0) & 0xFF))), byte((((new_prevBX_26 >> 8) & 0xFF))), byte((((new_prevBX_26 >> 0) & 0xFF))) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: prevBX_log_26,
		Size: 7,
	})
	var old_prevBY_18 int16 = state.prevBY
	state.prevBY =  -(1)
	var new_prevBY_18 int16 = state.prevBY
	var prevBY_log_18 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x12, byte((((old_prevBY_18 >> 8) & 0xFF))), byte((((old_prevBY_18 >> 0) & 0xFF))), byte((((new_prevBY_18 >> 8) & 0xFF))), byte((((new_prevBY_18 >> 0) & 0xFF))) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: prevBY_log_18,
		Size: 7,
	})
	var eraseBall_log2 []byte = []byte{ LogType_function_called, state.DEBUG_BIN_ID, 0x03, 0x00 }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: eraseBall_log2,
		Size: 4,
	})
}
func (state *ThingBreakoutGameGo) drawBall() {
	var bs int16 = (state.br * 2) / state.SCALE
	state.eraseBall()
	var old_prevBX_27 int16 = state.prevBX
	state.prevBX = (state.bx - state.br) / state.SCALE
	var new_prevBX_27 int16 = state.prevBX
	var prevBX_log_27 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x11, byte((((old_prevBX_27 >> 8) & 0xFF))), byte((((old_prevBX_27 >> 0) & 0xFF))), byte((((new_prevBX_27 >> 8) & 0xFF))), byte((((new_prevBX_27 >> 0) & 0xFF))) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: prevBX_log_27,
		Size: 7,
	})
	var old_prevBY_19 int16 = state.prevBY
	state.prevBY = (state.by - state.br) / state.SCALE
	var new_prevBY_19 int16 = state.prevBY
	var prevBY_log_19 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x12, byte((((old_prevBY_19 >> 8) & 0xFF))), byte((((old_prevBY_19 >> 0) & 0xFF))), byte((((new_prevBY_19 >> 8) & 0xFF))), byte((((new_prevBY_19 >> 0) & 0xFF))) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: prevBY_log_19,
		Size: 7,
	})
	var r_17 uint8 = 183
	var g_18 uint8 = 199
	var b_19 uint8 = 111
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_17,
		G: g_18,
		B: b_19,
	})
	var setColorsent_log_20 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x07, byte(r_17), byte(g_18), byte(b_19) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: setColorsent_log_20,
		Size: 7,
	})
	var x_21 uint8 = uint8(state.prevBX)
	var y_22 uint8 = uint8(state.prevBY)
	var width_23 uint8 = uint8(bs)
	var height_24 uint8 = uint8(bs)
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
		X: x_21,
		Y: y_22,
		Width: width_23,
		Height: height_24,
	})
	var fillRectsent_log_25 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0A, byte(x_21), byte(y_22), byte(width_23), byte(height_24) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: fillRectsent_log_25,
		Size: 8,
	})
	var drawBall_log3 []byte = []byte{ LogType_function_called, state.DEBUG_BIN_ID, 0x04, 0x00 }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: drawBall_log3,
		Size: 4,
	})
}
func (state *ThingBreakoutGameGo) erasePad() {
	var ps int16 = state.padlen / state.SCALE
	if state.prevPX > 0 {
		var r_26 uint8 = state.bgcolor[0]
		var g_27 uint8 = state.bgcolor[1]
		var b_28 uint8 = state.bgcolor[2]
		state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
			R: r_26,
			G: g_27,
			B: b_28,
		})
		var setColorsent_log_29 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x07, byte(r_26), byte(g_27), byte(b_28) }
		state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
			Payload: setColorsent_log_29,
			Size: 7,
		})
		var x_30 uint8 = uint8(state.prevPX)
		var y_31 uint8 = uint8(state.prevPY)
		var width_32 uint8 = uint8(ps)
		var height_33 uint8 = 4
		state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
			X: x_30,
			Y: y_31,
			Width: width_32,
			Height: height_33,
		})
		var fillRectsent_log_34 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0A, byte(x_30), byte(y_31), byte(width_32), byte(height_33) }
		state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
			Payload: fillRectsent_log_34,
			Size: 8,
		})
	}
	var erasePad_log4 []byte = []byte{ LogType_function_called, state.DEBUG_BIN_ID, 0x05, 0x00 }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: erasePad_log4,
		Size: 4,
	})
}
func (state *ThingBreakoutGameGo) drawPad() {
	var ps int16 = state.padlen / state.SCALE
	state.erasePad()
	var old_prevPX_20 int16 = state.prevPX
	state.prevPX = (state.padx - (state.padlen / 2)) / state.SCALE
	var new_prevPX_20 int16 = state.prevPX
	var prevPX_log_20 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x16, byte((((old_prevPX_20 >> 8) & 0xFF))), byte((((old_prevPX_20 >> 0) & 0xFF))), byte((((new_prevPX_20 >> 8) & 0xFF))), byte((((new_prevPX_20 >> 0) & 0xFF))) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: prevPX_log_20,
		Size: 7,
	})
	var old_prevPY_32 int16 = state.prevPY
	state.prevPY = state.pady / state.SCALE
	var new_prevPY_32 int16 = state.prevPY
	var prevPY_log_32 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x17, byte((((old_prevPY_32 >> 8) & 0xFF))), byte((((old_prevPY_32 >> 0) & 0xFF))), byte((((new_prevPY_32 >> 8) & 0xFF))), byte((((new_prevPY_32 >> 0) & 0xFF))) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: prevPY_log_32,
		Size: 7,
	})
	var r_35 uint8 = state.fgcolor[0]
	var g_36 uint8 = state.fgcolor[1]
	var b_37 uint8 = state.fgcolor[2]
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_35,
		G: g_36,
		B: b_37,
	})
	var setColorsent_log_38 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x07, byte(r_35), byte(g_36), byte(b_37) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: setColorsent_log_38,
		Size: 7,
	})
	var x_39 uint8 = uint8(state.prevPX)
	var y_40 uint8 = uint8(state.prevPY)
	var width_41 uint8 = uint8(ps)
	var height_42 uint8 = 4
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
		X: x_39,
		Y: y_40,
		Width: width_41,
		Height: height_42,
	})
	var fillRectsent_log_43 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0A, byte(x_39), byte(y_40), byte(width_41), byte(height_42) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: fillRectsent_log_43,
		Size: 8,
	})
	var drawPad_log5 []byte = []byte{ LogType_function_called, state.DEBUG_BIN_ID, 0x06, 0x00 }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: drawPad_log5,
		Size: 4,
	})
}
func (state *ThingBreakoutGameGo) drawCountDown(c int16) {
	var r_44 uint8 = state.fgcolor[0]
	var g_45 uint8 = state.fgcolor[1]
	var b_46 uint8 = state.fgcolor[2]
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_44,
		G: g_45,
		B: b_46,
	})
	var setColorsent_log_47 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x07, byte(r_44), byte(g_45), byte(b_46) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: setColorsent_log_47,
		Size: 7,
	})
	if c > 0 {
		var r_48 uint8 = state.fgcolor[0]
		var g_49 uint8 = state.fgcolor[1]
		var b_50 uint8 = state.fgcolor[2]
		state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
			R: r_48,
			G: g_49,
			B: b_50,
		})
		var setColorsent_log_51 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x07, byte(r_48), byte(g_49), byte(b_50) }
		state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
			Payload: setColorsent_log_51,
			Size: 7,
		})
		var r_52 uint8 = state.bgcolor[0]
		var g_53 uint8 = state.bgcolor[1]
		var b_54 uint8 = state.bgcolor[2]
		state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetBGColor{
			R: r_52,
			G: g_53,
			B: b_54,
		})
		var setBGColorsent_log_55 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x08, byte(r_52), byte(g_53), byte(b_54) }
		state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
			Payload: setBGColorsent_log_55,
			Size: 7,
		})
		var x_56 uint8 = 80 - 6
		var y_57 uint8 = 90
		var v_58 int16 = c
		var digits_59 uint8 = 1
		var scale_60 uint8 = 4
		state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgdrawInteger{
			X: x_56,
			Y: y_57,
			V: v_58,
			Digits: digits_59,
			Scale: scale_60,
		})
		var drawIntegersent_log_61 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0B, byte(x_56), byte(y_57), byte((((v_58 >> 8) & 0xFF))), byte((((v_58 >> 0) & 0xFF))), byte(digits_59), byte(scale_60) }
		state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
			Payload: drawIntegersent_log_61,
			Size: 10,
		})
	} else {
		var r_62 uint8 = state.bgcolor[0]
		var g_63 uint8 = state.bgcolor[1]
		var b_64 uint8 = state.bgcolor[2]
		state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
			R: r_62,
			G: g_63,
			B: b_64,
		})
		var setColorsent_log_65 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x07, byte(r_62), byte(g_63), byte(b_64) }
		state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
			Payload: setColorsent_log_65,
			Size: 7,
		})
		var x_66 uint8 = 80 - 6
		var y_67 uint8 = 90
		var width_68 uint8 = 12
		var height_69 uint8 = 20
		state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
			X: x_66,
			Y: y_67,
			Width: width_68,
			Height: height_69,
		})
		var fillRectsent_log_70 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0A, byte(x_66), byte(y_67), byte(width_68), byte(height_69) }
		state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
			Payload: fillRectsent_log_70,
			Size: 8,
		})
	}
	var drawCountDown_log6 []byte = []byte{ LogType_function_called, state.DEBUG_BIN_ID, 0x07, 0x00, byte((((c >> 8) & 0xFF))), byte((((c >> 0) & 0xFF))) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: drawCountDown_log6,
		Size: 6,
	})
}
func (state *ThingBreakoutGameGo) drawWalls() {
	var r_71 uint8 = state.fgcolor[0]
	var g_72 uint8 = state.fgcolor[1]
	var b_73 uint8 = state.fgcolor[2]
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_71,
		G: g_72,
		B: b_73,
	})
	var setColorsent_log_74 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x07, byte(r_71), byte(g_72), byte(b_73) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: setColorsent_log_74,
		Size: 7,
	})
	var left uint8 = uint8((state.LEFT / state.SCALE))
	var right uint8 = uint8((state.RIGHT / state.SCALE))
	var top uint8 = uint8((state.TOP / state.SCALE))
	var bottom uint8 = uint8((state.BOTTOM / state.SCALE))
	var xcenter uint8 = uint8(((state.RIGHT - state.LEFT) / state.SCALE))
	var ycenter uint8 = uint8(((state.BOTTOM - state.TOP) / state.SCALE))
	var x_75 uint8 = left - 1
	var y_76 uint8 = top - 1
	var width_77 uint8 = xcenter + 1
	var height_78 uint8 = 1
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
		X: x_75,
		Y: y_76,
		Width: width_77,
		Height: height_78,
	})
	var fillRectsent_log_79 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0A, byte(x_75), byte(y_76), byte(width_77), byte(height_78) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: fillRectsent_log_79,
		Size: 8,
	})
	var x_80 uint8 = left - 1
	var y_81 uint8 = bottom
	var width_82 uint8 = xcenter + 1
	var height_83 uint8 = 1
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
		X: x_80,
		Y: y_81,
		Width: width_82,
		Height: height_83,
	})
	var fillRectsent_log_84 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0A, byte(x_80), byte(y_81), byte(width_82), byte(height_83) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: fillRectsent_log_84,
		Size: 8,
	})
	var x_85 uint8 = left - 1
	var y_86 uint8 = top
	var width_87 uint8 = 1
	var height_88 uint8 = ycenter
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
		X: x_85,
		Y: y_86,
		Width: width_87,
		Height: height_88,
	})
	var fillRectsent_log_89 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0A, byte(x_85), byte(y_86), byte(width_87), byte(height_88) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: fillRectsent_log_89,
		Size: 8,
	})
	var x_90 uint8 = right
	var y_91 uint8 = top
	var width_92 uint8 = 1
	var height_93 uint8 = ycenter
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
		X: x_90,
		Y: y_91,
		Width: width_92,
		Height: height_93,
	})
	var fillRectsent_log_94 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0A, byte(x_90), byte(y_91), byte(width_92), byte(height_93) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: fillRectsent_log_94,
		Size: 8,
	})
	var drawWalls_log7 []byte = []byte{ LogType_function_called, state.DEBUG_BIN_ID, 0x08, 0x00 }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: drawWalls_log7,
		Size: 4,
	})
}
func (state *ThingBreakoutGameGo) bitIsSet(variable uint8, bit uint8)  bool {
	var return_0 bool = bool((((1 << bit) & variable) != 0))
	var bitIsSet_log8 []byte = []byte{ LogType_function_called, state.DEBUG_BIN_ID, 0x09, 0x00, byte(variable), byte(bit), func() byte { if (return_0) { return 1 } else { return 0 } }() }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: bitIsSet_log8,
		Size: 7,
	})
	return return_0
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
	var createBricks_log9 []byte = []byte{ LogType_function_called, state.DEBUG_BIN_ID, 0x0A, 0x00 }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: createBricks_log9,
		Size: 4,
	})
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
	var return_3 uint8 = result
	var bricksLeft_log10 []byte = []byte{ LogType_function_called, state.DEBUG_BIN_ID, 0x0B, 0x00, byte(return_3) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: bricksLeft_log10,
		Size: 5,
	})
	return return_3
}
func (state *ThingBreakoutGameGo) drawBrick(x uint8, y uint8) {
	var bx_1 uint8 = uint8(((state.LEFT + ((state.RIGHT - state.LEFT) / 8) * int16(x)) / state.SCALE + 1))
	var by_1 uint8 = uint8(((state.TOP + 20 * state.SCALE + int16(state.BRICK_HEIGHT) * int16(y) * state.SCALE) / state.SCALE + 1))
	var w uint8 = uint8((((state.RIGHT - state.LEFT) / 8) / state.SCALE - 2))
	var h uint8 = uint8((state.BRICK_HEIGHT - 2))
	var r_95 uint8 = 155
	var g_96 uint8 = 103
	var b_97 uint8 = 89
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_95,
		G: g_96,
		B: b_97,
	})
	var setColorsent_log_98 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x07, byte(r_95), byte(g_96), byte(b_97) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: setColorsent_log_98,
		Size: 7,
	})
	var x_99 uint8 = bx_1
	var y_100 uint8 = by_1
	var width_101 uint8 = w
	var height_102 uint8 = h
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
		X: x_99,
		Y: y_100,
		Width: width_101,
		Height: height_102,
	})
	var fillRectsent_log_103 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0A, byte(x_99), byte(y_100), byte(width_101), byte(height_102) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: fillRectsent_log_103,
		Size: 8,
	})
	var r_104 uint8 = 100
	var g_105 uint8 = 56
	var b_106 uint8 = 43
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_104,
		G: g_105,
		B: b_106,
	})
	var setColorsent_log_107 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x07, byte(r_104), byte(g_105), byte(b_106) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: setColorsent_log_107,
		Size: 7,
	})
	var x_108 uint8 = bx_1
	var y_109 uint8 = by_1
	var width_110 uint8 = w
	var height_111 uint8 = h
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgdrawRect{
		X: x_108,
		Y: y_109,
		Width: width_110,
		Height: height_111,
	})
	var drawRectsent_log_112 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x09, byte(x_108), byte(y_109), byte(width_110), byte(height_111) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: drawRectsent_log_112,
		Size: 8,
	})
	var drawBrick_log11 []byte = []byte{ LogType_function_called, state.DEBUG_BIN_ID, 0x0C, 0x00, byte(x), byte(y) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: drawBrick_log11,
		Size: 6,
	})
}
func (state *ThingBreakoutGameGo) removeBrick(x uint8, y uint8) {
	var bx_1 uint8 = uint8(((state.LEFT + ((state.RIGHT - state.LEFT) / 8) * int16(x)) / state.SCALE + 1))
	var by_1 uint8 = uint8(((state.TOP + 20 * state.SCALE + int16(state.BRICK_HEIGHT) * int16(y) * state.SCALE) / state.SCALE + 1))
	var r_113 uint8 = state.bgcolor[0]
	var g_114 uint8 = state.bgcolor[1]
	var b_115 uint8 = state.bgcolor[2]
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_113,
		G: g_114,
		B: b_115,
	})
	var setColorsent_log_116 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x07, byte(r_113), byte(g_114), byte(b_115) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: setColorsent_log_116,
		Size: 7,
	})
	var x_117 uint8 = bx_1
	var y_118 uint8 = by_1
	var width_119 uint8 = uint8((((state.RIGHT - state.LEFT) / 8) / state.SCALE - 2))
	var height_120 uint8 = state.BRICK_HEIGHT - 2
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
		X: x_117,
		Y: y_118,
		Width: width_119,
		Height: height_120,
	})
	var fillRectsent_log_121 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0A, byte(x_117), byte(y_118), byte(width_119), byte(height_120) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: fillRectsent_log_121,
		Size: 8,
	})
	state.bricks[y] = state.unsetBit(state.bricks[y], x)
	var removeBrick_log12 []byte = []byte{ LogType_function_called, state.DEBUG_BIN_ID, 0x0D, 0x00, byte(x), byte(y) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: removeBrick_log12,
		Size: 6,
	})
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
	var return_3 bool = result
	var collideBrick_log13 []byte = []byte{ LogType_function_called, state.DEBUG_BIN_ID, 0x0E, 0x00, byte((((xpos >> 8) & 0xFF))), byte((((xpos >> 0) & 0xFF))), byte((((ypos >> 8) & 0xFF))), byte((((ypos >> 0) & 0xFF))), func() byte { if (return_3) { return 1 } else { return 0 } }() }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: collideBrick_log13,
		Size: 9,
	})
	return return_3
}
func (state *ThingBreakoutGameGo) drawLevel() {
	var r_122 uint8 = 158
	var g_123 uint8 = 209
	var b_124 uint8 = 130
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_122,
		G: g_123,
		B: b_124,
	})
	var setColorsent_log_125 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x07, byte(r_122), byte(g_123), byte(b_124) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: setColorsent_log_125,
		Size: 7,
	})
	var r_126 uint8 = state.fgcolor[0]
	var g_127 uint8 = state.fgcolor[1]
	var b_128 uint8 = state.fgcolor[2]
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetBGColor{
		R: r_126,
		G: g_127,
		B: b_128,
	})
	var setBGColorsent_log_129 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x08, byte(r_126), byte(g_127), byte(b_128) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: setBGColorsent_log_129,
		Size: 7,
	})
	var r_130 uint8 = state.bgcolor[0]
	var g_131 uint8 = state.bgcolor[1]
	var b_132 uint8 = state.bgcolor[2]
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_130,
		G: g_131,
		B: b_132,
	})
	var setColorsent_log_133 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x07, byte(r_130), byte(g_131), byte(b_132) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: setColorsent_log_133,
		Size: 7,
	})
	var x_134 uint8 = 6
	var y_135 uint8 = 2
	var v_136 int16 = int16(state.level)
	var digits_137 uint8 = 2
	var scale_138 uint8 = 2
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgdrawInteger{
		X: x_134,
		Y: y_135,
		V: v_136,
		Digits: digits_137,
		Scale: scale_138,
	})
	var drawIntegersent_log_139 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0B, byte(x_134), byte(y_135), byte((((v_136 >> 8) & 0xFF))), byte((((v_136 >> 0) & 0xFF))), byte(digits_137), byte(scale_138) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: drawIntegersent_log_139,
		Size: 10,
	})
	var drawLevel_log14 []byte = []byte{ LogType_function_called, state.DEBUG_BIN_ID, 0x0F, 0x00 }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: drawLevel_log14,
		Size: 4,
	})
}
func (state *ThingBreakoutGameGo) incrementScore(diff int8) {
	var old_score_0 int16 = state.score
	state.score = state.score + int16(diff)
	var new_score_0 int16 = state.score
	var score_log_0 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x1B, byte((((old_score_0 >> 8) & 0xFF))), byte((((old_score_0 >> 0) & 0xFF))), byte((((new_score_0 >> 8) & 0xFF))), byte((((new_score_0 >> 0) & 0xFF))) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: score_log_0,
		Size: 7,
	})
	if state.score < 0 {
		var old_score_1 int16 = state.score
		state.score = 0
		var new_score_1 int16 = state.score
		var score_log_1 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x1B, byte((((old_score_1 >> 8) & 0xFF))), byte((((old_score_1 >> 0) & 0xFF))), byte((((new_score_1 >> 8) & 0xFF))), byte((((new_score_1 >> 0) & 0xFF))) }
		state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
			Payload: score_log_1,
			Size: 7,
		})
	}
	state.drawScore()
	var incrementScore_log15 []byte = []byte{ LogType_function_called, state.DEBUG_BIN_ID, 0x10, 0x00, byte(diff) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: incrementScore_log15,
		Size: 5,
	})
}
func (state *ThingBreakoutGameGo) drawScore() {
	var r_140 uint8 = 158
	var g_141 uint8 = 209
	var b_142 uint8 = 130
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_140,
		G: g_141,
		B: b_142,
	})
	var setColorsent_log_143 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x07, byte(r_140), byte(g_141), byte(b_142) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: setColorsent_log_143,
		Size: 7,
	})
	var r_144 uint8 = state.fgcolor[0]
	var g_145 uint8 = state.fgcolor[1]
	var b_146 uint8 = state.fgcolor[2]
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetBGColor{
		R: r_144,
		G: g_145,
		B: b_146,
	})
	var setBGColorsent_log_147 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x08, byte(r_144), byte(g_145), byte(b_146) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: setBGColorsent_log_147,
		Size: 7,
	})
	var x_148 uint8 = 58
	var y_149 uint8 = 2
	var v_150 int16 = state.score
	var digits_151 uint8 = 5
	var scale_152 uint8 = 2
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgdrawInteger{
		X: x_148,
		Y: y_149,
		V: v_150,
		Digits: digits_151,
		Scale: scale_152,
	})
	var drawIntegersent_log_153 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0B, byte(x_148), byte(y_149), byte((((v_150 >> 8) & 0xFF))), byte((((v_150 >> 0) & 0xFF))), byte(digits_151), byte(scale_152) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: drawIntegersent_log_153,
		Size: 10,
	})
	var drawScore_log16 []byte = []byte{ LogType_function_called, state.DEBUG_BIN_ID, 0x11, 0x00 }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: drawScore_log16,
		Size: 4,
	})
}
func (state *ThingBreakoutGameGo) drawLives() {
	var r_154 uint8 = state.fgcolor[0]
	var g_155 uint8 = state.fgcolor[1]
	var b_156 uint8 = state.fgcolor[2]
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_154,
		G: g_155,
		B: b_156,
	})
	var setColorsent_log_157 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x07, byte(r_154), byte(g_155), byte(b_156) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: setColorsent_log_157,
		Size: 7,
	})
	var x_158 uint8 = 124
	var y_159 uint8 = 4
	var width_160 uint8 = 24 + 6
	var height_161 uint8 = 6
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
		X: x_158,
		Y: y_159,
		Width: width_160,
		Height: height_161,
	})
	var fillRectsent_log_162 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0A, byte(x_158), byte(y_159), byte(width_160), byte(height_161) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: fillRectsent_log_162,
		Size: 8,
	})
	var r_163 uint8 = 183
	var g_164 uint8 = 199
	var b_165 uint8 = 111
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_163,
		G: g_164,
		B: b_165,
	})
	var setColorsent_log_166 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x07, byte(r_163), byte(g_164), byte(b_165) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: setColorsent_log_166,
		Size: 7,
	})
	var i uint8 = 0
	for i < state.lives {
		var x_167 uint8 = 124 + (2 - i) * 12
		var y_168 uint8 = 4
		var width_169 uint8 = 6
		var height_170 uint8 = 6
		state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
			X: x_167,
			Y: y_168,
			Width: width_169,
			Height: height_170,
		})
		var fillRectsent_log_171 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0A, byte(x_167), byte(y_168), byte(width_169), byte(height_170) }
		state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
			Payload: fillRectsent_log_171,
			Size: 8,
		})
		i = i + 1
	}
	var drawLives_log17 []byte = []byte{ LogType_function_called, state.DEBUG_BIN_ID, 0x12, 0x00 }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: drawLives_log17,
		Size: 4,
	})
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
				var positionhandled_log_275 []byte = []byte{ LogType_message_handled, state.DEBUG_BIN_ID, 0x03, 0x12, 0x00, 0x00, byte((((e.X >> 8) & 0xFF))), byte((((e.X >> 0) & 0xFF))), byte((((e.Y >> 8) & 0xFF))), byte((((e.Y >> 0) & 0xFF))) }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: positionhandled_log_275,
					Size: 10,
				})
				var center int32 = (int32(state.RIGHT) - int32(state.LEFT) - int32(state.padlen))
				center = int32(e.X) * center
				center = center / 200
				var old_padx_9 int16 = state.padx
				state.padx = int16((int32(state.LEFT) + center + (int32(state.RIGHT) - int32(state.LEFT)) / 2))
				var new_padx_9 int16 = state.padx
				var padx_log_9 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x0E, byte((((old_padx_9 >> 8) & 0xFF))), byte((((old_padx_9 >> 0) & 0xFF))), byte((((new_padx_9 >> 8) & 0xFF))), byte((((new_padx_9 >> 0) & 0xFF))) }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: padx_log_9,
					Size: 7,
				})
			}
		}
	case FragmentTimerMsgsMsgtimer_timeout:
		if e := typedMessage; port == BreakoutGameGo_BreakoutGame_clock && (true) {
			return true, true, state, func() {
				var timer_timeoutlost_log_283 []byte = []byte{ LogType_message_lost, state.DEBUG_BIN_ID, 0x01, 0x16, byte(e.Id) }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: timer_timeoutlost_log_283,
					Size: 5,
				})
			}
		}
	case FragmentDisplayMsgsMsgdisplayReady:
		if port == BreakoutGameGo_BreakoutGame_display && (true) {
			return true, true, state, func() {
				var displayReadylost_log_284 []byte = []byte{ LogType_message_lost, state.DEBUG_BIN_ID, 0x02, 0x10 }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: displayReadylost_log_284,
					Size: 4,
				})
			}
		}
	case FragmentBreakoutGameMsglostBall:
		if port == BreakoutGameGo_BreakoutGame_game && (true) {
			return true, true, state, func() {
				var lostBalllost_log_285 []byte = []byte{ LogType_message_lost, state.DEBUG_BIN_ID, 0x05, 0x01 }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: lostBalllost_log_285,
					Size: 4,
				})
			}
		}
		if port == BreakoutGameGo_BreakoutGame_pro_game && (true) {
			return true, true, state, func() {
				var lostBalllost_log_287 []byte = []byte{ LogType_message_lost, state.DEBUG_BIN_ID, 0x07, 0x01 }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: lostBalllost_log_287,
					Size: 4,
				})
			}
		}
	case FragmentBreakoutGameMsgnextLevel:
		if port == BreakoutGameGo_BreakoutGame_game && (true) {
			return true, true, state, func() {
				var nextLevellost_log_286 []byte = []byte{ LogType_message_lost, state.DEBUG_BIN_ID, 0x05, 0x02 }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: nextLevellost_log_286,
					Size: 4,
				})
			}
		}
		if port == BreakoutGameGo_BreakoutGame_pro_game && (true) {
			return true, true, state, func() {
				var nextLevellost_log_288 []byte = []byte{ LogType_message_lost, state.DEBUG_BIN_ID, 0x07, 0x02 }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: nextLevellost_log_288,
					Size: 4,
				})
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
	var xsize_172 uint8 = state.XDISPSIZE
	var ysize_173 uint8 = state.YDISPSIZE
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgcreate{
		Xsize: xsize_172,
		Ysize: ysize_173,
	})
	var createsent_log_174 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0D, byte(xsize_172), byte(ysize_173) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: createsent_log_174,
		Size: 6,
	})
}
func (state *FragmentBreakoutGameStateChartSCStateINIT) Handle(port gosm.Port, message interface{}) (handled bool, internal bool, next gosm.State, action func()) {
	switch message.(type) {
	case FragmentDisplayMsgsMsgdisplayReady:
		if port == BreakoutGameGo_BreakoutGame_display {
			return true, false, state.FragmentBreakoutGameStateChartSCStateLAUNCH, func() {
				var displayReadyhandled_log_276 []byte = []byte{ LogType_message_handled, state.DEBUG_BIN_ID, 0x02, 0x10, 0x01, 0x02 }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: displayReadyhandled_log_276,
					Size: 6,
				})
				state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgclear{})
				var clearsent_log_175 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x06 }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: clearsent_log_175,
					Size: 4,
				})
				state.initColors()
				var r_176 uint8 = state.bgcolor[0]
				var g_177 uint8 = state.bgcolor[1]
				var b_178 uint8 = state.bgcolor[2]
				state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
					R: r_176,
					G: g_177,
					B: b_178,
				})
				var setColorsent_log_179 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x07, byte(r_176), byte(g_177), byte(b_178) }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: setColorsent_log_179,
					Size: 7,
				})
				var x_180 uint8 = 0
				var y_181 uint8 = 0
				var width_182 uint8 = state.XDISPSIZE
				var height_183 uint8 = state.YDISPSIZE
				state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
					X: x_180,
					Y: y_181,
					Width: width_182,
					Height: height_183,
				})
				var fillRectsent_log_184 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0A, byte(x_180), byte(y_181), byte(width_182), byte(height_183) }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: fillRectsent_log_184,
					Size: 8,
				})
				var r_185 uint8 = state.fgcolor[0]
				var g_186 uint8 = state.fgcolor[1]
				var b_187 uint8 = state.fgcolor[2]
				state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
					R: r_185,
					G: g_186,
					B: b_187,
				})
				var setColorsent_log_188 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x07, byte(r_185), byte(g_186), byte(b_187) }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: setColorsent_log_188,
					Size: 7,
				})
				var x_189 uint8 = 0
				var y_190 uint8 = 0
				var width_191 uint8 = state.XDISPSIZE
				var height_192 uint8 = 14
				state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
					X: x_189,
					Y: y_190,
					Width: width_191,
					Height: height_192,
				})
				var fillRectsent_log_193 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0A, byte(x_189), byte(y_190), byte(width_191), byte(height_192) }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: fillRectsent_log_193,
					Size: 8,
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
	var id_194 uint8 = 0
	var time_195 uint16 = state.period
	state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_start{
		Id: id_194,
		Time: time_195,
	})
	var timer_startsent_log_196 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x01, 0x14, byte(id_194), byte((((time_195 >> 8) & 0xFF))), byte((((time_195 >> 0) & 0xFF))) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: timer_startsent_log_196,
		Size: 7,
	})
	var old_countdown_10 uint8 = state.countdown
	state.countdown = 3
	var new_countdown_10 uint8 = state.countdown
	var countdown_log_10 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x1E, byte(old_countdown_10), byte(new_countdown_10) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: countdown_log_10,
		Size: 5,
	})
	state.drawScore()
	state.drawLives()
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgupdate{})
	var updatesent_log_197 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0F }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: updatesent_log_197,
		Size: 4,
	})
}
func (state *FragmentBreakoutGameStateChartSCStateLAUNCH) Handle(port gosm.Port, message interface{}) (handled bool, internal bool, next gosm.State, action func()) {
	switch typedMessage := message.(type) {
	case FragmentTimerMsgsMsgtimer_timeout:
		if t := typedMessage; port == BreakoutGameGo_BreakoutGame_clock && (t.Id == 0 && state.countdown > 0) {
			return true, true, state, func() {
				var timer_timeouthandled_log_278 []byte = []byte{ LogType_message_handled, state.DEBUG_BIN_ID, 0x01, 0x16, 0x02, 0x00, byte(t.Id) }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: timer_timeouthandled_log_278,
					Size: 7,
				})
				var id_198 uint8 = 0
				var time_199 uint16 = state.period
				state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_start{
					Id: id_198,
					Time: time_199,
				})
				var timer_startsent_log_200 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x01, 0x14, byte(id_198), byte((((time_199 >> 8) & 0xFF))), byte((((time_199 >> 0) & 0xFF))) }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: timer_startsent_log_200,
					Size: 7,
				})
				state.drawPad()
				if (state.countdown % 30) == 0 {
					state.drawCountDown(int16(state.countdown) / 30)
				}
				var old_countdown_11 uint8 = state.countdown
				state.countdown = state.countdown - 1
				var new_countdown_11 uint8 = state.countdown
				var countdown_log_11 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x1E, byte(old_countdown_11), byte(new_countdown_11) }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: countdown_log_11,
					Size: 5,
				})
				state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgupdate{})
				var updatesent_log_201 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0F }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: updatesent_log_201,
					Size: 4,
				})
			}
		}
		if t := typedMessage; port == BreakoutGameGo_BreakoutGame_clock && (t.Id == 0 && state.countdown == 0) {
			return true, false, state.FragmentBreakoutGameStateChartSCStatePLAY, func() {
				var timer_timeouthandled_log_277 []byte = []byte{ LogType_message_handled, state.DEBUG_BIN_ID, 0x01, 0x16, 0x02, 0x03, byte(t.Id) }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: timer_timeouthandled_log_277,
					Size: 7,
				})
				state.drawCountDown(0)
				state.resetBall()
				state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgupdate{})
				var updatesent_log_202 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0F }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: updatesent_log_202,
					Size: 4,
				})
			}
		}
	}
	return false, false, state, nil
}
func (state *FragmentBreakoutGameStateChartSCStateLAUNCH) OnExit() {}

func (state *FragmentBreakoutGameStateChartSCStatePLAY) OnEntry() {
	var id_203 uint8 = 0
	var time_204 uint16 = state.period
	state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_start{
		Id: id_203,
		Time: time_204,
	})
	var timer_startsent_log_205 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x01, 0x14, byte(id_203), byte((((time_204 >> 8) & 0xFF))), byte((((time_204 >> 0) & 0xFF))) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: timer_startsent_log_205,
		Size: 7,
	})
}
func (state *FragmentBreakoutGameStateChartSCStatePLAY) Handle(port gosm.Port, message interface{}) (handled bool, internal bool, next gosm.State, action func()) {
	switch typedMessage := message.(type) {
	case FragmentTimerMsgsMsgtimer_timeout:
		if t := typedMessage; port == BreakoutGameGo_BreakoutGame_clock && (t.Id == 0) {
			return true, true, state, func() {
				var timer_timeouthandled_log_281 []byte = []byte{ LogType_message_handled, state.DEBUG_BIN_ID, 0x01, 0x16, 0x03, 0x00, byte(t.Id) }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: timer_timeouthandled_log_281,
					Size: 7,
				})
				var old_bx_22 int16 = state.bx
				state.bx = state.bx + state.dx
				var new_bx_22 int16 = state.bx
				var bx_log_22 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x0A, byte((((old_bx_22 >> 8) & 0xFF))), byte((((old_bx_22 >> 0) & 0xFF))), byte((((new_bx_22 >> 8) & 0xFF))), byte((((new_bx_22 >> 0) & 0xFF))) }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: bx_log_22,
					Size: 7,
				})
				var old_by_29 int16 = state.by
				state.by = state.by + state.dy
				var new_by_29 int16 = state.by
				var by_log_29 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x0B, byte((((old_by_29 >> 8) & 0xFF))), byte((((old_by_29 >> 0) & 0xFF))), byte((((new_by_29 >> 8) & 0xFF))), byte((((new_by_29 >> 0) & 0xFF))) }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: by_log_29,
					Size: 7,
				})
				var wl int16 = state.LEFT + state.br
				var wr int16 = state.RIGHT - state.br
				var wt int16 = state.TOP + state.br
				var wb int16 = state.BOTTOM - state.br
				if state.bx < wl {
					var old_dx_13 int16 = state.dx
					state.dx =  -(state.dx)
					var new_dx_13 int16 = state.dx
					var dx_log_13 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x0C, byte((((old_dx_13 >> 8) & 0xFF))), byte((((old_dx_13 >> 0) & 0xFF))), byte((((new_dx_13 >> 8) & 0xFF))), byte((((new_dx_13 >> 0) & 0xFF))) }
					state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
						Payload: dx_log_13,
						Size: 7,
					})
					var old_bx_23 int16 = state.bx
					state.bx = 2 * wl - state.bx
					var new_bx_23 int16 = state.bx
					var bx_log_23 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x0A, byte((((old_bx_23 >> 8) & 0xFF))), byte((((old_bx_23 >> 0) & 0xFF))), byte((((new_bx_23 >> 8) & 0xFF))), byte((((new_bx_23 >> 0) & 0xFF))) }
					state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
						Payload: bx_log_23,
						Size: 7,
					})
					state.incrementScore( -(1))
				} else {
					if state.bx > wr {
						var old_dx_14 int16 = state.dx
						state.dx =  -(state.dx)
						var new_dx_14 int16 = state.dx
						var dx_log_14 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x0C, byte((((old_dx_14 >> 8) & 0xFF))), byte((((old_dx_14 >> 0) & 0xFF))), byte((((new_dx_14 >> 8) & 0xFF))), byte((((new_dx_14 >> 0) & 0xFF))) }
						state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
							Payload: dx_log_14,
							Size: 7,
						})
						var old_bx_24 int16 = state.bx
						state.bx = 2 * wr - state.bx
						var new_bx_24 int16 = state.bx
						var bx_log_24 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x0A, byte((((old_bx_24 >> 8) & 0xFF))), byte((((old_bx_24 >> 0) & 0xFF))), byte((((new_bx_24 >> 8) & 0xFF))), byte((((new_bx_24 >> 0) & 0xFF))) }
						state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
							Payload: bx_log_24,
							Size: 7,
						})
						state.incrementScore( -(1))
					}
				}
				if state.by < wt {
					var old_dy_5 int16 = state.dy
					state.dy =  -(state.dy)
					var new_dy_5 int16 = state.dy
					var dy_log_5 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x0D, byte((((old_dy_5 >> 8) & 0xFF))), byte((((old_dy_5 >> 0) & 0xFF))), byte((((new_dy_5 >> 8) & 0xFF))), byte((((new_dy_5 >> 0) & 0xFF))) }
					state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
						Payload: dy_log_5,
						Size: 7,
					})
					var old_by_30 int16 = state.by
					state.by = 2 * wt - state.by
					var new_by_30 int16 = state.by
					var by_log_30 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x0B, byte((((old_by_30 >> 8) & 0xFF))), byte((((old_by_30 >> 0) & 0xFF))), byte((((new_by_30 >> 8) & 0xFF))), byte((((new_by_30 >> 0) & 0xFF))) }
					state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
						Payload: by_log_30,
						Size: 7,
					})
					state.incrementScore( -(1))
				} else {
					if state.by > wb {
						state.Send(BreakoutGameGo_BreakoutGame_game, FragmentBreakoutGameMsglostBall{})
						var lostBallsent_log_206 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x05, 0x01 }
						state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
							Payload: lostBallsent_log_206,
							Size: 4,
						})
						state.Send(BreakoutGameGo_BreakoutGame_req_game, FragmentBreakoutGameMsglostBall{})
						var lostBallsent_log_207 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x06, 0x01 }
						state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
							Payload: lostBallsent_log_207,
							Size: 4,
						})
					}
				}
				if state.dy > 0 {
					if state.by > state.pady - state.br && state.by < state.pady + state.br {
						if state.bx > state.padx - state.padlen / 2 && state.bx < state.padx + state.padlen / 2 {
							var old_dy_6 int16 = state.dy
							state.dy =  -(state.dy)
							var new_dy_6 int16 = state.dy
							var dy_log_6 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x0D, byte((((old_dy_6 >> 8) & 0xFF))), byte((((old_dy_6 >> 0) & 0xFF))), byte((((new_dy_6 >> 8) & 0xFF))), byte((((new_dy_6 >> 0) & 0xFF))) }
							state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
								Payload: dy_log_6,
								Size: 7,
							})
							var old_by_31 int16 = state.by
							state.by = 2 * (state.pady - state.br) - state.by
							var new_by_31 int16 = state.by
							var by_log_31 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x0B, byte((((old_by_31 >> 8) & 0xFF))), byte((((old_by_31 >> 0) & 0xFF))), byte((((new_by_31 >> 8) & 0xFF))), byte((((new_by_31 >> 0) & 0xFF))) }
							state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
								Payload: by_log_31,
								Size: 7,
							})
							var old_dx_15 int16 = state.dx
							state.dx = state.dx / 4 + (state.bx - state.padx) / 4
							var new_dx_15 int16 = state.dx
							var dx_log_15 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x0C, byte((((old_dx_15 >> 8) & 0xFF))), byte((((old_dx_15 >> 0) & 0xFF))), byte((((new_dx_15 >> 8) & 0xFF))), byte((((new_dx_15 >> 0) & 0xFF))) }
							state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
								Payload: dx_log_15,
								Size: 7,
							})
						}
					}
				}
				var collision bool = state.collideBrick(state.bx - state.br, state.by - state.br) || state.collideBrick(state.bx + state.br, state.by - state.br) || state.collideBrick(state.bx + state.br, state.by + state.br) || state.collideBrick(state.bx - state.br, state.by + state.br)
				if collision {
					var old_dy_7 int16 = state.dy
					state.dy =  -(state.dy)
					var new_dy_7 int16 = state.dy
					var dy_log_7 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x0D, byte((((old_dy_7 >> 8) & 0xFF))), byte((((old_dy_7 >> 0) & 0xFF))), byte((((new_dy_7 >> 8) & 0xFF))), byte((((new_dy_7 >> 0) & 0xFF))) }
					state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
						Payload: dy_log_7,
						Size: 7,
					})
					state.incrementScore(10)
					if state.bricksLeft() == 0 {
						state.Send(BreakoutGameGo_BreakoutGame_game, FragmentBreakoutGameMsgnextLevel{})
						var nextLevelsent_log_208 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x05, 0x02 }
						state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
							Payload: nextLevelsent_log_208,
							Size: 4,
						})
						state.Send(BreakoutGameGo_BreakoutGame_req_game, FragmentBreakoutGameMsgnextLevel{})
						var nextLevelsent_log_209 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x06, 0x02 }
						state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
							Payload: nextLevelsent_log_209,
							Size: 4,
						})
					}
				}
				state.drawBall()
				state.drawPad()
				var ballx_210 int16 = state.bx
				var bally_211 int16 = state.by
				var padx_212 int16 = state.padx
				var pady_213 int16 = state.pady
				state.Send(BreakoutGameGo_BreakoutGame_ia, FragmentIAControllerMsgMsgupdateIA{
					Ballx: ballx_210,
					Bally: bally_211,
					Padx: padx_212,
					Pady: pady_213,
				})
				var updateIAsent_log_214 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x04, 0x13, byte((((ballx_210 >> 8) & 0xFF))), byte((((ballx_210 >> 0) & 0xFF))), byte((((bally_211 >> 8) & 0xFF))), byte((((bally_211 >> 0) & 0xFF))), byte((((padx_212 >> 8) & 0xFF))), byte((((padx_212 >> 0) & 0xFF))), byte((((pady_213 >> 8) & 0xFF))), byte((((pady_213 >> 0) & 0xFF))) }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: updateIAsent_log_214,
					Size: 12,
				})
				state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgupdate{})
				var updatesent_log_215 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0F }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: updatesent_log_215,
					Size: 4,
				})
				state.log(false)
				var id_216 uint8 = 0
				var time_217 uint16 = state.period
				state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_start{
					Id: id_216,
					Time: time_217,
				})
				var timer_startsent_log_218 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x01, 0x14, byte(id_216), byte((((time_217 >> 8) & 0xFF))), byte((((time_217 >> 0) & 0xFF))) }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: timer_startsent_log_218,
					Size: 7,
				})
			}
		}
	case FragmentBreakoutGameMsglostBall:
		if port == BreakoutGameGo_BreakoutGame_game {
			return true, false, state.FragmentBreakoutGameStateChartSCStateLOSTBALL, func() {
				var lostBallhandled_log_273 []byte = []byte{ LogType_message_handled, state.DEBUG_BIN_ID, 0x05, 0x01, 0x03, 0x04 }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: lostBallhandled_log_273,
					Size: 6,
				})
				var id_219 uint8 = 0
				state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_cancel{
					Id: id_219,
				})
				var timer_cancelsent_log_220 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x01, 0x15, byte(id_219) }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: timer_cancelsent_log_220,
					Size: 5,
				})
			}
		}
		if port == BreakoutGameGo_BreakoutGame_pro_game {
			return true, false, state.FragmentBreakoutGameStateChartSCStateLOSTBALL, func() {
				var lostBallhandled_log_271 []byte = []byte{ LogType_message_handled, state.DEBUG_BIN_ID, 0x07, 0x01, 0x03, 0x04 }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: lostBallhandled_log_271,
					Size: 6,
				})
				var id_223 uint8 = 0
				state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_cancel{
					Id: id_223,
				})
				var timer_cancelsent_log_224 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x01, 0x15, byte(id_223) }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: timer_cancelsent_log_224,
					Size: 5,
				})
			}
		}
	case FragmentBreakoutGameMsgnextLevel:
		if port == BreakoutGameGo_BreakoutGame_game {
			return true, false, state.FragmentBreakoutGameStateChartSCStateNEXTLEVEL, func() {
				var nextLevelhandled_log_274 []byte = []byte{ LogType_message_handled, state.DEBUG_BIN_ID, 0x05, 0x02, 0x03, 0x05 }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: nextLevelhandled_log_274,
					Size: 6,
				})
				var id_221 uint8 = 0
				state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_cancel{
					Id: id_221,
				})
				var timer_cancelsent_log_222 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x01, 0x15, byte(id_221) }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: timer_cancelsent_log_222,
					Size: 5,
				})
			}
		}
		if port == BreakoutGameGo_BreakoutGame_pro_game {
			return true, false, state.FragmentBreakoutGameStateChartSCStateNEXTLEVEL, func() {
				var nextLevelhandled_log_272 []byte = []byte{ LogType_message_handled, state.DEBUG_BIN_ID, 0x07, 0x02, 0x03, 0x05 }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: nextLevelhandled_log_272,
					Size: 6,
				})
				var id_225 uint8 = 0
				state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_cancel{
					Id: id_225,
				})
				var timer_cancelsent_log_226 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x01, 0x15, byte(id_225) }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: timer_cancelsent_log_226,
					Size: 5,
				})
			}
		}
	}
	return false, false, state, nil
}
func (state *FragmentBreakoutGameStateChartSCStatePLAY) OnExit() {}

func (state *FragmentBreakoutGameStateChartSCStateLOSTBALL) OnEntry() {
	var id_227 uint8 = 0
	var time_228 uint16 = state.period
	state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_start{
		Id: id_227,
		Time: time_228,
	})
	var timer_startsent_log_229 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x01, 0x14, byte(id_227), byte((((time_228 >> 8) & 0xFF))), byte((((time_228 >> 0) & 0xFF))) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: timer_startsent_log_229,
		Size: 7,
	})
	var old_lives_16 uint8 = state.lives
	state.lives = state.lives - 1
	var new_lives_16 uint8 = state.lives
	var lives_log_16 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x1C, byte(old_lives_16), byte(new_lives_16) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: lives_log_16,
		Size: 5,
	})
	state.eraseBall()
	state.erasePad()
	state.drawLives()
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgupdate{})
	var updatesent_log_230 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0F }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: updatesent_log_230,
		Size: 4,
	})
	state.log(true)
}
func (state *FragmentBreakoutGameStateChartSCStateLOSTBALL) Handle(port gosm.Port, message interface{}) (handled bool, internal bool, next gosm.State, action func()) {
	switch typedMessage := message.(type) {
	case FragmentTimerMsgsMsgtimer_timeout:
		if t := typedMessage; port == BreakoutGameGo_BreakoutGame_clock && (t.Id == 0 && state.lives > 0) {
			return true, false, state.FragmentBreakoutGameStateChartSCStateLAUNCH, func() {
				var timer_timeouthandled_log_279 []byte = []byte{ LogType_message_handled, state.DEBUG_BIN_ID, 0x01, 0x16, 0x04, 0x02, byte(t.Id) }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: timer_timeouthandled_log_279,
					Size: 7,
				})
			}
		}
		if t := typedMessage; port == BreakoutGameGo_BreakoutGame_clock && (t.Id == 0 && state.lives == 0) {
			return true, false, state.FragmentBreakoutGameStateChartSCStateGAMEOVER, func() {
				var timer_timeouthandled_log_280 []byte = []byte{ LogType_message_handled, state.DEBUG_BIN_ID, 0x01, 0x16, 0x04, 0x06, byte(t.Id) }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: timer_timeouthandled_log_280,
					Size: 7,
				})
			}
		}
	}
	return false, false, state, nil
}
func (state *FragmentBreakoutGameStateChartSCStateLOSTBALL) OnExit() {}

func (state *FragmentBreakoutGameStateChartSCStateNEXTLEVEL) OnEntry() {
	var id_231 uint8 = 0
	var time_232 uint16 = state.period
	state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_start{
		Id: id_231,
		Time: time_232,
	})
	var timer_startsent_log_233 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x01, 0x14, byte(id_231), byte((((time_232 >> 8) & 0xFF))), byte((((time_232 >> 0) & 0xFF))) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: timer_startsent_log_233,
		Size: 7,
	})
	var old_level_2 uint8 = state.level
	state.level = state.level + 1
	var new_level_2 uint8 = state.level
	var level_log_2 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x1D, byte(old_level_2), byte(new_level_2) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: level_log_2,
		Size: 5,
	})
	state.drawLevel()
	state.eraseBall()
	state.erasePad()
	if (state.level % 2) == 0 && state.padlen > 5 * state.SCALE {
		var old_padlen_3 int16 = state.padlen
		state.padlen = state.padlen - (4 * state.SCALE)
		var new_padlen_3 int16 = state.padlen
		var padlen_log_3 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x10, byte((((old_padlen_3 >> 8) & 0xFF))), byte((((old_padlen_3 >> 0) & 0xFF))), byte((((new_padlen_3 >> 8) & 0xFF))), byte((((new_padlen_3 >> 0) & 0xFF))) }
		state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
			Payload: padlen_log_3,
			Size: 7,
		})
	}
	if (state.level % 2) == 1 {
		var old_dy_8 int16 = state.dy
		state.dy = (state.dy * 3) / 2
		var new_dy_8 int16 = state.dy
		var dy_log_8 []byte = []byte{ LogType_property_changed, state.DEBUG_BIN_ID, 0x0D, byte((((old_dy_8 >> 8) & 0xFF))), byte((((old_dy_8 >> 0) & 0xFF))), byte((((new_dy_8 >> 8) & 0xFF))), byte((((new_dy_8 >> 0) & 0xFF))) }
		state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
			Payload: dy_log_8,
			Size: 7,
		})
	}
	state.drawLives()
	state.createBricks()
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgupdate{})
	var updatesent_log_234 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0F }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: updatesent_log_234,
		Size: 4,
	})
}
func (state *FragmentBreakoutGameStateChartSCStateNEXTLEVEL) Handle(port gosm.Port, message interface{}) (handled bool, internal bool, next gosm.State, action func()) {
	switch typedMessage := message.(type) {
	case FragmentTimerMsgsMsgtimer_timeout:
		if t := typedMessage; port == BreakoutGameGo_BreakoutGame_clock && (t.Id == 0) {
			return true, false, state.FragmentBreakoutGameStateChartSCStateLAUNCH, func() {
				var timer_timeouthandled_log_282 []byte = []byte{ LogType_message_handled, state.DEBUG_BIN_ID, 0x01, 0x16, 0x05, 0x02, byte(t.Id) }
				state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
					Payload: timer_timeouthandled_log_282,
					Size: 7,
				})
			}
		}
	}
	return false, false, state, nil
}
func (state *FragmentBreakoutGameStateChartSCStateNEXTLEVEL) OnExit() {}

func (state *FragmentBreakoutGameStateChartSCStateGAMEOVER) OnEntry() {
	state.eraseBall()
	state.erasePad()
	var r_235 uint8 = 255
	var g_236 uint8 = 255
	var b_237 uint8 = 255
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_235,
		G: g_236,
		B: b_237,
	})
	var setColorsent_log_238 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x07, byte(r_235), byte(g_236), byte(b_237) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: setColorsent_log_238,
		Size: 7,
	})
	var x_239 uint8 = 8
	var y_240 uint8 = 30
	var width_241 uint8 = 142
	var height_242 uint8 = 76
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
		X: x_239,
		Y: y_240,
		Width: width_241,
		Height: height_242,
	})
	var fillRectsent_log_243 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0A, byte(x_239), byte(y_240), byte(width_241), byte(height_242) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: fillRectsent_log_243,
		Size: 8,
	})
	var r_244 uint8 = state.fgcolor[0]
	var g_245 uint8 = state.fgcolor[1]
	var b_246 uint8 = state.fgcolor[2]
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_244,
		G: g_245,
		B: b_246,
	})
	var setColorsent_log_247 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x07, byte(r_244), byte(g_245), byte(b_246) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: setColorsent_log_247,
		Size: 7,
	})
	var x_248 uint8 = 9
	var y_249 uint8 = 31
	var width_250 uint8 = 140
	var height_251 uint8 = 50
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
		X: x_248,
		Y: y_249,
		Width: width_250,
		Height: height_251,
	})
	var fillRectsent_log_252 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0A, byte(x_248), byte(y_249), byte(width_250), byte(height_251) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: fillRectsent_log_252,
		Size: 8,
	})
	var r_253 uint8 = state.fgcolor[0]
	var g_254 uint8 = state.fgcolor[1]
	var b_255 uint8 = state.fgcolor[2]
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetBGColor{
		R: r_253,
		G: g_254,
		B: b_255,
	})
	var setBGColorsent_log_256 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x08, byte(r_253), byte(g_254), byte(b_255) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: setBGColorsent_log_256,
		Size: 7,
	})
	var r_257 uint8 = 158
	var g_258 uint8 = 209
	var b_259 uint8 = 130
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_257,
		G: g_258,
		B: b_259,
	})
	var setColorsent_log_260 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x07, byte(r_257), byte(g_258), byte(b_259) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: setColorsent_log_260,
		Size: 7,
	})
	var x_261 uint8 = 23
	var y_262 uint8 = 40
	var v_263 int16 = state.score
	var digits_264 uint8 = 5
	var scale_265 uint8 = 6
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgdrawInteger{
		X: x_261,
		Y: y_262,
		V: v_263,
		Digits: digits_264,
		Scale: scale_265,
	})
	var drawIntegersent_log_266 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0B, byte(x_261), byte(y_262), byte((((v_263 >> 8) & 0xFF))), byte((((v_263 >> 0) & 0xFF))), byte(digits_264), byte(scale_265) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: drawIntegersent_log_266,
		Size: 10,
	})
	var x_267 uint8 = 26
	var y_268 uint8 = 87
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgdrawThingML{
		X: x_267,
		Y: y_268,
	})
	var drawThingMLsent_log_269 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0C, byte(x_267), byte(y_268) }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: drawThingMLsent_log_269,
		Size: 6,
	})
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgupdate{})
	var updatesent_log_270 []byte = []byte{ LogType_message_sent, state.DEBUG_BIN_ID, 0x02, 0x0F }
	state.Send(BreakoutGameGo_WithBinaryLog_log, FragmentLogMsgsMsglog{
		Payload: updatesent_log_270,
		Size: 4,
	})
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
		DEBUG_BIN_ID: original.DEBUG_BIN_ID,
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
