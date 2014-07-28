#include <iostream>
#include <unistd.h>
#include <time.h>

#include "stack/PointStack.h"

using namespace std;

// int ind = 0;
// const int MAX = 10;
// int array[MAX];

PointStack stack(15);

int main(){
  // 乱数初期化
  srand((unsigned)time(NULL));
  
  for(int i=0; i<20; i++){
    if(rand()%2==0){
      stack.push(rand()%10);
      stack.printPointStack();
    } else {
      stack.pop();
      stack.printPointStack();      
    }
  }

  return 0;
}
