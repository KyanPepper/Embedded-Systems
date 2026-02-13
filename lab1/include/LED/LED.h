#ifndef _led_H
#define _led_H
#ifndef _LED_H // necessary for arduino-cli, which automatically includes headers that are not used
#ifndef TOP_LEVEL_PREAMBLE_1842173497_H
#define TOP_LEVEL_PREAMBLE_1842173497_H
/*Correspondence: Range: [(3, 4), (3, 28)) -> Range: [(0, 0), (0, 24)) (verbatim=true; src=/Users/kyankotschevar-smead/Desktop/Projects/Embedded-Systems/lab1/src/LED.lf)*/#include <pico/stdlib.h>
#endif // TOP_LEVEL_PREAMBLE_1842173497_H
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/schedule.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct led_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    int end[0]; // placeholder; MSVC does not compile empty structs
} led_self_t;
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
} led_set_t;
#endif
#endif
