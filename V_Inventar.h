#ifndef V_INVENTAR_H_INCLUDED
#define V_INVENTAR_H_INCLUDED

vector<int> inv;
int sizex=15, sizey=8;
void items(int x, int y, Item & item){
    switch(item.id){
    case 1:{
        setcurspos(x, y);
        cout<<"   ||"; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"   /\\"; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
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
        if(inv.empty()==0){
            //setcurspos(x+1, y+5); cout<<player.GetNameItem();
            items(x+1, y+1, player.GetItemId());
            inv.at(c)=player.GetItemId();
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
}

#endif // V_INVENTAR_H_INCLUDED
