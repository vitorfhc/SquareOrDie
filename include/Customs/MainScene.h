#ifndef __MAIN_SCENE__
#define __MAIN_SCENE__

#include "Components/Renderer.h"
#include "Customs/MapScript.h"
#include "Customs/NakedManScript.h"
#include "Engine/GameObject.h"
#include "Engine/Scene.h"

class MainScene : public Scene {
public:
  virtual void OnActivation() override;
  virtual void OnDeactivation() override;
  virtual void OnShown() override;
  virtual void OnHidden() override;

private:
  void CreateNakedMan();
  void CreateMap();
};

#endif
