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
    SceneManager::GetInstance()->SetCurrentScene("main");
  if (button->IsOver())
    renderer->SetSizes(std::make_pair(200, 200));
  else
    renderer->SetSizes(std::make_pair(100, 100));
}

void LuigiScript::FixedComponentUpdate() {}