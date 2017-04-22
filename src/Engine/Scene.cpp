#include "Engine/Scene.h"
#include "Log/log.h"

Scene::Scene() {}

Scene::~Scene() {}

void Scene::Start() {
  for (auto obj : m_gameObjects)
    obj->Start();
}

void Scene::Update() {
  for (auto it : m_gameObjects)
    if (it->active)
      it->Update();
}

void Scene::DrawUpdate() {
  for (auto it : m_gameObjects)
    if (it->active)
      it->DrawUpdate();
}

void Scene::AddGameObject(GameObject *gameObject) {
  m_gameObjects.push_back(gameObject);
}

void Scene::AddGameObject(std::vector<GameObject *> gameObjects) {
  m_gameObjects.insert(std::end(m_gameObjects), std::begin(gameObjects),
                       std::end(gameObjects));
}

void Scene::FixedUpdate() {
  for (auto it : m_gameObjects)
    if (it->active)
      it->FixedUpdate();
}
