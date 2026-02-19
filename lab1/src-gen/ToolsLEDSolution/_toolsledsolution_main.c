#include "include/api/schedule.h"
#include <string.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/ToolsLEDSolution/ToolsLEDSolution.h"
#include "_toolsledsolution_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _toolsledsolution_mainreaction_function_0(void* instance_args) {
    _toolsledsolution_main_main_self_t* self = (_toolsledsolution_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct led {
        _led_set_t* set;
    
    } led;
    led.set = &(self->_lf_led.set);
    #line 21 "/Users/kyankotschevar-smead/Desktop/Projects/Embedded-Systems/lab1/src/ToolsLEDSolution.lf"
    if (self->in_pause) {
        // During pause, keep LED off and count ticks (10 ticks = 1 second)
        self->pause_ticks++;
        if (self->pause_ticks >= 10) {
            // Pause complete, start next blink cycle
            self->in_pause = false;
            self->pause_ticks = 0;
            self->target_blinks++;
            if (self->target_blinks > 4) {
                self->target_blinks = 1;  // Reset to 1 after 4
            }
            self->blink_count = 0;
        }
        lf_set(led.set, false);
    } else {
        // Blinking phase
        self->led_on = !self->led_on;
        lf_set(led.set, self->led_on);
    
        if (!self->led_on) {
            // Just turned off, count this as one complete blink
            self->blink_count++;
            printf("Blink %d of %d\n", self->blink_count, self->target_blinks);
    
            if (self->blink_count >= self->target_blinks) {
                // Done with this cycle, enter pause
                self->in_pause = true;
                self->pause_ticks = 0;
                printf("Pausing for 1 second, next cycle: %d blinks\n", 
                       (self->target_blinks % 4) + 1);
            }
        }
    }
#line 51 "/Users/kyankotschevar-smead/Desktop/Projects/Embedded-Systems/lab1/src-gen/ToolsLEDSolution/_toolsledsolution_main.c"
}
#include "include/api/reaction_macros_undef.h"
_toolsledsolution_main_main_self_t* new__toolsledsolution_main() {
    _toolsledsolution_main_main_self_t* self = (_toolsledsolution_main_main_self_t*)lf_new_reactor(sizeof(_toolsledsolution_main_main_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_led_width = -2;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _toolsledsolution_mainreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
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
