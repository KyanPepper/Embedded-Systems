#ifndef _TOOLSLEDSOLUTION_MAIN_H
#define _TOOLSLEDSOLUTION_MAIN_H
#include "include/core/reactor.h"
#include "_led.h"
#ifndef TOP_LEVEL_PREAMBLE_1558460059_H
#define TOP_LEVEL_PREAMBLE_1558460059_H
#include <pico/stdlib.h>
#endif // TOP_LEVEL_PREAMBLE_1558460059_H
typedef struct {
    struct self_base_t base;
#line 12 "/Users/kyankotschevar-smead/Desktop/Projects/Embedded-Systems/lab1/src-gen/ToolsLEDSolution/_toolsledsolution_main.h"
    #line 14 "/Users/kyankotschevar-smead/Desktop/Projects/Embedded-Systems/lab1/src/ToolsLEDSolution.lf"
    bool led_on;
    #line 15 "/Users/kyankotschevar-smead/Desktop/Projects/Embedded-Systems/lab1/src/ToolsLEDSolution.lf"
    int blink_count;
    #line 16 "/Users/kyankotschevar-smead/Desktop/Projects/Embedded-Systems/lab1/src/ToolsLEDSolution.lf"
    int target_blinks;
    #line 17 "/Users/kyankotschevar-smead/Desktop/Projects/Embedded-Systems/lab1/src/ToolsLEDSolution.lf"
    bool in_pause;
    #line 18 "/Users/kyankotschevar-smead/Desktop/Projects/Embedded-Systems/lab1/src/ToolsLEDSolution.lf"
    int pause_ticks;
#line 23 "/Users/kyankotschevar-smead/Desktop/Projects/Embedded-Systems/lab1/src-gen/ToolsLEDSolution/_toolsledsolution_main.h"
    struct {
        _led_set_t set;
    } _lf_led;
    int _lf_led_width;
    reaction_t _lf__reaction_0;
    trigger_t _lf__t;
    reaction_t* _lf__t_reactions[1];
} _toolsledsolution_main_main_self_t;
_toolsledsolution_main_main_self_t* new__toolsledsolution_main();
#endif // _TOOLSLEDSOLUTION_MAIN_H
