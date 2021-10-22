#pragma once
#include"pch.h"
#include <string>

using std::string; 
class InfoPo
{
	int id;
	int NatNum;
	string nombrePoke;
	int generacion; 
 

public:
	InfoPo(int id, int NatNum, string nombrePoke, int generacion); 

	int getid(); 
	int getNatNum();
	string getnombrePoke(); 
	int getgeneracion(); 
};

