#ifndef __GAME_OBJECT__
#define __GAME_OBJECT__

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "Engine/Component.h"
#include "Engine/sdl2include.h"
#include "Globals/ComponentTypes.h"

class GameObject {
public:
  // active atribbute
  bool active = true;

  // constructor and destructor
  GameObject(std::string name, std::vector<Component *> components);
  GameObject(std::string name, Component *component);
  GameObject(std::string name);
  ~GameObject();
  // method for handling start and updates
  void Start();
  void Update();
  void FixedUpdate();
  void DrawUpdate();
  // components management
  void AddComponent(Component *component);
  void AddComponent(std::vector<Component *> components);
  Component *GetComponent(std::string name);
  std::string GetName() { return m_name; };

private:
  // map of components
  std::unordered_map<Uint32, std::vector<Component *>> m_components;
  // object name
  std::string m_name;

  // methods for handling specific update
  void PhysicsUpdate();
  void ComponentsUpdate();
};

#endif // __GAME_OBJECT__