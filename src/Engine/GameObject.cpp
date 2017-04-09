#include "Engine/GameObject.h"

GameObject::GameObject(std::vector<Component*> components) {
    for(auto it : components)
        AddComponent(it);
}

GameObject::GameObject(Component* component) {
    AddComponent(component);
}

GameObject::~GameObject() {}

void GameObject::Update() {
    ComponentsUpdate();
    PhysicsUpdate();
}

void GameObject::DrawUpdate() {
    auto it = m_components.find(C_DRAW);

    if(it != m_components.end())
        for(auto component : it->second) component->Update();
    
}

void GameObject::PhysicsUpdate() {
    auto it = m_components.find(C_PHYSICS);

    if(it != m_components.end())
        for(auto component : it->second) component->Update();
}

void GameObject::ComponentsUpdate() {
    auto it = m_components.find(C_COMMON);

    if(it != m_components.end())
        for(auto component : it->second) component->Update();
}

void GameObject::AddComponent(Component* component) {
    auto type = component->GetType();
    auto it = m_components.find(type);

    if(it != m_components.end())
        it->second.push_back(component);  
    else {
        m_components.emplace(type, std::vector<Component*>());
        m_components.at(type).push_back(component);
    }
                        
    component->SetOwner(this);
}

void GameObject::AddComponent(std::vector<Component*> components) {
    for(auto it : components)
        AddComponent(it);
}