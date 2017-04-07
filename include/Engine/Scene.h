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

    private:
    // gameobjects array
    std::vector<GameObject*> m_gameObjects;
};

#endif // __SCENE__