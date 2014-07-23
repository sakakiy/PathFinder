#include <iostream>
#include <unistd.h>
#include <time.h>

using namespace std;

int ind = 0;
const int MAX = 10;
int array[MAX];

void push(int);
int  pop();
void printArray();

int main(){
  
  srand((unsigned)time(NULL));
  for(int i=0; i<MAX; i++){
    array[i] = 0;
  }
  
  for(int i=0; i<20; i++){
    if(rand()%2==0){
      push(rand()%10);
      printArray();
    } else {
      pop();
      printArray();      
    }
  }

  return 0;
}

void push(int a){
  if(ind < MAX){
    array[ind] = a;
    ind++;
  } else {
    cout << "stack full.\n";
  }
}

int pop(){
  if(0 < ind){
    ind--;
    return array[ind];
  } else {
    cout << "stack empty.\n";
    return -1;
  }

}

void printArray(){
  cout << "array : ";
  for(int i=0; i<ind; i++){
    cout << array[i] << " ";
  }
  cout << "\n";
}
