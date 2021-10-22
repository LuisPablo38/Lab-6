#include "pch.h"
#include "PokeNatNumComparator.h"

int PokeNatNumComparator::compare(InfoPo a, InfoPo b)
{
	return a.getNatNum()-b.getNatNum();
}
