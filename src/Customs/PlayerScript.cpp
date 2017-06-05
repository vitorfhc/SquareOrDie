#include "Customs/PlayerScript.h"
#include <Customs/CatchAllController.h>
#include <Customs/MissileController.h>

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
  Move();
  CheckMovement();
  GameCollisionCheck();
  ScreenCollisionCheck();
}

void PlayerScript::ScreenCollisionCheck() {
  if (GetOwner()->GetTag() != "Catcher") {
    if (GetOwner()->GetPosition()->m_x + 40 < -1)
      GetOwner()->SetPosition(
          Vector(EngineGlobals::screen_width, GetOwner()->GetPosition()->m_y));
    if (GetOwner()->GetPosition()->m_x > EngineGlobals::screen_width + 1)
      GetOwner()->SetPosition(Vector(-39, GetOwner()->GetPosition()->m_y));
    if (GetOwner()->GetPosition()->m_y + 60 < -1)
      GetOwner()->SetPosition(Vector(GetOwner()->GetPosition()->m_x,
                                     EngineGlobals::screen_height - 1));
    if (GetOwner()->GetPosition()->m_y > EngineGlobals::screen_height + 1)
      GetOwner()->SetPosition(Vector(GetOwner()->GetPosition()->m_x, -59));

  } else {

    if (GetOwner()->GetPosition()->m_x < 0)
      GetOwner()->SetPosition(Vector(0, GetOwner()->GetPosition()->m_y));
    if (GetOwner()->GetPosition()->m_x + 40 > EngineGlobals::screen_width)
      GetOwner()->SetPosition(Vector(EngineGlobals::screen_width - 40,
                                     GetOwner()->GetPosition()->m_y));
    if (GetOwner()->GetPosition()->m_y < 0)
      GetOwner()->SetPosition(Vector(GetOwner()->GetPosition()->m_x, 0));
    if (GetOwner()->GetPosition()->m_y + 60 > EngineGlobals::screen_height)
      GetOwner()->SetPosition(Vector(GetOwner()->GetPosition()->m_x,
                                     EngineGlobals::screen_height - 60));
  }
}

void PlayerScript::Move() {
  if (GetOwner()->GetTag() == "Catcher") {
    m_speed *= 1.0015;
    if (m_speed >= 40) {
      CatchAllController::GetInstance()->EndGame(true);
    }
  } else
    m_speed = 10;
  GetOwner()->GetPosition()->m_x += m_movement.m_x * m_speed;
  GetOwner()->GetPosition()->m_y += m_movement.m_y * m_speed;
}

void PlayerScript::GameCollisionCheck() {
  for (auto obj : GetOwner()->GetCollisions()) {
    if (obj->GetTag() == "Catcher") {
      CatchAllController::GetInstance()->KillPlayer(GetOwner());
    } else if (obj->GetTag() == "Missile") {
      MissileController::GetInstance()->KillPlayer(GetOwner());
    }
  }
}

void PlayerScript::CheckMovement() {
  if (!m_movement.m_x && !m_movement.m_y)
    m_framesNotMoving++;
  else {
    m_framesNotMoving -= 2;
    if (m_framesNotMoving < 0)
      m_framesNotMoving = 0;
  }
  if (m_framesNotMoving > EngineGlobals::fixed_update_rate * 2) {
    CatchAllController::GetInstance()->KillPlayer(GetOwner());
    if (GetOwner()->GetTag() == "Catcher")
      CatchAllController::GetInstance()->EndGame(true);
  }
}

void PlayerScript::ResetMovementCheck() { m_framesNotMoving = 0; }
