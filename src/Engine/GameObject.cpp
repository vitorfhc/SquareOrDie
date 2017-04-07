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
    PhysicsUpdate();
    DrawUpdate();
}

void GameObject::DrawUpdate() {

}

void GameObject::PhysicsUpdate() {

}

void GameObject::AddComponent(Component* component) {
    auto it = m_components.find(component->GetType());
    if(it != m_components.end()) {
        it->second.push_back(component);
        return;
    }
    m_components.insert(std::make_pair<Uint8, Component*>
                        (component->GetType(), component));
}

void GameObject::AddComponent(std::vector<Component*> components) {
    for(auto it : components)
        AddComponent(it);
}