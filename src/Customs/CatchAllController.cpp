#include "Customs/CatchAllController.h"

CatchAllController *CatchAllController::m_instance = nullptr;

void CatchAllController::AddPlayer(GameObject *player) {
  m_players.push_back(player);
  player->active = false;
}

CatchAllController::CatchAllController() { m_alive = 0; }

CatchAllController *CatchAllController::GetInstance() {
  if (!m_instance)
    m_instance = new CatchAllController();
  return m_instance;
}

void CatchAllController::StartGame() {
  ActivatePlayers();
  DefineCatcher();
}

void CatchAllController::EndGame() {
  INFO("CATCH ALL END");

  DeactivatePlayers();

  auto timer = Timer();
  while (!timer.HasPassed(1500)) {
  }

  SceneManager::GetInstance()->SetCurrentScene("Main");
}

void CatchAllController::KillPlayer(GameObject *player) {
  player->active = false;
  m_alive--;
  if (m_alive < 2)
    EndGame();
}

void CatchAllController::DefineCatcher() {
  srand(time(NULL));
  m_catcher = rand() % 2;
  // auto catcherText = new UIText(m_players[m_catcher], "C",
  //                              "assets/UIpack/Font/kenvector_future_thin.ttf",
  //                              100, 255, 0, 0, 255, 1);
  // Vector offset = Vector(5, 40);
  // catcherText->SetOffset(offset);
  m_players[m_catcher]->SetTag("Catcher");
}

std::vector<GameObject *> CatchAllController::GetPlayers() { return m_players; }

void CatchAllController::ActivatePlayers() {
  int i = 0;
  for (auto player : m_players) {
    INFO("ACTIVATING PLAYER");
    player->SetTag("Player");
    player->SetPosition(Vector(m_wPos[i], m_hPos[i]));
    player->active = true;
    i++;
  }
  m_alive = m_players.size();
}

void CatchAllController::DeactivatePlayers() {
  for (auto player : m_players) {
    INFO("DEACTIVATING PLAYER");
    player->SetTag("Player");
    player->active = false;
    player->SetPosition(Vector(0, 0));
  }
  m_alive = m_players.size();
}
