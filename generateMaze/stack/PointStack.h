#include <iostream>

using namespace std;

struct Point{
  int x;
  int y;
};

class PointStack{

  int ind;
  const int MAX;
  int * array;

 public:
  PointStack(int size);
  ~PointStack();
  void init();       // スタックの初期化
  void push(int);    // 要素をスタックにのせる
  int  pop();        // 要素をスタックから取り出す
  void printPointStack(); // スタックの状態を表示する

};
