#ifndef __NAKED_MAN_SCRIPT__
#define __NAKED_MAN_SCRIPT__

#include "Components/Animator.h"
#include "Components/Script.h"
#include "Engine/InputSystem.h"
#include "Globals/EngineGlobals.h"

class NakedManScript : public Script {
public:
  NakedManScript(GameObject *owner);
  std::string GetComponentName() override { return "NakedManScript"; };
  void FixedComponentUpdate() override;
  void Start() override;

protected:
  void ComponentUpdate() override;

private:
  float walkSpeed = 3;
  InputSystem *input = nullptr;
  Animator *animator = nullptr;
  Vector *position = nullptr;
  char movements = 0x00; // up down left right
  int deadzone_x = EngineGlobals::screen_width / 2 + 100;
  int deadzone_y = EngineGlobals::screen_height / 2 + 100;
};

#endif
