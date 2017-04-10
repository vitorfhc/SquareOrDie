#ifndef __COMPONENT__
#define __COMPONENT__

#include <string>

#include "Globals/ComponentTypes.h"

class GameObject;

class Component {
public:
  // constructor and destructor
  Component(GameObject *owner);
  ~Component();
  // getters and setters
  virtual inline ComponentType GetType() final { return m_type; };
  virtual inline void SetOwner(GameObject *gameObject) final {
    m_owner = gameObject;
  };
  virtual inline GameObject *GetOwner() { return m_owner; };
  // unoverridable update
  virtual void Update() final;
  // method for getting the component name
  virtual std::string GetComponentName() = 0;

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