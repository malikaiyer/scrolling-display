#include <stdio.h>
#include <ncurses.h>
#include <unistd.h> //for usleep

#define OFF 1
#define ON 2
#define TEXT 3

void openInput(void){
    //don't display keys as they are pressed
    noecho();
    //get entries immediately without needing a return
    cbreak();
    //makes the arrow keys work right
    keypad(stdscr,TRUE);
    //Lets the program keep going when a key isn't pressed
    nodelay(stdscr, TRUE);
}
void closeInput(void){
    //does nothing but must be present
}
int checkInput(int delay){
    int ch = getch();
    timeout(delay);

     if(KEY_LEFT == ch) {
         return 1;}
     else if(KEY_RIGHT == ch){
        return 2;}
     else if(KEY_UP==ch){
        return 3;}
     else if(KEY_DOWN==ch){
        return 4;}
     else if('\n' == ch || '\r' == ch || KEY_ENTER == ch){
        return 5;}
     else{
        return 0;}
}
