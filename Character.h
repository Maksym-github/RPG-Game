#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

class Character {
protected:
    int m_hp;
    double m_repair=2;
    float m_damage;
    int m_x, m_y;
    double m_speed;
    int m_attackSpeed;
public:
    Timer m_TimerMove;
    Timer m_TimerAttack;
    Character(int hp, int damage, int x, int y, double speed, double AttackSpeed):
    m_hp(hp), m_damage(damage), m_x(x), m_y(y), m_speed(speed), m_attackSpeed(AttackSpeed) {}
    double GetAttackSpeed() const { return m_attackSpeed; }
    void takeDamage(int amount){
        m_hp-=amount;
    }
    bool isAlive(){
        return m_hp>0;
    }
    void Clear(int width, int height){
        for(int i=0; i<height; i++)
        {
            for(int j=0; j<width; j++){
                setcurspos(m_x+j, m_y+i);
                SetConsoleTextAttribute(CursOut, 0);
                cout << " ";
            }
        }
    }
};

#endif // CHARACTER_H_INCLUDED
