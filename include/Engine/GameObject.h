#ifndef __GAME_OBJECT__
#define __GAME_OBJECT__

#include <ostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "Engine/Component.h"
#include "Engine/sdl2include.h"
#include "Globals/ComponentTypes.h"
#include "Math/Vector.h"

class GameObject {
public:
  // active atribbute
  bool active = true;

  // constructor and destructor
  GameObject(std::string name, Vector *position = new Vector(0, 0),
             int width = 0, int height = 0, Uint8 layer = 0);
  ~GameObject();
  // method for handling start and updates
  void Start();
  void Update();
  void FixedUpdate();
  void DrawUpdate();
  // components management
  void AddComponent(Component *component);
  void AddComponent(std::vector<Component *> components);
  Component *GetComponent(std::string name);
  std::unordered_map<Uint32, std::vector<Component *>> GetAllComponents() {
    return m_components;
  };
  std::string GetName() { return m_name; };
  // getter and setter
  inline void SetTag(std::string tag) { m_tag = tag; };
  inline std::string GetTag() { return m_tag; };
  inline Vector *GetPosition() { return m_position; };
  inline void SetPosition(Vector value) { *m_position = value; };
  inline int GetWidth() { return m_width; };
  inline int GetHeight() { return m_height; };
  void SetSize(int width, int height);
  inline Uint8 GetLayer() { return m_layer; };
  Vector GetVelocity();
  // operator overload
  bool operator<(const GameObject &go) const;
  // velocity
  void AddVelocity(Vector velocity);
  // Collision
  void AddCollision(GameObject *gameobject);
  void ClearCollisions();
  std::vector<GameObject *> GetCollisions();

private:
  // map of components
  std::unordered_map<Uint32, std::vector<Component *>> m_components;
  // object properties
  std::string m_name = "no_name_defined";
  std::string m_tag = "";
  Vector *m_position = new Vector(0, 0);
  int m_width = 0;
  int m_height = 0;
  Uint8 m_layer;
  Vector *m_velocity;
  std::vector<GameObject *> m_colliding;

  // methods for handling specific update
  void PhysicsUpdate();
  void ComponentsUpdate();
};

#endif // __GAME_OBJECT__
