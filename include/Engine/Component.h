#ifndef __COMPONENT__
#define __COMPONENT__

class GameObject;
#include "Globals/ComponentTypes.h"

class Component {
    public:
    // constructor and destructor
    Component();
    ~Component();
    // getters and setters
    inline ComponentType GetType() { return m_type; };
    inline void SetOwner(GameObject* gameObject) { m_owner = gameObject; };
    // unoverridable update
    virtual void Update() final;

    private:
    ComponentType m_type;
    GameObject* m_owner;

    virtual void ComponentUpdate() = 0;
};

#endif // __COMPONENT__