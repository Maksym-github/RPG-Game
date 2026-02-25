#ifndef SETCURSPOS_H_INCLUDED
#define SETCURSPOS_H_INCLUDED
#include <iostream>
#include <windows.h>

HANDLE CursOut=GetStdHandle(STD_OUTPUT_HANDLE);
COORD curspos;
void setcurspos(int x, int y) {curspos.X=x; curspos.Y=y; SetConsoleCursorPosition(CursOut, curspos);}

#endif // SETCURSPOS_H_INCLUDED
