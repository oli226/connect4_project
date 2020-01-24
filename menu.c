
#include "menu.h"

int start_menu(){

    char gamename[]="Connect 4";
    int szer, dlug; //wartosci dlugosci i szerokosci terminalu

    initscr(); //Inizjalizacja  ncurses
    raw();
    noecho(); //nie wyswietla inputu usera
    keypad(stdscr, TRUE);


    getmaxyx(stdscr, szer, dlug); //pobranie rozmiarów terminalu
    move(szer/2, (dlug-strlen(gamename))/2); //kursor na srodku, zeby powitanie bylo w centrum
    printw(gamename); //nazwa gry
    WINDOW * menuwin=newwin(7, dlug-12, szer-9, 6); //tworzymy okno
    box(menuwin, 0, 0);
    refresh();//odswiezamy, zeby zobaczyc to co zrobilismy -> tytul gry i boxa
    wrefresh(menuwin);//odświeżamy samo okno
    keypad(menuwin, TRUE);//odpalamy dzialanie klawiatury w oknie

    char *opcje[] = {
        "New game",
        "High Score",
        "Options",
        "Exit",
    };
    int wybor;
    int zaznacz=0;

    while(1)
    {
        for(int i = 0; i < 4; i++) {
            if(i == zaznacz)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i+1, 1, opcje[i]);
            if (i == zaznacz)
                wattroff(menuwin, A_REVERSE);
        }

        wybor = wgetch(menuwin);
        switch(wybor)
        {
        case KEY_UP:
            zaznacz--;
            if(zaznacz < 0) zaznacz = 0;
            break;
        case KEY_DOWN:
            zaznacz++;
            if(zaznacz > 3) zaznacz = 3;
            break;
        default:
            break;
        }

        if(wybor==10) break;
    }

    printw("\nWybrano: %s", opcje[zaznacz]);
    refresh();

    getch();

    endwin();

    return zaznacz;

}

