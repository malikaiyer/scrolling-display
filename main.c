#include <stdio.h>
#include "scroll.h"
#include <ncurses.h>
#include <unistd.h>
#include <math.h>

#define OFF 1
#define ON 2
#define TEXT 3

void handler(unsigned int code){}
/*
int main(void){
    openDisplay();
    openInput();
    
    //initializing varaibles 
    char letter = 'M';
    int num;
    int start = 1;

    //initializing displayLetter
    displayLetter(letter, 0, 0);

    closeDisplay();
 }
*/
 int main(void) {
    openDisplay();
    openInput();
    int running = 1, on = 0;
    int x=0, y=0;
    int dx=0, dy=0;
    int xDiv=0, yDiv=0;
    int xCom=1000, yCom=1000;
    int dxCount=0, dyCount=0;
    int count2=1;


    while(running) {
        int ch = getch();
        //if('\n' == ch || '\r' == ch || KEY_ENTER == ch)
        //{
         //   running=0;}
        if(KEY_LEFT == ch || 'h' == ch) {
            dx--;
            if(dx<-10){dx=-10;}
            if(dx<0){
                xDiv++;
                if(xDiv > 10){xDiv=10;}
            }
            else {
                xDiv--;
            }
        } else if(KEY_RIGHT == ch || 'l' == ch) {
            dx++;
            if(dx>10){dx=10;}
            if(dx>0){
                xDiv++;
                if(xDiv>10){xDiv=10;}
            }    
            else {
                xDiv--;
            }
        } else if(KEY_UP == ch || 'k' == ch) {
            dy--;
            if(dy<-10){dy=-10;}
            if(dy<0){
                yDiv++;
                if(yDiv>10){yDiv=10;}
            }
            else {
                yDiv--;
            }
        } else if(KEY_DOWN == ch || 'j' == ch) {
            dy++;
            if(dy>10){dy=10;}
            if(dy>0){
                yDiv++;
                if(yDiv>10){yDiv=10;}
            }
            else {
                yDiv--;
            }
        }

        if(dxCount==1000){dxCount=0;}
        dxCount++;

        if(dyCount==1000){dyCount=0;}
        dyCount++;

        if (xDiv==1) { xCom = 1000;
        } else if(xDiv==2) { xCom = 500;
        } else if(xDiv==3) { xCom = 333;
        } else if(xDiv==4) { xCom = 250;
        } else if(xDiv==5) { xCom = 200;
        } else if(xDiv==6) { xCom = 166;
        } else if(xDiv==7) { xCom = 142;
        } else if(xDiv==8) { xCom = 125;
        } else if(xDiv==9) { xCom = 111;
        } else if(xDiv==10){ xCom = 100;
        }

        if (yDiv==1) { yCom = 1000;
        } else if(yDiv==2) { yCom = 500;
        } else if(yDiv==3) { yCom = 333;
        } else if(yDiv==4) { yCom = 250;
        } else if(yDiv==5) { yCom = 200;
        } else if(yDiv==6) { yCom = 166;
        } else if(yDiv==7) { yCom = 142;
        } else if(yDiv==8) { yCom = 125;
        } else if(yDiv==9) { yCom = 111;
        } else if(yDiv==10){ yCom = 100;
        }

        if (dxCount==xCom) {
            dxCount=0;
            if (dx<0){
                x--;
                if(x<0){x=7;}
            }
            if (dx>0) {
                x++;
                if(x>7){x=0;}
            }
        }

        if (dyCount==yCom) {
            dyCount=0;
            if (dy<0){
                y--;
                if(y<0){y=7;}
            }
            if (dy>0){
                y++;
                if(y>7){y=0;}
            }
        }

        if (ch != ERR) {
            char buffer[1024];
           //printf(buffer,"    Got octal keycode: %o   ",ch);
           //isplay_msg(buffer);
        }
        
        
        
       if('\n' == ch || '\r' == ch || KEY_ENTER == ch){
             count2+=1;
             clearDisplay();
             if(count2==5){
                 running=0;
             }
       }
       
       if (count2==1){
          displayLetter('M',y,x);
          usleep(1000);

       } else if(count2==2){
          displayLetter('I',y,x);
          usleep(1000);

      } else if(count2==3){
          displayLetter('P',y,x);
          usleep(1000);

      } else if(count2==4){
          displayLetter('H',y,x);
          usleep(1000);
      }

    }
    //display_dot(x,y,0);
    clearDisplay();
    closeDisplay();
}

