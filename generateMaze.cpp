#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

using namespace std;

const int  WIDTH  = 31; // 偶数の通りをキレイに通るように奇数とする
const int  HEIGHT = 31; // 同上
const char WALL   = 'x';
const char WAY    = '1';
const char EMPTY  = ' ';

void generateMaze(char buf[][WIDTH + 2]);
void generateRandomMaze(char buf[][WIDTH + 2]);
void step(char buf[][WIDTH + 2], int px, int py, int x, int y);
void saveMazeFile(char buf[][WIDTH + 2], const char* name);
void printMaze(char buf[][WIDTH + 2]);

////
// main
//
int main(int argc, char* argv[]){
  
  // 迷路バッファ
  char buffer[HEIGHT][WIDTH + 2];
  
  // バッファの初期化
  for(int i=0; i<HEIGHT; i++){
    for(int j=0; j<WIDTH; j++){
      if((i == 0 || i == HEIGHT - 1) || ( j == 0 || j == WIDTH - 1) ){
        buffer[i][j] = WALL;
      } else {
        buffer[i][j] = EMPTY;
      }
    }
    
    // ヌル文字と改行を文末につける
    buffer[i][WIDTH] = '\n';
    buffer[i][WIDTH + 1] = '\0';
  }
  
  // 迷路を生成する
  //  generateMaze(buffer);
  generateRandomMaze(buffer);

  // 迷路を表示する
  printMaze(buffer);

  // 迷路をファイルに保存
  saveMazeFile(buffer, "maze.txt");
}

////
// 迷路バッファを表示する
//
void printMaze(char buf[][WIDTH + 2]){
  
  // 確認、改行コードを含んでいるので表示のときに改行しない
  for(int i=0; i<HEIGHT; i++){
    printf("%3d : %s", i, buf[i]);
  }
  
}

////
// 迷路を生成する
//
void generateMaze(char buf[][WIDTH + 2]){
  
  // 乱数初期化
  srand((unsigned)time(NULL));

  int randomNum;
  
  // ランダムで何か入れる（予定）
  for(int i=1; i<HEIGHT - 1; i++){
    for(int j=1; j<WIDTH - 1; j++){
      // buf[i][j] = WALL;
      //itoa(rand() % 5, &ascii, 10);
      
      randomNum = rand() % 3;
      if(randomNum == 1){
        buf[i  ][j  ] = WAY;
        buf[i+1][j  ] = WAY;
        buf[i-1][j  ] = WAY;
        buf[i  ][j+1] = WAY;
        buf[i  ][j-1] = WAY;
      } else {
        //       buf[i][j] = WALL;
      }
    }
  }
  
  // スタート地点とゴール地点を設定
  // スタート地点は上の方に、ゴール地点は下の方に来るように設定
  buf[1 + (rand() % (HEIGHT/2 - 1)) ][1 + (rand() % (WIDTH - 1))] = 's';
  buf[HEIGHT/2 + (rand() % (HEIGHT/2 - 1)) ][1 + (rand() % (WIDTH - 1))] = 'g';
  
}

////
// 迷路をファイルに書き込む
//
void saveMazeFile(char buf[][WIDTH + 2], const char* name){
  
  // ファイルポインタ
  FILE* pFile = fopen(name, "w");
  
  // ファイル書き込み
  for(int i=0; i<HEIGHT; i++){
    fputs(buf[i], pFile);
  }
  fclose(pFile);
  
}

////
// 通路上の迷路をランダムに作成する
//
void generateRandomMaze(char buf[][WIDTH + 2]){

  // 乱数初期化
  srand((unsigned)time(NULL));

  // スタート地点を、偶数の点から選ぶ
  int startX = 2 + (rand() % (WIDTH/2 - 1)) * 2;
  int startY = 2 + (rand() % (HEIGHT/2 - 1)) * 2;  
  
  // TODO
  // このへんから step を呼び出したりするかも
  step(buf, 0, 0, startX, startY);
  
  // スタート地点を記しておく
  buf[startY][startX] = 's';
}

////
// 迷路を作成するときの1ステップ
// 引数を、進む方向と座標に変更する。
//
void step(char buf[][WIDTH + 2], int px, int py, int x, int y){
  
  // TODO
  //  srand((unsigned)time(NULL));
  usleep(100 * 1000);
  printMaze(buf);
  
  // 進む方向を決める、元来た道を戻ることになるなら再度道を決める
  int dx, dy;
  do{    
    switch(rand()%4){
    case 0:
      dx = 1;
      dy = 0;
      break;
      
    case 1:
      dx = 0;
      dy = 1;
      break;
      
    case 2:
      dx = -1;
      dy = 0;
      break;
      
    case 3:
      dx = 0;
      dy = -1;
      break;
      
    default:
      cout << "default\n";
      break;
    }
  }while( (x - px + 2*dx) == 0 && (y - py + 2*dy == 0));
  
  // 次に向かう先の座標
  int nx = x + dx + dx;
  int ny = y + dy + dy;
  // 進めるかどうか、2マス先まで見る
  if(0 <= nx && nx < WIDTH){
    if(0 <= ny && ny < HEIGHT){
      // 1マス、2マス先に道がなければ道にする
      if(buf[y + dy][x + dx] == EMPTY && buf[ny][nx] == EMPTY){
        buf[y + dy][x + dx] = WAY;
        buf[ny][nx] = WAY;
        // 次のステップへ
        step(buf, x, y, nx, ny);
      }
    }
  }
  // 進めなければリターンする
  return;
  
  // 壁とかじゃなければ2マス進み道にする
  
  // 進めなくなったらリターン、今までの道（偶数点）からランダムに再開する
  // すべての道が埋まるまでやる?全体を調べておかないといけない。
  
}
