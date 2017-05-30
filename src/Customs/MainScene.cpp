#include "Customs/MainScene.h"

MainScene::MainScene() {}

void MainScene::OnActivation() {
  m_width_middle = EngineGlobals::screen_width / 2;
  m_height_middle = EngineGlobals::screen_height / 2;

  CreatePlayButton();
  CreateQuitButton();
  CreateBackground();
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

  AddGameObject(quitButton);
}

void MainScene::CreateBackground() {
  auto background = new GameObject("Background", new Vector(0, 0),
                                   m_width_middle * 2, m_height_middle * 2, 0);
  auto backgroundRectangle = new RectangleRenderer(
      background, Vector(0, 0), m_width_middle * 2, m_height_middle * 2);
  backgroundRectangle->SetColor(255, 255, 255, 255);
  AddGameObject(background);
}
