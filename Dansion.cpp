#include <iostream>
#include <cstdlib>
#include "status.h"
#include "Player.h"
#include "Enemy.h"


using namespace std;


void draw(Object* object);
//ステージの初期化、プレイヤーの位置を算出する。
void init(Object* object,Player* player,Enemy* enemy)
{
  int count=0;
  for(int i=0;i<height;i++)
  {
    for(int j=0;j<width;j++)
    {
      switch (stageData[i*width+j]){
        case '#': object[i*width+j] = WALL; break;
        case 'P':
          object[i*width+j] = PLAYER;
          player->move(j,i);
          break;
        case 'E':
          object[i*width+j] = ENEMY;
          if(count>enemynum) cout <<"Init: count is wrong." <<endl;
          enemy[count].move(j,i);
          count++;
          break;
        default: object[i*width+j] = NONE; break;
      }
    }
  }
  draw(object);
}

void input(char* command)
{
  cout << "Please input the command" <<endl;
  cout << "'w': up. 'a': left. 'd':right. 's':down. 'g':attack. 'e':exit ";
  cin >>*command;
  if(*command=='e') exit(1);
  cout <<endl;
  //TODO:　複数の入力があった時の例外判定。
  //if(!command[1]=='¥0') cout << "wrong command";
}

void battle(char command,Player* player,Enemy* enemy,Object* object,
            int& remaining)
{
  if(command=='g')
  {
    if(enemy->isDead()) {
      return;
    }
    if( ( abs( enemy->x() - player->x() ) ) <=1 &&
      ( ( abs( enemy->y() - player->y() )<=1) ) )
    {
      enemy->damage(player->attack());
      if(enemy->isDead()) {
        object[enemy->y()*width+enemy->x()]=NONE;
        remaining--;
      }
    }
  }
}


void draw(Object* object)
{
  //cout <<object[2*width+4] <<endl;
  for(int i=0;i<height;i++)
  {
    for(int j=0;j<width;j++)
    {
      switch (object[width*i+j])
      {
        case WALL: cout << "#" <<" "; break;
        case PLAYER: cout << "P" <<" "; break;
        case ENEMY: cout << "E" <<" "; break;
        case NONE: cout << "  "; break;
        default: cout <<"error " <<endl; exit(1);
      }
    }
    cout <<endl;

  }
}
void gameClear()
{
  cout << "Conguratularion!!" <<endl;
}

int main()
{

  Player* player =new Player(10,100);
  Enemy* enemy=new Enemy[enemynum];
  int remaining=enemynum;
  char command;
  char* stage=new char;
  //stage=stageData;
  //cout <<stage<<endl;
  Object* object=new Object[width*height]; //変更して描画する。

  for(int i=0;i<enemynum;i++)
  {
    enemy[i].setup(10,10);
  }


  init(object,player,enemy);


  while(1)
  {
    input(&command);
    if(command=='q') break;
    player->update(object,command);
    for(int i=0;i<enemynum;i++)
    {
      battle(command,player,&enemy[i],object,remaining);

      enemy[i].update(object,player);
    }
    draw(object);
    cout <<"px: " <<player->x() <<" py: " <<player->y() <<endl;
    if(remaining==0) {
      gameClear();
      break;
    }
  }

  delete player;
  //for(int i=0;i<enemynum;i++) delete enemy[i];
  delete[] enemy;
  //delete stage;
  delete[] object;

  return 0;
}
