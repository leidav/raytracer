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

#ifndef SCENE_OBJECT_H
#define SCENE_OBJECT_H

#include "matrix.h"

enum ScObjType
{
	SCOBJ_CAMERA,
	SCOBJ_LAMP_POINT,
	SCOBJ_PRIMITIV_SPHERE,
	SCOBJ_PRIMITIV_TRIANGLE,
	SCOBJ_PRIMITIV_PLANE,
	SCOBJ_MESH,
	SCOBJ_SURFACE
};

class Scene;

class SceneObject
{
public:
	SceneObject(Scene *scene);

	virtual ~SceneObject() {}

	SceneObject(Scene *scene, const Mat4 &transform_matrix);

	void setTransformMatrix(const Mat4 &transform_matrix);

	Mat4 getTransformMatrix() const;

	void transform();

	inline Vec3 getPos() const { return _pos; }

	virtual ScObjType type() const = 0;

protected:
	Scene *_scene;
	Mat4 _transform_matrix;
	Vec3 _pos;
	
	
};

#endif
