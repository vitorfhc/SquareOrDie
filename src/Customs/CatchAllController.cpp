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
  UIText *messengerText;
  for (auto it : m_players) {
    if (it->active) {
      messengerText = (UIText *)SceneManager::GetInstance()
                          ->GetScene("CatchAll")
                          ->GetGameObject("Messenger")
                          ->GetComponent("UIText");
      messengerText->SetText(it->GetName() + " WINS!");
      it->active = false;
    }
  }
  messengerText->SetText("");
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
  auto catcherText = new UIText(m_players[m_catcher], "C",
                                "assets/UIpack/Font/kenvector_future_thin.ttf",
                                100, 255, 0, 0, 255, 1);
  Vector offset = Vector(5, 40);
  catcherText->SetOffset(offset);
  m_players[m_catcher]->SetTag("Catcher");
}

std::vector<GameObject *> CatchAllController::GetPlayers() { return m_players; }

void CatchAllController::ActivatePlayers() {
  int seed = 1024;
  for (auto player : m_players) {
    player->SetTag("Player");
      srand(time(NULL) * seed);
      int w = rand() % (EngineGlobals::screen_width - 60);
      int h = rand() % (EngineGlobals::screen_height - 60);
      player->SetPosition(Vector(w, h));
      seed *= 0.2;
      player->active = true;
  }
  m_alive = m_players.size();
}
