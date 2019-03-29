package main

import (
	"time"
	"github.com/SINTEF-9012/gosm"
)

/* -- Ports -- */
const (
	TimerGo_TimerGo_timer = 9
)

/* -- Component --*/
type ThingTimerGo struct {
	 *gosm.Component
	Timers map[uint8]*time.Timer
}

func (state *ThingTimerGo) initialize() {
	state.Timers = map[uint8]*time.Timer(make(map[uint8]*time.Timer))
}
func (state *ThingTimerGo) startTimer(id uint8, delay uint16) {
	state.cancel(id)
	
    	state.Timers[id] = time.AfterFunc(time.Millisecond*time.Duration(delay), func() {
    		
	state.Send(TimerGo_TimerGo_timer, FragmentTimerMsgsMsgtimer_timeout{
		Id: id,
	})
	
    	})
    
}
func (state *ThingTimerGo) cancel(id uint8) {
	
    	if t, ok := state.Timers[id]; ok {
    		t.Stop()
    		delete(state.Timers, id)
    	}
    
}
/* -- States -- */
type ThingTimerGoStateChartSoftTimer struct {
	 gosm.CompositeState
	 *ThingTimerGo
}

type ThingTimerGoStateChartSoftTimerStatedefault struct {
	 *ThingTimerGoStateChartSoftTimer
}

/* -- Handlers -- */
func (state *ThingTimerGoStateChartSoftTimer) OnEntry() {
	state.initialize()
	state.CompositeState.OnEntry()
}
func (state *ThingTimerGoStateChartSoftTimer) Handle(port gosm.Port, message interface{}) (handled bool, internal bool, next gosm.State, action func()) {
	if handled, internal, next, action = state.CompositeState.Handle(port, message); handled {
		return
	}
	return false, false, state, nil
}
func (state *ThingTimerGoStateChartSoftTimer) OnExit() {
	state.CompositeState.OnExit()
}

func (state *ThingTimerGoStateChartSoftTimerStatedefault) OnEntry() {}
func (state *ThingTimerGoStateChartSoftTimerStatedefault) Handle(port gosm.Port, message interface{}) (handled bool, internal bool, next gosm.State, action func()) {
	switch typedMessage := message.(type) {
	case FragmentTimerMsgsMsgtimer_start:
		if m := typedMessage; port == TimerGo_TimerGo_timer && (m.Time > 0) {
			return true, true, state, func() {
				state.startTimer(m.Id, m.Time)
			}
		}
		if m := typedMessage; port == TimerGo_TimerGo_timer && (m.Time == 0) {
			return true, true, state, func() {
				state.Send(TimerGo_TimerGo_timer, FragmentTimerMsgsMsgtimer_timeout{
					Id: m.Id,
				})
			}
		}
	case FragmentTimerMsgsMsgtimer_cancel:
		if m := typedMessage; port == TimerGo_TimerGo_timer {
			return true, true, state, func() {
				state.cancel(m.Id)
			}
		}
	}
	return false, false, state, nil
}
func (state *ThingTimerGoStateChartSoftTimerStatedefault) OnExit() {}

/* -- Instance Constructor -- */
func NewThingTimerGo()  *ThingTimerGo {
	/* Create instance struct */
	instance := &ThingTimerGo{}
	/* Initialize state structs */
	stateThingTimerGoStateChartSoftTimer := &ThingTimerGoStateChartSoftTimer{}
	stateThingTimerGoStateChartSoftTimerStatedefault := &ThingTimerGoStateChartSoftTimerStatedefault{}
	/* Initialize regions */
	stateThingTimerGoStateChartSoftTimer.CompositeState.Regions = []gosm.Region{
		gosm.Region{ Initial: stateThingTimerGoStateChartSoftTimerStatedefault, KeepsHistory: false},
	}
	/* Set state links */
	stateThingTimerGoStateChartSoftTimer.ThingTimerGo = instance
	stateThingTimerGoStateChartSoftTimerStatedefault.ThingTimerGoStateChartSoftTimer = stateThingTimerGoStateChartSoftTimer
	/* Make component */
	component := gosm.MakeComponent(100, stateThingTimerGoStateChartSoftTimer)
	instance.Component = component
	/* Internal ports */
	return instance
}

func cloneThingTimerGo(original *ThingTimerGo)  *ThingTimerGo {
	clone := &ThingTimerGo{
		Timers: original.Timers,
	}
	return clone
}
/* -- Session forks -- */
