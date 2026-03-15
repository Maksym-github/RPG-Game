/*Äàòà ïî÷àòêó: 14,02,2026;
2Ä-ãðà äå ïåðñîíàæ(ñèìâîë àáî ACSII-çîáðàæåííÿ) áóäå õîäèòè ñòð³ëî÷êàìè àáî wasd ³ áèòè âîðîãî³â ËÊÌ ïðè áëèçüêîìó çóñòð³÷³ ç íèì àáî íà â³äñòàí³, ÿêùî âèêîðèñòîâóº ëóê ÷è êàì³íü. Ìîæëèâî ïåðåêëàñòè*/
#include <iostream>
#include <windows.h>
#include <vector>
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
    SetConsoleCP(1251);
    srand(time(NULL));
    Player player(playername);
    player.item={1, "Sword1", 5}; //для перевірки
    inventar(player, 100, 0); //для перевірки
    //cout<<"Type Your name: "; cin>>playername;
    //Menu(player);
    return 0;
}
