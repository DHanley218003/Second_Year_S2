/*
 * main.cpp version 0.4.0
 * A program for allocating seats on a 17 seat aircraft
 * Created on: Jan 20, 2016
 * Author: A00218003
 */
/* TODO
 * Add passenger names for assigned seat
 * Add disabled seat type
 * Modify array to deal with seating arrangement
 * Add customer seat type, e.g. Aductl/Child/Student/Disabled
 */

#include <stdio.h>
#include <sstream>
#include <iostream>
#include <string.h>
#include <fstream>
#include "Seats.h"
#include <vector>
#include "ClearScreen.h"

	
struct Returner //used to transer the seatmap and array size
{
public:
	Seat ** seat;
	unsigned int row;
	unsigned int column;
};

//function prototypes
char nth_letter(int n);
void ChangeType(Returner x);
void Reset(Returner x);
void ShowSeats(Returner x);
void ShowDetails(Returner x);
void AddPassenger(Returner x);
void RemovePassenger(Returner x);
void AutoAssign(Returner x);
void Pause();
Returner loadFile();

int main()
{
	int menu = -1;
	Returner x = loadFile();

	while(true)
	{
		ClearScreen();
		std::cout << "Please select an option:\n1: print map of seats\n2: print seat details\n3: add a passenger\n4: remove a passenger\n5: Autoassign a seat\n6: reset seats\n7: Change seat type\n0: exit program" << std::endl;
		std::cin >> menu;
		if (std::cin)
		{
			switch (menu)
			{
			case 0:
				return 0;
			case 1:
				ShowSeats(x);
				Pause();
				break;
			case 2:
				ShowDetails(x);
				Pause();
				break;
			case 3:
				AddPassenger(x);
				break;
			case 4:
				RemovePassenger(x);
				break;
			case 5:
				AutoAssign(x);
				break;
			case 6:
				Reset(x);
				break;
			case 7:
				ChangeType(x);
				break;
			}
		}
		else
			std::cout << "Please enter a number!" << std::endl;
	}
	return 0;
}



Returner loadFile() // loads the file and returns it as the seatmap struct
{
	std::string temp;
	std::string name;
	char type;
	unsigned int seatRow = 0;
	unsigned int seatColumn = 0;
	std::ifstream inStream;
	try
	{
		inStream.open("default.txt");
		if (inStream.is_open())
		{
			std::getline(inStream, temp); // get seat row length from the first line
			seatRow = atoi(temp.c_str());
			std::getline(inStream, temp);
			seatColumn = atoi(temp.c_str());	// get seat column length from the second line
			Seat **seats = new Seat*[seatRow];  // initialise the row
			for (unsigned int i = 0; i <= seatRow; ++i)
			{
				seats[i] = new Seat[seatColumn]; // initialise the columns
			}

			for (int i = 0; i < seatRow; i++)
			{
				for(int j = 0; j < seatColumn; j++)
				{
					temp = "";
					std::getline(inStream, temp);
					std::istringstream ss(temp); // gets the next line for processing
					if (!(ss >> name >> type))
					{
						seats[i][j].setName("");
						seats[i][j].setType('X');
					}
					else
					{
						seats[i][j].setName(name); // set the name(if exists) to the seat
						seats[i][j].setType(type); // set the seat type (should exist!)
					}
				}
			}
			inStream.close();
			Returner x;
			x.seat = seats;
			x.column = seatColumn;
			x.row = seatRow;
			return x;
		}
	}
	catch (_exception e)
	{
		printf("Unable to open file: %s", &e);
	}
	Returner x;
	Seat **seats = new Seat*[1];
	x.seat = seats;
	x.column = 1;
	x.row = 1;
	return x;
	//load seats from file here
}

void AutoAssign(Returner x) //Finds the first free seat and assigns it
{
	for(unsigned int i = 0; i < x.row; i++)
	{
		for(unsigned int j = 0; j < x.column; j++)
		{
			if (x.seat[i][j].getName().empty() && x.seat[i][j].getType() != 'X')
			{
				std::cout << "Please enter your full name: ";
				std::string y;
				std::cin >> y;
				x.seat[i][j].setName(y);
				return;
			}
		}
	}
	std::cout << "No free seats found!" << std::endl;
}

void RemovePassenger(Returner x) // unassigns a selected seat
{
	int tempc, tempr;
	ShowSeats(x);
	while (true)
	{
		std::cout << "Please enter an seat row to remove: ";
		std::cin >> tempc;
		if (std::cin)
		{
			if (tempc < 0 || tempc > x.row)
				break;
			std::cout << "Please enter an seat column to remove: ";
			std::cin >> tempr;
			if (std::cin)
			{
				if (tempc < 0 || tempr < 0)
					break;
				else if (x.seat[tempc][tempr].getName().empty())
					std::cout << "That seat is empty, please enter another seat number or enter -1 to quit." << std::endl;
				else
				{
					x.seat[tempc][tempr].setName("");
					std::cout << "Seat removed! Please enter another seat number or enter -1 to quit." << std::endl;
				}
			}
			else
			{
				std::cout << "Please enter a number!" << std::endl;
			}
		}
		else
		{
			std::cout << "Please enter a number!" << std::endl;
		}
	}
}

void AddPassenger(Returner x) // assigns a selected seat
{
	int tempc, tempr;
	ShowSeats(x);
	while(true)
	{
		std::cout << "Please enter an seat row to add: ";
		std::cin >> tempc;
		if (std::cin)
		{
			if(tempc < 0 || tempc > x.row)
				break;
			std::cout << "Please enter an seat column to add: ";
			std::cin >> tempr;
			if (std::cin)
			{
				if (tempr < 0 || tempr > x.column)
					break;
				else if (!x.seat[tempc][tempr].getName().empty())
					std::cout << "That seat is taken, please enter another seat number or enter -1 to quit." << std::endl;
				else
				{
					std::cout << "Please enter your full name: ";
					std::string y;
					std::cin >> y;
					x.seat[tempc][tempr].setName(y);
					std::cout << "Seat added! Please enter another seat number or enter -1 to quit." << std::endl;
				}
			}
			else
			{
				std::cout << "Please enter a number!" << std::endl;
			}
		}
		else
		{
			std::cout << "Please enter a number!" << std::endl;
		}
	}
}

void ChangeType(Returner x) // Changes the seat type
{
	int tempc, tempr;
	ShowSeats(x);
	while (true)
	{
		std::cout << "Please enter an seat row to modify: ";
		std::cin >> tempc;
		if (std::cin)
		{
			if (tempc < 0 || tempc > x.row)
				break;
			std::cout << "Please enter an seat column to modify: ";
			std::cin >> tempr;
			if (std::cin)
			{
				if (tempr < 0 || tempr > x.column)
					break;
				else
				{
					std::cout << "E = economy B = business F = first class D = disabled C = child A = adult S = student X = no seat" << std::endl;
					std::cout << "Please enter the seat type: " << std::endl;
					char y;
					std::cin >> y;
					if (x.seat[tempc][tempr].setType(y))
						std::cout << "Seat modified! Please enter another seat number or enter -1 to quit." << std::endl;
					else
						std::cout << "Invalid seat type! Please try again or enter -1 to quit." << std::endl;
				}
			}
			else
			{
				std::cout << "Please enter a number!" << std::endl;
			}
		}
		else
		{
			std::cout << "Please enter a number!" << std::endl;
		}
	}
}
void ShowDetails(Returner x) // shows a detailed list of the seats
{
	ClearScreen();
	for(unsigned int i = 0; i < x.row;i++)
	{
		for(unsigned int j = 0; j < x.column;j++)
		{
			if (x.seat[i][j].getType() == 'X')
				std::cout << "No seat" << std::endl;
			else if(!x.seat[i][j].getName().empty())
				std::cout << "Name: " << x.seat[i][j].getName() << " Type: " << x.seat[i][j].getType() << std::endl;
			else
				std::cout << "Empty " << " Type: " << x.seat[i][j].getType() << std::endl;
		}
	}
}

void Reset(Returner x)
{
	// Sets all names as "", effectively unreserving seats.
	for(unsigned int i = 0; i < x.row;i++)
	{
		for(unsigned int j = 0; j < x.column;j++)
		{
			x.seat[i][j].setName("");
		}
	}
	std::cout << "Seats reset!" << std::endl;
}

void ShowSeats(Returner x)
{
	ClearScreen();
	for (unsigned int i = 0; i < x.row; i++)
	{
		for (unsigned int j = 0; j < x.column; j++)
		{
			if (x.seat[i][j].getType() == 'X')
				std::cout << " X  " << ' ';
			else if (!x.seat[i][j].getName().empty())
				std::cout << '[' << i << nth_letter(j) << ']' << ' ';
		}
		std::cout << std::endl;
	}
}

void Pause()
{
	std::cout << "Press any key to continue!" << std::endl;
	std::cin.sync();
	std::cin.get();
	return;
}

char nth_letter(int n)
{
	if (!(n >= 0) && !(n <= 26))
		return 'X';
	return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n];
}