#include "lib.h"

int main(){


    //Wywolania tymczasowe
    int **board;

    createBoard(board);
    changeDefaultBoard();

    printBoard(board);

    
    freeBoard(board);

    return EXIT_SUCCESS;
}