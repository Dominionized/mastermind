#pragma once
class ConsoleMenu
{
public:
	ConsoleMenu();
	~ConsoleMenu();
	void Run();
	void displayCredits();
	string choixDesCouleurs();
	string accents(const string &pString);

	Color tabCouleurs[4]; //4 couleurs parmis un choix de 8
};

