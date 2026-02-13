#ifndef _LED_H
#define _LED_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_1842173497_H
#define TOP_LEVEL_PREAMBLE_1842173497_H
#include <pico/stdlib.h>
#endif // TOP_LEVEL_PREAMBLE_1842173497_H
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _led_set_t;
typedef struct {
    struct self_base_t base;
#line 25 "/Users/kyankotschevar-smead/Desktop/Projects/Embedded-Systems/lab1/src-gen/ToolsLEDSolution/_led.h"
#line 26 "/Users/kyankotschevar-smead/Desktop/Projects/Embedded-Systems/lab1/src-gen/ToolsLEDSolution/_led.h"
    _led_set_t* _lf_set;
    // width of -2 indicates that it is not a multiport.
    int _lf_set_width;
    // Default input (in case it does not get connected)
    _led_set_t _lf_default__set;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    trigger_t _lf__set;
    reaction_t* _lf__set_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _led_self_t;
_led_self_t* new__led();
#endif // _LED_H
