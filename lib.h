#include <stdio.h>
#include <stdlib.h>

//Deklaracje

//Pierwsze wersje są void typ void

extern int defaultColumn;
extern int defaultRow;

//Pokaz menu
void showMenu(void);

//Zmien domyslny rozmiar planszy
void changeDefaultBoard(void);

//Utworz domyslna plansze
int **createBoard (int **board);

//Pokaz plansze 
void printBoard(int **board);

//Wrzuc krazek
void move(void);

//Sprawdzanie zwyciestwa
void checkWin(void);

void freeBoard(int **board);