/*
 * main.cpp version 2.0.0
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

//Classes
class Seat
{
	std::string name;
	char type;
	void setName(std::string x)
	{
		name = x;
	}
	void setName()
	{
		printf("Please enter your full name: ");
		std::string x;
		scanf("%s", &x);
		name = x;
	}
	bool setType(char x)
	{
		if (x == 'E' || x == 'B' || x == 'F' || x == 'D')
		{
			type = x;
			return true;
		}
		else
			return false;
	}
	std::string getName()
	{
		return name;
	}
	char getType()
	{
		return type;
	}
};

//function prototypes
void Reset();
void ShowSeats();
void ClearScreen();
void ShowDetails();
void AddPassenger();
void RemovePassenger();
void AutoAssign();

void main()
{
	int menu = -1;
	char type;
	unsigned int input;
	//load seats from file here
	Seat seats[input];
	char input;
	for (unsigned int i = 0; i < hasNext(); i++)
	{
		
		type = input;
		input.setType(type);
	}
	while(true)
	{
		ClearScreen();
		printf("Please select an option:\n1: print map of seats\n2: print seat details\n3: add a passenger\n4: remove a passenger\n5: Autoassign a seat\n6: reset seats\n0: exit program\n");
		if (scanf("%d", &menu))
		{
			if (menu == 0)
				break;
			else if (menu == 1)
				ShowSeats();
			else if (menu == 2)
				ShowDetails();
			else if (menu == 3)
				AddPassenger();
			else if (menu == 4)
				RemovePassenger();
			else if (menu == 5)
				AutoAssign();
			else if (menu == 6)
				Reset();
		}
	}
}

void AutoAssign(seats) //Finds the first free seat and assigns it
{
	for(unsigned int i = 0; i < seats.sizeof; i++)
	{
		if (seats[i].getName == "")
		{
			seats[i].setName();
		}
	}
}

void RemovePassenger(seats) // unassigns a selected seat
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

void AddPassenger(seats) // assigns a selected seat
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

void ShowDetails(seats) // shows a detailed list of the seats
{
	ClearScreen();
	printf("Seat Number |\t Reserved |\t Seat Class\n"); //Table heading
	for(unsigned int i = 0; i < 16; i++)
	{
		for(unsigned int j = 0; j < 3; j++)
		{
			if(j == 0)
				printf("%d\t\t", s[i][j]);
			else if(j ==1)
			{
				if(s[i][j] == 1)
					printf("yes\t\t");
				else
					printf("no\t\t");
			}
			else
			{
				if(s[i][j] == 0)
					printf("Economy\n");
				if(s[i][j] == 1)
					printf("Business\n");
				if(s[i][j] == 2)
					printf("First\n");
			}
		}
	}
	printf("\nEnter a number to continue\n");
	int temp;
	std::cin >> temp;//rather than system("pause");, which would crash in linux
}

void Reset(unsigned int y[17][4])
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

void ShowSeats(unsigned int y[17][4])
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