#include <iostream>
#include <ctime>

void PlayIntroduction(int Difficulty)
{
    std::cout << "\n\nYou are a trying to be a King of the hacker world and present in a level "<< Difficulty ;
    std::cout << " secure server room...\nYou need to input the correct code to become the king...\n\n";
}

bool PlayGame(int Difficulty)
{
    PlayIntroduction(Difficulty);
    
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeMul = CodeA * CodeB * CodeC;
    std::cout << "+ There are 3 numbers in the code ";
    std::cout << "\n+ The code adds up to: "<< CodeSum;
    std::cout << "\n+ The code multiplies to: " << CodeMul << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin>> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if(GuessSum==CodeSum && GuessProduct==CodeMul)
    {
        std::cout<< "\n**Well done you are near to become a king!!**Head on to the next level";
        return true;
    }
    else 
    {
        std::cout<< "\n**You entered the wrong code! Careful agent! Try again!**";
        return false;
    }
}

int main()
{
    srand(time(NULL));
    
    int LevelDifficulty = 1;
    int const MaxLevel = 10;
    while(LevelDifficulty <= MaxLevel)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    std::cout<< "\n**Well done!! You are now the KING! Rule the World!**\n";
    return 0;
}