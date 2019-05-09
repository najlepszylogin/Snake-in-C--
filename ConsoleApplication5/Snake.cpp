#include "SNAKE_H.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <windows.h>

using namespace std;

int main()
{
	int x=5;
	int y;
	char key;
	int speed = 125;
	snake Game;
	cout << "Kliknij cokolwiek aby rozpoczac";
	_getch();
	system("CLS");

	do {
		Game.DrawMap();
		if (_kbhit()) {
			key = _getch();
			if (key == 'q' && speed!=350)speed += 50;
			if (key == 'e' && speed!=50)speed -= 50;
			Game.ChangeBuff();
			}
		Game.Eat();
		Game.ChangeDirection(key);
		Game.Update();
		Sleep(speed);
		if (Game.CheckEnd() == true)
		{
			x = 1000;
		}
		cls();
	} while (x != 1000);
	gotoxy(5, size_ + 2);
	cout << "KONIEC GRY!!!!";
	cout << endl;
	cout << "Zdobylas " << Game.GivePoints() << " punktow!" << endl << endl << endl;
	_getch();
	return 0;
}