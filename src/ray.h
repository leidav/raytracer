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

#ifndef RAY_H
#define RAY_H

#include "vector.h"

class Ray
{
public:

	Vec3 origin;
	Vec3 dir;		

	Ray():origin(Vec3()),dir(Vec3())
	{
	}

	Ray(const Vec3 &origin, const Vec3 &dir)
	{
		this->origin=origin;
		this->dir=dir;
	}

	Ray(const Ray &r):origin(r.origin),dir(r.dir)
	{
	}

	virtual ~Ray() {}
	
	inline Vec3 posAt(float a) const
	{
		return origin+dir*a;
	}

};
#endif
