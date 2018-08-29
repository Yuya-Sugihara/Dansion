#ifndef DANSIONPLAYER
#define DANSIONPLAYER

#include "status.h"
#include <iostream>
using namespace std;
class Player
{
private:
  int px,py;
  int power,hp;

public:
  
  Player(int power,int hp): power(power),hp(hp)
  {
  };

  void move(int x,int y);
  int x() const {return this->px;}
  int y() const {return this->py;}
  void update(Object* object,char command);
  int attack();

};




#endif
