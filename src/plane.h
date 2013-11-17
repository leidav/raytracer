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

#ifndef PLANE_H
#define PLANE_H


#include "scene_geometry.h"

class Plane : public SceneGeometry
{
public:

	Plane(Scene *scene, Shader *shader);

	Plane(Scene *scene, const Mat4 &transform, Shader *shader);

	virtual ~Plane(){}

	void setNormal(Vec3 normal);

	bool intersect(const Ray &r,Vec3 &pos,Vec3 &normal);

	ScObjType type() const;

protected:
	
	Vec3 _normal;
	
};
#endif
