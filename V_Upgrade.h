#ifndef V_UPGRADE_H_INCLUDED
#define V_UPGRADE_H_INCLUDED

int priceupgrades[4]={3, 2, 5, 2}, priceitems[5]={0, 1, 1, 1, 1};
int buyItem(int id){ ItemDB[id].isbuy=true; return id; }
void Upgrade(Player & player){
    player.HpSet();
    system("cls");
    while(true){
        inventar(player, 140, 0);
        for(int i=0; i<(int)player.inventory.size(); i++){
        setcurspos(0, 15); cout<<"DEBUG: "<<player.inventory[i]<<ItemDB[i].name<<ItemDB[player.inventory[i]].name;}
        setcurspos(0, 0);
        cout<<"Experience: "<<player.GetExp()<<" Token: "<<player.GetToken()<<" \n"
        <<"DMG: "<<player.GetDamage()
        <<" Hp: "<<player.GetHp()
        <<" Recovery Hp: "<<player.GetRepair()
        <<" Speed player: "<<player.Speed()<<endl;
        cout<<"Нажми .. щоб: b - повернутися назад; a - +1 до атаки за "<<priceupgrades[0]<<" T; H - +1 до хп за "<<priceupgrades[2]<<" T; h - -0,1 сек до відновлення хп за "<<priceupgrades[1]<<" T; s - -0,01 сек швидкості ходьби за "<<priceupgrades[3]<<" T;\n";
        cout<<"1 - купити меч І-рівня за "<<priceitems[1]<<" Т; 2 - купити меч ІІ-рівня за "<<priceitems[2]<<" Т; 3 - купити меч ІІІ-рівня за "<<priceitems[3]<<" Т; 4 - купити гранату "<<priceitems[4]<<" T \n";
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
                    player.RepairInc(0.1);
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
                if(player.GetToken()>=priceitems[1]&&!ItemDB[0].isbuy){
                    player.AddToken(-priceitems[1]);
                    player.inventory.push_back(buyItem(0));
                }
                //if(ItemDB[0].isbuy) player.inventory.push_back(ItemDB[0].id);
                break;
            }
            case '2':{
                if(player.GetToken()>=priceitems[2]&&!ItemDB[1].isbuy){
                    player.AddToken(-priceitems[2]);
                    player.inventory.push_back(buyItem(1));
                }
                //if(ItemDB[1].isbuy) player.inventory.push_back(ItemDB[1].id);
                break;
            }
            case '3':{
                if(player.GetToken()>=priceitems[3]&&!ItemDB[2].isbuy){
                    player.AddToken(-priceitems[3]);
                    player.inventory.push_back(buyItem(2));
                }
                //if(ItemDB[2].isbuy) player.inventory.push_back(ItemDB[2].id);
                break;
            }
            case '4':{
                if(player.GetToken()>=priceitems[4]&&!ItemDB[3].isbuy){
                    player.AddToken(-priceitems[4]);
                    player.inventory.push_back(buyItem(3));
                }
                //if(ItemDB[3].isbuy) player.inventory.push_back(ItemDB[3].id);
                break;
            }
        }
    }
}

#endif // V_UPGRADE_H_INCLUDED
