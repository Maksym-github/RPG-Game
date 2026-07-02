#ifndef V_UPGRADE_H_INCLUDED
#define V_UPGRADE_H_INCLUDED

vector<int> priceupgrades={3, 2, 5, 2}, priceitems={0, 1, 1, 1, 1, 1};
int x1=50, y1=3, x2=10, y2=3, kx=10;
int buyItem(int id){ ItemDB[id].isbuy=true; return id; }
#include "SafeProgresSystem.h"
void Upgrade(Player& player, SaveSystem& savesys){
    player.HpSet();
    system("cls");
    setcurspos(72, 0); cout << "АПҐРЕЙДИ\n";
    while(true){
        /*inventar(player, 140, 0);
        for(int i=0; i<(int)player.inventory.size(); i++){
        setcurspos(0, 15); cout<<"DEBUG: "<<player.inventory[i]<<ItemDB[i].name<<ItemDB[player.inventory[i]].name;}*/
        setcurspos(0, 1);
        cout<<"Experience: "<<player.GetExp()<<" Token: "<<player.GetToken()<<" \n"
        <<"DMG: "<<player.GetDamage()
        <<" Hp: "<<player.GetHp()
        <<" Recovery Hp: "<<player.GetRepair()
        <<" Speed player: "<<player.Speed();
        setcurspos(x1, y1); cout << "BODY";
        setcurspos(x1-kx, y1+1); cout << "a - +1 до атаки за " << priceupgrades[0] << " T";
        setcurspos(x1-kx, y1+2); cout << "H - +1 до хп за " << priceupgrades[2] << " T";
        setcurspos(x1-kx, y1+3); cout << "h - -0,1 сек до відновлення хп за " << priceupgrades[1] << " T";
        setcurspos(x1-kx, y1+4); cout << "s - -0,01 сек швидкості ходьби за " << priceupgrades[3] << " T";
        setcurspos(x2, y2); cout << "ITEMS";
        setcurspos(x2-kx, y2+1); cout << "1 - купити меч І-рівня за " << priceitems[1] << " Т";
        setcurspos(x2-kx, y2+2); cout << "2 - купити меч ІІ-рівня за " << priceitems[2] << " Т";
        setcurspos(x2-kx, y2+3); cout << "3 - купити меч ІІІ-рівня за " << priceitems[3] << " Т";
        setcurspos(x2-kx, y2+4); cout << "4 - купити гранату " << priceitems[4] << " T";
        switch(_getch()){
            case 'b':{ system("cls"); return;}
            case 'a':{
                if(player.GetToken()>=priceupgrades[0]){
                    player.AddDamage(1);
                    player.AddToken(-priceupgrades[0]);
                    priceupgrades[0]+=3*1.5;}
                break;
            }
            case 'h':{
                if(player.GetToken()>=priceupgrades[1]){
                    player.RepairInc(0.1);
                    player.AddToken(-priceupgrades[1]);
                    priceupgrades[1]+=2*1.5;}
                break;
            }
            case 'H':{
                if(player.GetToken()>=priceupgrades[2]){
                    player.HpInc(1);
                    player.AddToken(-priceupgrades[2]);
                    priceupgrades[2]+=5*1.5;}
                break;
            }
            case 's':{
                if(player.Speed()>0&&player.GetToken()>=priceupgrades[3]){
                    player.SpeedInc(0.01);
                    player.AddToken(-priceupgrades[3]);
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
            case '5':{
                if(player.GetToken()>=priceitems[5]&&!ItemDB[4].isbuy){
                    player.AddToken(-priceitems[5]);
                    player.inventory.push_back(buyItem(4));
                }
                //if(ItemDB[3].isbuy) player.inventory.push_back(ItemDB[3].id);
                break;
            }
        }

        setcurspos(0, 20);
        cout << "Нажми .. щоб: b - повернутися назад;" << endl;
        savesys.Write(player);
    }
}

#endif // V_UPGRADE_H_INCLUDED
