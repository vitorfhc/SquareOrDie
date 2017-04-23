#include "Engine/GameObject.h"

GameObject::GameObject(std::string name, Vector *position) {
  m_name = name;
  m_position = position;
}

GameObject::GameObject(std::string name, std::vector<Component *> components,
                       Vector *position) {
  m_name = name;
  m_position = position;
  for (auto it : components)
    AddComponent(it);
}

GameObject::GameObject(std::string name, Component *component,
                       Vector *position) {
  m_name = name;
  m_position = position;
  AddComponent(component);
}

GameObject::~GameObject() {
  delete m_position;
}

void GameObject::Start() {
  for (auto key = m_components.begin(); key != m_components.end(); key++) {
    for (auto component : key->second) {
      component->Start();
    }
  }
}

void GameObject::Update() { ComponentsUpdate(); }

void GameObject::DrawUpdate() {
  auto it = m_components.find(C_DRAW);

  if (it != m_components.end())
    for (auto component : it->second)
      if (component->active)
        component->Update();
}

void GameObject::PhysicsUpdate() {
  auto it = m_components.find(C_PHYSICS);

  if (it != m_components.end())
    for (auto component : it->second)
      if (component->active)
        component->Update();
}

void GameObject::ComponentsUpdate() {
  auto it = m_components.find(C_COMMON);

  if (it != m_components.end())
    for (auto component : it->second)
      if (component->active)
        component->Update();
}

void GameObject::AddComponent(Component *component) {
  auto type = component->GetType();
  auto it = m_components.find(type);

  if (it != m_components.end())
    it->second.push_back(component);
  else {
    m_components.emplace(type, std::vector<Component *>());
    m_components.at(type).push_back(component);
  }
}

void GameObject::AddComponent(std::vector<Component *> components) {
  for (auto it : components)
    AddComponent(it);
}

Component *GameObject::GetComponent(std::string name) {
  for (auto key = m_components.begin(); key != m_components.end(); key++) {
    for (auto value : key->second) {
      if (value->GetComponentName() == name)
        return value;
    }
  }
  return nullptr;
}

void GameObject::FixedUpdate() {
  PhysicsUpdate();

  for (auto key = m_components.begin(); key != m_components.end(); key++) {
    for (auto value : key->second)
      value->FixedComponentUpdate();
  }
}
