#ifndef _accelwakeup_main_H
#define _accelwakeup_main_H
#ifndef _ACCELWAKEUP_MAIN_H // necessary for arduino-cli, which automatically includes headers that are not used
#ifndef TOP_LEVEL_PREAMBLE_665846007_H
#define TOP_LEVEL_PREAMBLE_665846007_H
/*Correspondence: Range: [(12, 2), (18, 29)) -> Range: [(0, 0), (6, 29)) (verbatim=true; src=/Users/kyankotschevar-smead/Desktop/Projects/Embedded-Systems/lab4/AccelWakeup.lf)*/#include <math.h>
#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>

#define LED_PIN 25
#define WAKE_THRESHOLD_G 0.1f
#endif // TOP_LEVEL_PREAMBLE_665846007_H
#ifndef TOP_LEVEL_PREAMBLE_809968973_H
#define TOP_LEVEL_PREAMBLE_809968973_H
/*Correspondence: Range: [(21, 2), (22, 16)) -> Range: [(0, 0), (1, 16)) (verbatim=true; src=/Users/kyankotschevar-smead/Desktop/Projects/Embedded-Systems/lab4/lib/IMU.lf)*/#include <pico/stdlib.h>
#include <imu.h>
#endif // TOP_LEVEL_PREAMBLE_809968973_H
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/schedule.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct accelwakeup_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    bool awake;
    float baseline_x;
    float baseline_y;
    float baseline_z;
    bool calibrated;
    int cal_count;
    int end[0]; // placeholder; MSVC does not compile empty structs
} accelwakeup_self_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;

} accelerometer_trigger_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} accelerometer_x_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} accelerometer_y_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} accelerometer_z_t;
#endif
#endif
