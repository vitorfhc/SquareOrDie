#include "Engine/GraphicsSystem.h"
#include "Engine/SDLSystem.h"
#include "Engine/sdl2include.h"
#include "Log/log.h"

GraphicsSystem *GraphicsSystem::m_instance = 0;

GraphicsSystem::GraphicsSystem() {}

GraphicsSystem::~GraphicsSystem() { m_instance = nullptr; }

GraphicsSystem *GraphicsSystem::GetInstance() {
  if (!m_instance)
    m_instance = new GraphicsSystem();
  return m_instance;
}

void GraphicsSystem::Draw(Image *img, Vector position,
                          std::pair<int, int> sizes) {
  SDL_Rect dest;
  dest.w = sizes.first;
  dest.h = sizes.second;
  dest.x = position.m_x;
  dest.y = position.m_y;

  int result = SDL_RenderCopy(SDLSystem::GetInstance()->GetRenderer(),
                              img->GetTexture(), img->GetRect(), &dest);

  if (result < 0) {
    ERROR(SDL_GetError());
    exit(1);
  }
}