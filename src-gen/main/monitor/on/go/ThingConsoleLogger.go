package main

import (
	"github.com/SINTEF-9012/gosm"
	"log"
)

/* -- Ports -- */
const (
	ConsoleLogger_Logger_log = 12
)

/* -- Component --*/
type ThingConsoleLogger struct {
	 *gosm.Component
	ACTIVATE_ON_STARTUP bool
}

func (state *ThingConsoleLogger) log_function_called(inst string, fn_name string, ty string, returns string, params string) {
	log.Println(""+("function_called(")+(inst)+(", ")+(fn_name)+(", ")+(ty)+(", ")+(returns)+(", ")+(params)+(")"))
}
func (state *ThingConsoleLogger) log_property_changed(inst string, prop_name string, ty string, old_value string, new_value string) {
	log.Println(""+("property_changed(")+(inst)+(", ")+(prop_name)+(", ")+(ty)+(", ")+(old_value)+(", ")+(new_value)+(")"))
}
func (state *ThingConsoleLogger) log_message_lost(inst string, port_name string, msg_name string, params string) {
	log.Println(""+("message_lost(")+(inst)+(", ")+(port_name)+(", ")+(msg_name)+(", ")+(params)+(")"))
}
func (state *ThingConsoleLogger) log_message_sent(inst string, port_name string, msg_name string, params string) {
	log.Println(""+("message_sent(")+(inst)+(", ")+(port_name)+(", ")+(msg_name)+(", ")+(params)+(")"))
}
func (state *ThingConsoleLogger) log_message_handled(inst string, source string, target string, port_name string, msg_name string, params string) {
	log.Println(""+("message_handled(")+(inst)+(", ")+(source)+(", ")+(target)+(", ")+(port_name)+(", ")+(msg_name)+(", ")+(params)+(")"))
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
	case FragmentLogMsgsMsgfunction_called:
		if d := typedMessage; port == ConsoleLogger_Logger_log {
			return true, true, state, func() {
				state.log_function_called(d.Inst, d.Fn_name, d.Ty, d.Returns, d.Params)
			}
		}
	case FragmentLogMsgsMsgproperty_changed:
		if d := typedMessage; port == ConsoleLogger_Logger_log {
			return true, true, state, func() {
				state.log_property_changed(d.Inst, d.Prop_name, d.Ty, d.Old_value, d.New_value)
			}
		}
	case FragmentLogMsgsMsgmessage_lost:
		if d := typedMessage; port == ConsoleLogger_Logger_log {
			return true, true, state, func() {
				state.log_message_lost(d.Inst, d.Port_name, d.Msg_name, d.Params)
			}
		}
	case FragmentLogMsgsMsgmessage_sent:
		if d := typedMessage; port == ConsoleLogger_Logger_log {
			return true, true, state, func() {
				state.log_message_sent(d.Inst, d.Port_name, d.Msg_name, d.Params)
			}
		}
	case FragmentLogMsgsMsgmessage_handled:
		if d := typedMessage; port == ConsoleLogger_Logger_log {
			return true, true, state, func() {
				state.log_message_handled(d.Inst, d.Source, d.Target, d.Port_name, d.Msg_name, d.Params)
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
	}
	return clone
}
/* -- Session forks -- */
