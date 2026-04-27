#ifndef V_INVENTAR_H_INCLUDED
#define V_INVENTAR_H_INCLUDED

int sizex=16, sizey=8, itemx;
void items(int x, int y, int c){
    switch(c){
    case 1:{
        setcurspos(x, y);
        cout<<"1            .'"; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"          .-'.'"; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"      \\.' .'  "; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"      /\\.'    "; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"    .' /\\     "; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"   / .'        "; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"   \\/          "; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        break;
        }
    case 2:{
        setcurspos(x, y);
        cout<<"2            .'"; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"          .-'.'"; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"      \\.' .'  "; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"      /\\.'    "; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"    .' /\\     "; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"   / .'        "; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"   \\/          "; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        break;
        }
    case 3:{
        setcurspos(x, y);
        cout<<"3            .'"; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"          .-'.'"; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"      \\.' .'  "; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"      /\\.'    "; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"    .' /\\     "; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"   / .'        "; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"   \\/          "; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        break;
        }
    case 4:{
        setcurspos(x, y);
        cout<<"4  -------"; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"  //     \\  "; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"//         \\"; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<" |         | "; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"\\         //"; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"  \\     //  "; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        cout<<"   -------   "; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        break;
        }
    }
}
void inventar(Player & player, int x, int y){
    setcurspos(x, y);
    SetConsoleTextAttribute(CursOut, 15);
    //SetConsoleOutputCP(866);
    for(int c=0; c<5; c++){
        for(int j=0; j<sizex; j++) cout<<'#';
        for(int i=0; i<sizey; i++){
            curspos.X=x+sizex; SetConsoleCursorPosition(CursOut, curspos);
            cout<<'#';
            curspos.X=x; SetConsoleCursorPosition(CursOut, curspos);
            cout<<'#';
            curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        }
        for(int j=0; j<=sizex; j++) cout<<'#';
        curspos.Y++; curspos.Y--; SetConsoleCursorPosition(CursOut, curspos);
    }
    for(int i=0; i<(int)player.inventory.size(); i++){
        items(x+1, y + (i * sizey) + 1, ItemDB[player.inventory[i]].id);
    }
}

#endif // V_INVENTAR_H_INCLUDED
