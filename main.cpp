/*Дата початку: 14,02,2026;
2Д-гра де персонаж(символ або ACSII-зображення) буде ходити стрілочками або wasd і бити ворогоів ЛКМ при близькому зустрічі з ним або на відстані, якщо використовує лук чи камінь. Можливо перекласти*/
#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <ctime>
#include <conio.h>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include "SetCursPos.h"
#include "InputState.h"
#include "V_InputManager.h"
#include "Timer.h"
#include "Item.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "V_Hit.h"
#include "V_DrawBorder.h"
#include "V_Inventar.h"
#include "V_Upgrade.h"
#include "SafeProgresSystem.h"
#include "SaveData.h"

using namespace std;

int bx=0, by=4;
string playername="Player";
SaveSystem savesys;
Player player(playername);

void Game(int dx, int dy){
    savesys.Read(player);
    const int MAX_ENEMY = 54;
    int wave = 1, enemiesToSpawn = wave, spawned = 0, aliveEnemies = 0;
    Timer spawnTimer;
    player.HpSet();
    system("cls");
    Enemy enemy[MAX_ENEMY];
    InputState inputstate;
    while(player.isAlive()){
        InputManager(inputstate);
        SetConsoleTextAttribute(CursOut, 15);
        if(currentState == GameState::play){
            inventar(player, 140, 0);
            if(spawned < enemiesToSpawn && spawnTimer.elapsed()>=1.5){
                enemy[spawned] = Enemy(10 + wave * 2);
                spawned++;
                aliveEnemies++;
                spawnTimer.reset();
            }
            aliveEnemies = 0;
            for(int i=0; i<spawned; i++){
                if(enemy[i].isAlive())
                    aliveEnemies++;
            }
            drawBorder(dx, dy);
            SetConsoleOutputCP(1251);
            player.UpdateAndDrawObjects();
            setcurspos(0, 0);
            cout<<"Your name: "<<player.GetName()
            <<" Hp: "<<player.GetHp()
            <<" Damage: "<<player.GetDamage()
            <<" Experience: "<<player.GetExp()
            <<" Token: "<<player.GetToken()
            <<"     Нажми .. щоб: p - зупинити гру ";
            player.Clear(8, 3);
            player.Move(inputstate);
            player.Repairing();
            player.visualplayer(player.GetPosX(), player.GetPosY());
            for(int i=0; i<spawned; i++){ enemy[i].Clear(8, 3);}
            for(int i=0; i<spawned; i++){ enemy[i].Move(player);}
            for(int i=0; i<spawned; i++) Hit(player, enemy[i], inputstate);
            for(int i=0; i<spawned; i++){ if(enemy[i].isAlive()){ enemy[i].visualenemy(enemy[i].GetPosX(), enemy[i].GetPosY());}}
            setcurspos(0, dy+30+2);
            SetConsoleTextAttribute(CursOut, 15);
            cout<<" Wave: "<<wave<<"; Alive enemies: "<<aliveEnemies<<"; ";
            for(int i=0; i<spawned; i++){ cout<<"Hp enemy"<<i<<": "<<enemy[i].GetHp()<<"    ";}
            if(aliveEnemies == 0 && spawned == enemiesToSpawn){
                wave++;
                enemiesToSpawn=2+wave*2;
                int enemyHP = 10 + wave * 3;
                spawned = 0;
            }
            Sleep(10);
        }
        else if(currentState == GameState::pause){
            setcurspos(0, 0);
            cout<<"Нажми .. щоб: p - продовжити бій; e - вийти з гри;";
            setcurspos(53, 16);
            cout<<"Paused";
            system("cls");
            if(GetAsyncKeyState('E') & 0x8000) { currentState = GameState::play; break;}
        }
        savesys.Write(player);
    }
    if(!player.isAlive()){
        setcurspos(53, 16);
        SetConsoleTextAttribute(CursOut, 12);
        cout<<"Game over!";
        SetConsoleTextAttribute(CursOut, 15);
        Sleep(500);
        system("cls");
    }
}

void Properties(){
    system("cls");
    SetConsoleTextAttribute(CursOut, 15);
    while(true){
        setcurspos(70, 0); std::cout << "НАЛАШТУВАННЯ\n";
        std::cout<<"Нажми .. щоб: b - повернутися назад\n";
        std::cout << "1 - Скинути прогрес (Почати нову гру)\n";
        std::cout << "Ваш вибір: ";

        switch(_getch()) {
            case '1':{
                std::cout << "\n\nУВАГА! Ви дійсно хочете видалити весь прогрес?\n";
                std::cout << "Цю дію НЕМОЖЛИВО скасувати! (y - так / n - ні): ";

                char confirm = _getch();
                if (confirm == 'y' || confirm == 'Y') {
                    if (std::remove("Progres.sav") == 0) {
                        std::cout << "\n\nПрогрес успішно скинуто!\n";
                    } else {
                        std::cout << "\n\nФайлу збереження не знайдено (ви ще не грали).\n";
                    }

                    std::cout << "Гра зараз закриється для застосування змін.\n";
                    std::cout << "Запустіть її знову, щоб почати з чистого аркуша.\n";
                    std::cout << "Натисніть будь-яку клавішу для виходу...";
                    _getch();

                    exit(0);
                } else {
                    std::cout << "\n\nСкидання скасовано. Натисніть будь-яку клавішу...";
                    _getch();
                }
                break;
            }
            case 'b':{ system("cls"); return;}
        }
    }
}

int main(){
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    //cout<<"Type Your name: "; cin>>playername;

    srand(time(NULL));

    savesys.Read(player);

    while(true){
        SetConsoleTextAttribute(CursOut, 15);
        setcurspos(75, 0); cout << "МЕНЮ\n";
        cout<<"Нажми .. щоб: s почати грати; u перейти до апґрейдів; p перейти до налаштувань\n";
        switch(_getch()){
            case 's':{ Game(bx, by); break;}
            case 'u':{ Upgrade(player, savesys); break;}
            case 'p':{ Properties(); break;}
        }
    }

    return 0;
}
