#ifndef __SDLSYSTEM_H__
#define __SDLSYSTEM_H__

#include "Log/log.h"
#include "Log/sdl_log.h"
#include "Globals/EngineGlobals.h"
#include "Globals/InputGlobals.h"
#include "Engine/sdl2include.h"
#include "Engine/InputSystem.h"
#include "Engine/SceneManager.h"
#include "Engine/Image.h"
#include "Components/Renderer.h"
#include "Engine/GameObject.h"

using namespace std;

class SDLSystem
{
  public:
    // initialize all systems
    void Init();
    // run system
    void Run();
    // systems shutdown
    void Shutdown();
    // get singleton instance
    static SDLSystem *GetInstance();
    // getters and setters
    SDL_Window *GetWindow() const { return m_window; };
    SDL_Renderer *GetRenderer() const { return m_renderer; };

  private:
    // SDL attributes
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    // singleton instance
    static SDLSystem *m_instance;
    // game attributes
    bool m_isRunning;
    int m_framerate;
    int m_frameCounter;
    Uint32 m_currentTicks;
    Uint32 m_lastFrameTicks;
    Uint32 m_gameEndTicks;

    // constructor and destructor
    SDLSystem();
    ~SDLSystem();
    // systems init
    bool InitSDL();
    bool InitIMG();
    bool InitMixer();
    bool InitTTF();
    // graphics methods
    bool CreateWindow();
    bool CreateRenderer();
    // system framerate counter
    void CalculateFramerate();
};

#endif //__SDLSYSTEM_H__