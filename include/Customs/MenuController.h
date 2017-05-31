#ifndef __MENU_CONTROLLER__
#define __MENU_CONTROLLER__

class MenuController {
public:
  MenuController *GetInstance();
  void SelectGamemode(char gamemode);
  char GetGamemode();

private:
  MenuController();
  MenuController *m_instance = nullptr;
  char m_selectedGamemode = 0x02;
};

#endif
