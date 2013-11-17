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

#ifndef SCENE_H
#define SCENE_H


#include <vector>

class Shader;
class SceneGeometry;
class SceneLight;
class Camera;
class ImageBuffer;
class Ray;

class Scene
{
public:
	Scene();

	virtual ~Scene() {}
	
	void addCamera(Camera *cam);

	void addLight(SceneLight *light);

	void addGeometry(SceneGeometry *geometry);

	void addShader(Shader *shader);

	inline Camera* getCamera() {return _camera;};

	inline std::vector<SceneLight*> getLights() const {return _lights;}

	inline std::vector<SceneGeometry*> getGeometry() const {return _geometry;}

	inline std::vector<Shader*> getShaders() const {return _shaders;}

	bool trace(SceneGeometry **obj,const Ray &ray,Vec3 &pos,Vec3 &normal);

	bool trace(const Ray &ray);

	void render(ImageBuffer &buffer,const Color &bg);
	
protected:
	int _max_distance;

	Camera *_camera;
	std::vector<SceneGeometry*> _geometry;
	std::vector<SceneLight*> _lights;
	std::vector<Shader*> _shaders;
};
#endif
