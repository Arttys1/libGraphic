#pragma once
#ifndef H_LIBGRAPHIC
#define H_LIBGRAPHIC

//
//Things to do :
// implement spotlight in fragment shader
// implement Material class
//

//include openGL headers
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

//include library headers
#include "Window.h"
#include "ShapeCollection.h"
#include "Shape.h"
#include "Shader.h"
#include "Color.h"
#include "Texture.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Cube.h"
#include "ITransformable.h"
#include "Transformation.h"
#include "Vector3D.h"
#include "Camera.h"
#include "Light.h"
#include "PointLight.h"
#include "DirectionalLight.h"
#include "SpotLight.h"

#endif //H_LIBGRAPHIC