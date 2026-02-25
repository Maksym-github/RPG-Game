#ifndef V_HIT_H_INCLUDED
#define V_HIT_H_INCLUDED


void Hit(Player & player, Enemy & enemy){
    int now = GetTickCount();
    int rx=abs(player.GetPosX()-enemy.GetPosX()), ry=abs(player.GetPosY()-enemy.GetPosY());
    if(rx<=8&&ry<=3){
        if(enemy.isAlive()){
            if(_kbhit()){
                switch (_getch()){
                    case ' ': enemy.takeDamage(player.GetDamage()); break;
                }
            }
            if(now==2000){
                player.takeDamage(enemy.GetDamage());
                now=0;
            }
        }
    }
}

#endif // V_HIT_H_INCLUDED
