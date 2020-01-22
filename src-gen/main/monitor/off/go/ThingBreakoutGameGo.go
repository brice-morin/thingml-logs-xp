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
	BreakoutGameGo_WithLog_log = 0
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
	DEBUG_ID string
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
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgfunction_called{
		Inst: state.DEBUG_ID,
		Fn_name: "initColors",
		Ty: "void_",
		Returns: "",
		Params: "",
	})
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
	var params_3 string = "" + ("r=" + (fmt.Sprintf("%d", int64(r_0)) + ",")) + ("g=" + (fmt.Sprintf("%d", int64(g_1)) + ",")) + ("b=" + (fmt.Sprintf("%d", int64(b_2)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "setBGColor",
		Params: params_3,
	})
	var r_4 uint8 = state.fgcolor[0]
	var g_5 uint8 = state.fgcolor[1]
	var b_6 uint8 = state.fgcolor[2]
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_4,
		G: g_5,
		B: b_6,
	})
	var params_7 string = "" + ("r=" + (fmt.Sprintf("%d", int64(r_4)) + ",")) + ("g=" + (fmt.Sprintf("%d", int64(g_5)) + ",")) + ("b=" + (fmt.Sprintf("%d", int64(b_6)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "setColor",
		Params: params_7,
	})
}
func (state *ThingBreakoutGameGo) resetBall() {
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgfunction_called{
		Inst: state.DEBUG_ID,
		Fn_name: "resetBall",
		Ty: "void_",
		Returns: "",
		Params: "",
	})
	var old_bx_16 string = "" + fmt.Sprintf("%d", int64(state.bx))
	state.bx = state.padx - state.br / state.SCALE
	var new_bx_16 string = "" + fmt.Sprintf("%d", int64(state.bx))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
		Inst: state.DEBUG_ID,
		Prop_name: "bx",
		Ty: "Int16",
		Old_value: old_bx_16,
		New_value: new_bx_16,
	})
	var old_by_0 string = "" + fmt.Sprintf("%d", int64(state.by))
	state.by = state.pady - state.br / state.SCALE
	var new_by_0 string = "" + fmt.Sprintf("%d", int64(state.by))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
		Inst: state.DEBUG_ID,
		Prop_name: "by",
		Ty: "Int16",
		Old_value: old_by_0,
		New_value: new_by_0,
	})
	var old_dx_8 string = "" + fmt.Sprintf("%d", int64(state.dx))
	state.dx = (state.padx + state.prevBX + state.prevBY) % 300 - 150
	var new_dx_8 string = "" + fmt.Sprintf("%d", int64(state.dx))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
		Inst: state.DEBUG_ID,
		Prop_name: "dx",
		Ty: "Int16",
		Old_value: old_dx_8,
		New_value: new_dx_8,
	})
	if state.dy > 0 {
		var old_dy_24 string = "" + fmt.Sprintf("%d", int64(state.dy))
		state.dy =  -(state.dy)
		var new_dy_24 string = "" + fmt.Sprintf("%d", int64(state.dy))
		state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
			Inst: state.DEBUG_ID,
			Prop_name: "dy",
			Ty: "Int16",
			Old_value: old_dy_24,
			New_value: new_dy_24,
		})
	}
	var old_prevBX_21 string = "" + fmt.Sprintf("%d", int64(state.prevBX))
	state.prevBX =  -(1)
	var new_prevBX_21 string = "" + fmt.Sprintf("%d", int64(state.prevBX))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
		Inst: state.DEBUG_ID,
		Prop_name: "prevBX",
		Ty: "Int16",
		Old_value: old_prevBX_21,
		New_value: new_prevBX_21,
	})
	var old_prevBY_13 string = "" + fmt.Sprintf("%d", int64(state.prevBY))
	state.prevBY =  -(1)
	var new_prevBY_13 string = "" + fmt.Sprintf("%d", int64(state.prevBY))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
		Inst: state.DEBUG_ID,
		Prop_name: "prevBY",
		Ty: "Int16",
		Old_value: old_prevBY_13,
		New_value: new_prevBY_13,
	})
}
func (state *ThingBreakoutGameGo) eraseBall() {
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgfunction_called{
		Inst: state.DEBUG_ID,
		Fn_name: "eraseBall",
		Ty: "void_",
		Returns: "",
		Params: "",
	})
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
		var params_11 string = "" + ("r=" + (fmt.Sprintf("%d", int64(r_8)) + ",")) + ("g=" + (fmt.Sprintf("%d", int64(g_9)) + ",")) + ("b=" + (fmt.Sprintf("%d", int64(b_10)) + ","))
		state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
			Inst: state.DEBUG_ID,
			Port_name: "display",
			Msg_name: "setColor",
			Params: params_11,
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
		var params_16 string = "" + ("x=" + (fmt.Sprintf("%d", int64(x_12)) + ",")) + ("y=" + (fmt.Sprintf("%d", int64(y_13)) + ",")) + ("width=" + (fmt.Sprintf("%d", int64(width_14)) + ",")) + ("height=" + (fmt.Sprintf("%d", int64(height_15)) + ","))
		state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
			Inst: state.DEBUG_ID,
			Port_name: "display",
			Msg_name: "fillRect",
			Params: params_16,
		})
	}
	var old_prevBX_22 string = "" + fmt.Sprintf("%d", int64(state.prevBX))
	state.prevBX =  -(1)
	var new_prevBX_22 string = "" + fmt.Sprintf("%d", int64(state.prevBX))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
		Inst: state.DEBUG_ID,
		Prop_name: "prevBX",
		Ty: "Int16",
		Old_value: old_prevBX_22,
		New_value: new_prevBX_22,
	})
	var old_prevBY_14 string = "" + fmt.Sprintf("%d", int64(state.prevBY))
	state.prevBY =  -(1)
	var new_prevBY_14 string = "" + fmt.Sprintf("%d", int64(state.prevBY))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
		Inst: state.DEBUG_ID,
		Prop_name: "prevBY",
		Ty: "Int16",
		Old_value: old_prevBY_14,
		New_value: new_prevBY_14,
	})
}
func (state *ThingBreakoutGameGo) drawBall() {
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgfunction_called{
		Inst: state.DEBUG_ID,
		Fn_name: "drawBall",
		Ty: "void_",
		Returns: "",
		Params: "",
	})
	var bs int16 = (state.br * 2) / state.SCALE
	state.eraseBall()
	var old_prevBX_23 string = "" + fmt.Sprintf("%d", int64(state.prevBX))
	state.prevBX = (state.bx - state.br) / state.SCALE
	var new_prevBX_23 string = "" + fmt.Sprintf("%d", int64(state.prevBX))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
		Inst: state.DEBUG_ID,
		Prop_name: "prevBX",
		Ty: "Int16",
		Old_value: old_prevBX_23,
		New_value: new_prevBX_23,
	})
	var old_prevBY_15 string = "" + fmt.Sprintf("%d", int64(state.prevBY))
	state.prevBY = (state.by - state.br) / state.SCALE
	var new_prevBY_15 string = "" + fmt.Sprintf("%d", int64(state.prevBY))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
		Inst: state.DEBUG_ID,
		Prop_name: "prevBY",
		Ty: "Int16",
		Old_value: old_prevBY_15,
		New_value: new_prevBY_15,
	})
	var r_17 uint8 = 183
	var g_18 uint8 = 199
	var b_19 uint8 = 111
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_17,
		G: g_18,
		B: b_19,
	})
	var params_20 string = "" + ("r=" + (fmt.Sprintf("%d", int64(r_17)) + ",")) + ("g=" + (fmt.Sprintf("%d", int64(g_18)) + ",")) + ("b=" + (fmt.Sprintf("%d", int64(b_19)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "setColor",
		Params: params_20,
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
	var params_25 string = "" + ("x=" + (fmt.Sprintf("%d", int64(x_21)) + ",")) + ("y=" + (fmt.Sprintf("%d", int64(y_22)) + ",")) + ("width=" + (fmt.Sprintf("%d", int64(width_23)) + ",")) + ("height=" + (fmt.Sprintf("%d", int64(height_24)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "fillRect",
		Params: params_25,
	})
}
func (state *ThingBreakoutGameGo) erasePad() {
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgfunction_called{
		Inst: state.DEBUG_ID,
		Fn_name: "erasePad",
		Ty: "void_",
		Returns: "",
		Params: "",
	})
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
		var params_29 string = "" + ("r=" + (fmt.Sprintf("%d", int64(r_26)) + ",")) + ("g=" + (fmt.Sprintf("%d", int64(g_27)) + ",")) + ("b=" + (fmt.Sprintf("%d", int64(b_28)) + ","))
		state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
			Inst: state.DEBUG_ID,
			Port_name: "display",
			Msg_name: "setColor",
			Params: params_29,
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
		var params_34 string = "" + ("x=" + (fmt.Sprintf("%d", int64(x_30)) + ",")) + ("y=" + (fmt.Sprintf("%d", int64(y_31)) + ",")) + ("width=" + (fmt.Sprintf("%d", int64(width_32)) + ",")) + ("height=" + (fmt.Sprintf("%d", int64(height_33)) + ","))
		state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
			Inst: state.DEBUG_ID,
			Port_name: "display",
			Msg_name: "fillRect",
			Params: params_34,
		})
	}
}
func (state *ThingBreakoutGameGo) drawPad() {
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgfunction_called{
		Inst: state.DEBUG_ID,
		Fn_name: "drawPad",
		Ty: "void_",
		Returns: "",
		Params: "",
	})
	var ps int16 = state.padlen / state.SCALE
	state.erasePad()
	var old_prevPX_29 string = "" + fmt.Sprintf("%d", int64(state.prevPX))
	state.prevPX = (state.padx - (state.padlen / 2)) / state.SCALE
	var new_prevPX_29 string = "" + fmt.Sprintf("%d", int64(state.prevPX))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
		Inst: state.DEBUG_ID,
		Prop_name: "prevPX",
		Ty: "Int16",
		Old_value: old_prevPX_29,
		New_value: new_prevPX_29,
	})
	var old_prevPY_12 string = "" + fmt.Sprintf("%d", int64(state.prevPY))
	state.prevPY = state.pady / state.SCALE
	var new_prevPY_12 string = "" + fmt.Sprintf("%d", int64(state.prevPY))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
		Inst: state.DEBUG_ID,
		Prop_name: "prevPY",
		Ty: "Int16",
		Old_value: old_prevPY_12,
		New_value: new_prevPY_12,
	})
	var r_35 uint8 = state.fgcolor[0]
	var g_36 uint8 = state.fgcolor[1]
	var b_37 uint8 = state.fgcolor[2]
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_35,
		G: g_36,
		B: b_37,
	})
	var params_38 string = "" + ("r=" + (fmt.Sprintf("%d", int64(r_35)) + ",")) + ("g=" + (fmt.Sprintf("%d", int64(g_36)) + ",")) + ("b=" + (fmt.Sprintf("%d", int64(b_37)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "setColor",
		Params: params_38,
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
	var params_43 string = "" + ("x=" + (fmt.Sprintf("%d", int64(x_39)) + ",")) + ("y=" + (fmt.Sprintf("%d", int64(y_40)) + ",")) + ("width=" + (fmt.Sprintf("%d", int64(width_41)) + ",")) + ("height=" + (fmt.Sprintf("%d", int64(height_42)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "fillRect",
		Params: params_43,
	})
}
func (state *ThingBreakoutGameGo) drawCountDown(c int16) {
	var params string = "" + ("c=" + (fmt.Sprintf("%d", int64(c)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgfunction_called{
		Inst: state.DEBUG_ID,
		Fn_name: "drawCountDown",
		Ty: "void_",
		Returns: "",
		Params: params,
	})
	var r_44 uint8 = state.fgcolor[0]
	var g_45 uint8 = state.fgcolor[1]
	var b_46 uint8 = state.fgcolor[2]
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_44,
		G: g_45,
		B: b_46,
	})
	var params_47 string = "" + ("r=" + (fmt.Sprintf("%d", int64(r_44)) + ",")) + ("g=" + (fmt.Sprintf("%d", int64(g_45)) + ",")) + ("b=" + (fmt.Sprintf("%d", int64(b_46)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "setColor",
		Params: params_47,
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
		var params_51 string = "" + ("r=" + (fmt.Sprintf("%d", int64(r_48)) + ",")) + ("g=" + (fmt.Sprintf("%d", int64(g_49)) + ",")) + ("b=" + (fmt.Sprintf("%d", int64(b_50)) + ","))
		state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
			Inst: state.DEBUG_ID,
			Port_name: "display",
			Msg_name: "setColor",
			Params: params_51,
		})
		var r_52 uint8 = state.bgcolor[0]
		var g_53 uint8 = state.bgcolor[1]
		var b_54 uint8 = state.bgcolor[2]
		state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetBGColor{
			R: r_52,
			G: g_53,
			B: b_54,
		})
		var params_55 string = "" + ("r=" + (fmt.Sprintf("%d", int64(r_52)) + ",")) + ("g=" + (fmt.Sprintf("%d", int64(g_53)) + ",")) + ("b=" + (fmt.Sprintf("%d", int64(b_54)) + ","))
		state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
			Inst: state.DEBUG_ID,
			Port_name: "display",
			Msg_name: "setBGColor",
			Params: params_55,
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
		var params_61 string = "" + ("x=" + (fmt.Sprintf("%d", int64(x_56)) + ",")) + ("y=" + (fmt.Sprintf("%d", int64(y_57)) + ",")) + ("v=" + (fmt.Sprintf("%d", int64(v_58)) + ",")) + ("digits=" + (fmt.Sprintf("%d", int64(digits_59)) + ",")) + ("scale=" + (fmt.Sprintf("%d", int64(scale_60)) + ","))
		state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
			Inst: state.DEBUG_ID,
			Port_name: "display",
			Msg_name: "drawInteger",
			Params: params_61,
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
		var params_65 string = "" + ("r=" + (fmt.Sprintf("%d", int64(r_62)) + ",")) + ("g=" + (fmt.Sprintf("%d", int64(g_63)) + ",")) + ("b=" + (fmt.Sprintf("%d", int64(b_64)) + ","))
		state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
			Inst: state.DEBUG_ID,
			Port_name: "display",
			Msg_name: "setColor",
			Params: params_65,
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
		var params_70 string = "" + ("x=" + (fmt.Sprintf("%d", int64(x_66)) + ",")) + ("y=" + (fmt.Sprintf("%d", int64(y_67)) + ",")) + ("width=" + (fmt.Sprintf("%d", int64(width_68)) + ",")) + ("height=" + (fmt.Sprintf("%d", int64(height_69)) + ","))
		state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
			Inst: state.DEBUG_ID,
			Port_name: "display",
			Msg_name: "fillRect",
			Params: params_70,
		})
	}
}
func (state *ThingBreakoutGameGo) drawWalls() {
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgfunction_called{
		Inst: state.DEBUG_ID,
		Fn_name: "drawWalls",
		Ty: "void_",
		Returns: "",
		Params: "",
	})
	var r_71 uint8 = state.fgcolor[0]
	var g_72 uint8 = state.fgcolor[1]
	var b_73 uint8 = state.fgcolor[2]
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_71,
		G: g_72,
		B: b_73,
	})
	var params_74 string = "" + ("r=" + (fmt.Sprintf("%d", int64(r_71)) + ",")) + ("g=" + (fmt.Sprintf("%d", int64(g_72)) + ",")) + ("b=" + (fmt.Sprintf("%d", int64(b_73)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "setColor",
		Params: params_74,
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
	var params_79 string = "" + ("x=" + (fmt.Sprintf("%d", int64(x_75)) + ",")) + ("y=" + (fmt.Sprintf("%d", int64(y_76)) + ",")) + ("width=" + (fmt.Sprintf("%d", int64(width_77)) + ",")) + ("height=" + (fmt.Sprintf("%d", int64(height_78)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "fillRect",
		Params: params_79,
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
	var params_84 string = "" + ("x=" + (fmt.Sprintf("%d", int64(x_80)) + ",")) + ("y=" + (fmt.Sprintf("%d", int64(y_81)) + ",")) + ("width=" + (fmt.Sprintf("%d", int64(width_82)) + ",")) + ("height=" + (fmt.Sprintf("%d", int64(height_83)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "fillRect",
		Params: params_84,
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
	var params_89 string = "" + ("x=" + (fmt.Sprintf("%d", int64(x_85)) + ",")) + ("y=" + (fmt.Sprintf("%d", int64(y_86)) + ",")) + ("width=" + (fmt.Sprintf("%d", int64(width_87)) + ",")) + ("height=" + (fmt.Sprintf("%d", int64(height_88)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "fillRect",
		Params: params_89,
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
	var params_94 string = "" + ("x=" + (fmt.Sprintf("%d", int64(x_90)) + ",")) + ("y=" + (fmt.Sprintf("%d", int64(y_91)) + ",")) + ("width=" + (fmt.Sprintf("%d", int64(width_92)) + ",")) + ("height=" + (fmt.Sprintf("%d", int64(height_93)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "fillRect",
		Params: params_94,
	})
}
func (state *ThingBreakoutGameGo) bitIsSet(variable uint8, bit uint8)  bool {
	var return_0 bool = bool((((1 << bit) & variable) != 0))
	var return_as_string0 string = "" + (fmt.Sprintf("%t", return_0))
	var params string = "" + ("variable=" + (fmt.Sprintf("%d", int64(variable)) + ",")) + ("bit=" + (fmt.Sprintf("%d", int64(bit)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgfunction_called{
		Inst: state.DEBUG_ID,
		Fn_name: "bitIsSet",
		Ty: "Boolean",
		Returns: return_as_string0,
		Params: params,
	})
	return return_0
}
func (state *ThingBreakoutGameGo) createBricks() {
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgfunction_called{
		Inst: state.DEBUG_ID,
		Fn_name: "createBricks",
		Ty: "void_",
		Returns: "",
		Params: "",
	})
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
	var return_3 uint8 = result
	var return_as_string3 string = "" + (fmt.Sprintf("%d", int64(return_3)))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgfunction_called{
		Inst: state.DEBUG_ID,
		Fn_name: "bricksLeft",
		Ty: "UInt8",
		Returns: return_as_string3,
		Params: "",
	})
	return return_3
}
func (state *ThingBreakoutGameGo) drawBrick(x uint8, y uint8) {
	var params string = "" + ("x=" + (fmt.Sprintf("%d", int64(x)) + ",")) + ("y=" + (fmt.Sprintf("%d", int64(y)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgfunction_called{
		Inst: state.DEBUG_ID,
		Fn_name: "drawBrick",
		Ty: "void_",
		Returns: "",
		Params: params,
	})
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
	var params_98 string = "" + ("r=" + (fmt.Sprintf("%d", int64(r_95)) + ",")) + ("g=" + (fmt.Sprintf("%d", int64(g_96)) + ",")) + ("b=" + (fmt.Sprintf("%d", int64(b_97)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "setColor",
		Params: params_98,
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
	var params_103 string = "" + ("x=" + (fmt.Sprintf("%d", int64(x_99)) + ",")) + ("y=" + (fmt.Sprintf("%d", int64(y_100)) + ",")) + ("width=" + (fmt.Sprintf("%d", int64(width_101)) + ",")) + ("height=" + (fmt.Sprintf("%d", int64(height_102)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "fillRect",
		Params: params_103,
	})
	var r_104 uint8 = 100
	var g_105 uint8 = 56
	var b_106 uint8 = 43
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_104,
		G: g_105,
		B: b_106,
	})
	var params_107 string = "" + ("r=" + (fmt.Sprintf("%d", int64(r_104)) + ",")) + ("g=" + (fmt.Sprintf("%d", int64(g_105)) + ",")) + ("b=" + (fmt.Sprintf("%d", int64(b_106)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "setColor",
		Params: params_107,
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
	var params_112 string = "" + ("x=" + (fmt.Sprintf("%d", int64(x_108)) + ",")) + ("y=" + (fmt.Sprintf("%d", int64(y_109)) + ",")) + ("width=" + (fmt.Sprintf("%d", int64(width_110)) + ",")) + ("height=" + (fmt.Sprintf("%d", int64(height_111)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "drawRect",
		Params: params_112,
	})
}
func (state *ThingBreakoutGameGo) removeBrick(x uint8, y uint8) {
	var params string = "" + ("x=" + (fmt.Sprintf("%d", int64(x)) + ",")) + ("y=" + (fmt.Sprintf("%d", int64(y)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgfunction_called{
		Inst: state.DEBUG_ID,
		Fn_name: "removeBrick",
		Ty: "void_",
		Returns: "",
		Params: params,
	})
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
	var params_116 string = "" + ("r=" + (fmt.Sprintf("%d", int64(r_113)) + ",")) + ("g=" + (fmt.Sprintf("%d", int64(g_114)) + ",")) + ("b=" + (fmt.Sprintf("%d", int64(b_115)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "setColor",
		Params: params_116,
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
	var params_121 string = "" + ("x=" + (fmt.Sprintf("%d", int64(x_117)) + ",")) + ("y=" + (fmt.Sprintf("%d", int64(y_118)) + ",")) + ("width=" + (fmt.Sprintf("%d", int64(width_119)) + ",")) + ("height=" + (fmt.Sprintf("%d", int64(height_120)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "fillRect",
		Params: params_121,
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
	var return_3 bool = result
	var return_as_string3 string = "" + (fmt.Sprintf("%t", return_3))
	var params string = "" + ("xpos=" + (fmt.Sprintf("%d", int64(xpos)) + ",")) + ("ypos=" + (fmt.Sprintf("%d", int64(ypos)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgfunction_called{
		Inst: state.DEBUG_ID,
		Fn_name: "collideBrick",
		Ty: "Boolean",
		Returns: return_as_string3,
		Params: params,
	})
	return return_3
}
func (state *ThingBreakoutGameGo) drawLevel() {
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgfunction_called{
		Inst: state.DEBUG_ID,
		Fn_name: "drawLevel",
		Ty: "void_",
		Returns: "",
		Params: "",
	})
	var r_122 uint8 = 158
	var g_123 uint8 = 209
	var b_124 uint8 = 130
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_122,
		G: g_123,
		B: b_124,
	})
	var params_125 string = "" + ("r=" + (fmt.Sprintf("%d", int64(r_122)) + ",")) + ("g=" + (fmt.Sprintf("%d", int64(g_123)) + ",")) + ("b=" + (fmt.Sprintf("%d", int64(b_124)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "setColor",
		Params: params_125,
	})
	var r_126 uint8 = state.fgcolor[0]
	var g_127 uint8 = state.fgcolor[1]
	var b_128 uint8 = state.fgcolor[2]
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetBGColor{
		R: r_126,
		G: g_127,
		B: b_128,
	})
	var params_129 string = "" + ("r=" + (fmt.Sprintf("%d", int64(r_126)) + ",")) + ("g=" + (fmt.Sprintf("%d", int64(g_127)) + ",")) + ("b=" + (fmt.Sprintf("%d", int64(b_128)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "setBGColor",
		Params: params_129,
	})
	var r_130 uint8 = state.bgcolor[0]
	var g_131 uint8 = state.bgcolor[1]
	var b_132 uint8 = state.bgcolor[2]
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_130,
		G: g_131,
		B: b_132,
	})
	var params_133 string = "" + ("r=" + (fmt.Sprintf("%d", int64(r_130)) + ",")) + ("g=" + (fmt.Sprintf("%d", int64(g_131)) + ",")) + ("b=" + (fmt.Sprintf("%d", int64(b_132)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "setColor",
		Params: params_133,
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
	var params_139 string = "" + ("x=" + (fmt.Sprintf("%d", int64(x_134)) + ",")) + ("y=" + (fmt.Sprintf("%d", int64(y_135)) + ",")) + ("v=" + (fmt.Sprintf("%d", int64(v_136)) + ",")) + ("digits=" + (fmt.Sprintf("%d", int64(digits_137)) + ",")) + ("scale=" + (fmt.Sprintf("%d", int64(scale_138)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "drawInteger",
		Params: params_139,
	})
}
func (state *ThingBreakoutGameGo) incrementScore(diff int8) {
	var params string = "" + ("diff=" + (fmt.Sprintf("%d", int64(diff)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgfunction_called{
		Inst: state.DEBUG_ID,
		Fn_name: "incrementScore",
		Ty: "void_",
		Returns: "",
		Params: params,
	})
	var old_score_31 string = "" + fmt.Sprintf("%d", int64(state.score))
	state.score = state.score + int16(diff)
	var new_score_31 string = "" + fmt.Sprintf("%d", int64(state.score))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
		Inst: state.DEBUG_ID,
		Prop_name: "score",
		Ty: "Int16",
		Old_value: old_score_31,
		New_value: new_score_31,
	})
	if state.score < 0 {
		var old_score_32 string = "" + fmt.Sprintf("%d", int64(state.score))
		state.score = 0
		var new_score_32 string = "" + fmt.Sprintf("%d", int64(state.score))
		state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
			Inst: state.DEBUG_ID,
			Prop_name: "score",
			Ty: "Int16",
			Old_value: old_score_32,
			New_value: new_score_32,
		})
	}
	state.drawScore()
}
func (state *ThingBreakoutGameGo) drawScore() {
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgfunction_called{
		Inst: state.DEBUG_ID,
		Fn_name: "drawScore",
		Ty: "void_",
		Returns: "",
		Params: "",
	})
	var r_140 uint8 = 158
	var g_141 uint8 = 209
	var b_142 uint8 = 130
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_140,
		G: g_141,
		B: b_142,
	})
	var params_143 string = "" + ("r=" + (fmt.Sprintf("%d", int64(r_140)) + ",")) + ("g=" + (fmt.Sprintf("%d", int64(g_141)) + ",")) + ("b=" + (fmt.Sprintf("%d", int64(b_142)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "setColor",
		Params: params_143,
	})
	var r_144 uint8 = state.fgcolor[0]
	var g_145 uint8 = state.fgcolor[1]
	var b_146 uint8 = state.fgcolor[2]
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetBGColor{
		R: r_144,
		G: g_145,
		B: b_146,
	})
	var params_147 string = "" + ("r=" + (fmt.Sprintf("%d", int64(r_144)) + ",")) + ("g=" + (fmt.Sprintf("%d", int64(g_145)) + ",")) + ("b=" + (fmt.Sprintf("%d", int64(b_146)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "setBGColor",
		Params: params_147,
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
	var params_153 string = "" + ("x=" + (fmt.Sprintf("%d", int64(x_148)) + ",")) + ("y=" + (fmt.Sprintf("%d", int64(y_149)) + ",")) + ("v=" + (fmt.Sprintf("%d", int64(v_150)) + ",")) + ("digits=" + (fmt.Sprintf("%d", int64(digits_151)) + ",")) + ("scale=" + (fmt.Sprintf("%d", int64(scale_152)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "drawInteger",
		Params: params_153,
	})
}
func (state *ThingBreakoutGameGo) drawLives() {
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgfunction_called{
		Inst: state.DEBUG_ID,
		Fn_name: "drawLives",
		Ty: "void_",
		Returns: "",
		Params: "",
	})
	var r_154 uint8 = state.fgcolor[0]
	var g_155 uint8 = state.fgcolor[1]
	var b_156 uint8 = state.fgcolor[2]
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_154,
		G: g_155,
		B: b_156,
	})
	var params_157 string = "" + ("r=" + (fmt.Sprintf("%d", int64(r_154)) + ",")) + ("g=" + (fmt.Sprintf("%d", int64(g_155)) + ",")) + ("b=" + (fmt.Sprintf("%d", int64(b_156)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "setColor",
		Params: params_157,
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
	var params_162 string = "" + ("x=" + (fmt.Sprintf("%d", int64(x_158)) + ",")) + ("y=" + (fmt.Sprintf("%d", int64(y_159)) + ",")) + ("width=" + (fmt.Sprintf("%d", int64(width_160)) + ",")) + ("height=" + (fmt.Sprintf("%d", int64(height_161)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "fillRect",
		Params: params_162,
	})
	var r_163 uint8 = 183
	var g_164 uint8 = 199
	var b_165 uint8 = 111
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_163,
		G: g_164,
		B: b_165,
	})
	var params_166 string = "" + ("r=" + (fmt.Sprintf("%d", int64(r_163)) + ",")) + ("g=" + (fmt.Sprintf("%d", int64(g_164)) + ",")) + ("b=" + (fmt.Sprintf("%d", int64(b_165)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "setColor",
		Params: params_166,
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
		var params_171 string = "" + ("x=" + (fmt.Sprintf("%d", int64(x_167)) + ",")) + ("y=" + (fmt.Sprintf("%d", int64(y_168)) + ",")) + ("width=" + (fmt.Sprintf("%d", int64(width_169)) + ",")) + ("height=" + (fmt.Sprintf("%d", int64(height_170)) + ","))
		state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
			Inst: state.DEBUG_ID,
			Port_name: "display",
			Msg_name: "fillRect",
			Params: params_171,
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
				var params string = "" + ("x=" + (fmt.Sprintf("%d", int64(e.X)) + ",")) + ("y=" + (fmt.Sprintf("%d", int64(e.Y)) + ","))
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_handled{
					Inst: state.DEBUG_ID,
					Source: "SC",
					Target: "_",
					Port_name: "controller",
					Msg_name: "position",
					Params: params,
				})
				var center int32 = (int32(state.RIGHT) - int32(state.LEFT) - int32(state.padlen))
				center = int32(e.X) * center
				center = center / 200
				var old_padx_30 string = "" + fmt.Sprintf("%d", int64(state.padx))
				state.padx = int16((int32(state.LEFT) + center + (int32(state.RIGHT) - int32(state.LEFT)) / 2))
				var new_padx_30 string = "" + fmt.Sprintf("%d", int64(state.padx))
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
					Inst: state.DEBUG_ID,
					Prop_name: "padx",
					Ty: "Int16",
					Old_value: old_padx_30,
					New_value: new_padx_30,
				})
			}
		}
	case FragmentTimerMsgsMsgtimer_timeout:
		if e := typedMessage; port == BreakoutGameGo_BreakoutGame_clock && (true) {
			return true, true, state, func() {
				var params string = "" + ("id=" + (fmt.Sprintf("%d", int64(e.Id)) + ","))
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_lost{
					Inst: state.DEBUG_ID,
					Port_name: "clock",
					Msg_name: "timer_timeout",
					Params: params,
				})
			}
		}
	case FragmentDisplayMsgsMsgdisplayReady:
		if port == BreakoutGameGo_BreakoutGame_display && (true) {
			return true, true, state, func() {
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_lost{
					Inst: state.DEBUG_ID,
					Port_name: "display",
					Msg_name: "displayReady",
					Params: "",
				})
			}
		}
	case FragmentBreakoutGameMsglostBall:
		if port == BreakoutGameGo_BreakoutGame_game && (true) {
			return true, true, state, func() {
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_lost{
					Inst: state.DEBUG_ID,
					Port_name: "game",
					Msg_name: "lostBall",
					Params: "",
				})
			}
		}
		if port == BreakoutGameGo_BreakoutGame_pro_game && (true) {
			return true, true, state, func() {
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_lost{
					Inst: state.DEBUG_ID,
					Port_name: "pro_game",
					Msg_name: "lostBall",
					Params: "",
				})
			}
		}
	case FragmentBreakoutGameMsgnextLevel:
		if port == BreakoutGameGo_BreakoutGame_game && (true) {
			return true, true, state, func() {
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_lost{
					Inst: state.DEBUG_ID,
					Port_name: "game",
					Msg_name: "nextLevel",
					Params: "",
				})
			}
		}
		if port == BreakoutGameGo_BreakoutGame_pro_game && (true) {
			return true, true, state, func() {
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_lost{
					Inst: state.DEBUG_ID,
					Port_name: "pro_game",
					Msg_name: "nextLevel",
					Params: "",
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
	var params_174 string = "" + ("xsize=" + (fmt.Sprintf("%d", int64(xsize_172)) + ",")) + ("ysize=" + (fmt.Sprintf("%d", int64(ysize_173)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "create",
		Params: params_174,
	})
}
func (state *FragmentBreakoutGameStateChartSCStateINIT) Handle(port gosm.Port, message interface{}) (handled bool, internal bool, next gosm.State, action func()) {
	switch message.(type) {
	case FragmentDisplayMsgsMsgdisplayReady:
		if port == BreakoutGameGo_BreakoutGame_display {
			return true, false, state.FragmentBreakoutGameStateChartSCStateLAUNCH, func() {
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_handled{
					Inst: state.DEBUG_ID,
					Source: "SC.INIT",
					Target: "SC.LAUNCH",
					Port_name: "display",
					Msg_name: "displayReady",
					Params: "_",
				})
				state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgclear{})
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
					Inst: state.DEBUG_ID,
					Port_name: "display",
					Msg_name: "clear",
					Params: "",
				})
				state.initColors()
				var r_175 uint8 = state.bgcolor[0]
				var g_176 uint8 = state.bgcolor[1]
				var b_177 uint8 = state.bgcolor[2]
				state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
					R: r_175,
					G: g_176,
					B: b_177,
				})
				var params_178 string = "" + ("r=" + (fmt.Sprintf("%d", int64(r_175)) + ",")) + ("g=" + (fmt.Sprintf("%d", int64(g_176)) + ",")) + ("b=" + (fmt.Sprintf("%d", int64(b_177)) + ","))
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
					Inst: state.DEBUG_ID,
					Port_name: "display",
					Msg_name: "setColor",
					Params: params_178,
				})
				var x_179 uint8 = 0
				var y_180 uint8 = 0
				var width_181 uint8 = state.XDISPSIZE
				var height_182 uint8 = state.YDISPSIZE
				state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
					X: x_179,
					Y: y_180,
					Width: width_181,
					Height: height_182,
				})
				var params_183 string = "" + ("x=" + (fmt.Sprintf("%d", int64(x_179)) + ",")) + ("y=" + (fmt.Sprintf("%d", int64(y_180)) + ",")) + ("width=" + (fmt.Sprintf("%d", int64(width_181)) + ",")) + ("height=" + (fmt.Sprintf("%d", int64(height_182)) + ","))
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
					Inst: state.DEBUG_ID,
					Port_name: "display",
					Msg_name: "fillRect",
					Params: params_183,
				})
				var r_184 uint8 = state.fgcolor[0]
				var g_185 uint8 = state.fgcolor[1]
				var b_186 uint8 = state.fgcolor[2]
				state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
					R: r_184,
					G: g_185,
					B: b_186,
				})
				var params_187 string = "" + ("r=" + (fmt.Sprintf("%d", int64(r_184)) + ",")) + ("g=" + (fmt.Sprintf("%d", int64(g_185)) + ",")) + ("b=" + (fmt.Sprintf("%d", int64(b_186)) + ","))
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
					Inst: state.DEBUG_ID,
					Port_name: "display",
					Msg_name: "setColor",
					Params: params_187,
				})
				var x_188 uint8 = 0
				var y_189 uint8 = 0
				var width_190 uint8 = state.XDISPSIZE
				var height_191 uint8 = 14
				state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
					X: x_188,
					Y: y_189,
					Width: width_190,
					Height: height_191,
				})
				var params_192 string = "" + ("x=" + (fmt.Sprintf("%d", int64(x_188)) + ",")) + ("y=" + (fmt.Sprintf("%d", int64(y_189)) + ",")) + ("width=" + (fmt.Sprintf("%d", int64(width_190)) + ",")) + ("height=" + (fmt.Sprintf("%d", int64(height_191)) + ","))
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
					Inst: state.DEBUG_ID,
					Port_name: "display",
					Msg_name: "fillRect",
					Params: params_192,
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
	var id_193 uint8 = 0
	var time_194 uint16 = state.period
	state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_start{
		Id: id_193,
		Time: time_194,
	})
	var params_195 string = "" + ("id=" + (fmt.Sprintf("%d", int64(id_193)) + ",")) + ("time=" + (fmt.Sprintf("%d", int64(time_194)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "clock",
		Msg_name: "timer_start",
		Params: params_195,
	})
	var old_countdown_6 string = "" + fmt.Sprintf("%d", int64(state.countdown))
	state.countdown = 3
	var new_countdown_6 string = "" + fmt.Sprintf("%d", int64(state.countdown))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
		Inst: state.DEBUG_ID,
		Prop_name: "countdown",
		Ty: "UInt8",
		Old_value: old_countdown_6,
		New_value: new_countdown_6,
	})
	state.drawScore()
	state.drawLives()
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgupdate{})
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "update",
		Params: "",
	})
}
func (state *FragmentBreakoutGameStateChartSCStateLAUNCH) Handle(port gosm.Port, message interface{}) (handled bool, internal bool, next gosm.State, action func()) {
	switch typedMessage := message.(type) {
	case FragmentTimerMsgsMsgtimer_timeout:
		if t := typedMessage; port == BreakoutGameGo_BreakoutGame_clock && (t.Id == 0 && state.countdown > 0) {
			return true, true, state, func() {
				var params string = "" + ("id=" + (fmt.Sprintf("%d", int64(t.Id)) + ","))
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_handled{
					Inst: state.DEBUG_ID,
					Source: "SC.LAUNCH",
					Target: "_",
					Port_name: "clock",
					Msg_name: "timer_timeout",
					Params: params,
				})
				var id_196 uint8 = 0
				var time_197 uint16 = state.period
				state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_start{
					Id: id_196,
					Time: time_197,
				})
				var params_198 string = "" + ("id=" + (fmt.Sprintf("%d", int64(id_196)) + ",")) + ("time=" + (fmt.Sprintf("%d", int64(time_197)) + ","))
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
					Inst: state.DEBUG_ID,
					Port_name: "clock",
					Msg_name: "timer_start",
					Params: params_198,
				})
				state.drawPad()
				if (state.countdown % 30) == 0 {
					state.drawCountDown(int16(state.countdown) / 30)
				}
				var old_countdown_7 string = "" + fmt.Sprintf("%d", int64(state.countdown))
				state.countdown = state.countdown - 1
				var new_countdown_7 string = "" + fmt.Sprintf("%d", int64(state.countdown))
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
					Inst: state.DEBUG_ID,
					Prop_name: "countdown",
					Ty: "UInt8",
					Old_value: old_countdown_7,
					New_value: new_countdown_7,
				})
				state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgupdate{})
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
					Inst: state.DEBUG_ID,
					Port_name: "display",
					Msg_name: "update",
					Params: "",
				})
			}
		}
		if t := typedMessage; port == BreakoutGameGo_BreakoutGame_clock && (t.Id == 0 && state.countdown == 0) {
			return true, false, state.FragmentBreakoutGameStateChartSCStatePLAY, func() {
				var params string = "" + ("id=" + (fmt.Sprintf("%d", int64(t.Id)) + ","))
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_handled{
					Inst: state.DEBUG_ID,
					Source: "SC.LAUNCH",
					Target: "SC.PLAY",
					Port_name: "clock",
					Msg_name: "timer_timeout",
					Params: params,
				})
				state.drawCountDown(0)
				state.resetBall()
				state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgupdate{})
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
					Inst: state.DEBUG_ID,
					Port_name: "display",
					Msg_name: "update",
					Params: "",
				})
			}
		}
	}
	return false, false, state, nil
}
func (state *FragmentBreakoutGameStateChartSCStateLAUNCH) OnExit() {}

func (state *FragmentBreakoutGameStateChartSCStatePLAY) OnEntry() {
	var id_199 uint8 = 0
	var time_200 uint16 = state.period
	state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_start{
		Id: id_199,
		Time: time_200,
	})
	var params_201 string = "" + ("id=" + (fmt.Sprintf("%d", int64(id_199)) + ",")) + ("time=" + (fmt.Sprintf("%d", int64(time_200)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "clock",
		Msg_name: "timer_start",
		Params: params_201,
	})
}
func (state *FragmentBreakoutGameStateChartSCStatePLAY) Handle(port gosm.Port, message interface{}) (handled bool, internal bool, next gosm.State, action func()) {
	switch typedMessage := message.(type) {
	case FragmentTimerMsgsMsgtimer_timeout:
		if t := typedMessage; port == BreakoutGameGo_BreakoutGame_clock && (t.Id == 0) {
			return true, true, state, func() {
				var params string = "" + ("id=" + (fmt.Sprintf("%d", int64(t.Id)) + ","))
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_handled{
					Inst: state.DEBUG_ID,
					Source: "SC.PLAY",
					Target: "_",
					Port_name: "clock",
					Msg_name: "timer_timeout",
					Params: params,
				})
				var old_bx_17 string = "" + fmt.Sprintf("%d", int64(state.bx))
				state.bx = state.bx + state.dx
				var new_bx_17 string = "" + fmt.Sprintf("%d", int64(state.bx))
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
					Inst: state.DEBUG_ID,
					Prop_name: "bx",
					Ty: "Int16",
					Old_value: old_bx_17,
					New_value: new_bx_17,
				})
				var old_by_1 string = "" + fmt.Sprintf("%d", int64(state.by))
				state.by = state.by + state.dy
				var new_by_1 string = "" + fmt.Sprintf("%d", int64(state.by))
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
					Inst: state.DEBUG_ID,
					Prop_name: "by",
					Ty: "Int16",
					Old_value: old_by_1,
					New_value: new_by_1,
				})
				var wl int16 = state.LEFT + state.br
				var wr int16 = state.RIGHT - state.br
				var wt int16 = state.TOP + state.br
				var wb int16 = state.BOTTOM - state.br
				if state.bx < wl {
					var old_dx_9 string = "" + fmt.Sprintf("%d", int64(state.dx))
					state.dx =  -(state.dx)
					var new_dx_9 string = "" + fmt.Sprintf("%d", int64(state.dx))
					state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
						Inst: state.DEBUG_ID,
						Prop_name: "dx",
						Ty: "Int16",
						Old_value: old_dx_9,
						New_value: new_dx_9,
					})
					var old_bx_18 string = "" + fmt.Sprintf("%d", int64(state.bx))
					state.bx = 2 * wl - state.bx
					var new_bx_18 string = "" + fmt.Sprintf("%d", int64(state.bx))
					state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
						Inst: state.DEBUG_ID,
						Prop_name: "bx",
						Ty: "Int16",
						Old_value: old_bx_18,
						New_value: new_bx_18,
					})
					state.incrementScore( -(1))
				} else {
					if state.bx > wr {
						var old_dx_10 string = "" + fmt.Sprintf("%d", int64(state.dx))
						state.dx =  -(state.dx)
						var new_dx_10 string = "" + fmt.Sprintf("%d", int64(state.dx))
						state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
							Inst: state.DEBUG_ID,
							Prop_name: "dx",
							Ty: "Int16",
							Old_value: old_dx_10,
							New_value: new_dx_10,
						})
						var old_bx_19 string = "" + fmt.Sprintf("%d", int64(state.bx))
						state.bx = 2 * wr - state.bx
						var new_bx_19 string = "" + fmt.Sprintf("%d", int64(state.bx))
						state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
							Inst: state.DEBUG_ID,
							Prop_name: "bx",
							Ty: "Int16",
							Old_value: old_bx_19,
							New_value: new_bx_19,
						})
						state.incrementScore( -(1))
					}
				}
				if state.by < wt {
					var old_dy_25 string = "" + fmt.Sprintf("%d", int64(state.dy))
					state.dy =  -(state.dy)
					var new_dy_25 string = "" + fmt.Sprintf("%d", int64(state.dy))
					state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
						Inst: state.DEBUG_ID,
						Prop_name: "dy",
						Ty: "Int16",
						Old_value: old_dy_25,
						New_value: new_dy_25,
					})
					var old_by_2 string = "" + fmt.Sprintf("%d", int64(state.by))
					state.by = 2 * wt - state.by
					var new_by_2 string = "" + fmt.Sprintf("%d", int64(state.by))
					state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
						Inst: state.DEBUG_ID,
						Prop_name: "by",
						Ty: "Int16",
						Old_value: old_by_2,
						New_value: new_by_2,
					})
					state.incrementScore( -(1))
				} else {
					if state.by > wb {
						state.Send(BreakoutGameGo_BreakoutGame_game, FragmentBreakoutGameMsglostBall{})
						state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
							Inst: state.DEBUG_ID,
							Port_name: "game",
							Msg_name: "lostBall",
							Params: "",
						})
						state.Send(BreakoutGameGo_BreakoutGame_req_game, FragmentBreakoutGameMsglostBall{})
						state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
							Inst: state.DEBUG_ID,
							Port_name: "req_game",
							Msg_name: "lostBall",
							Params: "",
						})
					}
				}
				if state.dy > 0 {
					if state.by > state.pady - state.br && state.by < state.pady + state.br {
						if state.bx > state.padx - state.padlen / 2 && state.bx < state.padx + state.padlen / 2 {
							var old_dy_26 string = "" + fmt.Sprintf("%d", int64(state.dy))
							state.dy =  -(state.dy)
							var new_dy_26 string = "" + fmt.Sprintf("%d", int64(state.dy))
							state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
								Inst: state.DEBUG_ID,
								Prop_name: "dy",
								Ty: "Int16",
								Old_value: old_dy_26,
								New_value: new_dy_26,
							})
							var old_by_3 string = "" + fmt.Sprintf("%d", int64(state.by))
							state.by = 2 * (state.pady - state.br) - state.by
							var new_by_3 string = "" + fmt.Sprintf("%d", int64(state.by))
							state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
								Inst: state.DEBUG_ID,
								Prop_name: "by",
								Ty: "Int16",
								Old_value: old_by_3,
								New_value: new_by_3,
							})
							var old_dx_11 string = "" + fmt.Sprintf("%d", int64(state.dx))
							state.dx = state.dx / 4 + (state.bx - state.padx) / 4
							var new_dx_11 string = "" + fmt.Sprintf("%d", int64(state.dx))
							state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
								Inst: state.DEBUG_ID,
								Prop_name: "dx",
								Ty: "Int16",
								Old_value: old_dx_11,
								New_value: new_dx_11,
							})
						}
					}
				}
				var collision bool = state.collideBrick(state.bx - state.br, state.by - state.br) || state.collideBrick(state.bx + state.br, state.by - state.br) || state.collideBrick(state.bx + state.br, state.by + state.br) || state.collideBrick(state.bx - state.br, state.by + state.br)
				if collision {
					var old_dy_27 string = "" + fmt.Sprintf("%d", int64(state.dy))
					state.dy =  -(state.dy)
					var new_dy_27 string = "" + fmt.Sprintf("%d", int64(state.dy))
					state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
						Inst: state.DEBUG_ID,
						Prop_name: "dy",
						Ty: "Int16",
						Old_value: old_dy_27,
						New_value: new_dy_27,
					})
					state.incrementScore(10)
					if state.bricksLeft() == 0 {
						state.Send(BreakoutGameGo_BreakoutGame_game, FragmentBreakoutGameMsgnextLevel{})
						state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
							Inst: state.DEBUG_ID,
							Port_name: "game",
							Msg_name: "nextLevel",
							Params: "",
						})
						state.Send(BreakoutGameGo_BreakoutGame_req_game, FragmentBreakoutGameMsgnextLevel{})
						state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
							Inst: state.DEBUG_ID,
							Port_name: "req_game",
							Msg_name: "nextLevel",
							Params: "",
						})
					}
				}
				state.drawBall()
				state.drawPad()
				var ballx_202 int16 = state.bx
				var bally_203 int16 = state.by
				var padx_204 int16 = state.padx
				var pady_205 int16 = state.pady
				state.Send(BreakoutGameGo_BreakoutGame_ia, FragmentIAControllerMsgMsgupdateIA{
					Ballx: ballx_202,
					Bally: bally_203,
					Padx: padx_204,
					Pady: pady_205,
				})
				var params_206 string = "" + ("ballx=" + (fmt.Sprintf("%d", int64(ballx_202)) + ",")) + ("bally=" + (fmt.Sprintf("%d", int64(bally_203)) + ",")) + ("padx=" + (fmt.Sprintf("%d", int64(padx_204)) + ",")) + ("pady=" + (fmt.Sprintf("%d", int64(pady_205)) + ","))
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
					Inst: state.DEBUG_ID,
					Port_name: "ia",
					Msg_name: "updateIA",
					Params: params_206,
				})
				state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgupdate{})
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
					Inst: state.DEBUG_ID,
					Port_name: "display",
					Msg_name: "update",
					Params: "",
				})
				state.log(false)
				var id_207 uint8 = 0
				var time_208 uint16 = state.period
				state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_start{
					Id: id_207,
					Time: time_208,
				})
				var params_209 string = "" + ("id=" + (fmt.Sprintf("%d", int64(id_207)) + ",")) + ("time=" + (fmt.Sprintf("%d", int64(time_208)) + ","))
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
					Inst: state.DEBUG_ID,
					Port_name: "clock",
					Msg_name: "timer_start",
					Params: params_209,
				})
			}
		}
	case FragmentBreakoutGameMsglostBall:
		if port == BreakoutGameGo_BreakoutGame_game {
			return true, false, state.FragmentBreakoutGameStateChartSCStateLOSTBALL, func() {
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_handled{
					Inst: state.DEBUG_ID,
					Source: "SC.PLAY",
					Target: "SC.LOSTBALL",
					Port_name: "game",
					Msg_name: "lostBall",
					Params: "_",
				})
				var id_210 uint8 = 0
				state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_cancel{
					Id: id_210,
				})
				var params_211 string = "" + ("id=" + (fmt.Sprintf("%d", int64(id_210)) + ","))
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
					Inst: state.DEBUG_ID,
					Port_name: "clock",
					Msg_name: "timer_cancel",
					Params: params_211,
				})
			}
		}
		if port == BreakoutGameGo_BreakoutGame_pro_game {
			return true, false, state.FragmentBreakoutGameStateChartSCStateLOSTBALL, func() {
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_handled{
					Inst: state.DEBUG_ID,
					Source: "SC.PLAY",
					Target: "SC.LOSTBALL",
					Port_name: "pro_game",
					Msg_name: "lostBall",
					Params: "_",
				})
				var id_214 uint8 = 0
				state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_cancel{
					Id: id_214,
				})
				var params_215 string = "" + ("id=" + (fmt.Sprintf("%d", int64(id_214)) + ","))
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
					Inst: state.DEBUG_ID,
					Port_name: "clock",
					Msg_name: "timer_cancel",
					Params: params_215,
				})
			}
		}
	case FragmentBreakoutGameMsgnextLevel:
		if port == BreakoutGameGo_BreakoutGame_game {
			return true, false, state.FragmentBreakoutGameStateChartSCStateNEXTLEVEL, func() {
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_handled{
					Inst: state.DEBUG_ID,
					Source: "SC.PLAY",
					Target: "SC.NEXTLEVEL",
					Port_name: "game",
					Msg_name: "nextLevel",
					Params: "_",
				})
				var id_212 uint8 = 0
				state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_cancel{
					Id: id_212,
				})
				var params_213 string = "" + ("id=" + (fmt.Sprintf("%d", int64(id_212)) + ","))
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
					Inst: state.DEBUG_ID,
					Port_name: "clock",
					Msg_name: "timer_cancel",
					Params: params_213,
				})
			}
		}
		if port == BreakoutGameGo_BreakoutGame_pro_game {
			return true, false, state.FragmentBreakoutGameStateChartSCStateNEXTLEVEL, func() {
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_handled{
					Inst: state.DEBUG_ID,
					Source: "SC.PLAY",
					Target: "SC.NEXTLEVEL",
					Port_name: "pro_game",
					Msg_name: "nextLevel",
					Params: "_",
				})
				var id_216 uint8 = 0
				state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_cancel{
					Id: id_216,
				})
				var params_217 string = "" + ("id=" + (fmt.Sprintf("%d", int64(id_216)) + ","))
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
					Inst: state.DEBUG_ID,
					Port_name: "clock",
					Msg_name: "timer_cancel",
					Params: params_217,
				})
			}
		}
	}
	return false, false, state, nil
}
func (state *FragmentBreakoutGameStateChartSCStatePLAY) OnExit() {}

func (state *FragmentBreakoutGameStateChartSCStateLOSTBALL) OnEntry() {
	var id_218 uint8 = 0
	var time_219 uint16 = state.period
	state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_start{
		Id: id_218,
		Time: time_219,
	})
	var params_220 string = "" + ("id=" + (fmt.Sprintf("%d", int64(id_218)) + ",")) + ("time=" + (fmt.Sprintf("%d", int64(time_219)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "clock",
		Msg_name: "timer_start",
		Params: params_220,
	})
	var old_lives_4 string = "" + fmt.Sprintf("%d", int64(state.lives))
	state.lives = state.lives - 1
	var new_lives_4 string = "" + fmt.Sprintf("%d", int64(state.lives))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
		Inst: state.DEBUG_ID,
		Prop_name: "lives",
		Ty: "UInt8",
		Old_value: old_lives_4,
		New_value: new_lives_4,
	})
	state.eraseBall()
	state.erasePad()
	state.drawLives()
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgupdate{})
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "update",
		Params: "",
	})
	state.log(true)
}
func (state *FragmentBreakoutGameStateChartSCStateLOSTBALL) Handle(port gosm.Port, message interface{}) (handled bool, internal bool, next gosm.State, action func()) {
	switch typedMessage := message.(type) {
	case FragmentTimerMsgsMsgtimer_timeout:
		if t := typedMessage; port == BreakoutGameGo_BreakoutGame_clock && (t.Id == 0 && state.lives > 0) {
			return true, false, state.FragmentBreakoutGameStateChartSCStateLAUNCH, func() {
				var params string = "" + ("id=" + (fmt.Sprintf("%d", int64(t.Id)) + ","))
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_handled{
					Inst: state.DEBUG_ID,
					Source: "SC.LOSTBALL",
					Target: "SC.LAUNCH",
					Port_name: "clock",
					Msg_name: "timer_timeout",
					Params: params,
				})
			}
		}
		if t := typedMessage; port == BreakoutGameGo_BreakoutGame_clock && (t.Id == 0 && state.lives == 0) {
			return true, false, state.FragmentBreakoutGameStateChartSCStateGAMEOVER, func() {
				var params string = "" + ("id=" + (fmt.Sprintf("%d", int64(t.Id)) + ","))
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_handled{
					Inst: state.DEBUG_ID,
					Source: "SC.LOSTBALL",
					Target: "SC.GAMEOVER",
					Port_name: "clock",
					Msg_name: "timer_timeout",
					Params: params,
				})
			}
		}
	}
	return false, false, state, nil
}
func (state *FragmentBreakoutGameStateChartSCStateLOSTBALL) OnExit() {}

func (state *FragmentBreakoutGameStateChartSCStateNEXTLEVEL) OnEntry() {
	var id_221 uint8 = 0
	var time_222 uint16 = state.period
	state.Send(BreakoutGameGo_BreakoutGame_clock, FragmentTimerMsgsMsgtimer_start{
		Id: id_221,
		Time: time_222,
	})
	var params_223 string = "" + ("id=" + (fmt.Sprintf("%d", int64(id_221)) + ",")) + ("time=" + (fmt.Sprintf("%d", int64(time_222)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "clock",
		Msg_name: "timer_start",
		Params: params_223,
	})
	var old_level_5 string = "" + fmt.Sprintf("%d", int64(state.level))
	state.level = state.level + 1
	var new_level_5 string = "" + fmt.Sprintf("%d", int64(state.level))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
		Inst: state.DEBUG_ID,
		Prop_name: "level",
		Ty: "UInt8",
		Old_value: old_level_5,
		New_value: new_level_5,
	})
	state.drawLevel()
	state.eraseBall()
	state.erasePad()
	if (state.level % 2) == 0 && state.padlen > 5 * state.SCALE {
		var old_padlen_20 string = "" + fmt.Sprintf("%d", int64(state.padlen))
		state.padlen = state.padlen - (4 * state.SCALE)
		var new_padlen_20 string = "" + fmt.Sprintf("%d", int64(state.padlen))
		state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
			Inst: state.DEBUG_ID,
			Prop_name: "padlen",
			Ty: "Int16",
			Old_value: old_padlen_20,
			New_value: new_padlen_20,
		})
	}
	if (state.level % 2) == 1 {
		var old_dy_28 string = "" + fmt.Sprintf("%d", int64(state.dy))
		state.dy = (state.dy * 3) / 2
		var new_dy_28 string = "" + fmt.Sprintf("%d", int64(state.dy))
		state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgproperty_changed{
			Inst: state.DEBUG_ID,
			Prop_name: "dy",
			Ty: "Int16",
			Old_value: old_dy_28,
			New_value: new_dy_28,
		})
	}
	state.drawLives()
	state.createBricks()
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgupdate{})
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "update",
		Params: "",
	})
}
func (state *FragmentBreakoutGameStateChartSCStateNEXTLEVEL) Handle(port gosm.Port, message interface{}) (handled bool, internal bool, next gosm.State, action func()) {
	switch typedMessage := message.(type) {
	case FragmentTimerMsgsMsgtimer_timeout:
		if t := typedMessage; port == BreakoutGameGo_BreakoutGame_clock && (t.Id == 0) {
			return true, false, state.FragmentBreakoutGameStateChartSCStateLAUNCH, func() {
				var params string = "" + ("id=" + (fmt.Sprintf("%d", int64(t.Id)) + ","))
				state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_handled{
					Inst: state.DEBUG_ID,
					Source: "SC.NEXTLEVEL",
					Target: "SC.LAUNCH",
					Port_name: "clock",
					Msg_name: "timer_timeout",
					Params: params,
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
	var r_224 uint8 = 255
	var g_225 uint8 = 255
	var b_226 uint8 = 255
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_224,
		G: g_225,
		B: b_226,
	})
	var params_227 string = "" + ("r=" + (fmt.Sprintf("%d", int64(r_224)) + ",")) + ("g=" + (fmt.Sprintf("%d", int64(g_225)) + ",")) + ("b=" + (fmt.Sprintf("%d", int64(b_226)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "setColor",
		Params: params_227,
	})
	var x_228 uint8 = 8
	var y_229 uint8 = 30
	var width_230 uint8 = 142
	var height_231 uint8 = 76
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
		X: x_228,
		Y: y_229,
		Width: width_230,
		Height: height_231,
	})
	var params_232 string = "" + ("x=" + (fmt.Sprintf("%d", int64(x_228)) + ",")) + ("y=" + (fmt.Sprintf("%d", int64(y_229)) + ",")) + ("width=" + (fmt.Sprintf("%d", int64(width_230)) + ",")) + ("height=" + (fmt.Sprintf("%d", int64(height_231)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "fillRect",
		Params: params_232,
	})
	var r_233 uint8 = state.fgcolor[0]
	var g_234 uint8 = state.fgcolor[1]
	var b_235 uint8 = state.fgcolor[2]
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_233,
		G: g_234,
		B: b_235,
	})
	var params_236 string = "" + ("r=" + (fmt.Sprintf("%d", int64(r_233)) + ",")) + ("g=" + (fmt.Sprintf("%d", int64(g_234)) + ",")) + ("b=" + (fmt.Sprintf("%d", int64(b_235)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "setColor",
		Params: params_236,
	})
	var x_237 uint8 = 9
	var y_238 uint8 = 31
	var width_239 uint8 = 140
	var height_240 uint8 = 50
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgfillRect{
		X: x_237,
		Y: y_238,
		Width: width_239,
		Height: height_240,
	})
	var params_241 string = "" + ("x=" + (fmt.Sprintf("%d", int64(x_237)) + ",")) + ("y=" + (fmt.Sprintf("%d", int64(y_238)) + ",")) + ("width=" + (fmt.Sprintf("%d", int64(width_239)) + ",")) + ("height=" + (fmt.Sprintf("%d", int64(height_240)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "fillRect",
		Params: params_241,
	})
	var r_242 uint8 = state.fgcolor[0]
	var g_243 uint8 = state.fgcolor[1]
	var b_244 uint8 = state.fgcolor[2]
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetBGColor{
		R: r_242,
		G: g_243,
		B: b_244,
	})
	var params_245 string = "" + ("r=" + (fmt.Sprintf("%d", int64(r_242)) + ",")) + ("g=" + (fmt.Sprintf("%d", int64(g_243)) + ",")) + ("b=" + (fmt.Sprintf("%d", int64(b_244)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "setBGColor",
		Params: params_245,
	})
	var r_246 uint8 = 158
	var g_247 uint8 = 209
	var b_248 uint8 = 130
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgsetColor{
		R: r_246,
		G: g_247,
		B: b_248,
	})
	var params_249 string = "" + ("r=" + (fmt.Sprintf("%d", int64(r_246)) + ",")) + ("g=" + (fmt.Sprintf("%d", int64(g_247)) + ",")) + ("b=" + (fmt.Sprintf("%d", int64(b_248)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "setColor",
		Params: params_249,
	})
	var x_250 uint8 = 23
	var y_251 uint8 = 40
	var v_252 int16 = state.score
	var digits_253 uint8 = 5
	var scale_254 uint8 = 6
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgdrawInteger{
		X: x_250,
		Y: y_251,
		V: v_252,
		Digits: digits_253,
		Scale: scale_254,
	})
	var params_255 string = "" + ("x=" + (fmt.Sprintf("%d", int64(x_250)) + ",")) + ("y=" + (fmt.Sprintf("%d", int64(y_251)) + ",")) + ("v=" + (fmt.Sprintf("%d", int64(v_252)) + ",")) + ("digits=" + (fmt.Sprintf("%d", int64(digits_253)) + ",")) + ("scale=" + (fmt.Sprintf("%d", int64(scale_254)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "drawInteger",
		Params: params_255,
	})
	var x_256 uint8 = 26
	var y_257 uint8 = 87
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgdrawThingML{
		X: x_256,
		Y: y_257,
	})
	var params_258 string = "" + ("x=" + (fmt.Sprintf("%d", int64(x_256)) + ",")) + ("y=" + (fmt.Sprintf("%d", int64(y_257)) + ","))
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "drawThingML",
		Params: params_258,
	})
	state.Send(BreakoutGameGo_BreakoutGame_display, FragmentDisplayMsgsMsgupdate{})
	state.Send(BreakoutGameGo_WithLog_log, FragmentLogMsgsMsgmessage_sent{
		Inst: state.DEBUG_ID,
		Port_name: "display",
		Msg_name: "update",
		Params: "",
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
		DEBUG_ID: original.DEBUG_ID,
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
