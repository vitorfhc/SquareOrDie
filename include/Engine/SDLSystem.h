#ifndef __SDLSYSTEM_H__
#define __SDLSYSTEM_H__

#include "Log/log.h"
#include "Log/sdl_log.h"
#include "Engine/sdl2include.h"
#include "Globals/EngineGlobals.h"

using namespace std;

class SDLSystem {
    public:
    // initialize all systems
    void Init();
    // run system
    void Run();
    // systems shutdown
    void Shutdown();
    // get singleton instance
    static SDLSystem* GetInstance();

    private:
    // attributes
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    static SDLSystem* m_instance;
    bool m_isRunning;

    // constructor and destructor
    SDLSystem();
    ~SDLSystem();
    // getters and setters
    SDL_Window* GetWindow() const { return m_window; };
    SDL_Renderer* GetRenderer() const { return m_renderer; };
    // systems init
    bool InitSDL();
    bool InitIMG();
    bool InitMixer();
    bool InitTTF();
    // graphics methods
    bool CreateWindow();
    bool CreateRenderer();
};

#endif //__SDLSYSTEM_H__