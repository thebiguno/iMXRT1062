/*
  T41BB5X_Pro_map.h - driver code for IMXRT1062 processor (on Teensy 4.1 board)

  Part of grblHAL

  Board by Phil Barrett: https://github.com/phil-barrett/grblHAL-teensy-4.x

  Copyright (c) 2021 Terje Io

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#if N_ABC_MOTORS > 2
#error "Axis configuration is not supported!"
#endif

#define BOARD_NAME "T41BB5X Pro"
#define HAS_IOPORTS

#if N_AXIS > 5
#error Max number of axes is 5 for T41U5XBB
#endif

#if QEI_ENABLE && SPINDLE_SYNC_ENABLE
#error Quadrature encoder and spindle sync cannot be enabled at the same time
#endif

// Board has 2K FRAM
/* supply problems...
#undef EEPROM_ENABLE
#undef EEPROM_IS_FRAM
#define EEPROM_ENABLE   1
#define EEPROM_IS_FRAM  1
*/
#define X_STEP_PIN          (2u)
#define X_DIRECTION_PIN     (3u)
#define X_ENABLE_PIN        (10u)
#define X_LIMIT_PIN         (20u)

#define Y_STEP_PIN          (4u)
#define Y_DIRECTION_PIN     (5u)
#define Y_ENABLE_PIN        (35u)
#define Y_LIMIT_PIN         (21u)

#define Z_STEP_PIN          (6u)
#define Z_DIRECTION_PIN     (7u)
#define Z_ENABLE_PIN        (39u)
#define Z_LIMIT_PIN         (22u)

// Define ganged axis or A axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 0
#define M3_AVAILABLE
#define M3_STEP_PIN         (8u)
#define M3_DIRECTION_PIN    (9u)
#define M3_LIMIT_PIN        (23u)
#define M3_ENABLE_PIN       (38u)
#endif

// Define ganged axis or B axis step pulse and step direction output pins.
#if N_ABC_MOTORS == 2
#define M4_AVAILABLE
#define M4_STEP_PIN         (26u)
#define M4_DIRECTION_PIN    (27u)
#define M4_LIMIT_PIN        (28u)
#define M4_ENABLE_PIN       (37u)
#endif

// Define spindle enable and spindle direction output pins.
#define SPINDLE_ENABLE_PIN      (12u)
#define SPINDLE_DIRECTION_PIN   (11u)
#define SPINDLEPWMPIN           (13u) // NOTE: only pin 12 or pin 13 can be assigned!

// Define flood and mist coolant enable output pins.
#define COOLANT_FLOOD_PIN   (19u)
#define COOLANT_MIST_PIN    (18u)

// Define user-control CONTROLs (cycle start, reset, feed hold, door) input pins.
#define RESET_PIN           (40u)
#define FEED_HOLD_PIN       (16u)
#define CYCLE_START_PIN     (17u)
#define SAFETY_DOOR_PIN     (29u)

// Define probe switch input pin.
#define PROBE_PIN           (15u)

#if QEI_ENABLE
#define QEI_A_PIN           (36u)
#define QEI_B_PIN           (30u)
//#define QEI_INDEX_PIN       (36u)
#define QEI_SELECT_PIN      (31u)
#endif

#if SPINDLE_SYNC_ENABLE
#define SPINDLE_INDEX_PIN   (31u) // ST2
#define SPINDLE_PULSE_PIN   (14u) // ST3
#endif

// Define auxillary input pins
#define AUXINPUT0_PIN       (36u) // ST0
#if !QEI_ENABLE
#define AUXINPUT1_PIN       (30u) // ST1
#if !SPINDLE_SYNC_ENABLE
#define AUXINPUT2_PIN       (31u) // ST2
#define AUXINPUT3_PIN       (14u) // ST3
#endif
#endif

// Define auxillary output pins
#define AUXOUTPUT0_PIN      (34U)
#define AUXOUTPUT1_PIN      (32U)
#define AUXOUTPUT2_PIN      (33U)

#if KEYPAD_ENABLE
#define KEYPAD_STROBE_PIN   (41U)
#endif

#if EEPROM_ENABLE || KEYPAD_ENABLE
#define I2C_PORT    4
#define I2C_SCL4    (24u) // Not used, for info only
#define I2C_SDA4    (25u) // Not used, for info only
#endif
