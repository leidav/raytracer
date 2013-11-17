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

#include "blinn.h"
#include "color.h"
#include "vector.h"
#include "scene.h"
#include "scene_light.h"

BlinnShader::BlinnShader(Scene *scene,const Color &ambient, const Color &diffuse, const Color &specular,
		float hardness):Shader(scene),_ambient(ambient),
		_diffuse(diffuse),_specular(specular),_hardness(hardness)
{
}

Color BlinnShader::shade(const Vec3 &pos,const Vec3 &normal)
{
	return lightLoop(pos,normal);
}

Color BlinnShader::forEachLight(const Vec3 &pos,const Vec3 &normal,
					const SceneLight &light)
{
	/*if(light.isVisible(pos)==true) {*/
		return light.getDiffuseColor()*diffuse(pos,normal,light)*_diffuse+light.getAmbientColor()*_ambient+
			light.getSpecularColor()*specular(pos,normal,light,_hardness)*_specular;
	/*}
	else {
		return Color(0,0,0);
	}*/
}
