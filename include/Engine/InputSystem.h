#ifndef __INPUT_SYSTEM__
#define __INPUT_SYSTEM__

#include <utility>

#include "Engine/sdl2include.h"
#include "Log/log.h"
#include "Globals/InputGlobals.h"

class InputSystem {
    public:
    // singleton getter
    static InputSystem* GetInstance();
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
    // private attributes
    static InputSystem* m_instance;
    // keyboard states
    const Uint8* m_states;
    Uint8* m_oldStates;
    int m_statesSize;
    // mouse states
    Uint32 m_mouseStates = 0;
    Uint32 m_oldMouseStates = 0;
    int m_mouseX, m_mouseY;

};

#endif // __INPUT_SYSTEM__