#include "lib.h"

int defaultColumn = 7; //ilość el w wierzu => kolumny
int defaultRow = 6; // ilość el w kolumnie => wiersze

//Funkcje

void changeDefaultBoard(void){

    printf("Domyślna liczba kolumn to 7. Podaj nową ilość kolumn:");
    scanf("%d", &defaultColumn);
    putchar('\n');
    printf("Domyślna liczba wierszy to 6. Podaj nową ilość wierszy:");
    scanf("%d", &defaultRow);
    putchar('\n');
}

int **createBoard(int **board){

    board = (int**)malloc(defaultColumn * sizeof(int*));
    if (board == NULL){
        perror("Error in malloc");
        exit (1);
    }
    
    int i;

    for (i = 0; i < defaultColumn; i++){
        board[i] = (int*)malloc(defaultRow * sizeof(int));
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
    for (i = 0; i < defaultRow; i++) {
            printf ("+");
            for (j = 0; j < defaultColumn; j++)
                printf("---+");
            printf ("\n");
            printf ("|");
            for (j = 0; j < defaultColumn; j++)
                printf("   |");
            printf ("\n");
        }

        printf ("+");
        for (j = 0; j < defaultColumn; j++)
            printf("---+");
        printf ("\n");

    // DODAĆ printowanie liczb pod kolumnami
}


void freeBoard(int **board){

    int i;

    for (i = 0; i < defaultRow; i++){
            free(board[i]);
        }
    free(board);

    //NAPRAWIĆ dealokację pamięci
}