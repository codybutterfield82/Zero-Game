#include <sstream>
#include <string>
#include <iostream>
#include <time.h>
#include "TileGame.h"

using namespace std;

TileGame::TileGame(){    //Assign each item in the array to the value of the index    
  for(int i = 0; i < 10; i++){      
    tiles[i] = i;    
  }    //TODO: Mix the positions up    
  for(int i = 0; i < 10; i++){
    int po1 = rand()% 9; 
    int po2 = rand()% 9;
    swap(po1, po2);
  }
}

int TileGame::findZero(){    
  int zero;
  for(int i=0; i<10; i++){
    if(tiles[i] == 0){
      zero = i;
    }
  }    
  return zero;
}

void TileGame:: moveRight(){    
  int zero = findZero();
  int temp;
  
  temp = tiles[zero];
  tiles[zero] = tiles[zero+1];
  tiles[zero+1] = temp;

  if(zero == 9){
    return;    
  }  //TODO:  Swap the value to the left of the zero with the zero  //Use the variable zero as the index of the zero
}

void TileGame::moveLeft(){    
  int zero = findZero(); 
  int temp;

  if(zero == 0){
    return;
  }

  temp = tiles[zero];
  tiles[zero] = tiles[zero-1];
  tiles[zero-1] = temp;    //TODO:  Swap the value to the right of the zero with the zero    //Use the variable zero as the index of the zero

}

void TileGame::swap(){    
  int zero = findZero();
  int temp;

  if(zero == 9 || zero == 0) {
    return; 
  }   

  temp = tiles[zero-1];
  tiles[zero-1] = tiles[zero+1];
  tiles[zero+1] = temp;  
     //TODO:  Swap the values on Eithor Side of the 0    //Use the variable zero as the index of the zero
}

void TileGame::swap(int pos1, int pos2){    
  int temp = tiles[pos1];
  tiles[pos1] = tiles[pos2];
  tiles[pos2] = temp;
}

bool TileGame::inOrder(){    //TODO: Check to see if the game is in order.
  for(int i = 0; i < 9; i++){
      if(tiles[i] != i){
          return false;
      }
    }
  return true;      
}//Returns the game as a string for display 

string TileGame::getDisplay(){
  stringstream output;  
  for(int i = 0; i < 10; i++){    
    if(tiles[i]>0)      
    output << "[" << tiles[i] << "]" << " ";    
    else output << "[ ]" << " ";  
  }  
  return output.str();
}