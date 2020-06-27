#include "CPlayer.h"
#include<conio.h>

int CPlayer::playeTurn()
{
	int key=0;
	char key_press;
	int ascii_value;
	while (true)
	{
		key_press = _getch();
		ascii_value = key_press;
		gotoXY(15, 17);
		if (ascii_value == 72)
		{
			cout << "Acion: UP   ";
			key = 3;
		}
		else if (ascii_value == 80)
		{
			cout << "Acion: Down ";
			key = 4;
		}
		else if (ascii_value == 75)
		{
			cout << "Acion: Left ";
			key = 1;
		}
		else if (ascii_value == 77)
		{
			cout << "Acion: Right";
			key = 2;
		}
		else if (ascii_value == 13)
		{
			break;
		}
	}
	return key;
}

bool CPlayer::isWin(string current, string goal)
{
		if (current != goal)
			return false;
	
	return true;
}

string CPlayer::getNamePlayer()
{
	return "Chuc mung nguoi choi " + name + " da chien thang";
}

CPlayer::CPlayer(string name)
{
	this->name = name;
}
string CPlayer::getName()
{
	return this->name;
}

