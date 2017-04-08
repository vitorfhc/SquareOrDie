#ifndef __GAME_OBJECT__
#define __GAME_OBJECT__

#include <unordered_map>
#include <vector>
#include <utility>

#include "Globals/ComponentTypes.h"
#include "Engine/Component.h"
#include "Engine/sdl2include.h"

class GameObject {
    public:
    // constructor and destructor
    GameObject(std::vector<Component*> components);
    GameObject(Component* component);
    GameObject();
    ~GameObject();
    // method for handling updates
    void Update();
    void AddComponent(Component* component);
    void AddComponent(std::vector<Component*> components);
    
    private:
    // map of components
    std::unordered_map<Uint32, std::vector<Component*>> m_components;

    // methods for handling specific update
    void PhysicsUpdate();
    void DrawUpdate();
    void ComponentsUpdate();
};

#endif // __GAME_OBJECT__