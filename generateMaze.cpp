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
  step(buf, startX - 2, startY, startX, startY);
  
  // スタート地点を記しておく
  buf[startY][startX] = 's';
}

////
// 迷路を作成するときの1ステップ
// 引数は 迷路バッファ、前の地点座標、移動してきた地点座標
//
void step(char buf[][WIDTH + 2], int px, int py, int x, int y){
  // 今いる場所が無効（壁の外側、または壁か道）なら return
  if((x < 0 || WIDTH < x) || (y < 0 || HEIGHT < y) || buf[y][x] != EMPTY){
      return;
  }

  // 今きた経路を「道」としてを確定する
  int dx = (x - px)/2;
  int dy = (y - py)/2;

  buf[y][x]       = WAY;
  buf[y-dy][x-dx] = WAY;
 
  //  srand((unsigned)time(NULL));
  usleep(100 * 1000);
  printMaze(buf);

  // ある程度ランダムでどこかへ行く
  switch(rand()%2){
  case 0:
    step(buf, x, y, x + 2, y    );
    step(buf, x, y, x - 2, y    );
    break;

  case 1:
    step(buf, x, y, x    , y + 2);
    step(buf, x, y, x    , y - 2);
    break;
  }

}
