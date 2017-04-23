#ifndef __UI_BUTTON__
#define __UI_BUTTON__

#include <string>

#include "Components/Renderer.h"
#include "Engine/Component.h"

class UIButton : public Component {
public:
  // constructor and destructor
  UIButton(GameObject *owner);
  ~UIButton();
  // overrides
  std::string GetComponentName() override { return "UIButton"; };
  void Start() override;
  // uibutton methods
  bool IsClicked();
  bool IsOver();  

private:
  Renderer *m_rendererComponent;
  int m_rendererWidth, m_rendererHeight;
  Vector* m_position;
};

#endif // __UI_BUTTON__