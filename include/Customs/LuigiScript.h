#ifndef __LUIGI_SCRIPT__
#define __LUIGI_SCRIPT__

#include "Components/Script.h"
#include "Components/UIButton.h"

class InputSystem;

class LuigiScript : public Script {
public:
  LuigiScript(GameObject *owner);
  // Start method override
  void Start() override;

protected:
  void ComponentUpdate() override;
  void FixedComponentUpdate() override;
  std::string GetComponentName() override { return "LuigiScript"; };

private:
  InputSystem *input;
  UIButton *button;
};

#endif // __LUIGI_SCRIPT__