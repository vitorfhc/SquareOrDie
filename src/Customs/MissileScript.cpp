//
// Created by vitorfhc on 20/06/17.
//

#include "Customs/MissileScript.h"
#include <Customs/MissileController.h>
#include <Customs/MissileScene.h>
#include <Engine/SceneManager.h>
#include <Log/log.h>

MissileScript::MissileScript(GameObject *owner) : Script(owner) {}

std::string MissileScript::GetComponentName() { return "MissileScript"; }

void MissileScript::SelectTarget() {
  auto mScene = MissileController::GetInstance();
  m_chosen = mScene->GetRandomPlayer();
}

void MissileScript::FixedComponentUpdate() {
  if (!m_chosen || !m_chosen->active)
    SelectTarget();
  FollowTarget();
}

void MissileScript::FollowTarget() {
  Vector direction;
  direction.m_x = m_chosen->GetPosition()->m_x - GetOwner()->GetPosition()->m_x;
  direction.m_y = m_chosen->GetPosition()->m_y - GetOwner()->GetPosition()->m_y;
  direction = direction.GetNormalized();
  GetOwner()->SetPosition(*GetOwner()->GetPosition() + direction * m_speed);
}

void MissileScript::Activate() { SelectTarget(); }
