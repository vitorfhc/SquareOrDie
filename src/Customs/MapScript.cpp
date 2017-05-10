#include "Customs/MapScript.h"

MapScript::MapScript(GameObject *owner) : Script(owner) {}

void MapScript::Start() {
  character = SceneManager::GetInstance()->GetCurrentScene()->GetGameObject(
      "Character");
  if (character == nullptr)
    ERROR("DSAD");
  charPos = character->GetPosition();
}

void MapScript::ComponentUpdate() {}

void MapScript::FixedComponentUpdate() {
  if (charPos->m_x + 62 >= EngineGlobals::screen_width)
    GetOwner()->GetPosition()->m_x -= 5;
  if (charPos->m_x <= 0)
    GetOwner()->GetPosition()->m_x += 5;
  if (charPos->m_y + 41 >= EngineGlobals::screen_height)
    GetOwner()->GetPosition()->m_y -= 5;
  if (charPos->m_y <= 0)
    GetOwner()->GetPosition()->m_y += 5;
}
