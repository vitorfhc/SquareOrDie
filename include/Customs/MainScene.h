#ifndef __MAIN_SCENE__
#define __MAIN_SCENE__

#include "Engine/Scene.h"

class MainScene : public Scene {
public:
  MainScene();
  virtual void OnActivation() override;
  virtual void OnDeactivation() override;
  virtual void OnShown() override;
  virtual void OnHidden() override;

private:
};

#endif
