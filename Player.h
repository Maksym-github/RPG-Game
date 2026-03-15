#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

extern int bx;
extern int by;
struct Item{
    int id;
    string name;
    int damage;
};
class Player: public Character{
private:
    string m_name;
    int level, hp_max=m_hp;
    float exp=0, token=0;
    char a;
public:
    Player(string name):Character(10, 5, bx+rand()%129+1, by+rand()%29+1, 0.1), m_name(name){}
    Item item;
    int GetItemId() const { return item.id; }
    string GetNameItem() const { return item.name; }
    string GetName() const { return m_name; }
    double GetHp() const { return m_hp; }
    double GetDamage() const { return m_damage+item.damage; }
    double GetRepair() const { return m_repair; }
    float GetExp() const { return exp; }
    void AddExp(double value) { exp+=value; }
    float GetToken() const { return token; }
    void AddToken(double value) { token+=value; }
    int GetPosX() const { return m_x; }
    int GetPosY() const { return m_y; }
    double Speed() const { return m_speed; }
    void AddDamage(double value) { m_damage+=value; }
    void RepairInc(double value) { m_repair-=value; }
    void SpeedInc(double value) { m_speed-=value; }
    void HpInc(double value) { m_hp+=value; hp_max+=value; }
    void HpSet() { m_hp=hp_max;}
    void Move(){
        int nx=m_x, ny=m_y;
        if(_kbhit()&&m_timer.elapsed()>=m_speed){
            switch (_getch()) {
                case 'w': ny--; break;
                case 's': ny++; break;
                case 'a': nx--; a='l'; break;
                case 'd': nx++; a='r'; break;
            }
            /*switch(_getch()){
                case 72: ny--; break;
                case 80: ny++; break;
                case 75: nx--; break;
                case 77: nx++; break;
                default: return;
            }*/
            m_timer.reset();
        }
        if(nx<=bx||nx>=bx+123||ny<=by||ny>=by+29) return;
        m_x=nx;
        m_y=ny;
    }
    void visualplayer(int x, int y){
        if(a=='l'){
            setcurspos(x, y);
            cout<<" ######"; curspos.X=x; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
            cout<<"#@   @ #"; curspos.X=x; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
            cout<<" ######";
        }
        else if(a=='r'){
            setcurspos(x, y);
            cout<<" ######"; curspos.X=x; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
            cout<<"# @   @#"; curspos.X=x; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
            cout<<" ######";
        }
    }
    void Repairing() {
        int now = GetTickCount();
        if(m_hp<hp_max&&now==m_repair){
            m_hp++;
            now=0;
        }

    }
};

#endif // PLAYER_H_INCLUDED

