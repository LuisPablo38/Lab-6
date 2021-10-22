#include "pch.h"
#include "PokeGenComparator.h"

int PokeGenComparator::compare(InfoPo a, InfoPo b)
{
	return a.getgeneracion()-b.getgeneracion();
	if (a.getgeneracion() == b.getgeneracion())
	{
		return a.getnombrePoke().compare(b.getnombrePoke());
	}
}
