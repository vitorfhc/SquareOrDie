#include "Customs/CustomScene.h"
#include "Components/Renderer.h"
#include "Customs/MarioMovement.h"
#include "Engine/GameObject.h"
#include "Engine/Image.h"
#include "Log/log.h"

void CustomScene::OnActivation() {
  INFO("[SCENE] " << GetName() << " OnActivation() called");
  sceneManager = SceneManager::GetInstance();

  GameObject *mario = new GameObject("Mario", new Vector(100, 100), 313 / 2, 207 / 2);

  Image *marioImage = new Image("assets/topdown.png", 0, 0, 313, 207);
  MarioMovement *marioMovement = new MarioMovement(mario);
  Renderer *marioRenderer =
      new Renderer(mario, marioImage);

  AddGameObject(mario);
}

void CustomScene::OnDeactivation() { sceneManager = nullptr; }

void CustomScene::OnShown() {}

void CustomScene::OnHidden() {}