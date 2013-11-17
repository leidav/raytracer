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

#include "shader.h"
#include "scene.h"
#include "scene_light.h"

#include <vector>

Shader::Shader(Scene *scene):_scene(scene)
{
}

void Shader::setScene(Scene *scene) 
{
	_scene=scene;
}

Color Shader::lightLoop(const Vec3 &pos, const Vec3 &normal)
{
	Color c;
	std::vector<SceneLight*> lights=_scene->getLights();
	
	for(std::vector<SceneLight*>::const_iterator i=lights.begin();i!=lights.end();i++) {

		c+=forEachLight(pos,normal,**i);
	}
	return c;
}

Color Shader::forEachLight(const Vec3 &pos,const Vec3 &normal,
				const SceneLight &light)
{
	return Color(0,0,0);
}

float Shader::diffuse(const Vec3 &pos,const Vec3 &normal,const SceneLight &light)
{
	Vec3 light_pos;
	Vec3 dir;

	light_pos=light.getPos();
	dir=light_pos-pos;
	dir.normalize();

	float diff=(normal*dir);
	if(diff<0) {
		diff=0.0f;
	}
	return diff;
}

float  Shader::specular(const Vec3 &pos,const Vec3 &normal,
			const SceneLight &light,float hardness)
{
	Vec3 h;
	Vec3 v=pos*-1;
	Vec3 l=light.getPos()-pos;
	v.normalize();
	l.normalize();
	h=l+v;
	h.normalize();

	return pow(h*normal,hardness);
}

