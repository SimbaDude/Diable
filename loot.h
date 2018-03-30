#ifndef LOOT_H_INCLUDED
#define LOOT_H_INCLUDED



class loot
{
     friend class Game;
     int value;
     public:
     loot ()
     {
         srand(time(nullptr));
         int v = (rand() % 10) + 1;
         value = v;
     }
};


class helmet: public loot
{
    friend class Game;
    std::string name;
    int armor;
    public:
    helmet()
    {
        name = "helmet";
        armor = 8;
    }

};

class shield: public loot
{
    friend class Game;
    std::string name;
    int bonus;

    public:
    shield()
    {
        srand(time(nullptr));
        int c = rand()%2;
        if (c == 0)
        {
            name = "Buckler";
            bonus = 6;
        }

        else if (c == 1)
        {
            name = "Round Shield";
            bonus = 12;
        }
    }
};

class chest: public loot
{
    friend class Game;
    std::string name;
    int armor;
    public:
    chest()
    {
        srand(time(nullptr));
        int c = rand()%2;
        if (c == 0)
        {
            name = "Leather Armor";
            armor = 10;
        }

        else if (c == 1)
        {
            name = "Chain Mail";
            armor = 22;
        }
    }
};

class hand: public loot
{
    friend class Game;
    std::string name;
    int bonus;

    public:
    hand()
    {
        srand(time(nullptr));
        int c = rand()% 3;
        switch (c)
        {
            case 0:
                name = "Dagger";
                bonus = 4;
                break;
            case 1:
                name = "Club";
                bonus = 6;
                break;
            case 2:
                name = "Sword";
                bonus = 12;
        }
    }
};


loot makeLoot()
{
    loot *L = nullptr;
    srand(time(nullptr));
    int t = rand() % 6;
    switch (t)
    {
        case 0:
            L = new loot;
            break;
        case 1:
            L = new chest;
            break;
        case 2:
            L = new hand;
            break;
        case 3:
            L = new shield;
            break;
        case 4:
            L = new helmet;
            break;
        case 5: break; // no loot
    }

    return *L;
}

#endif // LOOT_H_INCLUDED
