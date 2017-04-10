#ifndef __RENDERER__
#define __RENDERER__

#include <utility>

#include "Engine/Component.h"
#include "Engine/Image.h"
#include "Math/Vector.h"

class Renderer : public Component {
public:
  // constructor and destructor
  Renderer(GameObject *owner, Vector *position, Image *img,
           std::pair<int, int> sizes);
  ~Renderer();
  // overriding method for getting component name
  inline std::string GetComponentName() override { return "Renderer"; };
  inline Vector GetPosition() { return *m_position; };
  inline void SetPosition(Vector vector) { *m_position = vector; };
  // getter for image
  inline Image* GetImage() { return m_image; };

protected:
  // overriding method called by final update
  void ComponentUpdate() override;

private:
  Image *m_image;
  Vector *m_position;
  std::pair<int, int> m_sizes;
};

#endif // __RENDERER__