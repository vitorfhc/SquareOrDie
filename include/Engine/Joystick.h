#ifndef __JOYSTICK__
#define __JOYSTICK__

#include <vector>

#include "Engine/sdl2include.h"

class Joystick {
public:
  Joystick(SDL_Joystick *joystick);
  ~Joystick();
  void Update();
  bool GetButtonDown(int index);
  bool GetButtonUp(int index);
  bool GetButtonPressed(int index);

private:
  SDL_Joystick *m_joystick = nullptr;

  int m_buttonsQnt = 0;
  int m_axesQnt = 0;

  std::vector<int> m_oldButtonsStates;
  std::vector<int> m_currentButtonsStates;
  std::vector<float> m_currentAxes;
};

#endif // __JOYSTICK__