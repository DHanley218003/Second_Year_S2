#ifndef SEATS_H
#define SEATS_H
#include <iostream>

class Seat // airline seat
{
private:
	std::string name; // passenger name
	char type; // seat type
public:
	void setName(std::string x); // takes in passenger name and sets it
	bool setType(char x); // takes in a capital letter to set as a seat type, returns true if correct letter was inputted
	std::string getName() const; // returns the seat passenger name
	char getType() const; // returns the seat type
};

#endif // SEATS_H