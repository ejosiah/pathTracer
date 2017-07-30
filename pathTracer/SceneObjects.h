#pragma once
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtc/matrix_access.hpp>
#include <glm/gtc/constants.hpp>
#include <ncl/gl/rayTracingUtilities.h>
#include <vector>
#include <tuple>
#include <utility>

using namespace std;
using namespace ncl;
using namespace gl;
using namespace glm;


tuple<vector<ray_tracing::Plane>> initSceneObjects() {

	ray_tracing::Plane top;
	top.n = { 0, -1, 0, 0 };
	top.d = dot(top.n, { 0, 100, 0, 0 });
	top.material.ambient = top.material.diffuse = vec4(1);
	top.material.specular = vec4(0);

	ray_tracing::Plane bottom;
	bottom.n = { 0, 1, 0, 0 };
	bottom.d = dot(bottom.n, { 100, 0, 0 , 0});
	bottom.material.ambient = top.material.diffuse = vec4(1);
	bottom.material.specular = vec4(0);

	ray_tracing::Plane right;
	right.n = { -1, 0, 0, 0 };
	right.d = dot(right.n, { 100, 0, 0, 0 });
	right.material.ambient = right.material.diffuse = { 0, 1, 0, 1 };
	right.material.specular = vec4(0);

	ray_tracing::Plane left;
	left.n = { 1, 0, 0, 0 };
	left.d = dot(left.n, { -100, 0, 0, 0 });
	left.material.ambient = right.material.diffuse = { 0, 0, 1, 1 };
	left.material.specular = vec4(0);

	ray_tracing::Plane back;
	back.n = { 0, 0, 1, 0 };
	back.d = dot(back.n, { 0, 0, -100, 0 });
	back.material.ambient = top.material.diffuse = vec4(1);
	back.material.specular = vec4(0);

	vector<ray_tracing::Plane> planes = { top, right, bottom, left };

	return make_tuple(planes);

}