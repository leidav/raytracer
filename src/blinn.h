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

#ifndef BLINN_H
#define BLINN_H

#include "shader.h"

class BlinnShader : public Shader
{
public:

	BlinnShader(Scene *scene,const Color& ambient, const Color& diffuse, const Color& specular,
		float hardness);

	virtual ~BlinnShader() {}

	void setColor(Color ambient, Color diffuse, Color specular);

	void setDiffuseColor(Color diffuse);
	
	void setAmbientColor(Color ambient);

	void setSpecularColor(Color specular);

	void setHardness(float hardness);

	Color shade(const Vec3 &pos,const Vec3 &normal);
	
	Color forEachLight(const Vec3 &pos,const Vec3 &normal,
					const SceneLight &light);

protected:

	Color _ambient;
	Color _diffuse;
	Color _specular;
	float _hardness;
};

#endif
