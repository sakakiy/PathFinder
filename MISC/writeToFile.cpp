#include <iostream>

using namespace std;



int main(){

  // ファイルポインタ
  FILE* pFile;

  pFile = fopen("test.txt", "w");
  fputs("write sentence to file.\n", pFile);
  fclose(pFile);
  
  cout << "write to file.\n";

  return 0;

}
