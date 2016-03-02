#include "Seats.h"
#include <iostream>

void Seat::setName(std::string x) // takes in passenger name and sets it
	{
		name = x;
	}

void Seat::setName() // Alternative for cli
	{
		printf("Please enter your full name: ");
		std::string x;
		scanf("%s", &x);
		name = x;
	}

bool Seat::setType(char x) // takes in a capital letter to set as a seat type, returns true if correct letter was inputted
	{
		if (x == 'E' || x == 'B' || x == 'F' || x == 'D' || x == 'X') // Economy, Business, First class, Disabled, No seat
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