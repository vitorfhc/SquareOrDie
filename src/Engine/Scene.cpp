#include "Engine/Scene.h"

Scene::Scene() {}

Scene::~Scene() {}

void Scene::Update() {
    for (auto it : m_gameObjects)
        it->Update();
}