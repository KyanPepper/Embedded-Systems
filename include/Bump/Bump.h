#ifndef _bump_H
#define _bump_H
#ifndef _BUMP_H // necessary for arduino-cli, which automatically includes headers that are not used
#ifndef TOP_LEVEL_PREAMBLE_543409470_H
#define TOP_LEVEL_PREAMBLE_543409470_H
/*Correspondence: Range: [(22, 2), (23, 9)) -> Range: [(0, 0), (1, 9)) (verbatim=true; src=/Users/kyankotschevar-smead/Desktop/Projects/Embedded-Systems/src/lib/Bump.lf)*/#include <ir_sensors.h>
// others
#endif // TOP_LEVEL_PREAMBLE_543409470_H
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/schedule.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct bump_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    interval_t sample_period;
    int end[0]; // placeholder; MSVC does not compile empty structs
} bump_self_t;
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
} bump_calibrate_t;
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
} bump_left_t;
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
} bump_right_t;
#endif
#endif
