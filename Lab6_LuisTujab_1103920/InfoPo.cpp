#include "pch.h"
#include "InfoPo.h"

InfoPo::InfoPo(int id, int NatNum, string nombrePoke, int generacion)
{
	this->id = id; 
	this->NatNum = NatNum; 
	this->nombrePoke = nombrePoke; 
	this->generacion = generacion; 
}



int InfoPo::getid()
{
	return this->id;
}

int InfoPo::getNatNum()
{
	return this->NatNum;
}

string InfoPo::getnombrePoke()
{
	return this->nombrePoke;
}

int InfoPo::getgeneracion()
{
	return this->generacion;
}
