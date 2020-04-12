#ifndef MA_MACHINE_H_INCLUDED
#define MA_MACHINE_H_INCLUDED

#define MICROSTEPS_XY 32 // Micro stepping XY
#define MICROSTEPS_Z 16  // Micro stepping Z
#define MICROSTEPS_A 16  // Micro stepping A

#define MOTOR_STEP 200 // number of step per turn
#define Z_SCREW_PITCH_MM 4 // Z Screw pitch in mm
#define PULLEY_REDUCTION_XY_NUME 10 // XY motor pulley
#define PULLEY_REDUCTION_XY_DENO 34 // XY 2nd pulley
#define MM_BELT_PER_TURN_XY (5.08 * 10) // 10 tooth * 5.08 mm XL037
//
#define DEFAULT_X_STEPS_PER_MM  428.3464567 //((MOTOR_STEP * MICROSTEPS_XY * PULLEY_REDUCTION_XY_DENO) / (PULLEY_REDUCTION_XY_NUME * MM_BELT_PER_TURN_XY))
#define DEFAULT_Y_STEPS_PER_MM  428.3464567 //(((MOTOR_STEP * MICROSTEPS_XY * PULLEY_REDUCTION_XY_DENO) / (PULLEY_REDUCTION_XY_NUME * MM_BELT_PER_TURN_XY))
#define DEFAULT_Z_STEPS_PER_MM  800 //((MOTOR_STEP * MICROSTEPS_Z) / Z_SCREW_PITCH_MM)
#define DEFAULT_A_STEPS_PER_DEG 40.44444444 //((MOTOR_STEP * MICROSTEPS_A * 18.2) / 360) // (12/52)*(20/84) reduction
#define DEFAULT_X_MAX_RATE ((29900/DEFAULT_X_STEPS_PER_MM)*60) // mm/min
#define DEFAULT_Y_MAX_RATE ((29900/DEFAULT_Y_STEPS_PER_MM)*60) // mm/min
#define DEFAULT_Z_MAX_RATE ((29900/DEFAULT_Z_STEPS_PER_MM)*60) // mm/min
#define DEFAULT_A_MAX_RATE ((29900/DEFAULT_A_STEPS_PER_DEG)*60) // °/min
#define DEFAULT_X_ACCELERATION (250.0*60*60) // 10*60*60 mm/min^2 = 10 mm/sec^2
#define DEFAULT_Y_ACCELERATION (250.0*60*60) // 10*60*60 mm/min^2 = 10 mm/sec^2
#define DEFAULT_Z_ACCELERATION (100.0*60*60) // 10*60*60 mm/min^2 = 10 mm/sec^2
#define DEFAULT_A_ACCELERATION (300.0*60*60) // 10*60*60 °/min^2 = 10 m°/sec^2
#define DEFAULT_X_MAX_TRAVEL 868.0 // mm NOTE: Must be a positive value.
#define DEFAULT_Y_MAX_TRAVEL 510.0 // mm NOTE: Must be a positive value.
#define DEFAULT_Z_MAX_TRAVEL 140.0 // mm NOTE: Must be a positive value.
#define DEFAULT_A_MAX_TRAVEL 360.0 // ° NOTE: Must be a positive value.
#define DEFAULT_SPINDLE_RPM_MAX 10000.0 // rpm
#define DEFAULT_SPINDLE_RPM_MIN 0.0 // rpm
#define DEFAULT_STEP_PULSE_MICROSECONDS 10
#define DEFAULT_STEPPING_INVERT_MASK 0b00000000
#define DEFAULT_DIRECTION_INVERT_MASK 0b00000000
#define DEFAULT_STEPPER_IDLE_LOCK_TIME 255 // msec (0-254, 255 keeps steppers enabled)
#define DEFAULT_STATUS_REPORT_MASK 1 // MPos enabled
#define DEFAULT_JUNCTION_DEVIATION 0.01 // mm
#define DEFAULT_ARC_TOLERANCE 0.002 // mm
#define DEFAULT_REPORT_INCHES 0 // false
#define DEFAULT_INVERT_ST_ENABLE 0 // false
#define DEFAULT_INVERT_LIMIT_PINS 0 // false
#define DEFAULT_SOFT_LIMIT_ENABLE 1 // true
#define DEFAULT_HARD_LIMIT_ENABLE 1  // true
#define DEFAULT_INVERT_PROBE_PIN 0 // false
#define DEFAULT_LASER_MODE 0 // false
#define DEFAULT_HOMING_ENABLE 1  // true
#define DEFAULT_HOMING_DIR_MASK 0b0011 // move X and Y negative dir
#define DEFAULT_HOMING_FEED_RATE 25.0 // mm/min
#define DEFAULT_HOMING_SEEK_RATE 200.0 // mm/min
#define DEFAULT_HOMING_DEBOUNCE_DELAY 50 // msec (0-65k)
#define DEFAULT_HOMING_PULLOFF 1.0 // mm

// Micro stepping settings (DRV8825)
/* MODE2|MODE1|MODE0|STEP MODE
     0  |  0  |  0  |Full step (2-phase excitation) with 71% current
     0  |  0  |  1  |1/2 step (1-2 phase excitation)
     0  |  1  |  0  |1/4 step (W1-2 phase excitation)
     0  |  1  |  1  |8 microsteps / step
     1  |  0  |  0  |16 microsteps / step
     1  |  0  |  1  |32 microsteps / step
*/

// MICROSTEPS_XY

#if (MICROSTEPS_XY == 1)
  #define STEPMODEXY   0
#elif (MICROSTEPS_XY == 2)
  #define STEPMODEXY   1
#elif (MICROSTEPS_XY == 4)
  #define STEPMODEXY   2
#elif (MICROSTEPS_XY == 8)
  #define STEPMODEXY   3
#elif (MICROSTEPS_XY == 16)
  #define STEPMODEXY   4
#elif (MICROSTEPS_XY == 32)
  #define STEPMODEXY   5
#endif
#define STEPMODE_XY STEPMODEXY

// MICROSTEPS_Z

#if (MICROSTEPS_Z == 1)
  #define STEPMODEZ   0
#elif (MICROSTEPS_Z == 2)
  #define STEPMODEZ   1
#elif (MICROSTEPS_Z == 4)
  #define STEPMODEZ   2
#elif (MICROSTEPS_Z == 8)
  #define STEPMODEZ   3
#elif (MICROSTEPS_Z == 16)
  #define STEPMODEZ   4
#elif (MICROSTEPS_Z == 32)
  #define STEPMODEZ   5
#endif
#define STEPMODE_Z STEPMODEZ

// MICROSTEPS_A

#if (MICROSTEPS_A == 1)
  #define STEPMODEA   0
#elif (MICROSTEPS_A == 2)
  #define STEPMODEA   1
#elif (MICROSTEPS_A == 4)
  #define STEPMODEA   2
#elif (MICROSTEPS_A == 8)
  #define STEPMODEA   3
#elif (MICROSTEPS_A == 16)
  #define STEPMODEA   4
#elif (MICROSTEPS_A == 32)
  #define STEPMODEA   5
#endif
#define STEPMODE_A STEPMODEA

// My M2560 pin map

// Serial port interrupt vectors
#define SERIAL_RX USART0_RX_vect
#define SERIAL_UDRE USART0_UDRE_vect

// Define step pulse output pins. NOTE: All step bit pins must be on the same port.
#define STEP_DDR      DDRA
#define STEP_PORT     PORTA
#define STEP_PIN      PINA
#define X_STEP_BIT    0 // MEGA2560 Digital Pin 22
#define Y_STEP_BIT    2 // MEGA2560 Digital Pin 24
#define Z_STEP_BIT    4 // MEGA2560 Digital Pin 26
#define A_STEP_BIT	  6 // MEGA2560 Digital Pin 28
#define STEP_MASK ((1<<X_STEP_BIT)|(1<<Y_STEP_BIT)|(1<<Z_STEP_BIT)|(1<<A_STEP_BIT)) // All step bits

// Define step direction output pins. NOTE: All direction pins must be on the same port.
#define DIRECTION_DDR     DDRA
#define DIRECTION_PORT    PORTA
#define DIRECTION_PIN     PINA
#define X_DIRECTION_BIT   1 // MEGA2560 Digital Pin 23
#define Y_DIRECTION_BIT   3 // MEGA2560 Digital Pin 25
#define Z_DIRECTION_BIT   5 // MEGA2560 Digital Pin 27
#define A_DIRECTION_BIT	  7 // MEGA2560 Digital Pin 29
#define DIRECTION_MASK ((1<<X_DIRECTION_BIT)|(1<<Y_DIRECTION_BIT)|(1<<Z_DIRECTION_BIT)|(1<<A_DIRECTION_BIT)) // All direction bits

// Define stepper driver enable/disable output pin.
#define STEPPERS_DISABLE_DDR   DDRG
#define STEPPERS_DISABLE_PORT  PORTG
#define STEPPERS_DISABLE_BIT   5 // MEGA2560 Digital Pin 4
#define STEPPERS_DISABLE_MASK  (1<<STEPPERS_DISABLE_BIT)

#define STEPPERS_DISABLE_ALL_AXIS_DDR   DDRL
#define STEPPERS_DISABLE_ALL_AXIS_PORT  PORTL
#define STEPPERS_DISABLE_AXIS_X_BIT   6 // MEGA2560 Digital Pin 43
#define STEPPERS_DISABLE_AXIS_X_MASK (1<<STEPPERS_DISABLE_AXIS_X_BIT)
#define STEPPERS_DISABLE_AXIS_Y_BIT   4 // MEGA2560 Digital Pin 45
#define STEPPERS_DISABLE_AXIS_Y_MASK (1<<STEPPERS_DISABLE_AXIS_Y_BIT)
#define STEPPERS_DISABLE_AXIS_Z_BIT   2 // MEGA2560 Digital Pin 47
#define STEPPERS_DISABLE_AXIS_Z_MASK (1<<STEPPERS_DISABLE_AXIS_Z_BIT)
#define STEPPERS_DISABLE_AXIS_A_BIT   0 // MEGA2560 Digital Pin 49
#define STEPPERS_DISABLE_AXIS_A_MASK (1<<STEPPERS_DISABLE_AXIS_A_BIT)
#define STEPPERS_DISABLE_ALL_AXIS_MASK (STEPPERS_DISABLE_AXIS_X_MASK | STEPPERS_DISABLE_AXIS_Y_MASK | STEPPERS_DISABLE_AXIS_Z_MASK | STEPPERS_DISABLE_AXIS_A_MASK)

// Define stepper presence enable/disable input pin.
#define CHECK_STEPPERS_PRESENCE
#if defined(CHECK_STEPPERS_PRESENCE)
#define STEPPERS_IS_PRESENT_ALL_AXIS_DDR  DDRL
#define STEPPERS_IS_PRESENT_ALL_AXIS_PORT PORTL
#define STEPPERS_IS_PRESENT_ALL_AXIS_PIN  PINL
#define STEPPERS_IS_PRESENT_AXIS_X_BIT    7 // MEGA2560 Digital Pin 42
#define STEPPERS_IS_PRESENT_AXIS_X_MASK   (1<<STEPPERS_IS_PRESENT_AXIS_X_BIT)
#define AXIS_X_IS_PRESENT                 (!(STEPPERS_IS_PRESENT_ALL_AXIS_PIN & STEPPERS_IS_PRESENT_AXIS_X_MASK))
#define STEPPERS_IS_PRESENT_AXIS_Y_BIT    5 // MEGA2560 Digital Pin 44
#define STEPPERS_IS_PRESENT_AXIS_Y_MASK   (1<<STEPPERS_IS_PRESENT_AXIS_Y_BIT)
#define AXIS_Y_IS_PRESENT                 (!(STEPPERS_IS_PRESENT_ALL_AXIS_PIN & STEPPERS_IS_PRESENT_AXIS_Y_MASK))
#define STEPPERS_IS_PRESENT_AXIS_Z_BIT    3 // MEGA2560 Digital Pin 46
#define STEPPERS_IS_PRESENT_AXIS_Z_MASK   (1<<STEPPERS_IS_PRESENT_AXIS_Z_BIT)
#define AXIS_Z_IS_PRESENT                 (!(STEPPERS_IS_PRESENT_ALL_AXIS_PIN & STEPPERS_IS_PRESENT_AXIS_Z_MASK))
#define STEPPERS_IS_PRESENT_AXIS_A_BIT    1 // MEGA2560 Digital Pin 48
#define STEPPERS_IS_PRESENT_AXIS_A_MASK   (1<<STEPPERS_IS_PRESENT_AXIS_A_BIT)
#define AXIS_A_IS_PRESENT                 (!(STEPPERS_IS_PRESENT_ALL_AXIS_PIN & STEPPERS_IS_PRESENT_AXIS_A_MASK))
#define STEPPERS_IS_PRESENT_ALL_AXIS_MASK (STEPPERS_IS_PRESENT_AXIS_X_MASK | STEPPERS_IS_PRESENT_AXIS_Y_MASK | STEPPERS_IS_PRESENT_AXIS_Z_MASK | STEPPERS_IS_PRESENT_AXIS_A_MASK)
#define JUMP_IF_AXIS_NOT_PRESENT(x)             \
if  (((x == X_AXIS) && (!AXIS_X_IS_PRESENT)) |  \
     ((x == Y_AXIS) && (!AXIS_Y_IS_PRESENT)) |  \
     ((x == Z_AXIS) && (!AXIS_Z_IS_PRESENT)) |  \
     ((x == A_AXIS) && (!AXIS_A_IS_PRESENT)))   \
      continue

#else
#define STEPPERS_IS_PRESENT_ALL_AXIS_PIN  0
#define STEPPERS_IS_PRESENT_AXIS_X_MASK   0
#define STEPPERS_IS_PRESENT_AXIS_Y_MASK   0
#define STEPPERS_IS_PRESENT_AXIS_Z_MASK   0
#define STEPPERS_IS_PRESENT_AXIS_A_MASK   0
#define AXIS_X_IS_PRESENT                 1
#define AXIS_Y_IS_PRESENT                 1                 1
#define AXIS_Z_IS_PRESENT                 1
#define AXIS_A_IS_PRESENT                 1
#endif

// Define homing/hard limit switch input pins and limit interrupt vectors.
// NOTE: All limit bit pins must be on the same port
#define LIMIT_DDR       DDRB
#define LIMIT_PORT      PORTB
#define LIMIT_PIN       PINB
#define X_LIMIT_BIT     4 // MEGA2560 Digital Pin 10
#define Y_LIMIT_BIT     5 // MEGA2560 Digital Pin 11
#define Z_LIMIT_BIT     6 // MEGA2560 Digital Pin 12
#define A_LIMIT_BIT     7 // MEGA2560 Digital Pin 13
#define LIMIT_INT       PCIE0  // Pin change interrupt enable pin
#define LIMIT_INT_vect  PCINT0_vect
#define LIMIT_PCMSK     PCMSK0 // Pin change interrupt register
#define LIMIT_MASK      ((1<<X_LIMIT_BIT)|(1<<Y_LIMIT_BIT)|(1<<Z_LIMIT_BIT)|(1<<A_LIMIT_BIT)) // All limit bits
#define HW_LIMIT_MASK   ((1<<X_LIMIT_BIT)|(1<<Y_LIMIT_BIT)|(1<<Z_LIMIT_BIT)) // All HW limit bits (Not A -> rot. axis)

// Define spindle enable and spindle direction output pins.
#define SPINDLE_ENABLE_DDR      DDRH
#define SPINDLE_ENABLE_PORT     PORTH
#define SPINDLE_ENABLE_BIT      3 // MEGA2560 Digital Pin 6
#define SPINDLE_DIRECTION_DDR   DDRE
#define SPINDLE_DIRECTION_PORT  PORTE
#define SPINDLE_DIRECTION_BIT   3 // MEGA2560 Digital Pin 5

// Define flood and mist coolant enable output pins.
#define COOLANT_FLOOD_DDR   DDRH
#define COOLANT_FLOOD_PORT  PORTH
#define COOLANT_FLOOD_BIT   5 // MEGA2560 Digital Pin 8
#define COOLANT_MIST_DDR    DDRH
#define COOLANT_MIST_PORT   PORTH
#define COOLANT_MIST_BIT    6 // MEGA2560 Digital Pin 9

// Define user-control CONTROLs (cycle start, reset, feed hold) input pins.
// NOTE: All CONTROLs pins must be on the same port and not on a port with other input pins (limits).
#define CONTROL_DDR               DDRK
#define CONTROL_PIN               PINK
#define CONTROL_PORT              PORTK
#define CONTROL_RESET_BIT         0  // MEGA2560 Analog Pin 8
#define CONTROL_FEED_HOLD_BIT     1  // MEGA2560 Analog Pin 9
#define CONTROL_CYCLE_START_BIT   2  // MEGA2560 Analog Pin 10
#define CONTROL_SAFETY_DOOR_BIT   3  // MEGA2560 Analog Pin 11
#define CONTROL_INT               PCIE2  // Pin change interrupt enable pin
#define CONTROL_INT_vect          PCINT2_vect
#define CONTROL_PCMSK             PCMSK2 // Pin change interrupt register
#define CONTROL_MASK              ((1<<CONTROL_RESET_BIT)|(1<<CONTROL_FEED_HOLD_BIT)|(1<<CONTROL_CYCLE_START_BIT)|(1<<CONTROL_SAFETY_DOOR_BIT))

// Define probe switch input pin.
#define PROBE_DDR       DDRK
#define PROBE_PIN       PINK
#define PROBE_PORT      PORTK
#define PROBE_BIT       7  // MEGA2560 Analog Pin 15
#define PROBE_MASK      (1<<PROBE_BIT)

// Advanced Configuration Below You should not need to touch these variables
// Set Timer up to use TIMER4B which is attached to Digital Pin 7
#define SPINDLE_PWM_MAX_VALUE     1024.0 // Translates to about 1.9 kHz PWM frequency at 1/8 prescaler
#ifndef SPINDLE_PWM_MIN_VALUE
  #define SPINDLE_PWM_MIN_VALUE   1   // Must be greater than zero.
#endif
#define SPINDLE_PWM_OFF_VALUE     0
#define SPINDLE_PWM_RANGE         (SPINDLE_PWM_MAX_VALUE-SPINDLE_PWM_MIN_VALUE)
#define SPINDLE_TCCRA_REGISTER		TCCR4A
#define SPINDLE_TCCRB_REGISTER		TCCR4B
#define SPINDLE_OCR_REGISTER	  	OCR4B
#define SPINDLE_COMB_BIT			    COM4B1

// 1/8 Prescaler, 16-bit Fast PWM mode
#define SPINDLE_TCCRA_INIT_MASK ((1<<WGM40) | (1<<WGM41))
#define SPINDLE_TCCRB_INIT_MASK ((1<<WGM42) | (1<<WGM43) | (1<<CS41))
#define SPINDLE_OCRA_REGISTER   OCR4A // 16-bit Fast PWM mode requires top reset value stored here.
#define SPINDLE_OCRA_TOP_VALUE  0x0400 // PWM counter reset value. Should be the same as PWM_MAX_VALUE in hex.

// Define spindle output pins.
#define SPINDLE_PWM_DDR		DDRH
#define SPINDLE_PWM_PORT  PORTH
#define SPINDLE_PWM_BIT		4 // MEGA2560 Digital Pin 7

// Micro stepping pin
#define MSTEP_MASK         0x03 // 3 pin mask
// XY
#define MSTEP_XY_DDR       DDRC
#define MSTEP_XY_PORT      PORTC
#define MSTEP_XY_OFFSET    0
// Z
#define MSTEP_Z_DDR        DDRC
#define MSTEP_Z_PORT       PORTC
#define MSTEP_Z_OFFSET     4   // Start at pin4
// A
#define MSTEP_A_DDR        DDRG
#define MSTEP_A_PORT       PORTG
#define MSTEP_A_OFFSET     0

// FEED_RATE_POT
#define USE_FEED_RATE_POT

#define FEED_RATE_POT_DDR       DDRF
#define FEED_RATE_POT_PORT      PORTF
#define FEED_RATE_POT_INPUT     0
#define FEED_RATE_POT_PIN       (1<<FEED_RATE_POT_INPUT)

// Status leds
#define USE_STATUS_LED

#define STATUS_LED_DDR    DDRJ
#define STATUS_LED_PORT   PORTJ
#define GREEN_LED_BIT     0
#define RED_LED_BIT       1
#define GREEN_LED         (1<<GREEN_LED_BIT)
#define RED_LED           (1<<RED_LED_BIT)
#define STATUS_LED_MASK   (GREEN_LED | RED_LED) // 2 output (pin mask)

#endif // MA_MACHINE_H_INCLUDED
