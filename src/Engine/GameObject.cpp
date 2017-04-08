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
    DrawUpdate();
}

void GameObject::DrawUpdate() {
    ComponentType drawTypes[] = { C_RENDERER };

    for(auto type : drawTypes) {
        auto it = m_components.find(type);

        if(it != m_components.end())
            for(auto component : it->second) component->Update();
    }
}

void GameObject::PhysicsUpdate() {
    ComponentType physicsTypes[] = { C_RIGIDBODY };

    for(auto type : physicsTypes) {
        auto it = m_components.find(type);

        if(it != m_components.end())
            for(auto component : it->second) component->Update();
    }
}

void GameObject::ComponentsUpdate() {
    ComponentType commonTypes[] = { C_AUDIO };

    for(auto type : commonTypes) {
        auto it = m_components.find(type);

        if(it != m_components.end())
            for(auto component : it->second) component->Update();
    }
}

void GameObject::AddComponent(Component* component) {
    auto type = component->GetType();
    auto it = m_components.find(type);

    if(it != m_components.end())
        it->second.push_back(component);  
    else
        m_components.insert(std::make_pair<Uint32, std::vector<Component*>>
                        (type, std::vector<Component*>(1, component)));
                        
    component->SetOwner(this);
}

void GameObject::AddComponent(std::vector<Component*> components) {
    for(auto it : components)
        AddComponent(it);
}