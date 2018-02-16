/*
 * computer.cpp
 *
 *      Author: Alex van der Linden
 */
#include "computer.h"
#include <iostream>

Computer::Computer(double clockRateGHz, double cpiArith, double cpiStore,
		double cpiLoad, double cpiBranch)
{
	this->clockRateGHz = clockRateGHz;
	this->cpiArith = cpiArith;
	this->cpiStore = cpiStore;
	this->cpiLoad = cpiLoad;
	this->cpiBranch = cpiBranch;

}


void Computer::printStats(void)
{
	std::cout<<"Clock rate\t: " << this->clockRateGHz << " [GHz]\n";
	std::cout<<"CPI Arith\t: " << this->cpiArith << " [cpi]\n";
	std::cout<<"CPI Store\t: " << this->cpiStore << " [cpi]\n";
	std::cout<<"CPI Load\t: " << this->cpiLoad << " [cpi]\n";
	std::cout<<"CPI Branch\t: " << this->cpiBranch << " [cpi]\n";
}

double Computer::calculateGlobalCPI(void)
{
	double averageCPI = (this->cpiArith + this->cpiStore +
			+ this->cpiLoad + this->cpiBranch)/4;

	return averageCPI;
}
