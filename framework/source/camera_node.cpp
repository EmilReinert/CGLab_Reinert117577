#include "application_solar.hpp"
#include "window_handler.hpp"

#include "utils.hpp"
#include "shader_loader.hpp"
#include "model_loader.hpp"

#include <glbinding/gl/gl.h>
// use gl definitions from glbinding 
using namespace gl;

//dont load gl bindings from glfw
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include "camera_node.hpp"

	camera_node::camera_node(){}
	camera_node::camera_node(std::string name):node{name}{}
	camera_node::~camera_node(){}

		//return perspective
	bool camera_node::getPerspective(){return isPerspective;}
	//get-set if enabled
	bool camera_node::getEnabled(){return isEnabled;}
	void camera_node::setEnabled(bool b){
		isEnabled = b;
	}
	//get-set PojectionMatrix
	glm::fmat4 camera_node::getProjectionMatrix(){return projectionMatrix;}
	void camera_node::setProjectionMatrix(glm::fmat4 newprojection){
		projectionMatrix = newprojection;
	}
