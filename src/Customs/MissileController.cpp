#include "Customs/MissileController.h"
#include <Components/UIText.h>
#include <Engine/SceneManager.h>
#include <Engine/Timer.h>
#include <Customs/PlayerScript.h>

MissileController *MissileController::m_instance = nullptr;

void MissileController::AddPlayer(GameObject *player) {
  m_players.push_back(player);
}

MissileController *MissileController::GetInstance() {
  if (!m_instance)
    m_instance = new MissileController();
  return m_instance;
}

void MissileController::StartGame() {
  m_alive = 3;
  DeactivateMissile();
  DeactivatePlayers();
  PositPlayers();
  PositMissile();
  ActivatePlayers();
  ActivateMissile();
}

void MissileController::PositPlayers() {
  for (int i = 0; i < 3; i++)
    m_players[i]->SetPosition(Vector(m_wPos[i], m_hPos[i]));
}

void MissileController::ActivatePlayers() {
  for (auto player : m_players) {
    auto script = (PlayerScript *)player->GetComponent("PlayerScript");
    script->ResetMovementCheck();
    player->ClearCollisions();
    player->active = true;
  }
}

void MissileController::DeactivatePlayers() {
  for (auto player : m_players)
    player->active = false;
}

MissileController::MissileController() {}

void MissileController::AddMissile(GameObject *missile) { m_missile = missile; }

void MissileController::DeactivateMissile() { m_missile->active = false; }

void MissileController::ActivateMissile() { m_missile->active = true; }

void MissileController::PositMissile() {
  m_missile->SetPosition(Vector(m_wPos[3], m_hPos[3]));
}

GameObject *MissileController::GetRandomPlayer() {
  srand(time(NULL));
  int playerIndex = rand() % 3;
  return m_players[playerIndex];
}

void MissileController::EndGame() {
  if (m_alive <= 1) {
    auto msgText = (UIText *)m_messenger->GetComponent("UIText");
    auto winner = GetWinner();
    msgText->SetText(winner->GetName() + " wins! Press ESC.");
    DeactivateMissile();
    DeactivatePlayers();
  }
}

void MissileController::KillPlayer(GameObject *player) {
  player->active = false;
  m_alive--;
  EndGame();
}

void MissileController::AddMessenger(GameObject *messenger) {
  m_messenger = messenger;
  m_messenger->SetSize(EngineGlobals::screen_width - 100, 100);
  m_messenger->SetPosition(Vector(
      EngineGlobals::screen_width / 2 - (m_messenger->GetWidth() / 2),
      EngineGlobals::screen_height / 2 - (m_messenger->GetHeight() / 2)));
}

GameObject *MissileController::GetWinner() {
  for (auto player : m_players) {
    if (player->active)
      return player;
  }
}
