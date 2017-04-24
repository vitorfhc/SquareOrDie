#include "Customs/MarioMovement.h"
#include "Components/Renderer.h"
#include "Engine/InputSystem.h"
#include "Engine/SDLSystem.h"
#include "Globals/EngineGlobals.h"
#include "Log/log.h"
#include "Math/Vector.h"

MarioMovement::MarioMovement(GameObject *owner) : Script(owner) {
  // getting reference for the input system
  input = InputSystem::GetInstance();
}

void MarioMovement::Start() {
  position = GetOwner()->GetPosition();
  // getting reference for the renderer component
  renderer = (Renderer *)GetOwner()->GetComponent("Renderer");
  // making an error raise if there no renderer component
  if (!renderer) {
    ERROR("NO RENDERER FOUND!");
    SDLSystem::GetInstance()->SetRunning(false);
  }
  if (input->GetGameController(0))
    gc = input->GetGameController(0);
}

void MarioMovement::ComponentUpdate() {
  // check for movements input
  if (gc) {
    xMovement = gc->GetAxis(GC_INPUT_AXIS_LEFTX);
    if (xMovement > 0)
      xMovement = 1;
    else if (xMovement < 0)
      xMovement = -1;
    yMovement = gc->GetAxis(GC_INPUT_AXIS_LEFTY);
    if (yMovement > 0)
      yMovement = 1;
    else if (yMovement < 0)
      yMovement = -1;
  }

  right = input->GetKeyPressed(INPUT_D);
  up = input->GetKeyPressed(INPUT_W);
  left = input->GetKeyPressed(INPUT_A);
  down = input->GetKeyPressed(INPUT_S);

  // special inputs
  boost = input->GetKeyPressed(INPUT_SPACE) || gc->GetButtonPressed(GC_INPUT_A);
  if (boost)
    movementSpeed = boostedSpeed;
  else
    movementSpeed = normalSpeed;

  crouch = input->GetKeyPressed(INPUT_LCTRL) ||
           gc->GetButtonPressed(GC_INPUT_LEFTSTICK);
  if (crouch)
    movementSpeed = crouchedSpeed;

  if (gc && gc->GetButtonUp(GC_INPUT_GUIDE))
    SDLSystem::GetInstance()->SetRunning(false);
  
  if (input->GetKeyDown(INPUT_Z))
    SceneManager::GetInstance()->SetCurrentScene("luigi");

  // rotate Mario to mouse
  std::pair<int, int> mousePos = input->GetMousePosition();
  renderer->RotateTowards(
      new Vector(mousePos.first - GetOwner()->GetWidth() / 2,
                 mousePos.second - GetOwner()->GetHeight() / 2));
}

void MarioMovement::FixedComponentUpdate() {
  // change of position
  position->m_x += right * movementSpeed;
  position->m_x -= left * movementSpeed;
  position->m_y -= up * movementSpeed;
  position->m_y += down * movementSpeed;

  position->m_x += xMovement * movementSpeed;
  position->m_y += yMovement * movementSpeed;

  // window edge collision
  if (position->m_x + GetOwner()->GetWidth() > EngineGlobals::screen_width)
    position->m_x = EngineGlobals::screen_width - GetOwner()->GetWidth();
  else if (position->m_x < 0)
    position->m_x = 0;

  if (position->m_y < 0)
    position->m_y = 0;
  else if (position->m_y + GetOwner()->GetHeight() > EngineGlobals::screen_height)
    position->m_y = EngineGlobals::screen_height - GetOwner()->GetHeight();

  // updating position according to new position
  // GetOwner()->SetPosition(position);
}