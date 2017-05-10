#include "Components/Animator.h"

Animator::Animator(GameObject *owner) : Component(owner, C_DRAW) {}

void Animator::AddAnimation(std::string name, Animation *animation) {
  m_aMap.emplace(name, animation);
}

void Animator::ToggleAnimation(std::string name) {}
