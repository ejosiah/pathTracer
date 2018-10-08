#pragma once
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtc/matrix_access.hpp>
#include <glm/gtc/constants.hpp>
#include <ncl/gl/rayTracingUtilities.h>
#include <vector>
#include <tuple>
#include <utility>
#include <iterator>

using namespace std;
using namespace ncl;
using namespace gl;
using namespace glm;

vector<ray_tracing::Sphere> initSceneObjects2() {
	ray_tracing::Sphere spheres[5];

	spheres[0] = ray_tracing::Sphere{
		{ 0, 0, 20, 0 },
		{ 1.0, 0.8, 0.0,1.0 },
		{ 1.0, 0.8, 0.0,1.0 },
		vec4(0),
		vec4(1),
		{ 1.0, 0.8, 0.0, 1.0 },
		1.0f,
		0.0f,
		1.0f,
		0.0f,
		5.0f
	};

	spheres[1] = ray_tracing::Sphere{
		{ 0,   15,   -20, 0 },
		{ 0.0, 0.0, 1.0, 1.0 },
		{ 0.0, 0.0, 1.0, 1.0 },
		vec4(0),
		vec4(1),
		{ 0.0, 0.0, 1.0, 1.0 },
		1.0f,
		0.0f,
		1.0f,
		0.0f,
		5.0f
	};
	
	spheres[2] = ray_tracing::Sphere{
		{ 0, -35, 0, 0 },
		vec4(0),
		vec4(1),
		vec4(1),
		vec4(1),
		vec4(0),
		1.0f,
		0.0f,
		1.0f,
		1.0f,
		15.0f
	};
	
	spheres[3] = ray_tracing::Sphere{
		{ 0, -5, 0, 0 },
		vec4(0),
		vec4(1),
		vec4(1),
		vec4(1),
		vec4(0),
		1.0f,
		0.8f,
		1.0f,
		0.1f,
		15.0f
	};

	spheres[4] = ray_tracing::Sphere{
		{ 0, -5, 0, 0 },
		{ 0.0, 0.0, 0.0, 1.0 },
		{ 1.0, 0.0, 0.0, 1.0 },
		{ 1.0, 0.0, 0.0, 1.0 },
		vec4(1),
		vec4(0),
		1.0f,
		0.8f,
		1.0f,
		0.1f,
		7.5f
	};

	return vector<ray_tracing::Sphere>(begin(spheres), end(spheres));
}


tuple<vector<ray_tracing::Plane>, vector<ray_tracing::Sphere>> initSceneObjects() {

	ray_tracing::Plane top;
	top.n = { 0, -1, 0, 0 };
	top.d = dot(top.n, { 0, 50, 0, 0 });
	top.ambient = vec4(0.3, 0.3, 0.3, 1.0);
	top.diffuse = vec4(1);
	top.specular = vec4(0.7, 0.7, 0.7, 1.0);
	top.transmittance = vec4(1);
	top.emission = vec4(0);
	top.shininess = 0;
	top.f0 = 0.1;
	top.ior = 0;
	//top.material.ambient = top.material.diffuse = vec4(1);
	//top.material.specular = vec4(0);

	ray_tracing::Plane back;
	back.n = { 0, 0, 1, 0 };
	back.d = dot(back.n, { 0, 0, -50, 0 });
	back.ambient = vec4(0.3, 0.3, 0.3, 1.0);
	back.diffuse = vec4(1);
	back.specular = vec4(0.7, 0.7, 0.7, 1.0);
	back.transmittance = vec4(1);
	back.emission = vec4(0);
	back.shininess = 0.0f;
	back.f0 = 0.1f;
	back.ior = 0.0f;

	ray_tracing::Plane bottom;
	bottom.n = { 0, 1, 0, 0 };
	bottom.d = dot(bottom.n, { 0, -50, 0 , 0});
	bottom.ambient = vec4(0.3, 0.3, 0.3, 1.0);
	bottom.diffuse = vec4(1);
	bottom.specular = vec4(0.7, 0.7, 0.7, 1.0);
	bottom.transmittance = vec4(1);
	bottom.emission = vec4(0);
	bottom.shininess = 0;
	bottom.f0 = 0.1;
	bottom.ior = 0.0f;
	//bottom.material.ambient = top.material.diffuse = vec4(1);
	//bottom.material.specular = vec4(0);

	ray_tracing::Plane right;
	right.n = { -1, 0, 0, 0 };
	right.d = dot(right.n, { 50, 0, 0, 0 });
	right.ambient = vec4(0.0, 0.3, 0, 1);
	right.diffuse = vec4(0, 1, 0, 1);
	right.specular = vec4(0, 0.7, 0, 1);
	right.transmittance = vec4(1);
	right.emission = vec4(0);
	right.shininess = 0.0f;
	right.f0 = 0.0f;
	right.ior = 0.0f;
	//right.material.ambient = right.material.diffuse = { 0, 1, 0, 1 };
	//right.material.specular = vec4(0);

	ray_tracing::Plane left;
	left.n = { 1, 0, 0, 0 };
	left.d = dot(left.n, { -50, 0, 0, 0 });
	left.ambient = { 0.3, 0, 0, 1 };
	left.diffuse = vec4(1, 0, 0, 1);
	left.specular = vec4(0.3, 0, 0, 1);
	left.transmittance = vec4(1);
	left.emission = vec4(0);
	left.shininess = 0.0f;
	left.f0 = 0.0f;
	left.ior = 0.0f;
	//left.material.ambient = right.material.diffuse = { 0, 0, 1, 1 };
	//left.material.specular = vec4(0);


	//back.material.ambient = top.material.diffuse = vec4(1);
	//back.material.specular = vec4(0);

	vector<ray_tracing::Plane> planes = { top, right, bottom, left, back };

	vector <ray_tracing::Sphere> spheres = initSceneObjects2();

	return make_tuple(planes, spheres);

}