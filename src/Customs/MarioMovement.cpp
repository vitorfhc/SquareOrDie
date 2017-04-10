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

  // checking input for movement
  position.m_x += input->GetKeyPressed(INPUT_D) * speed;
  position.m_x -= input->GetKeyPressed(INPUT_A) * speed;
  position.m_y -= input->GetKeyPressed(INPUT_W) * speed;
  position.m_y += input->GetKeyPressed(INPUT_S) * speed;

  // updating position according to new position
  renderer->SetPosition(position);
}