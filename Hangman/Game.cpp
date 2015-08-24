#include "Game.h"


Game::Game(std::vector<std::string> words)
{
	this->words = words;
	word = words[rand() %words.size()];
	code.resize(word.size());
	for (unsigned int i = 0; i < code.size(); i++)
		code[i] = '*';
	Discovered = false;
	lives = 6;
}

bool Game::isDiscovered()
{
	if (code == word)
		Discovered = true;
	return Discovered;
}

void Game::printMan()
{
	
		//   |/---
		//   |  o
		//   | /|\
	    //   | / \
		//   |____

		switch (lives)
		{
		case 0:
			std::cout << "|/---\n|  o\n|\n|\n|____";
			break;
		case 1:
			std::cout << "|/---\n|  o\n|\n|\n|____";
			break;
		case 2:
			std::cout << "|/---\n|  o\n|  |\n|\n|____";
			break;
		case 3:
			std::cout << "|/---\n|  o\n| /|\n|\n|____";
			break;
		case 4:
			std::cout << "|/---\n|  o\n| /|\\\n|\n|____";
			break;
		case 5:
			std::cout << "|/---\n|  o\n| /|\\\n| /\n|____";
			break;
		case 6:
			std::cout << "|/---\n|  o\n| /|\\\n| / \\\n|____";
			break;
		}

		std::cout << std::endl;

		return;
	
}

void Game::showCode()
{
	std::cout << code << std::endl;
}

bool Game::changeCode(char c)
{
	int j = 0;
	for (unsigned int i = 0; i < code.size(); i++)
	{
		if (tolower(c) == word[i] || toupper(c) == word[i])
		{
			code[i] = word[i];
			j++;
		}
	}
	if (j > 0)
		return true;
	else
	{
		lives--;
		return false;
	}
}

int Game::getLives()
{
	return lives;
}

void Game::showWord()
{
	std::cout << word << std::endl;
}