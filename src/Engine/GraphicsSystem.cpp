#include "Engine/GraphicsSystem.h"
#include "Engine/SDLSystem.h"
#include "Engine/sdl2include.h"
#include "Log/log.h"

#include <iostream>

GraphicsSystem *GraphicsSystem::m_instance = 0;

GraphicsSystem::GraphicsSystem() {}

GraphicsSystem::~GraphicsSystem() { m_instance = nullptr; }

GraphicsSystem *GraphicsSystem::GetInstance() {
  if (!m_instance)
    m_instance = new GraphicsSystem();
  return m_instance;
}

void GraphicsSystem::Draw(Image *img, Vector *position,
                          std::pair<int, int> sizes) {
  SDL_Rect dest;
  dest.w = sizes.first;
  dest.h = sizes.second;
  dest.x = position->m_x;
  dest.y = position->m_y;

  SDL_SetRenderDrawColor(SDLSystem::GetInstance()->GetRenderer(), 0, 255, 0,
                         255);
  SDL_RenderDrawRect(SDLSystem::GetInstance()->GetRenderer(), &dest);
  SDL_RenderDrawLine(SDLSystem::GetInstance()->GetRenderer(), 0, 0, dest.x,
                     dest.y);

  int result;
  result = SDL_RenderCopyEx(SDLSystem::GetInstance()->GetRenderer(),
                            img->GetTexture(), img->GetRect(), &dest,
                            img->GetRotationAngle(), img->GetSDLPivot(),
                            img->GetSDLFlip());

  if (result < 0)
    ERROR(SDL_GetError());
}

void GraphicsSystem::DrawFrame(Image *img, Frame *frame, Vector *position) {
  SDL_Rect dest;
  dest.w = frame->GetRect()->w;
  dest.h = frame->GetRect()->h;
  dest.x = position->m_x;
  dest.y = position->m_y;

  SDL_SetRenderDrawColor(SDLSystem::GetInstance()->GetRenderer(), 0, 255, 0,
                         255);
  SDL_RenderDrawRect(SDLSystem::GetInstance()->GetRenderer(), &dest);
  SDL_RenderDrawLine(SDLSystem::GetInstance()->GetRenderer(), 0, 0, dest.x,
                     dest.y);

  int result;
  result = SDL_RenderCopyEx(SDLSystem::GetInstance()->GetRenderer(),
                            img->GetTexture(), frame->GetRect(), &dest, 0, NULL,
                            (SDL_RendererFlip)0);

  if (result < 0)
    ERROR(SDL_GetError());
}