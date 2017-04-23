#include "Components/UIButton.h"
#include "Engine/GameObject.h"
#include "Engine/SDLSystem.h"
#include "Globals/ComponentTypes.h"
#include "Globals/InputGlobals.h"
#include "Log/log.h"

UIButton::UIButton(GameObject *owner) : Component(owner, C_DRAW) {}

void UIButton::Start() {
  // checking for renderer component existance
  m_rendererComponent = (Renderer *)GetOwner()->GetComponent("Renderer");
  if (!m_rendererComponent) {
    ERROR(
        "UIButton couldn't find renderer component: " << GetOwner()->GetName());
    SDLSystem::GetInstance()->SetRunning(false);
  }

  // case exists
  m_rendererWidth = m_rendererComponent->GetWidth();
  m_rendererHeight = m_rendererComponent->GetHeight();
  m_position = GetOwner()->GetPosition();
}

bool UIButton::IsClicked() {
  // checking if mouse is over button and clicked
  if (IsOver() && InputSystem::GetInstance()->GetMouseButtonDown(M_INPUT_LEFT))
    return true;
  return false;
}

bool UIButton::IsOver() {
  // getting button and mouse position
  m_position = GetOwner()->GetPosition();
  m_rendererWidth = m_rendererComponent->GetWidth();
  m_rendererHeight = m_rendererComponent->GetHeight();
  std::pair<int, int> mousePos = InputSystem::GetInstance()->GetMousePosition();

  // checking if mouse is over
  if (mousePos.first > m_position->m_x &&
      mousePos.first < m_position->m_x + m_rendererWidth &&
      mousePos.second > m_position->m_y &&
      mousePos.second < m_position->m_y + m_rendererHeight)
    return true;
  return false;
}