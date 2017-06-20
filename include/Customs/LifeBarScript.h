#ifndef SQUAREORDIE_LIFEBARSCRIPT_H
#define SQUAREORDIE_LIFEBARSCRIPT_H

#include <Components/RectangleRenderer.h>
#include <Components/Script.h>
#include <Customs/PlayerScript.h>
#include <Globals/EngineGlobals.h>

class LifeBarScript : public Script {
public:
  LifeBarScript(GameObject *owner);
  void ComponentUpdate() override;
  std::string GetComponentName() override;
  void SetPlayer(PlayerScript *playerScript);
  void Start() override;

private:
  RectangleRenderer *m_rRenderer;
  PlayerScript *m_playerScript;
};

#endif // SQUAREORDIE_LIFEBARSCRIPT_H
