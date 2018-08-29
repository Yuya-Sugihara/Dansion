#ifndef STATUS
#define STATUS


const int width=10;
const int height=7;
const int enemynum=4;
const char stageData[width*height]=
{
  '#','#','#','#','#','#','#','#','#','#',
  '#','E',' ',' ',' ',' ',' ',' ',' ','#',
  '#','#','#','#','P',' ',' ','#',' ','#',
  '#',' ',' ',' ',' ','#',' ','#','E','#',
  '#',' ','E',' ',' ','#',' ','#',' ','#',
  '#',' ',' ',' ','#',' ','E','#',' ','#',
  '#','#','#','#','#','#','#','#','#','#'
};

enum Object{
  WALL, //#
  PLAYER,  //P
  ENEMY,  //E
  NONE,
};


#endif
