#include "Components/CircleCollider.h"
#include "Engine/GameObject.h"
#include "Log/log.h"

CircleCollider::CircleCollider(GameObject *owner, Vector *offset, int radius) : Component(owner, C_PHYSICS) {
  m_offset = offset;
  m_shape.x = owner->GetPosition()->m_x + offset->m_x;
  m_shape.y = owner->GetPosition()->m_y + offset->m_y;
  m_shape.radius = radius;
}

void CircleCollider::ComponentUpdate() {
  m_shape.x = GetOwner()->GetPosition()->m_x + m_offset->m_x;
  m_shape.y = GetOwner()->GetPosition()->m_y + m_offset->m_y;
}

bool CircleCollider::CheckCollision(CircleCollider *collider) {
  auto other = collider->GetShape();
  Vector center(m_shape.x, m_shape.y);
  Vector otherCenter(other.x, other.y);
  if (center.GetDistance(otherCenter) <= m_shape.radius + other.radius) {
    INFO("Collision detected");
    return true;
  }
  return false;
}