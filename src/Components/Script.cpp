#include "Components/Script.h"

Script::Script(GameObject *owner) : Component(owner, C_COMMON) {};

Component *Script::GetObjectComponent(std::string name) {
  auto component = GetOwner()->GetComponent(name);
  return component;
}