#ifndef SQUAREORDIE_MISSILECONTROLLER_H
#define SQUAREORDIE_MISSILECONTROLLER_H

#include <Engine/GameObject.h>
#include <Globals/EngineGlobals.h>
#include <stdlib.h>
#include <time.h>

class MissileController {
public:
  static MissileController *GetInstance();
  void AddPlayer(GameObject *player);
  void StartGame();
  void KillPlayer(GameObject *player);
  void EndGame();
  GameObject *GetRandomPlayer();
  void AddMissile(GameObject *missile);
  void AddMessenger(GameObject *messenger);

private:
  MissileController();
  void PositPlayers();
  void PositMissile();
  void ActivatePlayers();
  void DeactivatePlayers();
  void ActivateMissile();
  void DeactivateMissile();
  GameObject *GetWinner();
  std::vector<GameObject *> m_players;
  GameObject *m_missile = nullptr;
  GameObject *m_messenger = nullptr;
  static MissileController *m_instance;
  int m_alive = 0;
  int m_wPos[4] = {0, EngineGlobals::screen_width - 40, 0,
                   EngineGlobals::screen_width - 40};
  int m_hPos[4] = {0, EngineGlobals::screen_height - 60,
                   EngineGlobals::screen_height - 60, 0};
};

#endif // SQUAREORDIE_MISSILECONTROLLER_H
