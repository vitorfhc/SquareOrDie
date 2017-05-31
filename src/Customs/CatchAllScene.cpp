#include "Customs/CatchAllScene.h"

CatchAllScene::CatchAllScene() {}

void CatchAllScene::OnActivation() {
  CreateObstacles();
  CreatePlayer();
}

void CatchAllScene::CreatePlayer() {
  auto player = new GameObject("Player", new Vector(10, 10), 40, 60, 2);
  auto playerRectangle = new RectangleRenderer(player, Vector(0, 0), 40, 60);
  playerRectangle->SetColor(0, 150, 0, 255);
  auto playerScript = new PlayerScript(player);
  auto playerCollider = new RectangleCollider(player, Vector(0, 0), 40, 60, 0);
  AddGameObject(player);
}

void CatchAllScene::CreateObstacles() {
  auto obsRect = new GameObject("ObsRect", new Vector(200, 200), 80, 80, 1);
  auto obsRectRect = new RectangleRenderer(obsRect, Vector(0, 0), 80, 80);
  obsRectRect->SetColor(255, 255, 255, 255);
  auto obsRectCollider =
      new RectangleCollider(obsRect, Vector(0, 0), 80, 80, 0);
  AddGameObject(obsRect);

  auto obsCircle = new GameObject("ObsCircle", new Vector(400, 400), 80, 80, 1);
  auto obsCircleCircle = new CircleRenderer(obsCircle, Vector(0, 0), 40);
  obsCircleCircle->SetColor(255, 255, 255, 255);
  auto colliderOffset = Vector(0, 0);
  auto obsCircleCollider = new CircleCollider(obsCircle, colliderOffset, 40, 0);
  AddGameObject(obsCircle);
}
