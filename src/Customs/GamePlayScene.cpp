#include "Customs/GamePlayScene.h"

void GamePlayScene::OnActivation() {
  CreateNakedMan();
  // CreateMap();
}

void GamePlayScene::OnDeactivation() {}

void GamePlayScene::OnShown() {}

void GamePlayScene::OnHidden() {}

void GamePlayScene::CreateNakedMan() {
  int xPos, yPos;
  xPos = EngineGlobals::screen_width / 2 - 32;
  yPos = EngineGlobals::screen_height / 2 - 32;

  auto nakedMan = new GameObject("NakedMan", new Vector(xPos, yPos), 64, 64, 1);

  // renderer
  auto nakedManImage = new Image("assets/nakedmansprite.png", 0, 128, 64, 64);
  auto nakedManRenderer = new Renderer(nakedMan, nakedManImage);

  // animations
  auto nakedManSprite = new Image("assets/nakedmansprite.png", 0, 0, 576, 256);

  auto walkSideAnimation = new Animation(nakedMan, nakedManSprite);
  for (int i = 0; i < 9; i++)
    walkSideAnimation->AddFrame(new Frame(i * 64, 192, 64, 64));

  auto walkUpAnimation = new Animation(nakedMan, nakedManSprite);
  for (int i = 0; i < 9; i++)
    walkUpAnimation->AddFrame(new Frame(i * 64, 0, 64, 64));

  auto walkDownAnimation = new Animation(nakedMan, nakedManSprite);
  for (int i = 0; i < 9; i++)
    walkDownAnimation->AddFrame(new Frame(i * 64, 128, 64, 64));

  // animator
  auto nakedManAnimator = new Animator(nakedMan);
  nakedManAnimator->AddAnimation("Walk Side", walkSideAnimation);
  nakedManAnimator->AddAnimation("Walk Up", walkUpAnimation);
  nakedManAnimator->AddAnimation("Walk Down", walkDownAnimation);

  // script
  auto nakedManScript = new NakedManScript(nakedMan);

  // rigidbody
  // auto nakedManRB = new Rigidbody(nakedMan);

  AddGameObject(nakedMan);
}

void GamePlayScene::CreateMap() {
  auto map = new GameObject("Map", new Vector(0, 0), 2000, 2000);

  // Renderer
  auto mapImage = new Image("assets/map.png", 0, 0, 2000, 2000);
  auto mapRenderer = new Renderer(map, mapImage);

  // Script
  auto mapScript = new MapScript(map);

  AddGameObject(map);
}
