#include "lib.h"

int defaultColumnSize = 6;
int defaultRowSize = 7;

//Funkcje

void changeDefaultBoard(void){

    printf("Domyślna liczba wierszy to 6. Podaj nową ilość wierszy:");
    scanf("%d", &defaultRowSize);
    putchar('\n');
    printf("Domyślna liczba wierszy to 7. Podaj nową ilość wierszy:");
    scanf("%d", &defaultColumnSize);
    putchar('\n');
    // Poprawić to
}

int **createBoard(int **board){

    board = (int**)malloc(defaultRowSize * sizeof(int*));
    if (board == NULL){
        perror("Error in malloc");
        exit (1);
    }
    
    int i;

    for (i = 0; i < defaultRowSize; i++){
        board[i] = (int*)malloc(defaultColumnSize * sizeof(int));
        if(board[i] == NULL){
            perror("Error in second malloc");
            exit (1);
        }
    }

    return board;
}

void printBoard(int **board){

    int i, j;

    //Na podstawie obrazka z zadania z https://www.it2051229.com/cconn4.html
    //Prawdopodobnie do zmiany
    for (i = 0; i < defaultRowSize; i++) {
            printf ("+");
            for (j = 0; j < defaultColumnSize; j++)
                printf("---+");
            printf ("\n");
            printf ("|");
            for (j = 0; j < defaultColumnSize; j++)
                printf("   |");
            printf ("\n");
        }

        printf ("+");
        for (j = 0; j < defaultColumnSize; j++)
            printf("---+");
        printf ("\n");

    // DODAĆ printowanie liczb pod kolumnami
}


void freeBoard(int **board){

    int i;

    for (i = 0; i < defaultColumnSize; i++){
            free(board[i]);
        }
    free(board);

    //NAPRAWIĆ dealokację pamięci
}