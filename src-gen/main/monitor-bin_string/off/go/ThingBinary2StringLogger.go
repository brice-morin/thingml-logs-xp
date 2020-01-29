package main

import (
	"github.com/SINTEF-9012/gosm"
	"fmt"
)

/* -- Ports -- */
const (
	Binary2StringLogger_Logger_log = 12
)

/* -- Component --*/
type ThingBinary2StringLogger struct {
	 *gosm.Component
	ACTIVATE_ON_STARTUP bool
	HAS_SIGNED_BYTE bool
}

func (state *ThingBinary2StringLogger) get_byte(b byte)  byte {
	if state.HAS_SIGNED_BYTE {
		return byte((b & 0xFF))
	} else {
		return byte(b)
	}
}
func (state *ThingBinary2StringLogger) stateName(id byte)  string {
	if id == 0 {
		return "BreakoutGame.SC"
	} else {
		if id == 1 {
			return "BreakoutGame.SC.INIT"
		} else {
			if id == 2 {
				return "BreakoutGame.SC.LAUNCH"
			} else {
				if id == 3 {
					return "BreakoutGame.SC.PLAY"
				} else {
					if id == 4 {
						return "BreakoutGame.SC.LOSTBALL"
					} else {
						if id == 5 {
							return "BreakoutGame.SC.NEXTLEVEL"
						} else {
							if id == 6 {
								return "BreakoutGame.SC.GAMEOVER"
							} else {
								if id == 7 {
									return "Logger"
								} else {
									if id == 8 {
										return "Logger.null.STARTUP"
									} else {
										if id == 9 {
											return "Logger.null.ON"
										} else {
											if id == 10 {
												return "Logger.null.OFF"
											} else {
												if id == 11 {
													return "HeadlessDisplay"
												} else {
													if id == 12 {
														return "HeadlessDisplay.null.INIT"
													} else {
														if id == 13 {
															return "HeadlessDisplay.null.MOCK"
														} else {
															if id == 14 {
																return "BasicIAController.SC"
															} else {
																if id == 15 {
																	return "BasicIAController.SC.Following"
																} else {
																	if id == 16 {
																		return "TimerJava.SoftTimer"
																	} else {
																		if id == 17 {
																			return "TimerJava.SoftTimer.default"
																		} else {
																			if id == 18 {
																				return "TimerJS.SoftTimer"
																			} else {
																				if id == 19 {
																					return "TimerJS.SoftTimer.default"
																				} else {
																					if id == 20 {
																						return "TimerNodeJS.SoftTimer"
																					} else {
																						if id == 21 {
																							return "TimerNodeJS.SoftTimer.default"
																						} else {
																							if id == 22 {
																								return "TimerPosix.SoftTimer"
																							} else {
																								if id == 23 {
																									return "TimerPosix.SoftTimer.default"
																								} else {
																									if id == 24 {
																										return "TimerArduino.SoftTimer"
																									} else {
																										if id == 25 {
																											return "TimerArduino.SoftTimer.default"
																										} else {
																											if id == 26 {
																												return "TimerGo.SoftTimer"
																											} else {
																												if id == 27 {
																													return "TimerGo.SoftTimer.default"
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return "unknown"
}
func (state *ThingBinary2StringLogger) do_log(payload []byte, size uint8) {
	var log_type byte = state.get_byte(payload[0])
	var inst byte = state.get_byte(payload[1])
	if log_type == LogType_function_called {
		var func_ byte = state.get_byte(payload[2])
		if inst == 0 {
			if func_ == 1 {
				fmt.Println(""+("function_called(BreakoutGame0, initColors, void")+(", _")+(")"))
			} else {
				if func_ == 2 {
					fmt.Println(""+("function_called(BreakoutGame0, resetBall, void")+(", _")+(")"))
				} else {
					if func_ == 3 {
						fmt.Println(""+("function_called(BreakoutGame0, eraseBall, void")+(", _")+(")"))
					} else {
						if func_ == 4 {
							fmt.Println(""+("function_called(BreakoutGame0, drawBall, void")+(", _")+(")"))
						} else {
							if func_ == 5 {
								fmt.Println(""+("function_called(BreakoutGame0, erasePad, void")+(", _")+(")"))
							} else {
								if func_ == 6 {
									fmt.Println(""+("function_called(BreakoutGame0, drawPad, void")+(", _")+(")"))
								} else {
									if func_ == 7 {
										var bin_c []byte = []byte{ state.get_byte(payload[3 + 0]), state.get_byte(payload[3 + 1]) }
										var c int16 = int16((bin_c[0] << 8 | bin_c[1] << 0))
										if  !(state.HAS_SIGNED_BYTE) {
											c = c + 256
										}
										fmt.Println(""+("function_called(BreakoutGame0, drawCountDown, void")+(", _")+(", c=")+fmt.Sprintf("%d", int64(c))+(")"))
									} else {
										if func_ == 8 {
											fmt.Println(""+("function_called(BreakoutGame0, drawWalls, void")+(", _")+(")"))
										} else {
											if func_ == 9 {
												var bin_result_1 []byte = []byte{ state.get_byte(payload[size - 1 + 0]) }
												var result_1 bool = int16((bin_result_1[0] << 0)) != 0
												var bin_variable []byte = []byte{ state.get_byte(payload[3 + 0]) }
												var variable uint8 = uint8((bin_variable[0] << 0))
												var bin_bit []byte = []byte{ state.get_byte(payload[4 + 0]) }
												var bit uint8 = uint8((bin_bit[0] << 0))
												fmt.Println(""+("function_called(BreakoutGame0, bitIsSet, Boolean")+(", ")+fmt.Sprintf("%t", result_1)+(", variable=")+fmt.Sprintf("%d", int64(variable))+(", bit=")+fmt.Sprintf("%d", int64(bit))+(")"))
											} else {
												if func_ == 10 {
													fmt.Println(""+("function_called(BreakoutGame0, createBricks, void")+(", _")+(")"))
												} else {
													if func_ == 11 {
														var bin_result_2 []byte = []byte{ state.get_byte(payload[size - 1 + 0]) }
														var result_2 uint8 = uint8((bin_result_2[0] << 0))
														fmt.Println(""+("function_called(BreakoutGame0, bricksLeft, UInt8")+(", ")+fmt.Sprintf("%d", int64(result_2))+(")"))
													} else {
														if func_ == 12 {
															var bin_x_1 []byte = []byte{ state.get_byte(payload[3 + 0]) }
															var x_1 uint8 = uint8((bin_x_1[0] << 0))
															var bin_y_1 []byte = []byte{ state.get_byte(payload[4 + 0]) }
															var y_1 uint8 = uint8((bin_y_1[0] << 0))
															fmt.Println(""+("function_called(BreakoutGame0, drawBrick, void")+(", _")+(", x=")+fmt.Sprintf("%d", int64(x_1))+(", y=")+fmt.Sprintf("%d", int64(y_1))+(")"))
														} else {
															if func_ == 13 {
																var bin_x_2 []byte = []byte{ state.get_byte(payload[3 + 0]) }
																var x_2 uint8 = uint8((bin_x_2[0] << 0))
																var bin_y_2 []byte = []byte{ state.get_byte(payload[4 + 0]) }
																var y_2 uint8 = uint8((bin_y_2[0] << 0))
																fmt.Println(""+("function_called(BreakoutGame0, removeBrick, void")+(", _")+(", x=")+fmt.Sprintf("%d", int64(x_2))+(", y=")+fmt.Sprintf("%d", int64(y_2))+(")"))
															} else {
																if func_ == 14 {
																	var bin_result []byte = []byte{ state.get_byte(payload[size - 1 + 0]) }
																	var result bool = int16((bin_result[0] << 0)) != 0
																	var bin_xpos []byte = []byte{ state.get_byte(payload[3 + 0]), state.get_byte(payload[3 + 1]) }
																	var xpos int16 = int16((bin_xpos[0] << 8 | bin_xpos[1] << 0))
																	if  !(state.HAS_SIGNED_BYTE) {
																		xpos = xpos + 256
																	}
																	var bin_ypos []byte = []byte{ state.get_byte(payload[5 + 0]), state.get_byte(payload[5 + 1]) }
																	var ypos int16 = int16((bin_ypos[0] << 8 | bin_ypos[1] << 0))
																	if  !(state.HAS_SIGNED_BYTE) {
																		ypos = ypos + 256
																	}
																	fmt.Println(""+("function_called(BreakoutGame0, collideBrick, Boolean")+(", ")+fmt.Sprintf("%t", result)+(", xpos=")+fmt.Sprintf("%d", int64(xpos))+(", ypos=")+fmt.Sprintf("%d", int64(ypos))+(")"))
																} else {
																	if func_ == 15 {
																		fmt.Println(""+("function_called(BreakoutGame0, drawLevel, void")+(", _")+(")"))
																	} else {
																		if func_ == 16 {
																			var bin_diff []byte = []byte{ state.get_byte(payload[3 + 0]) }
																			var diff int8 = int8((bin_diff[0] << 0))
																			if  !(state.HAS_SIGNED_BYTE) {
																				diff = diff + 1
																			}
																			fmt.Println(""+("function_called(BreakoutGame0, incrementScore, void")+(", _")+(", diff=")+fmt.Sprintf("%d", int64(diff))+(")"))
																		} else {
																			if func_ == 17 {
																				fmt.Println(""+("function_called(BreakoutGame0, drawScore, void")+(", _")+(")"))
																			} else {
																				if func_ == 18 {
																					fmt.Println(""+("function_called(BreakoutGame0, drawLives, void")+(", _")+(")"))
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	} else {
		if log_type == LogType_property_changed {
			var prop byte = state.get_byte(payload[2])
			if inst == 0 {
				if prop == 0 {
					var bin_old_1 []byte = []byte{ state.get_byte(payload[3 + 0]) }
					var old_1 uint8 = uint8((bin_old_1[0] << 0))
					var bin_new__1 []byte = []byte{ state.get_byte(payload[4 + 0]) }
					var new__1 uint8 = uint8((bin_new__1[0] << 0))
					fmt.Println(""+("property_changed(BreakoutGame0, XDISPSIZE, UInt8")+(", ")+fmt.Sprintf("%d", int64(old_1))+(", ")+fmt.Sprintf("%d", int64(new__1))+(")"))
				} else {
					if prop == 1 {
						var bin_old_2 []byte = []byte{ state.get_byte(payload[3 + 0]) }
						var old_2 uint8 = uint8((bin_old_2[0] << 0))
						var bin_new__2 []byte = []byte{ state.get_byte(payload[4 + 0]) }
						var new__2 uint8 = uint8((bin_new__2[0] << 0))
						fmt.Println(""+("property_changed(BreakoutGame0, YDISPSIZE, UInt8")+(", ")+fmt.Sprintf("%d", int64(old_2))+(", ")+fmt.Sprintf("%d", int64(new__2))+(")"))
					} else {
						if prop == 2 {
							var bin_old_3 []byte = []byte{ state.get_byte(payload[3 + 0]), state.get_byte(payload[3 + 1]) }
							var old_3 int16 = int16((bin_old_3[0] << 8 | bin_old_3[1] << 0))
							if  !(state.HAS_SIGNED_BYTE) {
								old_3 = old_3 + 256
							}
							var bin_new__3 []byte = []byte{ state.get_byte(payload[5 + 0]), state.get_byte(payload[5 + 1]) }
							var new__3 int16 = int16((bin_new__3[0] << 8 | bin_new__3[1] << 0))
							if  !(state.HAS_SIGNED_BYTE) {
								new__3 = new__3 + 256
							}
							fmt.Println(""+("property_changed(BreakoutGame0, SCALE, Int16")+(", ")+fmt.Sprintf("%d", int64(old_3))+(", ")+fmt.Sprintf("%d", int64(new__3))+(")"))
						} else {
							if prop == 3 {
								var bin_old_4 []byte = []byte{ state.get_byte(payload[3 + 0]), state.get_byte(payload[3 + 1]) }
								var old_4 int16 = int16((bin_old_4[0] << 8 | bin_old_4[1] << 0))
								if  !(state.HAS_SIGNED_BYTE) {
									old_4 = old_4 + 256
								}
								var bin_new__4 []byte = []byte{ state.get_byte(payload[5 + 0]), state.get_byte(payload[5 + 1]) }
								var new__4 int16 = int16((bin_new__4[0] << 8 | bin_new__4[1] << 0))
								if  !(state.HAS_SIGNED_BYTE) {
									new__4 = new__4 + 256
								}
								fmt.Println(""+("property_changed(BreakoutGame0, XMAX, Int16")+(", ")+fmt.Sprintf("%d", int64(old_4))+(", ")+fmt.Sprintf("%d", int64(new__4))+(")"))
							} else {
								if prop == 4 {
									var bin_old_5 []byte = []byte{ state.get_byte(payload[3 + 0]), state.get_byte(payload[3 + 1]) }
									var old_5 int16 = int16((bin_old_5[0] << 8 | bin_old_5[1] << 0))
									if  !(state.HAS_SIGNED_BYTE) {
										old_5 = old_5 + 256
									}
									var bin_new__5 []byte = []byte{ state.get_byte(payload[5 + 0]), state.get_byte(payload[5 + 1]) }
									var new__5 int16 = int16((bin_new__5[0] << 8 | bin_new__5[1] << 0))
									if  !(state.HAS_SIGNED_BYTE) {
										new__5 = new__5 + 256
									}
									fmt.Println(""+("property_changed(BreakoutGame0, YMAX, Int16")+(", ")+fmt.Sprintf("%d", int64(old_5))+(", ")+fmt.Sprintf("%d", int64(new__5))+(")"))
								} else {
									if prop == 5 {
										var bin_old_6 []byte = []byte{ state.get_byte(payload[3 + 0]), state.get_byte(payload[3 + 1]) }
										var old_6 int16 = int16((bin_old_6[0] << 8 | bin_old_6[1] << 0))
										if  !(state.HAS_SIGNED_BYTE) {
											old_6 = old_6 + 256
										}
										var bin_new__6 []byte = []byte{ state.get_byte(payload[5 + 0]), state.get_byte(payload[5 + 1]) }
										var new__6 int16 = int16((bin_new__6[0] << 8 | bin_new__6[1] << 0))
										if  !(state.HAS_SIGNED_BYTE) {
											new__6 = new__6 + 256
										}
										fmt.Println(""+("property_changed(BreakoutGame0, TOP, Int16")+(", ")+fmt.Sprintf("%d", int64(old_6))+(", ")+fmt.Sprintf("%d", int64(new__6))+(")"))
									} else {
										if prop == 6 {
											var bin_old_7 []byte = []byte{ state.get_byte(payload[3 + 0]), state.get_byte(payload[3 + 1]) }
											var old_7 int16 = int16((bin_old_7[0] << 8 | bin_old_7[1] << 0))
											if  !(state.HAS_SIGNED_BYTE) {
												old_7 = old_7 + 256
											}
											var bin_new__7 []byte = []byte{ state.get_byte(payload[5 + 0]), state.get_byte(payload[5 + 1]) }
											var new__7 int16 = int16((bin_new__7[0] << 8 | bin_new__7[1] << 0))
											if  !(state.HAS_SIGNED_BYTE) {
												new__7 = new__7 + 256
											}
											fmt.Println(""+("property_changed(BreakoutGame0, BOTTOM, Int16")+(", ")+fmt.Sprintf("%d", int64(old_7))+(", ")+fmt.Sprintf("%d", int64(new__7))+(")"))
										} else {
											if prop == 7 {
												var bin_old_8 []byte = []byte{ state.get_byte(payload[3 + 0]), state.get_byte(payload[3 + 1]) }
												var old_8 int16 = int16((bin_old_8[0] << 8 | bin_old_8[1] << 0))
												if  !(state.HAS_SIGNED_BYTE) {
													old_8 = old_8 + 256
												}
												var bin_new__8 []byte = []byte{ state.get_byte(payload[5 + 0]), state.get_byte(payload[5 + 1]) }
												var new__8 int16 = int16((bin_new__8[0] << 8 | bin_new__8[1] << 0))
												if  !(state.HAS_SIGNED_BYTE) {
													new__8 = new__8 + 256
												}
												fmt.Println(""+("property_changed(BreakoutGame0, LEFT, Int16")+(", ")+fmt.Sprintf("%d", int64(old_8))+(", ")+fmt.Sprintf("%d", int64(new__8))+(")"))
											} else {
												if prop == 8 {
													var bin_old_9 []byte = []byte{ state.get_byte(payload[3 + 0]), state.get_byte(payload[3 + 1]) }
													var old_9 int16 = int16((bin_old_9[0] << 8 | bin_old_9[1] << 0))
													if  !(state.HAS_SIGNED_BYTE) {
														old_9 = old_9 + 256
													}
													var bin_new__9 []byte = []byte{ state.get_byte(payload[5 + 0]), state.get_byte(payload[5 + 1]) }
													var new__9 int16 = int16((bin_new__9[0] << 8 | bin_new__9[1] << 0))
													if  !(state.HAS_SIGNED_BYTE) {
														new__9 = new__9 + 256
													}
													fmt.Println(""+("property_changed(BreakoutGame0, RIGHT, Int16")+(", ")+fmt.Sprintf("%d", int64(old_9))+(", ")+fmt.Sprintf("%d", int64(new__9))+(")"))
												} else {
													if prop == 9 {
														var bin_old_10 []byte = []byte{ state.get_byte(payload[3 + 0]), state.get_byte(payload[3 + 1]) }
														var old_10 int16 = int16((bin_old_10[0] << 8 | bin_old_10[1] << 0))
														if  !(state.HAS_SIGNED_BYTE) {
															old_10 = old_10 + 256
														}
														var bin_new__10 []byte = []byte{ state.get_byte(payload[5 + 0]), state.get_byte(payload[5 + 1]) }
														var new__10 int16 = int16((bin_new__10[0] << 8 | bin_new__10[1] << 0))
														if  !(state.HAS_SIGNED_BYTE) {
															new__10 = new__10 + 256
														}
														fmt.Println(""+("property_changed(BreakoutGame0, br, Int16")+(", ")+fmt.Sprintf("%d", int64(old_10))+(", ")+fmt.Sprintf("%d", int64(new__10))+(")"))
													} else {
														if prop == 10 {
															var bin_old_11 []byte = []byte{ state.get_byte(payload[3 + 0]), state.get_byte(payload[3 + 1]) }
															var old_11 int16 = int16((bin_old_11[0] << 8 | bin_old_11[1] << 0))
															if  !(state.HAS_SIGNED_BYTE) {
																old_11 = old_11 + 256
															}
															var bin_new__11 []byte = []byte{ state.get_byte(payload[5 + 0]), state.get_byte(payload[5 + 1]) }
															var new__11 int16 = int16((bin_new__11[0] << 8 | bin_new__11[1] << 0))
															if  !(state.HAS_SIGNED_BYTE) {
																new__11 = new__11 + 256
															}
															fmt.Println(""+("property_changed(BreakoutGame0, bx, Int16")+(", ")+fmt.Sprintf("%d", int64(old_11))+(", ")+fmt.Sprintf("%d", int64(new__11))+(")"))
														} else {
															if prop == 11 {
																var bin_old_12 []byte = []byte{ state.get_byte(payload[3 + 0]), state.get_byte(payload[3 + 1]) }
																var old_12 int16 = int16((bin_old_12[0] << 8 | bin_old_12[1] << 0))
																if  !(state.HAS_SIGNED_BYTE) {
																	old_12 = old_12 + 256
																}
																var bin_new__12 []byte = []byte{ state.get_byte(payload[5 + 0]), state.get_byte(payload[5 + 1]) }
																var new__12 int16 = int16((bin_new__12[0] << 8 | bin_new__12[1] << 0))
																if  !(state.HAS_SIGNED_BYTE) {
																	new__12 = new__12 + 256
																}
																fmt.Println(""+("property_changed(BreakoutGame0, by, Int16")+(", ")+fmt.Sprintf("%d", int64(old_12))+(", ")+fmt.Sprintf("%d", int64(new__12))+(")"))
															} else {
																if prop == 12 {
																	var bin_old_13 []byte = []byte{ state.get_byte(payload[3 + 0]), state.get_byte(payload[3 + 1]) }
																	var old_13 int16 = int16((bin_old_13[0] << 8 | bin_old_13[1] << 0))
																	if  !(state.HAS_SIGNED_BYTE) {
																		old_13 = old_13 + 256
																	}
																	var bin_new__13 []byte = []byte{ state.get_byte(payload[5 + 0]), state.get_byte(payload[5 + 1]) }
																	var new__13 int16 = int16((bin_new__13[0] << 8 | bin_new__13[1] << 0))
																	if  !(state.HAS_SIGNED_BYTE) {
																		new__13 = new__13 + 256
																	}
																	fmt.Println(""+("property_changed(BreakoutGame0, dx, Int16")+(", ")+fmt.Sprintf("%d", int64(old_13))+(", ")+fmt.Sprintf("%d", int64(new__13))+(")"))
																} else {
																	if prop == 13 {
																		var bin_old_14 []byte = []byte{ state.get_byte(payload[3 + 0]), state.get_byte(payload[3 + 1]) }
																		var old_14 int16 = int16((bin_old_14[0] << 8 | bin_old_14[1] << 0))
																		if  !(state.HAS_SIGNED_BYTE) {
																			old_14 = old_14 + 256
																		}
																		var bin_new__14 []byte = []byte{ state.get_byte(payload[5 + 0]), state.get_byte(payload[5 + 1]) }
																		var new__14 int16 = int16((bin_new__14[0] << 8 | bin_new__14[1] << 0))
																		if  !(state.HAS_SIGNED_BYTE) {
																			new__14 = new__14 + 256
																		}
																		fmt.Println(""+("property_changed(BreakoutGame0, dy, Int16")+(", ")+fmt.Sprintf("%d", int64(old_14))+(", ")+fmt.Sprintf("%d", int64(new__14))+(")"))
																	} else {
																		if prop == 14 {
																			var bin_old_15 []byte = []byte{ state.get_byte(payload[3 + 0]), state.get_byte(payload[3 + 1]) }
																			var old_15 int16 = int16((bin_old_15[0] << 8 | bin_old_15[1] << 0))
																			if  !(state.HAS_SIGNED_BYTE) {
																				old_15 = old_15 + 256
																			}
																			var bin_new__15 []byte = []byte{ state.get_byte(payload[5 + 0]), state.get_byte(payload[5 + 1]) }
																			var new__15 int16 = int16((bin_new__15[0] << 8 | bin_new__15[1] << 0))
																			if  !(state.HAS_SIGNED_BYTE) {
																				new__15 = new__15 + 256
																			}
																			fmt.Println(""+("property_changed(BreakoutGame0, padx, Int16")+(", ")+fmt.Sprintf("%d", int64(old_15))+(", ")+fmt.Sprintf("%d", int64(new__15))+(")"))
																		} else {
																			if prop == 15 {
																				var bin_old_16 []byte = []byte{ state.get_byte(payload[3 + 0]), state.get_byte(payload[3 + 1]) }
																				var old_16 int16 = int16((bin_old_16[0] << 8 | bin_old_16[1] << 0))
																				if  !(state.HAS_SIGNED_BYTE) {
																					old_16 = old_16 + 256
																				}
																				var bin_new__16 []byte = []byte{ state.get_byte(payload[5 + 0]), state.get_byte(payload[5 + 1]) }
																				var new__16 int16 = int16((bin_new__16[0] << 8 | bin_new__16[1] << 0))
																				if  !(state.HAS_SIGNED_BYTE) {
																					new__16 = new__16 + 256
																				}
																				fmt.Println(""+("property_changed(BreakoutGame0, pady, Int16")+(", ")+fmt.Sprintf("%d", int64(old_16))+(", ")+fmt.Sprintf("%d", int64(new__16))+(")"))
																			} else {
																				if prop == 16 {
																					var bin_old_17 []byte = []byte{ state.get_byte(payload[3 + 0]), state.get_byte(payload[3 + 1]) }
																					var old_17 int16 = int16((bin_old_17[0] << 8 | bin_old_17[1] << 0))
																					if  !(state.HAS_SIGNED_BYTE) {
																						old_17 = old_17 + 256
																					}
																					var bin_new__17 []byte = []byte{ state.get_byte(payload[5 + 0]), state.get_byte(payload[5 + 1]) }
																					var new__17 int16 = int16((bin_new__17[0] << 8 | bin_new__17[1] << 0))
																					if  !(state.HAS_SIGNED_BYTE) {
																						new__17 = new__17 + 256
																					}
																					fmt.Println(""+("property_changed(BreakoutGame0, padlen, Int16")+(", ")+fmt.Sprintf("%d", int64(old_17))+(", ")+fmt.Sprintf("%d", int64(new__17))+(")"))
																				} else {
																					if prop == 17 {
																						var bin_old_18 []byte = []byte{ state.get_byte(payload[3 + 0]), state.get_byte(payload[3 + 1]) }
																						var old_18 int16 = int16((bin_old_18[0] << 8 | bin_old_18[1] << 0))
																						if  !(state.HAS_SIGNED_BYTE) {
																							old_18 = old_18 + 256
																						}
																						var bin_new__18 []byte = []byte{ state.get_byte(payload[5 + 0]), state.get_byte(payload[5 + 1]) }
																						var new__18 int16 = int16((bin_new__18[0] << 8 | bin_new__18[1] << 0))
																						if  !(state.HAS_SIGNED_BYTE) {
																							new__18 = new__18 + 256
																						}
																						fmt.Println(""+("property_changed(BreakoutGame0, prevBX, Int16")+(", ")+fmt.Sprintf("%d", int64(old_18))+(", ")+fmt.Sprintf("%d", int64(new__18))+(")"))
																					} else {
																						if prop == 18 {
																							var bin_old_19 []byte = []byte{ state.get_byte(payload[3 + 0]), state.get_byte(payload[3 + 1]) }
																							var old_19 int16 = int16((bin_old_19[0] << 8 | bin_old_19[1] << 0))
																							if  !(state.HAS_SIGNED_BYTE) {
																								old_19 = old_19 + 256
																							}
																							var bin_new__19 []byte = []byte{ state.get_byte(payload[5 + 0]), state.get_byte(payload[5 + 1]) }
																							var new__19 int16 = int16((bin_new__19[0] << 8 | bin_new__19[1] << 0))
																							if  !(state.HAS_SIGNED_BYTE) {
																								new__19 = new__19 + 256
																							}
																							fmt.Println(""+("property_changed(BreakoutGame0, prevBY, Int16")+(", ")+fmt.Sprintf("%d", int64(old_19))+(", ")+fmt.Sprintf("%d", int64(new__19))+(")"))
																						} else {
																							if prop == 19 {
																								var bin_old_20 []byte = []byte{ state.get_byte(payload[3 + 0]) }
																								var old_20 uint8 = uint8((bin_old_20[0] << 0))
																								var bin_new__20 []byte = []byte{ state.get_byte(payload[4 + 0]) }
																								var new__20 uint8 = uint8((bin_new__20[0] << 0))
																								fmt.Println(""+("property_changed(BreakoutGame0, bgcolor, UInt8")+(", ")+fmt.Sprintf("%d", int64(old_20))+(", ")+fmt.Sprintf("%d", int64(new__20))+(")"))
																							} else {
																								if prop == 20 {
																									var bin_old_21 []byte = []byte{ state.get_byte(payload[3 + 0]) }
																									var old_21 uint8 = uint8((bin_old_21[0] << 0))
																									var bin_new__21 []byte = []byte{ state.get_byte(payload[4 + 0]) }
																									var new__21 uint8 = uint8((bin_new__21[0] << 0))
																									fmt.Println(""+("property_changed(BreakoutGame0, fgcolor, UInt8")+(", ")+fmt.Sprintf("%d", int64(old_21))+(", ")+fmt.Sprintf("%d", int64(new__21))+(")"))
																								} else {
																									if prop == 21 {
																										var bin_old_22 []byte = []byte{ state.get_byte(payload[3 + 0]), state.get_byte(payload[3 + 1]) }
																										var old_22 uint16 = uint16((bin_old_22[0] << 8 | bin_old_22[1] << 0))
																										var bin_new__22 []byte = []byte{ state.get_byte(payload[5 + 0]), state.get_byte(payload[5 + 1]) }
																										var new__22 uint16 = uint16((bin_new__22[0] << 8 | bin_new__22[1] << 0))
																										fmt.Println(""+("property_changed(BreakoutGame0, period, UInt16")+(", ")+fmt.Sprintf("%d", int64(old_22))+(", ")+fmt.Sprintf("%d", int64(new__22))+(")"))
																									} else {
																										if prop == 22 {
																											var bin_old_23 []byte = []byte{ state.get_byte(payload[3 + 0]), state.get_byte(payload[3 + 1]) }
																											var old_23 int16 = int16((bin_old_23[0] << 8 | bin_old_23[1] << 0))
																											if  !(state.HAS_SIGNED_BYTE) {
																												old_23 = old_23 + 256
																											}
																											var bin_new__23 []byte = []byte{ state.get_byte(payload[5 + 0]), state.get_byte(payload[5 + 1]) }
																											var new__23 int16 = int16((bin_new__23[0] << 8 | bin_new__23[1] << 0))
																											if  !(state.HAS_SIGNED_BYTE) {
																												new__23 = new__23 + 256
																											}
																											fmt.Println(""+("property_changed(BreakoutGame0, prevPX, Int16")+(", ")+fmt.Sprintf("%d", int64(old_23))+(", ")+fmt.Sprintf("%d", int64(new__23))+(")"))
																										} else {
																											if prop == 23 {
																												var bin_old_24 []byte = []byte{ state.get_byte(payload[3 + 0]), state.get_byte(payload[3 + 1]) }
																												var old_24 int16 = int16((bin_old_24[0] << 8 | bin_old_24[1] << 0))
																												if  !(state.HAS_SIGNED_BYTE) {
																													old_24 = old_24 + 256
																												}
																												var bin_new__24 []byte = []byte{ state.get_byte(payload[5 + 0]), state.get_byte(payload[5 + 1]) }
																												var new__24 int16 = int16((bin_new__24[0] << 8 | bin_new__24[1] << 0))
																												if  !(state.HAS_SIGNED_BYTE) {
																													new__24 = new__24 + 256
																												}
																												fmt.Println(""+("property_changed(BreakoutGame0, prevPY, Int16")+(", ")+fmt.Sprintf("%d", int64(old_24))+(", ")+fmt.Sprintf("%d", int64(new__24))+(")"))
																											} else {
																												if prop == 24 {
																													var bin_old_25 []byte = []byte{ state.get_byte(payload[3 + 0]) }
																													var old_25 uint8 = uint8((bin_old_25[0] << 0))
																													var bin_new__25 []byte = []byte{ state.get_byte(payload[4 + 0]) }
																													var new__25 uint8 = uint8((bin_new__25[0] << 0))
																													fmt.Println(""+("property_changed(BreakoutGame0, BRICK_ROWS, UInt8")+(", ")+fmt.Sprintf("%d", int64(old_25))+(", ")+fmt.Sprintf("%d", int64(new__25))+(")"))
																												} else {
																													if prop == 25 {
																														var bin_old_26 []byte = []byte{ state.get_byte(payload[3 + 0]) }
																														var old_26 uint8 = uint8((bin_old_26[0] << 0))
																														var bin_new__26 []byte = []byte{ state.get_byte(payload[4 + 0]) }
																														var new__26 uint8 = uint8((bin_new__26[0] << 0))
																														fmt.Println(""+("property_changed(BreakoutGame0, BRICK_HEIGHT, UInt8")+(", ")+fmt.Sprintf("%d", int64(old_26))+(", ")+fmt.Sprintf("%d", int64(new__26))+(")"))
																													} else {
																														if prop == 26 {
																															var bin_old_27 []byte = []byte{ state.get_byte(payload[3 + 0]) }
																															var old_27 uint8 = uint8((bin_old_27[0] << 0))
																															var bin_new__27 []byte = []byte{ state.get_byte(payload[4 + 0]) }
																															var new__27 uint8 = uint8((bin_new__27[0] << 0))
																															fmt.Println(""+("property_changed(BreakoutGame0, bricks, UInt8")+(", ")+fmt.Sprintf("%d", int64(old_27))+(", ")+fmt.Sprintf("%d", int64(new__27))+(")"))
																														} else {
																															if prop == 27 {
																																var bin_old_28 []byte = []byte{ state.get_byte(payload[3 + 0]), state.get_byte(payload[3 + 1]) }
																																var old_28 int16 = int16((bin_old_28[0] << 8 | bin_old_28[1] << 0))
																																if  !(state.HAS_SIGNED_BYTE) {
																																	old_28 = old_28 + 256
																																}
																																var bin_new__28 []byte = []byte{ state.get_byte(payload[5 + 0]), state.get_byte(payload[5 + 1]) }
																																var new__28 int16 = int16((bin_new__28[0] << 8 | bin_new__28[1] << 0))
																																if  !(state.HAS_SIGNED_BYTE) {
																																	new__28 = new__28 + 256
																																}
																																fmt.Println(""+("property_changed(BreakoutGame0, score, Int16")+(", ")+fmt.Sprintf("%d", int64(old_28))+(", ")+fmt.Sprintf("%d", int64(new__28))+(")"))
																															} else {
																																if prop == 28 {
																																	var bin_old_29 []byte = []byte{ state.get_byte(payload[3 + 0]) }
																																	var old_29 uint8 = uint8((bin_old_29[0] << 0))
																																	var bin_new__29 []byte = []byte{ state.get_byte(payload[4 + 0]) }
																																	var new__29 uint8 = uint8((bin_new__29[0] << 0))
																																	fmt.Println(""+("property_changed(BreakoutGame0, lives, UInt8")+(", ")+fmt.Sprintf("%d", int64(old_29))+(", ")+fmt.Sprintf("%d", int64(new__29))+(")"))
																																} else {
																																	if prop == 29 {
																																		var bin_old []byte = []byte{ state.get_byte(payload[3 + 0]) }
																																		var old uint8 = uint8((bin_old[0] << 0))
																																		var bin_new_ []byte = []byte{ state.get_byte(payload[4 + 0]) }
																																		var new_ uint8 = uint8((bin_new_[0] << 0))
																																		fmt.Println(""+("property_changed(BreakoutGame0, level, UInt8")+(", ")+fmt.Sprintf("%d", int64(old))+(", ")+fmt.Sprintf("%d", int64(new_))+(")"))
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		} else {
			if log_type == LogType_message_lost {
				var portID_1 byte = state.get_byte(payload[2])
				var messageID_1 byte = state.get_byte(payload[3])
				if inst == 0 {
					if portID_1 == 1 && messageID_1 == 22 {
						var bin_id_1 []byte = []byte{ state.get_byte(payload[4 + 0]) }
						var id_1 uint8 = uint8((bin_id_1[0] << 0))
						fmt.Println(""+("message_lost(BreakoutGame0, clock, timer_timeout")+(", id=")+fmt.Sprintf("%d", int64(id_1))+(")"))
					} else {
						if portID_1 == 2 && messageID_1 == 16 {
							fmt.Println(""+("message_lost(BreakoutGame0, display, displayReady")+(")"))
						} else {
							if portID_1 == 3 && messageID_1 == 18 {
								var bin_x_3 []byte = []byte{ state.get_byte(payload[4 + 0]), state.get_byte(payload[4 + 1]) }
								var x_3 int16 = int16((bin_x_3[0] << 8 | bin_x_3[1] << 0))
								if  !(state.HAS_SIGNED_BYTE) {
									x_3 = x_3 + 256
								}
								var bin_y_3 []byte = []byte{ state.get_byte(payload[6 + 0]), state.get_byte(payload[6 + 1]) }
								var y_3 int16 = int16((bin_y_3[0] << 8 | bin_y_3[1] << 0))
								if  !(state.HAS_SIGNED_BYTE) {
									y_3 = y_3 + 256
								}
								fmt.Println(""+("message_lost(BreakoutGame0, controller, position")+(", x=")+fmt.Sprintf("%d", int64(x_3))+(", y=")+fmt.Sprintf("%d", int64(y_3))+(")"))
							} else {
								if portID_1 == 5 && messageID_1 == 1 {
									fmt.Println(""+("message_lost(BreakoutGame0, game, lostBall")+(")"))
								} else {
									if portID_1 == 7 && messageID_1 == 1 {
										fmt.Println(""+("message_lost(BreakoutGame0, pro_game, lostBall")+(")"))
									} else {
										if portID_1 == 5 && messageID_1 == 2 {
											fmt.Println(""+("message_lost(BreakoutGame0, game, nextLevel")+(")"))
										} else {
											if portID_1 == 7 && messageID_1 == 2 {
												fmt.Println(""+("message_lost(BreakoutGame0, pro_game, nextLevel")+(")"))
											}
										}
									}
								}
							}
						}
					}
				}
			} else {
				if log_type == LogType_message_sent {
					var portID_2 byte = state.get_byte(payload[2])
					var messageID_2 byte = state.get_byte(payload[3])
					if inst == 0 {
						if portID_2 == 1 && messageID_2 == 20 {
							var bin_id_2 []byte = []byte{ state.get_byte(payload[4 + 0]) }
							var id_2 uint8 = uint8((bin_id_2[0] << 0))
							var bin_time []byte = []byte{ state.get_byte(payload[5 + 0]), state.get_byte(payload[5 + 1]) }
							var time uint16 = uint16((bin_time[0] << 8 | bin_time[1] << 0))
							fmt.Println(""+("message_sent(BreakoutGame0, clock, timer_start")+(", id=")+fmt.Sprintf("%d", int64(id_2))+(", time=")+fmt.Sprintf("%d", int64(time))+(")"))
						} else {
							if portID_2 == 1 && messageID_2 == 21 {
								var bin_id_3 []byte = []byte{ state.get_byte(payload[4 + 0]) }
								var id_3 uint8 = uint8((bin_id_3[0] << 0))
								fmt.Println(""+("message_sent(BreakoutGame0, clock, timer_cancel")+(", id=")+fmt.Sprintf("%d", int64(id_3))+(")"))
							} else {
								if portID_2 == 2 && messageID_2 == 6 {
									fmt.Println(""+("message_sent(BreakoutGame0, display, clear")+(")"))
								} else {
									if portID_2 == 2 && messageID_2 == 7 {
										var bin_r_1 []byte = []byte{ state.get_byte(payload[4 + 0]) }
										var r_1 uint8 = uint8((bin_r_1[0] << 0))
										var bin_g_1 []byte = []byte{ state.get_byte(payload[5 + 0]) }
										var g_1 uint8 = uint8((bin_g_1[0] << 0))
										var bin_b_1 []byte = []byte{ state.get_byte(payload[6 + 0]) }
										var b_1 uint8 = uint8((bin_b_1[0] << 0))
										fmt.Println(""+("message_sent(BreakoutGame0, display, setColor")+(", r=")+fmt.Sprintf("%d", int64(r_1))+(", g=")+fmt.Sprintf("%d", int64(g_1))+(", b=")+fmt.Sprintf("%d", int64(b_1))+(")"))
									} else {
										if portID_2 == 2 && messageID_2 == 8 {
											var bin_r []byte = []byte{ state.get_byte(payload[4 + 0]) }
											var r uint8 = uint8((bin_r[0] << 0))
											var bin_g []byte = []byte{ state.get_byte(payload[5 + 0]) }
											var g uint8 = uint8((bin_g[0] << 0))
											var bin_b []byte = []byte{ state.get_byte(payload[6 + 0]) }
											var b uint8 = uint8((bin_b[0] << 0))
											fmt.Println(""+("message_sent(BreakoutGame0, display, setBGColor")+(", r=")+fmt.Sprintf("%d", int64(r))+(", g=")+fmt.Sprintf("%d", int64(g))+(", b=")+fmt.Sprintf("%d", int64(b))+(")"))
										} else {
											if portID_2 == 2 && messageID_2 == 9 {
												var bin_x_4 []byte = []byte{ state.get_byte(payload[4 + 0]) }
												var x_4 uint8 = uint8((bin_x_4[0] << 0))
												var bin_y_4 []byte = []byte{ state.get_byte(payload[5 + 0]) }
												var y_4 uint8 = uint8((bin_y_4[0] << 0))
												var bin_width_1 []byte = []byte{ state.get_byte(payload[6 + 0]) }
												var width_1 uint8 = uint8((bin_width_1[0] << 0))
												var bin_height_1 []byte = []byte{ state.get_byte(payload[7 + 0]) }
												var height_1 uint8 = uint8((bin_height_1[0] << 0))
												fmt.Println(""+("message_sent(BreakoutGame0, display, drawRect")+(", x=")+fmt.Sprintf("%d", int64(x_4))+(", y=")+fmt.Sprintf("%d", int64(y_4))+(", width=")+fmt.Sprintf("%d", int64(width_1))+(", height=")+fmt.Sprintf("%d", int64(height_1))+(")"))
											} else {
												if portID_2 == 2 && messageID_2 == 10 {
													var bin_x_5 []byte = []byte{ state.get_byte(payload[4 + 0]) }
													var x_5 uint8 = uint8((bin_x_5[0] << 0))
													var bin_y_5 []byte = []byte{ state.get_byte(payload[5 + 0]) }
													var y_5 uint8 = uint8((bin_y_5[0] << 0))
													var bin_width []byte = []byte{ state.get_byte(payload[6 + 0]) }
													var width uint8 = uint8((bin_width[0] << 0))
													var bin_height []byte = []byte{ state.get_byte(payload[7 + 0]) }
													var height uint8 = uint8((bin_height[0] << 0))
													fmt.Println(""+("message_sent(BreakoutGame0, display, fillRect")+(", x=")+fmt.Sprintf("%d", int64(x_5))+(", y=")+fmt.Sprintf("%d", int64(y_5))+(", width=")+fmt.Sprintf("%d", int64(width))+(", height=")+fmt.Sprintf("%d", int64(height))+(")"))
												} else {
													if portID_2 == 2 && messageID_2 == 11 {
														var bin_x_6 []byte = []byte{ state.get_byte(payload[4 + 0]) }
														var x_6 uint8 = uint8((bin_x_6[0] << 0))
														var bin_y_6 []byte = []byte{ state.get_byte(payload[5 + 0]) }
														var y_6 uint8 = uint8((bin_y_6[0] << 0))
														var bin_v []byte = []byte{ state.get_byte(payload[6 + 0]), state.get_byte(payload[6 + 1]) }
														var v int16 = int16((bin_v[0] << 8 | bin_v[1] << 0))
														if  !(state.HAS_SIGNED_BYTE) {
															v = v + 256
														}
														var bin_digits []byte = []byte{ state.get_byte(payload[8 + 0]) }
														var digits uint8 = uint8((bin_digits[0] << 0))
														var bin_scale []byte = []byte{ state.get_byte(payload[9 + 0]) }
														var scale uint8 = uint8((bin_scale[0] << 0))
														fmt.Println(""+("message_sent(BreakoutGame0, display, drawInteger")+(", x=")+fmt.Sprintf("%d", int64(x_6))+(", y=")+fmt.Sprintf("%d", int64(y_6))+(", v=")+fmt.Sprintf("%d", int64(v))+(", digits=")+fmt.Sprintf("%d", int64(digits))+(", scale=")+fmt.Sprintf("%d", int64(scale))+(")"))
													} else {
														if portID_2 == 2 && messageID_2 == 12 {
															var bin_x_7 []byte = []byte{ state.get_byte(payload[4 + 0]) }
															var x_7 uint8 = uint8((bin_x_7[0] << 0))
															var bin_y_7 []byte = []byte{ state.get_byte(payload[5 + 0]) }
															var y_7 uint8 = uint8((bin_y_7[0] << 0))
															fmt.Println(""+("message_sent(BreakoutGame0, display, drawThingML")+(", x=")+fmt.Sprintf("%d", int64(x_7))+(", y=")+fmt.Sprintf("%d", int64(y_7))+(")"))
														} else {
															if portID_2 == 2 && messageID_2 == 13 {
																var bin_xsize []byte = []byte{ state.get_byte(payload[4 + 0]) }
																var xsize uint8 = uint8((bin_xsize[0] << 0))
																var bin_ysize []byte = []byte{ state.get_byte(payload[5 + 0]) }
																var ysize uint8 = uint8((bin_ysize[0] << 0))
																fmt.Println(""+("message_sent(BreakoutGame0, display, create")+(", xsize=")+fmt.Sprintf("%d", int64(xsize))+(", ysize=")+fmt.Sprintf("%d", int64(ysize))+(")"))
															} else {
																if portID_2 == 2 && messageID_2 == 15 {
																	fmt.Println(""+("message_sent(BreakoutGame0, display, update")+(")"))
																} else {
																	if portID_2 == 4 && messageID_2 == 19 {
																		var bin_ballx []byte = []byte{ state.get_byte(payload[4 + 0]), state.get_byte(payload[4 + 1]) }
																		var ballx int16 = int16((bin_ballx[0] << 8 | bin_ballx[1] << 0))
																		if  !(state.HAS_SIGNED_BYTE) {
																			ballx = ballx + 256
																		}
																		var bin_bally []byte = []byte{ state.get_byte(payload[6 + 0]), state.get_byte(payload[6 + 1]) }
																		var bally int16 = int16((bin_bally[0] << 8 | bin_bally[1] << 0))
																		if  !(state.HAS_SIGNED_BYTE) {
																			bally = bally + 256
																		}
																		var bin_padx []byte = []byte{ state.get_byte(payload[8 + 0]), state.get_byte(payload[8 + 1]) }
																		var padx int16 = int16((bin_padx[0] << 8 | bin_padx[1] << 0))
																		if  !(state.HAS_SIGNED_BYTE) {
																			padx = padx + 256
																		}
																		var bin_pady []byte = []byte{ state.get_byte(payload[10 + 0]), state.get_byte(payload[10 + 1]) }
																		var pady int16 = int16((bin_pady[0] << 8 | bin_pady[1] << 0))
																		if  !(state.HAS_SIGNED_BYTE) {
																			pady = pady + 256
																		}
																		fmt.Println(""+("message_sent(BreakoutGame0, ia, updateIA")+(", ballx=")+fmt.Sprintf("%d", int64(ballx))+(", bally=")+fmt.Sprintf("%d", int64(bally))+(", padx=")+fmt.Sprintf("%d", int64(padx))+(", pady=")+fmt.Sprintf("%d", int64(pady))+(")"))
																	} else {
																		if portID_2 == 5 && messageID_2 == 1 {
																			fmt.Println(""+("message_sent(BreakoutGame0, game, lostBall")+(")"))
																		} else {
																			if portID_2 == 6 && messageID_2 == 1 {
																				fmt.Println(""+("message_sent(BreakoutGame0, req_game, lostBall")+(")"))
																			} else {
																				if portID_2 == 5 && messageID_2 == 2 {
																					fmt.Println(""+("message_sent(BreakoutGame0, game, nextLevel")+(")"))
																				} else {
																					if portID_2 == 6 && messageID_2 == 2 {
																						fmt.Println(""+("message_sent(BreakoutGame0, req_game, nextLevel")+(")"))
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				} else {
					if log_type == LogType_message_handled {
						var portID byte = state.get_byte(payload[2])
						var messageID byte = state.get_byte(payload[3])
						var sourceID byte = state.get_byte(payload[4])
						var targetID byte = state.get_byte(payload[5])
						if inst == 0 {
							if portID == 1 && messageID == 22 {
								var bin_id []byte = []byte{ state.get_byte(payload[6 + 0]) }
								var id uint8 = uint8((bin_id[0] << 0))
								fmt.Println(""+("message_handled(BreakoutGame0, clock, timer_timeout, ")+(state.stateName(sourceID))+(", ")+(state.stateName(targetID))+(", id=")+fmt.Sprintf("%d", int64(id))+(")"))
							} else {
								if portID == 2 && messageID == 16 {
									fmt.Println(""+("message_handled(BreakoutGame0, display, displayReady, ")+(state.stateName(sourceID))+(", ")+(state.stateName(targetID))+(")"))
								} else {
									if portID == 3 && messageID == 18 {
										var bin_x []byte = []byte{ state.get_byte(payload[6 + 0]), state.get_byte(payload[6 + 1]) }
										var x int16 = int16((bin_x[0] << 8 | bin_x[1] << 0))
										if  !(state.HAS_SIGNED_BYTE) {
											x = x + 256
										}
										var bin_y []byte = []byte{ state.get_byte(payload[8 + 0]), state.get_byte(payload[8 + 1]) }
										var y int16 = int16((bin_y[0] << 8 | bin_y[1] << 0))
										if  !(state.HAS_SIGNED_BYTE) {
											y = y + 256
										}
										fmt.Println(""+("message_handled(BreakoutGame0, controller, position, ")+(state.stateName(sourceID))+(", ")+(state.stateName(targetID))+(", x=")+fmt.Sprintf("%d", int64(x))+(", y=")+fmt.Sprintf("%d", int64(y))+(")"))
									} else {
										if portID == 5 && messageID == 1 {
											fmt.Println(""+("message_handled(BreakoutGame0, game, lostBall, ")+(state.stateName(sourceID))+(", ")+(state.stateName(targetID))+(")"))
										} else {
											if portID == 7 && messageID == 1 {
												fmt.Println(""+("message_handled(BreakoutGame0, pro_game, lostBall, ")+(state.stateName(sourceID))+(", ")+(state.stateName(targetID))+(")"))
											} else {
												if portID == 5 && messageID == 2 {
													fmt.Println(""+("message_handled(BreakoutGame0, game, nextLevel, ")+(state.stateName(sourceID))+(", ")+(state.stateName(targetID))+(")"))
												} else {
													if portID == 7 && messageID == 2 {
														fmt.Println(""+("message_handled(BreakoutGame0, pro_game, nextLevel, ")+(state.stateName(sourceID))+(", ")+(state.stateName(targetID))+(")"))
													}
												}
											}
										}
									}
								}
							}
						}
					} else {
						fmt.Println(""+("unknown"))
					}
				}
			}
		}
	}
}
/* -- States -- */
type FragmentLoggerStateChart struct {
	 gosm.CompositeState
	 *ThingBinary2StringLogger
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
		if d := typedMessage; port == Binary2StringLogger_Logger_log {
			return true, true, state, func() {
				state.do_log(d.Payload, d.Size)
			}
		}
	case FragmentLogMsgsMsglog_off:
		if port == Binary2StringLogger_Logger_log {
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
		if port == Binary2StringLogger_Logger_log {
			return true, false, state.FragmentLoggerStateChartStateON, nil
			
		}
	}
	return false, false, state, nil
}
func (state *FragmentLoggerStateChartStateOFF) OnExit() {}

/* -- Instance Constructor -- */
func NewThingBinary2StringLogger()  *ThingBinary2StringLogger {
	/* Create instance struct */
	instance := &ThingBinary2StringLogger{}
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
	stateFragmentLoggerStateChart.ThingBinary2StringLogger = instance
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

func cloneThingBinary2StringLogger(original *ThingBinary2StringLogger)  *ThingBinary2StringLogger {
	clone := &ThingBinary2StringLogger{
		ACTIVATE_ON_STARTUP: original.ACTIVATE_ON_STARTUP,
		HAS_SIGNED_BYTE: original.HAS_SIGNED_BYTE,
	}
	return clone
}
/* -- Session forks -- */
