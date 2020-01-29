package main

/* -- Messages -- */
type FragmentLogMsgsMsglog_on struct {

}

type FragmentControllerMsgsMsgposition struct {

X int16

Y int16

}

type FragmentLogMsgsMsglog_off struct {

}

type FragmentTimerMsgsMsgtimer_timeout struct {

Id uint8

}

type FragmentBreakoutGameMsglostBall struct {

}

type FragmentIAControllerMsgMsgupdateIA struct {

Ballx int16

Bally int16

Padx int16

Pady int16

}

type FragmentDisplayMsgsMsgdestroy struct {

}

type FragmentControllerMsgsMsgvelocity struct {

Dx int16

Dy int16

}

type FragmentDisplayMsgsMsgsetBGColor struct {

R uint8

G uint8

B uint8

}

type FragmentDisplayMsgsMsgsetColor struct {

R uint8

G uint8

B uint8

}

type FragmentDisplayMsgsMsgfillRect struct {

X uint8

Y uint8

Width uint8

Height uint8

}

type FragmentDisplayMsgsMsgupdate struct {

}

type FragmentLogMsgsMsglog struct {

Payload []byte

Size uint8

}

type FragmentDisplayMsgsMsgdrawRect struct {

X uint8

Y uint8

Width uint8

Height uint8

}

type FragmentDisplayMsgsMsgdisplayReady struct {

}

type FragmentTimerMsgsMsgtimer_start struct {

Id uint8

Time uint16

}

type FragmentDisplayMsgsMsgclear struct {

}

type FragmentTimerMsgsMsgtimer_cancel struct {

Id uint8

}

type FragmentDisplayMsgsMsgdrawInteger struct {

X uint8

Y uint8

V int16

Digits uint8

Scale uint8

}

type FragmentDisplayMsgsMsgdrawThingML struct {

X uint8

Y uint8

}

type FragmentDisplayMsgsMsgcreate struct {

Xsize uint8

Ysize uint8

}

type FragmentBreakoutGameMsgnextLevel struct {

}


