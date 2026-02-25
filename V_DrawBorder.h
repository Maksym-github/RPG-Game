#ifndef V_DRAWBORDER_H_INCLUDED
#define V_DRAWBORDER_H_INCLUDED

void drawBorder(int dx, int dy){
    setcurspos(dx, dy);
    for(int j = dx; j <= dx + 130; j++) cout << "=";

    for(int i = dy; i <= dy + 29; i++)
    {
        setcurspos(dx, i + 1); cout << "|";
        setcurspos(dx + 130, i + 1); cout << "|";
    }

    setcurspos(dx, dy + 31);
    for(int j = dx; j <= dx + 130; j++) cout << "=";
}

#endif // V_DRAWBORDER_H_INCLUDED
