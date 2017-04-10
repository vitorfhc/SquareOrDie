#include "Engine/Component.h"

Component::Component() {}

Component::~Component()
{
    m_owner = nullptr;
}

void Component::Update()
{
    ComponentUpdate();
}