#include "Components/Renderer.h"
#include "Engine/GraphicsSystem.h"
#include "Globals/ComponentTypes.h"
#include "Log/log.h"

#include <math.h>

void Renderer::ComponentUpdate() {
  GraphicsSystem::GetInstance()->Draw(m_image, *m_position, m_sizes);
}

Renderer::Renderer(GameObject *owner, Vector *position, Image *img,
                   std::pair<int, int> sizes)
    : Component(owner, C_DRAW) {
  m_type = C_DRAW;
  m_position = position;
  m_image = img;
  m_sizes = sizes;

  if (!m_image)
    ERROR("Null image on renderer");
}

Renderer::~Renderer() { delete m_image; }

void Renderer::RotateTowards(Vector *point) {
  double angles;
  angles = atan2(point->m_y - m_position->m_y, point->m_x - m_position->m_x);
  angles = angles * 180 / 3.1415;
  if (angles < 0) angles = 360 - (-angles);
  Rotate(angles);
}

void Renderer::Rotate(double angles) {
  GetImage()->Rotate(angles);
}