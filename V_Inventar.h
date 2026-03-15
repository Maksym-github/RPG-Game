#ifndef V_INVENTAR_H_INCLUDED
#define V_INVENTAR_H_INCLUDED

int sizex=16, sizey=8;
vector<int> inv;
void items(int x, int y, int c){
    switch(c){
    case 1:{
        setcurspos(x, y);
        cout<<"  /\\"; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<" |  |"; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<" |  |"; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<" /  \\ "; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"------"; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<" |  |"; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<" |  |"; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<" |--|"; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        break;
        }
    case 2:{
        setcurspos(x, y);
        cout<<"   ||"; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"   /\\"; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"  |  |"; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"  |  |"; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"  /  \\ "; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"--------"; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<" |    |"; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<" |    |"; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<" |----|"; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        break;
        }
    }
}
void inventar(Player & player, int x, int y){
    setcurspos(x, y);
    SetConsoleOutputCP(866);
    for(int c=0; c<5; c++){
        for(int j=0; j<sizex; j++){
            cout<<'#';
        }
        for(int i=0; i<sizey; i++){
            curspos.X=x+sizex; SetConsoleCursorPosition(CursOut, curspos);
            cout<<'#';
            curspos.X=x; SetConsoleCursorPosition(CursOut, curspos);
            cout<<'#';
            curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        }
        for(int j=0; j<=sizex; j++){
            cout<<'#';
        }
        curspos.Y++; curspos.Y--; SetConsoleCursorPosition(CursOut, curspos);
    }
    items(x+1, y+1, 1);
    items(x+1, y+10, 2);
    items(x+1, y+20, 3);
}

#endif // V_INVENTAR_H_INCLUDED
