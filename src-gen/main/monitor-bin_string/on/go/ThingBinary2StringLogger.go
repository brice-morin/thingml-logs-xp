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
										fmt.Println(""+("function_called(BreakoutGame0, drawCountDown, void")+(", _")+(", c=")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[2]) << 8 | state.get_byte(payload[3]) << 0)))))+(")"))
									} else {
										if func_ == 8 {
											fmt.Println(""+("function_called(BreakoutGame0, drawWalls, void")+(", _")+(")"))
										} else {
											if func_ == 9 {
												fmt.Println(""+("function_called(BreakoutGame0, bitIsSet, Boolean")+(", ")+fmt.Sprintf("%t", (int16((state.get_byte(payload[4]) << 0)) != 0))+(", variable=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[2]) << 0)))))+(", bit=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[3]) << 0)))))+(")"))
											} else {
												if func_ == 10 {
													fmt.Println(""+("function_called(BreakoutGame0, createBricks, void")+(", _")+(")"))
												} else {
													if func_ == 11 {
														fmt.Println(""+("function_called(BreakoutGame0, bricksLeft, UInt8")+(", ")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[2]) << 0)))))+(")"))
													} else {
														if func_ == 12 {
															fmt.Println(""+("function_called(BreakoutGame0, drawBrick, void")+(", _")+(", x=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[2]) << 0)))))+(", y=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[3]) << 0)))))+(")"))
														} else {
															if func_ == 13 {
																fmt.Println(""+("function_called(BreakoutGame0, removeBrick, void")+(", _")+(", x=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[2]) << 0)))))+(", y=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[3]) << 0)))))+(")"))
															} else {
																if func_ == 14 {
																	fmt.Println(""+("function_called(BreakoutGame0, collideBrick, Boolean")+(", ")+fmt.Sprintf("%t", (int16((state.get_byte(payload[6]) << 0)) != 0))+(", xpos=")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[2]) << 8 | state.get_byte(payload[3]) << 0)))))+(", ypos=")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[4]) << 8 | state.get_byte(payload[5]) << 0)))))+(")"))
																} else {
																	if func_ == 15 {
																		fmt.Println(""+("function_called(BreakoutGame0, drawLevel, void")+(", _")+(")"))
																	} else {
																		if func_ == 16 {
																			fmt.Println(""+("function_called(BreakoutGame0, incrementScore, void")+(", _")+(", diff=")+fmt.Sprintf("%d", int64((int8((state.get_byte(payload[2]) << 0)))))+(")"))
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
					fmt.Println(""+("property_changed(BreakoutGame0, XDISPSIZE, UInt8")+(", ")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[3]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[4]) << 0)))))+(")"))
				} else {
					if prop == 1 {
						fmt.Println(""+("property_changed(BreakoutGame0, YDISPSIZE, UInt8")+(", ")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[3]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[4]) << 0)))))+(")"))
					} else {
						if prop == 2 {
							fmt.Println(""+("property_changed(BreakoutGame0, SCALE, Int16")+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[3]) << 8 | state.get_byte(payload[4]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[5]) << 8 | state.get_byte(payload[6]) << 0)))))+(")"))
						} else {
							if prop == 3 {
								fmt.Println(""+("property_changed(BreakoutGame0, XMAX, Int16")+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[3]) << 8 | state.get_byte(payload[4]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[5]) << 8 | state.get_byte(payload[6]) << 0)))))+(")"))
							} else {
								if prop == 4 {
									fmt.Println(""+("property_changed(BreakoutGame0, YMAX, Int16")+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[3]) << 8 | state.get_byte(payload[4]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[5]) << 8 | state.get_byte(payload[6]) << 0)))))+(")"))
								} else {
									if prop == 5 {
										fmt.Println(""+("property_changed(BreakoutGame0, TOP, Int16")+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[3]) << 8 | state.get_byte(payload[4]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[5]) << 8 | state.get_byte(payload[6]) << 0)))))+(")"))
									} else {
										if prop == 6 {
											fmt.Println(""+("property_changed(BreakoutGame0, BOTTOM, Int16")+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[3]) << 8 | state.get_byte(payload[4]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[5]) << 8 | state.get_byte(payload[6]) << 0)))))+(")"))
										} else {
											if prop == 7 {
												fmt.Println(""+("property_changed(BreakoutGame0, LEFT, Int16")+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[3]) << 8 | state.get_byte(payload[4]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[5]) << 8 | state.get_byte(payload[6]) << 0)))))+(")"))
											} else {
												if prop == 8 {
													fmt.Println(""+("property_changed(BreakoutGame0, RIGHT, Int16")+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[3]) << 8 | state.get_byte(payload[4]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[5]) << 8 | state.get_byte(payload[6]) << 0)))))+(")"))
												} else {
													if prop == 9 {
														fmt.Println(""+("property_changed(BreakoutGame0, br, Int16")+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[3]) << 8 | state.get_byte(payload[4]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[5]) << 8 | state.get_byte(payload[6]) << 0)))))+(")"))
													} else {
														if prop == 10 {
															fmt.Println(""+("property_changed(BreakoutGame0, bx, Int16")+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[3]) << 8 | state.get_byte(payload[4]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[5]) << 8 | state.get_byte(payload[6]) << 0)))))+(")"))
														} else {
															if prop == 11 {
																fmt.Println(""+("property_changed(BreakoutGame0, by, Int16")+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[3]) << 8 | state.get_byte(payload[4]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[5]) << 8 | state.get_byte(payload[6]) << 0)))))+(")"))
															} else {
																if prop == 12 {
																	fmt.Println(""+("property_changed(BreakoutGame0, dx, Int16")+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[3]) << 8 | state.get_byte(payload[4]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[5]) << 8 | state.get_byte(payload[6]) << 0)))))+(")"))
																} else {
																	if prop == 13 {
																		fmt.Println(""+("property_changed(BreakoutGame0, dy, Int16")+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[3]) << 8 | state.get_byte(payload[4]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[5]) << 8 | state.get_byte(payload[6]) << 0)))))+(")"))
																	} else {
																		if prop == 14 {
																			fmt.Println(""+("property_changed(BreakoutGame0, padx, Int16")+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[3]) << 8 | state.get_byte(payload[4]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[5]) << 8 | state.get_byte(payload[6]) << 0)))))+(")"))
																		} else {
																			if prop == 15 {
																				fmt.Println(""+("property_changed(BreakoutGame0, pady, Int16")+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[3]) << 8 | state.get_byte(payload[4]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[5]) << 8 | state.get_byte(payload[6]) << 0)))))+(")"))
																			} else {
																				if prop == 16 {
																					fmt.Println(""+("property_changed(BreakoutGame0, padlen, Int16")+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[3]) << 8 | state.get_byte(payload[4]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[5]) << 8 | state.get_byte(payload[6]) << 0)))))+(")"))
																				} else {
																					if prop == 17 {
																						fmt.Println(""+("property_changed(BreakoutGame0, prevBX, Int16")+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[3]) << 8 | state.get_byte(payload[4]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[5]) << 8 | state.get_byte(payload[6]) << 0)))))+(")"))
																					} else {
																						if prop == 18 {
																							fmt.Println(""+("property_changed(BreakoutGame0, prevBY, Int16")+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[3]) << 8 | state.get_byte(payload[4]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[5]) << 8 | state.get_byte(payload[6]) << 0)))))+(")"))
																						} else {
																							if prop == 19 {
																								fmt.Println(""+("property_changed(BreakoutGame0, bgcolor, UInt8")+(", ")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[3]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[4]) << 0)))))+(")"))
																							} else {
																								if prop == 20 {
																									fmt.Println(""+("property_changed(BreakoutGame0, fgcolor, UInt8")+(", ")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[3]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[4]) << 0)))))+(")"))
																								} else {
																									if prop == 21 {
																										fmt.Println(""+("property_changed(BreakoutGame0, period, UInt16")+(", ")+fmt.Sprintf("%d", int64((uint16((state.get_byte(payload[3]) << 8 | state.get_byte(payload[4]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((uint16((state.get_byte(payload[5]) << 8 | state.get_byte(payload[6]) << 0)))))+(")"))
																									} else {
																										if prop == 22 {
																											fmt.Println(""+("property_changed(BreakoutGame0, prevPX, Int16")+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[3]) << 8 | state.get_byte(payload[4]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[5]) << 8 | state.get_byte(payload[6]) << 0)))))+(")"))
																										} else {
																											if prop == 23 {
																												fmt.Println(""+("property_changed(BreakoutGame0, prevPY, Int16")+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[3]) << 8 | state.get_byte(payload[4]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[5]) << 8 | state.get_byte(payload[6]) << 0)))))+(")"))
																											} else {
																												if prop == 24 {
																													fmt.Println(""+("property_changed(BreakoutGame0, BRICK_ROWS, UInt8")+(", ")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[3]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[4]) << 0)))))+(")"))
																												} else {
																													if prop == 25 {
																														fmt.Println(""+("property_changed(BreakoutGame0, BRICK_HEIGHT, UInt8")+(", ")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[3]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[4]) << 0)))))+(")"))
																													} else {
																														if prop == 26 {
																															fmt.Println(""+("property_changed(BreakoutGame0, bricks, UInt8")+(", ")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[3]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[4]) << 0)))))+(")"))
																														} else {
																															if prop == 27 {
																																fmt.Println(""+("property_changed(BreakoutGame0, score, Int16")+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[3]) << 8 | state.get_byte(payload[4]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[5]) << 8 | state.get_byte(payload[6]) << 0)))))+(")"))
																															} else {
																																if prop == 28 {
																																	fmt.Println(""+("property_changed(BreakoutGame0, lives, UInt8")+(", ")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[3]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[4]) << 0)))))+(")"))
																																} else {
																																	if prop == 29 {
																																		fmt.Println(""+("property_changed(BreakoutGame0, level, UInt8")+(", ")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[3]) << 0)))))+(", ")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[4]) << 0)))))+(")"))
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
					if portID_1 == 0 && messageID_1 == 21 {
						fmt.Println(""+("message_lost(BreakoutGame0, clock, timer_timeout")+(", id=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[4]) << 0)))))+(")"))
					} else {
						if portID_1 == 1 && messageID_1 == 15 {
							fmt.Println(""+("message_lost(BreakoutGame0, display, displayReady")+(")"))
						} else {
							if portID_1 == 2 && messageID_1 == 17 {
								fmt.Println(""+("message_lost(BreakoutGame0, controller, position")+(", x=")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[4]) << 8 | state.get_byte(payload[5]) << 0)))))+(", y=")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[6]) << 8 | state.get_byte(payload[7]) << 0)))))+(")"))
							} else {
								if portID_1 == 4 && messageID_1 == 0 {
									fmt.Println(""+("message_lost(BreakoutGame0, game, lostBall")+(")"))
								} else {
									if portID_1 == 6 && messageID_1 == 0 {
										fmt.Println(""+("message_lost(BreakoutGame0, pro_game, lostBall")+(")"))
									} else {
										if portID_1 == 4 && messageID_1 == 1 {
											fmt.Println(""+("message_lost(BreakoutGame0, game, nextLevel")+(")"))
										} else {
											if portID_1 == 6 && messageID_1 == 1 {
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
					var portID byte = state.get_byte(payload[2])
					var messageID byte = state.get_byte(payload[3])
					if inst == 0 {
						if portID == 0 && messageID == 19 {
							fmt.Println(""+("message_sent(BreakoutGame0, clock, timer_start")+(", id=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[4]) << 0)))))+(", time=")+fmt.Sprintf("%d", int64((uint16((state.get_byte(payload[5]) << 8 | state.get_byte(payload[6]) << 0)))))+(")"))
						} else {
							if portID == 0 && messageID == 20 {
								fmt.Println(""+("message_sent(BreakoutGame0, clock, timer_cancel")+(", id=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[4]) << 0)))))+(")"))
							} else {
								if portID == 1 && messageID == 5 {
									fmt.Println(""+("message_sent(BreakoutGame0, display, clear")+(")"))
								} else {
									if portID == 1 && messageID == 6 {
										fmt.Println(""+("message_sent(BreakoutGame0, display, setColor")+(", r=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[4]) << 0)))))+(", g=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[5]) << 0)))))+(", b=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[6]) << 0)))))+(")"))
									} else {
										if portID == 1 && messageID == 7 {
											fmt.Println(""+("message_sent(BreakoutGame0, display, setBGColor")+(", r=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[4]) << 0)))))+(", g=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[5]) << 0)))))+(", b=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[6]) << 0)))))+(")"))
										} else {
											if portID == 1 && messageID == 8 {
												fmt.Println(""+("message_sent(BreakoutGame0, display, drawRect")+(", x=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[4]) << 0)))))+(", y=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[5]) << 0)))))+(", width=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[6]) << 0)))))+(", height=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[7]) << 0)))))+(")"))
											} else {
												if portID == 1 && messageID == 9 {
													fmt.Println(""+("message_sent(BreakoutGame0, display, fillRect")+(", x=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[4]) << 0)))))+(", y=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[5]) << 0)))))+(", width=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[6]) << 0)))))+(", height=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[7]) << 0)))))+(")"))
												} else {
													if portID == 1 && messageID == 10 {
														fmt.Println(""+("message_sent(BreakoutGame0, display, drawInteger")+(", x=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[4]) << 0)))))+(", y=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[5]) << 0)))))+(", v=")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[6]) << 8 | state.get_byte(payload[7]) << 0)))))+(", digits=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[8]) << 0)))))+(", scale=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[9]) << 0)))))+(")"))
													} else {
														if portID == 1 && messageID == 11 {
															fmt.Println(""+("message_sent(BreakoutGame0, display, drawThingML")+(", x=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[4]) << 0)))))+(", y=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[5]) << 0)))))+(")"))
														} else {
															if portID == 1 && messageID == 12 {
																fmt.Println(""+("message_sent(BreakoutGame0, display, create")+(", xsize=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[4]) << 0)))))+(", ysize=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[5]) << 0)))))+(")"))
															} else {
																if portID == 1 && messageID == 14 {
																	fmt.Println(""+("message_sent(BreakoutGame0, display, update")+(")"))
																} else {
																	if portID == 3 && messageID == 18 {
																		fmt.Println(""+("message_sent(BreakoutGame0, ia, updateIA")+(", ballx=")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[4]) << 8 | state.get_byte(payload[5]) << 0)))))+(", bally=")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[6]) << 8 | state.get_byte(payload[7]) << 0)))))+(", padx=")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[8]) << 8 | state.get_byte(payload[9]) << 0)))))+(", pady=")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[10]) << 8 | state.get_byte(payload[11]) << 0)))))+(")"))
																	} else {
																		if portID == 4 && messageID == 0 {
																			fmt.Println(""+("message_sent(BreakoutGame0, game, lostBall")+(")"))
																		} else {
																			if portID == 5 && messageID == 0 {
																				fmt.Println(""+("message_sent(BreakoutGame0, req_game, lostBall")+(")"))
																			} else {
																				if portID == 4 && messageID == 1 {
																					fmt.Println(""+("message_sent(BreakoutGame0, game, nextLevel")+(")"))
																				} else {
																					if portID == 5 && messageID == 1 {
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
						var handlerID byte = state.get_byte(payload[2])
						if inst == 0 {
							if handlerID == 0 {
								fmt.Println(""+("message_handled(BreakoutGame0, controller, position, SC, _, ")+(", x=")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[3]) << 8 | state.get_byte(payload[4]) << 0)))))+(", y=")+fmt.Sprintf("%d", int64((int16((state.get_byte(payload[5]) << 8 | state.get_byte(payload[6]) << 0)))))+(")"))
							} else {
								if handlerID == 1 {
									fmt.Println(""+("message_handled(BreakoutGame0, display, displayReady, INIT, LAUNCH, ")+(")"))
								} else {
									if handlerID == 2 {
										fmt.Println(""+("message_handled(BreakoutGame0, clock, timer_timeout, LAUNCH, _, ")+(", id=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[3]) << 0)))))+(")"))
									} else {
										if handlerID == 3 {
											fmt.Println(""+("message_handled(BreakoutGame0, clock, timer_timeout, LAUNCH, PLAY, ")+(", id=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[3]) << 0)))))+(")"))
										} else {
											if handlerID == 4 {
												fmt.Println(""+("message_handled(BreakoutGame0, clock, timer_timeout, PLAY, _, ")+(", id=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[3]) << 0)))))+(")"))
											} else {
												if handlerID == 5 {
													fmt.Println(""+("message_handled(BreakoutGame0, game, lostBall, PLAY, LOSTBALL, ")+(")"))
												} else {
													if handlerID == 6 {
														fmt.Println(""+("message_handled(BreakoutGame0, game, nextLevel, PLAY, NEXTLEVEL, ")+(")"))
													} else {
														if handlerID == 7 {
															fmt.Println(""+("message_handled(BreakoutGame0, pro_game, lostBall, PLAY, LOSTBALL, ")+(")"))
														} else {
															if handlerID == 8 {
																fmt.Println(""+("message_handled(BreakoutGame0, pro_game, nextLevel, PLAY, NEXTLEVEL, ")+(")"))
															} else {
																if handlerID == 9 {
																	fmt.Println(""+("message_handled(BreakoutGame0, clock, timer_timeout, LOSTBALL, LAUNCH, ")+(", id=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[3]) << 0)))))+(")"))
																} else {
																	if handlerID == 10 {
																		fmt.Println(""+("message_handled(BreakoutGame0, clock, timer_timeout, LOSTBALL, GAMEOVER, ")+(", id=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[3]) << 0)))))+(")"))
																	} else {
																		if handlerID == 11 {
																			fmt.Println(""+("message_handled(BreakoutGame0, clock, timer_timeout, NEXTLEVEL, LAUNCH, ")+(", id=")+fmt.Sprintf("%d", int64((uint8((state.get_byte(payload[3]) << 0)))))+(")"))
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
