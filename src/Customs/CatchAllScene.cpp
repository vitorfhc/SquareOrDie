#include "Customs/CatchAllScene.h"

CatchAllScene::CatchAllScene() {}

void CatchAllScene::OnActivation() {
  CreatePlayers();
  CreateMessenger();
}

void CatchAllScene::CreatePlayers() {
  for (unsigned int i = 0; i < 3; i++) {
    std::string playerName = "Player" + std::to_string(i + 1);
    auto player =
        new GameObject(playerName, new Vector(0, 0), 40, 60, 2);
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

void CatchAllScene::CreateMessenger() {
    auto messenger = new GameObject("Messenger", new Vector(0, 0), 500, 100, 5);
    auto messengerText =
            new UIText(messenger, "", "assets/UIpack/Font/kenvector_future_thin.ttf",
                       100, 255, 255, 255, 255, 1);

    CatchAllController::GetInstance()->AddMessenger(messenger);
    AddGameObject(messenger);
}

void CatchAllScene::OnShown() {
  CatchAllController::GetInstance()->StartGame();
}
