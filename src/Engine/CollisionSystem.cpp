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
    for (int k = i + 1; k < m_colliders.size(); k++) {
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

void CollisionSystem::CircleCircle(CircleCollider *c1, CircleCollider *c2) {
  bool collision = false;
  auto c2Center = c2->GetCenter();
  if (c1->GetCenter().GetDistance(c2Center) <=
      c1->GetRadius() + c2->GetRadius())
    collision = true;

  if (collision) {
    INFO("CIRCLE CIRCLE");
    INFO("COLLIDED");
  }
}

void CollisionSystem::RectRect(RectangleCollider *r1, RectangleCollider *r2) {
  bool collision = false;
  int x1[2], x2[2], y1[2], y2[2];

  x1[0] = r1->GetRectanglePoint().m_x;
  x1[1] = r1->GetRectanglePoint().m_x + r2->GetWidth();
  x2[0] = r2->GetRectanglePoint().m_x;
  x2[1] = r2->GetRectanglePoint().m_x + r2->GetWidth();

  y1[0] = r1->GetRectanglePoint().m_y + r2->GetHeight();
  y1[1] = r1->GetRectanglePoint().m_y;
  y2[0] = r2->GetRectanglePoint().m_y + r2->GetHeight();
  y2[1] = r2->GetRectanglePoint().m_y;

  if (x1[0] < x2[1] && x1[1] > x2[0] && y1[1] > y2[0] && y1[0] < y2[1])
    collision = true;

  if (collision) {
    INFO("COLLIDED");
    INFO("RECT RECT");
  }
}

void CollisionSystem::CircleRect(CircleCollider *c, RectangleCollider *r) {
  int x[2], y[2];
  bool collision = false;

  x[0] = r->GetRectanglePoint().m_x;
  x[1] = r->GetRectanglePoint().m_x + r->GetWidth();

  y[0] = r->GetRectanglePoint().m_y;
  y[1] = r->GetRectanglePoint().m_y + r->GetHeight();

  Vector points[4];
  points[0] = Vector(x[0], y[0]);
  points[1] = Vector(x[0], y[1]);
  points[2] = Vector(x[1], y[0]);
  points[3] = Vector(x[1], x[1]);

  auto circleCenter = c->GetCenter();

  if (circleCenter.GetDistance(points[0]) <= c->GetRadius() ||
      circleCenter.GetDistance(points[1]) <= c->GetRadius() ||
      circleCenter.GetDistance(points[2]) <= c->GetRadius() ||
      circleCenter.GetDistance(points[3]) <= c->GetRadius())
    collision = true;

  if (collision) {
    INFO("COLLIDED");
    INFO("RECT CIRCLE");
  }
}
