#include "Customs/NakedManScript.h"

NakedManScript::NakedManScript(GameObject *owner) : Script(owner) {}

void NakedManScript::Start() {
  inputSystem = InputSystem::GetInstance();
  owner = GetOwner();
  animation = (Animation *)owner->GetComponent("Animation");
  animation->SetHasExitTime(true);
  position = owner->GetPosition();
}

void NakedManScript::ComponentUpdate() {
  right = inputSystem->GetKeyPressed(INPUT_D);
  left = inputSystem->GetKeyPressed(INPUT_A);

  if (right != 0 || left != 0)
    animation->SetPlaying(true);
  else
    animation->SetPlaying(false);

  if (right)
    animation->SetFlip(false, false);
  else if (left)
    animation->SetFlip(true, false);
}

void NakedManScript::FixedComponentUpdate() {
  position->m_x += right * 5;
  position->m_x -= left * 5;
}