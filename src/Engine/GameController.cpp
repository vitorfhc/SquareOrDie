#include "Engine/GameController.h"
#include "Log/log.h"

GameController::GameController(SDL_GameController *gc) {
  if (gc) {
    INFO("    " << SDL_GameControllerName(gc) << " opened");
    m_gameController = gc;
  } else {
    ERROR("    Could not open game controller " << SDL_GameControllerName(gc));
  }

  // m_buttonsQnt = SDL_JoystickNumButtons(joystick);
  // m_axesQnt = SDL_JoystickNumAxes(joystick);

  // m_oldButtonsStates.resize(m_buttonsQnt, 0);
  // m_currentButtonsStates.resize(m_buttonsQnt, 0);
  // m_currentAxes.resize(m_axesQnt, 0);
}

GameController::~GameController() { m_gameController = nullptr; }

void GameController::Update() {}

bool GameController::GetButtonDown(int index) {}

bool GameController::GetButtonUp(int index) {}

bool GameController::GetButtonPressed(SDL_GameControllerButton button) {
  return SDL_GameControllerGetButton(m_gameController, button);
}

int GameController::GetAxis(int index) {}