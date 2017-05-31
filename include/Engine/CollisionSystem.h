#ifndef __COLLISION_SYSTEM__
#define __COLLISION_SYSTEM__

#include <vector>

#include "Components/Collider.h"
#include "Engine/SceneManager.h"
#include "Log/log.h"

using namespace std;

class CollisionSystem {
public:
  static CollisionSystem *GetInstance();
  void Update();

private:
  CollisionSystem();
  void DetectCollisions();
  void PushColliders();

  static CollisionSystem *m_instance;
  vector<Collider *> m_colliders;
};

#endif
