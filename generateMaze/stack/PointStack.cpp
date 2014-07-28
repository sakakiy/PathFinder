#include "PointStack.h"

using namespace std;

// コンストラクタで MAX のコンストラクタを呼びを初期化する
PointStack::PointStack(int size) : MAX(size){
  cout << "constructor\n";
  //  MAX = size;
  array = new int[MAX];
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
    array[i] = 0;
  }
  
  cout << "PointStack init.\n";
}

// 要素をスタックにのせる
void PointStack::push(int a){
  if(ind < MAX){
    array[ind] = a;
    ind++;
  } else {
    cout << "stack full.\n";
  }

}

// 要素をスタックから取り出す
int PointStack::pop(){
  if(0 < ind){
    ind--;
    return array[ind];
  } else {
    cout << "stack empty.\n";
    return -1;
  }
}


// スタックの状態を表示する
void PointStack::printPointStack(){
  cout << "array : ";
  for(int i=0; i<ind; i++){
    cout << array[i] << " ";
  }
  cout << "\n";
}
