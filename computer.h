/*
 * computer.h
 *
 *  Created on: Feb 16, 2018
 *      Author: Alex van der Linden
 */

#ifndef COMPUTER_H_
#define COMPUTER_H_

class Computer
{
public:
  /*
   * Initializes the Computer object.
   */
  Computer (double clockRateGHz, double cpiArith,
		  double cpiStore, double cpiLoad, double cpiBranch);

  /*
   * Prints all the statistics of the Computer object
   * to standard output (std::cout).
   */
  void printStats (void);

  /*
   * Calculates average cycles per instruction
   *
   * Return: double average cycles per instruction
   */
  double calculateGlobalCPI (void);


private:
  double clockRateGHz;  // Clock rate in GHz
  double cpiArith;  // CPI of instruction class Arith
  double cpiStore;  // CPI of instruction class Store
  double cpiLoad;  // CPI of instruction class Load
  double cpiBranch;  // CPI of instruction class Branch

};


#endif /* COMPUTER_H */
