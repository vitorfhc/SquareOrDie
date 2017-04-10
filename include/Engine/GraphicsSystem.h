#ifndef __GRAPHICS_SYSTEM__
#define __GRAPHICS_SYSTEM__

#include "Engine/SDLSystem.h"
#include "Engine/sdl2include.h"
#include "Log/log.h"
#include "Math/Vector.h"

class Image;

class GraphicsSystem {
public:
  // singleton getter
  static GraphicsSystem *GetInstance();
  // draw to renderer function
  void Draw(Image *img, Vector position, std::pair<int, int> sizes);

private:
  // singleton instance
  static GraphicsSystem *m_instance;

  // constructor and destructor
  GraphicsSystem();
  ~GraphicsSystem();
};

#endif // __GRAPHICS_SYSTEM__