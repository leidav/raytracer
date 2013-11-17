#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_main.h>
#include <string>

#include "color.h"
#include "vector.h"
#include "matrix.h"
#include "sphere.h"
#include "plane.h"
#include "camera.h"

#include "scene.h"
#include "blinn.h"
#include "scene_light.h"
#include "image_buffer.h"

const int WIDTH=1280;
const int HEIGHT=720;

int main(int argc, char *argv[])
{
	ImageBuffer image_buffer(WIDTH,HEIGHT);
	unsigned int* imgbuf=new unsigned int[WIDTH*HEIGHT];

	Color bg=Color(0.05088,0.05088,0.05088);

	Scene scene;

	Camera cam(&scene);
	SceneLight light(&scene);
	SceneLight light2(&scene);

	light.setDiffuseColor(Color(0.5,0.093,0.106));
	light.setSpecularColor(Color(0.5,0.093,0.106));
	light2.setDiffuseColor(Color(1*0.067,1*0.426,1*1));
	light2.setSpecularColor(Color(1*0.067,1*0.426,1*1));
	
	BlinnShader blinnshader(&scene,Color(0,0,0),Color(0.8,0.8,0.8),Color(0.5,0.5,0.5),50);
	Sphere sphere1(&scene,&blinnshader);
	Sphere sphere2(&scene,&blinnshader);
	Sphere sphere3(&scene,&blinnshader);
	Sphere sphere4(&scene,&blinnshader);
	Sphere sphere5(&scene,&blinnshader);
	
	Mat4 sphere_pos;
	Mat4 cam_pos;
	
	Mat4 light_pos;

	Vec3 cam_dir(0,0,1);
	Vec3 cam_up(0,1,0);
	
	light_pos.translate(20,25,-20);
	light.setTransformMatrix(light_pos);

	light_pos.identity();
	light_pos.translate(-20,25,-20);
	light2.setTransformMatrix(light_pos);

	cam_pos.identity();
	cam_pos.translate(0,0,1);
	cam_pos.rotateX(rad(0));

	cam.setTransformMatrix(cam_pos);
	cam.setDir(cam_dir);
	cam.setUp(cam_up);
	cam.setAspectRatio((float)WIDTH/HEIGHT);
	cam.setFocalLenght(35);
	cam.setSensorWidth(36);
	
	sphere1.setRadius(0.5);
	sphere2.setRadius(0.2);
	sphere3.setRadius(0.2);
	sphere4.setRadius(0.2);
	sphere5.setRadius(0.2);

	sphere_pos.identity();
	sphere_pos.translate(0,0,5);
	sphere1.setTransformMatrix(sphere_pos);

	sphere_pos.identity();
	sphere_pos.translate(0.6,0,4);
	sphere2.setTransformMatrix(sphere_pos);

	sphere_pos.identity();
	sphere_pos.translate(-0.6,0,4);
	sphere3.setTransformMatrix(sphere_pos);

	sphere_pos.identity();
	sphere_pos.translate(0,0.6,4);
	sphere4.setTransformMatrix(sphere_pos);

	sphere_pos.identity();
	sphere_pos.translate(0,-0.6,4);
	sphere5.setTransformMatrix(sphere_pos);

	scene.addLight(&light);
	scene.addLight(&light2);
	scene.addGeometry(&sphere1);
	scene.addGeometry(&sphere2);
	scene.addGeometry(&sphere3);
	scene.addGeometry(&sphere4);
	scene.addGeometry(&sphere5);
	scene.addCamera(&cam);

	scene.render(image_buffer,bg);
	image_buffer.toIntArray(imgbuf);


/*SDL*/
	bool isrunning=true;
	SDL_Event event;
	SDL_Window *screen;
	SDL_Renderer *renderer;
	SDL_Texture *screen_texture;
	
	screen = SDL_CreateWindow("Raytracer",SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED,
					WIDTH,HEIGHT,0);
	
	renderer = SDL_CreateRenderer(screen, -1, 0);
	screen_texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA8888,
						SDL_TEXTUREACCESS_STREAMING,
						WIDTH,HEIGHT);

	SDL_UpdateTexture(screen_texture, NULL, imgbuf,
				WIDTH*sizeof(unsigned int));

	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);



	SDL_RenderCopy(renderer, screen_texture, NULL, NULL);
	SDL_RenderPresent(renderer);

	while(isrunning) {
		while(SDL_PollEvent(&event)) {
			if(event.type==SDL_QUIT) {
				isrunning=false;
			}
		}
	
		
	}

	delete[] imgbuf;
	free(screen);
	free(renderer);
	free(screen_texture);

	return 0;
}
