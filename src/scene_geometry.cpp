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

#include "scene_geometry.h"


SceneGeometry::SceneGeometry(Scene *scene, Shader *shader):SceneObject(scene),_shader(shader)
{
}

SceneGeometry::SceneGeometry(Scene *scene, const Mat4 &transform, Shader *shader):
		SceneObject(scene,transform),_shader(shader)
{
}

void SceneGeometry::setShader(Shader *shader)
{
	_shader=shader;
}

Color SceneGeometry::shade(const Vec3 &pos,const Vec3 &normal) 
{
	return _shader->shade(pos,normal);
}
