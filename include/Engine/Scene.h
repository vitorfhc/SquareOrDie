#ifndef __SCENE__
#define __SCENE__

#include <vector>

#include "Engine/GameObject.h"
#include "Globals/SceneStates.h"

class Scene {
public:
  // constructor and destructor
  Scene();
  ~Scene();
  // start and update handling
  void Start();
  void Update();
  void FixedUpdate();
  void DrawUpdate();
  // handle gameobjects
  void AddGameObject(GameObject *gameObject);
  void AddGameObject(std::vector<GameObject *> gameObjects);
  // states
  inline void SetState(SceneStates state) { m_currentState = state; };
  inline SceneStates GetState() { return m_currentState; };

private:
  // scene state
  SceneStates m_currentState;
  // gameobjects vector
  std::vector<GameObject *> m_gameObjects;
};

#endif // __SCENE__