#include "lib.h"

//Funkcje
void setDefaultBoard(Game *game){
    game->columns = 7;
    game->rows = 6;
}

/*void changeDefaultBoard(void){

    printf("Domyślna liczba kolumn to 7. Podaj nową ilość kolumn:");
    scanf("%d", &defaultColumn);
    putchar('\n');
    printf("Domyślna liczba wierszy to 6. Podaj nową ilość wierszy:");
    scanf("%d", &defaultRow);
    putchar('\n');
}*/

void createBoard (Game *game){

    game->board= (int**)malloc(game->rows * sizeof(int*));
    if (game->board == NULL){
        perror("Error in malloc");
        exit (1);
    }
    
    int i;

    for (i = 0; i < game->rows; i++){
        game->board[i] = (int*)malloc(game->columns * sizeof(int));
        if(game->board[i] == NULL){
            perror("Error in second malloc");
            exit (1);
        }
    }
}

void printBoard(Game *game){

    int i, j;

    //Na podstawie obrazka z zadania z https://www.it2051229.com/cconn4.html
    for (j = 0; j < game->columns; j++){
            printf(" %d  ", j+1);
        }

    printf ("\n");

    for (i = 0; i < game->rows; i++) {
        printf ("+");
        for (j = 0; j < game->columns; j++){
            printf("---+");
        }
        printf ("\n");
        printf ("|");
        for (j = 0; j < game->columns; j++){
            if(game->board[i][j]==0)
                printf("   |");
            else 
            printf(" %d |", game->board[i][j]);
        }
        printf ("\n");
    }

    printf ("+");
    for (j = 0; j < game->columns; j++){
        printf("---+");
    }

    printf ("\n");
    
}

void freeBoard(Game *game){

    //naprawić dealokację

    int i;

    for (i = 0; i < game->rows; i++){
            free(game->board[i]);
        }
    free(game->board);
    free(game);
}

void move(Game *game){
    int chooseColumn;
    int player=1;
    while(1){
    int checkRow=game->rows-1; 
    int msg=0;
    printf("\nChoose number: ");
    scanf("%d",&chooseColumn);
    while(game->columns<chooseColumn && chooseColumn>0){
        printf("\nWrong number! Try again: %d",game->columns);
        scanf("%d",&chooseColumn);
    }
    while(game->board[checkRow][chooseColumn-1]==1||game->board[checkRow][chooseColumn-1]==2){
        if(checkRow==0){
            msg=1;
            break;
        }
        checkRow--;
        
    }
    game->board[checkRow][chooseColumn-1]=player;
    printBoard(game);
    if(msg==1)
    printf("\nThis column is full, sorry! Choose another one. :)\n");
    if(player==1)
        player=2;
    else
        player--;
    }
    
}

