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

#ifndef SHADER_H
#define SHADER_H

#include "color.h"
#include "vector.h"

class Scene;
class SceneLight;

struct SurfacePoint
{
	Vec3 pos;
	Vec3 normal;
};

class Shader
{
public:

	Shader(Scene *scene);

	virtual ~Shader() {}

	void setScene(Scene *scene);

	virtual Color shade(const Vec3 &pos,const Vec3 &normal)=0;


protected:
	//helper functions
	float diffuse(const Vec3 &pos,const Vec3 &normal,
			const SceneLight &light);

	float specular(const Vec3 &pos,const Vec3 &normal,
			const SceneLight &light,float hardness);

	Color lightLoop(const Vec3 &pos,const Vec3 &normal);
	
	virtual Color forEachLight(const Vec3 &pos,const Vec3 &normal,
					const SceneLight &light);


	Scene *_scene;
};

#endif
