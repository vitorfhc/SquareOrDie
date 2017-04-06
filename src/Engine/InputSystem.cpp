#include "Engine/InputSystem.h"

// static variables initialization
InputSystem* InputSystem::m_instance = 0;

InputSystem::InputSystem() {
    m_states = SDL_GetKeyboardState(&m_statesSize);
    m_oldStates = new Uint8[m_statesSize];
}

InputSystem::~InputSystem() {
    m_states = nullptr;
    delete [] m_oldStates;
    m_oldStates = nullptr;
}

InputSystem* InputSystem::GetInstance() {
    if(!m_instance) m_instance = new InputSystem();
    return m_instance;
}

void InputSystem::UpdateStates() {
    for(int i = 0; i < m_statesSize; i++)
        m_oldStates[i] = m_states[i];
    SDL_PumpEvents();
}

bool InputSystem::GetKeyDown(SDL_Scancode key) {
    if(m_states[key] && !m_oldStates[key]) {
        char message[] = "Key down: ";
        strcat(message, SDL_GetScancodeName(key));
        INFO(message);
        return true;
    }
    return false;
}

bool InputSystem::GetKeyUp(SDL_Scancode key) {
    if(!m_states[key] && m_oldStates[key]) {
        char message[] = "Key up: ";
        strcat(message, SDL_GetScancodeName(key));
        INFO(message);
        return true;
    }
    return false;
}

