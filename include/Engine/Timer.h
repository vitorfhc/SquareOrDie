#ifndef SQUAREORDIE_TIMER_H
#define SQUAREORDIE_TIMER_H

#include "Engine/sdl2include.h"

class Timer {
public:
    Timer();
    void ResetStartingTime();
    bool HasPassed(Uint32 seconds);

private:
    Uint32 m_startTime;
};

#endif //SQUAREORDIE_TIMER_H
