#include "Components/Renderer.h"
#include "Engine/GraphicsSystem.h"
#include "Globals/ComponentTypes.h"

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
}

Renderer::~Renderer() { delete m_image; }