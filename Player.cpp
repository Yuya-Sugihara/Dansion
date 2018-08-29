#include "Player.h"

int Player::attack()
{
  return power;
}
void Player::move(int x,int y)
{
  px=x;
  py=y;
}
void Player::update(Object* object,char command)
{
  int dx,dy;
  dx=dy=0;
  switch(command){
    case 'w': dy-=1; break;
    case 'a': dx-=1; break;
    case 'd': dx+=1; break;
    case 's': dy+=1; break;
    default: return ;
  }
  cout <<"InPlayer.update before:px,py: " <<px <<py <<endl;
  object[py*width+px]=NONE;
  switch (object[(py+dy)*width+(px+dx)] ) {
    case NONE:
      move(px+dx,py+dy);
      break;
    default:
      dx=dy=0;
      break;
  }
  cout <<"InPlayer.update after :px,py: " <<px <<py <<endl;
  object[py*width+px]=PLAYER;
}
