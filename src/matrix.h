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

#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

class Mat4
{
public:
	Mat4()
	{
		identity();
	}	

	virtual ~Mat4(){}

	Mat4(const float entries[4][4])
	{
		set(entries);
	}
	
	Mat4(const float entries[16])
	{
		set(entries);
	}

	Mat4(float _11,float _12,float _13,float _14,
		float _21,float _22,float _23,float _24,
		float _31,float _32,float _33,float _34,
		float _41,float _42,float _43,float _44)
	{
		set(_11,_12,_13,_14,_21,_22,_23,_24,_31,
			_32,_33,_34,_41,_42,_43,_44);
	}

	Mat4(const Mat4 &m)
	{
		for(int i=0;i<16;i++) {
			_entries[i]=m[i];
		}
	}

	void set(const float entries[16])
	{
		for(int i=0;i<16;i++) {
			_entries[i]=entries[i];
		}
	}

	void set(const float entries[4][4])
	{
		for(int y=0;y<4;y++) {
			for(int x=0;x<4;x++) {
				_entries[y*4+x]=entries[y][x];
			}	
		}
	}
	

	void set(float _11,float _12,float _13,float _14,
		float _21,float _22,float _23,float _24,
		float _31,float _32,float _33,float _34,
		float _41,float _42,float _43,float _44)
	{
		_entries[0]=_11;
		_entries[1]=_12;
		_entries[2]=_13;
		_entries[3]=_14;

		_entries[4]=_21;
		_entries[5]=_22;
		_entries[6]=_23;
		_entries[7]=_24;

		_entries[8]=_31;
		_entries[9]=_32;
		_entries[10]=_33;
		_entries[11]=_34;

		_entries[12]=_41;
		_entries[13]=_42;
		_entries[14]=_43;
		_entries[15]=_44;

	}

	inline const float* get() const
	{
		return _entries;
	}
	
	void identity()
	{
		for(int y=0;y<4;y++) {
			for(int x=0;x<4;x++) {
				if(x==y) {
					_entries[y*4+x]=1;
				}
				else {
					_entries[y*4+x]=0;
				}
			}	
		}
	}

	void fill(float s)
	{
		for(int i=0;i<16;i++) {
			_entries[i]=s;
		}
	}
	
	inline float operator() (int y , int x) const
	{
		return _entries[y*4+x];
	}

	inline float& operator() (int y, int x)
	{
		return _entries[y*4+x];
	}

	inline float operator[] (int pos) const
	{
		return _entries[pos];
	}

	inline float& operator[] (int pos)
	{
		return _entries[pos];
	}

	inline void scaleX(float s)
	{
		Mat4 m;
		m(0,0)=s;
		*this=m*(*this);
	}

	inline void scaleY(float s)
	{
		Mat4 m;
		m(1,1)=s;
		*this=m*(*this);
	}

	inline void scaleZ(float s)
	{
		Mat4 m;
		m(2,2)=s;
		*this=m*(*this);
	}
		
	void scale(float x, float y, float z)
	{
		Mat4 m;
		//m.identity();
		m(0,0)=x;
		m(1,1)=y;
		m(2,2)=z;

		*this=m*(*this);
	}

	inline void scale(const Vec3 &v)
	{
		scale(v.x,v.y,v.z);
	}
	
	inline void translateX(float s)
	{
		Mat4 m;
		m(0,3)=s;
		*this=m*(*this);
	}

	inline void translateY(float s)
	{
		Mat4 m;
		m(1,3)=s;
		*this=m*(*this);
	}

	inline void translateZ(float s)
	{
		Mat4 m;
		m(1,3)=s;
		*this=m*(*this);
	}

	inline void translate(const Vec3 &v)
	{
		translate(v.x,v.y,v.z);
	}

	void translate(float x,float y, float z)
	{
		Mat4 m;
		m(0,3)=x;
		m(1,3)=y;
		m(2,3)=z;
		*this=m*(*this);
	}

	inline void rotateX(float s)
	{
		Mat4 m;
		m(1,1)=cos(s);
		m(1,2)=-sin(s);
		m(2,1)=sin(s);
		m(2,1)=cos(s);
		*this=m*(*this);
	
	}

	inline void rotateY(float s)
	{
		Mat4 m;
		m(0,0)=cos(s);
		m(0,2)=sin(s);
		m(2,0)=-sin(s);
		m(2,2)=cos(s);
		*this=m*(*this);
	
	}

	inline void rotateZ(float s)
	{
		Mat4 m;
		m(0,0)=cos(s);
		m(0,1)=-sin(s);
		m(1,0)=sin(s);
		m(1,1)=cos(s);
		*this=m*(*this);
	
	}

	void rotateZYX(float x,float y,float z)
	{
		Mat4 m;
		m(0,0)=cos(y)*cos(z);
		m(0,1)=-cos(y)*sin(z);
		m(0,2)=sin(y);
		m(1,0)=cos(x)*sin(z)+sin(x)*sin(y)*cos(z);
		m(1,1)=sin(x)*cos(z)+cos(x)*sin(y)*sin(z);
		m(1,2)=cos(x)*cos(y);
		*this=m*(*this);
	}

	inline void rotateZYX(const Vec3 &v)
	{
		rotateZYX(v.x,v.y,v.z);
	}
	
	Vec3 operator *(const Vec3 &v) const
	{
		Vec3 vec;
		vec.x=(*this)(0,0)*v.x+(*this)(0,1)*v.y
			+(*this)(0,2)*v.z+(*this)(0,3);

		vec.y=(*this)(1,0)*v.x+(*this)(1,1)*v.y
			+(*this)(1,2)*v.z+(*this)(1,3);

		vec.z=(*this)(2,0)*v.x+(*this)(2,1)*v.y
			+(*this)(2,2)*v.z+(*this)(2,3);

		return vec;	
	}

	Mat4 operator* (const Mat4 &m) const
	{
		Mat4 tmp;
		for(int y=0;y<4;y++) {
			for(int x=0;x<4;x++) {
				for(int i=0;i<4;i++) {
					tmp(y,x)+=_entries[y*4+i]*m(i,x);	
				}
			}
		}
		return tmp;
	}

	Mat4  operator* (float s) const
	{
		Mat4 tmp;
		for(int i=0;i<16;i++) {
			tmp[i]=_entries[i]*s;
		}	
		return tmp;
	}
	
	Mat4& operator*= (float s)
	{
		for(int i=0;i<16;i++) {
			_entries[i]*=s;
		}
		return *this;	
	}


	Mat4& operator*= (const Mat4 &m)
	{
		Mat4 tmp;
		for(int y=0;y<4;y++) {
			for(int x=0;x<4;x++) {
				for(int i=0;i<4;i++) {
					tmp(y,x)+=_entries[y*4+i]*m(i,x);	
				}
			}
		}
		*this=tmp;
		return *this;
	}
	
	Mat4 operator/ (float s) const
	{
		Mat4 tmp;
		for(int i=0;i<16;i++) {
			tmp[i]=_entries[i]/s;
		}	
		return tmp;
	}

	Mat4& operator/= (float s)
	{
		for(int i=0;i<16;i++) {
			_entries[i]/=s;
		}
		return *this;
	}

	Mat4  operator+ (const  Mat4 &m) const
	{
		Mat4 tmp;
		for(int i=0;i<16;i++) {
			tmp[i]=_entries[i]+m[i];
		}	
		return tmp;
	}

	Mat4  operator- (const  Mat4 &m) const
	{
		Mat4 tmp;
		for(int i=0;i<16;i++) {
			tmp[i]=_entries[i]-m[i];
		}	
		return tmp;
	}

	Mat4& operator+= (const  Mat4 &m)
	{
		for(int i=0;i<16;i++) {
			_entries[i]+=m[i];
		}
		return *this;
	}


	Mat4& operator-= (const  Mat4 &m)
	{
		for(int i=0;i<16;i++) {
			_entries[i]-=m[i];
		}
		return *this;
	}
	
	Mat4& operator= (const  Mat4 &m)
	{
		for(int i=0;i<16;i++) {
			_entries[i]=m[i];
		}
		return *this;
	}

	bool operator==(const  Mat4 &m) const
	{
		for(int i=0;i<16;i++) {
			if(floatcmp(_entries[i],m[i])!=true)
				return false;
		}
		return true;
	}

	
protected:
	float _entries[16];
};

#endif
