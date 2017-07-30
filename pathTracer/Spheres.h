#pragma once

#include <set>
#include <random>

#include <glm/gtc/constants.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtc/matrix_access.hpp>

#include <ncl/gl/rayTracingUtilities.h>

using namespace std;
using namespace ncl;
using namespace gl;
using namespace glm;

const static float _PI = pi<float>();

vector<ray_tracing::Sphere> initSpheres() {
	using namespace ray_tracing;

	Material red;
	red.diffuse = { 0.87, 0.15, 0.15, 0.0 };
	red.specular = vec4(1);
	red.ior = 1.491;
	
}