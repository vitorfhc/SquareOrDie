#include "Customs/CatchAllScene.h"

CatchAllScene::CatchAllScene() {}

void CatchAllScene::OnActivation() { CreatePlayer(); }

void CatchAllScene::CreatePlayer() {
  auto player = new GameObject("Player", new Vector(10, 10), 40, 60, 1);
  auto playerRectangle = new RectangleRenderer(player, Vector(0, 0), 40, 60);
  playerRectangle->SetColor(0, 150, 0, 255);
  auto playerScript = new PlayerScript(player);
  AddGameObject(player);
}
