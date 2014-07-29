#include "PointStack.h"

using namespace std;

// コンストラクタで MAX のコンストラクタを呼びを初期化する
PointStack::PointStack(int size) : MAX(size){
  cout << "constructor\n";
  //  MAX = size;
  array = new Point[MAX];
  init();
}

PointStack::~PointStack(){
  cout << "destructor\n";
  delete[] array;
}

// スタックの初期化
void PointStack::init(){

  // スタックの地点を指す変数を初期化
  ind = 0;

  // スタック配列を初期化
  for(int i=0; i<MAX; i++){
    Point p = {0, 0};
    array[i] = p;
  }
  
  cout << "PointStack init.\n";
}

// 要素をスタックにのせる
void PointStack::push(Point a){
  if(ind < MAX){
    array[ind] = a;
    ind++;
  } else {
    cout << "stack full.\n";
  }

}

// 要素をスタックから取り出す
Point PointStack::pop(){
  if(0 < ind){
    ind--;
    return array[ind];
  } else {
    cout << "stack empty.\n";
    Point p = {-1, -1};
    return p;
  }
}


// スタックの状態を表示する
void PointStack::printPointStack(){
  cout << "array : ";
  for(int i=0; i<ind; i++){
    //cout << array[i].x << " ";
    printf("(%2d,%2d) ", array[i].x, array[i].y);
  }
  cout << "\n";
}
