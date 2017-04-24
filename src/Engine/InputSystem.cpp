#include <algorithm>

#include "Engine/InputSystem.h"
#include "Log/log.h"

// static variables initialization
InputSystem *InputSystem::m_instance = 0;

InputSystem::InputSystem() {
  SDL_PumpEvents();
  SDL_JoystickUpdate();

  m_states = SDL_GetKeyboardState(&m_statesSize);
  m_oldStates = new Uint8[m_statesSize];
  m_mouseStates = SDL_GetMouseState(&m_mouseX, &m_mouseY);

  SDL_JoystickEventState(SDL_IGNORE);
  LoadJoysticks();
}

InputSystem::~InputSystem() {
  m_states = nullptr;
  delete[] m_oldStates;
  m_oldStates = nullptr;
}

InputSystem *InputSystem::GetInstance() {
  if (!m_instance)
    m_instance = new InputSystem();
  return m_instance;
}

void InputSystem::UpdateStates() {
  // update old states to be equal to actual
  for (int i = 0; i < m_statesSize; i++)
    m_oldStates[i] = m_states[i];
  m_oldMouseStates = m_mouseStates;
  // update actual states
  SDL_PumpEvents();
  SDL_JoystickUpdate();
  UpdateJoysticks();

  m_mouseStates = SDL_GetMouseState(&m_mouseX, &m_mouseY);
}

bool InputSystem::GetKeyDown(KeyboardInputGlobal key) {
  if (m_states[key] && !m_oldStates[key]) {
    char message[] = "Key down: ";
    strcat(message, SDL_GetScancodeName((SDL_Scancode)key));
    // INFO(message);
    return true;
  }
  return false;
}

bool InputSystem::GetKeyUp(KeyboardInputGlobal key) {
  if (!m_states[key] && m_oldStates[key]) {
    char message[] = "Key up: ";
    strcat(message, SDL_GetScancodeName((SDL_Scancode)key));
    // INFO(message);
    return true;
  }
  return false;
}

bool InputSystem::GetKeyPressed(KeyboardInputGlobal key) {
  if (m_states[key]) {
    char message[] = "Key pressed: ";
    strcat(message, SDL_GetScancodeName((SDL_Scancode)key));
    // INFO(message);
    return true;
  }
  return false;
}

bool InputSystem::GetMouseButtonDown(MouseInputGlobal button) {
  bool isPressed = m_mouseStates & SDL_BUTTON(button);
  bool wasPressed = m_oldMouseStates & SDL_BUTTON(button);
  if (isPressed && !wasPressed) {
    // INFO("Mouse button down");
    return true;
  }
  return false;
}

bool InputSystem::GetMouseButtonUp(MouseInputGlobal button) {
  bool isPressed = m_mouseStates & SDL_BUTTON(button);
  bool wasPressed = m_oldMouseStates & SDL_BUTTON(button);
  if (!isPressed && wasPressed) {
    // INFO("Mouse button up");
    return true;
  }
  return false;
}

bool InputSystem::GetMouseButtonPressed(MouseInputGlobal button) {
  if (m_mouseStates & SDL_BUTTON(button)) {
    return true;
  }
  return false;
}

std::pair<int, int> InputSystem::GetMousePosition() {
  std::pair<int, int> position;
  position = std::make_pair(m_mouseX, m_mouseY);
  return position;
}

void InputSystem::LoadJoysticks() {
  INFO("[INPUT] Loading joysticks");
  int quantity = SDL_NumJoysticks();
  INFO("[INPUT] Found " << quantity << " available joysticks");

  for (int i = 0; i < quantity; i++) {
    SDL_Joystick *sdl_joystick = SDL_JoystickOpen(i);

    if (sdl_joystick) {

      Joystick *joy = new Joystick(sdl_joystick);

      m_joysticks.push_back(joy);
      INFO("    " << SDL_JoystickName(sdl_joystick) << " opened");

    } else {

      INFO("    " << SDL_JoystickName(sdl_joystick) << " could not be opened");
      INFO(SDL_GetError());
    }
  }
}

void InputSystem::UpdateJoysticks() {
  CheckJoystickConnections();
  for (auto joystick : m_joysticks)
    joystick->Update();
}

void InputSystem::CheckJoystickConnections() {
  unsigned int newQuantity = SDL_NumJoysticks();
  if (m_joysticks.size() > newQuantity) {
    INFO("Lost connection to a joystick");
  } else if (m_joysticks.size() < newQuantity) {
    INFO("New connection to a joystick");
  }
}

Joystick *InputSystem::GetJoystick(int index) {
  if (m_joysticks.size() < index + 1)
    return nullptr;
  return m_joysticks.at(index);
}