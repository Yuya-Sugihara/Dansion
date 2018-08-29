#ifndef DANSIONENEMY
#define DANSIONENEMY

#include "status.h"
#include <iostream>

using namespace std;
class Player;
class Enemy
{
private:
  int hp,power;
  int ex,ey;
  bool dead;

public:
  void setup(int hp,int power)
  {
    this->hp=hp;
    this->power=power;
    this->dead=false;
  }
  void damage(int damage)
  {
    hp-=damage;
    dead=true;
  }
  bool isDead(){return dead;}
  void move(int x,int y);
  void update(Object* object,const Player* player);
  int x() const{return ex;}
  int y() const{return ey;}
};


#endif
