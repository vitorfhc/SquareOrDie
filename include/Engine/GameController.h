#ifndef __GAME_CONTROLLER__
#define __GAME_CONTROLLER__

#include <vector>

#include "Engine/sdl2include.h"

class GameController {
public:
  GameController(SDL_GameController *gc);
  ~GameController();
  void Update();
  bool GetButtonDown(int index);
  bool GetButtonUp(int index);
  bool GetButtonPressed(SDL_GameControllerButton button);
  int GetAxis(int index);
  int GetButtonsQuantity() { return m_buttonsQnt; };

private:
  SDL_GameController *m_gameController = nullptr;

  int m_buttonsQnt = 0;
  int m_axesQnt = 0;

  std::vector<int> m_oldButtonsStates;
  std::vector<int> m_currentButtonsStates;
  std::vector<float> m_currentAxes;
};

#endif // __GAME_CONTROLLER__