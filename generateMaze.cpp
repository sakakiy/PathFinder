#include <iostream>

using namespace std;

const int width  = 15;
const int height = 20;
char buffer[height][width + 2];

void saveMazeFile(char buf[][width + 2], const char* name);

int main(int argc, char* argv[]){
  
  // バッファの初期化
  for(int i=0; i<height; i++){
    for(int j=0; j<width; j++){
      buffer[i][j] = '0';
    }
    
    // ヌル文字と改行を文末につける
    buffer[i][width] = '\n';
    buffer[i][width + 1] = '\0';
  }
  
  // 確認、改行コードを含んでいるので表示の際に開業しない
  for(int i=0; i<height; i++){
    printf("%3d : %s", i, buffer[i]);
  }
  
  // ランダムで何か入れる（予定）
  for(int i=0; i<height; i++){
    for(int j=0; j<width; j++){
      buffer[i][j] = '0';
    }
  }
  
  saveMazeFile(buffer, "maze.txt");
}

// 迷路をファイルに書き込む
void saveMazeFile(char buf[][width + 2], const char* name){
  // ファイルポインタ
  FILE* pFile = fopen(name, "w");
  
  // ファイル書き込み
  for(int i=0; i<height; i++){
    fputs(buffer[i], pFile);
  }
  fclose(pFile);
  
}
