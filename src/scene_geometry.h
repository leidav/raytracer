/*Copyright (C) 2012 David Leiter

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

#ifndef SCENE_GEOMETRY_H
#define SCENE_GEOMETRY_H


#include "scene_object.h"
#include "ray.h"

#include "shader.h"
class Shader;
class Color;

struct Intersection
{
	Ray r;
	Vec3 p;
	Vec3 n;
};

class SceneGeometry: public SceneObject
{
public:
	SceneGeometry(Scene *scene, Shader *shader);
	
	virtual ~SceneGeometry() {}

	SceneGeometry(Scene *scene, const Mat4 &transform, Shader *shader);

	void setShader(Shader *shader);

	Color shade(const Vec3 &pos,const Vec3 &normal);
	
	virtual bool intersect(const Ray &r,Vec3 &pos,Vec3 &normal)=0;

	virtual bool intersect(Intersection &i)=0;
	
	virtual bool intersect(const Ray &r)=0;

protected:
	Shader *_shader;
};

#endif
