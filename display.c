#include <stdio.h>
#include <ncurses.h>
#include <unistd.h> //for usleep

#define OFF 1
#define ON 2
#define TEXT 3

void displayPixels(uint16_t pixels[8][8], int xoffset, int yoffset);

static uint16_t pixels_m[8][8] = {
      {0,0,0,0,0,0,0,0},
      {0,1,1,0,0,1,1,0},
      {0,1,0,1,1,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,0,0,0,0,0,0,0}
};

 static uint16_t pixels_i[8][8] = {
      {0,0,0,0,0,0,0,0},
      {0,1,1,1,1,1,1,0},
      {0,0,0,1,0,0,0,0},
      {0,0,0,1,0,0,0,0},
      {0,0,0,1,0,0,0,0},
      {0,0,0,1,0,0,0,0},
      {0,1,1,1,1,1,1,0},
      {0,0,0,0,0,0,0,0}
};

static uint16_t pixels_p[8][8] = {
      {0,0,0,0,0,0,0,0},
      {0,0,1,1,1,1,0,0},
      {0,0,1,0,0,1,0,0},
      {0,0,1,1,1,1,0,0},
      {0,0,1,0,0,0,0,0},
      {0,0,1,0,0,0,0,0},
      {0,0,1,0,0,0,0,0},
      {0,0,0,0,0,0,0,0}
};

static uint16_t pixels_h[8][8] = {
      {0,0,0,0,0,0,0,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,1,1,1,1,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,1,0,0,0,0,1,0},
      {0,0,0,0,0,0,0,0}
};

static uint16_t pixels_blank[8][8] = {
       {0,0,0,0,0,0,0,0},
       {0,0,0,0,0,0,0,0},
       {0,0,0,0,0,0,0,0},
       {0,0,0,0,0,0,0,0},
       {0,0,0,0,0,0,0,0},
       {0,0,0,0,0,0,0,0},
       {0,0,0,0,0,0,0,0},
       {0,0,0,0,0,0,0,0}
 };

void openDisplay(void){
    initscr();
    start_color();
    init_pair(0, COLOR_BLACK, COLOR_BLACK);
    init_pair(1, COLOR_WHITE, COLOR_WHITE);
    init_pair(TEXT, COLOR_WHITE, COLOR_BLACK);
}
void closeDisplay(void){
    endwin();
}

void displayLetter(char letter, int xOffset, int yOffset){
    //displayPixels(pixels_m, xOffset, yOffset);
    switch(letter){
        case 'M':
            displayPixels(pixels_m, xOffset, yOffset);
            break;
        case 'I':
            displayPixels(pixels_i, xOffset+xOffset, yOffset);
            break;
        case 'P':
            displayPixels(pixels_p, xOffset, yOffset);
            break;
        case 'H':
            displayPixels(pixels_h, xOffset, yOffset);
            break;
        case ' ':
            displayPixels(pixels_blank, xOffset, yOffset);
        default:
            break;
    }
}   

void displayPixels(uint16_t pixels[8][8], int xoffset, int yoffset){
    for(int row=0; row<8; row++){
        int _row = (((row - xoffset)%8)+8)%8;
        move(row,0);
        for(int col=0; col<8; col++){
            int _col = (((col - yoffset)%8)+8)%8;
            move(row,col);
            attron(COLOR_PAIR(ON));
            //attron(COLOR_PAIR(OFF));
            int color = pixels[_row][_col];
            attron(COLOR_PAIR(color));
            addch(' ');
            attroff(COLOR_PAIR(color));
        }
    }
    refresh();
}

int lastx=-1, lasty=-1, laston=-1;
void display_dot(char x, char y, int on) {
      if(x==lastx && y==lasty && on==laston) {
          // No need to draw the same thing more than once
          return;
      }
      attron(COLOR_PAIR(OFF));
      mvaddch(lasty,lastx,' ');//#');
      if(on) {
          attron(COLOR_PAIR(ON));
          mvaddch(y,x,' ');//#');
      }
      lastx=x;
      lasty=y;
  }

 // Writes the message under where the dot is displayed
 void display_msg(char *msg) {
      attron(COLOR_PAIR(TEXT));
      mvaddstr(9,0,msg);
      //fprintf(stderr,"%s\n",msg);
  }
void clearDisplay(void){
    clear();
}
