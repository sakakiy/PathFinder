#include <iostream>
#include <unistd.h>
#include <time.h>

#include "stack/stack.h"

using namespace std;

// int ind = 0;
// const int MAX = 10;
// int array[MAX];

Stack stack(15);

int main(){
  // 乱数初期化
  srand((unsigned)time(NULL));
  
  for(int i=0; i<20; i++){
    if(rand()%2==0){
      stack.push(rand()%10);
      stack.printStack();
    } else {
      stack.pop();
      stack.printStack();      
    }
  }

  return 0;
}
