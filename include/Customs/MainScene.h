#ifndef __MAIN_SCENE__
#define __MAIN_SCENE__

#include "Components/RectangleRenderer.h"
#include "Components/Renderer.h"
#include "Components/UIButton.h"
#include "Components/UIText.h"
#include "Customs/CatchAllButtonScript.h"
#include "Customs/MissileButtonScript.h"
#include "Customs/PlayButtonScript.h"
#include "Customs/QuitButtonScript.h"
#include "Engine/Image.h"
#include "Engine/Scene.h"
#include "Globals/EngineGlobals.h"

class MainScene : public Scene {
public:
  MainScene();
  virtual void OnActivation() override;
  virtual void OnDeactivation() override;
  virtual void OnShown() override;
  virtual void OnHidden() override;

private:
  int m_width_middle;
  int m_height_middle;

  void CreatePlayButton();
  void CreateQuitButton();
  void CreateBackground();
  void CreateGamemodes();
  void CreateMusic();
};

#endif
