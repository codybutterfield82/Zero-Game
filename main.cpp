#include <iostream>
#include "TileGame.h"

using namespace std;

enum{QUIT, RIGHT, LEFT, SWAP };

int getChoice();
void displayWinner();
int main(){ 
  srand(time(NULL));
  cout << "Tile Game";  
  TileGame game;  
  
  int choice;  
  int chances = 0;  
  do{    
    cout << endl << game.getDisplay() << endl;    
    choice = getChoice();    
    switch (choice){
      case RIGHT: game.moveRight();        
        break;      
      case LEFT: game.moveLeft(); 
        break;      
      case SWAP: game.swap();        
        break;    
      }    
      
    chances ++;  
  } while (!game.inOrder() && choice > 0 && chances < 50);  
  
  if(game.inOrder()){    
    displayWinner();  
  } else {    
    cout << "Better Luck Next Time";  
  }
}
//Get Choice returns a the users choice
int getChoice(){
  int choice;    
  cout << "1. Shift Right\n2. Shift Left\n3. Swap\nChoose one: ";    cin >> choice;    
  return choice;
}

void displayWinner(){   
  cout << "\n****************************************\n";    
  cout << "     YOU WIN!!\n";    
  cout << "\n****************************************\n";
}