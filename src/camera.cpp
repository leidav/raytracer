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


#include "camera.h"
#include <stdio.h>

Camera::Camera(Scene *scene):SceneObject(scene),_aspect(1)
{
	_aspect=1;
	_length=35;
	_width=36;
	_dir.z=1;
	_up.y=1;
	_dir*=_length;

}

Camera::Camera(Scene *scene,const Mat4 &transform,const Vec3 &dir,const Vec3 &up,float aspect):
	SceneObject(scene,transform),_aspect(aspect),_length(35),_width(36),_dir(dir),_up(up)
{
}

void Camera::getViewPlane(ViewPlane &view)
{
	Vec3 right=_up.cross(_dir);
	right.normalize();
	view.width=right*_width/2;
	view.height=_up*(_width/(_aspect*2));
	view.midpoint=getPos()+_dir;
}

void Camera::setDir(const Vec3 &dir)
{
	_dir=dir;
}

void Camera::setUp(const Vec3 &up)
{
	_up=up;
	_up.normalize();
}

void Camera::setAspectRatio(float aspect)
{
	_aspect=aspect;
}

void Camera::setFocalLenght(float length)
{
		_length=length;
		_dir.normalize();
		_dir*=length;
}

void Camera::setSensorWidth(float width)
{
	_width=width;
}

Vec3 Camera::getDir() const
{
	return _dir;
}

Vec3 Camera::getUp() const
{
	return _up;
}

float Camera::getAspectRatio() const
{
	return _aspect;
}

float Camera::getFocalLenght() const 
{
	return _length;
}

float Camera::getSensorWidth() const
{
	return _width;
}


ScObjType Camera::type() const 
{
	return SCOBJ_CAMERA;
}
