#include "lib.h"

Game backup;

//Funkcje
void setDefaultBoard(Game *game){
    game->columns = 7;
    game->rows = 6;
}

void changeDefaultBoard(Game *game){
    //char next;

    printf("Default (minimal) values of columns is 7 and maximum 12. Enter new amount of columns: ");

    /* //check, errors
	while(1){
        if (scanf("%d", &game->columns) == 7 || (game->columns < 7 && game->columns > 12) || (( next = getchar()) != EOF && next != '\n')) { 
                clearerr(stdin);
                do
                    next = getchar();
                while (next != EOF && next != '\n'); 
                clearerr(stdin);
                printf("Wrong value. Please enter number of columns again: ");
            } else {
                break;
        }
    } */

     do{
    scanf("%d", &game->columns);
    if (game->columns < 7 || game->columns > 12){
        printf("Wrong value. Please enter number of columns again: ");
        }
    }while (game->columns < 7 || game->columns > 12);

    putchar('\n');
    printf("Default (minimal) value of rows is 6 and maximum 12. Enter new amount of rows: ");



    /* //check, errors
	while(1){
        if (scanf("%d", &game->rows) < 0 || (game->rows < 6 && game->rows > 12) || (( next = getchar()) != EOF && next != '\n')) { 
                clearerr(stdin);
                do
                    next = getchar();
                while (next != EOF && next != '\n'); 
                clearerr(stdin);
                printf("Wrong value. Please enter number of rows again: ");
            } 
            else {
                break;
        }
    } */

    do{
        scanf("%d", &game->rows);
        if (game->rows < 6 || game->rows > 12){
            printf("Wrong value. Please enter number of rows again: ");
        }
    }while (game->rows < 6 || game->rows > 12);

    putchar('\n');
}

void getBackup(Game *game, Game *backup){
    backup->columns = game->columns;
    backup->rows = game->rows;
}

void setBackup(Game *game, Game *backup){

    int i, j;

    for (i = 0; i < game->rows; i++) {
        for (j = 0; j < game->columns; j++){
            backup->board[i][j] = game->board[i][j];
        }
    }
}

void restoreBackup(Game *game, Game *backup){

    int i, j;

    for (i = 0; i < backup->rows; i++) {
        for (j = 0; j < backup->columns; j++){
            game->board[i][j] = backup->board[i][j];
        }
    }
}


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
            else if(game->board[i][j]==1){
            printf("\033[0;32m"); 
            printf(" O "); 
            printf("\033[0m");
            printf("|");
            }
            else if(game->board[i][j]==2){
            printf("\033[0;31m"); 
            printf(" O "); 
            printf("\033[0m");
            printf("|");
            }
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
    int countRowsP1=0;
    int countRowsP2=0;

    int rows=game->rows-1;
    int columns=game->columns-1;

    int win;

    //sprawdzanie poziome
    for(rows=game->rows-1; 0<=rows; rows--){                     
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
            countColumnsP1=0;
            countColumnsP2=0;
    }    
    //sprawdzanie pionowe
    for(int i=0; i<=columns; i++){                    
        for(rows=game->rows-1; 0<=rows; rows--){
            if(game->board[rows][i]==1)
            countRowsP1++;
            else
            countRowsP1=0;
            if(countRowsP1==4){
                    win=1;
                    break;
            }

            if(game->board[rows][i]==2)
            countRowsP2++;
            else
            countRowsP2=0;
                if(countRowsP2==4){
                    win=2;
                    break;
                }

        }
        countRowsP1=0;
        countRowsP2=0;
        if(win==1||win==2)
        break;
    }//sprawdzanie poziome
    for(rows=game->rows-1; 0<=rows; rows--){                     
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
            countColumnsP1=0;
            countColumnsP2=0;
    }    
    //sprawdzanie pionowe
    for(int i=0; i<=columns; i++){                    
        for(rows=game->rows-1; 0<=rows; rows--){
            if(game->board[rows][i]==1)
            countRowsP1++;
            else
            countRowsP1=0;
            if(countRowsP1==4){
                    win=1;
                    break;
            }

            if(game->board[rows][i]==2)
            countRowsP2++;
            else
            countRowsP2=0;
                if(countRowsP2==4){
                    win=2;
                    break;
                }

        }
        countRowsP1=0;
        countRowsP2=0;
        if(win==1||win==2)
        break;
    }



    
    //sprawdz ukosy od gory od lewej do prawej
    for (rows = 0; rows < game->rows - 3; rows++ ){
        for (columns = 0; columns < game->columns - 3; columns++){
            int checkedElement = game->board[rows][columns];
            if((checkedElement == game->board[rows+1][columns+1] && checkedElement == game->board[rows+2][columns+2] && checkedElement == game->board[rows+3][columns+3])){
                if (checkedElement == 1){
                    win = 1;
                    break;
                }
                else if (checkedElement == 2){
                    win = 2;
                    break;
                }
            }
        }
    }

    //sprawdz ukosy od gory od prawej do lewej
    
    for (rows = 0; rows < game->rows - 3; rows++ ){
        for (columns = 3; columns < game->columns; columns++){
            int checkedElement = game->board[rows][columns];
            if((checkedElement == game->board[rows+1][columns-1] && checkedElement == game->board[rows+2][columns-2] && checkedElement == game->board[rows+3][columns-3])){
                if (checkedElement == 1){
                    win = 1;
                    break;
                }
                else if (checkedElement == 2){
                    win = 2;
                    break;
                }
            }
        }
    }


    return win;
}

void makeMove(Game *game){
    int chooseColumn;
    int player=1;
    int count=game->columns*game->rows;
    int win;
    int lastMove = 0;

    getBackup(game, &backup);
    createBoard(&backup);

    while(1){
        int checkRow=game->rows-1; 
        int msg=0;
        char next;

        if(player==1){
            printf("\nPlayer 1 turn. Choose number: ");
            printf("\nType -1 to undo last players move.");
        }
        else{
            printf("\nPlayer 2 turn. Choose number: ");
            printf("\nType -1 to undo last players move.");
        }

        printf("\nChoose number: ");

        /*while(1){
            if (scanf("%d", &chooseColumn) < 0 || (( next = getchar()) != EOF && next != '\n')) { 
                    clearerr(stdin);
                    do
                        next = getchar();
                    while (next != EOF && next != '\n'); 
                    clearerr(stdin);
                    printf("Wrong value. Please enter again: ");
                } 
                else {
                    break;
            }
        }*/

        scanf("%d",&chooseColumn);



        while(game->columns<chooseColumn || chooseColumn<=0){
            if (chooseColumn == -1 && lastMove != -1){
                restoreBackup(game, &backup);
                break;
            }

             printf("\nWrong number! Try again: ");

            /*while(1){
                if (scanf("%d", &chooseColumn) < 0 || (( next = getchar()) != EOF && next != '\n')) { 
                        clearerr(stdin);
                        do
                            next = getchar();
                        while (next != EOF && next != '\n'); 
                        clearerr(stdin);
                        printf("Wrong value. Please enter again: ");
                    } 
                    else {
                        break;
                }
            }*/
             scanf("%d",&chooseColumn);

        }
        
        setBackup(game, &backup);

        if (chooseColumn == -1){

            if(count == game->columns*game->rows){
                printf("\nCan not undo first move. Sorry :p\n");
            }
            else{
                printBoard(game);
                count++;

                if(player==1)
                    player=2;
                else
                    player--;
            }
            lastMove = chooseColumn;
            continue;
        }

        lastMove = chooseColumn;

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


