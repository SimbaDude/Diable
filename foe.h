#ifndef FOE_H_INCLUDED
#define FOE_H_INCLUDED


enum enemy {kobold, goblin, skeleton} ;  // a token to tell the player what kind of enemy he is facing

class foe
{

    friend class Game;

    protected:
    int damage, FS;
    public:
    enemy type;
    foe (int d, int f, enemy n): damage(d), FS(f), type(n) // seperate instances of foe may be created with the same "type" but different combat values
    {

    }


    std::string what()
    {
        switch (type)
        {
            case kobold:
                return "kobolds";

            case goblin:
                return "goblins";

            case skeleton:
                return "skeletons";

        }
    }

    int attack(const Character &player)
    {
        float FSRatio = (float)player.FP / player.FPmax;
        srand(time(nullptr));
        int roll = (rand() % 20) + 1 + this->FS;
        if (roll > player.FS *FSRatio + 20)
            return this->damage * 1.5;
        else if (roll > player.FS * FSRatio + 5)
            return this->damage;
        else if (roll > player.FS * FSRatio)
            return this->damage * .5;
            else return 0;
    }

    foe * who()
    {
        return this;
    }
};

foe newFoe(enemy n) //generic "constructor" to create foes of the same type with the same fighting abilities
    {
        foe * f = nullptr;
        switch (n)
        {
            case kobold:
                f = new foe(4, 30, kobold);
                break;
            case goblin:
                f = new foe(8, 35, goblin);
                break;
            case skeleton:
                f = new foe(16, 25, skeleton);
                break;
        }

        return *f;
    }

#endif // FOE_H_INCLUDED
