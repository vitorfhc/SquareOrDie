#ifndef __MARIO_MOVEMENT__
#define __MARIO_MOVEMENT__

#include "Components/Script.h"

class Renderer;
class InputSystem;

class MarioMovement : public Script {
public:
  MarioMovement(GameObject *owner);
  // Start method override
  void Start() override;

protected:
  void ComponentUpdate() override;
  std::string GetComponentName() override { return "MarioMovement"; };
private:
  Renderer *renderer;
  InputSystem *input;
};

#endif // __MARIO_MOVEMENT__