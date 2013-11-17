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

#include "plane.h"
#include "math.h"
#include <stdio.h>

Plane::Plane(Scene *scene, Shader *shader):SceneGeometry(scene, shader)
{
}

Plane::Plane(Scene *scene,const Mat4 &transform_matrix,Shader *shader)
	:SceneGeometry(scene,transform_matrix,shader)
{
}
void Plane::setNormal(Vec3 normal)
{
	_normal=normal;
}

bool Plane::intersect(const Ray &r,Vec3 &p,Vec3 &n)
{
	float a;
	float d=_normal*(_pos);
	float tmp=r.dir*_normal;
	if(tmp!=0) {

		a=(d-r.origin*_normal)/tmp;
		if(a>0) {
			n=_normal;
			
			return true;
		}
	}
	return false;
	
}

ScObjType Plane::type() const
{
	return SCOBJ_PRIMITIV_PLANE;
}
