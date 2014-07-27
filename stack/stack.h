#include <iostream>

using namespace std;

class Stack{

  int ind;
  const int MAX;
  int * array;

 public:
  Stack(int size);
  ~Stack();
  void init();       // スタックの初期化
  void push(int);    // 要素をスタックにのせる
  int  pop();        // 要素をスタックから取り出す
  void printStack(); // スタックの状態を表示する

};
