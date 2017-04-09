#include "Engine/SceneManager.h"

SceneManager* SceneManager::m_instance = 0;

SceneManager::SceneManager() {
    
}

SceneManager::~SceneManager() {
    m_instance = nullptr;
}

SceneManager* SceneManager::GetInstance() {
    if(!m_instance) m_instance = new SceneManager();
    return m_instance;
}

void SceneManager::SetCurrentScene(std::string sceneName) {
    auto found = m_scenes.find(sceneName);
    if(found != m_scenes.end())
        m_currentScene = std::make_pair(found->first, found->second);
}

void SceneManager::AddScene(std::pair<std::string, Scene*> scenePair) {
    m_scenes.insert(scenePair);
}

void SceneManager::Update() {
    m_currentScene.second->Update();
}

void SceneManager::DrawUpdate() {
    m_currentScene.second->DrawUpdate();
}