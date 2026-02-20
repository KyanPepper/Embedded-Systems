#ifndef _ACCELEROMETER_H
#define _ACCELEROMETER_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_889753223_H
#define TOP_LEVEL_PREAMBLE_889753223_H
#include <pico/stdlib.h>
#include <imu.h>
#endif // TOP_LEVEL_PREAMBLE_889753223_H
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
} _accelerometer_trigger_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _accelerometer_x_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _accelerometer_y_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _accelerometer_z_t;
typedef struct {
    struct self_base_t base;
#line 68 "/home/masonmenser/Embedded-Systems/lab2/src-gen/AccelerometerDisplay/_accelerometer.h"
#line 69 "/home/masonmenser/Embedded-Systems/lab2/src-gen/AccelerometerDisplay/_accelerometer.h"
    _accelerometer_trigger_t* _lf_trigger;
    // width of -2 indicates that it is not a multiport.
    int _lf_trigger_width;
    // Default input (in case it does not get connected)
    _accelerometer_trigger_t _lf_default__trigger;
    _accelerometer_x_t _lf_x;
    int _lf_x_width;
    _accelerometer_y_t _lf_y;
    int _lf_y_width;
    _accelerometer_z_t _lf_z;
    int _lf_z_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    trigger_t _lf__trigger;
    reaction_t* _lf__trigger_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _accelerometer_self_t;
_accelerometer_self_t* new__accelerometer();
#endif // _ACCELEROMETER_H
