#include "Components/Rigidbody.h"
#include "Globals/ComponentTypes.h"
#include "Math/Vector.h"

Rigidbody::Rigidbody(GameObject *owner) : Component(owner, C_PHYSICS) {}

void Rigidbody::FixedComponentUpdate() {
  if (m_gravity)
    GetOwner()->AddVelocity(Vector(0, m_gravityForce));
}
