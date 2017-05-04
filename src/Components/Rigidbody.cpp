#include "Components/Rigidbody.h"
#include "Globals/ComponentTypes.h"
#include "Math/Vector.h"

Rigidbody::Rigidbody(GameObject *owner) : Component(owner, C_PHYSICS) {
  resultantForce = new Vector();
  appliedForces = new Vector();
}

void Rigidbody::FixedComponentUpdate() {
  resultantForce->m_y += m_gravityForce;
  
  GetOwner()->GetPosition()->m_x += resultantForce->m_x;
  GetOwner()->GetPosition()->m_y += resultantForce->m_y;

  GetOwner()->GetPosition()->m_x += appliedForces->m_x;
  GetOwner()->GetPosition()->m_y += appliedForces->m_y;
}