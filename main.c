#include "lib.h"
#include "menu.h"

int main(){


    //Wywolania tymczasowe
    
    Game game;

    //start_menu();
    setDefaultBoard(&game);
    changeDefaultBoard(&game);
    createBoard(&game);

    printBoard(&game);

    makeMove(&game);


    freeBoard(&game);

    return EXIT_SUCCESS;
}
