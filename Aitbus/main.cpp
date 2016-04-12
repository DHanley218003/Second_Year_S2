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

//What os is used? Used to determine screen clear command
#ifdef __linux__
	bool os = true;
#else
	bool os = false;
	#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <string.h>
#include <fstream>
#include "Seats.h"
#include <vector>

	
struct Returner
{
public:
	Seat ** seat;
	unsigned int row;
	unsigned int column;
};
//function prototypes
void Reset(Returner x);
void ShowSeats(Returner x);
void ClearScreen();
void ShowDetails(Returner x);
void AddPassenger(Returner x);
void RemovePassenger(Returner x);
void AutoAssign(Returner x);
Returner loadFile();

void main()
{
	int menu = -1;
	Returner x = loadFile();

	while(true)
	{
		ClearScreen();
		printf("Please select an option:\n1: print map of seats\n2: print seat details\n3: add a passenger\n4: remove a passenger\n5: Autoassign a seat\n6: reset seats\n0: exit program\n");
		if (scanf("%d", &menu))
		{
			if (menu == 0)
				break;
			else if (menu == 1)
				ShowSeats(x);
			else if (menu == 2)
				ShowDetails(x);
			else if (menu == 3)
				AddPassenger(x);
			else if (menu == 4)
				RemovePassenger(x);
			else if (menu == 5)
				AutoAssign(x);
			else if (menu == 6)
				Reset(x);
		}
	}
}



Returner loadFile()
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
		if (inStream)
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

			while (std::getline(inStream, temp))
			{
				std::getline(inStream, temp); // gets the next line for processing
				for(unsigned int i = 0; i < temp.size()-1; i++)
				{
					if(temp[i, i+1] == ' ') // detects a space
					{
						name = temp[0,i]; // everything up to the space is a name!
						type = temp[i+1,i+2]; // therefore after the space is the seat type
					}
				}
				for(unsigned int i = 0; i <= seatRow; i++)
				{
					for(unsigned int j = 0; j <= seatColumn; j++)
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
			if (x.seat[i][j].getName().empty())
			{
				printf("Please enter your full name: ");
				std::string y;
				scanf("%s", &y);
				x.seat[i][j].setName(y);
				return;
			}
		}
	}
}

void RemovePassenger(Returner x) // unassigns a selected seat
{
	int tempc, tempr;
	ShowDetails(x);
	while(true)
	{
		printf("Please enter an seat column to remove.\n");
		if (scanf("%d", &tempc))
		{
			printf("Please enter an seat column to remove.\n");
			if (scanf("%d", &tempr))
			{
				if (tempc < 0 || tempr < 0)
					break;
				else if (x.seat[tempc][tempr].getName().empty())
					printf("That seat is empty, please select another or enter -1 to quit.\n");
				else
				{
					x.seat[tempc][tempr].setName("");
					printf("Seat removed! Please enter another seat number or enter -1 to quit.\n");
				}
			}
			else
			{
				printf("Please enter a number!");
			}
		}
		else
		{
			printf("Please enter a number!");
		}
	}
}

void AddPassenger(Returner x) // assigns a selected seat
{
	int tempc, tempr;
	ShowDetails(x);
	while(true)
	{
		printf("Please enter an seat column to add.\n");
		if (scanf("%d", &tempc))
		{
			printf("Please enter an seat column to add.\n");
			if (scanf("%d", &tempr))
			{
				if (tempc < 0 || tempr < 0)
					break;
				else if (x.seat[tempc][tempr].getName().empty())
					printf("That seat is taken, please select another or enter -1 to quit.\n");
				else
				{
					printf("Please enter your full name: ");
					std::string y;
					scanf("%s", &y);
					x.seat[tempc][tempr].setName(y);
					printf("Seat added! Please enter another seat number or enter -1 to quit.\n");
				}
			}
			else
			{
				printf("Please enter a number!");
			}
		}
		else
		{
			printf("Please enter a number!");
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
			printf("Name: %s Type: %c", x.seat[i][j].getName(), x.seat[i][j].getType());
		}
	}
	std::cin;//rather than system("pause");, which would crash in linux
}

void Reset(Returner x)
{
	// Resets 2d array of: seat number, reservation flag, seat class(0,1,2)
	for(unsigned int i = 0; i < x.row;i++)
	{
		for(unsigned int j = 0; j < x.column;j++)
		{
			x.seat[i][j].setName("");
		}
	}
	printf("Seats reset.\n");
}

void ShowSeats(Returner x)
{
	ClearScreen();
	
	std::cin;//rather than system("pause");, which would crash in linux
}

void ClearScreen()
{
	if(os)//if linux
		std::cout << "\033[2J\033[1;1H";
	else//windows
		system("cls");
}