#include "Customs/LifeBarScript.h"

std::string LifeBarScript::GetComponentName() { return "LifeBarScript"; }

void LifeBarScript::ComponentUpdate() {
  float newWidth = EngineGlobals::fixed_update_rate * 2 -
                 m_playerScript->GetFramesNotMoving();
  newWidth /= EngineGlobals::fixed_update_rate * 2;
  newWidth *= 40;
  m_rRenderer->SetSize((int)newWidth, 10);
}

void LifeBarScript::Start() {
  m_rRenderer =
      (RectangleRenderer *)GetOwner()->GetComponent("RectangleRenderer");
}

void LifeBarScript::SetPlayer(PlayerScript *playerScript) {
  m_playerScript = playerScript;
}

LifeBarScript::LifeBarScript(GameObject *owner) : Script(owner) {}
