#ifndef V_INVENTAR_H_INCLUDED
#define V_INVENTAR_H_INCLUDED

void inventar(Player & player, int x, int y){
    setcurspos(x, y);
    for(int c=0; c<5; c++){
        for(int j=0; j<10; j++){
            cout<<'#';
        }
        for(int i=0; i<6; i++){
            curspos.X=x+10; SetConsoleCursorPosition(CursOut, curspos);
            cout<<'#';
            curspos.X=x; SetConsoleCursorPosition(CursOut, curspos);
            cout<<'#';
            curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        }
        for(int j=0; j<=10; j++){
            cout<<'#';
        }
        curspos.Y++; curspos.Y--; SetConsoleCursorPosition(CursOut, curspos);
    }
}

#endif // V_INVENTAR_H_INCLUDED
