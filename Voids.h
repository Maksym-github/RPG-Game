#ifndef VOIDS_H_INCLUDED
#define VOIDS_H_INCLUDED

void Game(Player & player, int dx, int dy){
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
            player.visualplayer(player.GetPosX(), player.GetPosY());
            player.Repairing();
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
        setcurspos(0, 0);
        cout<<"Íàæìè .. ùîá: b - ïîâåðíóòèñÿ íàçàä\n";
        switch(_getch()){
            case 'b': system("cls"); return;
        }
    }
}

void Menu(Player & player){
    while(true){
        setcurspos(0, 0);
        SetConsoleTextAttribute(CursOut, 15);
        cout<<"Íàæìè .. ùîá: s ïî÷àòè ãðàòè; u ïåðåéòè äî àï´ðåéä³â; p ïåðåéòè äî íàëàøòóâàíü\n";
        switch(_getch()){
            case 's': Game(player, bx, by); break;
            case 'u': Upgrade(player); break;
            case 'p': Properties(); break;
        }
    }
}

#endif // VOIDS_H_INCLUDED
