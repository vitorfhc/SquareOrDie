#include "Customs/MainScene.h"

void MainScene::OnActivation() {
  CreateLogo();
  CreatePlayButton();
}

void MainScene::OnDeactivation() {}

void MainScene::OnShown() {}

void MainScene::OnHidden() {}

void MainScene::CreateLogo() {
  int xMiddle = EngineGlobals::screen_width / 2 - 100;

  auto logo = new GameObject("Logo", new Vector(xMiddle, 100), 200, 100);

  auto logoText =
      new UIText(logo, "VoID", "assets/Archivo_Black/ArchivoBlack-Regular.ttf",
                 200, 255, 255, 255, 255, 1);

  AddGameObject(logo);
}

void MainScene::CreatePlayButton() {
  int xMiddle = EngineGlobals::screen_width / 2 - 100;

  auto play = new GameObject("Play", new Vector(xMiddle, 400), 200, 100);

  auto playText = new UIText(play, "Play", "assets/Raleway/Raleway-Regular.ttf",
                             200, 255, 255, 255, 150, 1);

  auto playButton = new UIButton(play);

  auto script = new PlayButtonScript(play);

  AddGameObject(play);
}
