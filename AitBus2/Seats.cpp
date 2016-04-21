#include "Seats.h"
#include <iostream>

void Seat::setName(std::string x) // takes in passenger name and sets it
	{
		name = x;
	}

bool Seat::setType(char x) // takes in a capital letter to set as a seat type, returns true if correct letter was inputted
	{
		if (x == 'E' || x == 'B' || x == 'F' || x == 'D' || x == 'C' || x == 'A' || x == 'S' || x == 'X') // Economy, Business, First class, Disabled, Child, Adult, Student, No seat
		{
			type = x;
			return true;
		}
		else
			return false;
	}
std::string Seat::getName() const// returns the seat passenger name
	{
		return name;
	}
char Seat::getType() const// returns the seat type
	{
		return type;
	}