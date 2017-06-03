#include "Engine/Timer.h"

Timer::Timer() {
    m_startTime = SDL_GetTicks();
}

bool Timer::HasPassed(Uint32 seconds) {
    if (SDL_GetTicks() - m_startTime >= seconds)
        return true;
    return false;
}

void Timer::ResetStartingTime() { m_startTime = SDL_GetTicks(); }

Uint32 Timer::GetCurrentTime() {
    return SDL_GetTicks();
}
