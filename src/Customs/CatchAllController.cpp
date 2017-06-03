#include "Customs/CatchAllController.h"

CatchAllController *CatchAllController::m_instance = nullptr;

void CatchAllController::AddPlayer(GameObject *player) {
  m_players.push_back(player);
  player->active = false;
  m_alive++;
}

CatchAllController::CatchAllController() { m_alive = 0; }

CatchAllController *CatchAllController::GetInstance() {
  if (!m_instance)
    m_instance = new CatchAllController();
  return m_instance;
}

void CatchAllController::StartGame() {
  for (auto player : m_players)
    player->active = true;
  srand(time(NULL));
  auto catcher = rand() % 2;
  auto catcherText = new UIText(m_players[catcher], "C",
                                "assets/UIpack/Font/kenvector_future_thin.ttf",
                                100, 255, 0, 0, 255, 1);
  Vector offset = Vector(5, 40);
  catcherText->SetOffset(offset);
}

void CatchAllController::EndGame() {
  for (auto it : m_players) {
    if (it->active) {
      auto messengerText = (UIText *)SceneManager::GetInstance()
                               ->GetScene("CatchAllScene")
                               ->GetGameObject("Messenger")
                               ->GetComponent("UIText");
      messengerText->SetText(it->GetName() + " WINS!");
      Timer timer = Timer();
      while (!timer.HasPassed(1500)) {
      }
      SceneManager::GetInstance()->SetCurrentScene("Main");
    }
  }
}

void CatchAllController::KillPlayer(GameObject *player) {
  player->active = false;
  m_alive--;
  if (m_alive < 2)
    EndGame();
}