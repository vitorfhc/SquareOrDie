#ifndef __NAKEDMANSCRIPT__
#define __NAKEDMANSCRIPT__

#include "Components/Animation.h"
#include "Components/Script.h"
#include "Engine/GameObject.h"
#include "Math/Vector.h"
#include "Engine/InputSystem.h"

class NakedManScript : public Script {
public:
  NakedManScript(GameObject *owner);
  void Start() override;

protected:
  void ComponentUpdate() override;
  void FixedComponentUpdate() override;
  std::string GetComponentName() override { return "NakedManScript"; };

private:
  InputSystem *inputSystem = nullptr;
  GameObject *owner = nullptr;
  Animation *animation = nullptr;
  Vector *position = nullptr;
  bool right = false;
  bool left = false;
};

#endif