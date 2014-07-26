#include <iostream>

using namespace std;

class Stack{

  int ind;
  const static int MAX = 10;
  int array[MAX];

 public:
  void init();       // スタックの初期化
  void push(int);    // 要素をスタックにのせる
  int  pop();        // 要素をスタックから取り出す
  void printStack(); // スタックの状態を表示する

};
