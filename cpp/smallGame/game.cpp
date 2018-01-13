#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
int getRandomNumber(int);
void fightMonster();
void attackMonster();
void attackPlayer();

int getRandomNumber(int num)
{
    srand(time(0));
    return static_cast<int>(rand()%num);
}

class Creature
{
protected:
    string m_name;
    char m_symbol;
    int m_health;
    int m_damage;
    int m_gold;
public:
    Creature(string name, char symbol, int health, int damage, int gold)
        : m_name(name), m_symbol(symbol), m_health(health), m_damage(damage), m_gold(gold) {}
    string getName() { return m_name; }
    char getSymbol() { return m_symbol; }
    int getHealth() { return m_health; }
    int getDamage() { return m_damage; }
    int getGold() { return m_gold; }
    void reduceHealth(int amount) { m_health-=amount; }
    bool isDead() { return (m_health <= 0)? true: false; }
    void addGold(int amount) { m_gold+=amount; }
};

class Player : public Creature
{
private:
    int m_level;
public:
    Player(string name): Creature(name, '@', 10, 1, 0), m_level(1){}
    int getLevel() { return m_level; }
    void levelUp()
    {
        m_level++;
        m_damage++;
        m_health+=2;
    }
};

class Monster: public Creature
{
public:
    enum Type {DRAGON, ORC, SLIME, MAX_TYPES};
    struct MonsterData
    {
        string name;
        char symbol;
        int health;
        int damage;
        int gold;
    };
    static MonsterData monsterData[MAX_TYPES];
    Monster(Type type): Creature(monsterData[type].name, monsterData[type].symbol, monsterData[type].health, monsterData[type].damage, monsterData[type].gold){}
    static Monster getRandomMonster()
    {
        int num = getRandomNumber(static_cast<int>(MAX_TYPES));
        return Monster(static_cast<Type>(num));
    }
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 },
};

void attackMonster(Player &p, Monster &m)
{
    m.reduceHealth(p.getDamage());
    cout << "You hit the " << m.getName() << " for " << p.getDamage() << " damage.\n";
    if (m.isDead() == true)
    {
        cout << "The " << m.getName() << " is killed.\n";
        p.addGold(m.getGold());
        p.levelUp();
        cout << "You are now at level " << p.getLevel() << ".\n";
        cout << "Your damage increased to " << p.getDamage() << ".\n";
        cout << "You are having " << p.getHealth() << " health left and " << p.getGold() << " gold.\n";
    }
    return;
}

void attackPlayer(Player &p, Monster &m)
{
    p.reduceHealth(m.getDamage());
    cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage.\n";
    return;
}

void fightMonster(Player &p, Monster &m)
{
    char action;
    while (1)
    {
        cout << "(R)un or (F)ight: ";
        cin >> action;
        if (action == 'r' || action == 'R')
        {
            int num = getRandomNumber(2);
            if (num == 0)
            {
                cout << "You fled away, coward.\n";
                cout << "You are having " << p.getHealth() << " health left and " << p.getGold() << " gold.\n";
                return;
            }
            else
            {
                cout << "You failed to flee.\n";
                attackPlayer(p, m);
                if (p.isDead())
                    return;
                continue;
            }
        }
        else if (action == 'f' || action == 'F')
        {
            while (1)
            {
                attackMonster(p, m);
                if (m.isDead())
                    return;
                attackPlayer(p, m);
                if (p.isDead())
                    return;
            }
        }
    }
}

int main()
{
    string name;
    cout << "Enter your name: ";
    cin >> name;
    Player p(name);
    cout << "Welcome, " << p.getName() << ".\n";
    while (p.isDead() == false || p.getLevel() < 20)
    {
        Monster m = Monster::getRandomMonster();
        if (m.getSymbol() == 's')
            cout << "\nYou have encountered a slime (s).\n";
        else if (m.getSymbol() == 'o')
            cout << "\nYou have encountered an orc (o).\n";
        else // 'D'
            cout << "\nYou have encountered a dragon (D).\n";
        fightMonster(p, m);
        if (p.isDead())
        {
            cout << "You died at level " << p.getLevel() << " with " << p.getGold() << " gold.\n";
            cout << "Too bad you can't take it!\n";
            break;
        }
        else if (p.getLevel() == 20)
        {
            cout << "Congratulations! You won the game with " << p.getGold() << " gold.\n";
            break;
        }
    }
    return 0;
}
