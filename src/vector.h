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

#ifndef VECTOR_H
#define VECTOR_H

#include "math.h"

class Vec3
{
public:
	float x;
	float y;
	float z;

	Vec3():x(0),y(0),z(0){}

	virtual ~Vec3(){}

	Vec3(const Vec3 &v):x(v.x),y(v.y),z(v.z){}

	Vec3(float x,float y, float z)
	{
		this->x=x;
		this->y=y;
		this->z=z;
	}
	
	//phy -> vertical angle, theta -> horizontal angle
	void set(float length, float phy, float theta)
	{	
	
		float t=length*cos(phy);
		y=length*sin(phy);
		x=t*sin(theta);
		z=t*cos(theta);
	
	}

	void normalize()
	{
		float il = 1.0f/length();
		x*=il;
		y*=il;
		z*=il;
	}

	inline float length() const
	{
		return std::sqrt(square(x)+square(y)+square(z));
	}

	inline float squareLength() const
	{
		return square(x)+square(y)+square(z);
	}
	
	//the angle between two vectors
	float angle(const Vec3 &v) const
	{
		float l = length();
		if(l)
			return acos(dot(v)/(l*v.length()));
		else 
			return 0;
	}
	
	float phy() const
	{
		float l= length();
		if(l) 
			return asin(y/l);
		else 
			return 0;
	}

	float theta() const
	{
		float l= length();
		if(l) 
			return acos(z/std::sqrt(square(l)-square(y)));
		else 
			return 0;
	}
	inline float dot(const Vec3 &v) const
	{
		return x*v.x+y*v.y+z*v.z;
	}

	inline Vec3 cross(const Vec3 &v) const
	{
		return Vec3(y*v.z-z*v.y,z*v.x-x*v.z,x*v.y-y*v.x);
	}

	//dot product as operator
	inline float operator* (const Vec3 &v) const
	{
		return x*v.x+y*v.y+z*v.z;
	}

	inline Vec3 operator* (float s) const
	{
		return Vec3(x*s,y*s,z*s);
	}
	
	inline Vec3& operator*= (float s)
	{
		x*=s;
		y*=s;
		z*=s;

		return *this;
	}
	
	inline Vec3 operator/ (float s) const
	{
		return Vec3(x/s,y/s,z/s);
	}

	inline Vec3&  operator/= (float s)
	{
		x/=s;
		y/=s;
		z/=s;

		return *this;
	}

	inline Vec3 operator+ (const Vec3 &v) const
	{
		return Vec3(x+v.x,y+v.y,z+v.z);	
	}

	inline Vec3 operator- (const Vec3 &v) const
	{
		return Vec3(x-v.x,y-v.y,z-v.z);	
	}

	inline Vec3& operator+= (const Vec3 &v)
	{
		x+=v.x;
		y+=v.y;
		z+=v.z;

		return *this;
	}

	inline Vec3& operator-= (const Vec3 &v)
	{
		x-=v.x;
		y-=v.y;
		z-=v.z;

		return *this;
	}
	
	inline Vec3& operator= (const Vec3 &v)
	{
		x=v.x;
		y=v.y;
		z=v.z;

		return *this;
	}

	bool operator==(const Vec3 &v) const
	{
		if(floatcmp(x,v.x)&&floatcmp(y,v.y)&&floatcmp(z,v.z))
			return true;
		else
			return false;
	}
};

#endif

