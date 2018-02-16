/*
 * main.cpp
 *
 *  Created on: Feb 16, 2018
 *      Author: Alex van der Linden
 */

#include <iostream>
#include "computer.h"
#include "program.h"

int main()
{
	Computer pc  = Computer(2.2, 1.2, 2.3, 3.4, 4.5);

	pc.printStats();

	std::cout << "\nGlobal Cycles per Instruction: ";
	std::cout << pc.calculateGlobalCPI() << " [cpi]\n\n";

	Program prog1 = Program(2, 3, 4, 5);
	prog1.printStats();

	std::cout << "\n\n";

	Program prog2 = Program(20, 0.2, 0.3, 0.4);
	prog2.printStats();

}

