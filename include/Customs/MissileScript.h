#ifndef SQUAREORDIE_MISSILESCRIPT_H
#define SQUAREORDIE_MISSILESCRIPT_H

#include <Components/Script.h>

class MissileScript : public Script {
public:
  MissileScript(GameObject *owner);

  std::string GetComponentName() override;

private:
  GameObject *m_chosen = nullptr;

public:
  void FixedComponentUpdate() override;
  void Activate();

private:
  void SelectTarget();

  void FollowTarget();
};

#endif // SQUAREORDIE_MISSILESCRIPT_H
