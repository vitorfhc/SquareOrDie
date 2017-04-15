#include "Engine/Image.h"
#include "Engine/SDLSystem.h"
#include "Log/log.h"

Image::Image() {}

Image::Image(std::string path, int x, int y, int width, int height) {
  LoadImage(path, x, y, width, height);
}

void Image::LoadImage(std::string path, int x, int y, int _width, int _height) {
  SDL_Surface *surface = IMG_Load(path.c_str());

  if (!surface)
    ERROR(IMG_GetError());

  m_texture = SDL_CreateTextureFromSurface(
      SDLSystem::GetInstance()->GetRenderer(), surface);

  if (!m_texture)
    ERROR(SDL_GetError());

  SDL_FreeSurface(surface);

  m_rectangle.x = x;
  m_rectangle.y = y;
  m_rectangle.w = _width;
  m_rectangle.h = _height;

  width = _width;
  height = _height;
}

SDL_Texture *Image::GetTexture() { return m_texture; }

SDL_Rect *Image::GetRect() { return &m_rectangle; }

void Image::SetPivot(int x, int y) {
  if (!sdlPivotPtr) sdlPivotPtr = &sdlPivot;
  sdlPivot.x = x;
  sdlPivot.y = y;

  if (!m_pivot)
    m_pivot = new Vector(0, 0);
  m_pivot->m_x = x;
  m_pivot->m_y = y;
}

void Image::Flip(bool horizontal, bool vertical) {
  m_horizontalFlip = horizontal;
  m_verticalFlip = vertical;

  SDL_RendererFlip flag = SDL_FLIP_NONE;
  if (horizontal)
    flag = SDL_FLIP_HORIZONTAL;
  if (vertical)
    flag = (SDL_RendererFlip)(flag | SDL_FLIP_VERTICAL);

  sdlFlip = flag;
}