#include "Customs/CatchAllScene.h"

CatchAllScene::CatchAllScene() {}

void CatchAllScene::OnActivation() {
  CreateObstacles();
  CreatePlayers();
  CreateMessenger();
}

void CatchAllScene::CreatePlayers() {
  for (unsigned int i = 0; i < 3; i++) {
    std::string playerName = "Player" + std::to_string(i + 1);
    auto player =
        new GameObject(playerName, new Vector(m_wPos[i], m_hPos[i]), 40, 60, 2);
    player->SetTag("Player");
    auto playerRectangle = new RectangleRenderer(player, Vector(0, 0), 40, 60);
    srand(time(NULL) * i);
    int color1 = rand() % 255, color2 = rand() % 255, color3 = rand() % 255;
    playerRectangle->SetColor(color1, color2, color3, 255);
    auto playerScript = new PlayerScript(player);
    auto playerCollider =
        new RectangleCollider(player, Vector(0, 0), 40, 60, 0);
    auto numberText = new UIText(player, std::to_string(i + 1),
                                 "assets/UIpack/Font/kenvector_future_thin.ttf",
                                 60, 255, 255, 255, 255, 1);
    Vector offsetText = Vector(5, 5);
    numberText->SetOffset(offsetText);
    CatchAllController::GetInstance()->AddPlayer(player);
    AddGameObject(player);
  }
}

void CatchAllScene::CreateObstacles() {
}

void CatchAllScene::CreateMessenger() {
  auto messenger = new GameObject(
      "Messenger", new Vector(m_screenWidth / 2, m_screenHeight / 2), 200, 100,
      5);
  auto messengerText =
      new UIText(messenger, "", "assets/UIpack/Font/kenvector_future_thin.ttf",
                 200, 255, 255, 255, 255, 1);
  AddGameObject(messenger);
}

void CatchAllScene::OnShown() {
  CatchAllController::GetInstance()->StartGame();
}
