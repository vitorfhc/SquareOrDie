#include "Engine/SDLSystem.h"

int main(int argc, char const *argv[]) {
  
  SDLSystem::GetInstance()->Init();
  SDLSystem::GetInstance()->Run();
  SDLSystem::GetInstance()->Shutdown();

  return 0;
}
