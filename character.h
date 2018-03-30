#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED


 void clearScreen()   //function to "refresh the screen"
{
    std::cout << std::string( 500, '\n' );
}

class Character
{

    friend void descend(Character player);
    friend class foe;
    friend class Game;
    int FP,HP,FS, HPmax, FPmax;
    public:
    int location;
    void enterDungeon();
    Character(int strength, int health, int ability, int intelligence)
    {
      HP = health * 4;
      FS = (strength + ability) * 2 + intelligence;
      FP = (strength + health) * 2;
      HPmax = HP;
      FPmax = FP;
    }


};

void descend(Character player);

void Character::enterDungeon()
{
    clearScreen();
    std::cout <<"Before you is a very dangerous dungeon ... Do you (q)uit or (d)escend ...";
    char choice;
    do
    {
        std::cin >> choice;
        if (choice == 'q')
            return;
        else if (choice == 'd')
        {
             Character::location = -1;
             descend(*this);
        }
    }while (!(choice == 'q' || choice == 'd'));

}

Character createCharacter()    // function rolls random values until the player enters c and presses enter
{
    srand(time(nullptr));
    int health, strength, ability, intelligence;
    char choice;
  do
  {
     clearScreen();
     health = (rand() % 5 )+ 8;
     strength = (rand() % 5 )+ 8;
     ability = (rand() % 5 )+ 8;
     intelligence =(rand() % 5 )+ 8;
   std::cout << "Health:       " << health << std::endl
        << "Strength:     " << strength <<std::endl
        << "Ability:      " << ability << std::endl
        << "Intelligence: " << intelligence << std::endl
        << std::endl << std::endl
        << "Enter (c) to continue or enter another key to reroll: ";
   std::cin >> choice;
   if (choice ==  'q')
    break;
  }while(choice != 'c');


  Character player(strength, health, ability, intelligence);
  return player;
}



#endif // CHARACTER_H_INCLUDED
