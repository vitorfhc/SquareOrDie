#ifndef __IMAGE__
#define __IMAGE__

#include <string>

#include "Engine/sdl2include.h"

class Image {
public:
  // image properties
  int width, height;
  int x, y;

  // constructors
  Image();
  Image(std::string path, int x, int y, int width, int height);
  // method for loading the image
  void LoadImage(std::string path, int x, int y, int width, int height);
  // getters
  SDL_Texture *GetTexture();
  SDL_Rect *GetRect();

private:
  // sdl variables for handling image
  SDL_Texture *m_texture;
  SDL_Rect m_rectangle;
};

#endif // __IMAGE__