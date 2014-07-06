#include <iostream>

using namespace std;

// 座標を表す構造体
struct Point{
  int x;
  int y;
};

struct Node{
  Point p;
  Node *next[4];
};

char buffer[10][128]; // ファイル読み込みバッファ
int  column      = 0; // 列数
int  row         = 0; // 行数

Point start, goal;

void fileRead(const char* name);
void printMap();


int main(int argc, char *argv[]){
  if(argc != 2){
    cout << "specify the MAP file name.\n";
    exit(0);
  }
  // マップファイルを読み込む
  fileRead(argv[1]);

  // マップを表示する
  printMap();

  return 0;
}

// ファイルからマップを読み込み、行列数を格納する
void fileRead(const char* name){

  // ファイルポインタ
  FILE* pFile = fopen(name, "r");
  
  int index = 0;
  while( fgets(buffer[index], 128, pFile) != NULL){
    // 文字列の長さから列数を決定
    column = string(buffer[0]).length() - 1;

    // スタートやゴールのいちを覚えておく
    for(int i=0; i<column; i++){
      switch(buffer[index][i]){
      case 's':
        start.x = i;
        start.y = index;
        break;
        
      case 'g':
        goal.x = i;
        goal.y = index;
        break;

      default:
        break;
       }
    }
    
    index++;
  }

  // 行数を決定
  row = index;

  printf("column     : %d\nrow        : %d\n", column, row);
  printf("< start > x:%2d, y:%2d\n", start.x, start.y);
  printf("< goal  > x:%2d, y:%2d\n", goal.x, goal.y);  
  
  cout << "file read.\n";

  fclose(pFile);
}

// マップを表示する
void printMap(){
  
  for(int i=0; i<row; i++){
    printf("%s", buffer[i]);
  }
  
}
