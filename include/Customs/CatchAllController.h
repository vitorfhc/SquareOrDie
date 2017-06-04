#ifndef SQUAREORDIE_CATCHALLCONTROLLER_H
#define SQUAREORDIE_CATCHALLCONTROLLER_H

using namespace std;

#include "Components/UIText.h"
#include "Engine/GameObject.h"
#include "Engine/Timer.h"

#include <stdlib.h>
#include <time.h>
#include <vector>

class CatchAllController {
public:
  void AddPlayer(GameObject *player);
  void KillPlayer(GameObject *player);
  void StartGame();
  void EndGame(bool runnersWin);
  static CatchAllController *GetInstance();
  void AddMessenger(GameObject *messenger);

private:
  void PositPlayers();
  GameObject *GetWinner();
  GameObject *GetRandomPlayer();
  CatchAllController();
  static CatchAllController *m_instance;
  vector<GameObject *> m_players;
  int m_alive;
  int m_catcher;
  GameObject *m_messenger = nullptr;
  int m_wPos[3] = {0, EngineGlobals::screen_width - 40, 0};
  int m_hPos[3] = {0, EngineGlobals::screen_height - 60,
                   EngineGlobals::screen_height - 60};

  void DefineCatcher();
  void ActivatePlayers();
  void DeactivatePlayers();
};

#endif // SQUAREORDIE_CATCHALLCONTROLLER_H
