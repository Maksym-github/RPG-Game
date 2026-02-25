/*Дата початку: 14,02,2026;
2Д-гра де персонаж(символ або ACSII-зображення) буде ходити стрілочками або wasd і бити ворогоів ЛКМ при близькому зустрічі з ним або на відстані, якщо використовує лук чи камінь. Можливо перекласти*/
#include <iostream>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include <chrono>
#include "SetCursPos.h"
#include "Timer.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "V_Hit.h"
#include "V_DrawBorder.h"
#include "V_Inventar.h"
#include "Voids.h"

using namespace std;

int bx=0, by=4;
string state, playername="Player";


int main(){
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    //cout<<"Type Your name: "; cin>>playername;
    Player player(playername);
    Menu(player);
    return 0;
}
