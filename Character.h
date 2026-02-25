#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

class Character {
protected:
    int m_hp, m_damage, m_x, m_y, m_repair=2000;
    double m_speed;
    Timer m_timer;
public:
    Character(int hp, int damage, int x, int y, double speed): m_hp(hp), m_damage(damage), m_x(x), m_y(y), m_speed(speed) {}
    void takeDamage(int amount){
        m_hp-=amount;
    }
    bool isAlive(){
        return m_hp>0;
    }
    void Clear(int width, int height)
    {
        for(int i=-1; i<=height; i++)
        {
            setcurspos(m_x-1, m_y+i);
            for(int j=-1; j<=width; j++)
                cout << " ";
        }
    }
};

#endif // CHARACTER_H_INCLUDED
