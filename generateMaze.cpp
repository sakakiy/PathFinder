#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
  
  int width  = 15;
  int height = 20;
  char buffer[height][width + 2];
  
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

  FILE* pFile = fopen("maze.txt", "w");

  // ランダムで何か入れる（予定）
  for(int i=0; i<height; i++){
    for(int j=0; j<width; j++){
      buffer[i][j] = '0';
    }
  }
  for(int i=0; i<height; i++){
    fputs(buffer[i], pFile);
  }
  fclose(pFile);

}
