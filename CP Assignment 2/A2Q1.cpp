#include <iostream>
using namespace std;


int find(int array[], int length, int target);

int main() {

  int b[] = {5,6,8,4,5,7,3,2,7};
  cout << find(b,9,4);

return 0;    
}

int find(int array[], int length, int target){

  if (array[length - 1] == target){
    
    return length - 1;
    
  }
  
  else if (length == 0){
    
    return -1;
    
  }

  else{
    
    find(array, length - 1, target);
    
  }
    
}    