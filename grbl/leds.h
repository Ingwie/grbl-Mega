/*
  leds.h - Add leds output to show states
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

#ifndef leds_h
#define leds_h

  #define GREEN_LED_ON      STATUS_LED_PORT |= GREEN_LED
  #define GREEN_LED_OFF     STATUS_LED_PORT &= ~GREEN_LED
  #define RED_LED_ON        STATUS_LED_PORT |= RED_LED
  #define RED_LED_OFF       STATUS_LED_PORT &= ~RED_LED
  #define ORANGE_LED_ON     STATUS_LED_PORT |= (GREEN_LED | RED_LED)// bicolor led used ;-)
  #define ORANGE_LED_OFF    STATUS_LED_PORT &= ~(GREEN_LED | RED_LED)

  void InitStatusLeds();

  void UpdateStatusLeds();

#endif // leds_h
