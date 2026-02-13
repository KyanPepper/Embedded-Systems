#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/LED/LED.h"
#include "_led.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _ledreaction_function_0(void* instance_args) {
    _led_self_t* self = (_led_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 11 "/Users/kyankotschevar-smead/Desktop/Projects/Embedded-Systems/lab1/src/LED.lf"
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
#line 16 "/Users/kyankotschevar-smead/Desktop/Projects/Embedded-Systems/lab1/src-gen/ToolsLEDSolution/_led.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _ledreaction_function_1(void* instance_args) {
    _led_self_t* self = (_led_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _led_set_t* set = self->_lf_set;
    int set_width = self->_lf_set_width; SUPPRESS_UNUSED_WARNING(set_width);
    #line 16 "/Users/kyankotschevar-smead/Desktop/Projects/Embedded-Systems/lab1/src/LED.lf"
    gpio_put(PICO_DEFAULT_LED_PIN, set->value);
#line 26 "/Users/kyankotschevar-smead/Desktop/Projects/Embedded-Systems/lab1/src-gen/ToolsLEDSolution/_led.c"
}
#include "include/api/reaction_macros_undef.h"
_led_self_t* new__led() {
    _led_self_t* self = (_led_self_t*)lf_new_reactor(sizeof(_led_self_t));
    // Set input by default to an always absent default input.
    self->_lf_set = &self->_lf_default__set;
    // Set the default source reactor pointer
    self->_lf_default__set._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _ledreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _ledreaction_function_1;
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
    self->_lf__set.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__set.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__set_reactions[0] = &self->_lf__reaction_1;
    self->_lf__set.reactions = &self->_lf__set_reactions[0];
    self->_lf__set.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__set.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__set.tmplt.type.element_size = sizeof(bool);
    return self;
}
