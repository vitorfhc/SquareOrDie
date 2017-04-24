#ifndef __MARIO_MOVEMENT__
#define __MARIO_MOVEMENT__

#include "Components/Script.h"
#include "Engine/GameController.h"
#include "Engine/sdl2include.h"

class Renderer;
class InputSystem;

class MarioMovement : public Script {
public:
  MarioMovement(GameObject *owner);
  // Start method override
  void Start() override;

protected:
  void ComponentUpdate() override;
  void FixedComponentUpdate() override;
  std::string GetComponentName() override { return "MarioMovement"; };

private:
  Vector *position;

  float xMovement = 0, yMovement = 0;

  bool right, left, up, down;
  bool boost, crouch;

  float normalSpeed = 5;
  float movementSpeed = normalSpeed;
  float boostedSpeed = 10;
  float crouchedSpeed = 2;
  
  Renderer *renderer;
  InputSystem *input;
  GameController *gc = nullptr;
};

#endif // __MARIO_MOVEMENT__