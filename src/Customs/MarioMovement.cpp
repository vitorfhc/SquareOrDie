#include "Customs/MarioMovement.h"
#include "Components/Renderer.h"
#include "Engine/InputSystem.h"
#include "Engine/SDLSystem.h"
#include "Log/log.h"
#include "Math/Vector.h"

MarioMovement::MarioMovement(GameObject *owner) : Script(owner) {
  // getting reference for the input system
  input = InputSystem::GetInstance();
}

void MarioMovement::Start() {
  // getting reference for the renderer component
  renderer = (Renderer *)GetOwner()->GetComponent("Renderer");
  // making an error raise if there no renderer component
  if (!renderer) {
    ERROR("NO RENDERER FOUND!");
    SDLSystem::GetInstance()->SetRunning(false);
  }
}

void MarioMovement::ComponentUpdate() {
  // deactivate object
  bool deactivate = input->GetKeyUp(INPUT_Q);
  GetOwner()->active = !deactivate;

  // deactivate the renderer
  if (input->GetKeyDown(INPUT_E))
    isVisible = !isVisible;
  renderer->active = isVisible;

  // super speed
  if (input->GetKeyDown(INPUT_SPACE))
    speed = 20;
  if (input->GetKeyUp(INPUT_SPACE))
    speed = 10;

  // checking input for movement
  right = input->GetJoystick(1)->GetButtonPressed(5) * speed;
  left = input->GetJoystick(1)->GetButtonPressed(7) * speed;

  // change scene
  if (input->GetKeyDown(INPUT_Z))
    SceneManager::GetInstance()->SetCurrentScene("luigi");

  // flip image
  // if (left)
  //   renderer->GetImage()->Flip(true, false);
  // else if (right)
  //   renderer->GetImage()->Flip(false, false);

  // rotate Mario to mouse
  std::pair<int, int> mousePos = input->GetMousePosition();
  renderer->RotateTowards(
      new Vector(mousePos.first - renderer->GetWidth() / 2,
                 mousePos.second - renderer->GetHeight() / 2));
}

void MarioMovement::FixedComponentUpdate() {
  // getting current position ans setting speed
  Vector* position = GetOwner()->GetPosition();

  // changing position values
  position->m_x += right * speed;
  position->m_x -= left * speed;
  position->m_y -= input->GetJoystick(1)->GetButtonPressed(4) * speed;
  position->m_y += input->GetJoystick(1)->GetButtonPressed(6) * speed;

  position->m_x += input->GetJoystick(1)->GetAxis(0) * speed / 32768.0;
  position->m_y += input->GetJoystick(1)->GetAxis(1) * speed / 32768.0;

  // window edge collision
  if (position->m_x + renderer->GetWidth() > 1280)
    position->m_x = 1280 - renderer->GetWidth();
  if (position->m_x < 0)
    position->m_x = 0;

  // updating position according to new position
  GetOwner()->SetPosition(position);
}