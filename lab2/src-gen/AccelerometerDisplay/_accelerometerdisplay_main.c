#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/AccelerometerDisplay/AccelerometerDisplay.h"
#include "_accelerometerdisplay_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _accelerometerdisplay_mainreaction_function_0(void* instance_args) {
    _accelerometerdisplay_main_main_self_t* self = (_accelerometerdisplay_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct a {
        _accelerometer_trigger_t* trigger;
    
    } a;
    a.trigger = &(self->_lf_a.trigger);
    #line 32 "/home/masonmenser/Embedded-Systems/lab2/AccelerometerDisplay.lf"
    lf_set(a.trigger, true);
#line 19 "/home/masonmenser/Embedded-Systems/lab2/src-gen/AccelerometerDisplay/_accelerometerdisplay_main.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _accelerometerdisplay_mainreaction_function_1(void* instance_args) {
    _accelerometerdisplay_main_main_self_t* self = (_accelerometerdisplay_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct a {
        _accelerometer_x_t* x;
    _accelerometer_y_t* y;
    _accelerometer_z_t* z;
    
    } a;
    struct d {
        _display_line0_t* line0;
    _display_line1_t* line1;
    _display_line2_t* line2;
    
    } d;
    a.x = self->_lf_a.x;
    a.y = self->_lf_a.y;
    a.z = self->_lf_a.z;
    d.line0 = &(self->_lf_d.line0);
    d.line1 = &(self->_lf_d.line1);
    d.line2 = &(self->_lf_d.line2);
    #line 36 "/home/masonmenser/Embedded-Systems/lab2/AccelerometerDisplay.lf"
    /// TODO: define max string size for line
    /// based on font you can have 4 or 8 lines
    static char buf0[17];
    static char buf1[17];
    static char buf2[17];
    
    snprintf(buf0, 17, "x:%2.4f", a.x->value);
    snprintf(buf1, 17, "y:%2.4f", a.y->value);
    snprintf(buf2, 17, "z:%2.4f", a.z->value);
    
    lf_set(d.line0, buf0);
    lf_set(d.line1, buf1);
    lf_set(d.line2, buf2);
#line 57 "/home/masonmenser/Embedded-Systems/lab2/src-gen/AccelerometerDisplay/_accelerometerdisplay_main.c"
}
#include "include/api/reaction_macros_undef.h"
_accelerometerdisplay_main_main_self_t* new__accelerometerdisplay_main() {
    _accelerometerdisplay_main_main_self_t* self = (_accelerometerdisplay_main_main_self_t*)lf_new_reactor(sizeof(_accelerometerdisplay_main_main_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_a_width = -2;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf_a.x_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf_a.x_reactions[0] = &self->_lf__reaction_1;
    self->_lf_a.x_trigger.reactions = self->_lf_a.x_reactions;
    self->_lf_a.x_trigger.last_tag = NEVER_TAG;
    self->_lf_a.x_trigger.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf_a.x_trigger.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf_a.y_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf_a.y_reactions[0] = &self->_lf__reaction_1;
    self->_lf_a.y_trigger.reactions = self->_lf_a.y_reactions;
    self->_lf_a.y_trigger.last_tag = NEVER_TAG;
    self->_lf_a.y_trigger.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf_a.y_trigger.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf_a.z_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf_a.z_reactions[0] = &self->_lf__reaction_1;
    self->_lf_a.z_trigger.reactions = self->_lf_a.z_reactions;
    self->_lf_a.z_trigger.last_tag = NEVER_TAG;
    self->_lf_a.z_trigger.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf_a.z_trigger.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_d_width = -2;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _accelerometerdisplay_mainreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _accelerometerdisplay_mainreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__t.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__t_reactions[0] = &self->_lf__reaction_0;
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    self->_lf__t.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__t.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    return self;
}
