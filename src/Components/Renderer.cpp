#include "Components/Renderer.h"

void Renderer::ComponentUpdate() {
  GraphicsSystem::GetInstance()->Draw(m_image, *m_position, m_sizes);
}

Renderer::Renderer(Vector *position, Image *img, std::pair<int, int> sizes) {
  m_type = C_DRAW;
  m_position = position;
  m_image = img;
  m_sizes = sizes;
}

Renderer::~Renderer() { delete m_image; }