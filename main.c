#include "lib.h"

int main(){


    //Wywolania tymczasowe
    
    Game game;

    setDefaultBoard(&game);
    createBoard(&game);

    printBoard(&game);

    
    freeBoard(&game);

    return EXIT_SUCCESS;
}