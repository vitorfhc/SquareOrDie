#ifndef __RENDERER__
#define __RENDERER__

#include <utility>

#include "Engine/Component.h"
#include "Engine/Image.h"
#include "Math/Vector.h"

class Renderer : public Component {
public:
  // constructor and destructor
  Renderer(GameObject *owner, Image *img,
           std::pair<int, int> sizes);
  ~Renderer();
  // overriding method for getting component name
  inline std::string GetComponentName() override { return "Renderer"; };
  // getter for image
  inline Image *GetImage() { return m_image; };
  inline int GetWidth() { return m_sizes.first; };
  inline int GetHeight() { return m_sizes.second; };
  // setter
  inline void SetSizes(std::pair<int, int> newSizes) { m_sizes = newSizes; };
  // image handling
  void Rotate(double angles);
  void RotateTowards(Vector *point);
  // override for start
  void Start() override;

protected:
  // overriding method called by final update
  void ComponentUpdate() override;

private:
  Image *m_image = nullptr;
  Vector *m_position = nullptr;
  std::pair<int, int> m_sizes;
};

#endif // __RENDERER__