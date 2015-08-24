#pragma once
#include <string>
#include <vector>
#include <iostream>

class Game
{
public:
	Game();
	Game(std::vector<std::string> words);
	bool isDiscovered();
	void printMan();
	void showCode();
	bool changeCode(char c);
	int getLives();
	void showWord();

private:
	bool Discovered;
	std::string code;
	std::string word;
	std::vector<std::string> words;
	int lives;

};

