#include "Enemy.h"
#include "Player.h"
void Enemy::move(int x,int y)
{
  ex=x;
  ey=y;
}
void Enemy::update(Object* object,const Player* player)
{
  if(this->dead==true)
  {
    //object[ey*width+ex]=NONE;
    return;
  }
  int px=player->x();
  int py=player->y();
  int dx,dy;
  dx=dy=0;

  if(px<ex) dx--;
  else if(px>ex) dx++;
  if(py<ey) dy--;
  else if(py>ey) dy++;

  cout <<"InEnemy.update before:ex,ey: " <<ex <<ey <<endl;
  object[ey*width+ex]=NONE;
  switch (object[(ey+dy)*width+(ex+dx)] ) {
    case NONE:
      move(ex+dx,ey+dy);
      break;
    default:
      dx=dy=0;
      break;
  }
  cout <<"InEnemy.update after :ex,ey: " <<ex <<ey <<endl;
  object[ey*width+ex]=ENEMY;

}
