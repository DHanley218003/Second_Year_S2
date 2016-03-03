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
#include <iostream>
#include <string.h>
#include <fstream>
#include "Seats.h"
#include <vector>

//function prototypes
void Reset(Seat **seats);
void ShowSeats(Seat **seats);
void ClearScreen();
void ShowDetails(Seat **seats);
void AddPassenger(Seat **seats);
void RemovePassenger(Seat **seats);
void AutoAssign(Seat **seats);
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
	delete[] seats;
}


struct Returner
{
public:
	Seat ** temp1;
	unsigned int tempRow;
	unsigned int tempColumn;
};

Returner loadFile()
{
	std::string temp;
	std::string name;
	char type;
	unsigned int seatRow = 0;
	unsigned int seatColumn = 0;
	std::fstream inStream;
	try
	{
		inStream.open("default.txt", std::ios::out);
		if (inStream.is_open)
		{
			seatRow = inStream.getline; // get seat row length from the first line
			seatColumn = inStream.getline; // get seat column length from the second line
			Seat **seats = new Seat*[seatRow];  // initialise the row
			for (int i = 0; i < seatRow; ++i)
				seats[i] = new Seat[seatColumn]; // initialise the columns

			while (inStream.getline)
			{
				temp = inStream.getline; // gets the next line for processing
				for(int i = 0; i < temp.size()-1; i++)
				{
					if(temp[i, i+1] == ' ') // detects a space
					{
						name = temp[0,i]; // everything up to the space is a name!
						type = temp[i+1,i+2]; // therefore after the space is the seat type
					}
				}
				for(int i = 0; i < seatRow; i++)
				{
					for(int j = 0; j < seatColumn; j++)
					{
						seats[i][j].setName(name); // set the name(if exists) to the seat
						seats[i][j].setType(type); // set the seat type (should exist!)
					}
				}
			}
		}
	}
	catch (_exception e)
	{
		printf("Unable to open file: %s", &e);
	}
	//load seats from file here
	Returner x;
	x.temp1 = seats;
	x.tempColumn = seatColumn;
	x.tempRow = seatRow;
	return x;
}

void AutoAssign(Seat **seats) //Finds the first free seat and assigns it
{
	for(unsigned int i = 0; i < seats; i++)
	{
		for(unsigned int j = 0; j < seats; j++)
		{
			if (seats[i][j].getName == "")
			{
				seats[i][j].setName();
				break;
			}
		}
	}
}

void RemovePassenger(Seat **seats) // unassigns a selected seat
{
	int tempc, tempr;
	ShowDetails(seats);
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
				else if (seats[tempc][tempr].getName() == "")
					printf("That seat is empty, please select another or enter -1 to quit.\n");
				else
				{
					seats[tempc][tempr].setName("");
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

void AddPassenger(Seat **seats) // assigns a selected seat
{
	int tempc, tempr;
	ShowDetails(seats);
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
				else if (seats[tempc][tempr].getName == "")
					printf("That seat is taken, please select another or enter -1 to quit.\n");
				else
				{
					seats[tempc][tempr].setName();
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

void ShowDetails(Seat **seats) // shows a detailed list of the seats
{
	ClearScreen();
	for(int i = 0; i < seats;i++)
	{
		for(int j = 0; j < seats;j++)
		{
			printf("Name: %s Type: %c", seats[i][j].getName, seats[i][j].getType);
		}
	}
	std::cin;//rather than system("pause");, which would crash in linux
}

void Reset(Seat **seats)
{
	// Resets 2d array of: seat number, reservation flag, seat class(0,1,2)
	for(int i = 0; i < seats;i++)
	{
		for(int j = 0; j < seats;j++)
		{
			seats[i][j].setName("");
		}
	}
	printf("Seats reset.\n");
}

void ShowSeats(Seat **seats)
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