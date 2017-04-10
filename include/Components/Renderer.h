#ifndef __RENDERER__
#define __RENDERER__

#include <utility>

#include "Engine/Image.h"
#include "Engine/Component.h"
#include "Engine/GraphicsSystem.h"
#include "Math/Vector.h"
#include "Globals/ComponentTypes.h"

class Renderer : public Component
{
  public:
    // constructor and destructor
    Renderer(Vector *position, Image *img, std::pair<int, int> sizes);
    ~Renderer();

  protected:
    // overriding method called by final update
    void ComponentUpdate() override;

  private:
    Image *m_image;
    Vector *m_position;
    std::pair<int, int> m_sizes;
};

#endif // __RENDERER__