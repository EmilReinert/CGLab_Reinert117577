#ifndef APPLICATION_SOLAR_HPP
#define APPLICATION_SOLAR_HPP

#include "application.hpp"
#include "model.hpp"
#include "structs.hpp"
#include "texture_loader.hpp"
#include "scene_graph.hpp"

// gpu representation of model
class ApplicationSolar : public Application
{
public:
  // allocate and initialize objects
  ApplicationSolar(std::string const &resource_path);
  // free allocated objects
  ~ApplicationSolar();

  // react to key input
  void keyCallback(int key, int action, int mods);
  //handle delta mouse movement input
  void mouseCallback(double pos_x, double pos_y);
  //handle resizing
  void resizeCallback(unsigned width, unsigned height);

  // draw all objects
  void render() const;
  //actual render for planet loop//for each planet
  void update_planet(node *const Planet, float count) const;

  //actuall render for planet loop//for each planet
  void drawStars() const;
  //actual skybox rendering
  void drawSkybox() const;

  //////SCENE-SETUP here!! //////////////
  void sceneSetup();
  void setScene(scene_graph &scene);

  //retruns pointer of scene
  scene_graph *getScene() const;

protected:
  void initializeShaderPrograms();

  //intializing of scene objects
  //for models
  void initializeGeometry();
  //for skybox
  void initializeSkybox();
  //initialiting of stars
  void initializeStars();
  //initialiting of stars
  void initializeOrbits();
  //initializing of the textures
  void initializeTextures();
  //initializing of framebuffer
  void initializeFramebuffer();
  // update uniform values
  void uploadUniforms();
  // upload projection matrix
  void uploadProjection();
  // upload view matrix
  void uploadView();

  // scene graph as member
  scene_graph *m_scene_graph;

  //render mode
  int render_mode = 1;

  // cpu representation of models
  model_object planet_object;
  model_object skybox_object;
  // colors of planetes
  std::vector<glm::vec3> planet_colors;
  // textures for the planets
  std::vector<texture_object> textures;
  std::vector<pixel_data> texture_images;
  //textures for skybox
  texture_object skybox_texture;
  std::vector<pixel_data> skybox_images;
  model_object star_object;
  model_object orbit_object;
  //framebuffer stuff
  // texture for framebuffer
  texture_object fbo_texture;
  // ojects for render and frame buffer
  framebuffer_object fbo;
  renderbuffer_object rbo;

  //holder of special scene objects
  // holds a vector of the planets
  std::vector<node *> m_planets;
  // holds random floats for stars
  std::vector<float> stars;

  // camera transform matrix
  glm::fmat4 m_view_transform;
  // camera projection matrix
  glm::fmat4 m_view_projection;
};

#endif