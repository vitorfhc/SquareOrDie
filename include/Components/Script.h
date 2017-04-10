#ifndef __SCRIPT__
#define __SCRIPT__

#include <utility>

#include "Engine/Component.h"
#include "Engine/GameObject.h"

class Script : public Component {
public:
  // constructor and destructor
  Script(GameObject *owner);
  // ~Script();
  // pure virtual name getter
  virtual std::string GetComponentName() = 0;

protected:
  // pure virtual comp update
  virtual void ComponentUpdate() = 0;
  // method for getting owner gameobject component
  virtual Component *GetObjectComponent(std::string name) final;
};

#endif // __SCRIPT__