#ifndef __COMPONENT__
#define __COMPONENT__

#include "Engine/GameObject.h"
#include "Globals/ComponentTypes.h"

class Component {
    public:
    // constructor and destructor
    Component();
    ~Component();
    // getters and setters
    inline virtual ComponentType GetType() final { return m_type; };
    inline virtual void SetOwner(GameObject* go) final { m_owner = go; };
    // unoverridable update
    virtual void Update() final {};

    private:
    ComponentType m_type;
    GameObject* m_owner;

    virtual void ComponentUpdate() = 0;
};

#endif // __COMPONENT__