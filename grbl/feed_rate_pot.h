/*
  fedd_rate_pot.h - Use a pot. to manage feed rate
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

#ifndef feed_rate_pot_h
#define feed_rate_pot_h

uint8_t feedratePotValue;

void InitFeedratePot();
void UpdateFeedratePotValue();

#endif // feed_rate_pot_h
