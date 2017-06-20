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
  INFO(m_chosen->GetName());
}

void MissileScript::FollowTarget() {
  // folows the target
}

void MissileScript::Activate() { SelectTarget(); }
