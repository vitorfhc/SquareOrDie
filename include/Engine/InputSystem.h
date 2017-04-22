#ifndef __INPUT_SYSTEM__
#define __INPUT_SYSTEM__

#include <utility>
#include <vector>

#include "Engine/sdl2include.h"
#include "Globals/InputGlobals.h"

class InputSystem {
public:
  // singleton getter
  static InputSystem *GetInstance();
  // update m_states and m_oldStates every frame
  void UpdateStates();
  bool GetKeyDown(KeyboardInputGlobal key);
  bool GetKeyUp(KeyboardInputGlobal key);
  bool GetKeyPressed(KeyboardInputGlobal key);
  bool GetMouseButtonDown(MouseInputGlobal button);
  bool GetMouseButtonUp(MouseInputGlobal button);
  bool GetMouseButtonPressed(MouseInputGlobal button);
  std::pair<int, int> GetMousePosition();

private:
  // constructor and destructor
  InputSystem();
  ~InputSystem();
  // Joystick handling
  void LoadJoysticks();
  void UpdateJoysticks();
  void CheckJoystickConnections();
  // private attributes
  static InputSystem *m_instance;
  // keyboard states
  const Uint8 *m_states;
  Uint8 *m_oldStates;
  int m_statesSize;
  // mouse states
  Uint32 m_mouseStates = 0;
  Uint32 m_oldMouseStates = 0;
  int m_mouseX, m_mouseY;
  // joysticks
  std::vector<SDL_Joystick *> m_joysticks;
  int m_joysticksQuantity = 0;
};

#endif // __INPUT_SYSTEM__