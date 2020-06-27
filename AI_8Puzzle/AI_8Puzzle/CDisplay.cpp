#include "CDisplay.h"
#include<time.h>


bool checkInputName(string name)
{
	for (int i = 0; i < name.length(); i++)
	{
		if (name[i] >= 'a' && name[i] <= 'z' || name[i] >= 'A' && name[i] <= 'Z')
			return true;
	}
	return false;
}

bool checkArray(int A[])
{
	for (int i = 0; i < 9; i++)
	{
		if (A[i] == 0)
			return false;
	}
	return true;
}
string input()
{
	string temp;
	while (true)
	{
		
		getline(cin, temp);
		gotoXY(37, 17);
		if (temp.empty())
			cout << "String empty";
		else if (temp.size() > 9)
			cout << "Goal is maxSize 9";
		else
		{
			int A[9] = { 0 };
			for (int i = 0; i < temp.size(); i++)
			{
				if (temp[i] >= '0' && temp[i] <= '8')
				{
					A[temp[i] - '0'] = 1;
				}
			}
			if (checkArray(A))
				break;
			else cout << "Goal is Fail";
		}
		Sleep(50);
		gotoXY(49, 15);
		cout << "                             ";
		gotoXY(37, 17);
		cout << "                             ";
		gotoXY(49, 15);
	}
	return temp;
}

void swap(int &x,int &y)
{
	int t = x;
	x = y;
	y = t;
}
string RandomStep(string goal,int steps)
{
	srand(time(NULL));
	string Assigment ;
	Assigment= goal;
	int step = 0;
	do
	{
		int index = -1;
		for (int i = 0; i < 9; i++)
		{
			if (Assigment[i] == '0')
			{
				index = i;
				break;
			}
		}
		int k;
		do
		{
			gotoXY(37, 17);
			cout << "Rand Assigment: ";
			for (int i = 0; i < 9; i++)
			{
				cout << Assigment[i] << " ";
			}
			k = rand() % 4;
			if (k == 0)
			{
				//left
				if (index % 3 != 2)
				{
					swap(Assigment[index], Assigment[index + 1]);
					break;
				}
					
			}
			else if (k == 1)
			{
				if (index % 3 != 0)
				{
					swap(Assigment[index], Assigment[index - 1]);
					break;
				}
			}
			else if (k == 2)
			{
				if (index / 3 != 2)
				{
					swap(Assigment[index], Assigment[index + 3]);
					break;
				}
					
			}
			else {
				if (index / 3 != 0)
				{
					swap(Assigment[index], Assigment[index - 3]);
					break;
				}
			}
		} while (true);
		
		step++;
		//Sleep(2);
	} while (step<steps);
	return Assigment;
}

void createDisplay()
{
	gotoXY(30, 5);
	cout << " 00 00      0 0 0    0     0  0 0 0  0 0 0  0      0 0 0 0" << endl;
	gotoXY(30, 6);
	cout << "0     0     0     0  0     0     0      0   0      0" << endl;
	gotoXY(30, 7);
	cout << " 00800      0 0 0    0     0    0      0    0      0 0 0" << endl;
	gotoXY(30, 8);
	cout << "0     0     0        0     0   0      0     0      0" << endl;
	gotoXY(30, 9);
	cout << " 00 00      0         0 0 0   0 0 0  0 0 0  0 0 0  0 0 0 0" << endl;

	string Input[3] = { "Player vs Player","Player vs Com","Exit" };
	gotoXY(50, 15);
	cout << ">> " << Input[0] << "   <<";
	gotoXY(50, 16);
	cout << ">> " << Input[1] << "      <<";
	gotoXY(50, 17);
	cout << ">> " << Input[2] << "               <<";
	
}
void CDisplay::playGame()
{	
	createDisplay();
	int flag = 0;
	gotoXY(70, 15 + flag);
	cout << "_";
	do
	{
		char key_press = _getch();
		int keyAscii = key_press;
		if (keyAscii == 80 || keyAscii == 77)
		{
			if (flag < 2)
				flag++;
			else flag = 0;
		}
		else if (keyAscii == 72 || keyAscii == 75)
		{
			if (flag > 0)
				flag--;
			else flag = 2;
		}
		else if (keyAscii == 13)
		{
			gotoXY(50, 15);
			cout << "                                                              ";
			gotoXY(50, 16);
			cout << "                                                              ";
			gotoXY(50, 17);
			cout << "                                                              ";
			if (flag == 2)
				exit(0);
			else if (flag == 0)
			{
				
				
				
				string name1,name2;

				gotoXY(37, 14);
				cout << "Moi nhap ten nguoi choi thu 1: ";
				do
				{

					gotoXY(68, 14);
					cout << "                                                  ";
					gotoXY(68, 14);
					getline(cin, name1);
				} while (!checkInputName(name1));
				
				gotoXY(37, 15);
				cout << "Moi nhap ten nguoi choi thu 2: ";
				do
				{
					gotoXY(68, 15);
					cout << "                                                  ";
					gotoXY(68, 15);
					getline(cin, name2);
				} while (!checkInputName(name2));
				string Goal = input();
				gotoXY(37, 16);
				cout << "Input Goal: ";
				
				string Assigment = RandomStep(Goal, 1000);
				gotoXY(37, 18);
				cout << "KeyPess";
				_getch();
				clrscr();

				CBoard *game = new CBoard(name1, name2,Assigment,Goal);
				game->playGame();
				_getch();
				clrscr();
				return;
			}
			else
			{
				gotoXY(37, 14);
				string name1;
				cout << "Moi nhap ten nguoi choi : ";
				getline(cin, name1);
				
				gotoXY(37, 15);
				cout << "Input Goal: ";
				string Goal = input();
				string Assigment = RandomStep(Goal, 1000);
				gotoXY(37, 18);
				cout << "KeyPess";
				_getch();
				clrscr();
				CBoard* game = new CBoard(name1,Assigment,Goal);
				game->playGame();
				_getch();
				clrscr();
				return;
			}
		}
		for (int i = 0; i <= 2; i++)
		{
			gotoXY(70, 15+i);
			cout << " ";
		}
		gotoXY(70, 15+flag);
		cout << "_";
	} while (true);

}
