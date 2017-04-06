#ifndef __INPUT_SYSTEM__
#define __INPUT_SYSTEM__

#include "Engine/sdl2include.h"
#include "Log/log.h"

class InputSystem {
    public:
    // singleton getter
    static InputSystem* GetInstance();
    // update m_states and m_oldStates every frame
    void UpdateStates();
    bool GetKeyDown(SDL_Scancode key);
    bool GetKeyUp(SDL_Scancode key);

    private:
    // constructor and destructor
    InputSystem();
    ~InputSystem();
    // private attributes
    static InputSystem* m_instance;
    const Uint8* m_states;
    int m_statesSize;
    Uint8* m_oldStates;
};

#endif // __INPUT_SYSTEM__