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


#include "vector.h"
#include "ray.h"
#include "camera.h"
#include "sphere.h"
#include "image_buffer.h"
#include "scene.h"

Scene::Scene()
{
	_max_distance=1000000;
}

void Scene::addCamera(Camera *cam)
{
	_camera=cam;
}
void Scene::addLight(SceneLight *light)
{
	_lights.push_back(light);
}

void Scene::addShader(Shader *shader)
{
	_shaders.push_back(shader);
}

void Scene::addGeometry(SceneGeometry *geometry)
{
	_geometry.push_back(geometry);
}

bool Scene::trace(const Ray &ray)
{
	for(std::vector<SceneGeometry*>::const_iterator i=_geometry.begin();
		i!=_geometry.end();i++) {
			if((*i)->intersect(ray)==true) {
				return true;
			}
	}
	return false;
}

bool Scene::trace(SceneGeometry **obj,const Ray &ray,Vec3 &pos,Vec3 &normal)
{
	bool hit=false;
	float distance=_max_distance;
	for(std::vector<SceneGeometry*>::const_iterator i=_geometry.begin();
		i!=_geometry.end();i++) {
			if((*i)->intersect(ray,pos,normal)==true) {
				hit=true;
				if(pos.squareLength()<distance) {		
					*obj=*i;
					distance=pos.squareLength();
				}
			}
			
	}

	return hit;
}

void Scene::render(ImageBuffer &buffer,const Color &bg)
{
	int buffer_width;
	int buffer_height;

	Vec3 dir;
	Vec3 intersection;
	Vec3 pos0;
	Vec3 dx,dy;
	Vec3 normal;

	Ray ray;
	ViewPlane view;
	SceneGeometry *geometry;

	buffer_width=buffer.getWidth();
	buffer_height=buffer.getHeight();

	_camera->getViewPlane(view);
	pos0=view.midpoint-view.width+view.height;
	
	dx=(view.width*2.0)/buffer_width;
	dy=(view.height*2.0)/buffer_height;

	dir=pos0;
	ray.origin=_camera->getPos();
	
	for(int y=0;y<buffer_height;y++) {
		for(int x=0;x<buffer_width;x++) {
			ray.dir=dir;
			ray.dir.normalize();

			if(trace(&geometry,ray,intersection,normal)==true) {
				buffer(x,y)=geometry->shade(intersection,normal);			
			}
			else {			
				buffer(x,y)=bg;
			}
			dir+=dx;
		}
		dir.x=pos0.x;
		dir-=dy;
	}
}
