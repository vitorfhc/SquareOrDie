#include "Engine/Joystick.h"

Joystick::Joystick(SDL_Joystick *joystick) {
  m_joystick = joystick;

  m_buttonsQnt = SDL_JoystickNumButtons(joystick);
  m_axesQnt = SDL_JoystickNumAxes(joystick);

  m_oldButtonsStates.resize(m_buttonsQnt, 0);
  m_currentButtonsStates.resize(m_buttonsQnt, 0);
  m_currentAxes.resize(m_axesQnt, 0);
}

Joystick::~Joystick() { m_joystick = nullptr; }

void Joystick::Update() {
  m_oldButtonsStates = m_currentButtonsStates;

  for (int index = 0; index < m_buttonsQnt; index++)
    m_currentButtonsStates[index] = SDL_JoystickGetButton(m_joystick, index);
  for (int index = 0; index < m_axesQnt; index++)
    m_currentAxes[index] = SDL_JoystickGetAxis(m_joystick, index);
}

bool Joystick::GetButtonDown(int index) {
  if (m_currentButtonsStates[index] && !m_oldButtonsStates[index])
    return true;
  return false;
}

bool Joystick::GetButtonUp(int index) {
  if (!m_currentButtonsStates[index] && m_oldButtonsStates[index])
    return true;
  return false;
}

bool Joystick::GetButtonPressed(int index) {
  if (m_currentButtonsStates[index])
    return true;
  return false;
}