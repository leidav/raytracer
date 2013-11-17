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

#include "sphere.h"
#include "math.h"
#include <stdio.h>

Sphere::Sphere(Scene *scene, Shader *shader):SceneGeometry(scene,shader)
{
}

Sphere::Sphere(Scene *scene, const Mat4 &transform_matrix,Shader *shader)
	:SceneGeometry(scene, transform_matrix,shader)
{
}
void Sphere::setRadius(float r)
{
	_radius=r;
}

bool Sphere::intersect(const Ray &r)
{
	Vec3 q;
	float a;
	
	a=r.dir*(_pos-r.origin);
	q=r.origin+r.dir*a;

	if((q-_pos).squareLength()>square(_radius)) {
		return false;
	}
	else {
		return true;
	}
}

bool Sphere::intersect(const Ray &r,Vec3 &p,Vec3 &n)
{
	Vec3 q;
	float a;
	float x;

	a=r.dir*(_pos-r.origin);
	q=r.origin+r.dir*a;
	
	if((q-_pos).squareLength()>square(_radius)) {
		return false;
	}
	else {
		
		x=std::sqrt(square(_radius)-((q-_pos).squareLength()));
		if(a>=x) {
			p=r.origin+r.dir*(a-x);
			n=p-_pos;
		}
		else if(a+x>0) {
			p=r.origin+r.dir*(a+x);
			n=p-_pos;
		}
			n.normalize();
			return true;
	}
		return false;
	
}

bool Sphere::intersect(Intersection &i)
{
	/*Vec3 pos;
	Vec3 q;
	float a;
	float x;

	pos=_transform*pos;
	a=r.dir()*(r.origin()-pos)*-1;
	q=r.origin()+r.dir()*a;
	
	if((q-pos).length()>_radius) {
		return false;
	}
	else {
		
		x=sqrt(_radius*_radius-((q-pos).length()*(q-pos).length()));
		if(a>=x) {
			p=r.origin()+r.dir()*(a-x);
			n=p-pos;
		}
		else if(a+x>0) {
			p=r.origin()+r.dir()*(a+x);
			n=p-pos;
		}
			n.normalize();
			return true;
	}
		return false;*/
	return false;
	
}

ScObjType Sphere::type() const
{
	return SCOBJ_PRIMITIV_SPHERE;
}
