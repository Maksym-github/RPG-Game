#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

extern int bx;
extern int by;
class Enemy: public Character{
private:
    char a;
    int m_n=0;
public:
    int lastAttack = 0;
    Enemy() : Character(10, 1, 0, 0, 0.3, 1) {
        m_hp = 0;
    }
    Enemy(int hp):Character(hp, 1, bx+rand()%120+1, by+rand()%24+1, 0.3, 1){}
    int GetHp()const{
        return m_hp;
    }
    int GetDamage() const { return m_damage; }
    int Speed() const { return m_speed; }
    void Move(const Player & player){
        int rx = player.GetPosX()-m_x, ry = player.GetPosY()-m_y, sw=8, sh=3;
        if (m_TimerMove.elapsed() >= m_speed) {
            if (m_x > bx && m_x < bx + 120 && m_y > by && m_y < by + 28) {
                if(rx>sw) {m_x++; a='r';}
                else if(rx<-sw) {m_x--; a='l';}
                if(ry>sh) {m_y++;}
                else if(ry<-sh) {m_y--;}
            }
            else return;
            m_TimerMove.reset();
        }
    }
    int GetPosX()const{
        return m_x;
    }
    int GetPosY()const{
        return m_y;
    }
    void visualenemy(int x, int y){
        SetConsoleTextAttribute(CursOut, 4);
        if(a=='l'){
            setcurspos(x, y);
            cout<<"########"; curspos.X=x; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
            cout<<"#@   @ #"; curspos.X=x; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
            cout<<"########";
        }
        else if (a=='r'){
            setcurspos(x, y);
            cout<<"########"; curspos.X=x; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
            cout<<"# @   @#"; curspos.X=x; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
            cout<<"########";
        }
    }
};


#endif // ENEMY_H_INCLUDED
