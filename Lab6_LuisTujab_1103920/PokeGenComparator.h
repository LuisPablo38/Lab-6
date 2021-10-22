#pragma once
#include "Comparator.h"
#include"InfoPo.h"
class PokeGenComparator :
	public Comparator<InfoPo>
{
	// Heredado vía Comparator
	virtual int compare(InfoPo a, InfoPo b) override;
};

