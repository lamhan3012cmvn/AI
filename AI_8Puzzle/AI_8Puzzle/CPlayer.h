#pragma once
#include<string>
#include<iostream>
#include"console.h"
using namespace std;


class CPlayer
{
private :
	string name;
	
public:
	int playeTurn();
	bool isWin(string current,string goal);
	string getNamePlayer();
	string getName();
	CPlayer( string );
};

