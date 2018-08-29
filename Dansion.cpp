#include <iostream>
#include "status.h"
#include "Player.h"


using namespace std;


void draw(Object* object);
//ステージの初期化、プレイヤーの位置を算出する。
void init(Object* object,Player* player)
{
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
        case 'E': object[i*width+j] = ENEMY; break;
        default: object[i*width+j] = NONE; break;
      }
    }
  }
  draw(object);
}

void input(char* command)
{
  cout << "Please input the command" <<endl;
  cout << "'w': up. 'a': left. 'd':right. 's':down. 'e':exit ";
  cin >>*command;
  if(*command=='e') exit(1);
  cout <<endl;
  //TODO:　複数の入力があった時の例外判定。
  //if(!command[1]=='¥0') cout << "wrong command";
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

int main()
{
  Player* player =new Player(10,100);
  char command;
  const char* stage=new char[width*height];
  stage=stageData;
  Object* object=new Object[width*height]; //変更して描画する。
  for(int i=0;i<width*height;i++) object[i]=WALL;

  init(object,player);
  cout <<"px: " <<player->x() <<" py: " <<player->y() <<endl;
  while(1)
  {
    input(&command);
    player->update(object,command);
    draw(object);
    cout <<"px: " <<player->x() <<" py: " <<player->y() <<endl;
  }

  return 0;
}
