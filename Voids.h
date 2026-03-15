#ifndef VOIDS_H_INCLUDED
#define VOIDS_H_INCLUDED

extern string state;

int priceupgrades[4]={3, 2, 5, 2}, priceitems[3]={10, 50, 100};

void Game(Player & player, int dx, int dy){
    const int MAX_ENEMY = 54;
    int wave = 1, enemiesToSpawn = wave, spawned = 0, aliveEnemies = 0;
    Timer spawnTimer;
    player.HpSet();
    system("cls");
    Enemy enemy[MAX_ENEMY];
    inventar(player, 140, 0);
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
            SetConsoleOutputCP(1251);
            setcurspos(0, 0);
            cout<<"Your name: "<<player.GetName()
            <<" Hp: "<<player.GetHp()
            <<" Damage: "<<player.GetDamage()
            <<" Experience: "<<player.GetExp()
            <<" Token: "<<player.GetToken()
            <<"     Нажми .. щоб: p - зупинити гру";
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
                    enemy[i].visualenemy(enemy[i].GetPosX(), enemy[i].GetPosY());
                }
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
        cout<<"Experience: "<<player.GetExp()<<" Token: "<<player.GetToken()<<" \n"
        <<"DMG: "<<player.GetDamage()
        <<" Hp: "<<player.GetHp()
        <<" Recovery Hp: "<<player.GetRepair()
        <<" Speed player: "<<player.Speed()<<endl;
        cout<<"Нажми .. щоб: b - повернутися назад; a - +1 до атаки за "<<priceupgrades[0]<<" T; H - +1 до хп за "<<priceupgrades[2]<<" T; h - -0,1 сек до відновлення хп за "<<priceupgrades[1]<<" T; s - -0,01 сек швидкості ходьби хп за "<<priceupgrades[3]<<" T;\n";
        cout<<"1 - купити меч І-рівня за "<<priceitems[0]<<" Т; 2 - купити меч ІІ-рівня за "<<priceitems[1]<<" Т;3 - купити меч ІІІ-рівня за "<<priceitems[2]<<" Т;\n";
        switch(_getch()){
            case 'b': system("cls"); return;
            case 'a':{
                if(player.GetToken()>=priceupgrades[0]){
                    player.AddDamage(1);
                    player.AddToken(-5);
                    priceupgrades[0]+=3*1.5;}
                break;
            }
            case 'h':{
                if(player.GetToken()>=priceupgrades[1]){
                    player.RepairInc(100);
                    player.AddToken(-5);
                    priceupgrades[1]+=2*1.5;}
                break;
            }
            case 'H':{
                if(player.GetToken()>=priceupgrades[2]){
                    player.HpInc(5);
                    player.AddToken(-5);
                    priceupgrades[2]+=5*1.5;}
                break;
            }
            case 's':{
                if(player.Speed()>0&&player.GetToken()>=priceupgrades[3]){
                    player.SpeedInc(0.01);
                    player.AddToken(-5);
                    priceupgrades[3]+=2*1.5;}
                break;
            }
            case '1':{
                if(player.GetToken()>=priceitems[0]){
                    player.AddToken(-10);
                    player.item={1, "Sword1", 5};
                }
                break;
            }
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
