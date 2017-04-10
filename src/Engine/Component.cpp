#include "Engine/Component.h"
#include "Engine/GameObject.h"

Component::Component(GameObject *owner) {
  m_owner = owner;
  m_owner->AddComponent(this);
}

Component::~Component() { m_owner = nullptr; }

void Component::Update() { ComponentUpdate(); }