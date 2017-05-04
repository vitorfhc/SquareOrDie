#ifndef __CIRCLE_COLLIDER__
#define __CIRCLE_COLLIDER__

#include <string>

#include "Engine/Component.h"
#include "Math/Shapes.h"
#include "Math/Vector.h"

class CircleCollider : public Component {
public:
  CircleCollider(GameObject *owner, Vector *offset, int radius);
  std::string GetComponentName() override { return "CircleCollider"; };
  inline Circle GetShape() { return m_shape; };
  void ComponentUpdate() override;
  bool CheckCollision(CircleCollider *collider);
  // bool CheckCollision(RectangleCollider *collider);

private:
  Circle m_shape;
  Vector *m_offset = nullptr;
};

#endif