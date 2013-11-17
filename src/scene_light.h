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

#ifndef SCENE_LIGHT_H
#define SCENE_LIGHT_H


#include "scene_object.h"
#include "color.h"

class SceneLight: public SceneObject
{
public:
	SceneLight(Scene *scene);
	
	virtual ~ SceneLight() {}

	SceneLight(Scene *scene, const Mat4 &transform_matrix);

	void setAmbientColor(const Color &c);

	void setDiffuseColor(const Color &c);

	void setSpecularColor(const Color &c);

	bool isVisible(const Vec3 &surface_pos) const;

	inline Color getAmbientColor() const 
	{
		return _ambient*_factor;
	}

	inline Color getDiffuseColor() const 
	{
		return _diffuse*_factor;
	}

	inline Color getSpecularColor() const 
	{ 
		return _specular*_factor;
	}

	ScObjType type() const;

protected:

	Color _ambient;
	Color _diffuse;
	Color _specular;
	float _factor;
};

#endif
