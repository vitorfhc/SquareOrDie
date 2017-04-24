#include "Customs/LuigiScript.h"
#include "Engine/InputSystem.h"
#include "Engine/SceneManager.h"
#include "Log/log.h"

LuigiScript::LuigiScript(GameObject *owner) : Script(owner) {}

void LuigiScript::Start() {
  input = InputSystem::GetInstance();
  button = (UIButton *)GetOwner()->GetComponent("UIButton");
  if (!button) {
    ERROR("Couldn't find UIButton component: " << GetOwner()->GetName());
  }
}

void LuigiScript::ComponentUpdate() {
  Renderer *renderer = (Renderer *)GetOwner()->GetComponent("Renderer");

  if (button->IsClicked())
    SceneManager::GetInstance()->SetCurrentScene("Main");
  if (button->IsOver())
    GetOwner()->SetSize(200, 200);
  else
    GetOwner()->SetSize(100, 100);
}

void LuigiScript::FixedComponentUpdate() {}