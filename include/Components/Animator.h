#ifndef __ANIMATOR__
#define __ANIMATOR__

#include <string>
#include <unordered_map>

#include "Components/Animation.h"
#include "Engine/Component.h"

typedef unordered_map<std::string, Animation *> AnimationMap;

class Animator : public Component {
public:
  Animator(GameObject *owner);
  void AddAnimation(std::string name, Animation *animation);
  void ToggleAnimation(std::string name);

private:
  AnimationMap m_aMap;
};

#endif
