#ifndef __GAME_OBJECT__
#define __GAME_OBJECT__

#include <unordered_map>
#include <vector>
#include <utility>
#include <string>

#include "Globals/ComponentTypes.h"
#include "Engine/Component.h"
#include "Engine/sdl2include.h"

class GameObject
{
  public:
    // constructor and destructor
    GameObject(std::string name, std::vector<Component *> components);
    GameObject(std::string name, Component *component);
    GameObject(std::string name);
    ~GameObject();
    // method for handling updates
    void Update();
    void DrawUpdate();
    // components management
    void AddComponent(Component *component);
    void AddComponent(std::vector<Component *> components);

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