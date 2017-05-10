#include "Customs/CustomScene.h"
#include "Components/Renderer.h"
#include "Customs/MapScript.h"
#include "Customs/MarioMovement.h"
#include "Engine/GameObject.h"
#include "Engine/Image.h"
#include "Log/log.h"

void CustomScene::OnActivation() {
  sceneManager = SceneManager::GetInstance();

  GameObject *character =
      new GameObject("Character", new Vector(250, 250), 313 / 5, 207 / 5);

  Image *characterImage = new Image("assets/topdown.png", 0, 0, 313, 207);
  MarioMovement *marioMovement = new MarioMovement(character);
  Renderer *characterRenderer = new Renderer(character, characterImage);

  auto map = new GameObject("map", new Vector(0, 0), 2000, 2000);
  auto mapImg = new Image("assets/map.png", 0, 0, 2000, 2000);
  auto mapRenderer = new Renderer(map, mapImg);
  auto mapScript = new MapScript(map);

  AddGameObject(map);
  AddGameObject(character);
}

void CustomScene::OnDeactivation() { sceneManager = nullptr; }

void CustomScene::OnShown() {}

void CustomScene::OnHidden() {}
