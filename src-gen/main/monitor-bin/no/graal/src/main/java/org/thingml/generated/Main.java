/**
 * File generated by the ThingML IDE
 * /!\Do not edit this file/!\
 * In case of a bug in the generated code,
 * please submit an issue on our GitHub
 **/

package org.thingml.generated;

import no.sintef.jasm.*;
import no.sintef.jasm.ext.*;

import org.thingml.generated.api.*;
import org.thingml.generated.messages.*;

import java.util.*;
public class Main {
//Things
public static BreakoutGameJava BreakoutGameJava_game;
public static TimerJava TimerJava_timer;
public static BasicIAController BasicIAController_ctrl;
public static HeadlessDisplay HeadlessDisplay_disp;
public static void main(String args[]) {
//Things
BreakoutGameJava_game = (BreakoutGameJava) new BreakoutGameJava();
BreakoutGameJava_game.buildBehavior(null, null);
BreakoutGameJava_game.init();
TimerJava_timer = (TimerJava) new TimerJava();
TimerJava_timer.buildBehavior(null, null);
TimerJava_timer.init();
BasicIAController_ctrl = (BasicIAController) new BasicIAController();
BasicIAController_ctrl.buildBehavior(null, null);
BasicIAController_ctrl.init();
HeadlessDisplay_disp = (HeadlessDisplay) new HeadlessDisplay();
HeadlessDisplay_disp.buildBehavior(null, null);
HeadlessDisplay_disp.init();
//Connecting internal ports...
BreakoutGameJava_game.getGame_port().addListener(BreakoutGameJava_game.getGame_port());
//Connectors
BreakoutGameJava_game.getIa_port().addListener(BasicIAController_ctrl.getGame_port());
HeadlessDisplay_disp.getDisplay_port().addListener(BreakoutGameJava_game.getDisplay_port());
BreakoutGameJava_game.getDisplay_port().addListener(HeadlessDisplay_disp.getDisplay_port());
TimerJava_timer.getTimer_port().addListener(BreakoutGameJava_game.getClock_port());
BreakoutGameJava_game.getClock_port().addListener(TimerJava_timer.getTimer_port());
BasicIAController_ctrl.getControls_port().addListener(BreakoutGameJava_game.getController_port());
final int[] game_fgcolor_array = new int[3];
final int[] game_bricks_array = new int[5];
final int[] game_bgcolor_array = new int[3];
BreakoutGameJava_game.initBreakoutGame_QUIET_var((boolean) (true));
BreakoutGameJava_game.initBreakoutGame_startTime_var((long)0);
BreakoutGameJava_game.initBreakoutGame_stopTime_var((long)0);
BreakoutGameJava_game.initBreakoutGame_lastTimestamp_var((long) (0));
BreakoutGameJava_game.initBreakoutGame_counter_var((int) (0));
BreakoutGameJava_game.initBreakoutGame_XDISPSIZE_var((int) (160));
BreakoutGameJava_game.initBreakoutGame_YDISPSIZE_var((int) (128));
BreakoutGameJava_game.initBreakoutGame_SCALE_var((int) (64));
BreakoutGameJava_game.initBreakoutGame_XMAX_var((int) (160 * 64));
BreakoutGameJava_game.initBreakoutGame_YMAX_var((int) (128 * 64));
BreakoutGameJava_game.initBreakoutGame_TOP_var((int) (14 * 64));
BreakoutGameJava_game.initBreakoutGame_BOTTOM_var((int) (128 * 64 + 8 * 64));
BreakoutGameJava_game.initBreakoutGame_LEFT_var((int) (1 * 64));
BreakoutGameJava_game.initBreakoutGame_RIGHT_var((int) (160 * 64 - 1 * 64));
BreakoutGameJava_game.initBreakoutGame_br_var((int) (3 * 64));
BreakoutGameJava_game.initBreakoutGame_bx_var((int) (160 * 64 / 2));
BreakoutGameJava_game.initBreakoutGame_by_var((int) (128 * 64));
BreakoutGameJava_game.initBreakoutGame_dx_var((int) (160 * 64 / 98));
BreakoutGameJava_game.initBreakoutGame_dy_var((int) ( -160 * 64 / 65));
BreakoutGameJava_game.initBreakoutGame_padx_var((int) (128 * 64 / 2));
BreakoutGameJava_game.initBreakoutGame_pady_var((int) (128 * 64 - 6 * 64));
BreakoutGameJava_game.initBreakoutGame_padlen_var((int) (25 * 64));
BreakoutGameJava_game.initBreakoutGame_prevBX_var((int) ( -1));
BreakoutGameJava_game.initBreakoutGame_prevBY_var((int) ( -1));
BreakoutGameJava_game.initBreakoutGame_period_var((int) (3));
BreakoutGameJava_game.initBreakoutGame_prevPX_var((int) ( -1));
BreakoutGameJava_game.initBreakoutGame_prevPY_var((int) ( -1));
BreakoutGameJava_game.initBreakoutGame_BRICK_ROWS_var((int) (5));
BreakoutGameJava_game.initBreakoutGame_BRICK_HEIGHT_var((int) (9));
BreakoutGameJava_game.initBreakoutGame_score_var((int) (0));
BreakoutGameJava_game.initBreakoutGame_lives_var((int) (3));
BreakoutGameJava_game.initBreakoutGame_level_var((int) (1));
BreakoutGameJava_game.initBreakoutGame_SC_LAUNCH_countdown_var((int)0);
BreakoutGameJava_game.initBreakoutGame_fgcolor_var(game_fgcolor_array);
BreakoutGameJava_game.initBreakoutGame_bricks_var(game_bricks_array);
BreakoutGameJava_game.initBreakoutGame_bgcolor_var(game_bgcolor_array);
BasicIAController_ctrl.initBasicIAController_ctrlx_var((int) (0));
//Network components for external connectors
/*$NETWORK$*/
//External Connectors
/*$EXT CONNECTORS$*/
/*$START$*/
HeadlessDisplay_disp.start();
TimerJava_timer.start();
BasicIAController_ctrl.start();
BreakoutGameJava_game.start();
//Hook to stop instances following client/server dependencies (clients firsts)
Runtime.getRuntime().addShutdownHook(new Thread() {
public void run() {
BreakoutGameJava_game.stop();
BasicIAController_ctrl.stop();
TimerJava_timer.stop();
HeadlessDisplay_disp.stop();
/*$STOP$*/
}
});

}
}
