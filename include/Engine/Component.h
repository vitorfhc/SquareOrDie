#ifndef __COMPONENT__
#define __COMPONENT__

class GameObject;
#include "Globals/ComponentTypes.h"

class Component
{
  public:
    // constructor and destructor
    Component();
    ~Component();
    // getters and setters
    virtual inline ComponentType GetType() final { return m_type; };
    virtual inline void SetOwner(GameObject *gameObject) final { m_owner = gameObject; };
    // unoverridable update
    virtual void Update() final;

  protected:
    // method to be overriden in derives components
    virtual void ComponentUpdate() = 0;

    // component type
    ComponentType m_type;

  private:
    // gameobject that owns the component
    GameObject *m_owner;
};

#endif // __COMPONENT__