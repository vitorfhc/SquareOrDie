#include "Customs/MissileScene.h"
#include <Components/RectangleCollider.h>
#include <Components/RectangleRenderer.h>
#include <Components/UIText.h>
#include <Customs/CatchAllController.h>
#include <Customs/MissileController.h>
#include <Customs/PlayerScript.h>
#include <Customs/LifeBarScript.h>

void MissileScene::OnActivation() {
  CreatePlayers();
  CreateMessenger();
  CreateMissile();
}

void MissileScene::OnShown() { MissileController::GetInstance()->StartGame(); }

void MissileScene::CreatePlayers() {
  for (int i = 0; i < 3; i++) {
    std::string playerName = "Player" + std::to_string(i + 1);
    auto player = new GameObject(playerName, new Vector(0, 0), 40, 60, 2);
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
    Vector offsetText = Vector(5, 0);
    numberText->SetOffset(offsetText);

    MissileController::GetInstance()->AddPlayer(player);
    AddGameObject(player);

    auto lifeBar = new GameObject("LifeBar" + std::to_string(i + 1),
                                  player->GetPosition(), 40, 10, 2);
    auto lifeBarRectangle =
        new RectangleRenderer(lifeBar, Vector(0, -15), 40, 10);
    auto lifeBarScript = new LifeBarScript(lifeBar);
    lifeBarScript->SetPlayer(playerScript);
    lifeBarRectangle->SetColor(255, 0, 0, 255);
    AddGameObject(lifeBar);
  }
}

void MissileScene::CreateMessenger() {
  auto messenger = new GameObject("Messenger", new Vector(0, 0), 500, 100, 5);
  auto messengerText =
      new UIText(messenger, "", "assets/UIpack/Font/kenvector_future_thin.ttf",
                 100, 255, 255, 255, 255, 1);

  MissileController::GetInstance()->AddMessenger(messenger);
  AddGameObject(messenger);
}

void MissileScene::CreateMissile() {
  auto missile = new GameObject("Missile", new Vector(0, 0), 40, 40, 2);
  missile->SetTag("Missile");
  auto missileRectRend = new RectangleRenderer(missile, Vector(0, 0), 40, 40);
  auto missileCol = new RectangleCollider(missile, Vector(0, 0), 40, 40, 0);

  MissileController::GetInstance()->AddMissile(missile);
  AddGameObject(missile);
}