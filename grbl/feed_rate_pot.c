/*
  fedd_rate_pot.c - Use a pot. to manage feed rate
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

#define ADC_VREF_TYPE (1 << REFS0) // AVCC (5V) with external capacitor at AREF pin

uint8_t feedratePotValue;

void InitFeedratePot()
{
  FEED_RATE_POT_DDR &= ~(FEED_RATE_POT_PIN); // Configure as input pin
  FEED_RATE_POT_PORT &= ~(FEED_RATE_POT_PIN); // Configure no pullup
  ADMUX = ADC_VREF_TYPE; // 5V reference
  ADCSRA = bit(ADEN) | bit(ADPS2) | bit(ADPS1) | bit(ADPS0); // ADC enabled, pre-scaler division=128.
  ADCSRB = 0; // AIN0 to AIN7
  ADMUX = FEED_RATE_POT_INPUT|ADC_VREF_TYPE; // select input
  ADCSRA |= (1 << ADSC); // Start first AD conversion
}

void UpdateFeedratePotValue()
{
  static uint8_t feedratePotValueMem;
  if (bit_is_clear(ADCSRA,ADSC)) // If the AD conversion is complete
    {
      feedratePotValue = ADC>>2; // Update value/4 -> (0 - 255)
      ADCSRA |= (1 << ADSC);     // Start another AD conversion

      if (feedratePotValueMem != feedratePotValue)
        {
          feedratePotValueMem = feedratePotValue;
          sys.f_override = feedratePotValueMem;
          // Rapid must don't exced DEFAULT_RAPID_OVERRIDE
          if (feedratePotValueMem > DEFAULT_RAPID_OVERRIDE) {feedratePotValueMem = DEFAULT_RAPID_OVERRIDE;}
          sys.r_override = feedratePotValueMem;
          sys.report_ovr_counter = 0; // Set to report change immediately
          plan_update_velocity_profile_parameters();
          plan_cycle_reinitialize();
        }
    }
}
