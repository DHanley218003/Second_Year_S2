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
#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

template <typename T,unsigned S>
inline unsigned arraysize(const T (&v)[S]) { return S; }

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include "Seats.h"
#include <vector>

//function prototypes
void Reset(std::vector<std::vector<Seat*>>);
void ShowSeats(std::vector<std::vector<Seat*>>);
void ClearScreen();
void ShowDetails(std::vector<std::vector<Seat*>>);
void AddPassenger(std::vector<std::vector<Seat*>>);
void RemovePassenger(std::vector<std::vector<Seat*>>);
void AutoAssign(std::vector<std::vector<Seat*>>);
std::vector<std::vector<Seat*>> loadFile();

void main()
{
	int menu = -1;
	std::vector<std::vector<Seat*>> seats;// = loadFile();

	while(true)
	{
		ClearScreen();
		printf("Please select an option:\n1: print map of seats\n2: print seat details\n3: add a passenger\n4: remove a passenger\n5: Autoassign a seat\n6: reset seats\n0: exit program\n");
		if (scanf("%d", &menu))
		{
			if (menu == 0)
				break;
			else if (menu == 1)
				ShowSeats(seats);
			else if (menu == 2)
				ShowDetails(seats);
			else if (menu == 3)
				AddPassenger(seats);
			else if (menu == 4)
				RemovePassenger(seats);
			else if (menu == 5)
				AutoAssign(seats);
			else if (menu == 6)
				Reset(seats);
		}
	}
}

std::vector<std::vector<Seat*>> loadFile()
{
	char type;
	unsigned int seatLength = 0;
	unsigned int seatWidth = 0;
	std::fstream inStream;
	try
	{
		inStream.open("default.txt", std::ios::out);
		if (inStream.is_open)
		{
			while (inStream.getline)
			{
				
			}
		}
	}
	catch (_exception e)
	{
		printf("Unable to open file: %s", &e);
	}
	//load seats from file here
	std::vector< std::vector<Seat*> > seats;
	seats.resize(seatLength, std::vector<Seat*>(seatWidth,0));
	char input;
	for (unsigned int i = 0; input; i++)
	{
		for (unsigned int j = 0; input; j++)
		{
			type = input;
			seats[i][j];
		}
	}
	return seats;
}

void AutoAssign(std::vector<std::vector<Seat*>> seats) //Finds the first free seat and assigns it
{
	for(unsigned int i = 0; i < seats.size(); i++)
	{
		if (seats[i].getName == "")
		{
			seats[i].setName();
		}
	}
}

void RemovePassenger(std::vector<std::vector<Seat*>> seats) // unassigns a selected seat
{
	int temp;
	while(true)
	{
		
		ShowDetails(seats);
		printf("Please enter an seat number to remove.\n");
		if (scanf("%d", &temp))
		{
			if (temp < 0)
				break;
			else if (seats[temp].getName() == "")
			{
				seats[temp].setName();
				printf("Seat Removed! Please enter another seat number or enter -1 to quit.\n");
			}
			else
				printf("That seat is empty, please enter another seat or -1 to quit.\n");
		}
		else
		{
			ClearScreen();
			printf("Please enter a number!");
		}
	}
}

void AddPassenger(std::vector<std::vector<Seat*>> seats) // assigns a selected seat
{
	int temp;
	ShowDetails(seats);
	while(true)
	{
		printf("Please enter an seat number to add.\n");
		if (scanf("%d", &temp))
		{
			if (temp < 0)
				break;
			else if (seats[temp].getName == "")
				printf("That seat is taken, please select another or enter -1 to quit.\n");
			else
			{
				seats[temp].setName();
				printf("Seat added! Please enter another seat number or enter -1 to quit.\n");
			}
		}
		else
		{
			printf("Please enter a number!");
		}
	}
}

void ShowDetails(std::vector<std::vector<Seat*>> seats) // shows a detailed list of the seats
{
	ClearScreen();
	for (unsigned int i = 0; i < seats.size(); i++)
	{
		if (i < seats.size())
		{
			printf("%s", seats[i].getName());
			printf("%c", seats[i].getType());
		}
	}
	std::cin;//rather than system("pause");, which would crash in linux
}

void Reset(std::vector<std::vector<Seat*>> seats)
{
	// Resets 2d array of: seat number, reservation flag, seat class(0,1,2)
	for(unsigned int i = 0;i < 16; i++)
	{
		for(unsigned int j = 1; j < 3; j++)
		{
			if(j == 2)//last int in array used to determine seat class
			{
				if(i > 13)// first class
					y[i][j] = 2;
				else if(i > 10)// business class
					y[i][j] = 1;
				else// economy class
					y[i][j] = 0;
			}
			else
				y[i][j] = 0;
		}
		y[i][0] = i;
	}
	printf("Seats reset.\n");
}

void ShowSeats(std::vector<std::vector<Seat*>> seats)
{
	ClearScreen();
	int ncount = 0;//used for seat numbering
	int scount = 0;
	for(unsigned int i = 0; i < 9; i++)
	{
		if(i % 2)//print numbers or blocks?
		{
			for(unsigned int j = 0; j < 4; j++)//blocks
			{
				if(j == 2)// tab to create aisle
					printf("\t");
				if(y[scount][1])//if a seat is occupied
					printf("%c ", 219);
				scount++;
			}
		}
		else
		{
			for(unsigned int j = 0; j < 4; j++)//numbers
			{
				if(j == 2)// tab to create aisle
					printf("\t");
				printf("%d ",ncount);
				ncount++;
			}
			
		}
		printf("\n");
	}
	for(unsigned int j = 0; j < 4; j++)// Prints last row of blocks
	{
		if(j == 2)// tab to create aisle
			printf("\t");
		if(y[scount][1])//if a seat is occupied
			printf("%c ", 219);
		scount++;
	}
	printf("\nEnter a number to continue\n");
	std::cin >> ncount;//rather than system("pause");, which would crash in linux
}

void ClearScreen()
{
	if(os)//if linux
		std::cout << "\033[2J\033[1;1H";
	else//windows
		system("cls");
}