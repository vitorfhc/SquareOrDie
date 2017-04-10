#include "Customs/MarioMovement.h"
#include "Components/Renderer.h"
#include "Engine/InputSystem.h"
#include "Log/log.h"
#include "Math/Vector.h"

MarioMovement::MarioMovement(GameObject *owner) : Script(owner) {
  // getting reference for the input system
  input = InputSystem::GetInstance();
}

void MarioMovement::Start() {
  // getting reference for the renderer component
  renderer = (Renderer *)GetObjectComponent("Renderer");
  // making an error raise if there no renderer component
  if (!renderer) {
    ERROR("NO RENDERER FOUND!");
    exit(1);
  }
}

void MarioMovement::ComponentUpdate() {
  // getting current position ans setting speed
  Vector position = renderer->GetPosition();
  float speed = 5;

  // deactivate object
  bool deactivate = input->GetKeyUp(INPUT_Q);
  GetOwner()->active = !deactivate;

  // deactivate this script
  bool deactivateComponent = input->GetKeyUp(INPUT_E);
  GetObjectComponent(GetComponentName())->active = !deactivateComponent;

  // checking input for movement
  bool right = input->GetKeyPressed(INPUT_D);
  bool left = input->GetKeyPressed(INPUT_A);

  position.m_x += right * speed;
  position.m_x -= left * speed;
  position.m_y -= input->GetKeyPressed(INPUT_W) * speed;
  position.m_y += input->GetKeyPressed(INPUT_S) * speed;

  // flip image
  if (left) renderer->GetImage()->Flip(true, false);
  else if (right) renderer->GetImage()->Flip(false, false);

  // updating position according to new position
  renderer->SetPosition(position);
}