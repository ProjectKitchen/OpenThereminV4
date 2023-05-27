// Build definitions

#ifndef _BUILD_H
#define _BUILD_H


// Set to build with serial support
#define SERIAL_ENABLED 0

// Set to enable volume control, else volume will be set to maximum
#define VOLUME_ENABLED 0

// Set to enable for monitoring pitch activity (auto-fading volume/pitch in case of activity < PITCH_ACTIVE_THRESHOLD)
#define CHECK_PITCH_ACTIVITY 1
#define AUTO_PITCH 0
#define AUTO_VOLUME 1

// Parameters for activity monitoring
#define PITCH_AVERAGER_SIZE 300
#define PITCH_ACTIVE_THRESHOLD 120
#define FADE_TIMEOUT 800

// Parameters for amplifier on/off via Gate Voltage + MOSFET Transistor
#define ACTIVATE_AMP_THRESHOLD 300
#define AMP_SHUTDOWN_TIMEOUT  5000

// Set to build with logarithmic 1V/oct pitch control voltage output
#define CV_LOG 1

// Set the trigger levels for the Gate signal (0 to 127 in preparation for later midi extensions)
#define GATE_ON  20 // That's the level which will drive the Gate high when volume increases from lower
#define GATE_OFF 16 // That's the level which will drive the Gate low when volume decreases from higher
// Making both values equal risk the gate signal to bounce, leave at least 4 (hysteresis) between both.
// Set both to 128 to disable the Gate Signal.

#endif // _BUILD_H
