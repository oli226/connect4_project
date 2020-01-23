#include "lib.h"

int main(){


    //Wywolania tymczasowe
    
    Game game;
    
    //int **board;
    setDefaultBoard(&game);
    createBoard(&game);

    //changeDefaultBoard();


    printBoard(&game);

    
    freeBoard(&game);

    return EXIT_SUCCESS;
}