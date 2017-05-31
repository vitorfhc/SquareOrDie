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

void CollisionSystem::DetectCollisions() {
  for (int i = 0; i < m_colliders.size(); i++) {
    for (int k = i; k < m_colliders.size(); k++) {
      if (m_colliders[i]->GetComponentName() ==
              m_colliders[k]->GetComponentName() &&
          m_colliders[i]->GetComponentName() == "CircleCollider")
        CircleCircle((CircleCollider *)m_colliders[i],
                     (CircleCollider *)m_colliders[k]);

      else if (m_colliders[i]->GetComponentName() ==
                   m_colliders[k]->GetComponentName() &&
               m_colliders[i]->GetComponentName() == "RectangleCollider")
        RectRect((RectangleCollider *)m_colliders[i],
                 (RectangleCollider *)m_colliders[k]);

      else if (m_colliders[i]->GetComponentName() !=
                   m_colliders[k]->GetComponentName() &&
               m_colliders[i]->GetComponentName() == "CircleCollider")
        CircleRect((CircleCollider *)m_colliders[i],
                   (RectangleCollider *)m_colliders[k]);

      else
        CircleRect((CircleCollider *)m_colliders[k],
                   (RectangleCollider *)m_colliders[i]);
    }
  }
}

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

void CollisionSystem::CircleCircle(CircleCollider *c1, CircleCollider *c2) {}

void CollisionSystem::RectRect(RectangleCollider *r1, RectangleCollider *r2) {}

void CollisionSystem::CircleRect(CircleCollider *c, RectangleCollider *r) {}
