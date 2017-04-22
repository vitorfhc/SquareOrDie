#ifndef __CUSTOM_SCENE__
#define __CUSTOM_SCENE__

#include "Engine/SceneManager.h"

class CustomScene : public Scene {
  public:
  void OnActivation() override;
  void OnDeactivation() override;
  void OnShown() override;
  void OnHidden() override;

  private:
  SceneManager *sceneManager = nullptr;
};

#endif // __CUSTOM_SCENE__