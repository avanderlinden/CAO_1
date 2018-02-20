/*
 * computer.cpp
 *
 *      Author: Alex van der Linden
 */
#include "computer.h"


Computer::Computer(double clockRateGHz, double cpiArith, double cpiStore,
		double cpiLoad, double cpiBranch)
{
	this->clockRateGHz = clockRateGHz;
	this->cpiArith = cpiArith;
	this->cpiStore = cpiStore;
	this->cpiLoad = cpiLoad;
	this->cpiBranch = cpiBranch;

}

//std::ostream Computer::stats()
//{
//	std::ostream stats;
//
//	stats<<"Clock rate\t: " << this->clockRateGHz << " [GHz]\n";
//	stats<<"CPI Arith\t: " << this->cpiArith << " [cpi]\n";
//	stats<<"CPI Store\t: " << this->cpiStore << " [cpi]\n";
//	stats<<"CPI Load\t: " << this->cpiLoad << " [cpi]\n";
//	stats<<"CPI Branch\t: " << this->cpiBranch << " [cpi]\n";
//
//	return stats;
//
//}

std::ostream& operator<<(std::ostream& out, const Computer& pc)
{
	out<<"Clock rate\t: " << pc.clockRateGHz << " [GHz]\n";
	out<<"CPI Arith\t: " << pc.cpiArith << " [cpi]\n";
	out<<"CPI Store\t: " << pc.cpiStore << " [cpi]\n";
	out<<"CPI Load\t: " << pc.cpiLoad << " [cpi]\n";
	out<<"CPI Branch\t: " << pc.cpiBranch << " [cpi]\n";

    return out;
}

void Computer::printStats(void)
{
	std::cout << this;
}

double Computer::calculateGlobalCPI(void)
{
	double average_cpi = (this->cpiArith + this->cpiStore +
			+ this->cpiLoad + this->cpiBranch)/4.0;

	return average_cpi;
}

double Computer::calculateExecutionTime(Program prog)
{
	double cpu_cycles = this->cpiArith * prog.getNumArith()
						+ this->cpiStore * prog.getNumStore()
						+ this->cpiLoad * prog.getNumLoad()
						+ this->cpiBranch * prog.getNumBranch();

	double cpu_time = cpu_cycles / (this->clockRateGHz * 1000000000);

	return cpu_time;
}

double Computer::calculateMIPS(void)
{
	// clock rate * 1000 because Million and Giga differ by factor 1000
	double mips = (this->clockRateGHz * 1000) / this->calculateGlobalCPI();
	return mips;
}

double Computer::calculateMIPS(Program prog)
{
	double ips = (prog.getNumTotal() / this->calculateExecutionTime(prog));
	return ips / 1000000; // convert IPS to MIPS
}


