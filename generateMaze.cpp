#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

using namespace std;

const int  WIDTH  = 15;
const int  HEIGHT = 20;
const char WALL   = '0';
const char WAY    = '1';

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
      buffer[i][j] = WALL;
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

  // スタート地点とゴール地点を設定
  // スタート地点は上の方に、ゴール地点は下の方に来るように設定
  int startX = 1 + (rand() % (WIDTH - 1));
  int startY = 1 + (rand() % (HEIGHT/2 - 1));
  int goalX  = 1 + (rand() % (WIDTH - 1));
  int goalY  = HEIGHT/2 + (rand() % (HEIGHT/2 - 1)) ;
  //  buf[startY ][startX] = 's';
  
  // ゴールを設定
  buf[goalY][goalX]    = 'g';
  
  // スタート地点の座標を取得してから配列に入れるように、上の行を変更する
  step(buf, startX - 1, startY, startX, startY);

  // 迷路を作成し終えてからスタート地点を設定
  buf[startY ][startX] = 's';
}

////
// 迷路を作成するときの1ステップ
//
void step(char buf[][WIDTH + 2], int px, int py, int x, int y){

  // 前のマスからの差分
  int dx = x - px;
  int dy = y - py;
  
  // マスにまだ道（1）がなければ
  if(buf[y][x] == WALL){
    // 壁より外に出ていなければ
    if(0 < x && x < WIDTH -1 && 0 < y && y < HEIGHT - 1){
      
      
      // さらに一つ先（前左右）が道（1）なら道にせず戻る
      if((buf[y + dy][x + dx] == WAY) || (buf[y + dx][x + dy] == WAY) || (buf[y - dx][x - dy] == WAY)){
        return;
      }
      // 道にする
      buf[y][x] = WAY;
      printf("( %2d, %2d )\n", x, y);
      printMaze(buf);
      cout << "\n";
      usleep(50 * 1000);
    }
  } else {
    // 既に移動先のマスが道なら何もしない
    return;
  }
  
  for(int i=0; i<4; i++){
    if(rand()%2 == 0){
      
      if(i <= 1) { // 5割でまっすぐ
        step(buf, x, y, x + dx, y + dy);
      } else if(i == 2){ // 2.5割でまがる1
        step(buf, x, y, x + dy, y + dx); // 横に曲がるため、dx|dy が y|x と互いに逆にたされる
      } else { // 2.5割でまがる2
        step(buf, x, y, x - dy, y - dx);
      }
      
    } 
  }
  
}
