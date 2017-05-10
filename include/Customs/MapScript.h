#ifndef __MAP_SCRIPT__
#define __MAP_SCRIPT__

#include "Components/Script.h"
#include "Engine/SceneManager.h"
#include "Globals/EngineGlobals.h"
#include "Log/log.h"

class MapScript : public Script {
public:
  MapScript(GameObject *owner);
  void Start() override;

protected:
  void ComponentUpdate() override;
  void FixedComponentUpdate() override;
  std::string GetComponentName() override { return "MapScript"; };

private:
  GameObject *character = nullptr;
  Vector *charPos = nullptr;
};

#endif
