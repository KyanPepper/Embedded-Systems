#ifndef _ACCELEROMETERDISPLAY_MAIN_H
#define _ACCELEROMETERDISPLAY_MAIN_H
#include "include/core/reactor.h"
#include "_accelerometer.h"
#include "_display.h"
#ifndef TOP_LEVEL_PREAMBLE_889753223_H
#define TOP_LEVEL_PREAMBLE_889753223_H
#include <pico/stdlib.h>
#include <imu.h>
#endif // TOP_LEVEL_PREAMBLE_889753223_H
#ifndef TOP_LEVEL_PREAMBLE_627746290_H
#define TOP_LEVEL_PREAMBLE_627746290_H
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#endif // TOP_LEVEL_PREAMBLE_627746290_H
typedef struct {
    struct self_base_t base;
#line 19 "/home/masonmenser/Embedded-Systems/lab2/src-gen/AccelerometerDisplay/_accelerometerdisplay_main.h"
#line 20 "/home/masonmenser/Embedded-Systems/lab2/src-gen/AccelerometerDisplay/_accelerometerdisplay_main.h"
    struct {
        _accelerometer_trigger_t trigger;
        _accelerometer_x_t* x;
        trigger_t x_trigger;
        reaction_t* x_reactions[1];
        _accelerometer_y_t* y;
        trigger_t y_trigger;
        reaction_t* y_reactions[1];
        _accelerometer_z_t* z;
        trigger_t z_trigger;
        reaction_t* z_reactions[1];
    } _lf_a;
    int _lf_a_width;
    struct {
        _display_line0_t line0;
        _display_line1_t line1;
        _display_line2_t line2;
    } _lf_d;
    int _lf_d_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    trigger_t _lf__t;
    reaction_t* _lf__t_reactions[1];
} _accelerometerdisplay_main_main_self_t;
_accelerometerdisplay_main_main_self_t* new__accelerometerdisplay_main();
#endif // _ACCELEROMETERDISPLAY_MAIN_H
