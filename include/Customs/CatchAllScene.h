#ifndef __CATCH_ALL_SCENE__
#define __CATCH_ALL_SCENE__

#include "Components/CircleCollider.h"
#include "Components/CircleRenderer.h"
#include "Components/RectangleCollider.h"
#include "Components/RectangleRenderer.h"
#include "Components/UIText.h"
#include "Customs/CatchAllController.h"
#include "Customs/PlayerScript.h"
#include "Engine/Scene.h"
#include "Globals/EngineGlobals.h"

#include <string>
#include <time.h>
#include <stdlib.h>

class CatchAllScene : public Scene {
public:
  CatchAllScene();
  virtual void OnActivation() override;

    void OnShown() override;

private:
  void CreatePlayers();
  void CreateMessenger();
  void CreateObstacles();

  int m_screenWidth = EngineGlobals::screen_width;
  int m_screenHeight = EngineGlobals::screen_height;
};

#endif
