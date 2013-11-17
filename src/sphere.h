/*Copyright (C) 2011 David Leiter

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

#ifndef SPHERE_H
#define SPHERE_H


#include "scene_geometry.h"

class Sphere : public SceneGeometry
{
public:

	Sphere(Scene *scene, Shader *shader);

	Sphere(Scene *scene, const Mat4 &transform_matrix, Shader *shader);

	virtual ~Sphere(){}	

	void setRadius(float r);

	bool intersect(const Ray &r,Vec3 &pos,Vec3 &normal);

	bool intersect(Intersection &i);

	bool intersect(const Ray &r);

	ScObjType type() const;

protected:
	
	float _radius;
};
#endif
