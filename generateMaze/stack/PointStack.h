#include <iostream>

using namespace std;

struct Point{
  int x;
  int y;
};

class PointStack{

  int ind;
  const int MAX;
  Point * array;

 public:
  PointStack(int size);
  ~PointStack();
  void init();       // スタックの初期化
  void push(Point);    // 要素をスタックにのせる
  Point  pop();        // 要素をスタックから取り出す
  void printPointStack(); // スタックの状態を表示する

};
