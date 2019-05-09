
#ifndef SNAKE_H

#include <windows.h>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>


#define SNAKE_H
#define size_ 15
#define size_a (size_-2)*(size_-2)


class snake
{
private:
	int x;
	int y;
	int size = size_;
	int points=0;
	int length=3;
	struct point_s
	{
		int x;
		int y;
	};
	point_s point;
	struct elements
	{
		int x=9999;
		int y=9999;
		int direction = 5; //1=up,2=right,3=down,4=left
		bool active = false;
		int buff_dir = 5;
	};
	elements body[size_a];
public:
	void Update();
	void ChangeDirection(char key);
	void Eat();
	void ChangeBuff();
	bool CheckEnd();
	void DrawMap();
	void GeneratePoint();
	bool Find(int i, int j, bool end);
	snake();
	int GivePoints();
};

void gotoxy(int x, int y);
void cls();


#endif
