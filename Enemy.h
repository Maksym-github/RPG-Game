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
    Enemy() : Character(10, 1, 0, 0, 0.3) {
        m_hp = 0;
    }
    Enemy(int hp):Character(hp, 1, bx+rand()%129+1, by+rand()%29+1, 0.3){}
    int GetHp()const{
        return m_hp;
    }
    int GetDamage() const { return m_damage; }
    int Speed() const { return m_speed; }
    void Move(const Player & player){
        int rx = player.GetPosX()-m_x, ry = player.GetPosY()-m_y, kx=8, ky=3;
        if((rx+kx>=bx||rx<=bx+130||ry>=by-1||ry+ky<=by+30)&& m_timer.elapsed()>=m_speed){
            if(rx>kx) {m_x++; a='r';}
            else if(rx<-kx) {m_x--; a='l';}
            if(ry>ky) {m_y++;}
            else if(ry<-ky) {m_y--;}
            m_timer.reset();
        }
        else return;
    }
    int GetPosX()const{
        return m_x;
    }
    int GetPosY()const{
        return m_y;
    }
    void visualenemy(int x, int y){
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
