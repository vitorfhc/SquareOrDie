#include "Customs/NakedManScript.h"
#include "Components/CircleCollider.h"
#include "Engine/SceneManager.h"

NakedManScript::NakedManScript(GameObject *owner) : Script(owner) {}

void NakedManScript::Start() {
  inputSystem = InputSystem::GetInstance();
  owner = GetOwner();
  animation = (Animation *)owner->GetComponent("Animation");
  animation->SetHasExitTime(false);
  animation->SetLoop(false);
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

  auto luigi =
      SceneManager::GetInstance()->GetCurrentScene()->GetGameObject("Luigi");
  auto luigiCol = (CircleCollider *)luigi->GetComponent("CircleCollider");
  auto col = (CircleCollider *)GetOwner()->GetComponent("CircleCollider");
  col->CheckCollision(luigiCol);
}