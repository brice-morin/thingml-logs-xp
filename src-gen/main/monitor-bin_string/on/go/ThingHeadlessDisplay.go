package main

import (
	"github.com/SINTEF-9012/gosm"
)

/* -- Ports -- */
const (
	HeadlessDisplay_HeadlessDisplay_display = 8
)

/* -- Component --*/
type ThingHeadlessDisplay struct {
	 *gosm.Component
}

func (state *ThingHeadlessDisplay) mock() {}
/* -- States -- */
type ThingHeadlessDisplayStateChart struct {
	 gosm.CompositeState
	 *ThingHeadlessDisplay
}

type ThingHeadlessDisplayStateChartStateINIT struct {
	 *ThingHeadlessDisplayStateChart
	 *ThingHeadlessDisplayStateChartStateMOCK
}

type ThingHeadlessDisplayStateChartStateMOCK struct {
	 *ThingHeadlessDisplayStateChart
	 *ThingHeadlessDisplayStateChartStateINIT
}

/* -- Handlers -- */
func (state *ThingHeadlessDisplayStateChart) OnEntry() {
	state.CompositeState.OnEntry()
}
func (state *ThingHeadlessDisplayStateChart) Handle(port gosm.Port, message interface{}) (handled bool, internal bool, next gosm.State, action func()) {
	if handled, internal, next, action = state.CompositeState.Handle(port, message); handled {
		return
	}
	return false, false, state, nil
}
func (state *ThingHeadlessDisplayStateChart) OnExit() {
	state.CompositeState.OnExit()
}

func (state *ThingHeadlessDisplayStateChartStateINIT) OnEntry() {
	state.Send(HeadlessDisplay_HeadlessDisplay_display, FragmentDisplayMsgsMsgdisplayReady{})
}
func (state *ThingHeadlessDisplayStateChartStateINIT) Handle(port gosm.Port, message interface{}) (handled bool, internal bool, next gosm.State, action func()) {
	switch message.(type) {
	case nil:
		return true, false, state.ThingHeadlessDisplayStateChartStateMOCK, nil
		
	}
	return false, false, state, nil
}
func (state *ThingHeadlessDisplayStateChartStateINIT) OnExit() {}

func (state *ThingHeadlessDisplayStateChartStateMOCK) OnEntry() {}
func (state *ThingHeadlessDisplayStateChartStateMOCK) Handle(port gosm.Port, message interface{}) (handled bool, internal bool, next gosm.State, action func()) {
	switch message.(type) {
	case FragmentDisplayMsgsMsgcreate:
		if port == HeadlessDisplay_HeadlessDisplay_display {
			return true, true, state, func() {
				state.mock()
			}
		}
	case FragmentDisplayMsgsMsgdestroy:
		if port == HeadlessDisplay_HeadlessDisplay_display {
			return true, true, state, func() {
				state.mock()
			}
		}
	case FragmentDisplayMsgsMsgupdate:
		if port == HeadlessDisplay_HeadlessDisplay_display {
			return true, true, state, func() {
				state.mock()
			}
		}
	case FragmentDisplayMsgsMsgclear:
		if port == HeadlessDisplay_HeadlessDisplay_display {
			return true, true, state, func() {
				state.mock()
			}
		}
	case FragmentDisplayMsgsMsgsetColor:
		if port == HeadlessDisplay_HeadlessDisplay_display {
			return true, true, state, func() {
				state.mock()
			}
		}
	case FragmentDisplayMsgsMsgsetBGColor:
		if port == HeadlessDisplay_HeadlessDisplay_display {
			return true, true, state, func() {
				state.mock()
			}
		}
	case FragmentDisplayMsgsMsgdrawRect:
		if port == HeadlessDisplay_HeadlessDisplay_display {
			return true, true, state, func() {
				state.mock()
			}
		}
	case FragmentDisplayMsgsMsgfillRect:
		if port == HeadlessDisplay_HeadlessDisplay_display {
			return true, true, state, func() {
				state.mock()
			}
		}
	case FragmentDisplayMsgsMsgdrawInteger:
		if port == HeadlessDisplay_HeadlessDisplay_display {
			return true, true, state, func() {
				state.mock()
			}
		}
	case FragmentDisplayMsgsMsgdrawThingML:
		if port == HeadlessDisplay_HeadlessDisplay_display {
			return true, true, state, func() {
				state.mock()
			}
		}
	}
	return false, false, state, nil
}
func (state *ThingHeadlessDisplayStateChartStateMOCK) OnExit() {}

/* -- Instance Constructor -- */
func NewThingHeadlessDisplay()  *ThingHeadlessDisplay {
	/* Create instance struct */
	instance := &ThingHeadlessDisplay{}
	/* Initialize state structs */
	stateThingHeadlessDisplayStateChart := &ThingHeadlessDisplayStateChart{}
	stateThingHeadlessDisplayStateChartStateINIT := &ThingHeadlessDisplayStateChartStateINIT{}
	stateThingHeadlessDisplayStateChartStateMOCK := &ThingHeadlessDisplayStateChartStateMOCK{}
	/* Initialize regions */
	stateThingHeadlessDisplayStateChart.CompositeState.Regions = []gosm.Region{
		gosm.Region{ Initial: stateThingHeadlessDisplayStateChartStateINIT, KeepsHistory: false},
	}
	/* Set state links */
	stateThingHeadlessDisplayStateChart.ThingHeadlessDisplay = instance
	stateThingHeadlessDisplayStateChartStateINIT.ThingHeadlessDisplayStateChart = stateThingHeadlessDisplayStateChart
	stateThingHeadlessDisplayStateChartStateINIT.ThingHeadlessDisplayStateChartStateMOCK = stateThingHeadlessDisplayStateChartStateMOCK
	stateThingHeadlessDisplayStateChartStateMOCK.ThingHeadlessDisplayStateChart = stateThingHeadlessDisplayStateChart
	stateThingHeadlessDisplayStateChartStateMOCK.ThingHeadlessDisplayStateChartStateINIT = stateThingHeadlessDisplayStateChartStateINIT
	/* Make component */
	component := gosm.MakeComponent(100, stateThingHeadlessDisplayStateChart)
	instance.Component = component
	/* Internal ports */
	return instance
}

func cloneThingHeadlessDisplay(original *ThingHeadlessDisplay)  *ThingHeadlessDisplay {
	clone := &ThingHeadlessDisplay{}
	return clone
}
/* -- Session forks -- */
