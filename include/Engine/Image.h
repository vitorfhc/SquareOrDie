#ifndef __IMAGE__
#define __IMAGE__

#include <string>

#include "Engine/sdl2include.h"
#include "Math/Vector.h"

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
  // getters and setters
  SDL_Texture *GetTexture();
  SDL_Rect *GetRect();
  inline double GetRotationAngle() { return m_rotation; };
  inline SDL_Point *GetSDLPivot() { return &sdlPivot; };
  inline SDL_RendererFlip GetSDLFlip() { return sdlFlip; };
  inline void Rotate(double angles) { m_rotation = angles; };
  void SetPivot(int x, int y);
  void Flip(bool horizontal, bool vertical);

private:
  // sdl variables for handling image
  SDL_Texture *m_texture;
  SDL_Rect m_rectangle;
  double m_rotation;
  SDL_Point sdlPivot;
  SDL_RendererFlip sdlFlip;
  // adpted image properties
  Vector m_pivot;
  bool m_horizontalFlip;
  bool m_verticalFlip;
};

#endif // __IMAGE__