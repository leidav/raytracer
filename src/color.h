/*Copyright (C) 2011 David Leiter

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
#ifndef COLOR_H
#define COLOR_H
class Color
{
public:
	Color();
	
	virtual ~Color(){};
	
	Color(float r, float g, float b);

	Color(const Color &c);
	
	void setHsv(float hue, float saturation, float value);

	void set(float r, float g, float b);

	void set(const float c[3]);

	void set(unsigned int rgb);

	void r(float r);
	
	void g(float g);

	void b(float b);

	unsigned int rgb() const;

	float r() const;
	
	float g() const;
	
	float b() const;

	float operator[] (int pos) const;

	float& operator[](int pos);

	void normalize();

	Color operator* (const Color &c) const;
	
	const Color& operator*= (const Color &c);
	
	Color operator* (float s) const;

	const Color& operator*= (float s);

	Color operator/ (const Color &c) const;
	
	const Color& operator/= (const Color &c);
	
	Color operator/ (float s) const;

	const Color& operator/= (float s);

	Color operator+ (const Color &c) const;
	
	const Color& operator+= (const Color &c);

	Color operator- (const Color &c) const;

	const Color& operator-= (const Color &c);
	
	bool operator== (const Color &c);	
	
	const Color& operator= (const Color &c);
		
private:
	float _r;
	float _g;
	float _b;
};
#endif
