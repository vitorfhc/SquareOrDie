#include "Engine/Component.h"

Component::Component() {}

Component::~Component() {}

void Component::Update() {
    ComponentUpdate();
}

void Component::ComponentUpdate() {}