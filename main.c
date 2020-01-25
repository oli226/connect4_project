#include "lib.h"
#include "menu.h"

int main(){

    int option;
    //Wywolania tymczasowe
    
    Game game;

    option=start_menu();

    switch (option)
    {
    case 0:

        setDefaultBoard(&game);
        createBoard(&game);
        printBoard(&game);
        makeMove(&game);
        freeBoard(&game);
        break;
    
    case 1:
        setDefaultBoard(&game);
        changeDefaultBoard(&game);
        createBoard(&game);
        printBoard(&game);
        makeMove(&game);
        freeBoard(&game);
        break;
    case 2:
        //highscores();
        break;
    case 3:
        break;
    }
    


    return EXIT_SUCCESS;
}
