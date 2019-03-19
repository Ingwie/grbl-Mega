/*
  leds.c - Add leds output to show states
  An add for the excellent Grbl

  Copyright (c) 2019 Bracame

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

#include "grbl.h"

uint8_t blink = 0;

void InitStatusLeds()
{
  STATUS_LED_DDR |= STATUS_LED_MASK; // Configure as output pin
  STATUS_LED_PORT |= STATUS_LED_MASK; // All leds ON at init

  // BLINK timer is Timer 5: Counter Overflow Interrupt
  TCCR5B = 0; // Normal operation. Overflow.
  TCCR5A = 0;
  TCCR5B |= (1<<CS51)|(1<<CS50); // 1/64 prescaler 0.26sec/tick
  TIMSK5 |= (1<<TOIE5); // Enable timer5 overflow interrupt

}

// Toggle BLINK byte each timer overflow.
ISR(TIMER5_OVF_vect, ISR_NOBLOCK) { blink = (blink)? 0 : 1; }

/* From system.h
#define STATE_IDLE          0      // Must be zero. No flags.
#define STATE_ALARM         bit(0) // In alarm state. Locks out all g-code processes. Allows settings access.
#define STATE_CHECK_MODE    bit(1) // G-code check mode. Locks out planner and motion only.
#define STATE_HOMING        bit(2) // Performing homing cycle
#define STATE_CYCLE         bit(3) // Cycle is running or motions are being executed.
#define STATE_HOLD          bit(4) // Active feed hold
#define STATE_JOG           bit(5) // Jogging mode.
#define STATE_SAFETY_DOOR   bit(6) // Safety door is ajar. Feed holds and de-energizes system.
#define STATE_SLEEP         bit(7) // Sleep state.
*/

void UpdateStatusLeds()
{
  static uint8_t stateMem = 0xFF;
  static uint8_t blinkmem = 0;

  if ((stateMem != sys.state) || (blinkmem != blink))
    {
      stateMem = sys.state;
      blinkmem = blink;

      switch (stateMem)
        {

        case STATE_IDLE :
          GREEN_LED_ON;
          RED_LED_OFF;
          break; // green
        case STATE_ALARM :
          RED_LED_ON;
          GREEN_LED_OFF;
          break; // red
        case STATE_CHECK_MODE :
        case STATE_HOLD :
          ORANGE_LED_ON;
          break; // orange
        case STATE_HOMING :
          if (blink)
            {
              GREEN_LED_ON;
              RED_LED_OFF;
            }
          else
            {
              RED_LED_ON;
              GREEN_LED_OFF;
            }
          break; // toggle green - red (blink)
        case STATE_CYCLE :
          if (blink)
            {
              ORANGE_LED_ON;
            }
          else
            {
              ORANGE_LED_OFF;
            }
          break; // orange blink
        case STATE_JOG :
          if (blink)
            {
              GREEN_LED_ON;
              RED_LED_OFF;
            }
          else
            {
              GREEN_LED_OFF;
              RED_LED_OFF;
            }
          break; // green blink

        default :
          ORANGE_LED_OFF; // All off
        }
    }
}
