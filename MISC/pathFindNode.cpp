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
void move(Node *, int, int); 


int main(int argc, char *argv[]){
  if(argc != 2){
    cout << "specify the MAP file name.\n";
    exit(0);
  }
  // マップファイルを読み込む
  fileRead(argv[1]);

  // マップを表示する
  printMap();

  // 開始点のノードを作る
  Node sNode;
  sNode.p.x = start.x;
  sNode.p.y = start.y;

  move(&sNode, start.x, start.y);

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

// 潜っていく
void move(Node* node, int px, int py){
  // cout << "node.p.x : " << node->p.x << "\n";
  // cout << "node.p.y : " << node->p.y << "\n";
  int x = node->p.x;
  int y = node->p.y;
  printf("node x : %d, y : %d\n", x, y);


  for(int i=0; i<4; i++){
    int tx = 0, ty = 0;
    switch(i){
    case 0:
      tx = x - 1;
      ty = y;
      if(tx < 0 || tx == px)continue;
      break;

    case 1:
      tx = x + 1;
      ty = y;
      if(row == tx || tx == px)continue;
      break;

    case 2:
      tx = x;
      ty = ty - 1;
      if(ty < 0 || ty == py)continue;
      break;

    case 3:
      tx = x;
      ty = ty + 1;
      if(column == ty || ty == py)continue;
      break;
    }
    
    //ここにいれる
  
    if(buffer[tx][ty] != '0'){
      Node n;
      n.p.x = tx;
      n.p.y = ty;
      node->next[i] = &n;
      
      if(buffer[tx][ty] == 'g'){
        cout << "GOAL : " << n.p.x << " " << n.p.y << "\n";
      } else {
        move(node->next[i], x, y);
      }
      
    } else {
      node->next[i] = NULL;
      cout << "NULL\n";
    }

  }

    
  /* 
  if(0 <= x-1 && buffer[x-1][y] == '1'){
    Node n;
    n.p.x = x-1;
    n.p.y = y;
    node->next[0] = &n;
      
    move(node->next[0]);
  } else {
    node->next[0] = NULL;
    cout << "NULL\n";
  }
  */
  
  /*
  
  if(x+1 < row && buffer[y][x+1] != '0'){
    Node n;
    n.p.x = x+1;
    n.p.y = y;
    node->next[1] = &n;
    
    if(buffer[y][x+1] == 'g'){
      cout << "GOAL : " << n.p.x << " " << n.p.y << "\n";
    } else {
      move(node->next[1]);
    }
    
  } else {
    node->next[1] = NULL;
    cout << "NULL\n";
    }
  */

  /*
  if(0 <= y-1 && buffer[x][y-1] == '1'){
    Node n;
    n.p.x = x;
    n.p.y = y-1;
    node->next[2] = &n;
      
    move(node->next[2]);
  } else {
    node->next[2] = NULL;
    cout << "NULL\n";
    }
  */
  
  /*
  if(y+1 < column && buffer[y+1][x] != '0'){
    Node n;
    n.p.x = x;
    n.p.y = y+1;
    node->next[3] = &n;
    
    if(buffer[y+1][x] == 'g'){
      cout << "GOAL : " << n.p.x << " " << n.p.y << "\n";
    } else {
      move(node->next[3]);
    }
    
  } else {
    node->next[3] = NULL;
    cout << "NULL\n";
  }
  */  
  
  
}
