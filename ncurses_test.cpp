/***********************************************************************//**
@file

Tests the different clocks available on the system

@author Thierry Guichon
@date 2015
@copyright ORBCOMM

***************************************************************************/



#include <stdlib.h>
#include <curses.h>
#include <signal.h>

static void finish(int sig);
  WINDOW *field;
  WINDOW *score;

  
void draw_borders(WINDOW *screen) {
  int x, y, i;
  getmaxyx(screen, y, x);
  // 4 corners
  mvwprintw(screen, 0, 0, "+");
  mvwprintw(screen, y - 1, 0, "+");
  mvwprintw(screen, 0, x - 1, "+");
  mvwprintw(screen, y - 1, x - 1, "+");
  // sides
  for (i = 1; i < (y - 1); i++) {
    mvwprintw(screen, i, 0, "|");
    mvwprintw(screen, i, x - 1, "|");
  }
  // top and bottom
  for (i = 1; i < (x - 1); i++) {
    mvwprintw(screen, 0, i, "-");
    mvwprintw(screen, y - 1, i, "-");
  }
}  
  
  
  
int
main(int argc, char *argv[])
{
    int num = 0;
 int parent_x, parent_y;
  int score_size = 3;
    /* initialize your non-curses data structures here */

    (void) signal(SIGINT, finish);      /* arrange interrupts to terminate */

    (void) initscr();      /* initialize the curses library */
    keypad(stdscr, TRUE);  /* enable keyboard mapping */
    (void) nonl();         /* tell curses not to do NL->CR/NL on output */
    (void) cbreak();       /* take input chars one at a time, no wait for \n */
    //(void) echo();         /* echo input - in color */
	  noecho();
	  
	  
  curs_set(FALSE);
  // get our maximum window dimensions
  getmaxyx(stdscr, parent_y, parent_x);
  // set up initial windows
  field = newwin(parent_y - score_size, parent_x, 0, 0);
  score = newwin(score_size, parent_x, parent_y - score_size, 0);
  

    if (has_colors())
    {
        start_color();

        /*
         * Simple color assignment, often all we need.  Color pair 0 cannot
         * be redefined.  This example uses the same value for the color
         * pair as for the foreground color, though of course that is not
         * necessary:
         */
        init_pair(1, COLOR_RED,     COLOR_BLACK);
        init_pair(2, COLOR_GREEN,   COLOR_BLACK);
        init_pair(3, COLOR_YELLOW,  COLOR_BLACK);
        init_pair(4, COLOR_BLUE,    COLOR_BLACK);
        init_pair(5, COLOR_CYAN,    COLOR_BLACK);
        init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(7, COLOR_WHITE,   COLOR_BLACK);
    }

 
  // draw our borders
  draw_borders(field);
  draw_borders(score);
  // simulate the game loop

    // draw to our windows
    mvwprintw(field, 1, 1, "Field");
    mvwprintw(score, 1, 1, "Score");
    // refresh each window
    wrefresh(field);
    wrefresh(score);

  
	
    for (;;)
    {
        int c = getch();     /* refresh, accept single keystroke of input */
        attrset(COLOR_PAIR(num % 8));
        num++;

        /* process the command keystroke */
    }

    finish(0);               /* we're done */
}

static void finish(int sig)
{
	
	delwin(field);
	delwin(score);
    endwin();

    /* do your non-curses wrapup here */

    exit(0);
}

