#include <stdint.h>

void openDisplay(void);
void closeDisplay(void);
void displayLetter(char letter, int xOffset, int yOffset);
void clearDisplay(void);
void openInput(void);
void closeInput(void);
int checkInput(int delay);
//void display_dot(char x, char y, int on);
void displayPixels(uint16_t pixels, int xOffset, int yOffset);
//void display_msg(char *msg);
