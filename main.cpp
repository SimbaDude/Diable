#include "game.h"

// copyleft simba 2018
// C++ 98


int main()
{
    std::cout << "Enter (q) at any time to quit. Press enter to roll a character.";
    char c = std::cin.get();
    if (c == 'q') return 0;
    Character player = createCharacter();
    Game::instance()->createDungeon();
    player.enterDungeon();

    //execute game loop
    // need a function to assess players location and call a relevant function
    return 0;
}
