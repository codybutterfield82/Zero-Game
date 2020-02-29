#ifndef TILEGAME_H
#define TILEGAME_H
#include <string>

using namespace std;

class TileGame{
  public:     
    TileGame();     
    void moveRight();     
    void moveLeft();     
    void swap(); //swaps values on either side of 0
    void swap(int, int); //lets you specify which 2 pos to swap    
    bool inOrder();     
    string getDisplay();  
  private:     
    int tiles[10];     
    int findZero();
};

#endif