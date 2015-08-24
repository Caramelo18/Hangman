#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <fstream>
#include "Game.h"	

using namespace std;

int main()
{
	srand((unsigned int) time(NULL));
	vector<string> words;
	char guess;
	std::fstream file;
	string line;
	file.open("C:/Users/fabio/Desktop/Hangman/Hangman/Debug/words.txt");
	
	while (!file.eof())
	{
		getline(file, line);
		words.push_back(line);
	}

	Game game(words);

	std::cout << "Welcome to Hangman!" << std::endl << std::endl;

	while (!game.isDiscovered())
	{
		game.printMan();
		if (game.getLives() == 0)
		{
			std::cout << std::endl << "You lost! The word was: "; game.showWord();
			std::cout << std::endl;
			return 0;
		}

		std::cout << std::endl << "Find the word:  "; game.showCode();

		std::cout << "Guess a letter: ";
		std::cin >> guess;
		std::cin.ignore(1000, '\n');
		std::cin.clear();
		std::cout << std::endl;

		game.changeCode(guess);
	}

	std::cout << "Congratulations, you found the word! \n\nThe word was: "; game.showCode();
	std::cout << std::endl;

	return 0;

}