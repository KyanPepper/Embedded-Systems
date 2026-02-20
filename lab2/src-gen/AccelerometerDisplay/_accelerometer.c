#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/IMU/Accelerometer.h"
#include "_accelerometer.h"
// *********** From the preamble, verbatim:
#line 29 "/home/masonmenser/Embedded-Systems/lab2/lib/IMU.lf"
// Static global IMU instance struct.
static imu_inst_t imu_instance;
// Boolean to ensure the IMU instance is initialized only once.
static bool _pololu_robot_imu_initialized = false;
#line 13 "/home/masonmenser/Embedded-Systems/lab2/src-gen/AccelerometerDisplay/_accelerometer.c"

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _accelerometerreaction_function_0(void* instance_args) {
    _accelerometer_self_t* self = (_accelerometer_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 42 "/home/masonmenser/Embedded-Systems/lab2/lib/IMU.lf"
    if (!_pololu_robot_imu_initialized) {
      _pololu_robot_imu_initialized = true;
      imu_init(&imu_instance);
    }
#line 27 "/home/masonmenser/Embedded-Systems/lab2/src-gen/AccelerometerDisplay/_accelerometer.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _accelerometerreaction_function_1(void* instance_args) {
    _accelerometer_self_t* self = (_accelerometer_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _accelerometer_trigger_t* trigger = self->_lf_trigger;
    int trigger_width = self->_lf_trigger_width; SUPPRESS_UNUSED_WARNING(trigger_width);
    _accelerometer_x_t* x = &self->_lf_x;
    _accelerometer_y_t* y = &self->_lf_y;
    _accelerometer_z_t* z = &self->_lf_z;
    #line 59 "/home/masonmenser/Embedded-Systems/lab2/lib/IMU.lf"
    axes_data_t acc_data;
        imu_read_acc(&imu_instance, &acc_data);
    
        lf_set(x, acc_data.x);
        lf_set(y, acc_data.y);
        lf_set(z, acc_data.z);
#line 45 "/home/masonmenser/Embedded-Systems/lab2/src-gen/AccelerometerDisplay/_accelerometer.c"
}
#include "include/api/reaction_macros_undef.h"
_accelerometer_self_t* new__accelerometer() {
    _accelerometer_self_t* self = (_accelerometer_self_t*)lf_new_reactor(sizeof(_accelerometer_self_t));
    // Set input by default to an always absent default input.
    self->_lf_trigger = &self->_lf_default__trigger;
    // Set the default source reactor pointer
    self->_lf_default__trigger._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _accelerometerreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _accelerometerreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last_tag = NEVER_TAG;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    self->_lf__trigger.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__trigger_reactions[0] = &self->_lf__reaction_1;
    self->_lf__trigger.reactions = &self->_lf__trigger_reactions[0];
    self->_lf__trigger.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__trigger.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__trigger.tmplt.type.element_size = sizeof(bool);
    return self;
}
