package main

import (
	"github.com/SINTEF-9012/gosm"
	"fmt"
)

/* -- Ports -- */
const (
	ConsoleLogger_Logger_log = 12
)

/* -- Component --*/
type ThingConsoleLogger struct {
	 *gosm.Component
	ACTIVATE_ON_STARTUP bool
	HAS_SIGNED_BYTE bool
	QUIET bool
}

func (state *ThingConsoleLogger) do_log(payload []byte, size uint8) {
	if  !(state.QUIET) {
		var log_type byte = payload[0]
		if log_type == LogType_function_called {
			fmt.Print(""+("log: function_called  ["))
		} else {
			if log_type == LogType_property_changed {
				fmt.Print(""+("log: property_changed ["))
			} else {
				if log_type == LogType_message_lost {
					fmt.Print(""+("log: message_lost     ["))
				} else {
					if log_type == LogType_message_sent {
						fmt.Print(""+("log: message_sent     ["))
					} else {
						if log_type == LogType_message_handled {
							fmt.Print(""+("log: message_handled  ["))
						} else {
							fmt.Print(""+("log: unknown          ["))
						}
					}
				}
			}
		}
	}
	var i uint8 = 0
	for i < size {
		var v byte = payload[i]
		if state.HAS_SIGNED_BYTE {
			fmt.Print(""+fmt.Sprintf("%d", int64(uint8((v & 0xFF)))))
		} else {
			fmt.Print(""+fmt.Sprintf("%d", int64(v)))
		}
		if  !(state.QUIET) {
			fmt.Print(""+(","))
		}
		i++
	}
	if  !(state.QUIET) {
		fmt.Println(""+("]"))
	} else {
		fmt.Println(""+(""))
	}
}
/* -- States -- */
type FragmentLoggerStateChart struct {
	 gosm.CompositeState
	 *ThingConsoleLogger
}

type FragmentLoggerStateChartStateSTARTUP struct {
	 *FragmentLoggerStateChart
	 *FragmentLoggerStateChartStateON
	 *FragmentLoggerStateChartStateOFF
}

type FragmentLoggerStateChartStateON struct {
	 *FragmentLoggerStateChart
	 *FragmentLoggerStateChartStateSTARTUP
	 *FragmentLoggerStateChartStateOFF
}

type FragmentLoggerStateChartStateOFF struct {
	 *FragmentLoggerStateChart
	 *FragmentLoggerStateChartStateSTARTUP
	 *FragmentLoggerStateChartStateON
}

/* -- Handlers -- */
func (state *FragmentLoggerStateChart) OnEntry() {
	state.CompositeState.OnEntry()
}
func (state *FragmentLoggerStateChart) Handle(port gosm.Port, message interface{}) (handled bool, internal bool, next gosm.State, action func()) {
	if handled, internal, next, action = state.CompositeState.Handle(port, message); handled {
		return
	}
	return false, false, state, nil
}
func (state *FragmentLoggerStateChart) OnExit() {
	state.CompositeState.OnExit()
}

func (state *FragmentLoggerStateChartStateSTARTUP) OnEntry() {}
func (state *FragmentLoggerStateChartStateSTARTUP) Handle(port gosm.Port, message interface{}) (handled bool, internal bool, next gosm.State, action func()) {
	switch message.(type) {
	case nil:
		if (state.ACTIVATE_ON_STARTUP) {
			return true, false, state.FragmentLoggerStateChartStateON, nil
			
		}
		if ( !(state.ACTIVATE_ON_STARTUP)) {
			return true, false, state.FragmentLoggerStateChartStateOFF, nil
			
		}
	}
	return false, false, state, nil
}
func (state *FragmentLoggerStateChartStateSTARTUP) OnExit() {}

func (state *FragmentLoggerStateChartStateON) OnEntry() {}
func (state *FragmentLoggerStateChartStateON) Handle(port gosm.Port, message interface{}) (handled bool, internal bool, next gosm.State, action func()) {
	switch typedMessage := message.(type) {
	case FragmentLogMsgsMsglog:
		if d := typedMessage; port == ConsoleLogger_Logger_log {
			return true, true, state, func() {
				state.do_log(d.Payload, d.Size)
			}
		}
	case FragmentLogMsgsMsglog_off:
		if port == ConsoleLogger_Logger_log {
			return true, false, state.FragmentLoggerStateChartStateOFF, nil
			
		}
	}
	return false, false, state, nil
}
func (state *FragmentLoggerStateChartStateON) OnExit() {}

func (state *FragmentLoggerStateChartStateOFF) OnEntry() {}
func (state *FragmentLoggerStateChartStateOFF) Handle(port gosm.Port, message interface{}) (handled bool, internal bool, next gosm.State, action func()) {
	switch message.(type) {
	case FragmentLogMsgsMsglog_on:
		if port == ConsoleLogger_Logger_log {
			return true, false, state.FragmentLoggerStateChartStateON, nil
			
		}
	}
	return false, false, state, nil
}
func (state *FragmentLoggerStateChartStateOFF) OnExit() {}

/* -- Instance Constructor -- */
func NewThingConsoleLogger()  *ThingConsoleLogger {
	/* Create instance struct */
	instance := &ThingConsoleLogger{}
	/* Initialize state structs */
	stateFragmentLoggerStateChart := &FragmentLoggerStateChart{}
	stateFragmentLoggerStateChartStateSTARTUP := &FragmentLoggerStateChartStateSTARTUP{}
	stateFragmentLoggerStateChartStateON := &FragmentLoggerStateChartStateON{}
	stateFragmentLoggerStateChartStateOFF := &FragmentLoggerStateChartStateOFF{}
	/* Initialize regions */
	stateFragmentLoggerStateChart.CompositeState.Regions = []gosm.Region{
		gosm.Region{ Initial: stateFragmentLoggerStateChartStateSTARTUP, KeepsHistory: false},
	}
	/* Set state links */
	stateFragmentLoggerStateChart.ThingConsoleLogger = instance
	stateFragmentLoggerStateChartStateSTARTUP.FragmentLoggerStateChart = stateFragmentLoggerStateChart
	stateFragmentLoggerStateChartStateSTARTUP.FragmentLoggerStateChartStateON = stateFragmentLoggerStateChartStateON
	stateFragmentLoggerStateChartStateSTARTUP.FragmentLoggerStateChartStateOFF = stateFragmentLoggerStateChartStateOFF
	stateFragmentLoggerStateChartStateON.FragmentLoggerStateChart = stateFragmentLoggerStateChart
	stateFragmentLoggerStateChartStateON.FragmentLoggerStateChartStateSTARTUP = stateFragmentLoggerStateChartStateSTARTUP
	stateFragmentLoggerStateChartStateON.FragmentLoggerStateChartStateOFF = stateFragmentLoggerStateChartStateOFF
	stateFragmentLoggerStateChartStateOFF.FragmentLoggerStateChart = stateFragmentLoggerStateChart
	stateFragmentLoggerStateChartStateOFF.FragmentLoggerStateChartStateSTARTUP = stateFragmentLoggerStateChartStateSTARTUP
	stateFragmentLoggerStateChartStateOFF.FragmentLoggerStateChartStateON = stateFragmentLoggerStateChartStateON
	/* Make component */
	component := gosm.MakeComponent(100, stateFragmentLoggerStateChart)
	instance.Component = component
	/* Internal ports */
	return instance
}

func cloneThingConsoleLogger(original *ThingConsoleLogger)  *ThingConsoleLogger {
	clone := &ThingConsoleLogger{
		ACTIVATE_ON_STARTUP: original.ACTIVATE_ON_STARTUP,
		HAS_SIGNED_BYTE: original.HAS_SIGNED_BYTE,
		QUIET: original.QUIET,
	}
	return clone
}
/* -- Session forks -- */
