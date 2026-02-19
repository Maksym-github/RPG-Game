/*Дата початку: 14,02,2026;
2Д-гра де персонаж(символ або ACSII-зображення) буде ходити стрілочками або wasd і бити ворогоів ЛКМ при близькому зустрічі з ним або на відстані, якщо використовує лук чи камінь. Можливо перекласти*/
#include <iostream>
#include <windows.h>
#include <ctime>
#include <conio.h>

using namespace std;

int bx=0, by=4, c=4;

HANDLE CursOut=GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE CursIn=GetStdHandle(STD_INPUT_HANDLE);
COORD curspos;

void setcurspos(int x, int y) {curspos.X=x; curspos.Y=y; SetConsoleCursorPosition(CursOut, curspos);}

class Character {
protected:
    int m_hp, m_damage, m_x, m_y, m_repair=2000;
public:
    Character(int hp, int damage, int x, int y): m_hp(hp), m_damage(damage), m_x(x), m_y(y) {}
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
class Player: public Character{
private:
    string m_name;
    int level, hp_max=m_hp;
    float experience;
    char a;
public:
    Player(string name):Character(10, 5, bx+rand()%129+1, by+rand()%29+1), m_name(name){}
    string GetName() const { return m_name; }
    int GetHp() const { return m_hp; }
    int GetDamage() const { return m_damage; }
    int GetRepair() const { return m_repair; }
    int GetPosX() const { return m_x; }
    int GetPosY() const { return m_y; }
    void AddDamage(int value) { m_damage+=value; }
    void RepairInc(int value) { m_repair-=value; }
    void HpInc(int value) { m_hp+=value; hp_max+=value; }
    void HpSet() { m_hp=hp_max;}
    void Move(){
        int nx=m_x, ny=m_y;
        if(_kbhit()){
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
class Enemy: public Character{
private:
    char a;
    int m_n;
public:
    int damage;
    int lastAttack = 0;
    Enemy(int n):Character(10, 1, bx+rand()%129+1, by+rand()%29+1), damage(m_damage), m_n(n){}
    int GetHp()const{
        return m_hp;
    }
    void Move(const Player & player){
        int rx = player.GetPosX()-m_x, ry = player.GetPosY()-m_y;
        if(rx+8>=bx||rx<=bx+130||ry>=by-1||ry+3<=by+30){
            if(rx>9) {m_x++; a='r';}
            else if(rx<-9) {m_x--; a='l';}
            if(ry>4) {m_y++;}
            else if(ry<-4) {m_y--;}
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

void Hit(Player & player, Enemy & enemy){
    int now = GetTickCount();
    int rx=abs(player.GetPosX()-enemy.GetPosX()), ry=abs(player.GetPosY()-enemy.GetPosY());
    if(rx<=9&&ry<=4){
        if(enemy.isAlive()){
            if(_kbhit()){
                switch (_getch()){
                    case ' ': enemy.takeDamage(player.GetDamage()); break;
                }
            }
            if(now-enemy.lastAttack>=2000){
                player.takeDamage(enemy.damage);
                enemy.lastAttack=now;
            }
        }
    }
}
void drawBorder(int dx, int dy){
    setcurspos(dx, dy);
    for(int j = dx; j <= dx + 130; j++) cout << "=";

    for(int i = dy; i <= dy + 29; i++)
    {
        setcurspos(dx, i + 1); cout << "|";
        setcurspos(dx + 130, i + 1); cout << "|";
    }

    setcurspos(dx, dy + 31);
    for(int j = dx; j <= dx + 130; j++) cout << "=";
}
void inventar(Player & player, int x, int y){
    setcurspos(x, y);
    for(int c=0; c<5; c++){
        for(int j=0; j<10; j++){
            cout<<'#';
        }
        for(int i=0; i<6; i++){
            curspos.X=x+10; SetConsoleCursorPosition(CursOut, curspos);
            cout<<'#';
            curspos.X=x; SetConsoleCursorPosition(CursOut, curspos);
            cout<<'#';
            curspos.Y++; SetConsoleCursorPosition(CursOut, curspos);
        }
        for(int j=0; j<=10; j++){
            cout<<'#';
        }
        curspos.Y++; curspos.Y--; SetConsoleCursorPosition(CursOut, curspos);
    }
}
void Game(Player & player, int dx, int dy){
    player.HpSet();
    system("cls");
    //зробити постійний спавн через певний час
    Enemy enemy[]={Enemy(0),Enemy(1),Enemy(2),Enemy(3)};
    inventar(player, 140, 3);
    while(player.isAlive()){
        drawBorder(dx, dy);
        setcurspos(0, 0);
        cout<<"Your name: "<<player.GetName()<<" Hp: "<<player.GetHp()<<"    "<<" Damage: "<<player.GetDamage()<<"    ";
        player.Move();
        player.Repairing();
        for(int i=0; i<c; i++)
            enemy[i].Move(player);
        player.Clear(8,3);
        for(int i=0; i<c; i++)
            enemy[i].Clear(8,3);
        player.visualplayer(player.GetPosX(), player.GetPosY());
        for(int i=0; i<c; i++)
            if(enemy[i].isAlive())
                enemy[i].visualenemy(enemy[i].GetPosX(), enemy[i].GetPosY());
        for(int i=0; i<c; i++)
            Hit(player, enemy[i]);
        setcurspos(0, dy+30+2);
        for(int i=0; i<c; i++)
            cout<<"Hp enemy"<<i<<": "<<enemy[i].GetHp()<<"    ";
        Sleep(30);
    }
    if(!player.isAlive()){
        setcurspos(53, 16);
        SetConsoleTextAttribute(CursOut, 12);
        cout<<"Game over!";
        SetConsoleTextAttribute(CursOut, 15);
        Sleep(500);
        system("cls");
    }
}
void Upgrade(Player & player){
    system("cls");
    while(true){
        setcurspos(0, 0);
        cout<<"DMG: "<<player.GetDamage()<<" Hp: "<<player.GetHp()<<" Recovery Hp: "<<player.GetRepair()<<endl;
        cout<<"Нажми .. щоб: b - повернутися назад; a - +1 до атаки; H - +1 до хп; h - -0,1 сек до відновлення хп\n";
        switch(_getch()){
            case 'b': system("cls"); return;
            case 'a': player.AddDamage(1); break;
            case 'h': player.RepairInc(100); break;
            case 'H': player.HpInc(1); break;
        }
    }
}
void Properties(){
    system("cls");
    while(true){
        setcurspos(0, 0);
        cout<<"Нажми .. щоб: b - повернутися назад\n";
        switch(_getch()){
            case 'b': system("cls"); return;
        }
    }
}
void Menu(Player & player){
    while(true){
        setcurspos(0, 0);
        cout<<"Нажми .. щоб: s почати грати; u перейти до апґрейдів; p перейти до налаштувань\n";
        switch(_getch()){
            case 's': Game(player, bx, by); break;
            case 'u': Upgrade(player); break;
            case 'p': Properties(); break;
        }
    }
}
int main(){
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    Player player("Player");
    Menu(player);
    return 0;
}
