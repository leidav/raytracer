/*Copyright (C) 2013 David Leiter

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MATH_H
#define MATH_H

#include <cmath>

const float PI =3.14159265;
const float MAX_DIFF =0.00001;

inline float rad(float a) { return a*PI/180.0; }
inline float deg(float a) { return a*180.0/PI;}
inline float square(float a) {return a*a;}
inline bool floatcmp(float a, float b) {return std::fabs(a-b)<=MAX_DIFF;}

inline float clamp(float min, float max, float val)
{
	return val>min ? (val<max ? val : max) : min;
}
#endif
