#include "Engine/CollisionSystem.h"

CollisionSystem *CollisionSystem::m_instance = nullptr;

CollisionSystem::CollisionSystem() {}

CollisionSystem *CollisionSystem::GetInstance() {
  if (!m_instance)
    m_instance = new CollisionSystem();
  return m_instance;
}

void CollisionSystem::Update() {
  PushColliders();
  DetectCollisions();
}

void CollisionSystem::DetectCollisions() {}

void CollisionSystem::PushColliders() {
  m_colliders.clear();

  auto gameobjects =
      SceneManager::GetInstance()->GetCurrentScene()->GetAllGameObjects();

  for (auto gameobject : gameobjects) {
    for (auto key : gameobject->GetAllComponents()) {
      if (key.first != C_PHYSICS)
        break;
      for (auto element : key.second) {
        if (element->GetComponentName() == "CircleCollider" ||
            element->GetComponentName() == "RectangleCollider")
          m_colliders.push_back((Collider *)element);
      }
    }
  }
}
