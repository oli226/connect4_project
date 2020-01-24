#include <stdio.h>
#include <stdlib.h>

//Deklaracje

//Pierwsze wersje są void typ void
typedef struct Game {

int **board;
int columns;
int rows;
int player;

}Game;

enum Players {Player1 = 1, Player2 = 2};

//Pokaz menu
void showMenu(void);

//Nadaj domyslne parametry
void setDefaultBoard(Game *game);

//Zmien domyslny rozmiar planszy
//void changeDefaultBoard(void);

//Utworz domyslna plansze
void createBoard (Game *game);

//Pokaz plansze 
void printBoard(Game *game);

//Wrzuc krazek
void move(void);

//Zmiana gracza
void switchPlayers(Game *game);

//Sprawdzanie zwyciestwa
void checkWin(void);

void freeBoard(Game *game);