package main

/* -- Messages -- */
type FragmentTimerMsgsMsgtimer_timeout struct {

Id uint8

}

type FragmentDisplayMsgsMsgdrawInteger struct {

X uint8

Y uint8

V int16

Digits uint8

Scale uint8

}

type FragmentBreakoutGameMsgnextLevel struct {

}

type FragmentDisplayMsgsMsgfillRect struct {

X uint8

Y uint8

Width uint8

Height uint8

}

type FragmentDisplayMsgsMsgsetColor struct {

R uint8

G uint8

B uint8

}

type FragmentDisplayMsgsMsgdestroy struct {

}

type FragmentLogMsgsMsglog_off struct {

}

type FragmentDisplayMsgsMsgsetBGColor struct {

R uint8

G uint8

B uint8

}

type FragmentControllerMsgsMsgvelocity struct {

Dx int16

Dy int16

}

type FragmentBreakoutGameMsglostBall struct {

}

type FragmentDisplayMsgsMsgdrawRect struct {

X uint8

Y uint8

Width uint8

Height uint8

}

type FragmentDisplayMsgsMsgcreate struct {

Xsize uint8

Ysize uint8

}

type FragmentDisplayMsgsMsgupdate struct {

}

type FragmentDisplayMsgsMsgdisplayReady struct {

}

type FragmentControllerMsgsMsgposition struct {

X int16

Y int16

}

type FragmentTimerMsgsMsgtimer_cancel struct {

Id uint8

}

type FragmentTimerMsgsMsgtimer_start struct {

Id uint8

Time uint16

}

type FragmentLogMsgsMsglog struct {

Payload []byte

Size uint8

}

type FragmentIAControllerMsgMsgupdateIA struct {

Ballx int16

Bally int16

Padx int16

Pady int16

}

type FragmentDisplayMsgsMsgclear struct {

}

type FragmentDisplayMsgsMsgdrawThingML struct {

X uint8

Y uint8

}

type FragmentLogMsgsMsglog_on struct {

}


