#ifndef __PLAYER_SCRIPT__
#define __PLAYER_SCRIPT__

#include "Components/RectangleRenderer.h"
#include "Components/Script.h"
#include "Engine/GameObject.h"
#include "Engine/InputSystem.h"
#include "Log/log.h"

using namespace std;

class PlayerScript : public Script {
public:
  PlayerScript(GameObject *owner);
  virtual string GetComponentName() override { return "PlayerScript"; };
  void ComponentUpdate() override;
  void FixedComponentUpdate() override;

private:
  Vector m_movement = Vector(0, 0);
  float m_speed = 10;
  void HandleInput();
  KeyboardInputGlobal m_up, m_down, m_left, m_right;
};

#endif
