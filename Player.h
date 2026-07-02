#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "SaveData.h"

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
    int oldId=-1;
    vector<int> inventory;
    vector<WorldObject> activeObjects;
    Player(string name):Character(10, 5, bx+rand()%120+1, by+rand()%24+1, 0.1, 2), m_name(name), hp_max(m_hp){}
    string GetName() const { return m_name; }
    int GetHp() const { return m_hp; }
    void EquipWeapon(int id) {
        Item& item = getItem(id);
        if (!item.isbuy) return;
        if (id == oldId) {
            oldId = -1;
            m_damage -= item.value;
        }
        else {
            if (oldId != -1) {
                Item& oldItem = getItem(oldId);
                m_damage -= oldItem.value;
            }
            oldId = id;
            m_damage += item.value;
        }
    }
    void Throw(Item& item) {
        WorldObject obj;
        obj.x = m_x;
        obj.y = m_y;
        obj.active = true;
        obj.duration = 2.0;
        obj.timer.reset();
        obj.type = item.type;

        if (item.type == granate) {
            obj.visual = "[ * ]";
            obj.color = 12;
        } else if (item.type == potion) {
            obj.visual = "( ~ )";
            obj.color = 10;
        }

        activeObjects.push_back(obj);
    }
    void Consume(float healAmount) {
        m_hp += healAmount;
        //if (m_hp >= hp_max) m_hp = hp_max;
        cout << "Ви випили зілля";
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
                Throw(item);
                inventory[slotIndex] = 0;
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
                int slot;
                if (key == '0') {
                    slot = 9;
                } else {
                    slot = key - '0';
                }
                UseItem(slot);
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
    void UpdateAndDrawObjects() {
        for (int i = 0; i < (int)activeObjects.size(); ) {
            if (activeObjects[i].timer.elapsed() >= activeObjects[i].duration) {
                activeObjects.erase(activeObjects.begin() + i);
            } else {
                SetConsoleTextAttribute(CursOut, activeObjects[i].color);
                setcurspos(activeObjects[i].x, activeObjects[i].y);
                cout << activeObjects[i].visual;

                if (activeObjects[i].type == granate && activeObjects[i].timer.elapsed() > 1.8) {
                    cout << " BOOM! ";
                }
                i++;
            }
        }
        SetConsoleTextAttribute(CursOut, 15);
    }
    void visualplayer(int x, int y){
        SetConsoleTextAttribute(CursOut, 15);
        if(a=='l'){
            setcurspos(x, y);   cout<<" ######";
            setcurspos(x, y+1); cout<<"#@   @ #";
            setcurspos(x, y+2); cout<<" ######";
        }
        else if(a=='r'){
            setcurspos(x, y);   cout<<" ######";
            setcurspos(x, y+1); cout<<"# @   @#";
            setcurspos(x, y+2); cout<<" ######";
        }
    }
    PlayerSaveData GetSaveData() const {
        PlayerSaveData data;
        data.hp_max = hp_max;
        data.repair = m_repair;
        data.damage = m_damage;
        data.exp = exp;
        data.token = token;
        data.speed = m_speed;
        data.attackSpeed = m_attackSpeed;
        data.name = m_name;
        data.oldId = oldId;
        data.inventory = inventory;
        return data;
    }
    void LoadSaveData(const PlayerSaveData& data) {
        hp_max = data.hp_max;
        m_hp = data.hp;
        m_repair = data.repair;
        m_damage = data.damage;
        exp = data.exp;
        token = data.token;
        m_speed = data.speed;
        m_attackSpeed = data.attackSpeed;
        m_name = data.name;
        inventory = data.inventory;

        oldId = -1;
        if (data.oldId != -1) {
            EquipWeapon(data.oldId);
        }
    }
};

#endif // PLAYER_H_INCLUDED
