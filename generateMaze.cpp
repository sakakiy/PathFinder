#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
  
  int width  = 15;
  int height = 20;
  char buffer[height][width + 1];
  
  // バッファの初期化
  for(int i=0; i<height; i++){
    for(int j=0; j<width; j++){
      buffer[i][j] = '0';
    }

    // ヌル文字を文末につける
    buffer[i][width] = '\0';
  }


  // 確認
  for(int i=0; i<height; i++){
    printf("%3d : %s\n", i, buffer[i]);
  }


  FILE* pFile = fopen("maze.txt", "a");

  // ランダムで何か入れる
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
