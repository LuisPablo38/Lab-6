#pragma once
#include "Comparator.h"
#include"InfoPo.h"
class PokeNatNumComparator :
	public Comparator<InfoPo>
{
	// Heredado v�a Comparator
	virtual int compare(InfoPo a, InfoPo b) override;
};

