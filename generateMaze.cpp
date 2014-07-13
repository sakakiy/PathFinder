#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int WIDTH  = 15;
const int HEIGHT = 20;


void generateMaze(char buf[][WIDTH + 2]);
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
      buffer[i][j] = '0';
    }
    
    // ヌル文字と改行を文末につける
    buffer[i][WIDTH] = '\n';
    buffer[i][WIDTH + 1] = '\0';
  }
  
  // 迷路を生成する
  generateMaze(buffer);

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
      // buf[i][j] = '0';
      //itoa(rand() % 5, &ascii, 10);
      
      randomNum = rand() % 3;
      if(randomNum == 1){
        buf[i  ][j  ] = '1';
        buf[i+1][j  ] = '1';
        buf[i-1][j  ] = '1';
        buf[i  ][j+1] = '1';
        buf[i  ][j-1] = '1';
      } else {
        //       buf[i][j] = '0';
      }
    }
  }
  
  // スタート地点とゴール地点を設定
  // スタート地点は上の方に、ゴール地点は下の方に来るように設定
  buf[1 + (rand() % (height/2 - 1)) ][1 + (rand() % (width - 1))] = 's';
  buf[height/2 + (rand() % (height/2 - 1)) ][1 + (rand() % (width - 1))] = 'g';
  
}

////
// 迷路をファイルに書き込む
//
void saveMazeFile(char buf[][width + 2], const char* name){
  
  // ファイルポインタ
  FILE* pFile = fopen(name, "w");
  
  // ファイル書き込み
  for(int i=0; i<height; i++){
    fputs(buf[i], pFile);
  }
  fclose(pFile);
  
}
