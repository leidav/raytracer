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

#ifndef CAMERA_H
#define CAMERA_H


#include "scene_object.h"
#include "matrix.h"
#include "vector.h"
#include "math.h"

struct ViewPlane
{
	Vec3 midpoint;
	Vec3 width;
	Vec3 height;
};

class Camera: public SceneObject
{
public:
	Camera(Scene *scene);

	virtual ~Camera() {}

	Camera(Scene *scene, const Mat4 &transform,const Vec3 &dir,const Vec3 &up,float aspect);

	void setDir(const Vec3 &dir);

	void setUp(const Vec3 &up);

	//void setAngle(float angle);

	void setAspectRatio(float aspect);
	
	void setFocalLenght(float length);

	void setSensorWidth(float width);

	Vec3 getDir() const;

	Vec3 getUp() const;

	//float getAngle() const;

	float getAspectRatio() const;

	float getFocalLenght() const;

	float getSensorWidth() const;

	void getViewPlane(ViewPlane &view);
	
	ScObjType type() const;

protected:
	float _aspect;
	float _length;
	float _width;

	Vec3 _dir;
	Vec3 _up;
};

#endif
