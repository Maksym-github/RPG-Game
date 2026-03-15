#ifndef SETCURSPOS_H_INCLUDED
#define SETCURSPOS_H_INCLUDED

HANDLE CursOut=GetStdHandle(STD_OUTPUT_HANDLE);
COORD curspos;
void setcurspos(int x, int y) {curspos.X=x; curspos.Y=y; SetConsoleCursorPosition(CursOut, curspos);}

#endif // SETCURSPOS_H_INCLUDED
