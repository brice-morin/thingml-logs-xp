package main

import (
	"github.com/SINTEF-9012/gosm"
)

/* -- Ports -- */
const (
	BasicIAController_Controller_controls = 10
	BasicIAController_IAController_game = 11
)

/* -- Component --*/
type ThingBasicIAController struct {
	 *gosm.Component
	ctrlx int16
}

/* -- States -- */
type ThingBasicIAControllerStateChartSC struct {
	 gosm.CompositeState
	 *ThingBasicIAController
}

type ThingBasicIAControllerStateChartSCStateFollowing struct {
	 *ThingBasicIAControllerStateChartSC
}

/* -- Handlers -- */
func (state *ThingBasicIAControllerStateChartSC) OnEntry() {
	state.CompositeState.OnEntry()
}
func (state *ThingBasicIAControllerStateChartSC) Handle(port gosm.Port, message interface{}) (handled bool, internal bool, next gosm.State, action func()) {
	if handled, internal, next, action = state.CompositeState.Handle(port, message); handled {
		return
	}
	return false, false, state, nil
}
func (state *ThingBasicIAControllerStateChartSC) OnExit() {
	state.CompositeState.OnExit()
}

func (state *ThingBasicIAControllerStateChartSCStateFollowing) OnEntry() {
	state.Send(BasicIAController_Controller_controls, FragmentControllerMsgsMsgposition{
		X: state.ctrlx,
		Y: 0,
	})
}
func (state *ThingBasicIAControllerStateChartSCStateFollowing) Handle(port gosm.Port, message interface{}) (handled bool, internal bool, next gosm.State, action func()) {
	switch typedMessage := message.(type) {
	case FragmentIAControllerMsgMsgupdateIA:
		if e := typedMessage; port == BasicIAController_IAController_game {
			return true, false, state, func() {
				if e.Ballx > e.Padx + 400 {
					state.ctrlx = state.ctrlx + 4
				} else {
					if e.Ballx < e.Padx - 400 {
						state.ctrlx = state.ctrlx - 4
					}
				}
				if state.ctrlx <  -(100) {
					state.ctrlx =  -(100)
				} else {
					if state.ctrlx > 100 {
						state.ctrlx = 100
					}
				}
			}
		}
	}
	return false, false, state, nil
}
func (state *ThingBasicIAControllerStateChartSCStateFollowing) OnExit() {}

/* -- Instance Constructor -- */
func NewThingBasicIAController()  *ThingBasicIAController {
	/* Create instance struct */
	instance := &ThingBasicIAController{}
	/* Initialize state structs */
	stateThingBasicIAControllerStateChartSC := &ThingBasicIAControllerStateChartSC{}
	stateThingBasicIAControllerStateChartSCStateFollowing := &ThingBasicIAControllerStateChartSCStateFollowing{}
	/* Initialize regions */
	stateThingBasicIAControllerStateChartSC.CompositeState.Regions = []gosm.Region{
		gosm.Region{ Initial: stateThingBasicIAControllerStateChartSCStateFollowing, KeepsHistory: false},
	}
	/* Set state links */
	stateThingBasicIAControllerStateChartSC.ThingBasicIAController = instance
	stateThingBasicIAControllerStateChartSCStateFollowing.ThingBasicIAControllerStateChartSC = stateThingBasicIAControllerStateChartSC
	/* Make component */
	component := gosm.MakeComponent(100, stateThingBasicIAControllerStateChartSC)
	instance.Component = component
	/* Internal ports */
	return instance
}

func cloneThingBasicIAController(original *ThingBasicIAController)  *ThingBasicIAController {
	clone := &ThingBasicIAController{
		ctrlx: original.ctrlx,
	}
	return clone
}
/* -- Session forks -- */
