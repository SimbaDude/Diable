#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#define nullptr 0
#define number_Rooms 12

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>


#include "character.h"
#include "foe.h"

class room
{
    friend void descend(Character player);
    friend room returnRoom(enemy type, int f);
    friend class Game;

    std::vector<foe> foes;

    public:
     room(std::vector<foe> f): foes(f)
    {

    }

    room()
    {

    }
};

class Game
{

    friend void createRoom(std::vector<room> &dungeon);
    friend void descend(Character player);
    void roomClear(Character player);
    static Game *gObject;
    std::vector<room> dungeon;
    public:
    void createDungeon();
    void battle(Character player);
    static Game *instance()
    {
        if (!(gObject))
            gObject = new Game;
        return gObject;
    }

    void showRooms() //just a test function not used in the game
    {

        for (int r = 0; r < number_Rooms; ++r)
        {
            if (dungeon[r].foes[0].type == kobold)
                std::cout<< "room " << r << " contains " << dungeon[r].foes.size() << " " << "kobolds \n";
            else if (dungeon[r].foes[0].type == goblin)
                std::cout<< "room " << r << " contains " << dungeon[r].foes.size() << " " << "goblins \n";
            else
                std::cout<< "room " << r << " contains " << dungeon[r].foes.size() << " " << "skeletons \n";
        }

    }

};

Game *Game::gObject = nullptr;



room returnRoom(enemy type, int f)
{
        //complete this function
        std::vector <foe> foes;
        //for n < f create new foes of type enemy and push back to foes
        for (int i = 0; i < f; ++i)
            foes.push_back(newFoe(type));


        room r(foes);


        return r;
}

void Game::battle(Character player)
{
    int loc = player.location; // could make this const
    clearScreen();
    std::cout << "You charge into battle against the " << this->dungeon[loc].foes[0].what() << " " << std::endl;
    int SFS = 0; int hits = 0; int dTotal = 0;
    float FSRatio = (float)player.FP / player.FPmax;
    for (int i = 0; i < this->dungeon[loc].foes.size(); ++i)
        SFS += this->dungeon[loc].foes[0].FS;

    if (player.FS * FSRatio > SFS){
            player.FP -= 2;
        std::cout << "The battle is over in an instant and you are unscathed. \nBefore you lie "
                  << this->dungeon[loc].foes.size() << ' ' << "dead " << this->dungeon[loc].foes[0].what()
                  << "\nPress enter to continue.";
                  std::cin.get();
                  std::cin.get();
        roomClear(player);
    }
    else if ((player.FS * FSRatio) + 25 > SFS)
    {
        player.FP -= 3;
        std::cout << "There was a very short battle. ";
        for (int i = 0; i < 2; i++)
        {
            int d = this->dungeon[loc].foes[0].attack(player);
            if (d)
            {
                ++hits;
                player.HP -= d;
                dTotal += d;
            }

            d = 0;
        }

        if (player.HP < -25)
        {
            std::cout << "The " << this->dungeon[loc].foes[0].what() << " are too many and you are overwhelmed, falling in battle. \n"
                      << "You have died... Press enter to quit";
            std::cin.get();
            std::cin.get();
            return;
        }

        else if (player.HP < 0)
        {
            std::cout << "You fought valiantly, and at your feet lay " << this->dungeon[loc].foes.size() << ' '
                      << "dead " << this->dungeon[loc].foes[0].what() << ". However you are mortally wounded in the battle. \n"
                      << "You rest now and after a short time you pass into the next life... \n"
                      << "You have died... Press enter to quit";
            std::cin.get();
            std::cin.get();
            return;
        }

        else
        {
            std::cout << "You were struck " << hits << " times for " << dTotal << " damage. \n"
                      << "Before you lie "  << this->dungeon[loc].foes.size() << ' ' << "dead " << this->dungeon[loc].foes[0].what()
                      << "\nPress enter to continue";
            std::cin.get();
            std::cin.get();
            roomClear(player);
        }
    }
     else if (player.FS * FSRatio + 50 > SFS)
    {
        player.FP -= 6;
        std::cout << "There was a brief battle. ";
        for (int i = 0; i < 4; i++)
        {
            int d = this->dungeon[loc].foes[0].attack(player);
            if (d)
            {
                ++hits;
                player.HP -= d;
                dTotal += d;
            }

            d = 0;
        }

        if (player.HP < -25)
        {
            std::cout << "The " << this->dungeon[loc].foes[0].what() << " are too many and you are overwhelmed, falling in battle. \n"
                      << "You have died... Press enter to quit";
            std::cin.get();
            std::cin.get();
            return;
        }

        else if (player.HP < 0)
        {
            std::cout << "You fought valiantly, and at your feet lay " << this->dungeon[loc].foes.size() << ' '
                      << "dead " << this->dungeon[loc].foes[0].what() << ". However you are mortally wounded in the battle. \n"
                      << "You rest now and after a short time you pass into the next life... \n"
                      << "You have died... Press enter to quit";
            std::cin.get();
            std::cin.get();
            return;
        }

        else
        {
            std::cout << "You were struck " << hits << " times for " << dTotal << " damage. \n"
                      << "Before you lie "  << this->dungeon[loc].foes.size() << ' ' << "dead " << this->dungeon[loc].foes[0].what()
                      << "\nPress enter to continue";
            std::cin.get();
            std::cin.get();
            roomClear(player);
        }
    }
     else
    {
        player.FP -= 9;
        std::cout << "There was an extended battle. ";
        for (int i = 0; i < 6; i++)
        {
            int d = this->dungeon[loc].foes[0].attack(player);
            if (d)
            {
                ++hits;
                player.HP -= d;
                dTotal += d;
            }

            d = 0;
        }

        if (player.HP < -25)
        {
            std::cout << "The " << this->dungeon[loc].foes[0].what() << " are too many and you are overwhelmed, falling in battle. \n"
                      << "You have died... Press enter to quit";
            std::cin.get();
            std::cin.get();
            return;
        }

        else if (player.HP < 0)
        {
            std::cout << "You fought valiantly, and at your feet lay " << this->dungeon[loc].foes.size() << ' '
                      << "dead " << this->dungeon[loc].foes[0].what() << ". However you are mortally wounded in the battle. \n"
                      << "You rest now and after a short time you pass into the next life... \n"
                      << "You have died... Press enter to quit";
            std::cin.get();
            std::cin.get();
            return;
        }

        else
        {
            std::cout << "You were struck " << hits << " times for " << dTotal << " damage. \n"
                      << "Before you lie "  << this->dungeon[loc].foes.size() << ' ' << "dead " << this->dungeon[loc].foes[0].what()
                      << "\nPress enter to continue";
            std::cin.get();
            std::cin.get();
            roomClear(player);
        }
    }



}

void Game::roomClear(Character player)
{
    clearScreen();
    int loc = player.location;
    for (int i = 0; i < this->dungeon[loc].foes.size(); ++i);
        //delete this->dungeon[loc].foes[i];
    if (loc + 1 == number_Rooms)
    {
        std::cout << "You have cleared the dungeon, congratulations! \nPress enter to quit.";
        std::cin.get();
        return;
    }

    else{
        std::cout << "Will you (d)escend further or (q)uit? ";
        char choice;
        do
        {
            std::cin >> choice;
            if (choice == 'q')
                return;
            else if (choice == 'd')
                descend(player);
        }while (!(choice == 'q' || choice == 'd'));
    }
}

void createRoom(std::vector<room> &dungeon)
{


    room aRoom;
    int t = rand() % 3;
    enemy type;
    int n = ((rand() % 8) + 2);
    switch (t)
    {
        case 0:
            type = kobold;
            break;
        case 1:
            type = goblin;
            break;
        case 2:
            type = skeleton;
            break;
    }
    aRoom = returnRoom(type, n);

    dungeon.push_back(aRoom);

}



void descend(Character player)
{
    clearScreen();
    ++(player.location);
    std::cout << "You have reached level " << player.location + 1 << " of the dungeon. \n"
              << "HP:" << player.HP << '/' << player.HPmax << "        FP:" << player.FP << '/' << player.FPmax << '\n'
              << "There are " << Game::instance()->dungeon[player.location].foes.size() << ' '
              << Game::instance()->dungeon[player.location].foes[0].what() << " here \n"
              << "Do you (q)uit or (a)ttack...";
    char choice;
    do
    {
     std::cin >> choice;
     if (choice == 'q')
        return;
     else if (choice == 'a');
        Game::instance()->battle(player);
    }while(!(choice == 'q' || choice == 'a'));
}

void Game::createDungeon()
{

        for (int n = 0; n <= number_Rooms; ++n)
            createRoom(dungeon);

}

#endif // GAME_H_INCLUDED
