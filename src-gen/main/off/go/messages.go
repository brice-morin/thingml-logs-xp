package main

/* -- Messages -- */
type FragmentDisplayMsgsMsgdrawThingML struct {

X uint8

Y uint8

}

type FragmentDisplayMsgsMsgdisplayReady struct {

}

type FragmentTimerMsgsMsgtimer_start struct {

Id uint8

Time uint16

}

type FragmentDisplayMsgsMsgsetColor struct {

R uint8

G uint8

B uint8

}

type FragmentControllerMsgsMsgposition struct {

X int16

Y int16

}

type FragmentLogMsgsMsglog_on struct {

}

type FragmentControllerMsgsMsgvelocity struct {

Dx int16

Dy int16

}

type FragmentTimerMsgsMsgtimer_timeout struct {

Id uint8

}

type FragmentDisplayMsgsMsgcreate struct {

Xsize uint8

Ysize uint8

}

type FragmentDisplayMsgsMsgsetBGColor struct {

R uint8

G uint8

B uint8

}

type FragmentBreakoutGameMsglostBall struct {

}

type FragmentLogMsgsMsglog_off struct {

}

type FragmentTimerMsgsMsgtimer_cancel struct {

Id uint8

}

type FragmentLogMsgsMsgmessage_handled struct {

Inst string

Source string

Target string

Port_name string

Msg_name string

Params string

}

type FragmentBreakoutGameMsgnextLevel struct {

}

type FragmentDisplayMsgsMsgdrawRect struct {

X uint8

Y uint8

Width uint8

Height uint8

}

type FragmentLogMsgsMsgmessage_lost struct {

Inst string

Port_name string

Msg_name string

Params string

}

type FragmentIAControllerMsgMsgupdateIA struct {

Ballx int16

Bally int16

Padx int16

Pady int16

}

type FragmentDisplayMsgsMsgdestroy struct {

}

type FragmentDisplayMsgsMsgclear struct {

}

type FragmentLogMsgsMsgmessage_sent struct {

Inst string

Port_name string

Msg_name string

Params string

}

type FragmentDisplayMsgsMsgdrawInteger struct {

X uint8

Y uint8

V int16

Digits uint8

Scale uint8

}

type FragmentLogMsgsMsgfunction_called struct {

Inst string

Fn_name string

Ty string

Returns string

Params string

}

type FragmentDisplayMsgsMsgupdate struct {

}

type FragmentDisplayMsgsMsgfillRect struct {

X uint8

Y uint8

Width uint8

Height uint8

}

type FragmentLogMsgsMsgproperty_changed struct {

Inst string

Prop_name string

Ty string

Old_value string

New_value string

}


