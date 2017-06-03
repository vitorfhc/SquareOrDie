#include <Customs/CatchAllController.h>
#include "Customs/PlayerScript.h"

PlayerScript::PlayerScript(GameObject *owner) : Script(owner) {}

void PlayerScript::ComponentUpdate() { HandleInput(); }

void PlayerScript::HandleInput() {
  m_movement.m_x = m_movement.m_y = 0;

  if (GetOwner()->GetName() == "Player1") {
    m_up = INPUT_W;
    m_left = INPUT_A;
    m_right = INPUT_D;
    m_down = INPUT_S;
  } else if (GetOwner()->GetName() == "Player2") {
    m_up = INPUT_U;
    m_left = INPUT_H;
    m_right = INPUT_K;
    m_down = INPUT_J;
  } else if (GetOwner()->GetName() == "Player3") {
    m_up = INPUT_UP;
    m_left = INPUT_LEFT;
    m_right = INPUT_RIGHT;
    m_down = INPUT_DOWN;
  }

  if (InputSystem::GetInstance()->GetKeyPressed(m_right))
    m_movement.m_x += 1;
  if (InputSystem::GetInstance()->GetKeyPressed(m_left))
    m_movement.m_x -= 1;
  if (InputSystem::GetInstance()->GetKeyPressed(m_down))
    m_movement.m_y += 1;
  if (InputSystem::GetInstance()->GetKeyPressed(m_up))
    m_movement.m_y -= 1;

  m_movement = m_movement.GetNormalized();
}

void PlayerScript::FixedComponentUpdate() {
  GetOwner()->GetPosition()->m_x += m_movement.m_x * m_speed;
  GetOwner()->GetPosition()->m_y += m_movement.m_y * m_speed;

    for(auto obj : GetOwner()->GetCollisions()) {
        if(obj->GetTag() == "Catcher") {
            CatchAllController::GetInstance()->KillPlayer(GetOwner());
            INFO("CATCHER GOT ONE");
        }
    }
}
