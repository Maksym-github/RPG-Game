#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

extern int bx;
extern int by;
class Player: public Character{
private:
    string m_name;
    int level, hp_max, i;
    float exp=0, token=100;
    char a;
    Timer m_regenTimer;
    double m_regenDelay = 3.0;
public:
    vector<int> inventory;
    int oldId=-1;
    Player(string name):Character(10, 5, bx+rand()%120+1, by+rand()%24+1, 0.1, 2), m_name(name), hp_max(m_hp){}
    string GetName() const { return m_name; }
    double GetHp() const { return m_hp; }
    void EquipWeapon(int id) {
        if (id < 0 || id >= (int)ItemDB.size()) return;
        if (id == oldId) {
            oldId = -1;
            m_damage = 5;
        }
        else if (ItemDB[id].isbuy) {
            oldId = id;
            m_damage = 5 + ItemDB[oldId].value;
        }
    }
    void Throw(){
        if(ItemDB[4].isbuy){
            setcurspos(m_x, m_y);
            cout<<"-----"; curspos.X--; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
            cout<<"//   \\"; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
            cout<<"|     |"; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
            cout<<"\\   //"; curspos.X--; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
            cout<<"-----"; curspos.X++; curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        }
    }
    void Consume(float healAmount) {
        m_hp += healAmount;
        if (m_hp > hp_max) m_hp = hp_max;
        // Можна додати звук або повідомлення "Ви випили зілля"
    }
    void UseItem(int slotIndex) {
        if (slotIndex >= (int)inventory.size() || inventory[slotIndex] == 0) return;

        int itemId = inventory[slotIndex];
        if (itemId == 0) return;
        Item& item = getItem(itemId);

        switch (item.type) {
            case weapon:
                EquipWeapon(itemId);
                break;
            case helmet:
                break;
            case potion:
                Consume(item.value);
                inventory[slotIndex]=0;
                break;
            case granate:
                Throw();
                break;
        }
    }
    float GetDamage() const { return m_damage; }
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
    void HpSet() { m_hp=hp_max; }
    void Move(InputState &inputstate){
        if (_kbhit()) {
            char key = _getch();
            if (key >= '0' && key <= '9') {
                UseItem(key - '0');
            }}

        int nx=m_x, ny=m_y;

        if (inputstate.IsMovingUp.current) ny--;
        if (inputstate.IsMovingDown.current) ny++;
        if (inputstate.IsMovingLeft.current) { nx--; a = 'l'; }
        if (inputstate.IsMovingRight.current) { nx++; a = 'r'; }
        //if(nx<=bx||nx>=bx+123||ny<=by||ny>=by+29) return;
        if (nx != m_x || ny != m_y) {
            if (m_TimerMove.elapsed() >= m_speed) {
                if(!(nx <= bx || nx >= bx + 123 || ny <= by || ny >= by + 29)) {
                    m_x=nx;
                    m_y=ny;
                }
                m_TimerMove.reset();
            }
        }
    }
    void visualplayer(int x, int y){
        SetConsoleTextAttribute(CursOut, 15);
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
        if (m_hp < hp_max) {
            if (m_regenTimer.elapsed() >= m_regenDelay) {
                m_hp++;
                if (m_hp > hp_max) m_hp = hp_max;
                m_regenTimer.reset();
            }
        } else {
            m_regenTimer.reset();
        }
    }
};

#endif // PLAYER_H_INCLUDED
