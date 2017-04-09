#ifndef __SCENE__
#define __SCENE__

#include <vector>

#include "Engine/GameObject.h"

class Scene {
    public:
    // constructor and destructor
    Scene();
    ~Scene();
    // update handling
    void Update();
    void DrawUpdate();
    // handle gameobjects
    void AddGameObject(GameObject* gameObject);
    void AddGameObject(std::vector<GameObject*> gameObjects);

    private:
    // gameobjects array
    std::vector<GameObject*> m_gameObjects;
};

#endif // __SCENE__