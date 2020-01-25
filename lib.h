#include <stdio.h>
#include <stdlib.h>

//Deklaracje

//Pierwsze wersje są void typ void
typedef struct Game {

int **board;
int columns;
int rows;

}Game;

//Pokaz menu
void showMenu(void);

//Nadaj domyslne parametry
void setDefaultBoard(Game *game);

//Zmien domyslny rozmiar planszy
void changeDefaultBoard(Game *game);

//Utworz domyslna plansze
void createBoard (Game *game);

//Pokaz plansze 
void printBoard(Game *game);

//Wrzuc krazek
void makeMove(Game *game);

//Zmiana gracza
void switchPlayers(Game *game);

//Sprawdzanie zwyciestwa
void checkWin(void);

//zapisuje backup kolumn i wierszy planszy;
void getBackup(Game *game, Game *backup);

//zapisuje plansze do backupu
void setBackup(Game *game, Game *backup);

//przywraca backup gry
void restoreBackup(Game *game, Game *backup);

//uwolnienie pamieci
void freeBoard(Game *game);


