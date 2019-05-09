#include "SNAKE_H.h"
#define BLOCK 219

void snake::DrawMap()
{
	using namespace std;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == 0 || i == size - 1 || j == 0 || j == size - 1)cout << char(BLOCK);
			else {
				if (Find(i,j,false))cout << char(178);
				else if (i == point.x && j == point.y)cout << char(254);
				else cout << " ";
			}
		}
		cout << endl;
	}

	gotoxy(size_ + 5, 5);
	cout << "Punkty: " << points;

}

snake::snake()
{
	x = size / 2;
	y = size / 2;
	body[0] =
	{
		x,y,2,true,2
	};
	body[1] =
	{
		x,y - 1,2,true,2
	};
	body[2] =
	{
		x,y - 2,2,true,2
	};
	body[3] =
	{
		x,y - 3,2,true,2
	};

	srand(time(NULL));
	int a, b;
	do 
	{
		a = (rand() % (size_ - 2))+1;
		b = (rand() % (size_ - 2))+1;
	} while (Find(a, b, false) == true);
	point.x = a;
	point.y = b;

}

bool snake::Find(int i, int j, bool end)
{
	for (int k = 0; k < size_a; k++)
	{
		if (end == true && k == 0)continue;
		if (i == body[k].x && j == body[k].y)return true;
		
	}
	return false;
}


void snake::Update()
{
	for (int i = 0; i < size_a; i++)
	{
		if (body[i + 1].active == true && body[i].active == true)
		body[i + 1].direction = body[i].buff_dir;

		if(body[i].active == true)
		{
			if (body[i].direction == 1)body[i].x--;
			if (body[i].direction == 2)body[i].y++;
			if (body[i].direction == 3)body[i].x++;
			if (body[i].direction == 4)body[i].y--;
			body[i].buff_dir = body[i].direction;
		}
	}

	x = body[0].x;
	y = body[0].y;
}

void snake::ChangeBuff()
{
	for (int i = 0; i < size_a; i++)
	{
		if (body[i].active == true)
		body[i].buff_dir = body[i].direction;

	}
}

void snake::ChangeDirection(char key)
{
	if (key == 'w' && body[0].direction!=3)
	{
		body[0].direction = 1;
		return;
	}
	if (key == 'd' && body[0].direction != 4)
	{
		body[0].direction = 2;
		return;
	}
	if (key == 's' && body[0].direction != 1)
	{
		body[0].direction = 3;
		return;
	}
	if (key == 'a' && body[0].direction != 2)
	{
		body[0].direction = 4;
		return;
	}
}

bool snake::CheckEnd()
{
	if (Find(x, y, true) == true || x == size_-1 || x == 0 || y == size_-1 || y == 0)
	{
		return true;
	}
}

int snake::GivePoints()
{
	return points;
}

void snake::Eat()
{
	if (x == point.x && y == point.y)
	{
		points += 100;
		GeneratePoint();
		length++;
		body[length].active = true;
		if (body[length - 1].direction == 1)
		{
			body[length].x = body[length - 1].x + 1;
			body[length].y = body[length - 1].y;
		}
		if (body[length - 1].direction == 2)
		{
			body[length].x = body[length - 1].x;
			body[length].y = body[length - 1].y - 1;
		}
		if (body[length - 1].direction == 3)
		{
			body[length].x = body[length - 1].x - 1;
			body[length].y = body[length - 1].y;
		}
		if (body[length - 1].direction == 4)
		{
			body[length].x = body[length - 1].x ;
			body[length].y = body[length - 1].y + 1;
		}

	}

}

void snake::GeneratePoint()
{
	srand(time(NULL));
	int a, b;
	do
	{
		a = (rand() % (size_ - 2))+1;
		b = (rand() % (size_ - 2))+1;
	} while (Find(a, b, false) == true);
	point.x = a;
	point.y = b;

}