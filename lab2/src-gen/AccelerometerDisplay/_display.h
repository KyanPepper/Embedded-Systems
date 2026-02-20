#ifndef _DISPLAY_H
#define _DISPLAY_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_627746290_H
#define TOP_LEVEL_PREAMBLE_627746290_H
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif // TOP_LEVEL_PREAMBLE_627746290_H
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _display_line0_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _display_line1_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _display_line2_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _display_line3_t;
typedef struct {
    struct self_base_t base;
#line 68 "/home/masonmenser/Embedded-Systems/lab2/src-gen/AccelerometerDisplay/_display.h"
#line 69 "/home/masonmenser/Embedded-Systems/lab2/src-gen/AccelerometerDisplay/_display.h"
    _display_line0_t* _lf_line0;
    // width of -2 indicates that it is not a multiport.
    int _lf_line0_width;
    // Default input (in case it does not get connected)
    _display_line0_t _lf_default__line0;
    _display_line1_t* _lf_line1;
    // width of -2 indicates that it is not a multiport.
    int _lf_line1_width;
    // Default input (in case it does not get connected)
    _display_line1_t _lf_default__line1;
    _display_line2_t* _lf_line2;
    // width of -2 indicates that it is not a multiport.
    int _lf_line2_width;
    // Default input (in case it does not get connected)
    _display_line2_t _lf_default__line2;
    _display_line3_t* _lf_line3;
    // width of -2 indicates that it is not a multiport.
    int _lf_line3_width;
    // Default input (in case it does not get connected)
    _display_line3_t _lf_default__line3;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    trigger_t _lf__line0;
    reaction_t* _lf__line0_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    trigger_t _lf__line1;
    reaction_t* _lf__line1_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    trigger_t _lf__line2;
    reaction_t* _lf__line2_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    trigger_t _lf__line3;
    reaction_t* _lf__line3_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _display_self_t;
_display_self_t* new__display();
#endif // _DISPLAY_H
