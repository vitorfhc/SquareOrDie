#include "Engine/Component.h"
#include "Engine/GameObject.h"

Component::Component(GameObject *owner, ComponentType type) {
  m_owner = owner;
  m_type = type;
  m_owner->AddComponent(this);
}

Component::~Component() { m_owner = nullptr; }

void Component::Update() { ComponentUpdate(); }

void Component::ComponentUpdate() {}