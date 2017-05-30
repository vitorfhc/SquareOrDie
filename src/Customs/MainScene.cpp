#include "Customs/MainScene.h"

MainScene::MainScene() {}

void MainScene::OnActivation() {
  m_width_middle = EngineGlobals::screen_width / 2;
  m_height_middle = EngineGlobals::screen_height / 2;

  CreatePlayButton();
  CreateQuitButton();
  CreateBackground();
  CreateGamemodes();
}

void MainScene::OnDeactivation() {}

void MainScene::OnShown() {}

void MainScene::OnHidden() {}

void MainScene::CreatePlayButton() {
  auto playButton = new GameObject(
      "PlayButton", new Vector(m_width_middle - (190 * 1.4 / 2), 100),
      190 * 1.4, 45 * 1.4, 1);
  auto playButtonImage =
      new Image("assets/UIpack/Spritesheet/greenSheet.png", 0, 94, 190, 45);
  auto playButtonRenderer = new Renderer(playButton, playButtonImage);
  auto playButtonText =
      new UIText(playButton, "Play", "assets/UIpack/Font/kenvector_future.ttf",
                 120, 255, 255, 255, 255, 1);
  auto vec = Vector(10, 0);
  playButtonText->SetOffset(vec);

  AddGameObject(playButton);
}

void MainScene::CreateQuitButton() {
  auto quitButton = new GameObject(
      "QuitButton",
      new Vector(m_width_middle - (190 * 1.4 / 2), 100 + (45 * 1.4)), 190 * 1.4,
      45 * 1.4, 1);
  auto quitButtonImage =
      new Image("assets/UIpack/Spritesheet/redSheet.png", 0, 94, 190, 45);
  auto quitButtonRenderer = new Renderer(quitButton, quitButtonImage);
  auto quitButtonText =
      new UIText(quitButton, "Quit", "assets/UIpack/Font/kenvector_future.ttf",
                 120, 255, 255, 255, 255, 1);
  auto vec = Vector(10, 0);
  quitButtonText->SetOffset(vec);

  AddGameObject(quitButton);
}

void MainScene::CreateBackground() {
  auto background = new GameObject("Background", new Vector(0, 0),
                                   m_width_middle * 2, m_height_middle * 2, 0);
  auto backgroundRectangle = new RectangleRenderer(
      background, Vector(0, 0), m_width_middle * 2, m_height_middle * 2);
  backgroundRectangle->SetColor(20, 20, 20, 255);
  AddGameObject(background);
}

void MainScene::CreateGamemodes() {
  // catch all
  auto catchAllButton = new GameObject(
      "CatchAllButton", new Vector(m_width_middle - 100 - 5, 300), 100, 100, 1);
  auto catchAllImage =
      new Image("assets/UIpack/Spritesheet/greySheet.png", 190, 98, 100, 100);
  auto catchAllRenderer = new Renderer(catchAllButton, catchAllImage);
  AddGameObject(catchAllButton);
  auto catchAllText = new UIText(catchAllButton, "Catch All",
                                 "assets/UIpack/Font/kenvector_future_thin.ttf",
                                 100, 0, 0, 0, 255, 1);
  auto vec = Vector(2, 0);
  catchAllText->SetOffset(vec);

  // missile
  auto missileButton = new GameObject(
      "MissileButton", new Vector(m_width_middle + 5, 300), 100, 100, 1);
  auto missileImage =
      new Image("assets/UIpack/Spritesheet/greySheet.png", 190, 98, 100, 100);
  auto missileRenderer = new Renderer(missileButton, catchAllImage);
  auto missileText = new UIText(missileButton, "Missile",
                                "assets/UIpack/Font/kenvector_future_thin.ttf",
                                100, 0, 0, 0, 255, 1);
  vec = Vector(2, 0);
  missileText->SetOffset(vec);
  AddGameObject(missileButton);
}
