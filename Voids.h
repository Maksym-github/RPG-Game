#ifndef VOIDS_H_INCLUDED
#define VOIDS_H_INCLUDED

extern string state;

void Game(Player & player, int dx, int dy){
    const int MAX_ENEMY = 54;
    int wave = 1, enemiesToSpawn = wave, spawned = 0, aliveEnemies = 0;
    Timer spawnTimer;
    player.HpSet();
    system("cls");
    Enemy enemy[MAX_ENEMY];
    inventar(player, 140, 3);
    state="play";
    while(player.isAlive()){
        if(state=="play"){
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
            if(_kbhit()){
                switch(_getch()){
                    case 'p': state="pause"; break;
                }
            }
            drawBorder(dx, dy);
            setcurspos(0, 0);
            cout<<"Your name: "<<player.GetName()
            <<" Hp: "<<player.GetHp()
            <<" Damage: "<<player.GetDamage()
            <<" Нажми .. щоб: p - зупинити гру";
            player.Move();
            player.Repairing();
            for(int i=0; i<spawned; i++){
                enemy[i].Move(player);}
            player.Clear(8,3);
            for(int i=0; i<spawned; i++){
                enemy[i].Clear(8,3);}
            player.visualplayer(player.GetPosX(), player.GetPosY());
            for(int i=0; i<spawned; i++){
                if(enemy[i].isAlive()){
                    enemy[i].visualenemy(enemy[i].GetPosX(), enemy[i].GetPosY());}
            }
            for(int i=0; i<spawned; i++){
                Hit(player, enemy[i]);}
            setcurspos(0, dy+30+2);
            cout<<" Wave: "<<wave<<"; Alive enemies: "<<aliveEnemies<<"; ";
            for(int i=0; i<spawned; i++){
                cout<<"Hp enemy"<<i<<": "<<enemy[i].GetHp()<<"    ";}
            if(aliveEnemies == 0 && spawned == enemiesToSpawn){
                wave++;
                enemiesToSpawn=2+wave*2;
                int enemyHP = 10 + wave * 3;
                spawned = 0;
            }
            Sleep(10);
        }
        else if(state=="pause"){
            system("cls");
            setcurspos(0, 0);
            cout<<"Нажми .. щоб: p - продовжити бій; e - вийти з бою";
            setcurspos(53, 16);
            cout<<"Paused";
            if(_kbhit()){
                switch(_getch()){
                    case 'p': state="play"; system("cls"); break;
                    case 'e': system("cls"); return;
                }
            }
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
void Upgrade(Player & player){
    player.HpSet();
    system("cls");
    while(true){
        setcurspos(0, 0);
        cout<<"DMG: "<<player.GetDamage()<<" Hp: "<<player.GetHp()<<" Recovery Hp: "<<player.GetRepair()
        <<" Speed player: "<<player.Speed()<<endl;
        cout<<"Нажми .. щоб: b - повернутися назад; a - +1 до атаки; H - +1 до хп; h - -0,1 сек до відновлення хп; s - -0,01 сек швидкості ходьби хп\n";
        switch(_getch()){
            case 'b': system("cls"); return;
            case 'a': player.AddDamage(1); break;
            case 'h': player.RepairInc(100); break;
            case 'H': player.HpInc(1); break;
            case 's': if (player.Speed()>0) player.SpeedInc(0.01); break;
        }
    }
}
void Properties(){
    system("cls");
    while(true){
        setcurspos(0, 0);
        cout<<"Нажми .. щоб: b - повернутися назад\n";
        switch(_getch()){
            case 'b': system("cls"); return;
        }
    }
}
void Menu(Player & player){
    while(true){
        setcurspos(0, 0);
        cout<<"Нажми .. щоб: s почати грати; u перейти до апґрейдів; p перейти до налаштувань\n";
        switch(_getch()){
            case 's': Game(player, bx, by); break;
            case 'u': Upgrade(player); break;
            case 'p': Properties(); break;
        }
    }
}

#endif // VOIDS_H_INCLUDED
