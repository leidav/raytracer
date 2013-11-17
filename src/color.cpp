/*Copyright (C) 2013 David Leiter

floathis program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

floathis program is distributed in the hope that it will be useful,
but WIfloatHOUfloat ANY WARRANfloatY; without even the implied warranty of
MERCHANfloatABILIfloatY or FIfloatNESS FOR A PARfloatICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "color.h"
#include "math.h"
#include <cstdio>
Color::Color():_r(0),_g(0),_b(0)
{
}

Color::Color(float r, float g, float b):_r(r),_g(g),_b(b)
{
}

Color::Color(const Color &c):_r(c.r()),_g(c.g()),_b(c.b())
{
}


void Color::setHsv(float hue, float saturation, float value)
{
}

void Color::set(float r, float g, float b)
{
	_r=r;
	_g=g;
	_b=b;
}
void Color::set(const float c[3])
{
	_r=c[0];
	_g=c[1];
	_b=c[2];
}

void Color::set(unsigned int rgb)
{
	_r=(float)(rgb>>16)/255;
	_g=(float)((rgb>>8)&0xFFFF)/255;
	_b=(float)(rgb&0xFF)/255;
}

unsigned int Color::rgb() const
{
	float r,g,b;

	if(_r>1.0) {
		r=1.0;
	}
	else {
		r=_r;
	}
	
	if(_g>1.0) {
		g=1.0;
	}
	else {
		g=_g;
	}

	if(_b>1.0) {
		b=1.0;
	}
	else {
		b=_b;
	}

	r=pow(r,1/2.2f);
	g=pow(g,1/2.2f);
	b=pow(b,1/2.2f);
	
	int rgb=0;
	rgb=((int)(r*255))<<24;
	rgb+=((int)(g*255))<<16;
	rgb+=((int)(b*255)<<8);
	
	return rgb;
	
}

void Color::r(float r)
{
	_r=r;
}

void Color::g(float g)
{
	_g=g;
}

void Color::b(float b)
{
	_b=b;
}

float Color::r() const
{
	return _r;
}

float Color::g() const
{
	return _g;
}
	
float Color::b() const
{
	return _b;
}

float Color::operator[] (int pos) const
{
	switch(pos) { 
		case 1:
			return _g;
		case 2: 
			return _b; 
		default:
			return _r;
	}
}
float& Color::operator[](int pos)
{
	switch(pos) { 
		case 1:
			return _g;
		case 2: 
			return _b; 
		default:
			return _r;
	}
}
void Color::normalize()
{
	float l=sqrt(square(_r)+square(_g)+square(_b));
	if(!l)
		return;
	
	_r/=l;
	_g/=l;
	_b/=l;
}

Color Color::operator* (const Color &c) const
{
	return Color(_r*c.r(),_g*c.g(),_b*c.b());
}
	
const Color& Color::operator*= (const Color &c)
{
	_r*=c.r();
	_g*=c.g();
	_b*=c.b();
	return *this;
}
	
Color Color::operator* (float s) const
{
	return Color(_r*s,_g*s,_b*s);
}

const Color&  Color::operator*= (float s)
{
	_r*=s;
	_g*=s;
	_b*=s;
	return *this;
}

Color Color::operator/ (const Color &c) const
{
	return Color(_r/c.r(),_g/c.g(),_b/c.b());
}
	
const Color& Color::operator/= (const Color &c)
{
	_r/=c.r();
	_g/=c.g();
	_b/=c.b();
	return *this;
}
	
Color  Color::operator/ (float s) const
{
	return Color(_r/s,_g/s,_b/s);
}

const Color& Color::operator/= (float s)
{
	_r/=s;
	_g/=s;
	_b/=s;
	return *this;
}

Color Color::operator+ (const Color &c) const
{
	return Color(_r+c.r(),_g+c.g(),_b+c.b());
}
	
const Color& Color::operator+= (const Color &c)
{
	_r+=c.r();
	_g+=c.g();
	_b+=c.b();
	return *this;
}

Color Color::operator- (const Color &c) const
{
	return Color(_r-c.r(),_g-c.g(),_b-c.b());
}

const Color& Color::operator-= (const Color &c)
{
	_r-=c.r();
	_g-=c.g();
	_b-=c.b();
	return *this;
}
	
bool Color::operator== (const Color &c)
{
	if(floatcmp(_r,c.r())&&floatcmp(_g,c.g())&&floatcmp(_b,c.b()))
		return true;
	else
		return false;
}	
	
const Color& Color::operator= (const Color &c)
{
	if(this==&c)
		return *this;

	_r=c.r();
	_g=c.g();
	_b=c.b();
	return *this;
}
