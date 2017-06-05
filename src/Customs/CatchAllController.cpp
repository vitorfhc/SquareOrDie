#include "Customs/CatchAllController.h"
#include <Customs/PlayerScript.h>

CatchAllController *CatchAllController::m_instance = nullptr;

void CatchAllController::AddPlayer(GameObject *player) {
  m_players.push_back(player);
}

CatchAllController::CatchAllController() { m_alive = 0; }

CatchAllController *CatchAllController::GetInstance() {
  if (!m_instance)
    m_instance = new CatchAllController();
  return m_instance;
}

void CatchAllController::StartGame() {
  auto msgText = (UIText *)m_messenger->GetComponent("UIText");
  msgText->SetText("");
  m_alive = 3;
  DeactivatePlayers();
  PositPlayers();
  ActivatePlayers();
  DefineCatcher();
}

void CatchAllController::PositPlayers() {
  for (int i = 0; i < 3; i++)
    m_players[i]->SetPosition(Vector(m_wPos[i], m_hPos[i]));
}

void CatchAllController::EndGame(bool runnersWin) {
  if (runnersWin) {
    auto msgText = (UIText *)m_messenger->GetComponent("UIText");
    msgText->SetText("The runners win! Press ESC.");
    DeactivatePlayers();
    return;
  }
  if (m_alive <= 1) {
    auto msgText = (UIText *)m_messenger->GetComponent("UIText");
    auto winner = GetWinner();
    msgText->SetText(winner->GetName() + " wins! Press ESC.");
    DeactivatePlayers();
  }
}

void CatchAllController::KillPlayer(GameObject *player) {
  player->active = false;
  GetPlayerLifeBar(player)->active = false;
  m_alive--;
  EndGame(false);
}

void CatchAllController::DefineCatcher() {
  auto chosen = GetRandomPlayer();
  chosen->SetTag("Catcher");
  auto playerText = (UIText *)chosen->GetComponent("UIText");
  playerText->SetText("C");
}

void CatchAllController::ActivatePlayers() {
  for (auto player : m_players) {
    auto text = (UIText *)player->GetComponent("UIText");
    std::string name = player->GetName();
    auto script = (PlayerScript *)player->GetComponent("PlayerScript");
    script->ResetMovementCheck();
    text->SetText(std::to_string(name.back() - 48));
    player->ClearCollisions();
    player->SetTag("Player");
    GetPlayerLifeBar(player)->active = true;
    player->active = true;
  }
}

void CatchAllController::DeactivatePlayers() {
  for (auto player : m_players) {
    GetPlayerLifeBar(player)->active = false;
    player->active = false;
  }
}

void CatchAllController::AddMessenger(GameObject *messenger) {
  m_messenger = messenger;
  m_messenger->SetSize(EngineGlobals::screen_width - 100, 100);
  m_messenger->SetPosition(Vector(
      EngineGlobals::screen_width / 2 - (m_messenger->GetWidth() / 2),
      EngineGlobals::screen_height / 2 - (m_messenger->GetHeight() / 2)));
}

GameObject *CatchAllController::GetRandomPlayer() {
  srand(time(NULL));
  int playerIndex = rand() % 3;
  return m_players[playerIndex];
}

GameObject *CatchAllController::GetWinner() {
  for (auto player : m_players) {
    if (player->active)
      return player;
  }
}

GameObject *CatchAllController::GetPlayerLifeBar(GameObject *player) {
  std::string playerName = player->GetName();
  std::string lifeName = "LifeBar";
  lifeName += playerName[6];
  return SceneManager::GetInstance()
      ->GetScene("CatchAll")
      ->GetGameObject(lifeName);
}
