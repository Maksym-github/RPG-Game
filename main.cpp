/*Дата початку: 14,02,2026;
2Д-гра де персонаж(символ або ACSII-зображення) буде ходити стрілочками або wasd і бити ворогоів ЛКМ при близькому зустрічі з ним або на відстані, якщо використовує лук чи камінь. Можливо перекласти*/
#include <iostream>
#include <windows.h>
#include <vector>
#include <ctime>
#include <conio.h>
#include <chrono>
#include "SetCursPos.h"
#include "InputState.h"
#include "V_InputManager.h"
#include "Item.h"
#include "Timer.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "V_Hit.h"
#include "V_DrawBorder.h"
#include "V_Inventar.h"
#include "V_Upgrade.h"
#include "Voids.h"

using namespace std;

int bx=0, by=4;
string playername="Player";

int main(){
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    srand(time(NULL));
    Player player(playername);
    //cout<<"Type Your name: "; cin>>playername;
    cout<<ItemDB.size();
    Menu(player);
    return 0;
}
