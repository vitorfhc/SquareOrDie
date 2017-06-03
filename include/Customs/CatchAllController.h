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
  void EndGame();
  static CatchAllController *GetInstance();

private:
  CatchAllController();
  static CatchAllController *m_instance;
  vector<GameObject *> m_players;
  int m_alive;
};

#endif // SQUAREORDIE_CATCHALLCONTROLLER_H
