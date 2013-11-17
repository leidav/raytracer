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

#include "scene_light.h"
#include "scene.h"
#include "ray.h"


SceneLight::SceneLight(Scene *scene):SceneObject(scene),_ambient(Color(0,0,0)),
				_diffuse(Color(1,1,1)),_specular(Color(0,0,0)),
				_factor(1)
{
}

SceneLight::SceneLight(Scene *scene, const Mat4 &transform_matrix): 
				SceneObject(scene, transform_matrix),
				_ambient(Color(0,0,0)),_diffuse(Color(1,1,1)),
				_specular(Color(0,0,0)),_factor(1)
{
}

bool SceneLight::isVisible(const Vec3 &surface_pos) const
{
	Vec3 dir=_pos-surface_pos;
	dir.normalize();
	Ray r(surface_pos,dir);
	if(_scene->trace(r)==true) {
		return false;
	}

	return true;
}

void SceneLight::setAmbientColor(const Color &c)
{
	_ambient=c;
}

void SceneLight::setDiffuseColor(const Color &c)
{
	_diffuse=c;
}

void SceneLight::setSpecularColor(const Color &c)
{
	_specular=c;
}


ScObjType SceneLight::type() const
{
	return SCOBJ_LAMP_POINT;
}
