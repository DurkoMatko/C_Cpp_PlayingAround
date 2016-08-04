#include <ncurses.h>
#include <pthread.h>
#include <iostream>
#include <unistd.h>

#define KB_ESCAPE 27
#define KB_RIGHT 67
#define KB_LEFT 68
#define KB_UP 65
#define KB_DOWN 66

using namespace std;

int kbhit(void)
{
    int ch = getch();

    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}

typedef struct tdata {
    char (*C)[8][8];
} tdata;

void *threadproc(void *arg)
{
   int c=0;
   tdata *data=arg;
    while(c<8)
    {
        sleep(2);
        mvaddch(10, 10, data->C[c][c]);
	c++;
    }
    return NULL;
}
int main() {

	//////////INIT////////////////////////////
	int KB_val=0;

	int xpos=0,ypos=0;
	char board[8][8];
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			board[i][j]='.';
		}
	}
	board[7][7]='G';
	board[6][6]='T';
	board[5][7]='T';
	board[4][5]='T';
	board[0][0]='P';



	///////////DRAW////////////////////////////
	initscr();
	raw();
	keypad(stdscr, TRUE);

	pthread_t threadHandle;
	tdata argument = { .C = &board};
	pthread_create(&threadHandle, NULL, &threadproc, &argument);

	while(KB_val!=KB_ESCAPE && board[7][7]!='P'){
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				mvaddch(i, j, board[i][j]);
			}
		}
		refresh();
		if (kbhit()) {
		    KB_val=getch();
		    board[ypos][xpos]='.';
		    switch(KB_val){
			case KEY_UP:
				ypos-=1;
				break;
			case KEY_DOWN:
				ypos+=1;
				break;
			case KEY_LEFT:
				xpos-=1;
				break;
			case KEY_RIGHT:
				xpos+=1;
				break;
		   }
		   if(board[ypos][xpos]=='T'){
			//mvaddch(10,10,'U');
			mvprintw(8,0,"You've fallen!");
			break;
		   }
                   else if(board[ypos][xpos]=='G'){
			mvprintw(8,0,"You've won!");
		   }
		   else{
		   	board[ypos][xpos]='P';
		   }
	      }
	}

	pthread_join(threadHandle, NULL);
	refresh();
	getch();
	endwin();
	return(0);
}
