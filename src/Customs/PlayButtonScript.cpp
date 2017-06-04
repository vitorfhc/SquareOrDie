#include <Customs/MenuController.h>
#include "Customs/PlayButtonScript.h"

PlayButtonScript::PlayButtonScript(GameObject *owner) : Script(owner) {}

void PlayButtonScript::Start() {
  m_uiButton = (UIButton *)GetOwner()->GetComponent("UIButton");
}

void PlayButtonScript::ComponentUpdate() {
  if (m_uiButton->IsClicked() && MenuController::GetInstance()->GetGamemode() & 0x02) {
    SceneManager::GetInstance()->SetCurrentScene("CatchAll");
  }
  else if (m_uiButton->IsClicked() && MenuController::GetInstance()->GetGamemode() & 0x01){
    SceneManager::GetInstance()->SetCurrentScene("Missile");
  }
}
