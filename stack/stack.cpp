#include <stack.h>

using namespace std;


// スタックの初期化
void Stack::init(){
  cout << "Stack init.\n";
}

// 要素をスタックにのせる
void Stack::push(int){
  if(ind < MAX){
    array[ind] = a;
    ind++;
  } else {
    cout << "stack full.\n";
  }

}

// 要素をスタックから取り出す
int Stack::pop(){
  if(0 < ind){
    ind--;
    return array[ind];
  } else {
    cout << "stack empty.\n";
    return -1;
  }
}


// スタックの状態を表示する
void Stack::printStack(){
  cout << "array : ";
  for(int i=0; i<ind; i++){
    cout << array[i] << " ";
  }
  cout << "\n";
}
