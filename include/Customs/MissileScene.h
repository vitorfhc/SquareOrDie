#ifndef SQUAREORDIE_MISSILESCENE_H
#define SQUAREORDIE_MISSILESCENE_H


#include <Engine/Scene.h>

class MissileScene : public Scene {
public:
    void OnActivation() override;

    void OnShown() override;

private:
    void CreatePlayers();
    void CreateMissile();
    void CreateMessenger();

};


#endif //SQUAREORDIE_MISSILESCENE_H
