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

int checkColumns(Game *game){
    int countColumnsP1=0;
    int countColumnsP2=0;
    int rows=game->rows-1;
    int columns=game->columns-1;
    
    int win;
    for(rows; 0<=rows; rows--){                     //zle, rows od dolu pownnio byc><
        for(int i=0; i<=columns; i++){
            if(game->board[rows][i]==1)
            countColumnsP1++;
            else
            countColumnsP1=0;
                if(countColumnsP1==4){
                    win=1;
                    break;
                }
                
            if(game->board[rows][i]==2)
            countColumnsP2++;
            else
            countColumnsP2=0;
                if(countColumnsP2==4){
                    win=2;
                    break;
                }    
            
        }
        // if(game->board[rows][0]==1)
        //     countColumnsP1++;
        //         if(countColumnsP1==4){
        //             win=1;
        //             break;
        //         }
        if(win==1||win==2)
        break;
    }
    return win;
}

void move(Game *game){
    int chooseColumn;
    int player=1;
    int count=game->columns*game->rows;
    int win;

    while(1){
        int checkRow=game->rows-1; 
        int msg=0;
        printf("\nChoose number: ");
        scanf("%d",&chooseColumn);
        while(game->columns<chooseColumn || chooseColumn<=0){
             printf("\nWrong number! Try again: ");
             scanf("%d",&chooseColumn);
         }
        while(game->board[checkRow][chooseColumn-1]==1||game->board[checkRow][chooseColumn-1]==2){
            if(checkRow==0){
                msg=1;
                break;
            }
            checkRow--;
        
        }
        if(msg==1){
            printBoard(game);
            printf("\nThis column is full, sorry! Choose another one. :)\n");
        }
        else{
            game->board[checkRow][chooseColumn-1]=player;
            printBoard(game);
            count--;
            if(player==1) 
            player=2;
            else
            player--;
        }
    
        
    
    
        if(count==0){
            printf("===========================\nIt seems that we got draw!\n===========================\n");
            break;
        }
        win=checkColumns(game);
        if(win==1){
            printf("\nPLAYER 1 WON!!!!!\n\n\n");
            break;
        }
        else if(win==2){
            printf("\nPLAYER 2 WON!!!!!\n\n\n");
            break;
        }
    }
    
    
}

