#include "lib.h"

int main(){


    //Wywolania tymczasowe
    int **board;

    board = createBoard();
    //changeDefaultBoard();

    printBoard(board);

    
    freeBoard(board);

    return EXIT_SUCCESS;
}