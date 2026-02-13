#ifndef _combined_main_H
#define _combined_main_H
#ifndef _COMBINED_MAIN_H // necessary for arduino-cli, which automatically includes headers that are not used
#ifndef TOP_LEVEL_PREAMBLE_1847410999_H
#define TOP_LEVEL_PREAMBLE_1847410999_H
/*Correspondence: Range: [(23, 2), (25, 26)) -> Range: [(0, 0), (2, 26)) (verbatim=true; src=/Users/kyankotschevar-smead/Desktop/Projects/Embedded-Systems/src/combined.lf)*/#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>
#endif // TOP_LEVEL_PREAMBLE_1847410999_H
#ifndef TOP_LEVEL_PREAMBLE_1778801068_H
#define TOP_LEVEL_PREAMBLE_1778801068_H
/*Correspondence: Range: [(18, 2), (19, 68)) -> Range: [(0, 0), (1, 68)) (verbatim=true; src=/Users/kyankotschevar-smead/Desktop/Projects/Embedded-Systems/src/lib/Display.lf)*/#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif // TOP_LEVEL_PREAMBLE_1778801068_H
#ifndef TOP_LEVEL_PREAMBLE_543409470_H
#define TOP_LEVEL_PREAMBLE_543409470_H
/*Correspondence: Range: [(22, 2), (23, 9)) -> Range: [(0, 0), (1, 9)) (verbatim=true; src=/Users/kyankotschevar-smead/Desktop/Projects/Embedded-Systems/src/lib/Bump.lf)*/#include <ir_sensors.h>
// others
#endif // TOP_LEVEL_PREAMBLE_543409470_H
#ifndef TOP_LEVEL_PREAMBLE_1155437763_H
#define TOP_LEVEL_PREAMBLE_1155437763_H
/*Correspondence: Range: [(18, 2), (26, 17)) -> Range: [(0, 0), (8, 17)) (verbatim=true; src=/Users/kyankotschevar-smead/Desktop/Projects/Embedded-Systems/src/lib/Encoders.lf)*/#include <math.h>
#include <hardware/pio.h>
#include <quadrature_encoder.pio.h>

// pin defines
#define RIGHT_ENCODER_AB 8
#define LEFT_ENCODER_AB 12
#define RIGHT_SM 0
#define LEFT_SM 1
#endif // TOP_LEVEL_PREAMBLE_1155437763_H
#ifndef TOP_LEVEL_PREAMBLE_369573800_H
#define TOP_LEVEL_PREAMBLE_369573800_H
/*Correspondence: Range: [(19, 2), (20, 17)) -> Range: [(0, 0), (1, 17)) (verbatim=true; src=/Users/kyankotschevar-smead/Desktop/Projects/Embedded-Systems/src/lib/Motors.lf)*/#include <motors.h>
#include <math.h>
#endif // TOP_LEVEL_PREAMBLE_369573800_H
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/schedule.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct combined_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    bool led_on;
    bool driving;
    int end[0]; // placeholder; MSVC does not compile empty structs
} combined_self_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_action_internal_t _base;
    self_base_t* parent;
    bool has_value;
    int source_id;

    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} combined_clear_bump_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} display_line0_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} display_line1_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} display_line2_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} display_line3_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;

} bump_calibrate_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;

} bump_left_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;

} bump_right_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;

} encoders_trigger_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int32_t value;

} encoders_right_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int32_t value;

} encoders_left_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} motors_left_power_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} motors_right_power_t;
#endif
#endif
