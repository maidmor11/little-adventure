#ifndef ROOM_H
#define ROOM_H
class State
{
public:
  enum current_room {MENU, ARENA};
  virtual void enter() = 0;
  virtual void exit() = 0;
  virtual int transition() = 0;
private:
};

class Menu : public State
{
public:
  void enter();
  void exit();
  int transition();
private:
};

class Arena : public State
{
public:
  void enter();
  void exit();
  int transition();
private:
};
#endif
