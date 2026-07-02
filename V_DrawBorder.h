#ifndef V_DRAWBORDER_H_INCLUDED
#define V_DRAWBORDER_H_INCLUDED

void drawBorder(int dx, int dy){
    setcurspos(dx, dy);
    SetConsoleOutputCP(866);
    SetConsoleTextAttribute(CursOut, 15);
    cout<<"\xc9"; for(int j = dx; j <= dx + 128; j++) {cout << "\xcd";} cout<<"\xbb";

    for(int i = dy; i <= dy + 29; i++)
    {
        setcurspos(dx, i + 1); cout << "\xba";
        setcurspos(dx + 130, i + 1); cout << "\xba";
    }

    setcurspos(dx, dy + 31);
    cout<<"\xc8"; for(int j = dx; j <= dx + 128; j++) {cout << "\xcd";} cout<<"\xbc";
}

#endif // V_DRAWBORDER_H_INCLUDED
